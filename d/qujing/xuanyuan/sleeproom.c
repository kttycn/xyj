// ��Ĺ���
inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG

����ǧ��ҪС��������ط����뵱���̴�������ʱ��槼�
��������ط�Ϊ�Լ�ѡ�����ѣ���ô��������һֱ���������
�����У����ǵ���Ǭ��������֮ƥ�еĺ����ˣ���������ط�
�ֳ����ڶ�С�������еĵط��������г�һ������Ҳ����槼�
һ����⡣��xiuxing��

LONG);
	set("exits", ([
		"east" : __DIR__"road3",
	]));
	set("no_clean_up",0);
	set("sleep_room",1);
	set("if_bed",1);
	setup();
}
void init()
{
	add_action("do_xiuxing","xiuxing");
}

int do_xiuxing()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if((string)me->query("family/family_name")!="��ԯ��Ĺ")
		return notify_fail("�㲻������ ��ԯ��Ĺ�ģ��ò��������������С�\n");
	if(me->query("faith")>200||me->query("daoxing")>100000)
		return notify_fail("���Ѿ�����Ҫ�����ֵط�������.\n");
	tell_object(me,"���������£��ų��������������ʱ��о��Լ��·�������ɾ�\n");

	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("spells",2);
	me->receive_damage("kee",50);
	me->receive_damage("sen",50);
	message_vision("$N���÷���������!\n",me);
	return 1;
}
