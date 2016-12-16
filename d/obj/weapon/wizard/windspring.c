// windspring.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( CYN "��Ȫ֮��" NOR, ({ "sword of windspring", "sword" }) );
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"���ǲ����������ഫ���������տ��ɫ�Ľ�������ɫ������ʹ\n"
			"�÷�Ȫ֮����Ϊ���С���֮���ߡ�������������֮�⣬��ѽ�Ҳ��\n"
			"���������������\n");
		set("value", 0);
		set("material", "sapphire");
		set("wield_msg", "$N��ˢ����һ�����һ�����������$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
		set("weapon_prop/courage", 15);
		set("weapon_prop/intelligence", 15);
		set("weapon_prop/personality", 15);
		set("rigidity", 40);
		set("replica_ob", "/obj/longsword");
	}

	init_sword(75);
	setup();
}

