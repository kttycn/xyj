inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG

�������ﵱȻ���Ǻ�����ϲ���������ˣ�������
ƽʱҲϲ����Щ͵�����������飬������Щ�������
�����Ǻ����ϲ���Ի��ˣ����������ǵ����С�����
�Ļ�����������make��һ����ͷ���ԡ�

LONG);
	set("exits", ([
		"south" : __DIR__"nei1",
	]));
	set("objects", ([
		"/d/obj/misc/head":1,
		"/d/qujing/xuanyuan/obj/renxue":2,
		"/d/obj/misc/head2":1,
		"/d/obj/food/jitui":3,
	]));
	setup();
}


void init()
{
	add_action("do_make","make");
}
int do_make()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if((string)me->query("family/family_name")!="��ԯ��Ĺ")
		return notify_fail("�㲻������ ��ԯ��Ĺ�ģ��ò���������������ͷ\n");
	if(me->query("faith")>200||me->query("daoxing")>100000)
		return notify_fail("������Ҫ�����ֵط��ɻ��ˣ�\n");
	tell_object(me,"��ץ��һ�����ˣ�......�������������ʱһ��ͷ­�����ˡ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->add("combat_exp",15);
	me->add("daoxing",15);
	me->add("potential",4);
	me->add("bellicosity",1);
	me->improve_skill("spells",2);
	me->receive_damage("kee",50);
	message_vision("$N���÷���������!\n",me);
	("/d/obj/misc/head")->move(me);
	return 1;
}
