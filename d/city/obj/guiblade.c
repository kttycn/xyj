//By waiwai@mszj 2000/09/28

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(HIB"��ͷ��"NOR, ({ "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "iron");
		set("long", "���ֺ��صĴ󵶣�ǿ��ϲ���ã�������Լʮ���ء�\n");
		set("wield_msg", "$N���һ�ѱ���߲���$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(28);
	setup();
}
