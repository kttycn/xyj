inherit NPC;
#include <ansi.h>
void create()
{
	set_name("����", ({"yao guai", "guai"}));
	set("long", "�������ﱻ���ŵ����֡�\n");
	set("age", 32);
	set("attitude", "aggressive");
	set("str", 30);
	set("int", 30);
	set("per", 10);
	set("con", 30);
	set("combat_exp", 1500000+random(100000));
	set("max_kee", 3000+random(2000));
	set("max_sen", 3000+random(2000));
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100+random(50));
	set("max_mana", 2000);
	set("mana", 4000);
	set("mana_factor", 100+random(50));
	set_skill("ningxue-force", 150+random(60));
	set_skill("bainiao-jian", 150+random(60));
	set_skill("dodge", 150+random(60));
	set_skill("literate", 150+random(60));
	set_skill("sword", 150+random(60));
	set_skill("force", 150+random(60));
	set_skill("parry", 150+random(60));
	set_skill("spells", 150+random(60));
	set_skill("dengxian-dafa", 150+random(60));
	set_skill("xiaoyaoyou", 150+random(60));
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "bainiao-jian");
	map_skill("sword", "bainiao-jian");
	map_skill("force", "ningxue-force");
	map_skill("spells", "dengxian-dafa");
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "sword", "chaofeng" :),
		(: cast_spell, "juanbi" :),
	}) );
	setup();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}
void die()
{
	object ob;
	ob = query_temp("last_damage_from");
	ob->add("daoxing",1000);
	ob->add("combat_exp",1000);
	ob->add("potential",200);
	message("system",HIC"��"HIW"��������Ѷ"HIC"��"HIY+ob->query("name")+HIG"ɱ��[1;37m������[1;32m������֣��ܵ�������[2;37;0m\n"NOR,users());    
	tell_object (ob,"��Ӯ����"+COMBAT_D->chinese_daoxing(1000)+"���С�"+
	chinese_number(100)+"����ѧ"+chinese_number(200)+"��Ǳ�ܣ�\n");

	::die();
}