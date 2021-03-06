// created 20020314 stone
// shiban.c

inherit ITEM;

void init();
void breaks();

void create()
{
 	set_name("石板",({"shiban", "flagstone", "ban", "shi ban"}));
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
	set("long","醉星楼的一块石板，上面倾乎有字，模模糊糊，看不清楚。\n");
        set("material", "stone");
        set("value", 0); // reduced price because now shop's selling
        		// price variable.
	}        
	setup();
}

void init()
{
        add_action("do_breaks", "breaks");
        add_action("do_breaks", "pi");
         add_action("do_breaks", "劈");
}
int do_breaks(string arg){
	object ob,me;
	me=this_player();
	
	if( (!arg) || !((arg == "shiban") || (arg == "石板")))
                return notify_fail("你要劈什么？\n");
        if (me->is_busy()) 
        	return notify_fail("你现在正忙着呢。");        
	if( (int)me->query("kee") < 200)
		return notify_fail("你的力气不够了，不能自如运用内力。\n");
	if( (int)me->query("sen") < 200)
		return notify_fail("你现在神志不清，强行运功的怕有走火入魔的危险。\n");
	if( (int)me->query_skill("unarmed", 1) < 30)
		return notify_fail("你的拳脚功夫还不到火候，你不怕手会断吗！\n");
	if( (int)me->query_skill("force", 1) < 30)
		return notify_fail("你的内家功夫还不到火侯，强行运功恐怕会受内伤！\n");
	if( (int)me->query("force") < 300 )
                return notify_fail("你的真气不够。\n");
	if( !this_object()->id(arg) ) return 0;
	ob=new("/d/obj/book/anabook.c");
	message_vision("$N凝神定气，气沉丹田，内力运行一个小周天。\n", me);
	me->start_busy(3);
	message_vision("突然，$N双眼回睁，大喝一声「开」，化掌为刀，一掌劈向石板。\n顿时石板断为两截。从石板中掉出一样东西，$N忙放入怀中。\n",me);
	ob->move(me);
//	ob -> move(this_object());
	me->add("force", -50);
	destruct(this_object());
	return 1;		
}