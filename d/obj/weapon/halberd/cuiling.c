#include <weapon.h>
inherit HALBERD;

void create()
{
	set_name("������", ({ "cuiling halberd", "halberd" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "˫");
		set("long", "һ˫��ꪣ��������г����Ĳ����趯ʱ��Ϊ������\n");
		set("value", 6000);
		set("material", "blacksteel");
		set("wield_msg", "$N������ȡ��һ˫$n������Ʈ�ޣ������쳣��\n");
		set("unequip_msg", "$N�����е�$n�������󣬲�������$N���ܡ�\n");
	}
	init_halberd(60, TWO_HANDED);
	setup();
}

