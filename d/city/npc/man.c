#include <ansi.h>
inherit NPC;
int ask_me();
//int ask_gift();
int ask_bing();
int test_player (object me);
int ask_qiu();

void create()
{
	set_name("������ʿ", ({ "noname", "man" }));
	set("title",HIW"һ����ʦ"NOR);
	set("long", 
		"������������ʿ��û����֪������������\n"
		"����������û�ù��±�������������±�(�±�).\n"
	);
	set("age", 57);
	set("class", "swordsman");
	set("attitude", "friendly");
	set("race", "����");
	set("shen_type", 1);
	set("str", 70);
	set("int", 40);
	set("con", 40);
	set("spi", 40);
	set("cor", 43);
	set("no_kill",1);
	set("faith", 10000);
	set("score", 40000);

//	set("max_kee", 50000);
//	set("max_gin", 10000);
//	set("max_sen", 50000);
	set("force", 12000);
	set("max_force", 6000);
	set("force_factor", 300);
	set("mana", 12000);
	set("max_mana", 6000);
	set("mana_factor", 300);
	set("combat_exp", 6400000);
	set("daoxing", 6400000);

	set_skill("literate", 320);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("unarmed", 340);
	set_skill("hunyuan-zhang", 340); 
	set_skill("sword", 350);
	set_skill("yujianshu", 350);
	set_skill("spells", 350);
	set_skill("taoism", 350);
	set_skill("zixia-shengong", 350);
	set_skill("force", 350);
	set_skill("seven-steps", 350);
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("spells","taoism");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	map_skill("unarmed","hunyuan-zhang");

	set("shushan/duanshui_perform", 1);
	set("shushan/wanjian_perform", 1);
	create_family("��ɽ����", 1, "����");

	set("inquiry", ([
		"mengzhu": (: ask_me :),
		"����": (: ask_me :),
		"�±�":(: ask_bing :),
		"��������": (: test_player :),
		"kaibang": (: test_player :),
	]) );
	set("chat_msg", ({
		(: random_move :)
	}));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
		  (: perform_action, "sword", "fumo" :),
		  (: perform_action, "sword", "wanjian" :),
  		  (: perform_action, "sword", "duanshui" :),
		  (: perform_action, "sword", "tianjian" :),

	 }) );
	setup();

	carry_object("/obj/cloth")->wear();
	carry_object("/d/obj/weapon/sword/mujian")->wield();
}

void init()
{
	add_action("do_yao","yaoche");
	if ( !wizardp(this_player()) && this_player()->query("guild") != "fight" ) 
		add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "hit", "ji", 
		"fight", "steal", "cast", "apply", "kill", "study", "practice", 
		"exercise", "halt", "quit"}));
	else {
		add_action("do_fight", "fight");
		add_action("do_steal", "steal");
		add_action("do_cast", "cast");
		add_action("do_ji", "ji");
		add_action("do_apply", "apply");
	}
}

int do_yao()
{
	object me;
	me = this_player();
	if(!me->query("zhanyi/mengzhu"))
		return notify_fail("��û�г�����Ȩ�ޡ�\n");
	if (me->query_temp("che"))
		return notify_fail("���Ѿ�Ҫ�����ˡ�\n");
	me->set_temp("che",1);
	message_vision("$N������һ�����Ҵ�ææ����ȥ�ˡ�\n",me);
	me->move("/d/biwu/b14");
	message_vision("$NͻȻ������������ǰ��\n",me);
	return 1;
}

int ask_me()
{
	object who, me;
	who = this_player();
	me = this_object();
	if((this_player()->query("combat_exp")+this_player()->query("daoxing")/2)<2500000)
		tell_object(this_player(),"������ʿ˵�����㾭��̫�ͣ���Ҫ���������������ɣ�\n");
	else {
		command ("chat ��λ"+RANK_D->query_respect(who)+"�����ˣ�\n");
		command ("chat "+who->query("name")+"���������������ۣ�\n");
		tell_object(this_player(),"������ʿ˵���� �ðɣ�����Σ�����أ�ǧ�������������������Σ�ա��Լ�С�İɣ�\n");
		this_player()->move("/d/biwu/hole");
	}
	return 1;
}

