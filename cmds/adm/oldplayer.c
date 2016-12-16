// snowman.

#include <ansi.h>
inherit F_CLEAN_UP;
int save_record(object me, object ob);

int main(object me, string arg)
{
	string obj;
	object ob;

	if( !arg )
		return notify_fail("oldplayer <ĳ��>��\n");
                
	sscanf(arg, "%s", obj);

	ob = find_player(obj);
	if( !userp(ob) || wizardp(ob) ) return notify_fail("������ôС������ɣ�\n");
		
	message_vision(HIR "\n$N����һ��"BLU"���"HIR"����$n���������У���$p�������ֻأ���\n\n"NOR,me,ob);  
	tell_object(ob, HIW"��е�����к��������ֱ�������֮�磬���������ȥ���֣�\n"NOR);
	log_file("static/oldplayer",sprintf("%s(%s) modify %s(%s) to oldplayered times at %s��\n", me->name(1),
		me->query("id"), ob->name(1), ob->query("id"), ctime(time()) ) );
	
	ob->delete("life/live_forever");
	ob->delete("life/live_forever_announced");
	ob->delete("life/no_death_decrease");
	ob->set("race","������");

	ob->save();
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : oldplayer <ĳ��>

������ɸı����Ϊ�����û������ã�

HELP
    );
    return 1;
}
