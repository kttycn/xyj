// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>

inherit HALBERD;

void create()
{
	set_name("ľ�", ({"muji", "mu ji", "halberd","ji"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
		set("long", "����һľ�Ƶĳ�ꪣ�������ʱ�õģ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������\n");
	}
	init_halberd(15);
	setup();
}

