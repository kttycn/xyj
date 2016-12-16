#include <ansi.h>
inherit ITEM;
//inherit F_AUTOLOAD;  

int do_locate(string arg);
int do_task();

void create()
{
	set_name(HIB"ˮ����"NOR, ({"shuijing qiu","qiu"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ������Ѱ��ʧ���"HIB"ˮ����"NOR"�������зǷ���ħ����\n"+
			"����(task)�г����ж�ʧ����Ʒ����(locate)�����ҵ���Ʒ�Ĵ��λ�ã�\n");
		set("unit", "��");
		set("value", 50000);
	}
	setup();
}

void init()
{
	object ob = this_player();

	add_action("do_locate","locate");
	add_action("do_task","task");
}

int do_task()
{
	string output;
	output=HIB"ˮ����"NOR"��ͻȻӳ�ֳ�һƪӬͷС�֣�\n\n"+TASK_D->dyn_quest_list();
	this_player()->start_more(output);
	return 1;
}

int do_locate(string arg)
{
	if ( ! arg)
		return notify_fail("locate <��Ʒ>\n");
	else
		TASK_D->locate_quest(this_player(),arg);
   this_player()->add("sen",-5);
   return 1;
}

//int query_autoload() { return 1; }
