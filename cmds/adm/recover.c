// snowman.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i ,lvl=1, j = 1;
        mapping skills;
        string *sk, obj;
        object ob;
          
        if( !arg )
                return notify_fail("recover <ĳ��> [����]��\n");
                
        if( sscanf(arg, "%s %d", obj, i)==2 ) j = i;
        else obj = arg;

        ob = find_player(obj);
        if( !ob )  ob = find_living(obj);
	if( !ob )  ob = present(obj, environment(me));
        if( !ob ) return notify_fail("�Ҳ���������\n");
        
        if( !userp(ob) ) return notify_fail("�Է�ֻ�Ǹ�NPC��������ôС������ɣ�\n");
        if( (wiz_level(me) < wiz_level("(wizard)")) && me!=ob )
		return notify_fail("��û�лָ�" + ob->name() + "������ʧ��Ȩ����\n");
		
        message_vision(HIR "\n$N����һ��"BLU"���"HIR"����$n���������У���$p�������ֻأ���\n\n"NOR,me,ob);  
        tell_object(ob, HIW"��е�����к��������ֱ�������֮�磬�ָ��˲�����ʧ��\n"NOR);
        if( ob!=me && !wizardp(ob)) 
            log_file("static/RECOVER",
		sprintf("%s(%s) recovered %s(%s) %d times at %s��\n", me->name(1),
			me->query("id"), ob->name(1), ob->query("id"), j, ctime(time()) ) );
        while(j--){
            skills = ob->query_skills();
            if (mapp(skills)) {
                    sk = keys(skills);
                    for (i=0;i<sizeof(sk);i++)
                            skills[sk[i]]+=lvl;
            }
            ob->add("combat_exp",ob->query("combat_exp")/39);
            ob->add("daoxing", ob->query("daoxing")/39);
            ob->add("potential", ob->query("potential"));
            i = ob->query("potential");
            if (i < 0) i = 0;
            ob->add("death/count", -1);
            if (i < ob->query("death_times")) ob->add("death_times", i); 
        }      
        ob->reincarnate();
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : recover <ĳ��> [����]

������ɻָ�������ʧ�����ã�

HELP
    );
    return 1;
}
