// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
        set_name("��־��", ({"guang zhizi", "guang"}));
        set("gender", "����" );
        set("age", 43);
        set("long", "����ɽ���Ƕ��ڶ��������еĽܳ���������������书��\n��ǧ�����ϼ��гɾ͡�\n");
        set("combat_exp", 400000);
        set("attitude", "friendly");
        create_family("����ɽ���Ƕ�", 2, "��ͽ");
   set("int", 25);
   set("class", "taoist");

        set("eff_dx", 300000);
        set("nkgain", 300);

        set_skill("unarmed", 110);
        set_skill("dodge", 110);
        set_skill("parry", 110);
        set_skill("spells", 80);  
        set_skill("dao", 80);
        set_skill("literate", 110);
        set_skill("stick", 110);  
        set_skill("qianjun-bang", 110);
        set_skill("puti-zhi", 110);  
        set_skill("jindouyun", 110);
        set_skill("dodge", 110);
        set_skill("force", 110);   
        set_skill("wuxiangforce", 110);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
        set("str", 25);
        set("max_kee", 1500);
        set("max_gin", 1500);
        set("max_sen", 1500);
        set("force", 2000);
        set("max_force", 1500);
        set("force_factor", 40);
        set("mana", 2000);
        set("max_mana", 1000);
        set("mana_factor", 20);
        setup();
        carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}

void init()
{
	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
}
