#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(MAG"��"CYN"��"NOR"˫��"NOR, ({"ziqing shuangsword", "sword" }));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѵ���ɫ�ĵĳ�����һ�ѵ���ɫ�ĳ�����������һ�����ص�������\n");
		set("no_sell", 1);
		set("no_put", 1);
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/changjian");
		set("material", "crimsonsteel");
		set("wield_msg", "����ѣĿ�� "MAG"�� "CYN"�� "NOR"��������,˫������,��һ������,���ɺ���������\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
		set("weapon_prop/int", 9);
		set("weapon_prop/per", 4);
	}
	init_sword(180);
	set("is_monitored",1);
	setup();
}
