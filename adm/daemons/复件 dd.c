#include <ansi.h>
inherit F_DBASE;
#define WORLD_FILE "/d/wiz/xj"
int sizeofmap,linelen,map_start_line;// 地图行数 本行长度 地图起始行数 地图总数
mapping all_exits = ([ ]);//总出口  ([房间名1,([方向 中文房间名 ])])
mapping all_data = ([ ]);//除文件名和短描述对照mapping 以外的所有数据集合
/*
获得目录中文名称 all_data["/d/baihe/"]["cname"] ===>白河村
获得目录文件名称对应房间信息设置 all_data["/d/baihe/shulin"]["roomset"] ==>具体设置的字符串，格式分析见下 room_set()
*/
string pinyin(string hanzi);
string *allfile,*map,dir,file;//区域地图文件名，区域地图文本，区域目录名，当前文件名
string *f_line,*alldir=({});// 总地图，总mulu
mapping filename_to_short = ([ ]);// filename-->中文房间名
mapping short_to_set = ([ ]);// short-->房间所有设置项长描述
mapping short_to_filename = ([ ]);// 中文房间名-->filename
mapping xy2filename = ([ ]);// 地址-->filename
        // map[x][y]  x第几行  ，y第几列,x相对偏移，  y相对偏移
string xy_to_filename(int x,int y,int x1,int y1);
int add_exit(string n1,string exit,string n2);
string replace_blank(string str);
string str_format(string name,string long_desc);
int room_set(object room,string arg);
/*******************************************************************
 '-','<','>',西-东，西高-东低，西低-东高，
 '|','V','A',北        北低      北高
             |          V         A
             南  ，   南高  ，  南低
 '/','\','X',东北  西北       交错连接
              /      \          X
          西南     东南
几个特殊的
 'E','!'  '{'      // 楼上  上   高 爬上/爬下
                   //  E     !   {  绳子
                   // 楼下，下   低
********************************************************************/
//所有连接符
mixed temp,*all_fus=({ '-','<','>','|','V','A','/','\\','X','E','!','{'  });
int test_file();
int read_dir();
int read_room_list();
int read_map(string dirname);
int get_exit(mixed fu,int x,int y);
// 用于检测文件名(英文名)是否有效,防止把连接符作为文件名
// 如果希望用一些特别的字符（如汉字等）作为 write_file() 的
// 文件名，，请更改本函数，或使本函数直接 return 1 .
int valid(string n)
{
	string l = "1234567890abcdefghijklmnopqrstuvwxyz_";
	mixed t;
	if(!n) return 0;
	foreach(t in l)
		if(n[0] == t) return 1;
	return 0;
}
//只留下文件名，其他转空格
string replace_nouse_to_blank(string s)
{
	string *all_fu= ({"-","|","/","\\","X","A","V","<",">","E","!","{"});
	foreach(temp in all_fu)
	     s = replace_string(s,temp," ");
	return s;
}
int read_file_msg()
{
 	return 	test_file() &&  read_room_list();
}
//验证文件是否可用,读入世界文件所有数据行
int test_file()
{
	string file;
	if(file_size(WORLD_FILE)==-1) 
	{write("xj文件不存在。\n");return 0; }	
	if(!file = read_file(WORLD_FILE))
	{write("无法读取该文件："WORLD_FILE"\n");return 0; }
	
	if(strsrch(file,"	") != -1)
		{write("该文件含有TAB跳格,因为每个人的长度定义可能不一致，会导致出错,请全部替换为空格\n");return 0; }
	if(strlen(file) < 10) 
	{write("该文件内容太少，无法作为有效资料。\n");return 0; }
	
	if(strsrch(file,"#create area file#") == -1
	 || strsrch(file,"#dir#") == -1
	 || strsrch(file,"#list#") == -1
	 || strsrch(file,"#list_end#") == -1
	 || strsrch(file,"#map#") == -1
	 || strsrch(file,"#map_end#") == -1)
		{write("该文件资料不足，无法建立场景。请参阅示例获得格式规范说明。\n");return 0; }	
			
	f_line = explode(file,"\n");
	
	return 1;
}
//读取 房间名称列表
int read_room_list()
{
	string *temp_arr,checking;
	int m;
	// ok,make a file_name list for all rooms.
	temp = ({ });
	m = 0;
	// get rooms list
	foreach(checking in f_line)
	{
	  	if(strsrch(checking,"#list_end#") != -1)break;
		if(m) temp += ({ checking });
		if(!m && strsrch(checking,"#list#") != -1)m = 1;//找到列表了
	}
	if(!temp || !sizeof(temp))
		{write("无法读取有效的房间名称列表，请查正再试。\n");return 0; }
	m = sizeof(temp);
	short_to_filename = ([ ]);// 中文房间名-->filename
	filename_to_short = ([ ]);// filename-->中文房间名
	// 进行有效判断，并生成2个对应的 map ，方便调用
	foreach(checking in temp)
	{
		if(sizeof(temp_arr = explode(checking,":"))!=2)
			{write("房间名称列表有的缺:或太多：，请查正再试。\n");return 0; }
        checking =replace_string(checking," ","");
		sscanf(checking,"%s:%s",temp_arr[0],temp_arr[1]);
		if(sizeof(temp_arr) >1 && valid(temp_arr[1])) //房间的文件名合理
		{
			if(!undefinedp(short_to_filename[ temp_arr[0]]))
			{write("房间名称列表" + temp_arr[0] +"重复定义，请查正再试。\n");return 0; }
			
			short_to_filename[ temp_arr[0] ] = temp_arr[1];
			if(!undefinedp(filename_to_short[ temp_arr[1] ]))
			{write("文件名称列表"+temp_arr[1]+ "重复定义，请查正再试。\n");return 0; }
			
			filename_to_short[ temp_arr[1] ] = temp_arr[0];
		}
	}
  	//有些无聊，不过还是加上，防止存在没考虑到的问题
	if(!filename_to_short || !short_to_filename)
		{write("无法获得有效的房间名称列表，请查正再试。\n");return 0; }
	return 1;
}
//读取第n 目录设置
int read_dir()
{
	// ok. get "alldir" first
	string s1,s2;
	int i;
	//如果没有所有目录//alldir未定义，那么就初始化它
		alldir= filter_array(f_line,(: strsrch($1,"#dir#") != -1 :));
		if(!alldir || !arrayp(alldir) || !sizeof(alldir))
		{write("无法读取有效的 区域目录 设置，请查正再试。\n");return 0; }
		
		
		for(i=0;i<sizeof(alldir);i++)
		{
		sscanf(alldir[i],"#dir#%s %s",s1,s2);
		if(s1[0] != '/' || s1[<1] != '/')
		{write("目录"+s1+"，它并不是一个绝对路径名，前后必须有/,请查正再试。\n");return 0; }
		alldir[i]=  replace_string(s1," ","");
		s2=replace_string(s2," ","");//
		all_data[s1]=([]);
		all_data[s1]["cname"]=s2;//获得区域中文名称,以后可以加入战场五行参数
		}
		if(file_size("/d/wiz/alldir")==-1)
		write_file("/d/wiz/alldir",implode(alldir,"\n"),1);//输出所有区域目录，方便后续编程用
		return 1;
}
//读取dir_name地图,设置地图,添加 坐标--〉文件名
int read_map(string dir_name)
{
	mapping counter = ([ ]);// 计数器,统计重复房间次数
	string s1,s2,line,checking,temp_name1,temp_name2,dirname;
	int m,n,x,y,left,right,i,c,a;
	n=0;x=0;i=0;c=0;
		dirname=dir_name;
	map = ({ });m = 0;
//log_file("dd.log",dirname+"目录地图读取...\n");
	foreach(checking in f_line)//每次都从头读起
	{
		 i++;
		if(strsrch(checking,"#dir#"+dirname+" ") != -1 ||n)
		{
			n++;//找到地图了，每行都进来对照一下
			if(strsrch(checking,"#map_end#") != -1)	break;
			if(m) map += ({ checking });
			if(strsrch(checking,"#map#") != -1)//地图开始输出每行数据了
			{
				m=1;
				map_start_line=i;//留着地图查错时输出位置用
			}
		}
	 }
 //    foreach(checking in map) log_file("dd.log",checking+"\n");
	sizeofmap = sizeof(map);
	if(!map || !sizeofmap)
	{write("无法读取"+dirname+"地图设置，请查正再试。\n");return 0;}
//log_file("dd.log",dirname+"目录地图读取成功！正在进行地点设置>>\n");
	//添加房间细节设置
	while(strsrch(map[x],":") == -1) x++;//跳过空行
	while(x<sizeofmap)  //有当前房间长描述 && map[x][0]!=' '&& sizeof(map[x])>3
	{
        if(strsrch(map[x],":") == -1){x++;continue;}//跳过无房间设置的空白行
		if(sscanf(map[x],"%s:%s",s1,s2)==2)//s1文件short名  s2长描述 long
            short_to_set[s1]= map[x]+"#exitlong#\n";//出口连接文件信息
		else log_file("dd.log","地图"+ map_start_line+x+"行设置错误\n");
		//while(map[x+1][0]==' '&& strsrch(map[x+1],":") != -1)  //开始有空格，并且有：，说明是房间的设置项
		x++;
		while(x<sizeofmap)
		{
        if(strsrch(map[x],":") != -1 && map[x][0]!=' ')break;//下个房间标志
        if(strsrch(map[x],":") != -1)
            short_to_set[s1]+= map[x]+"\n";
	//	log_file("dd.log",dirname+"短--长 mapping 添加特征部分 设置成功！\n");
		x++;
		}
	//	log_file("dd.log",dirname+x+"行设置成功！\n");
	}
	//log_file("dd.log",dirname+"目录地图设置添加本地特色描述读取成功！\n");
	//reset_eval_cost();
	// 将获得的 map 信息拆分，获得坐标-〉文件名
	allfile = ({ });
	//地图连接部分
	for(x=0;strsrch(map[x],":") == -1;x++)
	{
		line = map[x];//一行行来
		linelen=sizeof(line);
		if(!line|| !linelen) continue;//空白行
		if((a=strsrch(line,"/d/")) != -1) //找到和其他地图连接，把里面所有/换为*,以免和连接符混淆
		{
		  while(a<linelen) //字符串是文件名一部分
		  {
			if(line[a]=='/'&& strsrch("1234567890abcdefghijklmnopqrstuvwxyz_",line[a+1]) != -1)
			{
			//    /后面还有字母，应该是文件名的一部分
                line[a]='*';
			}
			a++;
		  }
		  //log_file("dd.log",dirname+"/修改为*成功！\n");
		}
		map[x] = line;
		line = replace_nouse_to_blank(line);//只留下文件名，其他转空格
		xy2filename[x]=([]);//由行、列获得文件名 格式 ({ x:({ y : filename})})
		for(y=0;y<linelen;y++)
		{
			if(line[y]==' ') continue;
			//遇到文件里的short了
			right=y;left=y;
			while((right!=(linelen-1))&&line[right+1]!=' ') y=++right;
			checking = line[left..right];//文件里的short
			checking=replace_string(checking,".","");//去掉为延长文件名而添加的.符号
			if(checking[0]=='*') //把连接的其他目录下的路径恢复正常
			{
				checking=replace_string(checking,"*","/");
				short_to_filename[checking]=checking;
				filename_to_short[checking]=
			 		all_data[checking[0..strsrch(checking,"/",-1)]]["cname"]+
					filename_to_short[checking[strsrch(checking,"/",-1)+1..]];
			}
			if(!short_to_filename[checking])  // 检查每个的有效性,地图设置地点"+checking+"有无对应文件名
			{
			short_to_filename[checking]=pinyin(checking);
			filename_to_short[short_to_filename[checking]]=checking;
            /*            
            i=2;//检查是否传送房间，修正short，去掉中文房间名后面传送用的定位串，主要用于试炼窟8、9层
            while(short_to_filename[checking][<i..<1]==checking[<i..<1])
                {filename_to_short[short_to_filename[checking]]=checking[0..<(i+1)];
                    i+=2;
                }*/
			//检查是否传送房间，修正short，去掉中文房间名后面传送用的定位串，主要用于试炼窟8、9层
			 if(short_to_filename[checking][<2..<1]==checking[<2..<1])
                filename_to_short[short_to_filename[checking]]=checking[0..<3];                  
			}
			if(undefinedp(counter[checking]))  //中文房间名短描述第一次出现
			{
			counter[checking]=0;//开始统计...
			xy2filename[ x][left]=short_to_filename[checking];//添加 坐标--〉文件名
			if(checking[0]!='/')                                   //不添加连接的其他目录下的文件名
				{	allfile += ({ xy2filename[x][left] });//添加文件名
					//log_file("dd.log",dirname+checking+"文件开始设置！\n");
				}
			}
			else		//房间名称第n次出现，依次叫做file file1 file2。。。
			{
			counter[checking]=counter[checking]+1;//统计次数
			temp_name1=short_to_filename[checking];		 //设置重复房间的mapping,
			temp_name2=short_to_filename[checking]+counter[checking];//英文文件名后面加了数字，
			filename_to_short[temp_name2]=filename_to_short[temp_name1];//但中文名称不变
			xy2filename[x][left] =temp_name2;//添加 坐标--〉文件名
			allfile += ({temp_name2 });//添加文件名
			}
		}
	}
	if(!allfile || !sizeof(allfile)) { write("无法读取地图地点，请查正再试。\n");return 0;}
	//write("地图设置成功！在地图里，共有 "+sizeof(allfile)+" 个地点。开始计算方向 ...\n");
	return 1;
}
 //设置所有出口
