// changan wusheng
// xuanya0.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

�ͱھ�����ǰ������һ����
LONG);
set("exits", ([ /* sizeof() == 4 */
"south": __DIR__"shijie8",
]));
set("objects", ([
        "/d/wusheng/npc/laozhe": 1]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object laozhe;
	object me=this_player();

	if( (!arg) || !((arg == "xuanya") || (arg == "����")))
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy()) return notify_fail("��������æ���ء�");
	if( me->query("kee") < (int)(me->query("max_kee")/3)){
		me->receive_damage("kee",(int)me->query("max_kee")*20/100);
		return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
	}
	if (!((string)me->query("family/family_name")=="��ʥ��" )&&
	objectp(laozhe = present("laozhe", environment(me))) && living(laozhe)
	&&!wizardp(me))
		message_vision("�����������˼䲢��Ϸˣ֮��������ɧ�����ɼ�����\n", me);
	else
	{
		if ((int)me->query_skill("dodge", 1)<100 && (int)me->query_skill("mizong-steps", 1) < 100)
		{
			message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
			me->improve_skill("dodge", 100-me->query("str"));
			tell_object(me, "�������һЩ�����Ṧ��������š�\n");
		}
		else
		{
			message_vision("$N������������һ������������������Ƶ����²����ˡ�\n", me);
			me->move(__DIR__"xuanya1.c");
		}
	}
	me->receive_damage("kee", (int)me->query("max_kee")*10/100);
	return 1;
}
