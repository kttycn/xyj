#include <ansi.h>

#define DIRNAME "/d/biwu/"
#define MAXPOSITION 1
#define DEBUG 0

int get_position_int ();
void find(string id);

string get_position_str ()
{
	return chinese_number(get_position_int ());
}

string get_honor_str ()
{
	string *honors = ({"����",});
	return honors[get_position_int()-1];
}

string get_respect_str ()
{
	return HIW "�� ��Ӱ��Ե ��"HIG"��"HIR"��"HIY"��"HIR"��"HIB"��"HIW" ����������"NOR;
}

void reset_me (object me)
{
	int i;
	object *inv;
	mapping skill_status, map_status;
	string *skillnames, *mapnames;
    
	reset_eval_cost();
	if ( mapp(map_status = me->query_skill_map()) )
	{
		mapnames = keys(map_status);
		for(i=0; i<sizeof(mapnames); i++)
		{
			me->map_skill(mapnames[i]);
		}
	}

	if ( mapp(skill_status = me->query_skills()) )
	{
		skillnames = keys(skill_status);
		for(i=0; i<sizeof(skillnames); i++)  
		{
			me->delete_skill(skillnames[i]);
		}
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		destruct (inv[i]);
	}

	me->set_name(get_honor_str(), ({ "numberone","meng zhu",  "mengzhu" }) );
	me->set("title", get_respect_str());
	me->set("gender", "����" );
	me->set("long",get_respect_str()+"��\n");
	me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
	me->set("attitude", "heroism");
	me->set("current_player","none of us");

	me->set("str", 30);
	me->set("per", 30);
	me->set("int", 30);
	me->set("age", 100);
	me->set("weapon", 0);
	me->set("armor", 0);

	me->set_skill("force",  100); 
	me->set_skill("spells", 100); 
	me->set_skill("unarmed",100);
	me->set_skill("sword",  100);
	me->set_skill("dodge",  100);
	me->set_skill("parry",  100);

	me->set("max_gin", 1000);
	me->set("eff_gin", 1000);
	me->set("gin", 1000);
	me->set("max_kee", 1000);
	me->set("eff_kee", 1000);
	me->set("kee", 1000);
	me->set("max_sen", 1000);
	me->set("eff_sen", 1000);
	me->set("sen", 1000);
	me->set("force", 2000);
	me->set("max_force", 1000);
	me->set("mana", 1000);
	me->set("max_mana", 1000);
	me->set("force_factor", 50);

	//me->set("no_clean_up",1);
	me->set("no_unconcious",1);
	me->set("combat_exp", 500000);

	me->delete_temp("apply");
	me->setup();
	reset_eval_cost();

}