int set_exits(string *map)
{
	int x,y;
	mixed fu;
	string line;
	all_exits = ([ ]);
	// 以每一个连接符为单位，开始计算方向
	for(x=0;x<sizeofmap;x++)
	{	line = map[x];
	 	if(strsrch(line,":") != -1) continue;//防止长描述里面有连接符号,地图内本身不能出现:
		linelen = sizeof(map[x]);
		for(y=0;y<linelen;y++)
		{
			fu = map[x][y];
			if(member_array(fu,all_fus)==-1) continue;
			if(fu=='-'||fu=='<'||fu=='>')
			{
				if(y==0||y==linelen-1)
				{write("文件第"+(x+1+map_start_line)+"行 ，"+(y+1)+"列  -,<,> 连接错误\n");return 0;}
			}
			if(fu=='|'||fu=='A'||fu=='V'||fu=='E'||fu=='!'||fu=='{')
			{
				if(x==0||x==sizeofmap||(y+1)>sizeof(map[x-1])||(y+1)>sizeof(map[x+1]))
		 		{write("文件第"+(x+1+map_start_line)+"行,"+(y+1)+"列 |,A,V,E,! { 连接错误\n");return 0;}
			}
			if(fu=='/')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||y>sizeof(map[x+1]))
				{write("文件第"+(x+1+map_start_line)+"行,"+(y+1)+"列  /  连接错误\n");return 0;}
			}
			if(fu=='\\')
			{
				if(x==0||x==sizeofmap||y==0||y>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
				{write("文件第"+(x+1+map_start_line)+"行,"+(y+1)+"列  \\  连接错误\n");return 0;}
			}
			if(fu=='X')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
					{write("文件第"+(x+1+map_start_line)+"行,"+(y+1)+"列 x 连接错误\n");return 0;}
			}
			 //过滤掉多符相连时的中间的符,可能还有交叉  aaa-----bbb等,只检查左边或上边
	//如果是某个连接符，且左边或上边延伸方向上不是这个符，即该连接符第一次出现，就连接房间，
    //如果连接符交叉，可能会设置2次或更多次，浪费cpu
			if((member_array(fu,({'-','<','>'}))!=-1&&map[x][y-1]!=fu&&map[x][y-2]!=fu) //交叉连接打断了就多检查一下，下面几种跨行，检查麻烦
			||(member_array(fu,({'|','A','V','E','!','{'}))!=-1&&map[x-1][y]!=fu)
			||(fu=='/' &&map[x-1][y+1]!=fu)
			||(fu=='\\'&&map[x-1][y-1]!=fu)
			||fu=='X')
			if(!get_exit(fu,x,y))
                {write("文件第"+(x+1+map_start_line)+"行,"+(y+1)+"列处"+(string)fu+"无法连接出口\n");return 0;}
		}
	}
	if(!all_exits || !sizeof(all_exits)) {write("无法设置出口2\n");return 0;}
	//write("方向读取完毕！建立文件：\n");
	return 1;
}
//              连接符号 行位置x  列位置y
int get_exit(mixed fu,int x,int y)
{
	// 连接符联的两个文件名 name1:较左或较上的  name2:较右或较下的
	string name1,name2;
	//-------------横向连接符--------------------
	if(fu=='-'||fu=='<'||fu=='>')
	{
		name1 = xy_to_filename(x,y,0,-1);
		name2 = xy_to_filename(x,y,0,1);
		if(fu=='-')
		return add_exit(name1,"east",name2)&&add_exit(name2,"west",name1);
		if(fu=='<')
		return add_exit(name1,"eastdown",name2)&&add_exit(name2,"westup",name1);
		if(fu=='>')
		return add_exit(name1,"eastup",name2)&&add_exit(name2,"westdown",name1);
	}
	//-------------纵向连接符--------------------
	if(fu=='|'||fu=='A'||fu=='V'||fu=='E'||fu=='!'||fu=='{')
	{
		name1 = xy_to_filename(x,y,-1,0);
		name2 = xy_to_filename(x,y,1,0);
		if(fu=='|')
		return add_exit(name1,"south",name2)&&add_exit(name2,"north",name1);
		if(fu=='A')
		return add_exit(name1,"southdown",name2)&&add_exit(name2,"northup",name1);
		if(fu=='V')
		return add_exit(name1,"southup",name2)&&add_exit(name2,"northdown",name1);
		if(fu=='E')
		return add_exit(name1,"downstairs",name2)&&add_exit(name2,"upstairs",name1);
		                       //下楼                                    上楼
		if(fu=='!')
		return add_exit(name1,"down",name2)&&(strsrch(dir,"shilianku") != -1||add_exit(name2,"up",name1));//试炼窟.扬州井底只能下不能上
		//return add_exit(name1,"down",name2)&&add_exit(name2,"up",name1);//扬州井底井口分两个地图，不用这句||strsrch(name2,"jingdi") != -1
		if(fu=='{')
		return add_exit(name1,"climbdown",name2)&&add_exit(name2,"climbup",name1);
	}
	//-----西南-东北-------------------------
	if(fu=='/')
	{
		name1 = xy_to_filename(x,y,-1,1);
		name2 = xy_to_filename(x,y,1,-1);
		return add_exit(name1,"southwest",name2)&&add_exit(name2,"northeast",name1);
	}
	//-----西北-东南-------------------------
	if(fu=='\\')
	{
		name1 = xy_to_filename(x,y,-1,-1);
		name2 = xy_to_filename(x,y,1,1);
		return add_exit(name1,"southeast",name2)&&add_exit(name2,"northwest",name1);
	}
	//---------交叉连接-------------------------
	if(fu=='X')
	{
	// x 相当于 /，\ 两者在一个位置上,调用两次
		if(!get_exit('/',x,y)||!get_exit('\\',x,y)) return 0;
		return 1;
	}
}
 //由坐标地址得到文件名 x1 y1是用来解决过滤掉多符相连
 // map[x][y]        x第几行  ，y第几列,x相对偏移，    y相对偏移
