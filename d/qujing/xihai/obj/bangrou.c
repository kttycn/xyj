// edit by lucas

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "bangrou", "rou" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����ɿڵİ��⡣\n");
                set("unit", "��");
                set("food_remaining", 4);
                set("food_supply", 15);
        }
        setup();
}

