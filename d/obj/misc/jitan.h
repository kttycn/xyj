// by bluewww@YSZZ

#include <ansi.h>

#define SHILI_D "/adm/daemons/shili"

void invite_one(object me,string pos);

string get_pos()
{
	string fname=file_name(this_object());
	string* flist=explode(fname,"/");
	return flist[sizeof(flist)-2];
}

int exp_level(int exp)
{
	int i=0;
	int sum=1;

	while(sum<exp){
		sum=sum*10;
		i++;
	}
	return i;
}

int check_exp(int exp,object ob)
{
	int obexp=ob->query("combat_exp");
	int ll,tl;

	tl=exp*12/10;
	ll=exp*8/10;
	if(obexp>ll&&obexp<tl)return 1;
	return 0;
}

void init ()
{
	string pos=get_pos();
	string faname=SHILI_D->query_family(pos);
	string mname=SHILI_D->query_master(faname);

	this_object()->set("short",mname+"��̨");
	add_action("do_tiaozhan","tiaozhan");
	add_action("do_list","listshili");
}

int do_list()
{
	object me=this_player();
	string pos=get_pos();
	string faname=me->query("family/family_name");
	int shili=SHILI_D->query_shili(pos,faname);

	if( ! faname )
		return notify_fail("�㻹�ǸϿ��Ҹ���������ɣ�\n");

	write(faname+"�ڱ�����������Ϊ��"+shili+"\n");
	return 1;
}

int do_tiaozhan()
{
	object me=this_player();
	int exp=me->query("combat_exp");
	string pos=get_pos();
	string faname=SHILI_D->query_family(pos);
	object* inv;
	int i;

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");       

	if(exp<100000)
		return notify_fail("���ò��ͷ��ˣ���Ҳ�������鷳��\n");

	if(me->query("family/family_name")==faname)
		return notify_fail("�㵽���ŵĵ�ͷ�ϵ�ʲô�ң�\n");

	if(!me->query("family/family_name"))
		return notify_fail("������Ϊ˭����Ϊ˭æ��?\n");

	if(me->query_temp("in_tiaozhan"))
		return notify_fail("���Ѿ�����ս�У�\n");
	inv=all_inventory();
	for(i=0;i<sizeof(inv);i++)
		if(inv[i]->query_temp("in_tiaozhan"))
			return notify_fail("��������������ս�ˣ��㻹�ǵȵȰɡ�\n");

	me->set_temp("in_tiaozhan",1);
	write(GRN+SHILI_D->query_master(faname)+"������ͻȻ����˵����"+RANK_D->query_rude(me)+"����ţ���ȥ��һ���˺�����Ա��ԣ�\n"+NOR);
	invite_one(me,pos);        
	return 1;           
}

