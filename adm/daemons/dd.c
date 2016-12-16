#include <ansi.h>
inherit F_DBASE;
#define WORLD_FILE "/d/wiz/xj"
int sizeofmap,linelen,map_start_line;// ��ͼ���� ���г��� ��ͼ��ʼ���� ��ͼ����
mapping all_exits = ([ ]);//�ܳ���  ([������1,([���� ���ķ����� ])])
mapping all_data = ([ ]);//���ļ����Ͷ���������mapping ������������ݼ���
/*
���Ŀ¼�������� all_data["/d/baihe/"]["cname"] ===>�׺Ӵ�
���Ŀ¼�ļ����ƶ�Ӧ������Ϣ���� all_data["/d/baihe/shulin"]["roomset"] ==>�������õ��ַ�������ʽ�������� room_set()
*/
string pinyin(string hanzi);
string *allfile,*map,dir,file;//�����ͼ�ļ����������ͼ�ı�������Ŀ¼������ǰ�ļ���
string *f_line,*alldir=({});// �ܵ�ͼ����mulu
mapping filename_to_short = ([ ]);// filename-->���ķ�����
mapping short_to_set = ([ ]);// short-->�����������������
mapping short_to_filename = ([ ]);// ���ķ�����-->filename
mapping xy2filename = ([ ]);// ��ַ-->filename
        // map[x][y]  x�ڼ���  ��y�ڼ���,x���ƫ�ƣ�  y���ƫ��
