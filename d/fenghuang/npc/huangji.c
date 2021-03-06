#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();

void create()
{
	set_name("黄吉", ({ "huang ji", "huang" }));
	set("nickname", HIY "无敌神龙" NOR);
	set("age", 25);
	set("title", HIW "神龙将军" NOR);
	set("gender", "男性");
	set("long", "他是宗主的亲传弟子，掌法了得，人称神龙将军。\n");
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "将军");
	set("per", 24);
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
	set("combat_exp", 1400000);
	set("score", -7000);

	set_skill("literate", 100);
	set_skill("unarmed",140);
	set_skill("dodge", 110);
	set_skill("parry", 130);
	set_skill("force", 120);
	set_skill("wuzu-xinfa", 120);
	set_skill("fenghuang-shenfa", 110);
	set_skill("wudi-zhan",140);
	set_skill("spells", 120);
	set_skill("yufeng-shu", 120);
	map_skill("spells", "yufeng-shu");
	map_skill("unarmed","wudi-zhan");
	map_skill("parry", "wudi-zhan");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 80);
	create_family("凤凰星",3,"大将");

	set("inquiry", ([
		"职位": (: rank_me :),
	]) );

	setup();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "凤凰星")
	     {
	       message_vision("黄吉对着$N点点头，微微笑了笑。\n",ob);
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

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "护国将军")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "凤凰星"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIR"凤凰传说"NOR+RED"◆"BLU"守护游侠"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIR"凤凰传说"NOR+RED"◆"YEL"越空飞将"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIR"凤凰传说"NOR+RED"◆"RED"腾龙隐王"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIR"凤凰传说"NOR+RED"◆"MAG"天魔武皇"NOR);
		} else {
			me->set("nick", HIR"凤凰传说"NOR+RED"◆"CYN"宇宙霸主"NOR);
		}

		tell_object(me, "黄吉对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"黄吉对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}
