#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name( HIY"轩辕剑"NOR , ({ "xuanyuan sword", "sword" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
HIY"这是一柄黄金色之千年古剑，传说是天界诸神赐于轩辕黄帝击败
蚩尤之旷世神剑：其内蕴藏无穷之力，为斩妖除魔的神器。\n" NOR
);
//              set("value", 0);
          	set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
		set("no_put", "这柄古剑装不进容器里去。\n");
		set("no_drop", "这么稀世难求的神兵宝剑，扔了多可惜呀！\n");
		set("no_give", "这可是神兵宝刃啊，哪能随便给人？\n");
		set("no_get", "你刚摸到剑身，突然轩辕剑现出万道金光，你心中一惊，忙把手缩了回去。\n");
                set("material", "gold"); 
                set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("wield_msg",HIY "突然四周金光大盛，仿佛金色阳光，摄人心魄，定睛细看，只见$N手中已多了一柄$n。\n" NOR);
                set("unwield_msg", "金光瞬间暗淡,$N将手中的"HIY"$n"NOR+"插入腰间的剑鞘。\n");
                set("weapon_prop/personality", 8);
                set("male_only", 1);
        }

        set("is_monitored", 1);
        init_sword(180); 
        setup();

}


void owner_is_killed(object killer)
{
        message_vision("\n"YEL"轩辕剑"NOR+"落在地上，瞬间金光大盛，突然又消失了。\n",killer);
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{   
        if ( !((string)me->query("gender")=="男性")) return 0;
        if (random(8)<2) return 0;
        if ( !((string)victim->query("gender")=="女性")){
    victim->busy(random(1));
//    return HIY "轩辕剑发出万道耀眼的金光，金光中$N犹如金甲天神，$n不由胆战心惊。\n" NOR;
    return HIY "$N举起轩辕剑，自上而下重重的一挥，轩辕剑中现出万道金色光芒，宛如万龙钻出般扑向$n，
光芒所到之处仿佛像能吸人的精魂似的，$n感到一阵眩晕。\n" NOR;
//    return HIY "光芒所到之处，仿佛能吸人精魂般，$n不禁胆战心惊。\n" NOR;
			
			}
    return 0;
}
 

