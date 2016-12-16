// yuyi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"����"NOR, ({ "yu yi", "yi" }));
	set("long", "����һ�����߲���ë�Ƴɵ�˿�£���Ȼ������ȴ�ر�ů�\n");
	set_weight(0);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("wear_msg", HIW "ֻ����ˢ����һ����$Nչ��һ����ɫ���������ϡ�\n" NOR);
		set("remove_msg", HIW "$N�����´����������������۵���СС��һ�š�\n" NOR);
		set("armor_prop/armor", 200);
		set("armor_prop/dodge", 50);
		set("replace_file", "/d/obj/cloth/bai");
		set("armor_prop/personality", 10);
		set("value", 1000000);
		set("female_only", 1);
	}
	set("no_sell",1);
	set("no_give", 1);
	set("no_get", 1);
	set("no_put",1);
	set("is_monitored",1);
	setup();
}

void init()
{
	cloth::init();
	unique::init();
}
