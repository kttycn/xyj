#include <weapon.h>

inherit HALBERD;

void create()
{
	set_name("���", ({ "ji", "halberd" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ƽ���ĸ�ꪣ�����û�������\n");
		set("value", 1000);
		set("material", "blacksteel");
		set("wield_msg", "����һ�֣�ֻ��$N��������һ��ѩ����$n����\n") ;   
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_halberd(15);
	setup();
}

