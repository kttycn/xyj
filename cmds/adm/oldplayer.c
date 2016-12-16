// snowman.

#include <ansi.h>
inherit F_CLEAN_UP;
int save_record(object me, object ob);

int main(object me, string arg)
{
	string obj;
	object ob;

	if( !arg )
		return notify_fail("oldplayer <某人>。\n");
                
	sscanf(arg, "%s", obj);

	ob = find_player(obj);
	if( !userp(ob) || wizardp(ob) ) return notify_fail("不用这么小题大作吧？\n");
		
	message_vision(HIR "\n$N祭起一道"BLU"鬼火"HIR"，将$n笼罩在其中，把$p又送入轮回！！\n\n"NOR,me,ob);  
	tell_object(ob, HIW"你感到神情恍忽，宛若又遍历六道之界，重又想起过去种种！\n"NOR);
	log_file("static/oldplayer",sprintf("%s(%s) modify %s(%s) to oldplayered times at %s。\n", me->name(1),
		me->query("id"), ob->name(1), ob->query("id"), ctime(time()) ) );
	
	ob->delete("life/live_forever");
	ob->delete("life/live_forever_announced");
	ob->delete("life/no_death_decrease");
	ob->set("race","赛亚人");

	ob->save();
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : oldplayer <某人>

此命令将可改变玩家为受限用户，谨用！

HELP
    );
    return 1;
}
