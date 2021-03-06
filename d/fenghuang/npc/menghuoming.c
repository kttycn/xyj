#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
string ask_me();
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name("孟火明", ({ "meng huoming", "meng" }));
	set("nickname", HIR "烈火狂狮" NOR);
	set("age", 30);
	set("title", HIR "烈火将军" NOR);
	set("gender", "男性");
	set("long", "他面色火红，赤发冲天，是宗主的亲传弟子，以勇猛著称，故得
名烈火将军。\n");

	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "将军");
	set("per", 20);
	set("str", 40);
	set("int", 25);
	set("con", 30);

	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 1000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 1800);
	set("mana", 3600);
	set("mana_factor", 80);
	set("daoxing", 3000000);
	set("combat_exp", 800000);
	set("score", -5000);

	set_skill("stick", 140);
	set_skill("literate", 100);
	set_skill("unarmed",90);
	set_skill("dodge", 120);
	set_skill("parry", 110);
	set_skill("force", 120);
	set_skill("spells", 100);
	set_skill("yufeng-shu", 100);
	set_skill("tenglong-finger",90);
	set_skill("wuzu-xinfa", 110);
	set_skill("fenghuang-shenfa", 110);
	set_skill("liedi-stick",140);
	map_skill("unarmed","tenglong-finger");
	map_skill("parry", "jile-dao");
	map_skill("spells", "yufeng-shu");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");
	map_skill("stick","liedi-stick");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 80);

	create_family("凤凰星",3,"大将");
	set("inquiry", ([
		"出城": (: expell_me :),
		"leave": (: expell_me :),
		"任务" : (: ask_me :),
		"清道": (: ask_mieyao :),
		"cancel": (: ask_cancel :),
	]));
	setup();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "凤凰星")
	{
		message_vision("孟火明对着$N点点头，微微笑了笑。\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	ob = this_player();
	if (!(int)this_player()->query("bmark/毕业生"))
		command("say 你还是去凤凰军校去进修一下吧。\n");
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
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", HIC"凤凰城国防军少校"NOR);
	}
	return 0;
}

string ask_me()
{
	object me;
	int i;
	me=this_player();
	if (me->query("family/family_name")!="凤凰星")
		return "你不是凤凰星战士，别在这里捣乱！\n";
	if (me->query_temp("digdong1")==1 || me->query_temp("digdong2")==1
	|| me->query_temp("digdong3")==1 || me->query_temp("digdong4")==1
	|| me->query_temp("digdong5")==1 || me->query_temp("digdong6")==1)
		return "你已经有任务在身了！\n";
	if (me->query("combat_exp")>500000)
		return "你已经不需要通过杀怪兽来增加自己的武学了。\n";
	i=random(5)+1;
	if (i==1)
	{
		me->set_temp("digdong1",1);
		tell_object(me,"据说一号岩洞有怪兽出没，你去查看一下！\n");
	}
	if (i==2)
	{
		me->set_temp("digdong2",1);
		tell_object(me,"据说二号岩洞有怪兽出没，你去查看一下！\n");
	}
	if (i==3)
	{
		me->set_temp("digdong3",1);
		tell_object(me,"据说三号岩洞有怪兽出没，你去查看一下！\n");
	}
	if (i==4)
	{
		me->set_temp("digdong4",1);
		tell_object(me,"据说四号岩洞有怪兽出没，你去查看一下！\n");
	}
	if (i==5)
	{
		me->set_temp("digdong5",1);
		tell_object(me,"据说五号岩洞有怪兽出没，你去查看一下！\n");
	}
	if (i==6)
	{
		me->set_temp("digdong6",1);
		tell_object(me,"据说六号岩洞有怪兽出没，你去查看一下！\n");
	}
	return "快去快回！\n";
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="凤凰星") {
		command("say 你既是执意离开，本将军也不留你，不过以后可不要怪我无情。");
		me->set_temp("betray", 1);
		command("say 你要离开，本少爷可要留下点东西，你才能走哦！");
		return ("你可愿意(agree)？");
	}
	return ("在这里闹什么闹。");
}

void init()
{
	::init();
	add_action("do_agree", "agree");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N答道：弟子愿意。\n\n", this_player());
		this_player()->add("betray/count", 1);
		this_player()->add("betray/phoenix", 1);
		command("say 既然你不想留在我门派，那就走吧！");
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*90/100);
		if(this_player()->query_skill("yufeng-shu"))
			this_player()->delete_skill("yufeng-shu");
		if(this_player()->query_skill("tenglong-finger"))
			this_player()->delete_skill("tenglong-finger");
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "普通百姓");
		this_player()->set_temp("betray",0);
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->save();
		command("pat");
		command("say 当初怎么会把这样的人收归门下……\n");
		return 1;
	}
	return 0;
}

//string ask_cancel()
//{
//	object me=this_player();
//	if("/d/obj/yao/mieyao"->delete_mieyao(me))
//		me->add("faith",-5);
//	return ("没用的东西！");
//}
string ask_cancel()
{
	object me=this_player();
	return "/d/obj/yao/mieyao"->delete_mieyao(me);
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="凤凰星") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"孟火明放目远望前方：\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"即我门人,当以扫清妖氛为己任。\n"NOR;
	}
	return ("本将军不明白。");
}
