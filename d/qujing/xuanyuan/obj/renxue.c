// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
       set_name(HIR"��Ѫ"NOR ,({"xian xue","xue"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("long", "һ���ʺ����Ѫ.\n");
                set("unit", "��");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 60);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "���׾�",
                "drunk_apply": 10,
        ]));
}
