// /d/guzhanchang/obj/skull.c
//stone 20020624

#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("白骨骷髅",({"ku lou", "skull", "kulou"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","
                
一个白惨惨的骷髅头骨，当中两个黑洞洞的眼眶，正瞪着你，
仿佛还向你咧着嘴笑呢！你倒吸一口气，忙不迭的闭上眼睛。
\n");
                set("unit","个");
                set("value",5000);
                set("material","bone");
                set("wield_msg","$N抓住$n的鼻子，虽觉得很不顺手，但也还威风。\n");
                set("unwield_msg","$N把$n放回行囊中，甩了甩酸痛的手。\n");
        }
        init_hammer(5);
        setup();
}
