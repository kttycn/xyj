// guanjia.c
// 9-2-97 pickle
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string expell_me(object me);
void create()
{
	set_name("田鼠精", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
	set("gender", "女性");
	set("age", 23);
	set("long",
"她就是无底洞的大管家。想当年她和玉鼠一齐修仙成了人形，\n"
"但因资质太差，成正果终究是无望。照顾着当年的交情，玉鼠\n"
"安排她做了这洞的管家。\n");
	set("title", "大管家");
	set("cor", 25);
	set("combat_exp", 200000);
	set("daoxing", 400000);

	set("attitude", "heroic");
	create_family("陷空山无底洞", 2, "弟子");
	set_skill("literate", 50);
	set_skill("unarmed", 90);
	set_skill("parry", 90);
	set_skill("spells", 90);	
	set_skill("sword", 90);	
	set_skill("qixiu-jian", 90);
	set_skill("yinfeng-zhua", 90);
	set_skill("lingfu-steps", 90);
	set_skill("dodge", 90);
	set_skill("force", 90);
	set_skill("yaofa", 90);
	set_skill("huntian-qigong", 90);
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "yinfeng-zhua");
	map_skill("spells", "yaofa");
	map_skill("sword", "qixiu-jian");
	map_skill("parry", "qixiu-jian");
	map_skill("dodge", "lingfu-steps");
	
	set("str", 30);
	set("per", 30);
	set("max_kee", 800);
	set("max_sen", 800);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 75);
	set("mana", 3000);
	set("max_mana", 1500);
	set("mana_factor", 76);
	set("inquiry", ([
		"叛门": (: expell_me :),
		"leave": (: expell_me :),
		"name": "本姑娘就是这无底洞的大总管！",
		"here": "你瞎了眼啦？这里就是鼎鼎大名的陷空山无底洞！",
		"rumors": "不知道！找别人问去。",
		"人肉包子": "你瞎了眼啦？本姑娘又不是厨子！",
		"职位": (: rank_me :),
	]) );	
	setup();
	carry_object("/d/obj/weapon/blade/blade.c")->wield();
	carry_object("/d/obj/cloth/yuanxiang")->wear();
	carry_object("/d/obj/cloth/nichang")->wear();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "万圣鼠王")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "陷空山无底洞"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", BLU"无底洞府"NOR+RED"◆"BLU"钻地鼠精"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", BLU"无底洞府"NOR+RED"◆"YEL"人肉厨子"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", BLU"无底洞府"NOR+RED"◆"RED"翻天鼠王"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", BLU"无底洞府"NOR+RED"◆"MAG"八臂蝠神"NOR);
		} else {
			me->set("nick", BLU"无底洞府"NOR+RED"◆"CYN"千翼蝠圣"NOR);
		}

		tell_object(me, "田鼠精对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"田鼠精对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

int attempt_apprentice(object me)
{
	string myname=RANK_D->query_rude(me);
	string myid=me->query("id");
	command("look "+myid);
	command("consider");
	if (me->query("combat_exp")+me->query("daoxing")>400000)
	{
		command("say "+myname+"来干什么？想来抢老娘的位子？\n");
		return 1;
	}
	if (me->query("wudidong/sell_reward")<1000)
	{
		command("say "+myname+"要想来无底洞，先提几颗人头来孝敬我！\n");
		return 1;
	}
	command("grin");
	command("say 老娘最爱吃人肉包子了。"+myname+"别忘了多给厨房弄点原料！");
	command("recruit "+myid);
	return 1;
}
int prevent_learn(object me, string skill)
{
	string myname=RANK_D->query_rude(me);

}
string expell_me(object me)
{
	me=this_player();

	if((string)me->query("family/family_name")=="陷空山无底洞")
	{
		me->set_temp("wudidong/betray", 1);
		return ("什么？想要离开？那你就别怪老娘惩罚！(jieshou)\n");
	}
	return ("你是哪里来的！滚！\n");
}
void init()
{
		add_action("do_accept", "jieshou");
}
int do_accept(string arg)
{
		object me=this_player();
		if (arg) return notify_fail("你要干什么？\n");
		if (!me->query_temp("wudidong/betray")) return notify_fail("你要接受什么？\n");
		message_vision("$N道：不错，我要离开无底洞这耗子窝！\n", me);
		message_vision("田鼠精气疯了，既是如此，你便滚出无底洞！\n", this_player());
		me->add("betray/count", 1);
		me->add("betray/wudidong", 1);
		if (me->query_skill("yaofa"))
				me->delete_skill("yaofa");
		if (me->query_skill("huntian-qigong"))
				me->delete_skill("huntian-qigong");
		if (me->query_skill("qixiu-jian"))
				me->delete_skill("qixiu-jian");
		me->delete("family");
		me->delete("class");
		me->delete("faith");
		me->delete("family_wp");
		me->set("title", "普通百姓");
		me->set("combat_exp", me->query("combat_exp")*80/100);
		me->set("daoxing", me->query("daoxing")*80/100);
		if( (int)me->query("score") < 1000 )
			me->set("score", 0);
		else
			me->add("score", -1000 );
		me->save();
		message_vision("田鼠精一脚向$N踢去，$N如同一束稻草向东飞去。。。\n", this_player());
		this_player()->move("/d/city/kezhan");
		tell_room( environment(this_player()),"房梁上噗噗嗦嗦几声响，掉下个人来！\n", ({this_player()}));
		this_player()->unconcious();		
		return 1;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob))
	{
		ob->set("class", "yaomo");
	}
}
