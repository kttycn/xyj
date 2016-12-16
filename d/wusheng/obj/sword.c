// wusheng-sword.c ��������

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIW"��������"NOR, ({"chunyang sword", "baojian", "sword"}));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���޽���ı��������ŵ����⡣\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("value", 30000);
		set("material", "crimsonsteel");
		set("wield_msg", "$N��Цһ�����ӱ���γ���$n��������һ�ƣ��ֳ����⽣��\n");
		set("unwield_msg", "$N�����е�$n������У���Ƕ���һ˿Ц�⡣\n");
		set("weapon_prop/int", 50);
		set("replace_file", "/d/obj/weapon/sword/qingfeng");
	}
	set("is_monitored",1);
	init_sword(70);
	setup();
}

