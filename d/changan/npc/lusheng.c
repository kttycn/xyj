inherit NPC;

void create() {
        set_name("¬��", ({"lu sheng","lu", "sheng"}));
   set("long","һ���ܻ����ε�������\n");
        set("gender", "����" );
        set("age", 25);
        set("daoxing", 100);
	set("combat_exp", 200);
        set("attitude", "peaceful");
        set_skill("unarmed", 5);
        set_skill("dodge", 5);
        set_skill("parry", 5);
        set_skill("literate", 5);
        set_skill("force", 5);   
        set_skill("sword", 3);
        set("per", 27);
        set("max_kee", 500);
        set("max_sen", 300);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/misc/pillow");
}