string xy_to_filename(int x,int y,int x1,int y1);
int add_exit(string n1,string exit,string n2);
string replace_blank(string str);
string str_format(string name,string long_desc);
int room_set(object room,string arg);
/*******************************************************************
 '-','<','>',��-��������-���ͣ�����-���ߣ�
 '|','V','A',��        ����      ����
             |          V         A
             ��  ��   �ϸ�  ��  �ϵ�
 '/','\','X',����  ����       ��������
              /      \          X
          ����     ����
���������
 'E','!'  '{'      // ¥��  ��   �� ����/����
                   //  E     !   {  ����
                   // ¥�£���   ��
********************************************************************/
//�������ӷ�
mixed temp,*all_fus=({ '-','<','>','|','V','A','/','\\','X','E','!','{'  });
int test_file();
int read_dir();
int read_room_list();
int read_map(string dirname);
int get_exit(mixed fu,int x,int y);
// ���ڼ���ļ���(Ӣ����)�Ƿ���Ч,��ֹ�����ӷ���Ϊ�ļ���
// ���ϣ����һЩ�ر���ַ����纺�ֵȣ���Ϊ write_file() ��
// �ļ�����������ı���������ʹ������ֱ�� return 1 .
int valid(string n)
{
	string l = "1234567890abcdefghijklmnopqrstuvwxyz_";
	mixed t;
	if(!n) return 0;
	foreach(t in l)
		if(n[0] == t) return 1;
	return 0;
}
//ֻ�����ļ���������ת�ո�
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
//��֤�ļ��Ƿ����,���������ļ�����������
int test_file()
{
	string file;
	if(file_size(WORLD_FILE)==-1) 
	{write("xj�ļ������ڡ�\n");return 0; }	
	if(!file = read_file(WORLD_FILE))
	{write("�޷���ȡ���ļ���"WORLD_FILE"\n");return 0; }
	
	if(strsrch(file,"	") != -1)
		{write("���ļ�����TAB����,��Ϊÿ���˵ĳ��ȶ�����ܲ�һ�£��ᵼ�³���,��ȫ���滻Ϊ�ո�\n");return 0; }
	if(strlen(file) < 10) 
	{write("���ļ�����̫�٣��޷���Ϊ��Ч���ϡ�\n");return 0; }
	
	if(strsrch(file,"#create area file#") == -1
	 || strsrch(file,"#dir#") == -1
	 || strsrch(file,"#list#") == -1
	 || strsrch(file,"#list_end#") == -1
	 || strsrch(file,"#map#") == -1
	 || strsrch(file,"#map_end#") == -1)
		{write("���ļ����ϲ��㣬�޷����������������ʾ����ø�ʽ�淶˵����\n");return 0; }	
			
	f_line = explode(file,"\n");
	
	return 1;
}
//��ȡ ���������б�
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
		if(!m && strsrch(checking,"#list#") != -1)m = 1;//�ҵ��б���
	}
	if(!temp || !sizeof(temp))
		{write("�޷���ȡ��Ч�ķ��������б���������ԡ�\n");return 0; }
	m = sizeof(temp);
	short_to_filename = ([ ]);// ���ķ�����-->filename
	filename_to_short = ([ ]);// filename-->���ķ�����
	// ������Ч�жϣ�������2����Ӧ�� map ���������
	foreach(checking in temp)
	{
		if(sizeof(temp_arr = explode(checking,":"))!=2)
			{write("���������б��е�ȱ:��̫�ࣺ����������ԡ�\n");return 0; }
        checking =replace_string(checking," ","");
		sscanf(checking,"%s:%s",temp_arr[0],temp_arr[1]);
		if(sizeof(temp_arr) >1 && valid(temp_arr[1])) //������ļ�������
		{
			if(!undefinedp(short_to_filename[ temp_arr[0]]))
			{write("���������б�" + temp_arr[0] +"�ظ����壬��������ԡ�\n");return 0; }
			
			short_to_filename[ temp_arr[0] ] = temp_arr[1];
			if(!undefinedp(filename_to_short[ temp_arr[1] ]))
			{write("�ļ������б�"+temp_arr[1]+ "�ظ����壬��������ԡ�\n");return 0; }
			
			filename_to_short[ temp_arr[1] ] = temp_arr[0];
		}
	}
  	//��Щ���ģ��������Ǽ��ϣ���ֹ����û���ǵ�������
	if(!filename_to_short || !short_to_filename)
		{write("�޷������Ч�ķ��������б���������ԡ�\n");return 0; }
	return 1;
}
//��ȡ��n Ŀ¼����
int read_dir()
{
	// ok. get "alldir" first
	string s1,s2;
	int i;
	//���û������Ŀ¼//alldirδ���壬��ô�ͳ�ʼ����
		alldir= filter_array(f_line,(: strsrch($1,"#dir#") != -1 :));
		if(!alldir || !arrayp(alldir) || !sizeof(alldir))
		{write("�޷���ȡ��Ч�� ����Ŀ¼ ���ã���������ԡ�\n");return 0; }
		
		
		for(i=0;i<sizeof(alldir);i++)
		{
		sscanf(alldir[i],"#dir#%s %s",s1,s2);
		if(s1[0] != '/' || s1[<1] != '/')
		{write("Ŀ¼"+s1+"����������һ������·������ǰ�������/,��������ԡ�\n");return 0; }
		alldir[i]=  replace_string(s1," ","");
		s2=replace_string(s2," ","");//
		all_data[s1]=([]);
		all_data[s1]["cname"]=s2;//���������������,�Ժ���Լ���ս�����в���
		}
		if(file_size("/d/wiz/alldir")==-1)
		write_file("/d/wiz/alldir",implode(alldir,"\n"),1);//�����������Ŀ¼��������������
		return 1;
}
//��ȡdir_name��ͼ,���õ�ͼ,��� ����--���ļ���
int read_map(string dir_name)
{
	mapping counter = ([ ]);// ������,ͳ���ظ��������
	string s1,s2,line,checking,temp_name1,temp_name2,dirname;
	int m,n,x,y,left,right,i,c,a;
	n=0;x=0;i=0;c=0;
		dirname=dir_name;
	map = ({ });m = 0;
//log_file("dd.log",dirname+"Ŀ¼��ͼ��ȡ...\n");
	foreach(checking in f_line)//ÿ�ζ���ͷ����
	{
		 i++;
		if(strsrch(checking,"#dir#"+dirname+" ") != -1 ||n)
		{
			n++;//�ҵ���ͼ�ˣ�ÿ�ж���������һ��
			if(strsrch(checking,"#map_end#") != -1)	break;
			if(m) map += ({ checking });
			if(strsrch(checking,"#map#") != -1)//��ͼ��ʼ���ÿ��������
			{
				m=1;
				map_start_line=i;//���ŵ�ͼ���ʱ���λ����
			}
		}
	 }
 //    foreach(checking in map) log_file("dd.log",checking+"\n");
	sizeofmap = sizeof(map);
	if(!map || !sizeofmap)
	{write("�޷���ȡ"+dirname+"��ͼ���ã���������ԡ�\n");return 0;}
//log_file("dd.log",dirname+"Ŀ¼��ͼ��ȡ�ɹ������ڽ��еص�����>>\n");
	//��ӷ���ϸ������
	while(strsrch(map[x],":") == -1) x++;//��������
	while(x<sizeofmap)  //�е�ǰ���䳤���� && map[x][0]!=' '&& sizeof(map[x])>3
	{
        if(strsrch(map[x],":") == -1){x++;continue;}//�����޷������õĿհ���
		if(sscanf(map[x],"%s:%s",s1,s2)==2)//s1�ļ�short��  s2������ long
            short_to_set[s1]= map[x]+"#exitlong#\n";//���������ļ���Ϣ
		else log_file("dd.log","��ͼ"+ map_start_line+x+"�����ô���\n");
		//while(map[x+1][0]==' '&& strsrch(map[x+1],":") != -1)  //��ʼ�пո񣬲����У���˵���Ƿ����������
		x++;
		while(x<sizeofmap)
		{
        if(strsrch(map[x],":") != -1 && map[x][0]!=' ')break;//�¸������־
        if(strsrch(map[x],":") != -1)
            short_to_set[s1]+= map[x]+"\n";
	//	log_file("dd.log",dirname+"��--�� mapping ����������� ���óɹ���\n");
		x++;
		}
	//	log_file("dd.log",dirname+x+"�����óɹ���\n");
	}
	//log_file("dd.log",dirname+"Ŀ¼��ͼ������ӱ�����ɫ������ȡ�ɹ���\n");
	//reset_eval_cost();
	// ����õ� map ��Ϣ��֣��������-���ļ���
	allfile = ({ });
	//��ͼ���Ӳ���
	for(x=0;strsrch(map[x],":") == -1;x++)
	{
		line = map[x];//һ������
		linelen=sizeof(line);
		if(!line|| !linelen) continue;//�հ���
		if((a=strsrch(line,"/d/")) != -1) //�ҵ���������ͼ���ӣ�����������/��Ϊ*,��������ӷ�����
		{
		  while(a<linelen) //�ַ������ļ���һ����
		  {
			if(line[a]=='/'&& strsrch("1234567890abcdefghijklmnopqrstuvwxyz_",line[a+1]) != -1)
			{
			//    /���滹����ĸ��Ӧ�����ļ�����һ����
                line[a]='*';
			}
			a++;
		  }
		  //log_file("dd.log",dirname+"/�޸�Ϊ*�ɹ���\n");
		}
		map[x] = line;
		line = replace_nouse_to_blank(line);//ֻ�����ļ���������ת�ո�
		xy2filename[x]=([]);//���С��л���ļ��� ��ʽ ({ x:({ y : filename})})
		for(y=0;y<linelen;y++)
		{
			if(line[y]==' ') continue;
			//�����ļ����short��
			right=y;left=y;
			while((right!=(linelen-1))&&line[right+1]!=' ') y=++right;
			checking = line[left..right];//�ļ����short
			checking=replace_string(checking,".","");//ȥ��Ϊ�ӳ��ļ�������ӵ�.����
			if(checking[0]=='*') //�����ӵ�����Ŀ¼�µ�·���ָ�����
			{
				checking=replace_string(checking,"*","/");
				short_to_filename[checking]=checking;
				filename_to_short[checking]=
			 		all_data[checking[0..strsrch(checking,"/",-1)]]["cname"]+
					filename_to_short[checking[strsrch(checking,"/",-1)+1..]];
			}
			if(!short_to_filename[checking])  // ���ÿ������Ч��,��ͼ���õص�"+checking+"���޶�Ӧ�ļ���
			{
			short_to_filename[checking]=pinyin(checking);
			filename_to_short[short_to_filename[checking]]=checking;
            /*            
            i=2;//����Ƿ��ͷ��䣬����short��ȥ�����ķ��������洫���õĶ�λ������Ҫ����������8��9��
            while(short_to_filename[checking][<i..<1]==checking[<i..<1])
                {filename_to_short[short_to_filename[checking]]=checking[0..<(i+1)];
                    i+=2;
                }*/
			//����Ƿ��ͷ��䣬����short��ȥ�����ķ��������洫���õĶ�λ������Ҫ����������8��9��
			 if(short_to_filename[checking][<2..<1]==checking[<2..<1])
                filename_to_short[short_to_filename[checking]]=checking[0..<3];                  
			}
			if(undefinedp(counter[checking]))  //���ķ�������������һ�γ���
			{
			counter[checking]=0;//��ʼͳ��...
			xy2filename[ x][left]=short_to_filename[checking];//��� ����--���ļ���
			if(checking[0]!='/')                                   //��������ӵ�����Ŀ¼�µ��ļ���
				{	allfile += ({ xy2filename[x][left] });//����ļ���
					//log_file("dd.log",dirname+checking+"�ļ���ʼ���ã�\n");
				}
			}
			else		//�������Ƶ�n�γ��֣����ν���file file1 file2������
			{
			counter[checking]=counter[checking]+1;//ͳ�ƴ���
			temp_name1=short_to_filename[checking];		 //�����ظ������mapping,
			temp_name2=short_to_filename[checking]+counter[checking];//Ӣ���ļ�������������֣�
			filename_to_short[temp_name2]=filename_to_short[temp_name1];//���������Ʋ���
			xy2filename[x][left] =temp_name2;//��� ����--���ļ���
			allfile += ({temp_name2 });//����ļ���
			}
		}
	}
	if(!allfile || !sizeof(allfile)) { write("�޷���ȡ��ͼ�ص㣬��������ԡ�\n");return 0;}
	//write("��ͼ���óɹ����ڵ�ͼ����� "+sizeof(allfile)+" ���ص㡣��ʼ���㷽�� ...\n");
	return 1;
}
 //�������г���
