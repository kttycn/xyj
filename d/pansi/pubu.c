// pubu.c 
// by/lestat

inherit ROOM;
#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_xianmei();

#include <ansi.h>
void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
��������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ��һ
�����ٲ����������ӵ������Ӹ�����ֱк������������������Ԩ������������
��������ͷ��������
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" :  __DIR__"tao_out",
	]));
	set("objects",([
		__DIR__"npc/qingxia" : 1,
	]));
	set("outdoors", "xiaoyao" );
	set("no_clean_up", 0);
	setup();
}
 
void init()
{
	object where=this_object();
	remove_call_out("check_time");
	check_time(where);
	add_action("do_xianmei","xianmei");
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object ob;
	int new_sen;
	ob = this_player();
	new_sen = random( ob->query("max_sen")*3 );
	if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
	if( !arg || arg=="" ) return 0;
	if( arg != "down" )
		return notify_fail("����Ҫ������ɱ����ô�벻������\n");
	tell_object(ob, HIR"�㲻��˼��������һԾ�����������¡�������\n"NOR);
	message("vision", NOR"ֻ��" + ob->query("name") + "�����ң���������������֮�С�������\n"NOR, environment(ob), ob);
	if((ob->query_skill("dodge",1)<30) && ob->query("family/family_name") != "��˿��"){
		ob->unconcious();
		ob->receive_damage("sen",new_sen);
		ob->move(__DIR__"yanfeng");
	}else{
		ob->move(__DIR__"yanfeng");
	}
	return 1;
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));
	if((phase==45)&&(!query("pansi/start_hungry"))) feel_hungry(where);
	if((phase==48)&&query("pansi/start_hungry")) feel_full(where);
	call_out("check_time",40,where);
}

void feel_hungry(object where)
{
	message("channel:es",HIM+"����˿������ϼ����(Qingxia xianzi)��������鷳�ƣ���֪��λ��ͽ������οһ���Ұ���\n"+NOR,users());
	set("pansi/start_hungry",1);
}
void feel_full(object where)
{
	tell_object(where,"��ϼ����Ц������������ƽ�����ˡ�\n");
	set("pansi/start_hungry",0);
}
int do_xianmei()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("pansi/start_hungry"))
		return notify_fail("��ϼ���Ӱ�����һ�ۣ�����������õĺܣ���Զ�㡣\n");
	if((string)me->query("family/family_name")!="��˿��")
		return notify_fail("��ϼ����˵���������鷳����������ʲô�£�\n");
 	if(me->query("faith")>800)
		return notify_fail("��Щ��������������������ɡ�\n");
	tell_object(me,"�㲻ͣ�İ�ο����ϼ���ӣ�ֱ����ϼ����˵��ת��Ϊϲ��\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("pansi-dafa",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"����������˿�󷨽����ˣ�\n");
	return 1;
}
