//Cracked by Roath
// girlbook.c

inherit ITEM;

void create()
{
	set_name("〖鞭法总谱〗", ({"whipbook","book","shu"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","一本小册子。上面密密麻麻地画着好多舞鞭的小人儿。\n");
		set("material", "paper");
		set("value", 500);   
		set("no_sell",1);
	}
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
	add_action("do_read", "du");
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("书要拿起来读。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("安全区内不能读书。\n");

    if( me->is_busy() )
       		return notify_fail("你现在忙着呢，哪有可能静心研读...\n");
   	if( me->is_fighting() )
       		return notify_fail("现在才想到精研鞭法，太晚了吧？\n");
	
	if( (int)me->query_skill("whip",1)<100 )
		return notify_fail("你看来看去，就是没明白这本小册子中写的都是啥。\n");
	if( (int)me->query_skill("whip",1)>140 )
		return notify_fail("你在鞭法方面已经很有造诣了，这本书不会让你长进多少。\n");

	sen_cost = 35 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("whip", 1)/5+(int)me->query("int")+1;
	me->improve_skill("whip", gain);

	message_vision("$N研读有关基础鞭术的技巧，似乎有点心得。\n", me);
	return 1;
}

