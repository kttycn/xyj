//created 5-20-97 pickle

#include <ansi.h> 
inherit NPC;

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

	set_skill("spear", 200);
	set_skill("force", 190);
	set_skill("dodge", 180);
	set_skill("literate", 180);
	set_skill("parry", 160);
	set_skill("unarmed", 180);
	set_skill("wuyue-spear", 200);
	set_skill("spells", 200);
	set_skill("pingtian-dafa", 200);
	set_skill("moshenbu", 180);
	set_skill("huomoforce", 190);
	set_skill("moyun-shou", 180);

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
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "spear", "buhui" :),
		(: perform_action, "unarmed", "zhangxinlei" :)
	}) );
	create_family("火云洞", 1, "蓝");
	setup();
 
	carry_object("/d/obj/weapon/spear/huaji2")->wield();
	carry_object("/d/city/obj/xjdan");
	carry_object("/d/obj/armor/jinjia")->wear();
}
 
