// edit by lucas

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "hetun", "fish" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���綾�ĺ����㣬��Ȼ����ζ������ҳ���\n");
                set("unit", "��");
                set("food_remaining", 4);
                set("food_supply", 15);
        }
        setup();
}


