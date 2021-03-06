#include <ansi.h>

inherit NPC;

void wield_arrow();
int do_kill();

void create()
{
	set_name("后羿", ({"hou yi"}));
	set("gender", "男性" );
	set("title",HIY"落日神箭"NOR);
	set("long", "他就是传说中射落九个太阳的大英雄。\n");
	set("age", 35);
	set("per", 25);
	set("attitude", "friendly");
	set("rank_info/respect", "英雄");
	set("combat_exp", 2000000);
	set("daoxing", 500000);
	set("max_kee", 2700);
	set("max_sen", 1500);
	set("attitude", "friendly");
	set("per", 30);
	set("str", 50);
	set("int", 28);

	set_skill("force",180);
	set_skill("spells",180);
	set_skill("archery",200);
	set_skill("dodge",180);
	set_skill("unarmed",180);
	set_skill("parry",180);
	set_skill("luori-archery",200);
	set_skill("seashentong", 170);
	set_skill("dragonfight", 200);
	set_skill("dragonforce", 180);
	set_skill("dragon-steps", 180);
	map_skill("archery","luori-archery");
map_skill("parry","luori-archery");
	map_skill("dodge","dragon-steps");
	map_skill("spells","seashentong");
	map_skill("unarmed","dragonfight");

	set("force",3000);
	set("max_force",6000);
	set("force_factor",150);

	set("eff_dx", 500000);
	set("nkgain", 650);
	set("inquiry",([
		"复仇" : (: do_kill :),
	]));

	setup();
	carry_object("/d/obj/cloth/surcoat")->wear();
	carry_object("/d/obj/weapon/archery/qiankun-bow")->wield();
	carry_object("/d/obj/weapon/archery/zhentian-arrow")->wield();
}
void init()
{
	object ob;
	::init();
	set("chat_chance", 60);
	set("chat_msg", ({
		"后羿仰天长叹！\n",
		"后羿擦了擦额头上的汗水。\n",
		"后羿眼里流露出一丝哀怨。\n",
		(: random_move :)
	}) );
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "archery", "riyue" :),
	}) );
	set("inquiry", ([
		"name" : "我就是射日的后羿。\n",
	]) );
	add_action("do_cast","cast");
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();
	message_vision("$N对着$n结结巴巴的想念咒语，却怎么也张不开嘴。\n",who,me);
	return 1;
}

/*void attempt_apprentice(object ob)
{
	if ( !((string)ob->query("gender")=="女性")){
		command("shake");
		command("say 除了嫦娥，我最讨厌女人！月宫只收女徒，我就偏收男徒，这位" +
		RANK_D->query_respect(ob) + "还是另请高就吧。\n");
		return;
	}
	if ( (int)ob->query("str") <28){
		command("shake");
		command("say 以我看这位" +
		RANK_D->query_respect(ob) + "的资质并不适于学习我的武功，还是另请高就吧。\n");
		ob->set_temp("denied_by_hou_yi",1);
		return;
	}
	if ( (int)ob->query("kill_xiwangmu") ) {
		command("hate");
		command("say 你去把王母那混蛋东西杀了，我就收你为徒！\n");
		ob->set_temp("kill_xiwangmu_hou",1);
		return;
	}
    if ( ((int)ob->query("combat_exp") < 800000) || ((int)ob->query("daoxing")<100000)) {
		command("say " + RANK_D->query_respect(ob) +
		"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
		return;
	}

	if ( !(int)ob->query("family") ) {
		command("kick");
		command("say 好你个"+RANK_D->query_respect(ob)+"，敢来玩我！\n");
		this_object()->kill_ob(ob);
		return;
	}

	command("pat "+ob->query("id"));
	command("say 好，希望" + RANK_D->query_respect(ob) +
	"多加努力，吓得西王母那个死老太婆屁也不敢放一个。\n");
	command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}

void wield_arrow()
{
	if (!this_object()->query_temp("weapon"));
	{
		carry_object("/d/obj/weapon/archery/zhentian-arrow")->wield();
		message_vision("$N手一招，又拿出一壶箭来。\n",this_object());
	}
	message_vision((string)this_object()->query_temp("weapon"));
	remove_call_out("wield_arrow");
	call_out("wield_arrow",10);
}

int do_kill()
{
	object who = this_player();

	command("pat " + who->query("id") );
	command("say 好！只要你去杀了西王母，帮我出了这口气，一切好商量。\n");
	who->delete_temp("kill_xiwangmu");
	who->set_temp("kill_xiwangmu", 1);
	return 1;
}
*/