string xy_to_filename(int x,int y,int x1,int y1)
{
	int left,linelen;
	string line;
	//过滤掉重复的连接符，如 aaaa-------bbbb
	do{
		x+=x1;y+=y1;
		line = map[x];
		linelen =sizeof(line);
		if(((y+1)>linelen)||line[y]==' '||y<0)
		{	write("地图第"+(x+1+map_start_line)+"行,第"+(y+1)+"列处无文件名文字，附近连接符连接错误。\n");
			return 0;
		}
		if(member_array(line[y],all_fus)==-1)  break;//找到 房间名称 了
	  }while(1);
	left = y;
	//获得文件名起始坐标
	if(left>0)
	{
						 //出现......   意味着已经到了房间名称最左边
		while(member_array(line[left-1],({' '})+all_fus)==-1)
		{
	 	left--;
	 	if(left==0) 	break;
	 	}
	}
	//获得文件名
	return xy2filename[x][left];
}
//设置出口        房间1----〉出口-------房间2
int add_exit(string n1,string exit,string n2)
{
	if((!n1)||(!n2)) return 0;
	if(undefinedp(all_exits[n1]))
		all_exits[n1] = ([ ]);
	all_exits[n1][exit] = n2;
	return 1;
}
//获得出口信息
string get_exit_msg(string file)
{
	string longexitmsg="",msg = "",exit,*exits=({"east","eastup","eastdown","west","westup","westdown",
			    "north","northup","northdown","south","southup","southdown",
			    "northeast","northwest","southeast","southwest",
			    "upstairs","downstairs","up","down","climbup","climbdown"
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
	 "upstairs":"沿阶梯往上走就是",
	 "downstairs":"沿阶梯往下走就到了",
	   "up":"上方似乎是通往",
	   "down" :"朝下似乎可以到",
	 "climbup":"上面洞穴一根绳子垂了下来，沿着绳子往上爬似乎可以到",
	 "climbdown":"地面洞口系着根绳子，沿着绳子向下爬似乎可以到达"
	]);
	longexitmsg="";
	if(undefinedp(all_exits[file]))
	{
		all_exits[file]=([]);
		all_exits[file]["long"]="";//孤立房间，没有出口描述
		  return "";
	}
	foreach(exit in exits)  //逐一查询,添加
	{
		if(!undefinedp(all_exits[file][exit]))
		{
			if(all_exits[file][exit][0]=='/')//其它目录连接
		 		msg +=  exit +":"+all_exits[file][exit]+",";
			else
				msg +=  exit +":"+dir+all_exits[file][exit]+",";
				longexitmsg+= exit2long[exit]+filename_to_short[all_exits[file][exit]]+"，";
		}
	}
	longexitmsg=longexitmsg[0..<3]+"。";//最后的逗号换成句号
	// 	log_file("dd.log",filename+"'s longexitmsg is "+longexitmsg+"\n");
	all_exits[file]["long"] = longexitmsg;
	return msg[0..<2];
}
//建立文件数据         文件名
int create_data(string file)
{
	string exit_msg ;
	all_data[dir][file]=([]);
	if(!filename_to_short[file])
	{
		write("无法建立 "+file+" 。\n");
		return 0;
	}
	exit_msg =get_exit_msg(file);//必须先运行函数，否则出口连接文字未设置
	if(! short_to_set[filename_to_short[file]])//包括短，长描述，特殊设置 如果根本没有设置
		all_data[dir][file]["roomset"] = filename_to_short[file]+":这个房间没有设置任何信息数据，等待巫师来描写。#exitlong#\n";
	else all_data[dir][file]["roomset"] = short_to_set[filename_to_short[file]];//包括短，长描述，特殊设置
 
	all_data[dir][file]["roomset"]=replace_string(all_data[dir][file]["roomset"],"#exitlong#",all_exits[file]["long"]);
	all_data[dir][file]["roomset"]+="exits:"+exit_msg+"\n";
	//log_file("dd.log","\n"+filename+" roomset is"+all_data[dir][file]["roomset"]);
	return 1;
}
//虚拟物件精灵调用
object create_it(string room_filename)
{
	object room;
	int n;
	if((n=strsrch(room_filename,'/',-1)) != -1)//无意义检查，防止有人胡乱用错误参数调用这个函数
	{
		dir=room_filename[0..n];//全局变量初始化		
		file=room_filename[n+1..];
	}
    else {write(room_filename+" is not a full path filename.\n");return 0;}
	