void invite_one(object me,string pos)
{
	object* list=users();
	object* canusers=({}), target;
	int i=sizeof(list);
	string faname=SHILI_D->query_family(pos);
	int exp=me->query("combat_exp");

	while(i--){
		if(list[i]->query("family/family_name")!=faname)
			continue;
		if( wizardp(list[i]) )
			continue;
		if (!environment(list[i]))
			continue;
		if (list[i]->is_fighting())
			continue;
		if (list[i]->is_busy())
			continue;
		if (list[i]->query_temp("no_move"))
			continue;
		if (list[i]->is_ghost())
			continue;
		if (!living(list[i]))
			continue;
		if(list[i]->query_temp("in_tiaozhan"))
			continue;       
		if(list[i]->query_temp("ask_yingzhan"))
			continue;               

		if(exp<list[i]->query("combat_exp")&&list[i]->query("combat_exp")<exp*10)
			canusers+=({list[i]});
	}
	if(sizeof(canusers)>0){
		i=random(sizeof(canusers));
		canusers[i]->set_temp("ask_yingzhan",1);
		canusers[i]->set_temp("yingzhan_place",file_name(this_object()));
		canusers[i]->set_temp("yingzhan_man",me);
		canusers[i]->set_temp("no_move",1);
		tell_object(canusers[i],"����ߴ���"+SHILI_D->query_master(faname)+"��������
������"+SHILI_D->query_chinese(pos)+"��ս���ŵ�������������30��������ȥӦս(yingzhan)��\n");
		target = canusers[i];
		call_out("check_yingzhan",30,me,canusers[i],faname);
		return;
	}
	write(GRN+SHILI_D->query_master(faname)+"������˵������������û�к��ʵ���ѡ��"+RANK_D->query_rude(me)+"���������ˡ�\n"NOR);
	me->delete_temp("in_tiaozhan");
	me->delete_temp("no_move");
	return;
}

void check_yingzhan(object me,object target,string faname)
{
	if(environment(target)!=this_object()
	&&target->query_temp("ask_yingzhan")){
		tell_object(target,GRN"����ߴ���"+SHILI_D->query_master(faname)+"��������"+RANK_D->query_rude(target)+"����Ȼ�Ա����Ų����ǣ�\n"NOR);
		write(GRN+SHILI_D->query_master(faname)+"�������˼һ�᣺��������û�к��ʵ���ѡ��"+RANK_D->query_rude(me)+"�����Ȼ�ȥ�ɡ�\n"NOR);
		me->delete_temp("in_tiaozhan");
		target->delete_temp("ask_yingzhan");
		target->delete_temp("no_move");
		target->delete_temp("yingzhan_place");
		target->add("faith",-20-random(10));
	}
}

void alternative_die (object me)
{
	object ob;
	int exp=me->query("combat_exp");
	string str;
	int i=exp_level(exp);
	string pos=get_pos();
	string ofaname,mfaname;
	string omname,mmname;

	if( !me->query_temp("ask_yingzhan") && !me->query_temp("in_tiaozhan") ) {
		me->die();
		return;
	}
	me->set("kee", 1);
	me->set("sen", 1);
	me->set("eff_kee",me->query("max_kee"));
	me->set("eff_sen",me->query("max_sen"));
	me->remove_all_killer();
	all_inventory(environment(me))->remove_killer(me);

	message_vision ("\n$N���ص�ˤ���ڵء�\n",me);
	message_vision ("���´������йٵ�����������֮�����������٣�\n",me);
	message_vision ("\n$N�����ӵ�������������\n",me);

	ob = me->query_temp("last_damage_from");
	if (! ob)
		return;  

	if(!me->query_temp("in_tiaozhan")||!ob->query_temp("in_tiaozhan"))
		return;
	ofaname=ob->query("family/family_name");
	mfaname=me->query("family/family_name");
	omname=SHILI_D->query_master(ofaname);
	mmname=SHILI_D->query_master(mfaname);

	i=(i-3)*5+2;

	me->add("faith",-i/2-random(i/2));
	me->add("score", -3);
	ob->add("faith",i*4/10+random(i/2));
	ob->add("score", 2);
	SHILI_D->increase_shili(pos,ofaname,i);
	SHILI_D->decrease_shili(pos,mfaname,i);

	tell_object(ob,GRN+"����ߴ���"+omname+"����������Ȼ�Ǻ����ģ�\n"NOR);
	tell_object(me,GRN+"����ߴ���"+mmname+"�����������д�����Ȼ���ˣ�\n"NOR);

	if(SHILI_D->query_family(pos)==ofaname){
		str=ofaname+"�ӹ��˶�"+SHILI_D->query_chinese(pos)+"�Ŀ���Ȩ��";
		this_object()->set("short",omname+"��̨");
		CHANNEL_D->do_channel(ob,"chat",str);
	}
	me->delete_temp("in_tiaozhan");
	ob->delete_temp("in_tiaozhan");
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("in_tiaozhan"))
		return notify_fail("�㻹����ս�У���ô���뿪�أ�\n");
	return ::valid_leave(me, dir);      
}    

