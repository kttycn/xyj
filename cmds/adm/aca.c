// cmd : auto_create_area.c  ���ݼ������ļ����������� room file.
// by naihe 2:01 03-11-15 for huns@������̳
// EM: lonely@163.com  or  lovesb@21cn.com
// PS: �ҵĵ����� xkx ���

// V1.1
// ������һ��BUG
// �����˼���ķ�ʽ��ʹ���̸�����
// �����˽����ļ��ķ�ʽ��ֻ�����ڵ�ͼ��ġ��������б�����ļ���
// Ϊû�� setcolor(), delcolor() ������MUD�ӽ�������������

//v1.2
//�Ľ����ݴ��ԣ�����������������.
//������x���ӷ�,���Խ�������.
//���ӷ��������úͻ��ഩԽ�ˣ������ʾ����
//huns�޸��� 2003.12.07

//v1.3
//������A,<,>,V,v ���ӷ�,���Ըߵ����ˣ������ָ�ǵ��ƽϸߵ�λ��.
//   ��������filea>>>>>>fileb��Ҳ��������filea>---->fileb,��βһ������
//������E,! {  ���ӷ�,������ ¥��/¥�� ��/�� ����/���� λ��,Eȡ��״�Ƚ���¥�ݡ�{ ������.
//������һ����ͼ�쳣����ʱ���ܳ��ֵ�BUG
//��ͼ�п��Գ����ظ������ˣ������� С·-С·---С·
//�����˽ṹ��ȥ����һЩ����Ҫ��ѭ��

//v1.4
//���Ӷ��ͼ���ܣ��޸ļ���������ʾ
//ȥ�����������ɫ���ܣ�û�ã���ɫӦ����look�������ġ�
//huns �޸��� 2006-7-10 22:36
//������ѡ���Ƿ���ӳ�������������������ӳ��ڵ��������򻯴��ֹ���
#include <ansi.h>
int sizeofmap , linelen , map_start_line ,map_number;// ��ͼ���� ���г��� ��ͼ��ʼ���� ��ͼ����
mapping all_exits = ([ ]);          //�ܳ���  ([������1  , ([���� ���ķ����� ])])
mapping all_dirs = ([ ]); //���ļ����Ͷ���������mapping ������������ݼ���
/*
���Ŀ¼�������� all_dirs[/d/baihe/]["cname"] ===>�׺Ӵ�
���Ŀ¼�ļ����ƶ�Ӧ��������Ϣ all_dirs[/d/baihe/shulin]["short"] ===>����
���Ŀ¼�ļ����ƶ�Ӧ��������Ϣ all_dirs[/d/baihe/shulin]["long"] ===>��������������������������������  
���Ŀ¼�ļ����ƶ�Ӧ������Ϣ���� all_dirs[/d/baihe/shulin]["roomset"] ==>

*/

string filename , *allfile , *f_len  ,dir ;

string *map,*alldir=({}) ;       		   // �ܵ�ͼ
mapping filename_to_short = ([ ]);        // filename-->���ķ�����

mapping short_to_long = ([ ]);        // short-->���ķ��䳤����
mapping short_to_filename = ([ ]);        // ���ķ�����-->filename
mapping xy2filename = ([ ]);        // ��ַ-->filename

        // map[x][y]  x�ڼ���  ��y�ڼ��� ,x���ƫ�ƣ�  y���ƫ��
string xy_to_filename( int x,   int y ,   int x1  ,     int y1 ) ;

int add_exit( string n1, string exit, string n2 );

/*******************************************************************
 '-','<','>',        //��-��������-���ͣ�����-���ߣ�

 '|','V','A',    // ��       ����      ����      ����
                     // |         v         V         A
                     // ��  ��   �ϸ�  ��  �ϸ�  ��  �ϵ�

 '/','\','X',    //     ����  ����       �������ӣ� ��������
                       //    /          \          x          X
                       //����     ��     ���ϣ�

���������
 'E','!'  '{'      // ¥��  ��   �� ����/����
                   //  E     !   {  ����
                   // ¥�£���   ��
********************************************************************/

//�������ӷ�
mixed *all_foos=({ '-','<','>', '|', 'V','A', '/','\\', 'X', 'E','!','{'  }) ;