	if(undefinedp(all_data[dir][file])
		||n=(file_name(previous_object(2))=="/cmds/wiz/update"))
	{  //第一次运行或update，数据文件，可能被修改过，只能重新读取
		if(n) test_file();//验证文件是否可用,读入世界文件所有数据行
		if(member_array(dir,alldir)!=-1)
		{
			if(!read_map(dir)){write("dir=="+dir+" 下地图读取错误\n");return 0;}
			//设置区域地图连接文本所有出口
			if(!set_exits(map)){ write("dir=="+dir+" 下地图连接错误\n"); return 0;}
	// 建立在当前地图内的所有房间的数据
			foreach(temp in allfile) create_data(temp);
		}
	}
	room=new(ROOM);
	//log_file("dd.log","\n"+filename+" exits is"+room->query("exits"));
	//经常出错无信息,详细检测一下
	if(all_data==([])){write("all_data是空的\n");return 0;}
	
	if(undefinedp(all_data[dir])||all_data[dir]==([]))
		{write("all_data["+dir+"]未设置\n");return 0;}
	if(undefinedp(all_data[dir][file])||all_data[dir][file]==([]))
		{write("all_data["+dir+"]["+file+"]未设置...\n");return 0;}
	room_set(room,all_data[dir][file]["roomset"]);
	//除文件名和短描述对照mapping 以外的所有room数据集合
	//	log_file("dd.log","\n"+filename+" now is \n"+roomobj->query("short")+"\n"+roomobj->query("long")+"\n");
	room->reset();
	return room;
}
int create()
{
	seteuid(getuid());
	set("name","世界精灵");
    set("channel_id","世界精灵(dd)");	
	if(!read_file_msg()) return 0;
	//log_file("dd.log","xj文件测试成功，载入room-list成功");
	alldir=({});
	return read_dir();
}
string pinyin(string hanzi)
{
	//if(!file = read_file(filename)){	write("无法读取该文件："+filename+"\n");return 0;}
	//mapping hz2py=([]);
	int hzlong,i;
	string *fileline=explode(read_file("/d/wiz/pinyin"),"\n");
	string py,hz,*hzs,mypinyin;
	hzs=({});
	mypinyin="";
	hzlong=sizeof(hanzi)/2;//how many hz
	for(i=0;i<hzlong;i++)
	 hzs+=({ hanzi[(i*2)..(i*2+1)] });//分成几个独立的汉字
	foreach(temp in fileline)
	{
		sscanf(temp,"%s:%s",py,hz);
			for(i=0;i<hzlong;i++)
			{
				if(strsrch(hz,hzs[i])%2==0)//防止汉字错位乱码
					//hz2py[hzs[i]]=py;
					hzs[i]=py;
			}
	}
			//foreach(t1 in hzs)		mypinyin+=hz2py[t1];
			mypinyin=implode(hzs,"");
			//末尾相同，说明有传送位置，那么拼音无需存盘
					if(hanzi[<2..<1]!=mypinyin[<2..<1])
                    {   f_line=f_line[0..<2]+({hanzi+":"+mypinyin,"#list_end#"});
                        write_file(WORLD_FILE,implode(f_line,"\n"),1);
                    }
				return mypinyin;
	}
