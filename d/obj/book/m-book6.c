inherit ITEM;

void create()
{
        set_name("����ϡ����", ({ "boji xidoufang", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������������������йر���������顣\n");
                set("value", 100000);
                set("material", "paper");
                set("exp_required", 50000);
                set("jing_cost", 90);
                set("difficulty", 27);
                set("min_skill", 70);
                set("max_skill", 80);
        }
}
#include "m-book.h";
               