int test_file(string filename);
int read_dir( int n);
int read_room_list();
int read_map( int n);
int get_exit( mixed foo ,int x  ,int y );
int total_map_n();

// ���ڼ���ļ���(Ӣ����)�Ƿ���Ч
// ���ϣ����һЩ�ر���ַ����纺�ֵȣ���Ϊ write_file() ��
// �ļ�����������ı���������ʹ������ֱ�� return 1 .
int valid( string n )
{
	string l = "1234567890abcdefghijklmnopqrstuvwxyz-_";
	mixed t;
	if( !n ) return 0;
	foreach( t in l )
		if( n[0] == t ) return 1;
	return 0;
}

//ֻ�����ļ���������ת�ո�
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

//��֤�ļ��Ƿ����
int test_file(string filename)
{
	string   file ,*temp_f_len;
	map_number=0;
	if( !filename ) return notify_fail("��ָ���ļ���\n");
	
	if(file_size( filename )==-1) return notify_fail("�ļ������ڡ�\n");
	
	//write("------ ok>>>>\n"+file_size( filename ));
	
	if( !file = read_file( filename )  )	return notify_fail("�޷���ȡ���ļ���"+filename+"\n");

	if(strsrch( file, "	" ) != -1)
	return notify_fail("���ļ�����TAB����,��Ϊÿ���˵ĳ��ȶ�����ܲ�һ�£��ᵼ�³���,��ȫ���滻Ϊ�ո�\n");

	file=replace_string( file, "\t", "        " );
//tabת8�ո�,����ͼʱ����TAB�������ҵı༭����TABʱ��ʾ���̲�һ��( ��

	if( strlen( file ) < 10 ) return notify_fail("���ļ�����̫�٣��޷���Ϊ��Ч���ϡ�\n");

	if( strsrch( file, "#create area file#" ) == -1
	 || strsrch( file, "#dir#" ) == -1
	 || strsrch( file, "#list#" ) == -1
	// || strsrch( file, "#list_end#" ) == -1
	 || strsrch( file, "#map#" ) == -1
	 || strsrch( file, "#map_end#" ) == -1 )
		return notify_fail("���ļ����ϲ��㣬�޷������ļ���"
			"����� help auto_create_area ��ø�ʽ�淶˵����\n");

	f_len = explode( file, "\n" );
		
	temp_f_len =f_len - ({ "", " ", "  ", "��", "	", }); //ȥ������,�ӿ��ٶ�
	if( sizeof(temp_f_len) < 10 )
		return notify_fail("���ļ�����̫�٣�����з���̫�٣��޷���Ϊ��Ч���ϡ�\n");

	//���ж��ٷ���ͼ
	map_number = sizeof( filter_array( f_len, (: strsrch( $1, "#map#" ) != -1 :) )  );


	return 1;
}

