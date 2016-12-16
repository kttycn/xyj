#include "ansi.h"
void get_reward(object who)
{
	int exp,pot;    
	pot=40+random(20);
	exp=90+random(30);   
	tell_object(who,"𫲻��˵������ϲ�㣡���������һ������\n");
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("faith",1);
	tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս���飻"+chinese_number(pot) + "��Ǳ��\n" NOR);
	who->delete("lingtai_quest");
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;
	t /= 60;
	m = t % 60;
	t /= 60;
	h = t % 24;
	t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	tell_object(me,HIC + sprintf("%s",this_object()->name()) +"˵��������" + time + "��\n");
	return 1;
}

int give_quest()
{
	object me=this_player(),obj;
	int exp=me->query("combat_exp");
	mapping quest;
	int timep;

	if( me->query("combat_exp") > 100000)
		return notify_fail("�㻹���ҵ��Ļ�ɰɡ�\n");

	if(me->query("family/family_name")!="����ɽ���Ƕ�")
		return notify_fail("����������������֪�кι�ɣ�\n");
	if(me->query("faith")>100)return notify_fail("������������!\n");
	if(exp>1000000){
		tell_object(me,"𫲻��˵������ľ����Ѿ��㹻�ߣ���ȥ��һ�������ˣ�\n"); 
		return 1;
	} 

	if((int) me->query("task_time") - time()>0)
	if(!me->query("lingtai_quest")){
	}
	else {
		tell_object(me,"𫲻��˵�����㲻�ǻ�������ô��\n");
		return 1;
	}
	else if(me->query("lingtai_quest")){
		tell_object(me,"𫲻��˵�����Ұ��������ˣ��ٸ���һ�λ��ᡣ\n");
		me->set("kee", me->query("kee")/2+1);
		me->delete_temp("lingtai_quest_number");
	}  
  
	quest="/d/lingtai/npc/quest_new"->query_quest();

	if((int)me->query_temp("lingtai_quest_number")<40)
		me->add_temp("lingtai_quest_number",1);
      
	timep=400+random(200);
	time_period(timep, me);      
	me->set("task_time", (int) time()+(int) timep);

	if(quest["quest_type"]=="sweep"){
		me->set("lingtai_quest/quest_type","��ɨ");
		me->set("lingtai_quest/quest",quest["location"]);
		if(!(obj=present("broom",me))){
			obj=new("/d/lingtai/obj/shaoba.c");
			obj->move(me);
		}
		tell_object(me,"𫲻��˵�������Ҵ�ɨ"+quest["location"]+"������ɨ�㡣\n");
		return 1;
	}
	if(quest["quest_type"]=="dig"){
		me->set("lingtai_quest/quest_type","�ֵ�");
		me->set("lingtai_quest/quest","");
		if(!(obj=present("hoe",me))){
			obj=new("/d/lingtai/obj/chutou.c");
			obj->move(me);
		}
		tell_object(me,"𫲻��˵����ȥ���ֵ�С���ֵأ����ǳ�ͷ��\n");
		return 1;
	}
	if(quest["quest_type"]=="carry"){
		me->set("lingtai_quest/quest_type","��ˮ");
		me->set("lingtai_quest/quest","");
		if(!(obj=present("shuitong",me))){
			obj=new("/d/lingtai/obj/shuitong.c");
			obj->move(me);
		}
		tell_object(me,"𫲻��˵����ȥ�������ˮ������ˮͰ��\n");
		return 1;
	}
	if(quest["quest_type"]=="volunteer"){
		me->set("lingtai_quest/quest_type","����ɽ��");
		tell_object(me,"𫲻��˵�����泿�¿���ɽ�š�\n");
		return 1;
	}
	if(quest["quest_type"]=="write"){
		me->set("lingtai_quest/quest_type","����");
		tell_object(me,"𫲻��˵��������������Ҫ�˰�æ�����������ȥ�ɡ�\n");
		return 1;
	}
}

int report_msg()
{
	object me=this_player();

	if(me->query("class")!="taoist"){
		command("shake");
		return 1;
	}
	if(!me->query("lingtai_quest"))
		return notify_fail(this_object()->query("name")+"˵��������Ѱ�ҿ�����\n");
	if(!me->query("lingtai_quest/done"))
		return notify_fail(this_object()->query("name")+"˵��������Ѱ�ҿ�����\n");
	if ((int) me->query("task_time") < time() )
	{
		tell_object(me,"𫲻��˵�������ϧ����û����ָ����ʱ������ɣ�\n");
		me->delete_temp("lingtai_quest_number");
		me->delete("lingtai_quest");
		return 1;
	}
	get_reward(me);
	return 1;
}
