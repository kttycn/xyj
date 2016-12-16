inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
	add_action("do_da", "da");
	add_action("do_jia", "jia");
}
void create()
{
	set_name(HIY"机器人"NOR"一号", ({ "jiqi ren","ren", }));
	set_weight(1000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "樽");
		set("material", "stone");
		set("no_get", "这样东西你搬不动，你还是别费力了。\n");
		set("long", "这是一个练功用的机器人你可以(da)(jia)。\n", );
	}
}

int do_da(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 

	if (!(arg=="jiqi ren" || arg == "jiqi"))
		return 0;
	if (me->is_busy()) {
		write("你现在正忙着呢。\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("你无法在战斗中专心下来打！\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "凤凰星"
	&& !(int)me->query("xmark/学员"))
	{
		write("你不是凤凰战士不能用！\n");
		return 1;
	}
	if (!id(arg)) { 
		write("你要打什么？\n");
		return 1;
	}
	message("vision", me->name() + "开始使用机器人。\n", environment(me), me);
	if( (int)me->query("kee") < 5 ) {
		write("你现在过于疲倦，无法专心下来打。\n");
		return 1;
	}
	pxlevel = me->query_skill("unarmed", 1);
	if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
		write("你的实战经验不足，不能用。\n");
		return 1;
	}
	if( me->query_skill("unarmed", 1) > 80){
		write("你已经不能从机器人身了领悟到更多的东西了。\n");
		return 1;
	}
	me->receive_damage("kee", 30);
	me->improve_skill("unarmed", (int)me->query_skill("unarmed", 1)/2+random(200));
	write("你开始使用机器人。\n");
	return 1;
}
int do_jia(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 

	if (!(arg=="jiqi ren" || arg == "jiqi"))
		return 0;
	if (me->is_busy()) {
		write("你现在正忙着呢。\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("你无法在战斗中专心下来打！\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "凤凰星"
	&& !(int)me->query("xmark/学员"))
	{
		write("你不是凤凰战士不能用！\n");
		return 1;
	}
	if (!id(arg)) { 
		write("你要干什么？\n");
		return 1;
	}
	message("vision", me->name() + "开始使用机器人。\n", environment(me), me);
	if( (int)me->query("kee") < 20 ) {
		write("你现在过于疲倦，无法专心下来打。\n");
		return 1;
	}
	pxlevel = me->query_skill("parry", 1);
	if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
		write("你的实战经验不足，不能用。\n");
		return 1;
	}
	if( me->query_skill("parry", 1) > 80){
		write("你已经不能从机器人身了领悟到更多的东西了。\n");
		return 1;
	}
	me->receive_damage("kee", 30);
	me->improve_skill("parry", (int)me->query_skill("parry", 1)/2+random(200));
	write("你开始使用机器人。\n");
	return 1;
}

