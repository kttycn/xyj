// cmd : auto_create_area.c  根据简单设置文件，生成区域 room file.
// by naihe 2:01 03-11-15 for huns@惊鸿论坛
// EM: lonely@163.com  or  lovesb@21cn.com
// PS: 我的单机是 xkx 类的

// V1.1
// 修正了一个BUG
// 更改了计算的方式，使流程更清晰
// 更改了建立文件的方式，只建立在地图里的、并且在列表里的文件名
// 为没有 setcolor(), delcolor() 函数的MUD加进了这两个函数

//v1.2
//改进了容错性，中文名长度随意了.
//增加了x连接符,可以交叉连了.
//连接符可以连用和互相穿越了，具体见示例。
//huns修改于 2003.12.07

//v1.3
//增加了A,<,>,V,v 连接符,可以高低连了，尖尖所指是地势较高的位置.
//   可以这样filea>>>>>>fileb，也可以这样filea>---->fileb,首尾一样即可
//增加了E,! {  连接符,可以连 楼上/楼下 上/下 爬上/爬下 位置,E取形状比较像楼梯、{ 像绳子.
//修正了一个地图异常复杂时可能出现的BUG
//地图中可以出现重复房间了，可以如 小路-小路---小路
//整理了结构，去掉了一些不必要的循环

//v1.4
//增加多地图功能，修改几个出错提示
//去掉给房间加颜色功能，没用，颜色应该是look来决定的。
//huns 修改于 2006-7-10 22:36
//可任意选择是否添加长描述，并决定添加连接出口的描述，简化打字过程
#include <ansi.h>
int sizeofmap , linelen , map_start_line ,map_number;// 地图行数 本行长度 地图起始行数 地图总数
mapping all_exits = ([ ]);          //总出口  ([房间名1  , ([方向 中文房间名 ])])
mapping all_dirs = ([ ]); //除文件名和短描述对照mapping 以外的所有数据集合
/*
获得目录中文名称 all_dirs[/d/baihe/]["cname"] ===>白河村
获得目录文件名称对应短描述信息 all_dirs[/d/baihe/shulin]["short"] ===>树林
获得目录文件名称对应长描述信息 all_dirs[/d/baihe/shulin]["long"] ===>树林树林树林树林树林树林树林树林  
获得目录文件名称对应房间信息设置 all_dirs[/d/baihe/shulin]["roomset"] ==>

*/

string filename , *allfile , *f_len  ,dir ;

string *map,*alldir=({}) ;       		   // 总地图
mapping filename_to_short = ([ ]);        // filename-->中文房间名

mapping short_to_long = ([ ]);        // short-->中文房间长描述
mapping short_to_filename = ([ ]);        // 中文房间名-->filename
mapping xy2filename = ([ ]);        // 地址-->filename

        // map[x][y]  x第几行  ，y第几列 ,x相对偏移，  y相对偏移
string xy_to_filename( int x,   int y ,   int x1  ,     int y1 ) ;

int add_exit( string n1, string exit, string n2 );

/*******************************************************************
 '-','<','>',        //西-东，西高-东低，西低-东高，

 '|','V','A',    // 北       北低      北低      北高
                     // |         v         V         A
                     // 南  ，   南高  ，  南高  ，  南低

 '/','\','X',    //     东北  西北       交叉连接， 交叉连接
                       //    /          \          x          X
                       //西南     ，     东南，

几个特殊的
 'E','!'  '{'      // 楼上  上   高 爬上/爬下
                   //  E     !   {  绳子
                   // 楼下，下   低
********************************************************************/

//所有连接符
mixed *all_foos=({ '-','<','>', '|', 'V','A', '/','\\', 'X', 'E','!','{'  }) ;

int test_file(string filename);
int read_dir( int n);
int read_room_list();
int read_map( int n);
int get_exit( mixed foo ,int x  ,int y );
int total_map_n();

// 用于检测文件名(英文名)是否有效
// 如果希望用一些特别的字符（如汉字等）作为 write_file() 的
// 文件名，，请更改本函数，或使本函数直接 return 1 .
int valid( string n )
{
	string l = "1234567890abcdefghijklmnopqrstuvwxyz-_";
	mixed t;
	if( !n ) return 0;
	foreach( t in l )
		if( n[0] == t ) return 1;
	return 0;
}

