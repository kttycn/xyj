// diamond.c

#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIW"��ʯ"NOR, ({"diamond", "zuanshi", "diamond_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "diamond");
                set("long", HIM"����������ʯ���˼��˰�����ʯ����������ʯ��\n"NOR);
                set("unit", "����");
                set("base_value", 500000 );
                set("base_unit", "����");
                set("base_weight", 5);
        }
        set_amount(1);
}