//��ȡ ���������б�
int read_room_list()
{
	mixed temp;
	string  *temp_arr , checking ;
	int m;
	// ok, make a file_name list for all rooms.
	write("------ ���ڶ�ȡ ���������б� >>>>\n");
	temp = ({ });
	m = 0;

	// get rooms list
	foreach( checking in f_len )
	{
	//	if( strsrch( checking , "#list_end#" ) != -1 )
	//		break; һֱ�����ļ�β���������жϽ����б��
		if( m ) temp += ({ checking });
		if( !m && strsrch( checking , "#list#" ) != -1 )
			m = 1;
	}
	if( !temp || !sizeof(temp) )
		return notify_fail("�޷���ȡ��Ч�ķ��������б���������ԡ�\n");

	m = sizeof(temp) ;

	write("����ȡ "+ m +" ���������ơ�\n------ ������֤���������Ƿ���Ч >>>\n");

	short_to_filename = ([ ]);// ���ķ�����-->filename
	filename_to_short = ([ ]);// filename-->���ķ�����
	//short_to_long = ([ ]);// ���ķ�����-->���ķ��䳤����
	// ������Ч�жϣ�������2����Ӧ�� map ���������
	foreach( checking in temp )
	{
	
		if(sizeof(temp_arr = explode( checking, ":" ))!=2)
			return notify_fail("���������б��е�ȱ:��̫�ࣺ����������ԡ�\n");
	
	//	if( sizeof(temp_arr) =2) //�������к��У�
	        
			sscanf( checking, "%s:%s",temp_arr[0] ,temp_arr[1] );//,temp_arr[2]
		
		temp_arr[0]= replace_string( temp_arr[0], " ", "" );
		temp_arr[1]= replace_string( temp_arr[1], " ", "" );	
		
		if( sizeof(temp_arr) >1 && valid(temp_arr[1]) )   //�������÷���ĳ�����...
		{
			if( !undefinedp( short_to_filename[ temp_arr[0]] ) )
				return notify_fail( "���������б�" + temp_arr[0] +"�ظ����壬��������ԡ�\n");

			short_to_filename[ temp_arr[0] ] = temp_arr[1];

			if( !undefinedp( filename_to_short[ temp_arr[1] ] ) )
				return notify_fail( "�ļ������б�"+temp_arr[1]+ "�ظ����壬��������ԡ�\n");

			filename_to_short[ temp_arr[1] ] = temp_arr[0];
			}
	}
  	//��Щ���ģ��������Ǽ��ϣ���ֹû���ǵ�������
	if( !filename_to_short || !short_to_filename )
	return notify_fail("�޷������Ч�ķ��������б���������ԡ�\n");

	if( sizeof(filename_to_short) < m)
	return notify_fail("���������б�Ӣ���ļ������ظ�����������ԡ�\n");

	if( sizeof(short_to_filename) < m )
	return notify_fail("���������б����Ķ��������ظ�����������ԡ�\n");

	write("����ȡ��Ч�������� "+sizeof(short_to_filename)+" ����\n");
	
	
	return 1;
}
/*
int sort(string a,string b)
{
	return (sizeof(a)>sizeof(b))?-1:0;	
}
*/
//��ȡ��n Ŀ¼����
int read_dir( int n)
{
//	function f = (: sort :);
	// ok. get "dir" first
	int i;
	
	write("----------------------------------------------\n- ���ڶ�ȡ Ŀ¼����\n");

	if( !sizeof(alldir) )//���û������Ŀ¼//alldirδ���壬��ô�ͳ�ʼ����
	{
		alldir= filter_array( f_len, (: strsrch( $1, "#dir#" ) != -1 :) );
		if( !alldir || !arrayp(alldir) || !sizeof(alldir) )
			return notify_fail("�޷���ȡ��Ч�� ������Ŀ¼�� ���ã���������ԡ�\n");
				
		for(i=0;i<sizeof(alldir);i++ )
		{
		alldir[i]=  replace_string(alldir[i],"#dir#" ,"");
		alldir[i]=  replace_string(alldir[i]," " ,"");
		}
		
		write_file( "/test/alldir", implode( alldir, "\n" ), 1 );//�����������Ŀ¼��������������
	}
	dir = replace_string( alldir[n-1], " ", "" );//��������Ŀ¼
	
	//dir = replace_string( checking, "#dir#", "");
	if( !dir ) return notify_fail("�޷���ȡ��Ч�� ������Ŀ¼�� ���ã���������ԡ�\n");
	if( dir[0] != '/' || dir[strlen(dir)-1] != '/' )
		return notify_fail("Ŀ¼Ϊ��"+dir+"����������һ������·��������������ԡ�\n");
	write("��ǰĿ¼�趨Ϊ��"+dir+"-- ���ڻ�õ�ͼ����...\n");
		return 1;
}