int set_exits(string *map)
{
	int x,y;
	mixed fu;
	string line;
	all_exits = ([ ]);
	// ��ÿһ�����ӷ�Ϊ��λ����ʼ���㷽��
	for(x=0;x<sizeofmap;x++)
	{	line = map[x];
	 	if(strsrch(line,":") != -1) continue;//��ֹ���������������ӷ���,��ͼ�ڱ����ܳ���:
		linelen = sizeof(map[x]);
		for(y=0;y<linelen;y++)
		{
			fu = map[x][y];
			if(member_array(fu,all_fus)==-1) continue;
			if(fu=='-'||fu=='<'||fu=='>')
			{
				if(y==0||y==linelen-1)
				{write("�ļ���"+(x+1+map_start_line)+"�� ��"+(y+1)+"��  -,<,> ���Ӵ���\n");return 0;}
			}
			if(fu=='|'||fu=='A'||fu=='V'||fu=='E'||fu=='!'||fu=='{')
			{
				if(x==0||x==sizeofmap||(y+1)>sizeof(map[x-1])||(y+1)>sizeof(map[x+1]))
		 		{write("�ļ���"+(x+1+map_start_line)+"��,"+(y+1)+"�� |,A,V,E,! { ���Ӵ���\n");return 0;}
			}
			if(fu=='/')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||y>sizeof(map[x+1]))
				{write("�ļ���"+(x+1+map_start_line)+"��,"+(y+1)+"��  /  ���Ӵ���\n");return 0;}
			}
			if(fu=='\\')
			{
				if(x==0||x==sizeofmap||y==0||y>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
				{write("�ļ���"+(x+1+map_start_line)+"��,"+(y+1)+"��  \\  ���Ӵ���\n");return 0;}
			}
			if(fu=='X')
			{
				if(x==0||x==sizeofmap||y==0||(y+2)>sizeof(map[x-1])||(y+2)>sizeof(map[x+1]))
					{write("�ļ���"+(x+1+map_start_line)+"��,"+(y+1)+"�� x ���Ӵ���\n");return 0;}
			}
			 //���˵��������ʱ���м�ķ�,���ܻ��н���  aaa-----bbb��,ֻ�����߻��ϱ�
	//�����ĳ�����ӷ�������߻��ϱ����췽���ϲ�����������������ӷ���һ�γ��֣������ӷ��䣬
    //������ӷ����棬���ܻ�����2�λ����Σ��˷�cpu
			if((member_array(fu,({'-','<','>'}))!=-1&&map[x][y-1]!=fu&&map[x][y-2]!=fu) //�������Ӵ���˾Ͷ���һ�£����漸�ֿ��У�����鷳
			||(member_array(fu,({'|','A','V','E','!','{'}))!=-1&&map[x-1][y]!=fu)
			||(fu=='/' &&map[x-1][y+1]!=fu)
			||(fu=='\\'&&map[x-1][y-1]!=fu)
			||fu=='X')
			if(!get_exit(fu,x,y))
                {write("�ļ���"+(x+1+map_start_line)+"��,"+(y+1)+"�д�"+(string)fu+"�޷����ӳ���\n");return 0;}
		}
	}
	if(!all_exits || !sizeof(all_exits)) {write("�޷����ó���2\n");return 0;}
	//write("�����ȡ��ϣ������ļ���\n");
	return 1;
}
//              ���ӷ��� ��λ��x  ��λ��y
int get_exit(mixed fu,int x,int y)
{
	// ���ӷ����������ļ��� name1:�������ϵ�  name2:���һ���µ�
	string name1,name2;
	//-------------�������ӷ�--------------------
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
	//-------------�������ӷ�--------------------
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
		                       //��¥                                    ��¥
		if(fu=='!')
		return add_exit(name1,"down",name2)&&(strsrch(dir,"shilianku") != -1||add_exit(name2,"up",name1));//������.���ݾ���ֻ���²�����
		//return add_exit(name1,"down",name2)&&add_exit(name2,"up",name1);//���ݾ��׾��ڷ�������ͼ���������||strsrch(name2,"jingdi") != -1
		if(fu=='{')
		return add_exit(name1,"climbdown",name2)&&add_exit(name2,"climbup",name1);
	}
	//-----����-����-------------------------
	if(fu=='/')
	{
		name1 = xy_to_filename(x,y,-1,1);
		name2 = xy_to_filename(x,y,1,-1);
		return add_exit(name1,"southwest",name2)&&add_exit(name2,"northeast",name1);
	}
	//-----����-����-------------------------
	if(fu=='\\')
	{
		name1 = xy_to_filename(x,y,-1,-1);
		name2 = xy_to_filename(x,y,1,1);
		return add_exit(name1,"southeast",name2)&&add_exit(name2,"northwest",name1);
	}
	//---------��������-------------------------
	if(fu=='X')
	{
	// x �൱�� /��\ ������һ��λ����,��������
		if(!get_exit('/',x,y)||!get_exit('\\',x,y)) return 0;
		return 1;
	}
}
 //�������ַ�õ��ļ��� x1 y1������������˵��������
 // map[x][y]        x�ڼ���  ��y�ڼ���,x���ƫ�ƣ�    y���ƫ��
