//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
	set ("short","����С·");
	set ("long", @LONG

����һ���ֳ���խ������С·�����������Ĳ�֪�����˼�����,С·��
����������߾�����ѻ��Ĵ�ͷ�ˡ������������ߣ��ϱߵ����ߵ�
����Խ��Խ���ˡ�
LONG);

	set("outdoors", "shushan");
	set("exits", ([      
		"southwest" : __DIR__"shanlu",
		"east" : __DIR__"exit",
		"north" : __DIR__"jitan",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
		if(dir =="north" && me->query("id")=="fei zei" ||("id") == "thief" ||("id") == "zei")
			return 0;
		return ::valid_leave(me, dir);
}
