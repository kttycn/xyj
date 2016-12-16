//By waiwai@mszj 2000/10/30

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object ob,string arg)
{
	object me,obj;
	int jin, qi, hun, neili, fali, shiwu, yinshui;
	if (!arg)  me = ob;
	else
	{
		me = present(arg, environment(ob));
		if (!me) me =  find_player(arg);
		if (!me) return notify_fail("你要恢复谁的状态？\n");
	}
	if (!wizardp(me) && userp(me) ){
		if(wiz_level(ob)<4)
			return notify_fail("你没有权利恢复玩家的状态？\n");
		MONITOR_D->report_rumor_object_msg( ob,"正在恢复"HIW+me->name()+
			"("+capitalize(me->query("id"))+")"HIM"的状态!\n");
		log_file("static/full", sprintf("%s(%s) full %s(%s) %d 时间 %s\n",
		ob->name(1), geteuid(ob), me->name(1), geteuid(me), wiz_level(ob), ctime(time()) ) );
	}

	jin = me->query("max_sen");
	qi =me->query("max_kee");
	hun =me->query("max_gin");
	fali = me->query("max_mana");
	neili = me->query("max_force");
	shiwu = me->max_food_capacity();
	yinshui = me->max_water_capacity();
	me->set("eff_sen", jin);
	me->set("eff_kee", qi);
	me->set("eff_gin", hun);
	me->set("sen", jin);
	me->set("kee", qi);
	me->set("gin", hun);
	me->set("mana", fali*2);
	me->set("force", neili*2);
	me->set("food", shiwu*3);
	me->set("water", yinshui*3);
	me->set("anger", 0);
	me->clean_condition();
	write(HIY"你虔诚地喃喃自语道：我无上的天神呀，给我回复的力量吧！！！\n"NOR);
	tell_object(me,HIW"你突然被一道神光包围，觉得全身充满活力！！！\n"NOR);

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : full [id]

此指令可让你恢复所有的精气。
HELP
    );
    return 1;
}
