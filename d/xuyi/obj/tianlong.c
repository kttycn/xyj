#include <weapon.h>

inherit F_UNIQUE;
inherit HALBERD;

void create()
{
	set_name("�����", ({ "tianlong ji", "halberd" ,"ji"}));
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ʥ��ʦ����������������\n");
		set("value", 20000);
		set("replace_file", "/d/obj/weapon/halberd/huaji");
		set("material", "blacksteel");
	}
	init_halberd(140);
	set("is_monitored",1);
	setup();
}

