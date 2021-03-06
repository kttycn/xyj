// hufa.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name(HIW"护法尊者"NOR, ({"hufa zunzhe", "zunzhe"}));
	set("long", "武圣门守派尊者，门派大小事物问他都知道。\n");
	set("title", HIC"武帝门"NOR);
	set("gender", "男性");
	set("age", 1000);
	set("class", "wusheng");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "护法");
	set("looking", "英俊潇洒，玉树临风，风流倜傥。");
	set("max_kee", 1000);
	set("max_gin", 100);
	set("max_sen", 1000);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 10);
	set("max_mana", 500);
	set("mana", 1000);
	set("mana_factor", 10);
	set("combat_exp", 1000000);
	set("daoxing", 1100000);

	set_skill("unarmed", 130);
	set_skill("dodge", 130);
	set_skill("parry", 130);
	set_skill("spells", 130);
	set_skill("feisheng-spells", 130);
	set_skill("literate", 80);
	set_skill("sword", 130);
	set_skill("wuying-sword", 130);
	set_skill("fumobashi", 130);
	set_skill("mizong-steps", 130);
	set_skill("dodge", 130);
	set_skill("force", 130);
	set_skill("xiantian-force", 130);

	map_skill("spells", "feisheng-spells");
	map_skill("unarmed", "fumobashi");
	map_skill("force", "xiantian-force");
	map_skill("sword", "wuying-sword");
	map_skill("parry", "wuying-sword");
	map_skill("dodge", "mizong-steps");

	set("inquiry", ([
		"出门" : (: expell_me :),
		"leave" : (: expell_me :),
		"cancel": (: ask_cancel :),
		"降魔": (: ask_mieyao :),
	]) );

	create_family("武圣门", 1, "护法");

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="武圣门") {
		 message_vision("护法尊者胡子抖抖，好像非常生气。\n", me);
		 me->set_temp("betray", 1);
		 message_vision("护法尊者对$N嚷嚷着：小东西，你说话是真心话(true)？\n", me);
		 return ("气死我了，气死我了！\n");
	}
	return ("问什么问！自己想去！\n");
}
void init()
{
	add_action("do_true", "true");
}

int do_true(string arg)
{
	if(this_player()->query("family/family_name") != "武圣门" )
		return 0;
	if(this_player()->query_temp("betray")) {
		message_vision("$N答道：弟子讲的真心话！\n\n", this_player());
		message_vision("护法尊者叹了口气，既是如此，你便下山吧！\n", this_player());
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("feisheng-spells") )
			this_player()->delete_skill("feisheng-spells");
		if( this_player()->query_skill("xiantian-force") )
			this_player()->delete_skill("xiantian-force");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/wusheng", 1);
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "普通百姓");
		this_player()->set_temp("betray", 0);
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->save();
		message_vision("护法尊者伸出手将$N一推，$N化作一股青烟向东而去 ... \n", this_player());
		this_player()->move("/d/city/center");
		tell_room( environment(this_player()),"天空上噗噗嗦嗦几声响，掉下个人来！\n", ({this_player()}));
		this_player()->unconcious();
		return 1;
	}
	return 0;
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="武圣门") {
	if ((int)ob->query("daoxing") < 100000 ) {
  	command("say 我们降魔除妖之人最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "你曾背叛孔武大帝，本护法最恨像你这样的人，我不原再收你为徒了！\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("feisheng-spells", 1) < 80 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对我飞升大法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
	command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	ob->set("class", "wusheng");
}
string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("没用的东西！");
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="武圣门") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"护法尊者放目远望前方：\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"灭妖除魔，乃我武圣门中人之本分。\n"NOR;
	}
	return ("本尊者不明白。");
}
