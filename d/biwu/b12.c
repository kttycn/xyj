inherit ROOM;
void create()
{
	set("short", "����¥��ʮ����");
	set("long", @LONG
����һ�������������˼�ʮ������ֵ�¥������ʮ�Ĳ�֮�ߡ�
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"b11",
		"up":__DIR__"b13",
	]));
	set("objects", ([
		__DIR__"npc/puti": 1,
	]));
	setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
}

int do_dazuo()
{
   object me;
   me = this_player();
   tell_object(me,"���ﲻ�ܴ�����\n");
return 1;
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="up" && ob=present("master puti", this_object()))
return notify_fail( 
"����Ӳ������\n");
return 1;
}
