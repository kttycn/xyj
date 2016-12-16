#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
        set_name(CYN"������"NOR, ({ "qingsuo sword", "sword","qingsuo" }));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ϸϸ�ĹŽ�,�����Ͽ���"+CYN"��������"NOR+"����,��������������⣬�������ˡ�\n");
		set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
		set("no_put", 1);
		set("no_drop", "��ô����Ķ��������˶��ϧѽ��\n");
		set("no_give", "�����������а������������ˣ�\n");
		set("no_get", "�㱻�����ϵĺ���һ����һ�����£�����һ�ɣ����������л��䣡\n");
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/xijian");
		set("material", "crimsonsteel");
		set("wield_msg", "ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
		set("unwield_msg", "$N�����ҡ,"+MAG"��۫��"NOR+"�����зɻ����С�\n");
		set("weapon_prop/int", 3);
	}
	init_sword(120);
	set("is_monitored",1);
	setup();
}
