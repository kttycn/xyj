#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
	set_name( HIW"�����ָ"NOR, ({ "ice ring", "ring" }) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
    	set("long", "�����ָ����Ȼ�����γɣ�ͨ����һ����Ѫ�ĺ�˿��������ζ�����˵����\n���б�а�Ĺ�Ч��\n");
		set("material", "gold");
		set("armor_prop/unarmed", 2);
		set("armor_prop/armor", 1);
		set("armor_prop/spells", 2);
        set("wear_msg", "$N��$n�ó�������������ָ�ϡ�\n");
	}
	setup();
}
