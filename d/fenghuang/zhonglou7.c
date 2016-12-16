inherit ROOM;

string look_out();

void create()
{
	set("short", "��¥�߲�");
	set("long", @LONG
���������¥֮����ֱ�������ı����ǿڴ��Ӻ�һ�����ҿ�
�еľ��ơ�ϸ�����ӣ��������������ߣ�ֱ��Ҳ������������
����ͭ������������������������Ǽ�ͼ�Σ�����������ǧ�
���ƴֿɺϱ����ɰ�������һͷ���Ժ�Ƥ������������������ɽ
�紵��������˭������ס��ײһ�������ԡ����⿴���и��ܴ��
������̨(out)���������վһ���ˡ�
LONG );
	set("exits", ([
		"down" : __DIR__"zhonglou6",
	]));
	set("objects", ([
		__DIR__"obj/bigzhong" : 1,
	]) );
	set("item_desc",([
		"out" : (: look_out :),
	]));
	setup();
}

void init()
{
	add_action("do_knock", "knock");
	add_action("do_out", "out");
}

int do_knock(string arg)
{
	object me;

	me = this_player();
	if ( !arg || ( arg != "bell" ) ) return notify_fail("��Ҫ��ʲ�᣿\n");

	me->add("kee", -200);

	if ( random((int)me->query("kar")) < 25 )
	{
		message_vision("$Nһ��С���õ��Լ�ͷ���ˡ�\n", me);
		me->add("kee", -10 - me->query("kee"));
	}

	else
	{
		mapping mine;

		mine = me->query_entire_dbase();
		message_vision("$N����һ�´��ӣ����ۡ���������������������\n", me);
		write("������Ѹ�װ��������ը�죬��ͷ����һƬ��Ϳ��\n"
			"ȫ��ҡҡ��׹������֧���Ų����ڵ��ϡ�����һ��\n"
			"���������㣬�øϿ��뿪�����Ȼ��û���ˡ�\n");

    if (random(2)==0) mine["combat_exp"] += 10; 
    else mine["potential"] += 10;
	}
	return 1;
}

int do_out(string arg)
{
	object me;
	int i, ging_cost, qi_cost;

	me = this_player();
//    i = (int)me->query_skill("dodge", 0) + random(200);
    i = (int)me->query_skill("dodge", 0) + random(5);
	ging_cost = 600 / (int)me->query("int");
	qi_cost = 500 / (int)me->query("int");
	if(((int)me->query("sen") < ging_cost) || ((int)me->query("kee") < qi_cost))
		i = 0;

	message_vision("$N���ϴ�̨��һ������������ȥ��\n", me);
	me->move(__DIR__"zhonglou");
    me->start_busy(1);
	message_vision("ֻ�����须��һ��$N����������������\n", me);
	if ( i < 50)
		me->die();
	else if( i < 140)
		me->unconcious();
	else if((int)me->query_skill("dodge", 1)<250){
		message_vision("$N�����ȵ�վ�ڵ��ϡ�\n", me);
		if( i > 175 && me->query("dodge",1)<200)
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("sen", ging_cost );
		me->receive_damage("kee", qi_cost );
	} else me->unconcious();

	return 1;
}

string look_out()
{
	return  "������������¥����Ĵ�̨�����������ң��������˳ǣ�������
���������۵ס���˵�ڴ˵ؿ������������ֱ�ӽ���������������
�����洦��\n";
}
