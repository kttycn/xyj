//npc by yushu 2000.11
inherit NPC;
void create()
{
        set_name("��ɽ����", ({"di zi"}));
        set("long","������ɽ���ɵĵ��ӡ�\n");
        set("title", "��ɽ���ɵ���������");
	 if(random(10)<7)
	    set("gender", "����" );
	  else
	    set("gender", "Ů��" );
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
        set_skill("force", 120);
        set_skill("seven-steps",120);
        set_skill("sword", 120);
        set_skill("dodge", 120);
        set_skill("yujianshu",120);
        set_skill("parry", 120);
        set_skill("spells", 120);
        set_skill("zixia-shengong", 120);
        set_skill("taoism",120);
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