string xy_to_filename(int x,int y,int x1,int y1)
{
	int left,linelen;
	string line;
	//���˵��ظ������ӷ����� aaaa-------bbbb
	do{
		x+=x1;y+=y1;
		line = map[x];
		linelen =sizeof(line);
		if(((y+1)>linelen)||line[y]==' '||y<0)
		{	write("��ͼ��"+(x+1+map_start_line)+"��,��"+(y+1)+"�д����ļ������֣��������ӷ����Ӵ���\n");
			return 0;
		}
		if(member_array(line[y],all_fus)==-1)  break;//�ҵ� �������� ��
	  }while(1);
	left = y;
	//����ļ�����ʼ����
	if(left>0)
	{
						 //����......   ��ζ���Ѿ����˷������������
		while(member_array(line[left-1],({' '})+all_fus)==-1)
		{
	 	left--;
	 	if(left==0) 	break;
	 	}
	}
	//����ļ���
	return xy2filename[x][left];
}
//���ó���        ����1----������-------����2
int add_exit(string n1,string exit,string n2)
{
	if((!n1)||(!n2)) return 0;
	if(undefinedp(all_exits[n1]))
		all_exits[n1] = ([ ]);
	all_exits[n1][exit] = n2;
	return 1;
}
//��ó�����Ϣ
string get_exit_msg(string file)
{
	string longexitmsg="",msg = "",exit,*exits=({"east","eastup","eastdown","west","westup","westdown",
			    "north","northup","northdown","south","southup","southdown",
			    "northeast","northwest","southeast","southwest",
			    "upstairs","downstairs","up","down","climbup","climbdown"
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
	 "upstairs":"�ؽ��������߾���",
	 "downstairs":"�ؽ��������߾͵���",
	   "up":"�Ϸ��ƺ���ͨ��",
	   "down" :"�����ƺ����Ե�",
	 "climbup":"���涴Ѩһ�����Ӵ������������������������ƺ����Ե�",
	 "climbdown":"���涴��ϵ�Ÿ����ӣ����������������ƺ����Ե���"
	]);
	longexitmsg="";
	if(undefinedp(all_exits[file]))
	{
		all_exits[file]=([]);
		all_exits[file]["long"]="";//�������䣬û�г�������
		  return "";
	}
	foreach(exit in exits)  //��һ��ѯ,���
	{
		if(!undefinedp(all_exits[file][exit]))
		{
			if(all_exits[file][exit][0]=='/')//����Ŀ¼����
		 		msg +=  exit +":"+all_exits[file][exit]+",";
			else
				msg +=  exit +":"+dir+all_exits[file][exit]+",";
				longexitmsg+= exit2long[exit]+filename_to_short[all_exits[file][exit]]+"��";
		}
	}
	longexitmsg=longexitmsg[0..<3]+"��";//���Ķ��Ż��ɾ��
	// 	log_file("dd.log",filename+"'s longexitmsg is "+longexitmsg+"\n");
	all_exits[file]["long"] = longexitmsg;
	return msg[0..<2];
}
//�����ļ�����         �ļ���
int create_data(string file)
{
	string exit_msg ;
	all_data[dir][file]=([]);
	if(!filename_to_short[file])
	{
		write("�޷����� "+file+" ��\n");
		return 0;
	}
	exit_msg =get_exit_msg(file);//���������к��������������������δ����
	if(! short_to_set[filename_to_short[file]])//�����̣����������������� �������û������
		all_data[dir][file]["roomset"] = filename_to_short[file]+":�������û�������κ���Ϣ���ݣ��ȴ���ʦ����д��#exitlong#\n";
	else all_data[dir][file]["roomset"] = short_to_set[filename_to_short[file]];//�����̣�����������������
 
	all_data[dir][file]["roomset"]=replace_string(all_data[dir][file]["roomset"],"#exitlong#",all_exits[file]["long"]);
	all_data[dir][file]["roomset"]+="exits:"+exit_msg+"\n";
	//log_file("dd.log","\n"+filename+" roomset is"+all_data[dir][file]["roomset"]);
	return 1;
}
//��������������
object create_it(string room_filename)
{
	object room;
	int n;
	if((n=strsrch(room_filename,'/',-1)) != -1)//�������飬��ֹ���˺����ô�����������������
	{
		dir=room_filename[0..n];//ȫ�ֱ�����ʼ��		
		file=room_filename[n+1..];
	}
    else {write(room_filename+" is not a full path filename.\n");return 0;}
	if(all_data==([])){write("all_data�ǿյģ�xj�ļ���ʽ������\n");return 0;}
	if(undefinedp(all_data[dir])){write("dir=="+dir+" ������\n");return 0;}
	