int ask_bing()
{
	object me,bing;
	mapping skl;
    string *sname;
    int i,how=0;//,what_day=100;
	me = this_player();

	if (((int)me->query("combat_exp")+(int)me->query("daoxing")/2) <10000 || (int)me->query("mud_age")<18000)
	{
		command("say �ٺ٣������������ƭ�ң�û�ţ���");
		return 1;
	}
      
	if ((int)me->query("combat_exp") >=3000 ) 
	{
		skl = me->query_skills();
		if(skl) sname  = keys(skl);
		for(i=0; i<sizeof(skl); i++)
			if (skl[sname[i]] >= 10)how=how+1; 
			if(how<3)
			{
				command("say �����ˮƽ����ȥ��һ�������");
				return 1;
			}
	} 
	if(!me->query("marks/nabing"))
	{
		message_vision("������ʿ�����ðɣ��͵�����$N�����������ɡ�������ʿ����$Nһֻ������±���\n",me);
		bing = new("/d/city/obj/yuebing");
		bing->move(me);
		me->set("marks/nabing",1);
	}
	else tell_object(me,"���Ѿ��ù�һ���±��ˣ������ã�\n");
	return 1;
}

void inform_player (string msg, object who)
{
	object me = this_object();

	message_vision (msg, me, who);
}

int test_player (object me)
{
	object who = this_player();
	string msg = "$N˵������λ"+RANK_D->query_respect(who);

	if ( who->query("guild/master") )
	{
		inform_player ("������ʿ˵�����Ϸ�ʰ��·磬�����ˣ������ˡ�\n", who);
		return 1;
	}
	if ( who->query("combat_exp")<5000000 
	|| who->query("daoxing")<5000000 )
	{
		inform_player ( msg+"���в������Ϸ���һ��С��������Ĺ�ͷ��\n",who);
		return 1;
	}	

	if( who->query("score") < 50000 )
	{
		inform_player ("������ʿ˵�����㻹�����������������⡣\n",who);
		return 1;
	}
/*	if( !who->query_temp("guild") )
	{
		inform_player("��λ"+RANK_D->query_respect(who)+"�����ҵĶ��֣���Ҫ��������������\n", who);
		return 1;
	}*/
	if( who->query_temp("guild") == "fight" )
	{
		inform_player ("��λ"+RANK_D->query_respect(who)+"�����ˣ��ã��ã������Ǿ��ٱ�һ����\n", who);
		return 1;
	}

	command ("chat* "+ "������ʿ˫�ֱ�ȭ����"+who->query("name")+"���˸�Ҿ������λ"+RANK_D->query_respect(who) +"���ˣ�\n");
	command ("chat "+ who->query("name")+"�����������Ͻ�������Ż���\n");
	tell_object(who, "������ʿ˵�����ðɣ���ɡ�\n" );

	call_out ("fight_player",3,who);
	return 1;
}

void fight_player (object who)
{
//	object me = this_object();

	who->set("guild","fight");
	tell_object( who , HIR"������ʿ˵�����ã���Ҫ�����ˡ�\n"NOR);
	command("fight "+who->query("id"));
} 

int accept_fight(object who)
{
	object me;
	me = this_object();

	if ( who->is_fighting() )
		return notify_fail("������ʿ˵����û���Ϸ���æ����ô��\n");

	if ( (int)who->query("kee")*100/(int)who->query("max_kee") < 30 )
		return notify_fail("������ʿ˵�����Ϸ��左�������Ȳ��ã��Ȳ��á�\n");

	remove_call_out("check_fight");
	call_out("check_fight", 1, me, who);
	return 1;
}

void noname_disappear (object me)
{
	if( me->is_fighting() )
		me->remove_all_killer();
}

