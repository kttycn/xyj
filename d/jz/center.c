//Cracked by Roath
inherit ROOM;

void create ()
{

	set ("short", "������");
	set ("long", @LONG

    ����С�ĳ������ģ������������˵�Ҳ���٣�ֻ��
һ��������æ�����Լ����£�·���л�������һЩ�췢��
�۵����࣬���Ǻ���������˴�������Ҫ������ȥ������
�ģ����Ѿ��ܿ��������ˡ�

LONG);

	set("exits",
	([ //sizeof() == 4
		"east" : __DIR__"sibei-w1",
		"west" : __DIR__"chengen-1",
		"north": __DIR__"xiaowu-1",
		"south": __DIR__"dingan-1",
		"up": __DIR__"jitan",
	]));
	set("objects", ([
		__DIR__"npc/people" :1,
	]));
	set("outdoors", "jiangzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
		if(dir =="up" && me->query("id")=="fei zei" ||("id") == "thief" ||("id") == "zei")
			return 0;
		return ::valid_leave(me, dir);
}