//只留下文件名，其他转空格
string replace_nouse_to_blank( string s )
{
	string temp , *all_foo= ({"-","|","/","\\",  "X" ,"A","V", "<",">" ,"E" ,"!" ,"{"}) ;
	foreach( temp in all_foo )
	     s = replace_string( s, temp, " " );

	return s;
}

int read_file_msg( string filename)
{
 	return  test_file(filename)
	        &&  read_room_list();
}

//验证文件是否可用
int test_file(string filename)
{
	string   file ,*temp_f_len;
	map_number=0;
	if( !filename ) return notify_fail("请指定文件。\n");
	
	if(file_size( filename )==-1) return notify_fail("文件不存在。\n");
	
	//write("------ ok>>>>\n"+file_size( filename ));
	
	if( !file = read_file( filename )  )	return notify_fail("无法读取该文件："+filename+"\n");

	if(strsrch( file, "	" ) != -1)
	return notify_fail("该文件含有TAB跳格,因为每个人的长度定义可能不一致，会导致出错,请全部替换为空格\n");

	file=replace_string( file, "\t", "        " );
//tab转8空格,画地图时别用TAB键跳格，我的编辑器用TAB时显示长短不一：( 。

	if( strlen( file ) < 10 ) return notify_fail("该文件内容太少，无法作为有效资料。\n");

	if( strsrch( file, "#create area file#" ) == -1
	 || strsrch( file, "#dir#" ) == -1
	 || strsrch( file, "#list#" ) == -1
	// || strsrch( file, "#list_end#" ) == -1
	 || strsrch( file, "#map#" ) == -1
	 || strsrch( file, "#map_end#" ) == -1 )
		return notify_fail("该文件资料不足，无法建立文件。"
			"请参阅 help auto_create_area 获得格式规范说明。\n");

	f_len = explode( file, "\n" );
		
	temp_f_len =f_len - ({ "", " ", "  ", "　", "	", }); //去掉空行,加快速度
	if( sizeof(temp_f_len) < 10 )
		return notify_fail("该文件内容太少，或空行符号太少，无法作为有效资料。\n");

	//共有多少幅地图
	map_number = sizeof( filter_array( f_len, (: strsrch( $1, "#map#" ) != -1 :) )  );


	return 1;
}

