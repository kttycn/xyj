#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
	set_name(MAG"�˰�÷����"NOR, ({ "meihua hammer", "hammer" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѷְ˰��÷��״��ͭ����������Ź�׭���˰�÷���Ͻ𴸡���\n");
		set("value", 0);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
		set("no_sell",1);
	}
	init_hammer(160);
	setup();
}

