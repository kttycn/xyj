inherit ROOM;

void create()
{
	set("short", "��˳�����");
	set("long", @LONG
��˳���һ�������ո۳��С�ÿ�춼���кܶ��ÿʹ����ﾭ����������������������
��������ʮ��������һ����������ҵ�ֺ�ᶫ����    
LONG );
	set("exits", ([
		"north" : __DIR__"bjie1",
		"south" : __DIR__"shentang",
		"east"  : __DIR__"eshangjie1",
		"west"  : __DIR__"shangjie1",
		"up"    : __DIR__"jitan",
	]));
	set("objects",([
		__DIR__"npc/xunbu" : 2,
		__DIR__"npc/bing" : 4,
	]));
	set("outdoors", "fenghuang");
	set("no_fly",1);
	setup();
	call_other("/obj/board/fenghuang_b", "???");
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
		if(dir =="up" && me->query("id")=="fei zei" ||("id") == "thief" ||("id") == "zei")
			return 0;
		return ::valid_leave(me, dir);
}

