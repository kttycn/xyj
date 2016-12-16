inherit ROOM;

int do_dig(string arg);

void create()
{
	set("short", "�ּ�յ�");
	set("long", @LONG
����һ���ּ�յأ����ܵ���ľ�������Ǳ����޼���һ�㣬��
�����յ�Χ��һ�������Բ�Σ��յ�����һ��޴��������ƽ����
����һ�Ѵ�ɡ��������Ҷï�ܵ���ȥ�˴������⡣
LONG
	);
	set("exits", ([
	]));

	set("outdoors", "dreamland");
	setup();
}

void init()
{
	add_action("do_dig","dig");
}

int do_dig(string arg)
{
	object ob = this_player();
	object wield;
	object sword;
	string sword_given,ziqing_given;

	sword_given = "/d/ourhome/honglou/dreamland/obj/qingsuo-sword.c";
//	ziqing_given = "/d/ourhome/honglou/dreamland/obj/ziqing-sword.c";

	if ( ! arg || arg != "di" )
		return notify_fail("��Ҫ��ʲô��\n");
//	if ( present("qingsuo sword",ob) || present("ziqing shuangjian",ob) )
//		return notify_fail("�㲻��������һ�����˿ɲ���̫̰�İ���\n");
	if ( present("qingsuo sword",ob))
		return notify_fail("�㲻��������һ�����˿ɲ���̫̰�İ���\n");
//	if ( (sword_given->in_mud()) || (ziqing_given->in_mud()) )
//		return notify_fail("��������һ�����Ѿ����˽����ȵ��ˡ�\n");
	if ( sword_given->in_mud())
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
		message_vision("$N��Ȼ���ִ����е���������\n",ob);
		sword=new("/d/ourhome/honglou/dreamland/obj/qingsuo-sword");
		sword->move(ob);
		if( sword->query("id")=="qingsuo sword" ) 
			MONITOR_D->report_rumor_object_msg(ob, "�õ������������ˣ�");
		return 1;
	}
	ob->add("kee",-50);
	ob->start_busy(1);
	message_vision("$N���˴����ľ���ʲôҲû���ڵ���\n",ob);
	return 1;
}
