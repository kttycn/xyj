// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping fm_weapon=([
	"方寸山三星洞":"stick",
	"南海普陀山":"staff",
	"月宫":"sword",
	"东海龙宫":"hammer",
	"阎罗地府":"whip",
	"陷空山无底洞":"sword",
	"火云洞":"spear",
	"大雪山":"sword",
	"五庄观":"sword",
	"蜀山剑派":"sword",
	"将军府":"spear",
	"盘丝洞":"whip",
	"武圣门":"sword",
	"盱眙山":"halberd",
	"轩辕古墓":"needle",
]);

void give_weapon(object me,object ob)
{
	seteuid(getuid());
	if(me->is_apprentice_of(ob))
	{
		if( me->query("family/family_name") == "凤凰星" )
		{
			if( !me->query("family_wp") )
			{
				me->set("family_wp","done");
				message_vision(CYN"$N微笑着对$n说道：我门下弟子虽无师门兵器，但是你若能刻苦用功，
拳脚功夫也胜过那些中看不中用的兵刃！！\n"NOR,ob,me);
			}
			return;
		}
		if(!me->query("family_wp")){
			object wp=new("/obj/weapon");
			wp->set("owner_id",me->query("id"));
			me->set("family_wp/type",fm_weapon[me->query("family/family_name")]);
			me->set("family_wp/damage",10);
			wp->set_value(me);
			wp->move(me);
			message_vision("$N微笑着对$n说道：这件"HIW+wp->query("name")+
				NOR"乃通灵之物，你要好好保管！！\n",ob,me);
		}
		else if(me->query("family_wp/id")&&!present(me->query("family_wp/id"),me))
		{
			object wp=new("/obj/weapon");
			wp->set("owner_id",me->query("id"));
			wp->set_value(me);
			wp->move(me);
			message_vision("$N对$n说道：这件"HIW+
			wp->query("name")+NOR"你拿回去吧！\n",ob,me);
		}
	}		 
}

int main(object me, string arg)
{
	object ob, old_app;
	mapping family, skills;
	int i;
	string *skname;

	if( !arg ) return notify_fail("指令格式：apprentice [cancel]|<对象>\n");

	if( arg=="cancel" )
	{
		old_app = me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
			return notify_fail("你现在并没有拜任何人为师的意思。\n");
		write("你改变主意不想拜" + old_app->name() + "为师了。\n");
		tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
		me->delete_temp("pending/apprentice");
		return 1;
	}

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("你想拜谁为师？\n");

	if( me->query("guild/master") )
		return notify_fail("你已经脱离三界，自立门户，再拜师也学不到什么东西了吧。\n");
	if( ob->query("guild/child") )
		return notify_fail("你没有能力收弟子，还是向你师父介绍一下吧。\n");
		
	if( !living(ob) )
		return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

	if( ob==me )
		return notify_fail("拜自己为师？好主意．．．不过没有用。\n");

	if( me->is_apprentice_of(ob) )
	{
		message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);
		give_weapon(me,ob);
		return 1;
	}

	if( !mapp( ob->query("family") ) )
		return notify_fail(ob->name() + "既不属于任何门派，也没有开山立派，不能拜师。\n");

	if ( (me->query("family")) && (me->query("family/family_name") != ob->query("family/family_name")) )
		return notify_fail(ob->name()+"是"+ob->query("family/family_name")+"师傅，未经本派师门同意不能改换门派！\n\n");

	if (ob->query("family/master_id") == me->query("id"))
		return notify_fail("开什么玩笑？拜自己的徒弟为师？\n");

	if ( userp(me) && userp(ob) && (wizardp(me) != wizardp(ob)) )
		return notify_fail("巫师玩家之间不能有师徒关系。\n");
/*
	if( me->query("family") ){
	if((int)ob->query("family/generation") >= (int)me->query("family/generation") )
		return notify_fail("你只能拜比自己辈份高的人为师。\n");
	}
*/
// If the target is willing to recruit us already, we do it.
	if( (object)ob->query_temp("pending/recruit") == me )
	{
		if( (string)me->query("family/family_name") != (string)ob->query("family/family_name") )
		{
			message_vision("$N决定投入$n门下！！\n\n"
				"$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",me, ob);
			me->set("score", 0);
			me->add("betrayer", 1);
		} else
			message_vision("$N决定拜$n为师。\n\n"
				"$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",me, ob);
		ob->recruit_apprentice(me);
		ob->delete_temp("pending/recruit");

		tell_object(ob, "恭喜你新收了一名弟子！\n");
		if( ob->query("guild/master") )
			me->set("guild/child", 1);
		family = me->query("family");
		printf("恭喜您成为%s的第%s代弟子。\n", me->query("family/family_name"),
			chinese_number( me->query("family/generation")));
		return 1;
	} else
	{
		old_app = me->query_temp("pending/apprentice");
		if( ob==old_app )
			return notify_fail("你想拜" + ob->name() + "为师，但是对方还没有答应。\n");
		else if( objectp(old_app) )
		{
			write("你改变主意不想拜" + old_app->name() + "为师了。\n");
			tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
		}

		message_vision("$N想要拜$n为师。\n", me, ob);
		me->set_temp("pending/apprentice", ob );
		if( userp(ob) )
		{
			tell_object(ob, YEL "如果你愿意收" + me->name() + "为弟子，用 recruit 指令。\n" NOR);
		} else 
			ob->attempt_apprentice(me);
		give_weapon(me,ob);
		return 1;
	}
}

int help(object me)
{
write(@HELP
指令格式 : apprentice|bai [cancel]|<对象>
 
这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即行
拜师之礼，否则要等到对方用 recruit 指令收你为弟子才能正式拜师。

请注意你已经有了师父，又背叛师门投入别人门下，所有技能会减半，并且
评价会降到零。

如果对你的师父使用这个指令，会变成向师父请安。
 
请参考相关指令 expell、recruit
HELP
    );
	return 1;
}
