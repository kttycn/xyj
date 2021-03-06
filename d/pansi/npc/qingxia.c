
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_chuxian(object me);
string ask_cancel();
string give_zui(object me);
void create()
{
	set_name(HIC"青霞仙子"NOR, ({"qingxia xianzi", "qingxia", "xianzi","master"}));
	set("long", "她是紫霞仙子的孪生姐姐,曾被佛祖把她和紫霞仙子捏在一棵灯芯里。後因紫霞仙子思凡
下界开山立派,故追至此处。\n");
	set("title", HIY"佛祖灯芯"NOR);
	set("gender", "女性");
	set("age", 20);
	set("class","xian");
	set("attitude", "friendly");
	set("rank_info/respect", "小姑娘");
	set("cor", 30);
	set("per", 21);
	set("max_kee", 4500);
	set("max_gin", 800);
	set("max_sen", 4500);
	set("force", 4000);
	set("max_force", 2400);
	set("force_factor", 125);
	set("max_mana", 1800);
	set("mana", 3000);
	set("mana_factor", 150);
	set("combat_exp", 1600000);
	set("daoxing", 3000000);

	set_skill("literate", 210);
	set_skill("unarmed", 230);
	set_skill("dodge", 210);
	set_skill("force", 210);
	set_skill("parry", 200);
	set_skill("sword", 300);
	set_skill("spells", 200);
	set_skill("whip", 230);
	set_skill("pansi-dafa", 210);
	set_skill("lanhua-shou", 210);
	set_skill("jiuyin-xinjing", 200);
	set_skill("qingxia-jian", 300);
	set_skill("yueying-wubu", 200);
	set_skill("yinsuo-jinling", 200);
	map_skill("spells", "pansi-dafa");
	map_skill("unarmed", "lanhua-shou");
	map_skill("force", "jiuyin-xinjing");
	map_skill("sword", "qingxia-jian");
	map_skill("parry", "yinsuo-jinling");
	map_skill("dodge", "yueying-wubu");
	map_skill("whip", "yinsuo-jinling");
	set("chat_chance_combat", 50);
	set("inquiry", ([
//		"复仇" : (: avenge :),
//	 "醉生梦死" : (: give_zui :),
		"修炼": (: ask_chuxian :),
		"职位": (: rank_me :),
		"cancel": (: ask_cancel :),
]));
	set("no_zui", 0);
	create_family("盘丝洞", 1, "红");
	setup();

	 carry_object("/d/obj/cloth/tianyi.c")->wear();
	 carry_object("/d/obj/weapon/sword/qinghong")->wield();
	 carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
	add_action("do_yes", "yes");
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "续缘玉女")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "盘丝洞"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", MAG"盘丝仙府"NOR+RED"◆"BLU"巡洞小妖"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", MAG"盘丝仙府"NOR+RED"◆"YEL"霞光使者"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", MAG"盘丝仙府"NOR+RED"◆"RED"桃花掌阵"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", MAG"盘丝仙府"NOR+RED"◆"MAG"灯芯大仙"NOR);
		} else {
			me->set("nick", MAG"盘丝仙府"NOR+RED"◆"CYN"忘情大圣"NOR);
		}

		tell_object(me, "青霞仙子对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"青霞仙子对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	/*if ( !((string)ob->query("gender")=="女性")){
		command("shake");
		command("say 我们盘丝洞只收女徒，这位" + RANK_D->query_respect(ob) + "还是另请高就吧。\n");
		return;
	}*/

	if ( (string)ob->query("family/family_name")=="盘丝洞") {
		if (((int)ob->query("daoxing") < 500000 )) {
			command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
			return;
		}
		command("pat "+ob->query("id"));
		command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们盘丝洞发扬光大。\n");
		command("recruit " + ob->query("id") );
		ob->set("title", "盘丝洞青霞仙子传人");
		ob->set("class", "yaomo");
		return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
	return;
}
int accept_fight(object me)
{
	return 0;
}
string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("没用的东西！");
}
string ask_chuxian(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="盘丝洞") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"青霞仙子拢指一算：\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"有志气。\n"NOR;
	}
	return ("本仙子不明白。");
}
