// edit by lucas
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "baoyu", "fish" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������⿵�������ı��㡣\n");
                set("unit", "��");
                set("food_remaining", 8);
                set("food_supply", 30);
        }
        setup();
}

