// cuiyu.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIG"����"NOR, ({"cui yu", "yu"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "һ֧���̵���ë��\n");
		set("value", 0);
		set("material", "plant");
		set_weight(10);
		set("armor_prop/armor", 10);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N����ذ�һ֧$n�����ޱߡ�\n");
		set("unequip_msg", "$N����ذ�$n���޽�ժ��������\n");
	}
	setup();
}