//移除设置字符串中无效空格,方便后面语法分析
string replace_blank(string str)
{
	string s1,s2,*allstr;
	int i,long;
	s1=str;
	if (strsrch(s1,"\"")==-1)
    {
        s1=replace_string(s1,":","::");
        s1=replace_string(s1,",",",,");
        return replace_string(s1," ","");
    }

	 allstr=explode(s1,"\"");//可能出错，第一个字符串可能为空，可能被舍弃，一定要仔细测试确认,目前无问题
	long=sizeof(allstr);
	s2="";
	for(i=0;i<long;i++)
	//不改变""字符串中的任何字符,其它的分隔符重复一次，利于后面打断分析，以免和字符串中的符号冲突
		s2+=((i%2==0)?
        replace_string(replace_string(replace_string(allstr[i]," ",""),":","::"),",",",,")
        :"\""+allstr[i]+"\""	);
	return s2;
}
//暂时先不开放这个功能比较好，文字中可能有颜色描述，长度可能出错，对不齐反而丑陋
string str_format(string name,string long_desc)
{
	string s1,s2;
	int i,k,howlong=80;//每行40个汉字，汉字2个字节
	s2=long_desc;
    if (strsrch(s2,"\\n")!=-1) //房间自己设定显示格式，就不多此一举了
       return replace_string(s2,"\\n","\n");
	s1 = replace_string(s2,",","，");//必须替换，否则汉字可能被打断
    s1 = replace_string(s1,".","。");
    s1 = replace_string(s1,"?","？");
    s1 = replace_string(s1,";","；");
    s1 = replace_string(s1,":","：");
    s1 = replace_string(s1,"!","！");
    if(s1!=s2){write("当前目录"+dir+"下房间--"+name+"--长描述里面有半角标点符号，请修改为中文全角符号\n");
	log_file("dd.log","当前目录"+dir+"下房间--"+name+"--长描述里面有半角标点符号，请修改为中文全角符号\n ");}
	s1 = "    "+s1;
	i=sizeof(s1)/howlong+1;
	s2="";
		for(k=0;k<i;k++)s2+=s1[k*howlong..(k+1)*howlong-1]+"\n";
	return s2;
}
//字符串处理，去掉“”，如果是数字就转数字
mixed str2right(string s)
{
	if(s[0]=='\"'&&s[<1]=='\"')s=s[1..<2];
		else sscanf(s,"%d",s);//如果b是数字就转成数字
	return s;
}

