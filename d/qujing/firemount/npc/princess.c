// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "铁扇公主"
inherit NPC;
inherit F_MASTER;

int test_player (object who);

void create()
{
	string dir;
	set_name(NAME, ({"tieshan gongzhu", "gongzhu", "princess"}));
	set("title", "火焰山红纶罗刹");
	set("gender", "女性");
	set("age", 28);
	set("per", 18);
	set("long", "火焰山铁扇公主。\n");
	set("rank_info/respect", "红纶公主");
	set("combat_exp", 400000);
	set("daoxing", 800000);

	set_skill("pingtian-dafa",90);
	set_skill("moyun-shou", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("spells", 90);
	set_skill("force", 90);
	set_skill("huomoforce", 90);
	set_skill("moshenbu", 90);
	map_skill("spells","pingtian-dafa");
	map_skill("force","huomoforce");
	map_skill("dodge", "moshenbu");
	map_skill("unarmed", "moyun-shou");

	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("force", 1500);
	set("max_force", 1500);
	set("mana", 1500);
	set("max_mana", 1500);
	set("force_factor", 40);
	set("eff_dx",80000);
	set("nkgain",140);
	create_family("翠云山芭蕉洞",2,"弟子");
	set("inquiry", ([
		"name":	 "你仔细看看我是谁！",
		"here":	 "你找土地去问！",
		"火焰山": "哼哼，只有一样法宝能镇住火焰山。",
		"法宝":	 "我很少把祖传家珍随便赠予外姓。",
		"铁扇":	 (: test_player :),
	]));

	setup();
	dir = "/d/qujing/firemount/";
	carry_object(dir+"obj/skirt")->wear();
	carry_object(dir+"obj/tieshan")->wield();
}

void init()
{
	::init();
	add_action("do_fight", "fight");
	add_action("do_kill", "kill");
	add_action("do_steal", "steal");
	add_action("do_cast", "cast");
}

void announce_success(object who)
{//disabled announce and reward...
	int i;

	if (who->query("daoxing")<4000)
	{
		tell_object (who,"你的道行不够，什么都没有得到！\n");
		return;
	}	

	if (who->query("obstacle/firemount") == "done")
	{
//		tell_object (who,"你已经过了这一关，什么都得不到了！\n");
		return;
	}	
	i = random(600);
	message_vision (HIY "一团红色云雾飘来，显现出"+NAME+"。\n" NOR,who);
	who->add("obstacle/number",1);
	who->set("obstacle/firemount","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"扑灭了火焰山八百里大火！");
	message("channel:chat",HIW"【过关斩将】铁扇公主(Tieshan gongzhu)："+who->query("name")+"闯过西行取经第二十一关！\n"NOR,users());
	tell_object (who,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行！\n");
	who->save();
	message_vision (HIY NAME+"化为红色云雾升起，向南边飘去。\n" NOR,who);
}

void return_object (object who, object ob)
{
	command ("give "+who->query("id")+" "+ob->query("id"));
}

int accept_object (object who, object ob)
{
	object me = this_object();

	if (ob->query("id") != "palm bone")
	{
		command("shake");
		call_out("return_object",1,who,ob);
		return 1;		
	}

	if (who->query("combat_exp")<4000)
	{
		message_vision ("$N对$n摇摇头：你道行不够，这芭蕉骨怕是假货。\n",me,who);
		call_out("return_object",1,who,ob);
		return 1;
	}	

	message_vision ("$N接下芭蕉骨，对$n连声道谢。\n",me,who);
	who->set("obstacle/firemount_bone",who->query("obstacle/firemount_bone")+1);
	if (who->query("obstacle/firemount_bone") > 9)
	{
		call_out("give_tieshan",1,me,who);
	}
	return 1;
}

void inform_player (string msg, object who)
{
	object me = this_object();

	message_vision (msg, me, who);
}

void give_tieshan (object me, object who)
{
	object tieshan = present("tie shan",me);
	string msg;

	if (tieshan)
	{
		message_vision ("$N苦笑一下，"+
			"很不情愿地双手捧出铁扇，交给$n。\n",me,who);
		tieshan->move(who);
		if (who->query("obstacle/firemount")!="done")
			who->set("obstacle/firemount","won");
	}
	else
		message_vision ("$N为难地说道：铁扇已经送人了，"+"公主实无他物相赠。\n",me,who);
}

int test_player (object me)
{
	object who = this_player();
	string msg = "$N说道：这位"+RANK_D->query_respect(who);

	if (who->query("combat_exp")<4000)
	{
		inform_player (msg+"道行不够，公主怕铁扇伤了你的根骨！\n",who);
		return 1;
	}	

	if (who->query("obstacle/firemount") == "won" ||
	who->query("obstacle/firemount") == "done")
	{
		give_tieshan (me,who);
		return 1;
	}	

	if (who->query("obstacle/firemount") == "fight")
		inform_player (msg+"又来啦？好，公主奉陪！\n",who);
	else		
		inform_player (msg+"想必是个爽快之人，公主最喜欢热闹！\n",who);

	call_out ("fight_player",3,who);
	return 1;
}

void fight_player (object who)
{
	object me = this_object();

	message_vision ("$N对众妖一喝：闪开！\n",me,who);
	who->set("obstacle/firemount","fight");
	command("fight "+who->query("id"));
} 

int accept_fight(object who)
{
	object me;
	me = this_object();

	remove_call_out("check_fight");
	call_out("check_fight", 1, me, who);
	return 1;
}

void player_win (object me, object who)
{
	object tieshan = present("tie shan",me);
	string msg;

	message_vision ("$N大惊失色：好武功！好武功！\n",me);
	give_tieshan (me,who);
	call_out ("princess_disappear",2,me);
}

void player_lose (object me, object who)
{
	message_vision ("$N一愣，慌忙扶住$n，连声说道：失礼失礼！\n",me,who);
	call_out ("princess_disappear",2,me);
}

void check_fight (object me, object who)
{
	int my_kee, whos_kee;
	int my_max_kee, whos_max_kee;

	my_kee = me->query("kee");
	whos_kee = who->query("kee");
	my_max_kee = me->query("max_kee");
	whos_max_kee = who->query("max_kee");

	if (me->is_fighting())
	{
		call_out ("check_fight",2,me,who);
		return;
	}

	if (!present(who, environment(me)))
		return;

	if ((my_kee*100/my_max_kee) <= 50)
		player_win (me, who);
	else if ((whos_kee*100/whos_max_kee) <= 50)
		player_lose (me, who);

}

void princess_disappear (object me)
{
	message_vision ("$N慢慢地化为红色云雾消失了。\n",me);
	destruct (me);
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
	
	if (who->query("obstacle/firemount") == "fight")
	{
		me->set("kee", me->query("max_kee"));
		me->set("eff_kee", me->query("max_kee"));
		return 0; // can fight
	}

	message_vision ("$N对$n摇摇头：要打架出去打！\n",me,who);
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
	message_vision ("小小山洞里响起一片杂乱的回音，$N看着$n一笑。\n",me,who);
}

int do_steal(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision ("$N趁着黑暗伸出手……一不小心摸到公主的长发。\n",who);
	call_out("no_steal",2,who,me);
	return 1;
}

void no_steal(object who, object me)
{
	message_vision ("$N按捺住性子，对$n说：请自尊自爱自律。\n",me,who);
}

int do_kill(string arg)
{
	object who = this_player();
	object me = this_object();

	if(arg && present(arg,environment(me))!=me) return 0;

	message_vision ("$N忽然眼露杀机，颤抖地喊了一声：杀！\n",who);
	call_out("no_kill",2,who,me);
	return 1;
}

void no_kill(object who, object me)
{
	message_vision ("刹那间山洞里众小妖纷纷上串下跳围着$N乱作一团。\n",who);
	message_vision ("只见$N冷冷地说道：静……一切都安静下来了。\n",me);
}

void attempt_apprentice(object ob)
{
	ob=this_player();

	if( (string)ob->query("family/family_name") == "火云洞") {
		if(((int)ob->query("max_mana") > 200 
		&& (int)ob->query("max_force") > 200 )
		||(string)ob->query("gender")=="女性")
		{
			command("nod");
			command("recruit " + ob->query("id"));
			return ;
		} else {
			command("angry "+ob->query("id"));
			message_vision(HIC "\n$N飞起一脚把$n踢出洞外！\n\n"NOR, this_object(), ob);
			ob->move("/d/qujing/firemount/shimen");
		}
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "yaomo_huo");
		ob->set("title", "翠云山芭蕉洞小妖");
		ob->set("kusong/Teach_princess", 1);
	}
	return 1;
}
