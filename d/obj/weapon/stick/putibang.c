#include <weapon.h>

inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name("������", ({"puti zhang", "zhang"}));
        set_weight(47000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�Ѱ���ɫ�Ķ̰���\n");
                set("value", 23300);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
				set("replace_file", "/d/obj/weapon/stick/qimeigun");
        }
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
    set("is_monitored", 1);
        init_stick(140);
        setup();
}
