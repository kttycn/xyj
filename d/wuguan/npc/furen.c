inherit NPC;

void create()
{
        set_name("�����", ({ "zhu furen", "zhu", "furen" }));
        set("long", "����һ������Ů�ˣ������������溬΢Ц��\n");
        set("gender", "Ů��");
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

