#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIR"ʬ"HIG"Ѫ"HIM"��"HIC"��"NOR, ({"shenbing", "dao","blade"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�����޽����֮������˵�е��Ϲ������\n");
		set("value", 25);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�ɲʱ����ر�ɫ������񺿣�$N�о�ӵ��������ħ����\n");
		set("unwield_msg", "$N���һ����$nת���Ѿ������ˡ�\n");
		set("weapon_prop/courage", 15);
	}
	init_blade(160);
	setup();
}