//读取 房间名称列表
int read_room_list()
{
	mixed temp;
	string  *temp_arr , checking ;
	int m;
	// ok, make a file_name list for all rooms.
	write("------ 正在读取 房间名称列表 >>>>\n");
	temp = ({ });
	m = 0;

	// get rooms list
	foreach( checking in f_len )
	{
	//	if( strsrch( checking , "#list_end#" ) != -1 )
	//		break; 一直读到文件尾，故无需判断结束行标记
		if( m ) temp += ({ checking });
		if( !m && strsrch( checking , "#list#" ) != -1 )
			m = 1;
	}
	if( !temp || !sizeof(temp) )
		return notify_fail("无法读取有效的房间名称列表，请查正再试。\n");

	m = sizeof(temp) ;

	write("共读取 "+ m +" 个房间名称。\n------ 正在验证房间名称是否有效 >>>\n");

	short_to_filename = ([ ]);// 中文房间名-->filename
	filename_to_short = ([ ]);// filename-->中文房间名
	//short_to_long = ([ ]);// 中文房间名-->中文房间长描述
	// 进行有效判断，并生成2个对应的 map ，方便调用
	foreach( checking in temp )
	{
	
		if(sizeof(temp_arr = explode( checking, ":" ))!=2)
			return notify_fail("房间名称列表有的缺:或太多：，请查正再试。\n");
	
	//	if( sizeof(temp_arr) =2) //长描述中含有：
	        
			sscanf( checking, "%s:%s",temp_arr[0] ,temp_arr[1] );//,temp_arr[2]
		
		temp_arr[0]= replace_string( temp_arr[0], " ", "" );
		temp_arr[1]= replace_string( temp_arr[1], " ", "" );	
		
		if( sizeof(temp_arr) >1 && valid(temp_arr[1]) )   //增加设置房间的长描述...
		{
			if( !undefinedp( short_to_filename[ temp_arr[0]] ) )
				return notify_fail( "房间名称列表" + temp_arr[0] +"重复定义，请查正再试。\n");

			short_to_filename[ temp_arr[0] ] = temp_arr[1];

			if( !undefinedp( filename_to_short[ temp_arr[1] ] ) )
				return notify_fail( "文件名称列表"+temp_arr[1]+ "重复定义，请查正再试。\n");

			filename_to_short[ temp_arr[1] ] = temp_arr[0];
			}
	}
  	//有些无聊，不过还是加上，防止没考虑到的问题
	if( !filename_to_short || !short_to_filename )
	return notify_fail("无法获得有效的房间名称列表，请查正再试。\n");

	if( sizeof(filename_to_short) < m)
	return notify_fail("房间名称列表英文文件名有重复，请查正再试。\n");

	if( sizeof(short_to_filename) < m )
	return notify_fail("房间名称列表中文短描述有重复，请查正再试。\n");

	write("共读取有效房间名称 "+sizeof(short_to_filename)+" 个。\n");
	
	
	return 1;
}
/*
int sort(string a,string b)
{
	return (sizeof(a)>sizeof(b))?-1:0;	
}
*/
//读取第n 目录设置
int read_dir( int n)
{
//	function f = (: sort :);
	// ok. get "dir" first
	int i;
	
	write("----------------------------------------------\n- 正在读取 目录设置\n");

	if( !sizeof(alldir) )//如果没有所有目录//alldir未定义，那么就初始化它
	{
		alldir= filter_array( f_len, (: strsrch( $1, "#dir#" ) != -1 :) );
		if( !alldir || !arrayp(alldir) || !sizeof(alldir) )
			return notify_fail("无法读取有效的 “区域目录” 设置，请查正再试。\n");
				
		for(i=0;i<sizeof(alldir);i++ )
		{
		alldir[i]=  replace_string(alldir[i],"#dir#" ,"");
		alldir[i]=  replace_string(alldir[i]," " ,"");
		}
		
		write_file( "/test/alldir", implode( alldir, "\n" ), 1 );//输出所有区域目录，方便后续编程用
	}
	dir = replace_string( alldir[n-1], " ", "" );//包含区域目录
	
	//dir = replace_string( checking, "#dir#", "");
	if( !dir ) return notify_fail("无法读取有效的 “区域目录” 设置，请查正再试。\n");
	if( dir[0] != '/' || dir[strlen(dir)-1] != '/' )
		return notify_fail("目录为："+dir+"，它并不是一个绝对路径名，请查正再试。\n");
	write("当前目录设定为："+dir+"-- 正在获得地图设置...\n");
		return 1;
}





