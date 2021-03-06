// by happ@YSZZ

inherit NPC;
string ask_cloth();
#include <ansi.h>

void create()
{
	set_name(HIM"雅典娜"NOR, ({ "athena", "yadianna", "shen" }));
	set("long", @LONG
　　传说中的乌云和雷电的主宰者，丰产女神，和平劳动的庇护者。
雅典的主神。她身穿战袍，手持长枪、盾牌，头戴战盔。
LONG);
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("per",100);//means no rong-mao description.

	set("max_force", 7500);
	set("force", 15000);
	set("force_factor", 375);
	set("mana", 15000);
	set("max_mana", 7500);
	set("mana_factor", 375);
	set("max_kee", 20000);
	set("max_gin", 20000);
	set("max_sen", 20000);
	set("combat_exp", 12500000);
	set("daoxing", 12500000);

	set_skill("spells", 501);
	set_skill("buddhism", 501);
	set_skill("unarmed", 501);
	set_skill("tenglong-finger", 501);
	set_skill("dodge", 501);
	set_skill("lotusmove", 501);
	set_skill("force", 501);
	set_skill("lotusforce", 501);
	set_skill("staff", 501);
	set_skill("parry", 501);
	set_skill("lunhui-zhang", 501);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "tenglong-finger");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");

	set("chat_chance_combat", 90);
	set("inquiry",([
		"黄金圣甲": (: ask_cloth:)
	]));

	setup();
	carry_object("/d/12gong/obj/armor")->wear();
	carry_object("/d/12gong/obj/cloth")->wear();
	carry_object("/d/12gong/obj/pifeng")->wear();
	carry_object("/d/12gong/obj/shield")->wear();
	carry_object("/d/12gong/obj/stick")->wield();
}

string ask_cloth()
{
	object ob = this_object();
	object me = this_player();
	object cloth;
	if( me->query("12gong/number") >= 12 && !me->query("12gong/all") )
	{
		command_function("chat "HIY+me->name()+"历尽磨难，终于得到了黄金圣甲！");
		me->set("12gong/all",1);
		cloth=new("/d/12gong/obj/gold_cloth.c");
		cloth->move(me);
		me->add("daoxing",300000);
		me->add("combat_exp",300000);
		me->add("potential",30000);
		return "你得到了300年道行,30万武学,3万潜能,黄金圣甲一件!\n
你可要注意了,如果你死了,或者你自己把圣衣给(drop)了,可别回来再找我要圣甲!";
	}
	return "要过了还来要什么?";
}
