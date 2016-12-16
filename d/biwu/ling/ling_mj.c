// gangzhang.c 钢杖
#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name(HIR"圣火令"NOR, ({ "mjling" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块明教的圣火令。你可以召唤(zhao)护卫来保护自己。\n");
		set("armor_prop/intelligence",2);
		set("armor_prop/karey",2);
		set("armor_prop/percao",2);
		set("armor_prop/strength",2);
		set("armor_prop/dexerity",2);
		set("armor_prop/constitution",2);
		set("no_put",1);
		set("no_get",1);
		set("no_drop",1);
		set("rigidity",100);
		set("material", "steel");
	
	}
	setup();
}
void init()
{
	add_action("do_zhao","zhao");
}
int do_zhao()
{
object dizi,me;
int exp;
me = this_player();
   if( (int)me-> query_temp("number") > 0 )
     return notify_fail("你最多只能召唤一名随身弟子。\n");
   if (me->query("jing")<100) 
	return notify_fail("你精不够。\n");
 if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
if ( me->is_busy() )
        return notify_fail("你现在正忙得不得了，还有心思召唤你的弟子？\n");
	exp = (int)me->query("combat_exp");
	me->receive_damage("jing",100);
	dizi = load_object("/d/biwu/dizi.c");
	dizi->move(environment(me));
        dizi->invocation(me, (exp));
        dizi->set("possessed", me);
	 dizi->set_name(this_player()->query("name")+"的随身弟子",({"dizi"}));
        me->add_temp("number",1);
        me->remove_all_killer();
	message_vision(CYN "\n$N发出号令，召唤身边的弟子来保护自己！\n" NOR, me);	
	message_vision(CYN "\n$N的弟子随着号令声而来！\n" NOR, me);
	return 1;
}
