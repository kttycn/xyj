#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY "����" NOR, ({ "baoguo", "xingli", "bag" }) );
        set_weight(500);
        set_max_encumbrance(28000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������ɮʦͽȡ���õİ�����\n");
                set("value", 8000);
        }
}

int is_container() { return 1; }

