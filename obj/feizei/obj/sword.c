#include <weapon.h>
#include <ansi.h>
inherit SWORD;
//inherit F_UNIQUE;
void create()
{
    set_name(HIW"�ɽ�"NOR, ({ "xian jian", "sword","jian" }) );
    set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//                set("unique", 1);
                set("no_drop",1);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",0);
            	set("no_get",0);
        	set("material", "iron");
                set("long", "�Ϲ�ʮ�����֮һ���ɽ�");
                set("wield_msg","ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��\n");
                set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
//            set("is_monitored",1);
        }
        init_sword(90+random(15));
        setup();
}

