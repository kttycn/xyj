inherit ITEM;

void create()
{
        set_name("�����", ({ "douzhen dinglun", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������촿�������Ľ�������ҩ����顣\n");
                set("value", 50000);
                set("material", "paper");
                set("exp_required", 200000);
                set("jing_cost", 80);
                set("difficulty", 26);
                set("min_skill", 60);
                set("max_skill", 70);
        }
}
#include "m-book.h";
                