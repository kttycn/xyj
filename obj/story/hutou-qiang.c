//yitianjian.c
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
    set_name(HIY"��ͷǹ"NOR, ({ "hutou qiang", "qiang","spear" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 20000);
//        	set("no_drop", "1");
        	set("material", "blacksteel");
        	set("long", "�������µ�һǹ���������屦��������ƽ���¡�\n");
        	set("wield_msg",HIC"ֱ�������ˮ���������һ�㣬$n"HIC"����$N���У����Ϊ֮��ɫ��\n"NOR);
        	set("unwield_msg", HIC"$N��$n�ջ�ǹϻ�������������ؼ�ֻ��������\n"NOR);
	}
	init_spear(180);
	set("is_monitored",1);
	setup();
}
