
inherit ITEM;

void create()
{
        set_name("�ٱ���", ({ "bag" }) );
        set_weight(0);
        set_max_encumbrance(8000000);
                set_max_items(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������еİٱ�����\n");
                set("value", 50000);
        }
}

int is_container() { return 1; }