//读取第n幅地图 ,设置地图 ,添加 坐标--〉文件名
int read_map( int n)
{
	mapping counter = ([ ]);        // 计数器,统计重复房间次数
	
	string  s1,s2 ,line,checking ,temp_name1,temp_name2 ;
	int  m ,x=0 ,y ,left ,right,i=0,c=0,a;
	

	map = ({ }); m = 0;

	foreach( checking in f_len )//每次都从头读起，似乎可以优化一下
	{
		i++;
		if( strsrch( checking , "#map_end#" ) != -1 )
		{
			if(sizeof(map))	break;
		}
		if( m ) map += ({ checking });
		if( strsrch( checking , "#map#" ) != -1 )
		{
			c ++;    //找到第c幅地图
			if(c==n)
			{
				m=1;
			map_start_line=i;}

		}
	}
	sizeofmap = sizeof(map);
	if( !map || !sizeofmap )
		return notify_fail("无法读取第"+n+"幅地图设置，请查正再试。\n");

	write("第"+n+"幅地图读取成功！正在进行地点设置>>\n");

	//添加本地特色描述
	while(strsrch( map[x] , ":" ) != -1)  //有当前房间的特别的长描述
	{
		sscanf(  map[x], "%s:%s",s1 ,s2 );//s1文件名  s2长描述
		
		s1= replace_string( s1, " ", "" ); 
		short_to_long[s1]=s2;		
		x++;
	}
	
	// 将获得的 map 信息拆分，获得坐标-〉文件名
	allfile = ({ });
	//for(x=0;x<sizeofmap;x++)
	for(x=x;x<sizeofmap;x++)
	
	{
		line = map[x];				//一行行来
		if( !line|| !sizeof(line)) continue;	//	�
		linelen=sizeof(line);	

		while((a=strsrch( line , "/d/" )) != -1)
		{
		  while(strsrch(  "1234567890abcdefghijklmnopqrstuvwxyz_/"  , line[a]) != -1 
		  			&& strsrch(  "1234567890abcdefghijklmnopqrstuvwxyz_/"  ,line[a+1]) != -1) //防止太紧密地图中靠近别的 /引起出错
		  {
		  if(line[a]=='/') line[a]='*';
		  
		  a++;
		  if(a+1==linelen)break;
		  
		  }
		  	
		}
		
		
		map[x] = line;
	 
		line = replace_nouse_to_blank( line );  //只留下文件名，其他转空格
		
		xy2filename[x]=([]);                    //格式 ({ x:({ y : filename})})
		for(y=0;y<linelen;y++)
		{
			if(line[y]==' ') continue;

			//遇到文件里的short了
			right=y; left=y;
			while((right!=(linelen-1))&&line[right+1]!=' ') y=++right;
			checking = line[left..right];       //文件里的short
			
			checking=replace_string(checking, ".", "");//去掉为延长文件名而添加的 ^符号
			
			if(checking[0]=='*') //把连接的其他目录下的路径恢复正常
			{
				checking=replace_string(checking, "*", "/");
				short_to_filename[checking]=checking;
				filename_to_short[checking]=filename_to_short[checking[strsrch(checking,"/",-1)+1..]];				
			}

		
			if( !short_to_filename[checking] )  // 检查每个的有效性
			 return	notify_fail("地图设置地点"+checking+"无对应文件名 ...请添加后再运行本程序\n");
			 
			 if(undefinedp(counter[checking]))  //中文短描述第一次出现
			{
			counter[checking]=0; 					  //开始统计...
			xy2filename[ x][left]=short_to_filename[checking] ;	//添加 坐标--〉文件名
			
			if(checking[0]!='/')                                   //把连接的其他目录下的文件名去掉
			allfile += ({ xy2filename[x][left] });			//添加文件名
			}
			else		//房间名称第n次出现，依次叫做file file1 file2。。。

			{
			counter[checking]=counter[checking]+1;   		  //统计次数
			temp_name1=short_to_filename[checking];	  		 //设置重复房间的mapping ,
			temp_name2=short_to_filename[checking]+counter[checking];//英文文件名后面加了数字，

			filename_to_short[temp_name2]=filename_to_short[temp_name1];//但中文名称不变

			xy2filename[x][left] =temp_name2   ;			//添加 坐标--〉文件名
			
			allfile += ({temp_name2 });				//添加文件名

			}
		}
	}

	if( !allfile || !sizeof(allfile) ) return notify_fail("无法读取地图地点，请查正再试。\n");

	write("地图设置成功！在地图里，共有 "+sizeof(allfile)+" 个地点。开始计算方向 ...\n");

	return 1;
}


 //设置所有出口
int set_exits( string *map )
{
	int x, y;
	mixed foo;
	string line;

	all_exits = ([ ]);

	// 以每一个连接符为单位，开始计算方向
	for(x=0;x<sizeofmap;x++)
	{	line = map[x];
		
	 	if(strsrch( line , ":" ) != -1) continue;//防止长描述里面有连接符号,地图内本身不能出现:
		linelen = sizeof(map[x]);
		for(y=0;y<linelen;y++)
		{
			foo = map[x][y];

			if(member_array(foo ,all_foos)==-1) continue;

			if(foo=='-'||foo=='<'||foo=='>')
			{
				if(y==0||y==linelen-1)
				return notify_fail("文件第"+(x+1+map_start_line)+"行 ，"+(y+1)+"列  - ,< ,> 连接错误\n");

			}
			if(foo=='|'||foo=='A'||foo=='V'||foo=='E'||foo=='!'||foo=='{')
			{
				if(x==0||x==sizeofmap||(y+1)>sizeof(map[x-1])||(y+1)>sizeof(map[x+1]))
		 		return notify_fail("文件第"+(x+1+map_start_line)+"行 ,"+(y+1)+"列 | ,A ,V ,E ,! { 连接错误\n");

			}
			if(foo=='/')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||y>sizeof(map[x+1]))
				return notify_fail("文件第"+(x+1+map_start_line)+"行 ,"+(y+1)+"列  /  连接错误\n");
			}
			if(foo=='\\')
			{
				if(x==0||x==sizeofmap||y==0||y>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
				return notify_fail("文件第"+(x+1+map_start_line)+"行 ,"+(y+1)+"列  \\  连接错误\n");
			}

			if(foo=='X')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
					return notify_fail("文件第"+(x+1+map_start_line)+"行 ,"+(y+1)+"列   x  连接错误\n");
			}
			 //过滤掉多符相连时的中间的符,可能还有交叉  aaa-----bbb等,只检查左边或上边
			 //如果是某个连接符，且左边或上边延伸方向上不是这个符，就连接房间
			if((member_array(foo,({'-','<','>'}))!=-1&&map[x][y-1]!=foo)
			||(member_array(foo,({'|','A','V','E','!','{'}))!=-1&&map[x-1][y]!=foo)
			||(foo=='/' &&map[x-1][y+1]!=foo)
			||(foo=='\\'&&map[x-1][y-1]!=foo)
			||foo=='X'
			 )
			if(!get_exit( foo,x ,y )) return  notify_fail( "无法设置出口1\n"  );

		}
	}
	if( !all_exits || !sizeof(all_exits) ) return notify_fail( "无法设置出口2\n"  );
	write("方向读取完毕！建立文件：\n");
	return 1;
}

