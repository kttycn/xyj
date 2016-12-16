inherit ROOM;

void create ()
{
	set ("short", "�ȵ�");
	set ("long", @LONG

���Ϸ����Ƿɷ�壬��Ҳ������Լ�����ô�ᵽ����ط��ġ��Ա�
�ĵ��Ϻ��������Щʲô������

LONG);
	set("outdoors", "guanjiang");
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_dig","dig");
}

int do_climb(string arg)
{
	object ob = this_player();

	if( ! arg || arg != "cliff" )
		return notify_fail("��Ҫ��ʲô��\n");

	if ( random(4) == 2 )
	{
		message_vision("ֻ��$Nһͷ����������\n",ob);
		ob->unconcious();
		return 1;
	}
	message_vision("ֻ��$NС�ĵ�������ȥ��\n",ob);
	ob->move("/d/meishan/cuiping");
	return 1;
}

int do_dig(string arg)
{
	object ob = this_player();
	object wield;
	object zhu;
	string tuzhu_given,shengzhu_given;
	tuzhu_given = "/d/obj/baowu/tuzhu.c";
//	shengzhu_given = "/d/obj/baowu/shengzhu.c";
	if ( ! arg || arg != "di" )
		return notify_fail("��Ҫ��ʲô��\n");
//	if ( present("tu lingzhu",ob) )
//		return notify_fail("�㲻��������һ�����˿ɲ���̫̰�İ���\n");
	if ( (tuzhu_given->in_mud()) )
		return notify_fail("��������һ�����Ѿ����˽����ȵ��ˡ�\n");
	if(!wield=ob->query_temp("weapon"))
		return notify_fail("������û��������\n");
	if(((string)wield->query("skill_type")!="sword"
	&& ((string)wield->query("skill_type")!="blade")))
		return notify_fail("��Ӧ���Ұѽ������ǵ�ʲô�ġ�\n");

	if( random(6) == 3 )
	{
		ob->add("kee",-50);
		message_vision("$N��������һ�ᣬͻȻ�о��и��������ڵ��¡�\n",ob);
		message_vision("$N��Ȼ����һ��ǳ��ɫ�����ӡ�\n",ob);
		zhu=new("/d/obj/baowu/tuzhu");
		zhu->move(ob);
		if (zhu->query("id")=="tuzhu" || zhu->query("id")=="tu lingzhu") 
			MONITOR_D->report_rumor_object_msg(ob, "�õ��������ˣ�");
		return 1;
	}
	ob->add("kee",-50);
	ob->start_busy(1);
	message_vision("$N���˴����ľ���ʲôҲû���ڵ���\n",ob);
	return 1;
}
