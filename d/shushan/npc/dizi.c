//npc by yushu 2000.11
inherit NPC;
void create()
{
        set_name("男弟子", ({"di zi"}));
        set("long","他是蜀山剑派的弟子。\n");
        set("title", "蜀山剑派弟子");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "swordsman");
        set("age", 20);
        set("per", 23);
        set("max_kee", 400);
        set("max_sen", 400);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 40);
        set("max_mana", 500);
        set("mana", 900);
        set("mana_factor", 30);
        set("combat_exp", 80000);
        set("daoxing", 80000);
        set_skill("force", 40);
        set_skill("seven-steps", 40);
        set_skill("sword", 40);
        set_skill("dodge", 40);
        set_skill("yujianshu", 40);
        set_skill("parry", 40);
        set_skill("spells", 40);
        set_skill("zixia-shengong", 40);
        set_skill("taoism", 40);
        map_skill("spells", "taoism");
        map_skill("force", "zixia-shengong");
        map_skill("sword", "yujianshu");
        map_skill("dodge", "seven-steps");
        map_skill("parry","yujianshu");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
            (: perform_action, "sword", "fumo" :),

       }) );
            setup();
       carry_object("/obj/cloth")->wear();
       carry_object("/d/obj/weapon/sword/changjian")->wield();
            
}

�
