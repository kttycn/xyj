// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit F_UNIQUE;
inherit HALBERD;

void create()
{
	set_name("����ǹ", ({ "chubai qiang", "halberd" ,"ji"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "С��̫�ӹ���֮�ϙ�������������ɺ��׺������ɡ�\n");
		set("value", 20000);
		set("replace_file", "/d/obj/weapon/halberd/huaji");
		set("wield_msg", "����һ�֣�ֻ��$N��������һ��ѩ����$n����\n") ;   
		set("unwield_msg", "$N�������е�$n��\n");
		set("material", "blacksteel");
	}
	init_halberd(70);
	set("is_monitored",1);
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
	setup();
}
