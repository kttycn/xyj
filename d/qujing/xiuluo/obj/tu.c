inherit ITEM;

void init();
int do_read(string arg);

void create()
{
	set_name("��Ǭ��ͼ��", ({"qiankun-tu","tu"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","������һ����Ƥ�����滭�Ÿ�ʽ����������Ѩλ��\n");
		set("material", "paper");
		set("value", 500);   
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
	}
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");

	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);
		remove_call_out ("destroy_book");
		call_out ("destroy_book", 18000/5*2);//5 hours
	}
}

void destroy_book()
{
	message_vision("һ��紵����" + (string)this_object()->query("name") + "ƬƬ���䣬����ȥ�ˡ�\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("Ǭ��ͼҪ����������\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("��ȫ���ڲ��ܶ���\n");
	if(me->query("xiuluo/jinchanzi")!="done" )
		return notify_fail("��������ģ�\n");
	if( me->is_busy() )
		return notify_fail("������æ���أ����п��ܾ����ж�...\n");
	if( me->is_fighting() )
		return notify_fail("���ڲ��뵽�����ϳ���ѧ��̫���˰ɣ�\n");
	if( (int)me->query_skill("literate",1)<200 )
		return notify_fail("�㿴����ȥ������û������ͼ�ϻ�����ʲô���⡣\n");
	if( (int)me->query_skill("dianxue",1)>160 )
		return notify_fail("����Ǭ����Ѩ�󷨷����Ѿ��������裬������Ƥ��������Ѿ�û���ˡ�\n");

	sen_cost = 35 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n"); 
	me->receive_damage("sen", sen_cost*3/2);

	gain = (int)me->query_skill("dianxue", 1)/5+(int)me->query("int")+1;
	me->improve_skill("dianxue", gain);

	message_vision("$N����Ǭ��ͼ��ϲ�Ľе�����Ȼ����������Ϊ�ϳ���ѧ��\n", me);

	return 1;
}
