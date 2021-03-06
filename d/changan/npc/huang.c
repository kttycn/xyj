//created 5-20-97 pickle

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;
int rank_me();
string avenge();

void create()
{
	set_name(HIY"黄飞虎"NOR, ({"huang feihu", "huang", "feihu", "master"}));
	set ("long", @LONG
开国武成王黄飞虎，兴周第一大将，封神榜
上五岳之首东岳泰山大齐仁圣大帝，下凡寻
找其五色神牛的下落。
LONG);
 
	set("title", HIW"东岳泰山大齐仁圣大帝"NOR);
	set("gender", "男性");
	set("age", 43);
	set("str", 45);
	set("per", 35);
	set("int", 30);
	set("cor", 50);
	set("cps", 40);
	set("combat_exp", 8000000);
	set("daoxing", 10000000);

	set_skill("spear", 300);
	set_skill("force", 290);
	set_skill("dodge", 280);
	set_skill("literate", 280);
	set_skill("parry", 260);
	set_skill("unarmed", 280);
	set_skill("wuyue-spear", 300);
	set_skill("spells", 290);
	set_skill("pingtian-dafa", 280);
	set_skill("moshenbu", 280);
	set_skill("huomoforce", 280);
	set_skill("moyun-shou", 280);

	map_skill("force", "huomoforce");
	map_skill("spells", "pingtian-dafa");
	map_skill("unarmed", "moyun-shou");
	map_skill("spear", "wuyue-spear");
	map_skill("parry", "wuyue-spear");
	map_skill("dodge", "moshenbu");

	set("max_sen", 6000);
	set("max_kee", 8000);
	set("force", 10000);
	set("max_force", 6000);
	set("mana",6000);
	set("max_mana",3000);
	set("daoxing",5000000);
	set("force_factor", 200);
	set("mana_factor", 150);
	set("inquiry", ([
		"复仇" : (: avenge :),
		"职位": (: rank_me :),
	]));
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "spear", "buhui" :),
		(: perform_action, "unarmed", "zhangxinlei" :),
		(: perform_action, "unarmed", "zhangxinlei" :),
	}) );
 
	create_family("火云洞", 1, "蓝");
	setup();
 
	carry_object("/d/obj/weapon/spear/huaji2")->wield();
	carry_object("/d/city/obj/xjdan");
	carry_object("/d/obj/armor/jinjia")->wear();
}
 
int accept_fight(object me)
{
	command("say 老夫手重，若是伤人反而不美了。\n");
	return 0;
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "平天大圣")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "火云洞"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", RED"三山九洞"NOR+RED"◆"BLU"巡视小妖"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", RED"三山九洞"NOR+RED"◆"YEL"移山大将"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", RED"三山九洞"NOR+RED"◆"RED"食人妖王"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", RED"三山九洞"NOR+RED"◆"MAG"寂静长老"NOR);
		} else {
			me->set("nick", RED"三山九洞"NOR+RED"◆"CYN"通天洞主"NOR);
		}

		tell_object(me, "黄飞虎对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"黄飞虎对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

int attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="火云洞") {
		if (((int)ob->query("daoxing") < 400000 )) {
			command("say " + RANK_D->query_respect(ob) +
			"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
			return 0;
		}
		command("haha "+ob->query("id"));
		command("say 看你的身手，象是见过我那孽畜，我传你些功夫，你去帮我把他pk到没道行！\n");
		command("recruit " + ob->query("id") );
		return 0;
	}
	command("say " + RANK_D->query_respect(ob) +"还是再苦练几年枪法罢！\n");
	return 1;
}
/*
{	
string myname=RANK_D->query_respect(me);
 if ((int)me->query_skill("spear")< 200) 
//	if ((int)me->query_skill("spear")< 200) 
		{
			command("say 这"+myname+"再苦练几年枪法罢！");
			return 0;
		}
	if ((int)me->query_skill("stick") < 200 )
		{
			command("say 这"+myname+"知道我那孽畜的下落？");
			return 0;
		}
	command("say 看你的身手，象是见过我那孽畜，我传你些功夫，你去帮我把他pk到没道行！\n");
	command("recruit " + me->query("id") );
	return 1;
}
*/
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
	ob->set("title", "五岳大帝座下山神");
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="火云洞")
		return ("你不是本派弟子，生死与本驸马何干？");
	if(who->query("faith")<1000)
		return ("你在本门名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("本王未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，本王还得想一想");
	command("say 本王这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见黄飞虎向空中一指：\n");
	tell_room(where,"护洞魔王何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")
+"抓了起来！");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我火云洞弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}  
