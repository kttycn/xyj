// kid.c

inherit NPC;

int ask_faith();

void create()
{
	set_name("燕赤霞",({ "swallow jiashen","god" }) );
	set("gender", "男性" );
	set("race","天神");
	set("long",
		"咦？这个燕赤霞怎么和我们的巫师长得一模一样，呵呵...\n"
		"他正在那里处理一些问题，你若是曾做过门派任务，可以问他关于faith或是忠诚的事，\n"
		"他会把你原来的数据修改为现在延用的方式。\n"
		"不过你要是不愿意让他改，那他也就乐得清闲了。\n" );
	set("age", 21);
	set("kar",110);
	set("str",30);
	set("cps",25);
	set("int",40);
	set("cor",19);
	set("con",42);
	set("spi",40);
	set("per",30);
	set("combat_exp",3012688);
	set("daoxing", 3157343);
	set("force",12000);
	set("max_force",6000);
	set("mana",6000);
	set("max_mana",3000);
	set("force_factor",300);
	set("mana_factor",300);
	set("degree","辅政王");
	set("xuewei","圣人");
	set("eff_gin",740);
	set("eff_kee",12576);
	set("eff_sen",12640);
	set("party/rank","人·神·鬼 三界总盟主");
	set("party/obstacle","斗战胜佛");
	set("party/dntg","齐天大圣");
	set("title","蜀山剑圣传人");
	set("gender","男性");
	
	set_skill("literate",201);
	set_skill("hunyuan-zhang",401);
	set_skill("zixia-shengong",401);
	set_skill("taoism",401);
	set_skill("canxin-jian",450);
	set_skill("parry",401);
	set_skill("sword",401);
	set_skill("dodge",401);
	set_skill("unarmed",401);
	set_skill("yujianshu",400);
	set_skill("spells",401);
	set_skill("seven-steps",401);
	set_skill("force",401);

	map_skill("dodge","seven-steps");
	map_skill("unarmed","hunyuan-zhang");
	map_skill("spells","taoism");
	map_skill("parry","canxin-jian");
	map_skill("sword","canxin-jian");
	map_skill("force","zixia-shengong");

	set("attitude", "peaceful");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "jianshen" :),
		(: perform_action, "sword", "xiangsi" :),
	}) );
	set("inquiry", ([
		"faith" : (: ask_faith :),
		"忠诚" : (: ask_faith :),
	]));

	setup();

	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

int ask_faith()
{
	object who=this_player();
	int faith;

	
	if(faith = who->query(who->query("class")+"_faith") )
	{
		command("say 好啊，让我看看。\n");
		printf("你原来的门派忠诚度是：%d\n",faith);
		command("say 好，我这就给你改。");
		who->set("faith",faith);
		who->delete(who->query("class")+"_faith");
		command("say 好了！放心地去吧。");
		return 1;
	}
	return notify_fail("你并没有做任何表示你忠于你的师门的事呀。\n");
}