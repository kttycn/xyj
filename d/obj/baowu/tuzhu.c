#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;
inherit F_UNIQUE;

int do_wear(string arg);
int do_remove(string arg);
int do_amalgamation();
object offensive_target(object me);

void create()
{
	set_name(HIY "土灵珠" NOR, ({"tu lingzhu", "tuzhu"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("material", "crystal");
		set("no_steal",1);
		set("value",0);
		set("no_put","这样东西装不进容器里去。\n");
		set("no_give","如此宝贵的宝物再世难求啊。\n");
		set("no_drop", "如此宝贵的宝物再世难求啊。\n");
		set("no_sell", "卖掉？谁能买得起？");
		set("replace_file", "/d/sea/obj/pearl");
		set("long","传说中的五行宝珠之一，佩之可避石砸，并可发出土系法术。\n为祈雨所必需之物。");
		set("armor_prop/armor", 1);
		set("spells/earth", 1);
	}
	set("is_monitored",1);
	setup();
}

int init()
{
	add_action("do_wear","wear");
	add_action("do_remove", "remove");
	add_action("do_amalgamation", "combine");
	return 1;
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int do_wear (string arg)
{
	object me = this_player();
	object zhu = this_object();
	string name = zhu->query("name");
	string msg;

	if(arg!="all" && arg != "tuzhu" &&	arg != "tu lingzhu" )
		return notify_fail("你要佩带什么？\n");
	msg = "$N戴上一颗"+name+"，黄色的宝珠在胸前一颤一颤的。\n"; 
	if(zhu->query("unequip_msg"))
		zhu->delete("unequip_msg");
	zhu->set("wear_msg",msg);
	remove_call_out("tuzhuconditions");
	call_out("tuzhuconditions",7,me,zhu);
	return 0;
}

int do_remove (string arg)
{
	object me = this_player();
	object zhu = this_object();
	string name = zhu->query("name");
	string msg;

	if (arg != "all" && arg != "tuzhu" && arg != "tu lingzhu")
		return notify_fail("你要摘掉什么？\n");

	msg = "$N将"+name+"轻轻地摘下来……\n"; 
	zhu->delete("wear_msg");
	zhu->set("unequip_msg",msg);
	remove_call_out("tuzhuconditions");
	return 0;
}

void tuzhuconditions(object who,object ob)
{
	object target;
	int ap,dp,damage;
	string msg;
	string type;
	type = ob->query("armor_type");
	if( !who || !ob )
		return;
	if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
		return;
	if( who->is_fighting())
	{
		if( ! target = offensive_target(who) ) return ;
		if( ! present( target,environment(who)) ) return ;		
		msg = HIY"土灵珠冉冉升起，$n的头上出现一座巨大的石山，只见土灵珠一沉，\n
石山急速下落！\n"NOR;

		ap = 2000000;
		dp = target->query("combat_exp");
			
			
		if( random(ap + dp) > dp )
		{
			damage = 500+random(300);
			damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
			damage -= random((int)target->query("mana_factor"));

			if( damage > 0 ) 
			{
				msg += HIC "结果$n躲避不及，被石山砸个正着！头破血流。\n" NOR;

				target->receive_damage("sen", damage*4/5);
				target->receive_wound("sen", damage/3);
				target->receive_damage("kee", damage*4/5);
				target->receive_wound("kee", damage/4);
			} 
			else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
		msg += HIC "\n谁知$n毫无反应。\n" NOR;	 
		}
		else
			msg += "但是被$n躲开了。\n";

		message_vision(msg, who, target); 
	}
	call_out("tuzhuconditions",7,who,ob);
}
int do_amalgamation()
{
	//五珠合璧
	object wind,water,thunder,earth;
	object who = this_player();
	object shengzhu;
	string shengzhu_given;
	shengzhu_given = "/d/obj/baowu/shengzhu.c";

	if(who->is_fighting())
		 return notify_fail("你正打仗呢！想死啊！\n");
	if(who->is_busy())
		 return notify_fail("你正忙着呢!\n");
	if(!wind = present("fengzhu",who))
		 return notify_fail("你还缺少"+HIG "风灵珠" NOR +"呢!怎么五珠合壁呢?\n");
	if(!thunder = present("leizhu",who))
		 return notify_fail("你还缺少"+HIB "雷灵珠" NOR +"呢!怎么五珠合壁呢?\n");
	if(!earth = present("huozhu",who))
		 return notify_fail("你还缺少"+HIR "火灵珠" NOR +"呢!怎么五珠合壁呢?\n");
	if(!water = present("shuizhu",who))
		 return notify_fail("你还缺少"+HIW "水灵珠" NOR +"呢!怎么五珠合壁呢?\n");
	if ((water->query("equipped")!="worn") && (wind->query("equipped")!="worn") && (thunder->query("equipped")!="worn") && (earth->query("equipped")!="worn") && (this_object()->query("equipped")!="worn"))
	{	
		if ( !(shengzhu_given->in_mud()) ) {
			message_vision("$N把五颗宝珠放在一起。只见五颗宝珠冉冉升起，一时宝光大盛，直冲云霄！\n
俄顷，"+HIG "风灵珠" NOR+"飞至东方放出柔和绿光；"+HIR "火灵珠" NOR +"飞至南方发出灼目红光；"+HIB "雷灵珠" NOR +"飞至西方忽明忽暗，\n
闪出幽幽蓝光；"+HIW "水灵珠" NOR +"却通体莹白，飞至北方；"+HIY "土灵珠" NOR +"直冲天穹，泻下万里黄光。\n
又待片刻，五珠呼的一暗，$N手中却多了一颗硕大的透明宝珠，不时发出五彩毫光。\n",who);
			shengzhu = new("/d/obj/baowu/shengzhu");
			shengzhu->move(who);
			MONITOR_D->report_rumor_object_msg(who, "拿到圣灵珠了！");
		} else {
			message_vision("$N把五颗宝珠放在一起。只见五颗宝珠冉冉升起，一时宝光大盛，直冲云霄！\n
俄顷，"+HIG "风灵珠" NOR+"飞至东方放出柔和绿光；"+HIR "火灵珠" NOR +"飞至南方发出灼目红光；"+HIB "雷灵珠" NOR +"飞至西方忽明忽暗，\n
闪出幽幽蓝光；"+HIW "水灵珠" NOR +"却通体莹白，飞至北方；"+HIY "土灵珠" NOR +"直冲天穹，泻下万里黄光。\n
又待片刻，五珠呼的一暗，一切都消失了。\n",who);
		}
		destruct(wind);
		destruct(water);
		destruct(earth);
		destruct(thunder);
		destruct(this_object());
		return 1;
	}
	return notify_fail("宝珠必须摘下才能合璧！\n");
}
