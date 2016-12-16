// wusheng-pifeng.c ������������

#include <ansi.h>
#include <armor.h>

inherit F_UNIQUE;
inherit SURCOAT;

void create()
{
	set_name(HIY"������������"NOR, ({"busi pifeng", "pifeng", "cloth" }));
	set_weight(4500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "һ���ò�������ë���ƶ��ɵ����硣\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("material", "crimsonsteel");
		set("unit", "��");
		set("value", 30000);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 5);
		set("armor_prop/spells", 10);
		set("replace_file", "/d/qujing/huangfeng/obj/jinyipifeng");
	}
	set("is_monitored",1);
	setup();
}