int save_record(object me, object ob)
{
	object *inv;
	mapping hp_status, skill_status, map_status;
	string *skillnames, *mapnames;
	int i, weapon_cnt, armor_cnt;

	reset_eval_cost();
	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]);
	me->set("per", hp_status["per"]);
	me->set("int", hp_status["int"]);
	me->set("age", hp_status["age"]);
	me->set("id", hp_status["id"]);

	me->set("max_gin",     hp_status["max_gin"]);
	me->set("eff_gin",     hp_status["eff_gin"]);
	me->set("gin",         hp_status["gin"]);
	me->set("max_kee",     hp_status["max_kee"]);
	me->set("eff_kee",     hp_status["eff_kee"]);
	me->set("kee",         hp_status["kee"]);
	me->set("max_sen",     hp_status["max_sen"]);
	me->set("eff_sen",     hp_status["eff_sen"]);
	me->set("sen",         hp_status["sen"]);
	me->set("max_force",   hp_status["max_force"]);
	me->set("force",       hp_status["force"]);
	me->set("max_mana",    hp_status["max_mana"]);
	me->set("mana",        hp_status["mana"]);
	me->set("gender",      hp_status["gender"]);
	me->set("combat_exp",  hp_status["combat_exp"]);
	me->set("daoxing",  hp_status["daoxing"]);

	me->set("eff_gin", me->query("max_gin"));
	me->set("gin",     me->query("max_gin"));
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("eff_sen", me->query("max_sen"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",   me->query("max_force")*2);
	me->set("mana",    me->query("max_mana")*2);

	skill_status = me->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames  = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++) {
			me->delete_skill(skillnames[i]);
		}
	}

	skill_status = ob->query_skills();
	if ( mapp(skill_status) )
	{
		skillnames  = keys(skill_status);

		for(i=0; i<sizeof(skillnames); i++) {
			me->set_skill(skillnames[i], skill_status[skillnames[i]]);
		}
	}
  
  // increase npc's enforce, as players have more options, e.g.
  // powerup, etc.
	me->set("force_factor",ob->query_skill("force")*5/8);

	reset_eval_cost();
	if (! me->query("new_player"))
	{
		me->save();
		reset_eval_cost();
		return 1;
	}

	me->set("new_player",0);

	if ( mapp(map_status = me->query_skill_map()) ) {
		mapnames = keys(map_status);

		for(i=0; i<sizeof(mapnames); i++) {
			me->map_skill(mapnames[i]);
		}
	}

	map_status = ob->query_skill_map();
	if ( mapp(map_status) ) 
	{
		mapnames  = keys(map_status);

		for(i=0; i<sizeof(mapnames); i++) {
			me->map_skill(mapnames[i], map_status[mapnames[i]]);
		}
	}
	
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}

	me->delete_temp("apply");
	me->setup();
	me->save();

	weapon_cnt = 0;
	armor_cnt = 0;
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if ( !inv[i]->query_unique() && inv[i]->query("skill_type") &&
				inv[i]->query("equipped") && !weapon_cnt ) {
			object obj = new(base_name(inv[i]));
			if (obj)
			{
				if(obj->move(me)) // mon 8/13/97
				obj->wield();
			}
			me->set("weapon", base_name(inv[i]));
		 weapon_cnt = 1;
		}
		else if ( !inv[i]->query_unique() && !inv[i]->query("skill_type") && 
				inv[i]->query("equipped") && !armor_cnt ) {
			object obj = new(base_name(inv[i]));
			if (obj)
			{
				if(obj->move(me))
				obj->wear();   //mon 8/13/97
			}
			me->set("armor", base_name(inv[i]));
		 armor_cnt = 1;
		}
	 else if( weapon_cnt && armor_cnt )
			break;
	}

	me->setup();
	me->save();
	reset_eval_cost();

	return 1;
}