//��ȡ��n����ͼ ,���õ�ͼ ,��� ����--���ļ���
int read_map( int n)
{
	mapping counter = ([ ]);        // ������,ͳ���ظ��������
	
	string  s1,s2 ,line,checking ,temp_name1,temp_name2 ;
	int  m ,x=0 ,y ,left ,right,i=0,c=0,a;
	

	map = ({ }); m = 0;

	foreach( checking in f_len )//ÿ�ζ���ͷ�����ƺ������Ż�һ��
	{
		i++;
		if( strsrch( checking , "#map_end#" ) != -1 )
		{
			if(sizeof(map))	break;
		}
		if( m ) map += ({ checking });
		if( strsrch( checking , "#map#" ) != -1 )
		{
			c ++;    //�ҵ���c����ͼ
			if(c==n)
			{
				m=1;
			map_start_line=i;}

		}
	}
	sizeofmap = sizeof(map);
	if( !map || !sizeofmap )
		return notify_fail("�޷���ȡ��"+n+"����ͼ���ã���������ԡ�\n");

	write("��"+n+"����ͼ��ȡ�ɹ������ڽ��еص�����>>\n");

	//��ӱ�����ɫ����
	while(strsrch( map[x] , ":" ) != -1)  //�е�ǰ������ر�ĳ�����
	{
		sscanf(  map[x], "%s:%s",s1 ,s2 );//s1�ļ���  s2������
		
		s1= replace_string( s1, " ", "" ); 
		short_to_long[s1]=s2;		
		x++;
	}
	
	// ����õ� map ��Ϣ��֣��������-���ļ���
	allfile = ({ });
	//for(x=0;x<sizeofmap;x++)
	for(x=x;x<sizeofmap;x++)
	
	{
		line = map[x];				//һ������
		if( !line|| !sizeof(line)) continue;	//	�
		linelen=sizeof(line);	

		while((a=strsrch( line , "/d/" )) != -1)
		{
		  while(strsrch(  "1234567890abcdefghijklmnopqrstuvwxyz_/"  , line[a]) != -1 
		  			&& strsrch(  "1234567890abcdefghijklmnopqrstuvwxyz_/"  ,line[a+1]) != -1) //��ֹ̫���ܵ�ͼ�п������ /�������
		  {
		  if(line[a]=='/') line[a]='*';
		  
		  a++;
		  if(a+1==linelen)break;
		  
		  }
		  	
		}
		
		
		map[x] = line;
	 
		line = replace_nouse_to_blank( line );  //ֻ�����ļ���������ת�ո�
		
		xy2filename[x]=([]);                    //��ʽ ({ x:({ y : filename})})
		for(y=0;y<linelen;y++)
		{
			if(line[y]==' ') continue;

			//�����ļ����short��
			right=y; left=y;
			while((right!=(linelen-1))&&line[right+1]!=' ') y=++right;
			checking = line[left..right];       //�ļ����short
			
			checking=replace_string(checking, ".", "");//ȥ��Ϊ�ӳ��ļ�������ӵ� ^����
			
			if(checking[0]=='*') //�����ӵ�����Ŀ¼�µ�·���ָ�����
			{
				checking=replace_string(checking, "*", "/");
				short_to_filename[checking]=checking;
				filename_to_short[checking]=filename_to_short[checking[strsrch(checking,"/",-1)+1..]];				
			}

		
			if( !short_to_filename[checking] )  // ���ÿ������Ч��
			 return	notify_fail("��ͼ���õص�"+checking+"�޶�Ӧ�ļ��� ...����Ӻ������б�����\n");
			 
			 if(undefinedp(counter[checking]))  //���Ķ�������һ�γ���
			{
			counter[checking]=0; 					  //��ʼͳ��...
			xy2filename[ x][left]=short_to_filename[checking] ;	//��� ����--���ļ���
			
			if(checking[0]!='/')                                   //�����ӵ�����Ŀ¼�µ��ļ���ȥ��
			allfile += ({ xy2filename[x][left] });			//����ļ���
			}
			else		//�������Ƶ�n�γ��֣����ν���file file1 file2������

			{
			counter[checking]=counter[checking]+1;   		  //ͳ�ƴ���
			temp_name1=short_to_filename[checking];	  		 //�����ظ������mapping ,
			temp_name2=short_to_filename[checking]+counter[checking];//Ӣ���ļ�������������֣�

			filename_to_short[temp_name2]=filename_to_short[temp_name1];//���������Ʋ���

			xy2filename[x][left] =temp_name2   ;			//��� ����--���ļ���
			
			allfile += ({temp_name2 });				//����ļ���

			}
		}
	}

	if( !allfile || !sizeof(allfile) ) return notify_fail("�޷���ȡ��ͼ�ص㣬��������ԡ�\n");

	write("��ͼ���óɹ����ڵ�ͼ����� "+sizeof(allfile)+" ���ص㡣��ʼ���㷽�� ...\n");

	return 1;
}


 //�������г���
