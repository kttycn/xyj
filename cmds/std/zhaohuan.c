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
		return notify_fail("Ҫ����ԯ���ʲ����ٻ���ԯ��ͯ��\n");
	
   //last 0 means do not show position.

	if( (int)me-> query_temp("number") > 1 )
		return notify_fail("��ֻ���ٻ�һλ��ԯ��ͯ��\n");
	if (me->query("sen")<100) 
		return notify_fail("�㾫�񲻹���\n");

	me->save();
	me->add_temp("number", 1);

	message_vision("ֻ��$N���һ������ԯ��ͯ���ڣ�\n", me);
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
ָ���ʽ: zhaohuan 
 
��Ϊ��ԯ�������˿������ٻ�һλ��ԯͯ���������Լ���
����whisper����ԯͯ����������磬�����ԯͯ�ӽ�
aaa-zuo����whisper aaa-zuo kill xiao er����������
ɱ��С����

ע���л�ʱ��˳����ԯ�������֡�

HELP
    );
   return 1;
}
 
