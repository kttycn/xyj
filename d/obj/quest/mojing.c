
inherit ITEM;
#include "task.h"
#include <ansi.h>

void create()
{
        set_name(HIB"墨镜"NOR, ({"mo jing"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一副鼹鼠的专用墨镜。\n");
                set("unit", "副");
               set("owner_name","鼹鼠精");
                set("owner_id","yan shu");
        }
}

