// created 20020425 stone
// goldstone.c

inherit ITEM;
#include <ansi.h>
void init();
void lians();

void create()
{
 	set_name(HIY"金矿石"NOR,({"shitou","shitou","stone"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
	set("long","这是一块闪烁着点点黄光的石头，好像是一块矿石。\n");
        set("material", "stone");
        set("value", 0); 
	}        
	setup();
}

void init()
{
        add_action("do_lians", "lians");
        add_action("do_lians", "liangold");
        add_action("do_lians", "炼");
}
int do_lians(string arg){
	object ob,me;
	me=this_player();
	
	if( (!arg) || !((arg == "shitou") || (arg == "金矿石")))
                return notify_fail("你要以内法力炼什么？\n");
        if (me->is_busy()) 
        	return notify_fail("你现在正忙着呢。");        
	if( (int)me->query("kee") < 200)
		return notify_fail("你的力气不够了，不能自如运用内力。\n");
	if( (int)me->query("sen") < 200)
		return notify_fail("你现在神志不清，强行运功的怕有走火入魔的危险。\n");
	if( (int)me->query_skill("force", 1) < 200)
		return notify_fail("你的内家功夫还不到火侯，强行运功恐怕会受内伤！\n");	
	if( (int)me->query("force") < 2000 )
                return notify_fail("你的真气不足，不能发出比火焰更炽烈的热力，。\n");
        if( (int)me->query("mana") < 2000 )
                return notify_fail("你的法力还不充盈，不能施展「炼石成金」神通。\n");
	if( !this_object()->id(arg) ) return 0;
	ob=new("/obj/money/gold.c");
	message_vision("$N从怀中取出一块石头。\$N猛地深吸一口真气，盘膝坐下，把石头用双手上下盖住。\n\n", me);
	me->start_busy(8);
	message_vision(HIR"一会后，$N面色涨红，头顶冒出丝丝白烟，$N的双手，却变得如火焰般赤红。\n\n"NOR,me);	
	message_vision("$N手中的石头竟渐渐缩小，一股烧焦石头的气味散了开来。\n到最后$N手中的石头竟不见了，$N的掌心中，却多了一块黄澄澄的金子。\n",me);
	ob->move(me);
	ob -> move(this_object());
	me->set("force", 0);
	me->set("mana", 0);
//	me->add("force", -50);
//	me->add("nama", -50);
	destruct(this_object());
	return 1;		
}