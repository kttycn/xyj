#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIC"�������µ�"NOR, ({"dragon blade", "dao","blade"}));
	set_weight(22000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "������ʥ���Ƴ�֮����������ذ�ʮ��������ޱȡ���˵����ϵ�������书�������ǡ������ܡ�\n");
		set("value", 25);
		set("wield_msg", "$N��ৡ���һ���ɳ�һ��$n�������У�ɲʱ��$N����ɫ�ֳ���⣬ת˲���š�\n");
		set("unwield_msg", "$N���һ����$nת���Ѿ������ˡ�\n");
		set("weapon_prop/courage", 15);
	}
	init_blade(160);
	setup();
}