int set_exits( string *map )
{
	int x, y;
	mixed foo;
	string line;

	all_exits = ([ ]);

	// ��ÿһ�����ӷ�Ϊ��λ����ʼ���㷽��
	for(x=0;x<sizeofmap;x++)
	{	line = map[x];
		
	 	if(strsrch( line , ":" ) != -1) continue;//��ֹ���������������ӷ���,��ͼ�ڱ����ܳ���:
		linelen = sizeof(map[x]);
		for(y=0;y<linelen;y++)
		{
			foo = map[x][y];

			if(member_array(foo ,all_foos)==-1) continue;

			if(foo=='-'||foo=='<'||foo=='>')
			{
				if(y==0||y==linelen-1)
				return notify_fail("�ļ���"+(x+1+map_start_line)+"�� ��"+(y+1)+"��  - ,< ,> ���Ӵ���\n");

			}
			if(foo=='|'||foo=='A'||foo=='V'||foo=='E'||foo=='!'||foo=='{')
			{
				if(x==0||x==sizeofmap||(y+1)>sizeof(map[x-1])||(y+1)>sizeof(map[x+1]))
		 		return notify_fail("�ļ���"+(x+1+map_start_line)+"�� ,"+(y+1)+"�� | ,A ,V ,E ,! { ���Ӵ���\n");

			}
			if(foo=='/')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||y>sizeof(map[x+1]))
				return notify_fail("�ļ���"+(x+1+map_start_line)+"�� ,"+(y+1)+"��  /  ���Ӵ���\n");
			}
			if(foo=='\\')
			{
				if(x==0||x==sizeofmap||y==0||y>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
				return notify_fail("�ļ���"+(x+1+map_start_line)+"�� ,"+(y+1)+"��  \\  ���Ӵ���\n");
			}

			if(foo=='X')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
					return notify_fail("�ļ���"+(x+1+map_start_line)+"�� ,"+(y+1)+"��   x  ���Ӵ���\n");
			}
			 //���˵��������ʱ���м�ķ�,���ܻ��н���  aaa-----bbb��,ֻ�����߻��ϱ�
			 //�����ĳ�����ӷ�������߻��ϱ����췽���ϲ���������������ӷ���
			if((member_array(foo,({'-','<','>'}))!=-1&&map[x][y-1]!=foo)
			||(member_array(foo,({'|','A','V','E','!','{'}))!=-1&&map[x-1][y]!=foo)
			||(foo=='/' &&map[x-1][y+1]!=foo)
			||(foo=='\\'&&map[x-1][y-1]!=foo)
			||foo=='X'
			 )
			if(!get_exit( foo,x ,y )) return  notify_fail( "�޷����ó���1\n"  );

		}
	}
	if( !all_exits || !sizeof(all_exits) ) return notify_fail( "�޷����ó���2\n"  );
	write("�����ȡ��ϣ������ļ���\n");
	return 1;
}

//              ���ӷ��� λ��x  λ��y
int get_exit( mixed foo ,int x  ,int y )
{
	// ���ӷ����������ļ��� name1:�������ϵ�  name2:���һ���µ�
	string name1 , name2;

	//-------------�������ӷ�--------------------
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
	//-------------�������ӷ�--------------------
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
		                       //��¥                                    ��¥

		if(foo=='!')
		return add_exit( name1, "down", name2 )&&add_exit( name2, "up", name1 );

		if(foo=='{')
		return add_exit( name1, "climbdown", name2 )&&add_exit( name2, "climbup", name1 );


	}

	//-----����-����-------------------------
	if(foo=='/')
	{
		name1 = xy_to_filename( x, y ,-1,1 );
		name2 = xy_to_filename( x, y ,1,-1 );

		return add_exit( name1, "southwest", name2 )&&add_exit( name2, "northeast", name1 );

	}
	//-----����-����-------------------------
	if(foo=='\\')
	{
		name1 = xy_to_filename( x, y ,-1,-1 );
		name2 = xy_to_filename( x, y ,1,1 );

		return  add_exit( name1, "southeast", name2 )&&add_exit( name2, "northwest", name1 );
	}

	//---------��������-------------------------
	if(foo=='X')
	{
	// x �൱�� /��\ ������һ��λ����,�ݹ��������
		if(!get_exit( '/' , x  , y )) return 0;
		if(!get_exit( '\\' , x  , y )) return 0;
		return 1;
	}

}

 //�ɵ�ַ�õ��ļ��� x1 y1������������˵��������
 // map[x][y]        x�ڼ���  ��y�ڼ��� , x���ƫ�ƣ�    y���ƫ��
