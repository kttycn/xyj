inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�����ǰ��һ���ú������̳ɵ�̨�ף�һֱ�������죬���ߵ�ǽ�ڶ�
�ǻ����ң�ǽ�ϸ�ʮ��������һյ�͵ƣ�ʹ���ܿ�����Χ��
LONG );
	set("exits", ([
		"up" : __DIR__"houyuan",
		"southdown": __DIR__"midao1",
	]));
	set("objects",([
		__DIR__"npc/weishi1" : 2,
	]));
	set("no_fight",1);
	set("no_magic",1);
//	set("no_clean_up", 0);
	  setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "southdown") )
	{
		if( ((string)me->query("family/family_name") != "�����") 
		&& !wizardp(me) )
			return notify_fail ("��ǰ����������ס�㣬˵�������Բ��𣬱����صأ���أ���\n");
		return ::valid_leave(me, dir);
	}
	return 1;
}
