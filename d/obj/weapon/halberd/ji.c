#include <weapon.h>

inherit F_UNIQUE;
inherit HALBERD;

void create()
{
	set_name("�޹��", ({ "chubai qiang", "halberd" ,"ji"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�˰�ɭɭ���Ϲ������\n");
		set("value", 20000);
		set("replace_file", "/d/obj/weapon/halberd/huaji");
		set("material", "blacksteel");
	}
	init_halberd(80);
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
	set("is_monitored",1);
	setup();
}

