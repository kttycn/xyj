//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
//by yushu�޸�
inherit NPC;
void create()
{
        set_name("��ͯ", ({ "jian tong", "tong" }));
        set("title", "��ɽ����");
        set("gender", "����");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 500);
        set("max_sen", 500);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 500);

        set_skill("force", 30);
        set_skill("zixia-shengong", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_skill("unarmed", 30);
        set_skill("spells", 30);
        set_skill("hunyuan-zhang", 30);
        set_skill("yujianshu", 30);
        set_skill("seven-steps", 30);    
        set_skill("taoism",30);

        map_skill("dodge", "seven-steps");
        map_skill("spells", "taoism");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "hunyuan-zhang");

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}