//              连接符号 位置x  位置y
int get_exit( mixed foo ,int x  ,int y )
{
	// 连接符联的两个文件名 name1:较左或较上的  name2:较右或较下的
	string name1 , name2;

	//-------------横向连接符--------------------
	if(foo=='-'||foo=='<'||foo=='>')
	{
		name1 = xy_to_filename( x, y ,0,-1 );
		name2 = xy_to_filename( x, y ,0,1 );

		if(foo=='-')
		return add_exit( name1, "east", name2 )&&add_exit( name2 , "west", name1 );

		if(foo=='<')
		return add_exit( name1, "eastdown", name2 )&&add_exit( name2 , "westup", name1 );

		if(foo=='>')
		return add_exit( name1, "eastup", name2 )&&add_exit( name2 , "westdown", name1 );

	}
	//-------------纵向连接符--------------------
	if(foo=='|'||foo=='A'||foo=='V'||foo=='E'||foo=='!'||foo=='{')
	{
		name1 = xy_to_filename( x, y ,-1,0 );
		name2 = xy_to_filename( x, y  ,1,0 );

		if(foo=='|')
		return add_exit( name1, "south", name2 )&&add_exit( name2, "north", name1 );

		if(foo=='A')
		return add_exit( name1, "southdown", name2 )&&add_exit( name2, "northup", name1 );

		if(foo=='V')
		return add_exit( name1, "southup", name2 )&&add_exit( name2, "northdown", name1 );

		if(foo=='E')
		return add_exit( name1, "downstairs", name2 )&&add_exit( name2, "upstairs", name1 );
		                       //下楼                                    上楼

		if(foo=='!')
		return add_exit( name1, "down", name2 )&&add_exit( name2, "up", name1 );

		if(foo=='{')
		return add_exit( name1, "climbdown", name2 )&&add_exit( name2, "climbup", name1 );


	}

	//-----西南-东北-------------------------
	if(foo=='/')
	{
		name1 = xy_to_filename( x, y ,-1,1 );
		name2 = xy_to_filename( x, y ,1,-1 );

		return add_exit( name1, "southwest", name2 )&&add_exit( name2, "northeast", name1 );

	}
	//-----西北-东南-------------------------
	if(foo=='\\')
	{
		name1 = xy_to_filename( x, y ,-1,-1 );
		name2 = xy_to_filename( x, y ,1,1 );

		return  add_exit( name1, "southeast", name2 )&&add_exit( name2, "northwest", name1 );
	}

	//---------交叉连接-------------------------
	if(foo=='X')
	{
	// x 相当于 /，\ 两者在一个位置上,递归调用两次
		if(!get_exit( '/' , x  , y )) return 0;
		if(!get_exit( '\\' , x  , y )) return 0;
		return 1;
	}

}

 //由地址得到文件名 x1 y1是用来解决过滤掉多符相连
 // map[x][y]        x第几行  ，y第几列 , x相对偏移，    y相对偏移