	if(undefinedp(all_data[dir][file])
		||n=(file_name(previous_object(2))=="/cmds/wiz/update"))
	{  //��һ�����л�update�������ļ������ܱ��޸Ĺ���ֻ�����¶�ȡ
		if(n) test_file();//��֤�ļ��Ƿ����,���������ļ�����������
		if(member_array(dir,alldir)!=-1)
		{
			if(!read_map(dir)){write("dir=="+dir+" �µ�ͼ��ȡ����\n");return 0;}
			//���������ͼ�����ı����г���
			if(!set_exits(map)){ write("dir=="+dir+" �µ�ͼ���Ӵ���\n"); return 0;}
	// �����ڵ�ǰ��ͼ�ڵ����з��������
			foreach(temp in allfile) create_data(temp);
		}
	}
	//Ӧ�ò�����ã�����һ�����һ��
	if(undefinedp(all_data[dir][file])||all_data[dir][file]==([]))
		{write("all_data["+dir+"]["+file+"]�ļ�δ���þ�������...\n");return 0;}
	
	room=new(ROOM);
	room_set(room,all_data[dir][file]["roomset"]);
	//���ļ����Ͷ���������mapping ���������room���ݼ���
	//	log_file("dd.log","\n"+filename+" now is \n"+roomobj->query("short")+"\n"+roomobj->query("long")+"\n");
	room->reset();
	return room;
}
int create()
{
	seteuid(getuid());
	set("name","���羫��");
    set("channel_id","���羫��(dd)");	
	if(!read_file_msg()) return 0;
	//log_file("dd.log","xj�ļ����Գɹ�������room-list�ɹ�");
	alldir=({});
	return read_dir();
}
string pinyin(string hanzi)
{
	//if(!file = read_file(filename)){	write("�޷���ȡ���ļ���"+filename+"\n");return 0;}
	//mapping hz2py=([]);
	int hzlong,i;
	string *fileline=explode(read_file("/d/wiz/pinyin"),"\n");
	string py,hz,*hzs,mypinyin;
	hzs=({});
	mypinyin="";
	hzlong=sizeof(hanzi)/2;//how many hz
	for(i=0;i<hzlong;i++)
	 hzs+=({ hanzi[(i*2)..(i*2+1)] });//�ֳɼ��������ĺ���
	foreach(temp in fileline)
	{
		sscanf(temp,"%s:%s",py,hz);
			for(i=0;i<hzlong;i++)
			{
				if(strsrch(hz,hzs[i])%2==0)//��ֹ���ִ�λ����
					//hz2py[hzs[i]]=py;
					hzs[i]=py;
			}
	}
			//foreach(t1 in hzs)		mypinyin+=hz2py[t1];
			mypinyin=implode(hzs,"");
			//ĩβ��ͬ��˵���д���λ�ã���ôƴ���������
					if(hanzi[<2..<1]!=mypinyin[<2..<1])
                    {   f_line=f_line[0..<2]+({hanzi+":"+mypinyin,"#list_end#"});
                        write_file(WORLD_FILE,implode(f_line,"\n"),1);
                    }
				return mypinyin;
	}