int room_set(object room,string arg)
{
	/*
	虚拟房间时专用set函数,每行设置一个完整的变量 。做个假设,用于设定房间的某些变量的函数内的变量形式为("aaa":bbb),
	bbb可以是 12332 、  "fsffd" 、  x,y,z  或 a:1,b:2,c:3    形式,索引变量名称或值串本身内部不能有空格,有会被过滤，除非用""括起来。
	引起错误,变量间、值间的空格无所谓。
//除了最简单的数据，比如设置许多数据为1，可以写在一排里以节约版面，中间用逗号分开，
//其他数据，每行设置一个
	*/
	string inputarg,name,*allline=({});
	mixed args,checking,a,b,index;
    temp=arg;
	if(sscanf(temp,"%s:%s\n%*s",name,args)==3)
	{		room->set("short",name);
			args=str_format(name,args);//长描述对齐，暂时先不开放这个功能比较好
			room->set("long",args+"\n");
	}
	else log_file("dd.log","DIR"+dir+"的房间 "+room->query("short")+"设定中described long lost :\n");
    temp=arg[strsrch(arg,"\n")+1..];
	if(!sizeof(temp))return 1;//仅仅只有长短描述。没有其它数据，这种房间最多，优先处理

    temp=replace_blank(temp);//去掉无效空格,,和:都重复一次，""包含起来的不处理
    allline=explode(temp,"\n");
	allline-=({""});
	foreach (inputarg in allline)
  {
      //log_file("dd.log","DIR "+dir+"房间 "+room->query("short")+"设定中inputarg is "+inputarg+"\n");
	 if(sscanf(inputarg,"%s::%s",name,args)!=2)
		log_file("dd.log","DIR "+dir+"房间 "+room->query("short")+"设定中 "+inputarg+" something is wrong\n");
	 //最简单的mapping格式//a:1  变量是简单的数字
 		if(strsrch(args,"::")==-1
        &&strsrch(args,",,")==-1
        &&sscanf(args,"%d",temp))
 		{ 			room->set(name,temp);continue;} 
		// a:"一些描述" ，或者某个值中间有空格或:或,时使用
		if(args[0]=='\"'&&args[<1]=='\"'&&strsrch(temp=args[1..<2],"\"")==-1) 
 		{
 				room->set(name,temp);//变量是字符串形式的值,直接设置上去
 				continue;
 		}
		//传进来的值还可能是array,直接添加,这个估计用处不大,不过先加上,将来也许有用
		// x: 1,2,4,6,abc,3 这样的写法
		if(strsrch(args,"::")==-1 &&strsrch(args,",,")!=-1)
		{
			temp=({});
			args=explode(args,",,");
			foreach(checking in args)
			{ temp+=({str2right(checking)});}
			room->set(name,temp);continue;
		}
//下面是至少两个:的设置
 //可能把一堆简单的设置比如 许多数据设置为1之类，放在一排以节省版面，末尾不要留无用的 ，
 //x:1,m:2,c:5 这样的写法
	  if((a=strsrch(args,"::"))!=-1
	   &&(b=strsrch(args,",,"))!=-1
	   &&a>b)
		{
			args=explode(inputarg,",,");
			foreach(checking in args)
			{
				if(sscanf(checking,"%s::%s",a,b)==2)
			 	 room->set(a,str2right(b));
				else log_file("dd.log","DIR"+dir+"房间 "+room->query("short")+"设定中"+inputarg+"something is wrong\n");
			}
			continue;
		}
	//输入端参数是指向阵列的mapping如  objects : x:1
	//输入端参数是mapping阵列如 objects : x:1,m:2,c:5 这样的写法
	//item : x:1,m,c,5 这样的写法
		
		if(strsrch(args,"::")!=-1)
		{   args=explode(args,",,");
			temp=([]);
			foreach(checking in args)
			{
				if(sscanf(checking,"%s::%s",a,b)==2)
			 	{   index=a;
			  		temp[a]=str2right(b);
			  	}
				else 
				{ 	if(!arrayp(b) )b=({b});
					b+=({str2right(checking)});
					temp[index]=b;
				}
			}
			room->add(name,temp);continue;
		 }
		
		//如果还不能识别类型的数据,直接把总体作为字符串设置
		// xxx:我是真的爱你  这样的写法
		room->set(name,args);
   }
	return 1;
}
