//shushan2 by yushu@SHXY 2000.12 
inherit NPC;
void create()
{
       set_name("蜀山弟子", ({"shouwei dizi", "dizi"}));
       set("title", "禁地守卫");
       set("long","蜀山剑派的禁地守卫\n");
       set("gender", "男性");
       set("age", 28);
	set("str", 25);
       set("attitude", "aggressive");
       set_skill("sword",140);
       set_skill("parry",140);
	set_skill("dodge",140);
	set_skill("hunyuan-zhang",140);
       set_skill("unarmed",140);
       set_skill("force",140);
       set_skill("zixia-shengong",140);
       set_skill("spells",140);
       set_skill("taoism",140);
 	set_skill("yujianshu",140);
	set_skill("seven-steps",140);
	map_skill("dodge", "seven-steps");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("force", "zixia-shengong");
	map_skill("spells", "taoism");
       set("max_kee",1000);
	set("bellicosity", 5000);
       set("max_sen",1000);
       set("force",2000);
       set("max_force",1000);
       set("mana",2000);
       set("max_mana",1000);
       set("mana_factor", 100);
       set("force_factor", 100);
       set("combat_exp", 300000);
       set("daoxing", 200000); 
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
                (: perform_action, "sword", "wanjian" :),
                (: cast_spell, "fu" :),
}) );

       setup();
       carry_object("/d/obj/weapon/sword/qinghong")->wield();
       carry_object("/d/obj/armor/yinjia")->wear();
       add_money("silver", 50);
       }
       void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "蜀山弟子喝道：那里来的人，擅闯蜀山禁地，不想活了！\n");
}