//�Ƴ������ַ�������Ч�ո�,��������﷨����
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

	 allstr=explode(s1,"\"");//���ܳ�����һ���ַ�������Ϊ�գ����ܱ�������һ��Ҫ��ϸ����ȷ��,Ŀǰ������
	long=sizeof(allstr);
	s2="";
	for(i=0;i<long;i++)
	//���ı�""�ַ����е��κ��ַ�,�����ķָ����ظ�һ�Σ����ں����Ϸ�����������ַ����еķ��ų�ͻ
		s2+=((i%2==0)?
        replace_string(replace_string(replace_string(allstr[i]," ",""),":","::"),",",",,")
        :"\""+allstr[i]+"\""	);
	return s2;
}
//��ʱ�Ȳ�����������ܱȽϺã������п�������ɫ���������ȿ��ܳ����Բ��뷴����ª
string str_format(string name,string long_desc)
{
	string s1,s2;
	int i,k,howlong=80;//ÿ��40�����֣�����2���ֽ�
	s2=long_desc;
    if (strsrch(s2,"\\n")!=-1) //�����Լ��趨��ʾ��ʽ���Ͳ����һ����
       return replace_string(s2,"\\n","\n");
	s1 = replace_string(s2,",","��");//�����滻�������ֿ��ܱ����
    s1 = replace_string(s1,".","��");
    s1 = replace_string(s1,"?","��");
    s1 = replace_string(s1,";","��");
    s1 = replace_string(s1,":","��");
    s1 = replace_string(s1,"!","��");
    if(s1!=s2){write("��ǰĿ¼"+dir+"�·���--"+name+"--�����������а�Ǳ����ţ����޸�Ϊ����ȫ�Ƿ���\n");
	log_file("dd.log","��ǰĿ¼"+dir+"�·���--"+name+"--�����������а�Ǳ����ţ����޸�Ϊ����ȫ�Ƿ���\n ");}
	s1 = "    "+s1;
	i=sizeof(s1)/howlong+1;
	s2="";
		for(k=0;k<i;k++)s2+=s1[k*howlong..(k+1)*howlong-1]+"\n";
	return s2;
}
//�ַ�������ȥ����������������־�ת����
mixed str2right(string s)
{
	if(s[0]=='\"'&&s[<1]=='\"')s=s[1..<2];
		else sscanf(s,"%d",s);//���b�����־�ת������
	return s;
}

