#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("������", ({"dragon whip", "whip"}));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ����Լ���ߣ����������ɵĳ��ޡ�\n");
		set("unit", "��");
		set("value", 0);
		set("wield_msg","ֻ����ž����һ���죬$N����������һ�����ɫ�ĳ��ޣ�\n");
		set("unwield_msg", "$N������$n�������䣮\n");
		set("no_sell",1);
	}
	init_whip(150);
	setup();
}