int convert_identity (object me, object ob)
{
	reset_eval_cost();
	me->reset_me(me);
	if (ob->query("id") == "meng zhu")
	{
		string current_player = ob->query("current_player");
		me->set("current_player",current_player);
		if (! current_player ||	current_player == "none of us")
		{
			me->save();
			return 1;
		}
		else
		{
			me->set("name", ob->query("name") );
			me->set("gender", ob->query("gender") );
			me->set("short",me->get_honor_str()+" "+
			me->query("name")+"("+capitalize(me->query("id"))+")");
		}
	}
	else
	{
		me->set("name", ob->query("name") );
		me->set("gender", ob->query("gender") );
		me->set("current_player",ob->query("id"));
		me->set("short",me->get_honor_str()+" "+
		me->query("name")+"("+capitalize(me->query("id"))+")");
		ob->set_temp("apply/short", ({ob->query("title")+me->get_respect_str()+
                 " "+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
	}

	save_record(me, ob);

	return 1;
}

int do_save()
{
//  write("���浵��...\n");
	return this_object()->save();
}

object find_and_restore (string name)
{
	object me = find_object(name);

	if (! me || ! me->restore())
		me = new (name);
	me->setup();
	return me;
}

object find_in_room ()
{
	string name = DIRNAME+"b12";
	object room;

	call_other(name, "???");
	room = find_object(name);
	if (room)
		return present ("meng zhu",room);
	else
	{
		name = DIRNAME+"npc/champion";
		return find_and_restore (name);
	}
}

int check_player_position (object who)
{
	int i;

	for (i = 1; i < get_position_int(); i++)
	{
		object ob = find_in_room();
		reset_eval_cost();
		if (ob->query("current_player") == who->query("id"))
			return 0;
	}
	return 1;
}

int remove_previous_position (object who, int position)
{
	object ob = find_in_room();
	reset_eval_cost();
	if (ob && ob->query("current_player") == who->query("id"))
	{
		ob->reset_me(ob);
		ob->save();
		ob->restore();
		return 1;
	}
	return 1;
}

int push_other_positions (object me, int position, int previous_position)
{
	int i;
	string src, dst;
	object who;
	object ob;

	for (i = previous_position-1; i >= position; i--)
	{
		reset_eval_cost();
		who = find_in_room();
		ob = find_in_room();
		ob->set("new_player",1);
		convert_identity(ob,who);
	}
	return 1;
}

int fully_recover (object me)
{
	object *inv, ob, current_player;
	string player_name;
	reset_eval_cost();
	me->set("eff_gin", me->query("max_gin"));
	me->set("gin",     me->query("max_gin"));
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("eff_sen", me->query("max_sen"));
	me->set("sen",     me->query("max_sen"));
	me->set("force",   me->query("max_force")*2);
	me->set("mana",    me->query("max_mana")*2);
	player_name = me->query("current_player");
	if (! player_name || player_name == "none of us")
		return 1;
  
	if (current_player = find_player(player_name))
	{
		save_record (me, current_player);
	}
	else if (current_player = LOGIN_D->find_body(player_name))
		{
			save_record (me, current_player);
		}
		else
		{
			seteuid(player_name);
			current_player = new(USER_OB);
			current_player->set("id", player_name);
			if (!current_player->restore()){
				destruct(current_player);
				return 1;
			}
			export_uid(current_player);
			seteuid(getuid());
			current_player->setup();
			if (current_player->query("combat_exp")>me->query("combat_exp"))
				save_record (me, current_player);
			destruct (current_player);
	}
	inv = all_inventory(me);
	while (inv && sizeof(inv))
	{
		destruct (inv[0]);
		inv = all_inventory(me);
	}
	if (me->query("weapon"))
	{
		ob = new(me->query("weapon"));
		if(ob && ob->move(me))
		ob->wield();   //mon 8/13/97
	}
	if (me->query("armor"))
	{
		ob = new(me->query("armor"));
		if(ob && ob->move(me))
		ob->wear();   //mon 8/13/97
	}
	reset_eval_cost();
	return 1;
}

int fully_recover_me ()
{
	return fully_recover (this_object());
}

int accept_fight(object ob)
{
	int i;
	object* inv;
	object me = this_object();
	object who = this_player();
	if (me->query("current_player") == ob->query("id")) 
	{
		command ("say �������������Լ�������\n");
		return notify_fail("���Ѿ������������ˡ�\n");
	}
	if (me->is_fighting())
	{
		command ("say ���Ժ�\n");
		return notify_fail("��������æ�ţ��޷��˼��㡣\n");
	}
	if (! interactive(ob))
	{
		command ("say ����\n");
		return notify_fail("You are a NPC.\n");
	}
	fully_recover (me);
	inv = all_inventory(who);
	for(i=0; i<sizeof(inv); i++){
		if( inv[i]->query_unique() ) {
			message_vision("ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n",me,inv[i]);
			destruct(inv[i]);
		}
	}
	remove_call_out("check_result");
	call_out("check_result", 1, me, ob);
	return 1;
}

int check_result(object me, object ob)
{
	int my_max_kee, his_max_kee;
	my_max_kee  = me->query("max_kee");
	his_max_kee = ob->query("max_kee");
	if (me->is_fighting())
	{
		call_out("check_result",1, me, ob);
		return 1;
	}
	if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 ) {
		int previous_position;
		string id;
		object zhang;
		message_vision ("$N�����°ݣ����������\n",me);
       	id = me->query("id");
		previous_position = remove_previous_position (ob,get_position_int());
		push_other_positions (me,get_position_int(),previous_position);
		me->set("new_player",1);
		zhang = new("/d/biwu/obj/zhang");
		find(id);
		zhang->move(ob);
		command ("chat �����ڿ�ʼ"+ob->query("name")+"�������ǵ��������ˣ�");
		message_vision("��������$Nһ�����ȡ�\n",ob);
		if( !ob->query("master/rank") )
			ob->add("score", 200);
		else
			ob->add("score", 5);
		ob->set("master/rank",HIG"��"HIR"��"HIY"��"HIR"��"HIB"��"HIW" ����������"NOR);
		ob->set("zhanyi/mengzhu",1);
		convert_identity (me, ob);
		call_out("log_positions",1);
		return 1;
	}
	if (( (int)ob->query("kee")*100/his_max_kee)<=50) {
		message_vision ("$N��$n����\n",me,ob); }
	return 1;  
}

string query_save_file()
{
	return DATA_DIR+"champion";
}

int do_bandage(string arg)
{
	object who = this_player();
	object me = present("meng zhu",environment(who));
	if (! arg || me != present(arg, environment(me))) return 0;
	message_vision ("$N�������ڵ�Ҫ��$n�����˿ڡ�\n",who,me);
	call_out("no_bandage",2,who,me);
	return 1;
}

void no_bandage(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_ji(string arg)
{
	object who = this_player();
	object me = this_object();
	message_vision ("$N�������������ʲô������\n",who);
	call_out("no_ji",2,who,me);
	return 1;
}

void no_ji(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();
	if (arg == "transfer")
	return 0;
	message_vision ("$N�ſ��죬���ɰɵ����˼������\n",who);
	call_out("no_cast",2,who,me);
	return 1;
}

void no_cast(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_exert(string arg)
{
	object who = this_player();
	object me = this_object();
	if (arg != "sheqi meng zhu" &&
	arg != "sheqi mengzhu" &&
	arg != "sheqi numberone")
		return 0;
	message_vision ("$N��������һ������\n",who);
	call_out("no_exert",2,who,me);
	return 1;
}

void no_exert(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_perform(string arg)
{
	object who = this_player();
	object me = this_object();
	message_vision ("$N��������һʩ�⹦��\n",who);
	call_out("no_perform",2,who,me);
	return 1;
}

void no_perform(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_steal(string arg)
{
	object who = this_player();
	object me = this_object();
	message_vision ("$N����֣�����������͵ʲô������\n",who);
	call_out("no_steal",2,who,me);
	return 1;
}

void no_steal(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_bian(string arg)
{
	object who = this_player();
	object me = this_object();
	message_vision ("$N������������ʲô������\n",who);
	call_out("no_bian",2,who,me);
	return 1;
}

void no_bian(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

int do_kill(string arg)
{
	object who = this_player();
	object me = this_object();
	if(!arg || present(arg,environment(me))!=me) return 0;
	message_vision ("$N��¶�׹⣬�����Ӷ���ɱ����\n",who);
	call_out("no_kill",2,who,me);
	return 1;
}

void no_kill(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

void die()
{
//  fully_recover (this_object());
}

void unconcious()
{
  //fully_recover (this_object());
}

void find(string id)
{
	object *ulist,*ilist;
	object ob;
	int i,j;
	ulist  =  users();
	i  =  sizeof(ulist);
	while (i--) {
	//if(ulist[i]->query("id")== id ) {
		if  (present  ("shenstaff",ulist[i]))
		{
			ilist  =  all_inventory(ulist[i]);
			j=sizeof(ilist);
			while (j--) {
				ob = ilist[j];
				if(ob->query("id")=="shenstaff")
				{
					destruct(ob);
				}
			}
			message_vision(HIY"$N���ϵ����Ȼ���һ����â������Զ����\n"NOR,ulist[i]);
			ulist[i]->add("score",-300);
			ulist[i]->delete("master/rank");
			ulist[i]->delete("zhanyi");
		}
	}
}