string xy_to_filename( int x ,   int y  ,  int x1  ,    int y1 )
{
	int  left,linelen ;
	string  line ;
	//���˵��ظ������ӷ����� aaaa-------bbbb ֻ����ұ߻��±�
	do{
		x+=x1 ; y+=y1 ;
		line = map[x];
		linelen =sizeof( line );
		if(( (y+1)>linelen)||line[y]==' ')
		{	write("��ͼ��"+(x+1+map_start_line)+"��,��"+(y+1)+"�д����ļ������֣��������ӷ����Ӵ���\n");
			return 0;
		}
		if( member_array( line[y] ,all_foos )==-1 )  break;    //�ҵ� �������� ��
	  }while(1);

	left = y;

	//����ļ�����ʼ����
	if(left>0)
	{
						 //����......   ��ζ���Ѿ����˷������������
		while(member_array(line[left-1] ,({' '})+all_foos)==-1)
		{
	 	left--;
	 	if(left==0) 	break;
	 	}
	}

	//����ļ���
	return xy2filename[x][left];
}

//���ó���        ����1----������-------����2
int add_exit( string n1, string exit, string n2 )
{
	if((!n1)||(!n2)) return 0;
	if( undefinedp( all_exits[n1] ) )
		all_exits[n1] = ([ ]);
	all_exits[n1][exit] = n2;
	return 1;
}

//��ó�����Ϣ
string get_exit_msg( string file )
{
	string longexitmsg="", msg = "" , exit , *exits=({"east", "eastup", "eastdown", "west", "westup", "westdown",
			    "north", "northup", "northdown","south", "southup", "southdown",
			    "northeast", "northwest", "southeast", "southwest" ,
			    "upstairs","downstairs",  "up","down" ,"climbup","climbdown"

			});
	mapping exit2long=([
	"east":"����ȥ����",
	 "eastup":"���߹�ȥ�ߴ�����",
	  "eastdown":"���ߵʹ����¾���", 
	 
	 "west":"�����߾���ȥ", 
	  "westup":"�����ȥ�ߴ�����ȥ",
	   "westdown":"����ʹ����¾���ȥ",
	   
	 "north":"�����߾͵���",
	  "northup":"���߸ߴ��߾͵���",
	   "northdown":"���ߵʹ����¾͵���",
	  
	 "south":"�������", 
	  "southup":"�����ȥ�ߴ�����", 
	   "southdown":"����ʹ����¾���",
	   
	 "northeast":"����������Ե�",
	  "northwest":"��������ȥ��",
	   "southeast":"���Ϸ��򵽴�", 
	   "southwest" :"���Ϸ�������",
	
	 "upstairs":"��¥�����Ͼ���",
	 "downstairs":"��¥�͵���",  
	   "up":"�����ƺ���ͨ��",
	   "down" :"�����ƺ����Ե�", 
	 "climbup":"���������������ƺ����Ե�",
	 "climbdown":"�������������ƺ����Ե���"
	
	]);
	longexitmsg="";
	if(undefinedp( all_exits[file] ) )
	{
		all_exits[file]=([]);
		 all_exits[file]["long"]="";//û�г�������
		  return "";
	} 
	 
	foreach( exit in exits)  //��һ��ѯ ,���
	{
		if( !undefinedp( all_exits[file][exit] ) )
		{			

			if( all_exits[file][exit][0]=='/')//����Ŀ¼����
		 		msg += sprintf("%-16s","\n		\""+ exit +"\"")+":\""+all_exits[file][exit]+"\",";			
			else
				msg += sprintf("%-16s","\n		\""+ exit +"\"")+": __DIR__\""+all_exits[file][exit]+"\",";	
							 
				longexitmsg+= exit2long[exit]+filename_to_short[all_exits[file][exit]]+",";		
		}
	}
	
	longexitmsg+=",";
	longexitmsg=replace_string( longexitmsg, ",,","��" );
	
	all_exits[file]["long"] = longexitmsg;
	
	msg+=",";
	return replace_string( msg, ",,","" ) + "\n";
}

