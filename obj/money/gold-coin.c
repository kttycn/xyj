#include <ansi.h>
inherit MONEY;

void create()
{
	set_name(MAG"��Ӱ���"NOR, ({"gold-coin", "ingot", "gold-coin_money"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "jinbi");
		set("long", HIY"һö��Ӱ��Ե��Ӳ�ң������ǷƷɸ���׿�����е�ȫ���񣬷�����ȫ����ʦ��ȫ�Ҹ���\n"NOR);
		set("unit", "��");
		set("base_value", 1000000);
		set("base_unit", "ö");
		set("base_weight", 3);
	}
	set_amount(1);
}

