#include <ansi.h>
inherit NPC;
int ask_me();
//int ask_gift();
int ask_bing();
int test_player (object me);
int ask_qiu();

void create()
{
	set_name("无名居士", ({ "noname", "man" }));
	set("title",HIW"一代宗师"NOR);
	set("long", 
		"他就是无名居士，没有人知道他的来历。\n"
		"如果中秋节你没拿过月饼，你可以问他月饼(月饼).\n"
	);
	set("age", 57);
	set("class", "swordsman");
	set("attitude", "friendly");
	set("race", "天神");
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
	create_family("蜀山剑派", 1, "弟子");

	set("inquiry", ([
		"mengzhu": (: ask_me :),
		"盟主": (: ask_me :),
		"月饼":(: ask_bing :),
		"开帮立派": (: test_player :),
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
		return notify_fail("你没有乘马车的权限。\n");
	if (me->query_temp("che"))
		return notify_fail("你已经要过马车了。\n");
	me->set_temp("che",1);
	message_vision("$N乘上了一辆马车匆匆忙忙地离去了。\n",me);
	me->move("/d/biwu/b14");
	message_vision("$N突然出现在众人眼前。\n",me);
	return 1;
}

int ask_me()
{
	object who, me;
	who = this_player();
	me = this_object();
	if((this_player()->query("combat_exp")+this_player()->query("daoxing")/2)<2500000)
		tell_object(this_player(),"无名居士说道：你经验太低，想要做盟主，必死无疑！\n");
	else {
		command ("chat 这位"+RANK_D->query_respect(who)+"有请了！\n");
		command ("chat "+who->query("name")+"欲与盟主较量争雄！\n");
		tell_object(this_player(),"无名居士说道： 好吧，里面危险重重，千万别乱来，否则有生命危险。自己小心吧！\n");
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
		command("say 嘿嘿，想用新玩家来骗我，没门！。");
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
				command("say 就你的水平？再去练一会儿！。");
				return 1;
			}
	} 
	if(!me->query("marks/nabing"))
	{
		message_vision("无名居士道：好吧，就当做是$N的中秋节礼物吧。无名居士给了$N一只中秋节月饼。\n",me);
		bing = new("/d/city/obj/yuebing");
		bing->move(me);
		me->set("marks/nabing",1);
	}
	else tell_object(me,"你已经拿过一次月饼了，还想拿？\n");
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
	string msg = "$N说道：这位"+RANK_D->query_respect(who);

	if ( who->query("guild/master") )
	{
		inform_player ("无名居士说道：老夫甘拜下风，不比了，不比了。\n", who);
		return 1;
	}
	if ( who->query("combat_exp")<5000000 
	|| who->query("daoxing")<5000000 )
	{
		inform_player ( msg+"道行不够，老夫怕一不小心伤了你的骨头！\n",who);
		return 1;
	}	

	if( who->query("score") < 50000 )
	{
		inform_player ("无名居士说道：你还不配向我提出这个问题。\n",who);
		return 1;
	}
/*	if( !who->query_temp("guild") )
	{
		inform_player("这位"+RANK_D->query_respect(who)+"不是我的对手，不要枉自送了性命。\n", who);
		return 1;
	}*/
	if( who->query_temp("guild") == "fight" )
	{
		inform_player ("这位"+RANK_D->query_respect(who)+"又来了，好，好，那我们就再比一场。\n", who);
		return 1;
	}

	command ("chat* "+ "无名居士双手抱拳，对"+who->query("name")+"作了个揖道：这位"+RANK_D->query_respect(who) +"请了！\n");
	command ("chat "+ who->query("name")+"欲脱离三界管辖，自立门户！\n");
	tell_object(who, "无名居士说道：好吧，请吧。\n" );

	call_out ("fight_player",3,who);
	return 1;
}

void fight_player (object who)
{
//	object me = this_object();

	who->set("guild","fight");
	tell_object( who , HIR"无名居士说道：好，我要出招了。\n"NOR);
	command("fight "+who->query("id"));
} 

int accept_fight(object who)
{
	object me;
	me = this_object();

	if ( who->is_fighting() )
		return notify_fail("无名居士说道：没见老夫正忙着那么？\n");

	if ( (int)who->query("kee")*100/(int)who->query("max_kee") < 30 )
		return notify_fail("无名居士说道：老夫体乏无力，比不得，比不得。\n");

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

	message_vision ("$N大惊失色：好武功！好武功！\n",me);
	command("chat "+ who->query("name")+"从此脱离三界管辖，自立门户！\n");
	who->delete("guild");
	who->set("guild/master", 1);
	who->set("master/guild", WHT"一代宗师"NOR);
	who->delete("family");
	who->delete("class");
	who->delete("family_wp");
	who->delete("betray");
	who->set("title", HIR"【"NOR CYN"逍遥仙客"HIR"】"NOR);
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
	message_vision ("$N一愣，慌忙扶住$n，连声说道：失礼失礼！\n",me,who);
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
		message_vision ("$N对$n摇摇头：一个一个地来，不要一拥而上！\n",me,who);
		return 1;
	}
	
	if (who->query("guild") == "fight")
	{
		me->set("kee", me->query("max_kee"));
		me->set("eff_kee", me->query("max_kee"));
		return 0; // can fight
	}

	message_vision ("$N对$n摇摇头：不打，不打！\n",me,who);
	return 1;
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();

	if(arg && present(arg,environment(me))!=me) return 0;
	message_vision ("$N吸口气，憋红了脸念了几声咒语。\n",who);
	call_out("no_cast",2,who,me);
	return 1;
}

void no_cast(object who, object me)
{
	message_vision ("十字街头响起一片杂乱的回音，$N看着$n笑了一笑。\n",me,who);
}

int do_ji(string arg)
{
	object who = this_player();
	object me = this_object();

	if(arg && present(arg,environment(me))!=me) return 0;
	message_vision ("$N吸口气，憋红了脸念了几声咒语。\n",who);
	call_out("no_ji",2,who,me);
	return 1;
}

void no_ji(object who, object me)
{
	message_vision ("十字街头响起一片杂乱的回音，$N看着$n笑了一笑。\n",me,who);
}

int do_apply(string arg)
{
	object who = this_player();
	object me = this_object();

	if(arg && present(arg,environment(me))!=me) return 0;
	message_vision ("$N吸口气，憋红了脸念了几声咒语。\n",who);
	call_out("no_apply",2,who,me);
	return 1;
}

void no_apply(object who, object me)
{
	message_vision ("十字街头响起一片杂乱的回音，$N看着$n笑了一笑。\n",me,who);
}

int do_steal(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision ("$N趁着混乱伸出手……一不小心摸到无名居士的剑锋上。\n",who);
	call_out("no_steal",2,who,me);
	return 1;
}

void no_steal(object who, object me)
{
	message_vision ("$N按捺住性子，对$n说：请自尊自爱自律。\n",me,who);
}

int do_action(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision ("$N对$n说道：哎，你真不地道，什么都敢做。\n",me, who);
	call_out("no_action",2,who,me);
	return 1;
}

void no_action(object who, object me)
{
	message_vision ("$N对$n摇了摇头。\n",me,who);
}

void princess_disappear (object me)
{
	message_vision ("$N叹了口气，说道：求一败何其难也！\n",me);
	destruct (me);
}
