#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(MAG"��"CYN"��"NOR"˫��"NOR, ({"ziqing shuangsword", "sword","shuangsword" }));
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ѵ���ɫ�ĵĹŽ���һ�ѵ���ɫ�ĹŽ���������һ�����ص�������\n");
		set("no_sell", 1);
		set("no_put", 1);
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/changjian");
		set("material", "crimsonsteel");
		set("wield_msg", "����ѣĿ�� "MAG"�� "CYN"�� "NOR"��������,˫������,��һ������,���ɺ���������\n");
		set("unwield_msg", "һ��ѣĿ��"MAG"�ϵ�"CYN"���"NOR"һ����$N���е�$n���з��뽣���С�\n");
		set("weapon_prop/courage", 5);
		set("weapon_prop/composure", 5);
	}
	init_sword(180);
	set("is_monitored",1);
	setup();
}
