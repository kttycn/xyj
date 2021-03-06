
#include <ansi.h>

inherit NPC;

int ask_ziying(object me);

void create()
{
	set_name("太上老君",({"taishang laojun","laojun","dao"}));
	set("gender", "男性");
	set("age", 55);
	set("long", "		\n太上老君。\n");

	set("attitude", "peaceful");
	set("class", "taoist");
	set("combat_exp", 2000000);
	set("daoxing", 4000000);
	set("kee", 400);
	set("max_kee", 400);
	set("sen", 400);
	set("max_sen", 400);
	set("force", 400);
	set("max_force", 400);
	set("mana", 400);
	set("max_mana", 400);
	set("force_factor", 5);
	set("mana_factor", 10);

	set_skill("spells", 30);
	set_skill("dao", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("unarmed", 30);

	set("inquiry", ([
		"ziying-sword"	:(: ask_ziying :),
		"紫郢剑"	:(: ask_ziying :),
		"here"	 : "这里就是兜率宫，你来这里干什么？",
	]));

	setup();
	carry_object("/d/lingtai/obj/cloth")->wear();
}


void init()
{
	object who;

	::init();
	if( interactive(who = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}


void greeting(object who)
{
	object me = this_object();
	if (who->query("dntg/laojunlu")=="allow")
	{
		me->command("kick");
	who->set("dntg/laojunlu","allow");
		me->command("chat 大事不好！"HIR+who->query("name")+HIC" 从八卦炉中逃出来了～～～～");
		remove_call_out("leave_laojunlu");
		call_out("leave_laojunlu", 1, who);	
	} 
}

int leave_laojunlu(object who)
{
	who = this_player();
	message("channel:rumor", HIC"【谣言四起】"HIR+who->query("name")+"一脚踢翻老君炉,怒火直冲九霄～～～～ \n"NOR, users());
	who->command("chat [1;31m玉帝老儿你等着，待我这就杀上灵霄殿，夺了你那昏君的宝座！！！[0m");
	who->move("/d/dntg/sky/tongmingdian");
}

int ask_ziying(object me)	
{
	me=this_player();
	if( me->query_temp("ask_ziying") == "tang1" ) 
	{
		command("consider");
		command("say 你俯耳过来。");
		command("say 据说，在五庄观后花园里有犀牛精，铁拐里比较清楚，你速去降伏！");
		command("say 老道一心为人，舍己奉公，把小羊让给别人，把肥猪留给自己。");
		me->set_temp("ask_ziying","laojun1");
		return 1;
	}
	else if( me->query_temp("ask_ziying") == "tieguaili" ) 
	{
		command("say 有这等大事？！");
		message_vision("$N掐指一算.....\n", this_object());
		message_vision("$N噼哩啪啦煽了自己无数个巴掌，终于明白了花儿为什么这样红的道理!\n", this_object());
		message_vision("对$N说道：肯定是在皇宫!\n", me);
		me->set_temp("ask_ziying","laojun2");
		return 1;
	}
	command("say 这是真的吗？");
	message_vision ("唐太宗有些慌张起来.\n",me);
	command("say 上仙还请后堂");
	me->set("enter", 1);
	return ("这次就多多感谢上仙了。。。\n");
}
