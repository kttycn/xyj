// created 6/8/97 pickle
// lingjian.c

inherit ITEM;

void init();
void breaks();

void create()
{
       	set_name("柱子",({"zhuzi", "zhu", "zi", "zhuzi", "pillar"}));
	set_weight(100000);
/*        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long",
	"一本脏兮兮的小册子。上面划着一些象是蚯蚓爬出来的图案。\n");
        set("material", "paper");
        set("value", 0); // reduced price because now shop's selling
	// price variable.
        set("skill", ([
                        "name": "spells",
                        "dx_required": 50,
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill": 40,
]) );
        }*/
	setup();
}

void init()
{
        add_action("do_breaks", "breaks");
}
int do_breaks(string arg){
	object ob,me;
	me=this_player();
	
	if( (!arg) || !((arg == "zhuzi") || (arg == "pillar")))
                return notify_fail("你要劈什么？\n");
        if (me->is_busy()) return notify_fail("你现在正忙着呢。");
        
	if( (int)me->query("kee") < 200)
		return notify_fail("你的力气不够了，不能自如运用内力。\n");
	if( (int)me->query("sen") < 200)
		return notify_fail("你现在神志不清，强行运功的怕有走火入魔的危险。\n");
	if( (int)me->query_skill("unarmed", 1) < 30)
		return notify_fail("你的拳脚功夫还不到火候，你不怕手会断吗！\n");
	if( (int)me->query_skill("force", 1) < 30)
		return notify_fail("你的真力还不够充沛，强行运功恐怕会受内伤！\n");
	if( (int)me->query("force") < 300 )
                return notify_fail("你的真气不够。\n");
	if( !this_object()->id(arg) ) return 0;
	ob=new("/d/obj/book/anabook.c");
	message_vision("$N凝神定气，气沉丹田，内力运行一个小周天。\n", me);
	me->start_busy(3);
	message_vision("突然，$N双眼回睁，大喝一声，「开」开，化掌为刀，一掌劈向柱子。顿时柱子断为两截。从柱子中掉出一样东西。\n",me);
	ob->move(me);
	me->add("force", -50);
	destruct(this_object());
	return 1;		
}