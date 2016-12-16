//xyjianqiao.c
//stone create
//20020220
int main(object me, string arg)
{
	string JIANTONG_FILE = "/d/update/stone/npc/jiantong.c";
	object jiantong;
	int i;

	object *enemy;
	seteuid(getuid());
        
//	if(!present("mostaff",me) && !present("shenstaff",me))
	if(!present("xianyuan jianqiao",me))
		return notify_fail("要有轩辕剑鞘才能召唤轩辕剑童。\n");
	
   //last 0 means do not show position.

	if( (int)me-> query_temp("number") > 1 )
		return notify_fail("你只能召唤一位轩辕剑童。\n");
	if (me->query("sen")<100) 
		return notify_fail("你精神不够。\n");

	me->save();
	me->add_temp("number", 1);

	message_vision("只听$N大喝一声：轩辕剑童何在！\n", me);
	jiantong = new(JIANTONG_FILE);
	jiantong->move(environment(me));
	jiantong->set("combat_exp",me->query("combat_exp")/2);
	jiantong->set("possessed", me);
	jiantong->show(me);
	me->add("sen",-100); 
	if(me->is_fighting()) {
	enemy = me->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			jiantong->kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(jiantong);
			else enemy[i]->kill_ob(jiantong);
		}
	}
me->remove_all_killer();
	}
      return 1;
}
 


int help(object me)
{
    write(@HELP
指令格式: zhaohuan 
 
身为轩辕剑的主人可以用召唤一位轩辕童子来保护自己。
可用whisper对轩辕童子下命令。例如，如果轩辕童子叫
aaa-zuo，用whisper aaa-zuo kill xiao er即可命令他
杀店小二。

注：招唤时必顺有轩辕剑鞘在手。

HELP
    );
   return 1;
}
 
