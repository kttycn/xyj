inherit NPC;

void create()
{
        set_name("朱夫人", ({ "zhu furen", "zhu", "furen" }));
        set("long", "这是一个中年女人，容颜俏丽，面含微笑。\n");
        set("gender", "女性");
         set("age", 40);
        set("attitude","friendly");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("dodge", 80);
        set("combat_exp", 150000);
        set("max_kee", 500);
        set("max_shen", 400);
        set("force", 900);
        set("max_force", 900);
        setup();
        carry_object("/d/obj/cloth/cloth")->wear();
}

