//By waiwai@mszj 2000/09/28

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_smoke", "xiyan");
}

void create()
{
	string *order = ({HIC"�л�"NOR, HIC"��ǰ��"NOR, HIR"���"+HIW"����"NOR, HIM"����ɽ"NOR, HIM"��·"NOR, HIB"ϣ����"NOR, 
HIW"����"NOR, HIY"ʥ����"NOR, HIY"����"NOR, HIG"����"NOR, HIG"��Ϫ"NOR, HIR"��˫ϲ"NOR, HIM"��è"NOR,});
	set_name( (order[random(sizeof(order))]), ({ "xiang yan", "yan" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����̣����� "+HIR"(xiyan) \n"NOR);
		set("unit", "��");
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_get", 1);
		set("count",8);
	}
}


int do_smoke()
{
	object me = this_player();
	object obj = this_object();

	if(environment(obj) != me)
		return notify_fail("�����ڿ��̰ɣ�\n");
	if(query("master") && query("master") != me->query("id"))
		return notify_fail("�����Ѿ���ȼ�ˣ����Ҳ�������̡�\n");
	add("count",-1);
	me->add("sen", 50);
	me->add("kee", -50);
	switch(query("count")) {
		case 1: message_vision("$N������һ��ʣ�µ�"+YEL"��ƨ��"+NOR"��������ָ��סһ�����ӵ�����ͷ��\n", me);
			break; 
		case 2: message_vision("$N�³�һ��"+HIC"��Ȧ"+NOR"�����������е�ɢ����\n", me);
			break;
		case 3: message_vision("$N�����۾������������һ��$n���ִӱǿ������������ˬ����ˬ������\n", me, obj);
			break;
		case 4: message_vision("$N�ݺݵ�����һ��$n�����������̫���ˣ�һ�����ǵ�ͨ�졣\n", me, obj);
			break;
		case 5: message_vision("$N����һ��$n��ҡͷ���Ե�˵����������һ֧�̣�����"+HIM"�����ɡ���\n"NOR, me, obj );
			break;
		case 6: message_vision("$N��������ȣ������۾���������һ��$n����������������ⶫ�������ֺ�����Ϊɶ�һ�\n��ôϲ������\n", me, obj);
			break;
		case 7: set("master", me->query("id"));
			message_vision("$N���һ֧$n��������"BLINK HIR"��"+NOR" �����̵�����������\n", me, obj);
			break;
		default:
			break;
	}        
	if(query("count") > 1) call_out("do_smoke", 10);
	else destruct(obj);
	return 1;
}