void player_win (object me, object who)
{
//	string msg;

	message_vision ("$N��ʧɫ�����书�����书��\n",me);
	command("chat "+ who->query("name")+"�Ӵ����������Ͻ�������Ż���\n");
	who->delete("guild");
	who->set("guild/master", 1);
	who->set("master/guild", WHT"һ����ʦ"NOR);
	who->delete("family");
	who->delete("class");
	who->delete("family_wp");
	who->delete("betray");
	who->set("title", HIR"��"NOR CYN"��ң�ɿ�"HIR"��"NOR);
	who->set("attitude", "kaibang");
	who->save();
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee", me->query("max_kee"));
	me->set("eff_gin", me->query("max_gin"));
	me->set("gin", me->query("max_gin"));
	me->set("eff_sen", me->query("max_sen"));
	me->set("sen", me->query("max_sen"));
//	call_out ("noname_disappear",2,me);
	noname_disappear(me);
}

void player_lose (object me, object who)
{
	message_vision ("$Nһ㶣���æ��ס$n������˵����ʧ��ʧ��\n",me,who);
//	call_out ("noname_disappear",2,me);
	noname_disappear( me );
}

void check_fight (object me, object who)
{
	int my_kee, whos_kee;
	int my_max_kee, whos_max_kee;

	my_kee = me->query("kee");
	whos_kee = who->query("kee");
	my_max_kee = me->query("max_kee");
	whos_max_kee = who->query("max_kee");

	if (!present(who, environment(me)))
		return;

	if ((my_kee*100/my_max_kee) <= 50) {
		remove_call_out("check_fight");
		player_win (me, who);
		return;
	}
	else if ((whos_kee*100/whos_max_kee) <= 50) {
		remove_call_out("check_fight");
		player_lose (me, who);
		return;
	}

	if (me->is_fighting())
	{
		remove_call_out("check_fight");
		call_out("check_fight", 1, me, who);
		return;
	}
}

int do_fight(string arg)
{
	object who = this_player();
	object me = this_object();

	if (me->is_fighting())
	{
		message_vision ("$N��$nҡҡͷ��һ��һ����������Ҫһӵ���ϣ�\n",me,who);
		return 1;
	}
	
	if (who->query("guild") == "fight")
	{
		me->set("kee", me->query("max_kee"));
		me->set("eff_kee", me->query("max_kee"));
		return 0; // can fight
	}

	message_vision ("$N��$nҡҡͷ�����򣬲���\n",me,who);
	return 1;
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();

	if(arg && present(arg,environment(me))!=me) return 0;
	message_vision ("$N������������������˼������\n",who);
	call_out("no_cast",2,who,me);
	return 1;
}

void no_cast(object who, object me)
{
	message_vision ("ʮ�ֽ�ͷ����һƬ���ҵĻ�����$N����$nЦ��һЦ��\n",me,who);
}

int do_ji(string arg)
{
	object who = this_player();
	object me = this_object();

	if(arg && present(arg,environment(me))!=me) return 0;
	message_vision ("$N������������������˼������\n",who);
	call_out("no_ji",2,who,me);
	return 1;
}

void no_ji(object who, object me)
{
	message_vision ("ʮ�ֽ�ͷ����һƬ���ҵĻ�����$N����$nЦ��һЦ��\n",me,who);
}

int do_apply(string arg)
{
	object who = this_player();
	object me = this_object();

	if(arg && present(arg,environment(me))!=me) return 0;
	message_vision ("$N������������������˼������\n",who);
	call_out("no_apply",2,who,me);
	return 1;
}

void no_apply(object who, object me)
{
	message_vision ("ʮ�ֽ�ͷ����һƬ���ҵĻ�����$N����$nЦ��һЦ��\n",me,who);
}

int do_steal(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision ("$N���Ż�������֡���һ��С������������ʿ�Ľ����ϡ�\n",who);
	call_out("no_steal",2,who,me);
	return 1;
}

void no_steal(object who, object me)
{
	message_vision ("$N����ס���ӣ���$n˵���������԰����ɡ�\n",me,who);
}

int do_action(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision ("$N��$n˵�����������治�ص���ʲô��������\n",me, who);
	call_out("no_action",2,who,me);
	return 1;
}

void no_action(object who, object me)
{
	message_vision ("$N��$nҡ��ҡͷ��\n",me,who);
}

void princess_disappear (object me)
{
	message_vision ("$N̾�˿�����˵������һ�ܺ�����Ҳ��\n",me);
	destruct (me);
}
