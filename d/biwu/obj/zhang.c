// gangzhang.c ����

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit HANDS;

void create()
{
	set_name(HIY"����"NOR, ({ "shenstaff" }));
	set_weight(25000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������������ȣ�������š��ԹŽ�����а��ʤ������������ٻ�(alert)�����������Լ���\n");
		set("rigidity",100);
		set("no_put", 1);
		set("no_sell", 1);
		set("no_drop", 1);
		set("value", 300000);
		set("armor_prop/strength",3);
		set("armor_prop/courage",3);
		set("armor_prop/composure",3);
		set("armor_prop/intelligence",3);
		set("armor_prop/spirituality",3);
		set("armor_prop/constitution",3);
		set("armor_prop/personality",15);
		set("armor_prop/karma",3);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	set("is_monitored",1);
	setup();
}
