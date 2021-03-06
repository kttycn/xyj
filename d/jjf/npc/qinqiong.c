#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_mieyao(object me);
string ask_cancel();
string avenge();

void create()
{
	set_name("秦琼", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
	set("title", "开国元勋");
	set("gender", "男性");
	set("age", 43);
	set("str", 30);
	set("per", 26);
	set("int", 30);
	set("cor", 50);
	set("cps", 50);
	set("long", "秦叔宝是大唐国开国名臣，更是一位出名的武将。\n");
	set("combat_exp", 1200000);

	set_skill("literate", 220);
	set_skill("spear", 240);
	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 250);
	set_skill("mace", 300);
	set_skill("wusi-mace", 300);
	set_skill("yanxing-steps", 250);
	set_skill("bawang-qiang", 240);
	set_skill("lengquan-force", 260);
	set_skill("unarmed", 260);
	set_skill("changquan", 220);
	map_skill("mace", "wusi-mace");
	map_skill("force", "lengquan-force");
	map_skill("unarmed", "changquan");
	map_skill("spear", "bawang-qiang");
	map_skill("archery", "xuanyuan-archery");
	map_skill("parry", "bawang-qiang");
	map_skill("dodge", "yanxing-steps");
	set("max_sen", 2800);
	set("max_kee", 4400);
	set("force", 2000);
	set("max_force", 1800);
	set("force_factor", 80);
	set("inquiry", ([
		"name": "在下秦琼，字叔宝。",
		"here": "这里就是将军府啊，难道你不知道？",
		"rumors": "在下不在江湖行走很久了，江湖上的事情在下可不太清楚。",
		"复仇" : (: avenge :),
		"cancel": (: ask_cancel :),
		"除魔": (: ask_mieyao :),
//		"逃犯": (: ask_bad :),
		"kill": (: ask_mieyao :),
		"职位": (: rank_me :),
 	]) );

	create_family("将军府", 2, "蓝");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "spear", "lianhuan" :),
		(: perform_action, "spear", "qiangjian" :),
		(: perform_action, "spear", "bugong" :),
	}) );

	setup();
	carry_object("/d/obj/weapon/spear/yinqiang")->wield();
	carry_object("/d/obj/armor/tiejia")->wear();
	carry_object("/d/obj/weapon/mace/copperjian");
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
	if((string)me->query("family/family_name")=="将军府") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"秦琼爽朗地笑了起来：\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"灭妖除魔，乃我官府中人之本分。\n"NOR;
	}
	return ("你不是官府中人！");
}

int accept_fight(object me)
{
	command("say 老夫久未和江湖人动手过招了，今日也不想破例。\n");
	return 0;
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "将军府掌门")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "将军府"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIR"大唐将星"NOR+RED"◆"BLU"护院亲兵"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIR"大唐将星"NOR+RED"◆"YEL"先锋大将"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIR"大唐将星"NOR+RED"◆"RED"守城提督"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIR"大唐将星"NOR+RED"◆"MAG"兵马元帅"NOR);
		} else {
			me->set("nick", HIR"大唐将星"NOR+RED"◆"CYN"开国元勋"NOR);
		}

		tell_object(me, "秦琼对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"秦琼对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

int attempt_apprentice(object me)
{
	string myname=RANK_D->query_respect(me);
	if ((int)me->query("combat_exp")< 100000)
	{
		command("say 这位"+myname+"还是先去跟本府家将打打基础吧！");
		return 0;
	}
	command("haha");
	command("say 很好，时下正是用人之际，"+myname+"多加努力，他日必定有成。\n");
	command("recruit " + me->query("id") );
	return 1;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
	string myname=RANK_D->query_respect(me);

	if (me->query("combat_exp") < 100000)
	{
		command("emote 皱了皱眉头，说道："+myname+"还欠修练，老夫所教"+myname+"恐怕难以理解。");
		return 1;
	}
	return 0;
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="将军府")
		return ("你不是本府弟子，生死与本将军何干？");
	if(who->query("faith")<1000)
		return ("你在本府名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("本将军未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，本将军还得想一想");
	command("say 本将军这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见秦琼大喝一声：\n");
	tell_room(where,"左右侍卫何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")
+"抓了起来！");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我将军府弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}
