// modified by vikee
//【蜀山剑派】dhxy-evil 2000.7.5
//fei 修改 2001.3
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int do_report();

void create()
{
	set_name("李逍遥", ({ "li xiaoyao", "li", "xiaoyao" }));
	set("title","蜀山剑派入门弟子");
	set("long", "他长得虽身材较瘦，但却浓眉阔眼，气宇暄昂。\n");
	set("gender", "男性");
	set("age", 18);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("per", 30);
	set("kee", 2800);
	set("max_kee", 2800);
	set("sen", 1600);
	set("max_sen", 1600);
	set("force", 4800);
	set("max_force", 2400);
	set("mana", 4800);
	set("max_mana", 2400);
	set("force_factor", 60);
	set("mana_factor", 60);

	set("combat_exp", 1800000);
	set("daoxing", 2500000);

	set_skill("force", 170);
	set_skill("dodge", 180);
	set_skill("parry", 160);
	set_skill("sword", 200);
	set_skill("canxin-jian", 200);
	set_skill("zixia-shengong", 150);
	set_skill("whip", 200);
	set_skill("yiruwhip", 200);
	set_skill("seven-steps",180);
	set_skill("literate", 100);
	set_skill("taoism",150);
	set_skill("spells",150);
	map_skill("whip", "yiruwhip");
	map_skill("spells", "taoism");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "seven-steps");
	map_skill("parry", "canxin-jian");
	map_skill("sword", "canxin-jian");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword","xiangsi" :),
		(: perform_action, "sword","jinsheng" :),
	}) );

	set("inquiry", ([
		"赵灵儿" : "你能帮我去救灵儿？我可会报答你的！\n",
		"醉道士" : "好久没见师父了！\n",
		"酒剑仙" : "好久没见师父了！\n",
		"任务完成"     : (: do_report :),
		"done"     : (: do_report :),
		"救出来了"     : (: do_report :),
	]));
	setup();
	create_family("蜀山剑派", 3, "未入门弟子");
	carry_object("/obj/cloth")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

int attempt_apprentice(object me)
{
	me =this_player();
	if( (string)me->query("family/family_name")=="蜀山派" || 
	( !me->query("family") && me->query("zhanyi/zhenyaota") != "done") )
	{
		if( (int)me->query("family/generation") > 3  )
		{
			if ( (string)me->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)me->query("family/generation") ==3  )
		{
			if ( (string)me->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		command("say 你非蜀山弟子，也没去救回灵儿，我不会收你的。");
		return 0;
	}
	command("consider");
	command("say 看在你诚心诚意的份上,我收你为徒!\n");
	command("recruit " + me->query("id") );
	me->set("shushan/xiangsi_perform",1);
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "蜀山剑派仙剑奇侠");
	}
	return 0;
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "李逍遥说道：这位" + RANK_D->query_respect(ob) +
"，能不能帮我救出灵儿！她被关进镇妖塔里了！\n");
}

int do_report()
{
	int i=random(500)+1;
	object who = this_player();
	object me = this_object();
	if(who->query("nyj/shushan") == "done"){
		command("shake "+who->query("id"));
		return 1;
	}
	if(me->query("obstacle/shushan") == "done")
		return 0;
	if (objectp(present("zhao linger", environment(who))) 
	&& who->query_temp("shushan/linger_daying") ){
		who->set("zhanyi/zhenyaota","done");
		who->delete("shushan/linger_daying");
		who->add("daoxing",4000+i);
		who->add("potential",1000);
		who->add("obstacle/number",1);
		who->set("obstacle/shushan","done");
		who->add("score", 10);
		command("thank "+who->query("id"));
		command("u&me "+who->query("id"));
		command("chat "+who->query("name")+"打破镇妖塔，救出赵灵儿，打破了数百年来没人能在镇妖塔出来的记录！\n");
		message("channel:chat",HIW"【过关斩将】李逍遥(Li xiaoyao)："+who->query("name")+"闯过西行取经第三十八关！\n"NOR,users());
		tell_object (who,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行和"+chinese_number(1000)+"点潜能的奖励！\n");
		me->save();
        return 1;
	}
	command("? "+who->query("id"));
	return 1;
}
