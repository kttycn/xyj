#include <weapon.h>

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
		set("material", "blacksteel");
	}
	set("wield_msg", "����һ�֣�ֻ��$N��������һ��ѩ����$n����\n") ;   
	set("unwield_msg", "$N�������е�$n��\n");
	init_halberd(140);
	setup();
}

