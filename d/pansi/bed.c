//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
	set("short", "ǧ�꺮����");
	set("long", @LONG

һ��ǧ�꺮�����ɵ�С������˵��������ڹ���������.
LONG
	);

	set("exits", ([
		"out": __DIR__"shishi3",
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("sleep_room",1);
	set("if_bed",1);

	setup();
}

void init() {
	add_action("do_sleep","sleep");
	::init();
}

int do_sleep()
{
	object me=this_player();
	int lvl_force, c_exp, c_skill;
	if (this_player()->query("family/family_name")!="��˿��")
	{
		write("�㶳��ȫ����,������ȥ����Ҳ˯���š�\n");
		this_player()->start_busy(1);
		return 1;
	}

	lvl_force=(int)me->query_skill("force",1);
	if(lvl_force>150) //force ���� 150
	{
		this_player()->start_busy(3);
		message_vision("$N�����˺��񴲣���ʼǱ���ڹ���ʹ��Ϣ���д�С���졣\n",this_player());
		if (random(20)>12) {
			message_vision("$N��Ϣ��ϣ�ֻ���þ���������Ϣ���������ڶ�����\n", this_player());
			c_exp=me->query("combat_exp");
			c_skill=me->query_skill("force",1);
			if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<250))
			{
				me->improve_skill("force", random(lvl_force));
			}
			me->receive_damage("kee",random(lvl_force/3));
		}
		else
			message_vision("$N��Ϣ��ϣ�վ������������������������ûʲô������\n", this_player());
	}
	else {
		this_player()->start_busy(1);
		message_vision("$N���Ϻ��񴲣�ֻ���ñ���̹ǣ���������һ���Ǳ�����������������\n", this_player()); }
	return 1;
}