string xy_to_filename( int x ,   int y  ,  int x1  ,    int y1 )
{
	int  left,linelen ;
	string  line ;
	//过滤掉重复的连接符，如 aaaa-------bbbb 只检查右边或下边
	do{
		x+=x1 ; y+=y1 ;
		line = map[x];
		linelen =sizeof( line );
		if(( (y+1)>linelen)||line[y]==' ')
		{	write("地图第"+(x+1+map_start_line)+"行,第"+(y+1)+"列处无文件名文字，附近连接符连接错误。\n");
			return 0;
		}
		if( member_array( line[y] ,all_foos )==-1 )  break;    //找到 房间名称 了
	  }while(1);

	left = y;

	//获得文件名起始坐标
	if(left>0)
	{
						 //出现......   意味着已经到了房间名称最左边
		while(member_array(line[left-1] ,({' '})+all_foos)==-1)
		{
	 	left--;
	 	if(left==0) 	break;
	 	}
	}

	//获得文件名
	return xy2filename[x][left];
}

//设置出口        房间1----〉出口-------房间2
int add_exit( string n1, string exit, string n2 )
{
	if((!n1)||(!n2)) return 0;
	if( undefinedp( all_exits[n1] ) )
		all_exits[n1] = ([ ]);
	all_exits[n1][exit] = n2;
	return 1;
}

//获得出口信息
string get_exit_msg( string file )
{
	string longexitmsg="", msg = "" , exit , *exits=({"east", "eastup", "eastdown", "west", "westup", "westdown",
			    "north", "northup", "northdown","south", "southup", "southdown",
			    "northeast", "northwest", "southeast", "southwest" ,
			    "upstairs","downstairs",  "up","down" ,"climbup","climbdown"

			});
	mapping exit2long=([
	"east":"东边去就是",
	 "eastup":"东边过去高处就是",
	  "eastdown":"东边低处往下就是", 
	 
	 "west":"西面走就是去", 
	  "westup":"西面过去高处就是去",
	   "westdown":"西面低处往下就是去",
	   
	 "north":"北边走就到了",
	  "northup":"北边高处走就到了",
	   "northdown":"北边低处往下就到了",
	  
	 "south":"南面就是", 
	  "southup":"南面过去高处就是", 
	   "southdown":"南面低处向下就是",
	   
	 "northeast":"东北方向可以到",
	  "northwest":"西北方向去往",
	   "southeast":"东南方向到达", 
	   "southwest" :"西南方向连着",
	
	 "upstairs":"沿楼梯往上就是",
	 "downstairs":"下楼就到了",  
	   "up":"向上似乎是通往",
	   "down" :"朝下似乎可以到", 
	 "climbup":"沿着绳子往上爬似乎可以到",
	 "climbdown":"沿着绳子向下似乎可以到达"
	
	]);
	longexitmsg="";
	if(undefinedp( all_exits[file] ) )
	{
		all_exits[file]=([]);
		 all_exits[file]["long"]="";//没有出口描述
		  return "";
	} 
	 
	foreach( exit in exits)  //逐一查询 ,添加
	{
		if( !undefinedp( all_exits[file][exit] ) )
		{			

			if( all_exits[file][exit][0]=='/')//其它目录连接
		 		msg += sprintf("%-16s","\n		\""+ exit +"\"")+":\""+all_exits[file][exit]+"\",";			
			else
				msg += sprintf("%-16s","\n		\""+ exit +"\"")+": __DIR__\""+all_exits[file][exit]+"\",";	
							 
				longexitmsg+= exit2long[exit]+filename_to_short[all_exits[file][exit]]+",";		
		}
	}
	
	longexitmsg+=",";
	longexitmsg=replace_string( longexitmsg, ",,","。" );
	
	all_exits[file]["long"] = longexitmsg;
	
	msg+=",";
	return replace_string( msg, ",,","" ) + "\n";
}

