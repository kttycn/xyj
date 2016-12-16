//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill,howlong, damage, force,time;
	mapping action; 
	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("你想要对着谁发呆？\n");

	if( target == me ) return notify_fail("看来也只有自己对着自己发呆了？\n");

	if (me->query_skill("idle-force",1)<200)
		return notify_fail("你的发呆大法还不够。\n");
	message_vision(HIC "\n$N使出发呆大法,痴痴的朝$n望去。\n"NOR,me,target);
	message_vision(HIC "\n$N一下惊呆了，当场昏迷.\n"NOR,target);
	command("rumor "+"听说"+target->name()+"被"+me->name()+"用发呆大法袭击成功！");
	howlong=1000-me->query_skill("idle-skill",1)*2;
	me->set("actions",action);
	me->reset_action();
	target->unconcious();
	me->start_busy(10);
	return 1;
}