//�����ļ�            Ŀ¼      �ļ���
void create_it( string dir, string file )
{
//	int t;
	string alltext,exit_msg; 
	
	if( !filename_to_short[file] )
	{
		write("�޷����� "+file+" ��\n");
		return;
	}
	write(">> "+filename_to_short[file]+": "+dir+file+".c ������.....");
	
	exit_msg =get_exit_msg(file);//���������к��������������������δ����
	
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
	write(   write_buffer("/test"+dir + file + ".c" , 0 ,alltext )  ? "�ɹ�\n":"ʧ��\n" );
}

int help(object me)
{
	string msg = "
===========================================
    auto_create_area �ļ���
    ���� auto_create_area /d/xj/abc
�����ݸ�abc�ļ����ã�����һƬ������Դ�ļ���
ʣ�µĹ������Ǿ����޸ķ���Ķ��� ��
��ע�⣬�����ֱز����٣������лᱻʡ�ԡ�
  ***** ������ʾ���ļ���ʽ ******

#create area file#
//
#list#
����:dating
����:woshi
����:chufang:������һ����Ѭ���ǣ���������ĳ���
��̨:yangtai
���ſ�:damenkou
����:menwai
С·:xiaolu
#list_end#

#dir#	/d/area1/
//�ļ�����λ��ʵ����/test/d/area1/
#map#
����-����-��^^^��
     |  \\  |  \\
   ��̨-���ſ�-����-----С·
#map_end#
//λ�ÿ���д������ע�����ݣ����ᱻ��ȡ��
  ********************************\n";

string msg1="
��ע�⣬Ϊ��ʹ��ʽ�淶�����������¹���

1��Ŀ¼��ʹ�þ���·��������ͷ����β����Ҫ / ���š�
2������������������ʹ�ÿո�
   - ,| ,/ ,\\ ,E, A, v ,V ,! ,{ ,< ,> ,x ,X.
3���������������ļ��������б��ڵ����пո񽫱����ԣ�
   ����ʹ�� \":\" ��������
4������Ϊ���ϱ����������Ҷ�
5�����򷿼����ӣ�ʹ�� \"-\" \"<\" \">\" ��������֮���޿ո�
6�����򷿼����ӣ�ʹ�� \"|\" \"A\" \"v\" \"V\" ��.
7����б�򷿼����ӣ�ʹ�� \"/\"��
8����б�򷿼����ӣ�ʹ�� \"\\\"��
9������������ x�� X.
10��A,v��V,< ,>,�����ָ�ǵ��ƽϸߵ�λ��.
11�����ӷ���������ʹ�ã�Ҳ�����໥��Խ,���������м�\n����^^^�������ӳ��Ա����㹻λ�ú�������������";


string msg2="\n
   7,8 ����                       9 ����
      abc  c,f λ�ñ�������������   aa bb
      d/e                             x
      fgh                           cc dd
                ��ʾaa dd������bb cc����,�Թ�����ʱ�õ�

   11����   ����1
             |
    ����3--------- ����4    ��ʾ 1 2 ������3 4 ����
             |
          ����2

�粻���ף����������ʾ����ʽ���Բ����׻��д���
����www.mudbuilder.com��̳ ���ԡ�

    д�ø��ļ������뱾ָ��ɡ�
==========\n";

	me->start_more( msg );
	me->start_more( msg1);
	me->start_more( msg2);
	return 1;
}

int main( object me, string arg )
{
	int map_i; // �ڼ�����ͼ
	if(!arg) return help(me);
		assure_file( "/test/ " );
		if( file_size( "/test" ) != -2 )
			return notify_fail("�޷�������Ŀ¼��/test\n");
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
		return notify_fail("�޷�������Ŀ¼��/test"+dir+"---\n");
		//write("\nok1\n");�����õ�

		if(!set_exits( map)) 	return 0 ;
		//write("\nok2\n");�����õ�

	// �����ڵ�ͼ�ڵķ���
		foreach( filename in allfile ) create_it( dir, filename );

		write("\n������ϣ������� /test"+dir+" �� "+sizeof(allfile)+" ���ļ���\n");
		
	}
	write("\n�����ļ�������ϣ�\n");
	return 1;
}

