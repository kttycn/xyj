//Cracked by Roath
// girlbook.c

inherit ITEM;

void create()
{
	set_name("���޷����ס�", ({"whipbook","book","shu"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ��С���ӡ�������������ػ��źö���޵�С�˶���\n");
		set("material", "paper");
		set("value", 500);   
		set("no_sell",1);
	}
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
	add_action("do_read", "du");
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("��Ҫ����������\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("��ȫ���ڲ��ܶ��顣\n");

    if( me->is_busy() )
       		return notify_fail("������æ���أ����п��ܾ����ж�...\n");
   	if( me->is_fighting() )
       		return notify_fail("���ڲ��뵽���б޷���̫���˰ɣ�\n");
	
	if( (int)me->query_skill("whip",1)<100 )
		return notify_fail("�㿴����ȥ������û�����ⱾС������д�Ķ���ɶ��\n");
	if( (int)me->query_skill("whip",1)>140 )
		return notify_fail("���ڱ޷������Ѿ����������ˣ��Ȿ�鲻�����㳤�����١�\n");

	sen_cost = 35 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("whip", 1)/5+(int)me->query("int")+1;
	me->improve_skill("whip", gain);

	message_vision("$N�ж��йػ��������ļ��ɣ��ƺ��е��ĵá�\n", me);
	return 1;
}

