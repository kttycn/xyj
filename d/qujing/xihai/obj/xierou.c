// edit by lucas
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("з��", ({ "xierou", "rou" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ζ��з�⡣\n");
                set("unit", "��");
                set("food_remaining", 8);
                set("food_supply", 30);
        }
        setup();
}

