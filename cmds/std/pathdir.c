
void create()
{
   seteuid(getuid());
}

int main(object me)
{
	string *path = ({
		"/d/qujing/yingjian/",
		"/d/qujing/yinwu/",
		"/d/qujing/yuhua/",
		"/d/qujing/yunzhan/",
		"/d/qujing/zhujie/",
		"/d/qujing/zhuzi/",
	});
	string mvdir,*dir,room_s, room;
	int i, j, f;
	object room_o;
	
	for( i = 0; i < sizeof(path); i++ )
	{
		mvdir=path[i];
		dir=get_dir(mvdir);
	
		for( j = 0; j < sizeof(dir); j++ )
		{
			room_s=dir[j];
			room_s=mvdir+room_s;
			room=room_s+"\n";
			room_o=find_object(room_s);
			if(!room_o) room_o=load_object(room_s);
			if(!room_o) room="NULL\n";
			write_file("/log/room",room,0);
		}
	}
	return 1;
}

string find_path(int amount)
{
}
