//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name(HIW"�齫��"NOR, ({"majiang pai", "pai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���齫�ơ�\n");
                set("unit", "��");
               set("owner_name",HIC"�׾���"NOR);
               set("owner_id","bai jingjing");
        }
}
