// By xiaom 23/3/2001
// modify By Canoe 2001.03.24
// random(dodge_skill)>99&&random(kar)>27
// busy 3 , ��receive_damage("kee", 30);
inherit ROOM;
void create ()
{
	set ("short", "ϲȵ��");
	set ("long", @LONG

������һƬ�����де����֣����������ϲȵ(xique)������
��ȥ��ߴߴ�����и���ͣ��
LONG);
	set("objects", ([
		"/d/niulang/obj/xique.c" : random(7) ,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"eside1",
	]));
	set("outdoors", "changan-south");

	setup();
}
void init()
{
	add_action("do_zhuo", "zhuo");
}
int do_zhuo(string arg)
{
	object me=this_player();
	object xique;
	int fy,qg;
	if ( !arg || ((arg != "xique") ))
		return notify_fail("��Ҫ׽ʲô��\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n"); 
	if (me->query("kee") < (int)(me->query("max_kee")/3))
		return notify_fail("����ЪЪ�ɣ���֪������ץϲȵ����ϲȵץ��:P\n");
	message_vision("$N�����������������������������������ˣ�\n",me);
	fy= me->query_kar();
	qg=me->query_skill("dodge",1);
	xique=present("xique", environment(me));
	if ( random(qg) < 100)
		return notify_fail("������һ�룬����һ�����ȣ����Դ�ˤ��������\n");
	if (random(fy)<28)
		return notify_fail("������һ����˭֪���������ã�һ�Ųȿգ���ͨˤ�˸������ࡣ\n");
//message_vision("$N�����������������������������������ˣ�\n",me);
	if(!xique) {
		message_vision("$N���ĵؽӽ�ϲȵ��ͻȻһ���춯��ϲȵ�������ˣ�\n",me);
		return 1;
	}
	if(!xique->move(me)) {
		message_vision("$N�Ĵ��Ķ���̫���ˣ����������ˤ��������\n",me);
		return 1;
	}
	else message_vision("$N�͵�һ�ˣ�׽ס��һֻϲȵ��\n",me);
	me->start_busy(3);
	me->receive_damage("kee", 30);
	return 1;
}
