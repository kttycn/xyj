// wusheng-cloth.c �Ų�Ʈ��˿��

#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIM"�Ų�Ʈ��˿��"NOR, ({"jiucai pao", "pao", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������濾꣬�����˿���������Ų���ɫ��˿�ۡ�\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("unit", "��");
		set("value", 40000);
		set("material", "crimsonsteel");
		set("armor_prop/armor", 70);
		set("armor_prop/dodge", 15);
		set("armor_prop/spells", 10);
		set("replace_file", "/d/obj/cloth/writepao");
	}
	set("is_monitored",1);
	setup();
}

void init()
{
	cloth::init();
	unique::init();
}

