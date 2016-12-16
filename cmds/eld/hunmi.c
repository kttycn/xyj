 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("找不到这个生物。\n");
	message_vision(HIB + "\n天空中一道神光倏然而下罩住了$n，$n应声摔倒在地上！！\n" + NOR,me,ob);
	ob -> unconcious();
	if ( !wizardp(ob) && userp(ob) ){
		log_file("static/hunmi", sprintf("%s(%s) 让 %s(%s) 昏了过去，时间 %s \n",
			me->name(1),geteuid(me),ob->name(1),geteuid(ob),ctime(time())));
		message("channel:chat",HIR"【监察精灵】公正法官(Faguan)："+"据说"+me->query("name")+"让玩家 "HIW+ob->query("name")+HIR" 昏了过去。\n"NOR,users());
	}
	return 1;
}
 
int help(object me)
{
   write(@HELP

指令格式: hunmi <id>
 
使某人立刻昏迷不醒

HELP
   );
   return 1;
}
