
#include <ansi.h>

inherit NPC;

int ask_ziying(object me);
int out_master();

void create()
{
	set_name("太上老君",({"taishang laojun","laojun","dao"}));
	set("gender", "男性");
	set("age", 55);
	set("long", "		\n太上老君。\n");
	set("per", 40);
	set("str",20);
	set("attitude", "peaceful");
	set("class", "taoist");
	set("combat_exp", 2000000);
	set("daoxing", 4000000);
	set("kee", 4000);
	set("max_kee", 4000);
	set("sen", 4000);
	set("max_sen", 4000);
	set("force", 4000);
	set("max_force", 4000);
	set("mana", 4000);
	set("max_mana", 4000);
	set("force_factor", 115);
	set("mana_factor", 115);

	set_skill("spells", 230);
	set_skill("taiyi", 220);
	set_skill("force",220);
	set_skill("zhenyuan-force",220);
	set_skill("parry", 220);
	set_skill("dodge", 220);
	set_skill("baguazhen", 200);
	set_skill("unarmed", 200);
	set_skill("wuxing-quan", 200);
	set_skill("sword",220);
	set_skill("sanqing-jian",220);
	set_skill("blade",210);
	set_skill("yange-blade",220);

	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("dodge", "baguazhen");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
	map_skill("blade", "yange-blade");
	
	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
        set("chat_chance_combat", 50);
        set("chat_msg_combat",
        ({
                (: cast_spell, "zhenhuo" :),
                (: cast_spell, "qiankun" :),
        }) );



	set("inquiry", ([
		"ziying-sword"	:(: ask_ziying :),
		"紫郢剑"	:(: ask_ziying :),
		"here"	 : "这里就是兜率宫，你来这里干什么？",
		"完成": (: out_master :),
		"done": (: out_master :),
	]));

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}


int ask_ziying(object me)	
{
//	object ob, me;
	me=this_player();
	
	if(this_object()->query("ziying")=="done" )
		command("say 对不起,紫郢剑已经被人借走了!");
	
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
		me->set_temp("ask_ziying_laojun",1);
		return 1;
	}

/*	if(!(me->query_temp("ask_ziying") == "tang2" )
	&& !(me->query_temp("kill_ziying_dragon"))
	&& !(me->query_temp("kill_ziying_nvjing"))
	&& !(me->query_temp("ask_ziying_laojun")))*/
	{
		tell_object(me,"太上老君对你说道：这位仙友还是自己琢磨吧！\n");
		command("heng");
		return 1;
	}
}	

init()
{
	add_action("do_accept","accept");
}

int out_master()
{
	object ob,me;
	me = this_player();
/*	if(!(me->query_temp("ask_ziying") == "tang2" )
		&&!me->query_temp("kill_ziying_dragon")
		&&!me->query_temp("kill_ziying_nvjing")
		&&!me->query_temp("ask_ziying_laojun"))*/
//	if( me->query_temp("ask_ziying") == "tang2"
//	&& me->query_temp("kill_ziying_dragon")
//	&& me->query_temp("kill_ziying_nvjing")
//	&& me->query_temp("ask_ziying_laojun"))
	if( !(me->query_temp("kill_ziying_nvjing")==1))
	{
		tell_object(me,"太上老君对你说道：这位仙友还是自己琢磨吧！\n");
		command("heng");
		return 1;		
	} else {
		tell_object(me,"太上老君沉吟了一会,对"+me->query("name")+"说道:要想拿紫郢剑,
		你必须过我这关(accept test).\n");
		me->set_temp("ziying/test",1);
		return 1;
		}
	
}


int do_accept(string arg)
{
//	int i;
//	object ziying;
//	string ziying_given
//	,ziqing_given;
//	ziying_given = "/d/huanggong/doublesword/obj/doublesword.c";
	mapping guild;
	object ob,me,ziying;
	 me = this_player();
//	 ziying=/d/huanggong/doublesword/obj/doublesword.c;

	if( !me->query_temp("ziying/test") )
		return 0;
	if( arg== "test" )
	{
		say("\n太上老君说道：很好，小心了，这是第一招。\n\n");
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment()))
		{
			say("太上老君叹了口气，说道：嘻嘻，连第一招都撑不过，真是自不量力....\n");
			return 1;
		}
		say("\n太上老君说道：第二招，小心了。\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("太上老君叹道：就这样子还想拿紫郢剑，唉.....\n");
			return 1;
		}
		say("\n太上老君说道：你注意了!....第三招。\n\n");
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment()))
		{
			say("太上老君说道：嘿嘿，能经住我三下已经不容易了，我早就看出来这第三下子你受不了了！\n");
			return 1;
		}
		say("\n太上老君说道：小心了，第四招。\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("太上老君笑道：你还是回去多多练习吧.....\n");
			return 1;
		}
		if(ziying = present("ziying-sword", me))
			destruct(ziying);
//		if(zheng = present("xuesheng zheng", me))
//			destruct(zheng);
		command("say 好好，你虽非道家一派，但武功机智都属非凡，理当奖励送你。");
		message_vision ("太上老君阴声到：如若叫我看见你为非作歹，莫怪我心狠手辣！\n\n",me);
		message_vision ("太上老君送给你一把紫郢剑。\n\n",me);
		ob = new("/d/huanggong/doublesword/obj/ziying-sword");
		ob->move(me);
//			return 1;
//		}
//		if (ziying->query("id")=="ziying sword" && ziying->query("id")=="ziying")
		MONITOR_D->report_rumor_object_msg(me, "拿到〖紫郢剑〗了！");
		this_object()->set("ziying","done");
		me->delete_temp("ziying/test");
		me->delete_temp("ask_ziying");		
		me->delete_temp("kill_ziying_dragon");
		me->delete_temp("kill_ziying_nvjing");
		me->delete_temp("ask_ziying_laojun");
		return 1;
	}
	return 0;
}