//建立文件            目录      文件名
void create_it( string dir, string file )
{
//	int t;
	string alltext,exit_msg; 
	
	if( !filename_to_short[file] )
	{
		write("无法建立 "+file+" 。\n");
		return;
	}
	write(">> "+filename_to_short[file]+": "+dir+file+".c 建立中.....");
	
	exit_msg =get_exit_msg(file);//必须先运行函数，否则出口连接文字未设置
	
	alltext = "//Created by command: \"auto_create_area.c\" v1.5
// File: "+ dir + file + ".c   "+ctime(time())+
"\n//#include <ansi.h>
inherit ROOM;
void create()
{
	set(\"short\", \""+filename_to_short[file]+"\");
	set(\"long\",@LONG\n"+short_to_long[filename_to_short[file]]
	+ all_exits[file]["long"]
	+"\nLONG\n);
	set(\"exits\", ([ /* sizeof() == "+(sizeof( all_exits[file])-1)+" */"+exit_msg+" ]));
/*	set(\"objects\", ([ // sizeof() ==
  		__DIR__\"npc/...\" : 1,
		]));
*/
        set(\"outdoors\", __DIR__);
	setup();
	//replace_program(ROOM);
}
";
	write(   write_buffer("/test"+dir + file + ".c" , 0 ,alltext )  ? "成功\n":"失败\n" );
}

int help(object me)
{
	string msg = "
===========================================
    auto_create_area 文件名
    例如 auto_create_area /d/xj/abc
将根据该abc文件设置，生成一片简单区域源文件，
剩下的工作就是具体修改房间的定义 。
请注意，各部分必不可少，而空行会被省略。
  ***** 以下是示范文件格式 ******

#create area file#
//
#list#
大厅:dating
卧室:woshi
厨房:chufang:这里是一个烟熏火燎，香气四溢的厨房
阳台:yangtai
大门口:damenkou
门外:menwai
小路:xiaolu
#list_end#

#dir#	/d/area1/
//文件生成位置实际在/test/d/area1/
#map#
大厅-卧室-厨^^^房
     |  \\  |  \\
   阳台-大门口-门外-----小路
#map_end#
//位置可以写任意行注释内容，不会被读取。
  ********************************\n";

string msg1="
请注意，为了使格式规范，请遵守以下规则：

1、目录请使用绝对路径，即开头及结尾都需要 / 符号。
2、房间中文名，请勿使用空格及
   - ,| ,/ ,\\ ,E, A, v ,V ,! ,{ ,< ,> ,x ,X.
3、房间中文名及文件名对照列表内的所有空格将被忽略，
   并请使用 \":\" 符号连接
4、方向为：上北下南左西右东
5、横向房间连接，使用 \"-\" \"<\" \">\" ，房间名之间无空格。
6、纵向房间连接，使用 \"|\" \"A\" \"v\" \"V\" 。.
7、西斜向房间连接，使用 \"/\"。
8、东斜向房间连接，使用 \"\\\"。
9、交叉连接用 x或 X.
10、A,v或V,< ,>,尖尖所指是地势较高的位置.
11、连接符可以连续使用，也可以相互穿越,房间名称中间\n可用^^^符号来延长以便有足够位置和其它房间相连";


string msg2="\n
   7,8 例子                       9 例子
      abc  c,f 位置必须有中文名字   aa bb
      d/e                             x
      fgh                           cc dd
                表示aa dd相连，bb cc相连,迷宫里有时用到

   11例子   房间1
             |
    房间3--------- 房间4    表示 1 2 相连，3 4 相连
             |
          房间2

如不明白，请对照上文示范格式。仍不明白或有错误，
请予www.mudbuilder.com论坛 留言。

    写好该文件后，输入本指令即可。
==========\n";

	me->start_more( msg );
	me->start_more( msg1);
	me->start_more( msg2);
	return 1;
}

int main( object me, string arg )
{
	int map_i; // 第几幅地图
	if(!arg) return help(me);
		assure_file( "/test/ " );
		if( file_size( "/test" ) != -2 )
			return notify_fail("无法建立该目录：/test\n");
	if(!read_file_msg( arg )) return 0;
	alldir=({}) ;
	for( map_i=1;map_i<=map_number;	map_i++)
	{
	//	short_to_long = short_to_long_bk+([]);
		reset_eval_cost();
		if(!read_dir(map_i ) || !read_map( map_i))
			return 0;
		
		assure_file( "/test"+dir+" " );
		if( file_size( "/test"+dir ) != -2 )
		return notify_fail("无法建立该目录：/test"+dir+"---\n");
		//write("\nok1\n");测试用的

		if(!set_exits( map)) 	return 0 ;
		//write("\nok2\n");测试用的

	// 建立在地图内的房间
		foreach( filename in allfile ) create_it( dir, filename );

		write("\n建立完毕！共生成 /test"+dir+" 下 "+sizeof(allfile)+" 个文件。\n");
		
	}
	write("\n所有文件建立完毕！\n");
	return 1;
}

