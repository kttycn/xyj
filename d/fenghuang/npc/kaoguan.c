inherit NPC;
#include <ansi.h>;
int out_master();

void create()
{
	set_name("纪卡诺", ({ "ji keluo", "ji" }) );
	set("title", "凤凰军校主考官");
	set("gender", "男性");
	set("age", 35);
	set("long","他是凤凰军校的主考官，学员要毕业，必须过他这关。\n");

	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "教官");
	set("per", 24);
	set("str", 26);
	set("int", 28);
	set("con", 30);

	set("max_kee", 800);
	set("max_gin", 300);
	set("max_sen", 800);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 1000);
	set("mana_factor", 50);
	set("daoxing", 300000);
	set("combat_exp", 400000);
	set("score", 0);

	set("inquiry", ([
		"毕业": (: out_master :),
	]) );
	set_skill("unarmed",50);
	set_skill("spells", 50);
	set_skill("yufeng-shu", 50);
	set_skill("force",60);
	set_skill("stick",50);
	set_skill("parry",50);
	set_skill("liedi-stick",50);
	set_skill("fenghuang-shenfa",50);
	set_skill("dodge",50);
	set_skill("tenglong-finger",50);
	set_skill("wuzu-xinfa",60);
	set_skill("spells", 50);
	set_skill("yufeng-shu", 50);
	map_skill("spells", "yufeng-shu");
	map_skill("unarmed","tenglong-finger");
	map_skill("force","wuzu-xinfa");
	map_skill("spells","yufeng-shu");
	map_skill("stick","liedi-stick");
	map_skill("parry","liedi-stick");
	map_skill("dodge","fenghuang-shenfa");

	create_family("凤凰星", 4, "教官");
	setup();

	carry_object("/d/fenghuang/obj/ganggun")->wield();
	carry_object("/d/fenghuang/obj/beixin")->wear();
}

init()
{
	add_action("do_accept","accept");
}

int out_master()
{
	object ob, me;
	me = this_player();
	if (!(int)me->query("xmark/学员"))
	{
		tell_object(me,"考官对你说，你不是本校学员，不要来捣乱。\n");
		return 1;
	}

	tell_object(me,"考官沉吟了一会,对"+me->query("name")+"说道:要想毕业,
	你必须过我这关(accept test).\n");
	me->set_temp("phoenix/test",1);
	return 1;
}
int do_accept(string arg)
{
	mapping guild;
	object ob, me, zheng;
	me = this_player();

	if( !me->query_temp("phoenix/test") )
		return 0;
	if( arg== "test" )
	{
		say("\n考官点了点头，说道：很好，小心了　，这是第一招....\n\n");
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment()))
		{
			say("考官叹了口气，说道：嘻嘻，连第一招都撑不过，真是自不量力....\n");
			return 1;
		}
		say("\n考官喝道：第二招....\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("考官叹道：这样子还想出师,唉.....\n");
			return 1;
		}
		say("\n考官喝道：第三招，你注意了!....\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("考官笑道：你还是回去多多练习吧.....\n");
			return 1;
		}
		if(zheng = present("xuesheng zheng", me))
			destruct(zheng);
		say("\n考官微笑道：恭喜,你可以毕业了，这是你的毕业证，拿好了。\n\n");
		me->set("title",HIM"凤凰城国防军准尉"NOR);
		ob = new("/d/fenghuang/obj/zhengshu1");
		ob->move(me);
		me->delete("xmark/学员");
		me->set("bmark/毕业生", 1);
		return 1;
	}
	return 0;
}

void reset()
{
//        delete_temp("learned");
	set("apprentice_available", 3);
}

void attempt_apprentice(object ob)
{       
	if (!(int)ob->query_temp("bmark/学员"))
		command("say 你不是凤凰军校学员，我不能收下你，你还是另找别人吧。\n");
	else if (!(int)ob->query_temp("bmark/毕业"))
		command("say 你已经从凤凰军校毕业了，我怎么敢收你呢。\n");
	else
	{
		command("say 好吧，我收下你。\n");
		command("recruit "+ob->query("id"));
		return;
	}
	return;
}

int recruit_apprentice(object ob)
{
	string title = ob->query("title");
	
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", title);
	}
	return 0;
}
