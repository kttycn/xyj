// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
string ask_aotang();

void create()
{
	set_name("王方平", ({ "wang fangping", "wang", "fangping" }));

	set("long","王方平本是山中道士，后在丰都山同阴长生同修炼成仙，御封(「鬼王」。\n");
	set("attitude", "peaceful");
	set("per", 30);
	set("str", 25);
	set("int", 25);
	set("age", 30);
	set("title", "轮回司主");
	set("nickname", "鬼王");
	set("combat_exp", 850000);
	set("daoxing", 600000);

	set("max_gin", 1400);
	set("max_kee", 1400);
	set("max_sen", 1400);
	set("class", "youling");
	set("force", 2500);
	set("max_force", 1500);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 2500);
	set("mana_factor", 100);

	set_skill("literate", 100);
	set_skill("ghost-steps", 120);
	set_skill("dodge", 120);
	set_skill("unarmed", 120);
	set_skill("parry", 120);
	set_skill("spells", 120);
	set_skill("gouhunshu", 80);
	set_skill("jinghun-zhang", 120);
	set_skill("force", 120);
	set_skill("tonsillit", 80);
	set_skill("stick", 120);
	set_skill("kusang-bang", 120);

	map_skill("stick","kusang-bang");
	map_skill("parry", "kusang-bang");
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
//                (: exert_function, "powerup" :),
		(: exert_function, "sheqi" :),
		(: cast_spell, "gouhun" :),
	}) );

    set("inquiry",([
		"熬孟婆汤" : (: ask_aotang :),
	]));

	set("nkgain", 400);

	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 50);


	create_family("阎罗地府", 2, "你好");

	setup();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
	carry_object("/d/obj/cloth/taijicloth")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
	command("grin");

	command("say 很好，" + RANK_D->query_respect(me) +
"多加努力，他日必定有成。\n");
	command("recruit " + me->query("id") );
	me->set("class", "youling");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "youling");
	ob->set("title", HIB"地府招魂司阴兵"NOR);
}

string ask_aotang()
{
	object who = this_player();
	object me = this_object();
	if(who->query("family/family_name")!="阎罗地府")
		return "你不是鬼府弟子，问这些干什么？\n";
	if(who->query("faith")>500 || who->query("combat_exp")>50000
	|| who->query("daoxing")>50000 )
		return "你现在的身份怎么可以干这等脏活？";
	if(who->is_busy())
		return ("你正忙着呢！");
	command("say 那好，你去替我熬些孟婆汤来。");
	message_vision("$N在炉子旁坐下，聚精会神地看火熬汤。\n",who);
	who->start_busy(5);
	call_out("finish_aotang",5,who,me);
	command("nod");
	return ("果然是一个勤快人。");
}

void finish_aotang(object me,object master)
{
	message_vision("$N在炉子跟前蹲了好久，汤终于熬好了，松了一口气，只觉得双眼被烟熏的发酸！\n");
	me->receive_damage("sen",20);
	message_vision("$N走到$n面前，恭恭敬敬地说了声：禀告王爷，熬好了，没错！\n",me,master);
	command("pat "+me->query("id"));
	command("say 好弟子！");
	tell_object(me,HIY"你觉得对摄气诀有了一些领悟。\n"NOR);
	me->add("faith",1);
	me->add("combat_exp",9);
	me->add("potential",3);
	me->improve_skill("tonsillit",random(me->query("int")),1);
}