int room_set(object room,string arg)
{
	/*
	���ⷿ��ʱר��set����,ÿ������һ�������ı��� ����������,�����趨�����ĳЩ�����ĺ����ڵı�����ʽΪ("aaa":bbb),
	bbb������ 12332 ��  "fsffd" ��  x,y,z  �� a:1,b:2,c:3    ��ʽ,�����������ƻ�ֵ�������ڲ������пո�,�лᱻ���ˣ�������""��������
	�������,�����䡢ֵ��Ŀո�����ν��
//������򵥵����ݣ����������������Ϊ1������д��һ�����Խ�Լ���棬�м��ö��ŷֿ���
//�������ݣ�ÿ������һ��
	*/
	string inputarg,name,*allline=({});
	mixed args,checking,a,b,index;
    temp=arg;
	if(sscanf(temp,"%s:%s\n%*s",name,args)==3)
	{		room->set("short",name);
			args=str_format(name,args);//���������룬��ʱ�Ȳ�����������ܱȽϺ�
			room->set("long",args+"\n");
	}
	else log_file("dd.log","DIR"+dir+"�ķ��� "+room->query("short")+"�趨��described long lost :\n");
    temp=arg[strsrch(arg,"\n")+1..];
	if(!sizeof(temp))return 1;//����ֻ�г���������û���������ݣ����ַ�����࣬���ȴ���

    temp=replace_blank(temp);//ȥ����Ч�ո�,,��:���ظ�һ�Σ�""���������Ĳ�����
    allline=explode(temp,"\n");
	allline-=({""});
	foreach (inputarg in allline)
  {
      //log_file("dd.log","DIR "+dir+"���� "+room->query("short")+"�趨��inputarg is "+inputarg+"\n");
	 if(sscanf(inputarg,"%s::%s",name,args)!=2)
		log_file("dd.log","DIR "+dir+"���� "+room->query("short")+"�趨�� "+inputarg+" something is wrong\n");
	 //��򵥵�mapping��ʽ//a:1  �����Ǽ򵥵�����
 		if(strsrch(args,"::")==-1
        &&strsrch(args,",,")==-1
        &&sscanf(args,"%d",temp))
 		{ 			room->set(name,temp);continue;} 
		// a:"һЩ����" ������ĳ��ֵ�м��пո��:��,ʱʹ��
		if(args[0]=='\"'&&args[<1]=='\"'&&strsrch(temp=args[1..<2],"\"")==-1) 
 		{
 				room->set(name,temp);//�������ַ�����ʽ��ֵ,ֱ��������ȥ
 				continue;
 		}
		//��������ֵ��������array,ֱ�����,��������ô�����,�����ȼ���,����Ҳ������
		// x: 1,2,4,6,abc,3 ������д��
		if(strsrch(args,"::")==-1 &&strsrch(args,",,")!=-1)
		{
			temp=({});
			args=explode(args,",,");
			foreach(checking in args)
			{ temp+=({str2right(checking)});}
			room->set(name,temp);continue;
		}
//��������������:������
 //���ܰ�һ�Ѽ򵥵����ñ��� �����������Ϊ1֮�࣬����һ���Խ�ʡ���棬ĩβ��Ҫ�����õ� ��
 //x:1,m:2,c:5 ������д��
	  if((a=strsrch(args,"::"))!=-1
	   &&(b=strsrch(args,",,"))!=-1
	   &&a>b)
		{
			args=explode(inputarg,",,");
			foreach(checking in args)
			{
				if(sscanf(checking,"%s::%s",a,b)==2)
			 	 room->set(a,str2right(b));
				else log_file("dd.log","DIR"+dir+"���� "+room->query("short")+"�趨��"+inputarg+"something is wrong\n");
			}
			continue;
		}
	//����˲�����ָ�����е�mapping��  objects : x:1
	//����˲�����mapping������ objects : x:1,m:2,c:5 ������д��
	//item : x:1,m,c,5 ������д��
		
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
		
		//���������ʶ�����͵�����,ֱ�Ӱ�������Ϊ�ַ�������
		// xxx:������İ���  ������д��
		room->set(name,args);
   }
	return 1;
}
