//����ɽ���ɡ�dhxy-evil 2000.7.5
//yushu�޸� 2001.2
inherit NPC;
void create()
{
	set_name("����ң", ({ "li xiaoyao", "li", "xiaoyao" }));
	set("title","��ɽ�������ŵ���");
	set("long", "����ң��Ľ��ݣ�����Ũü���ۣ������Ѱ���\n");
	set("gender", "����");
	set("age", 18);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("per", 30);
	set("kee", 2800);
	set("max_kee", 2800);
	set("sen", 1600);
	set("max_sen", 1600);
	set("force", 4800);
	set("max_force", 2400);
	set("mana", 4800);
	set("max_mana", 2400);
	set("force_factor", 60);
	set("mana_factor", 60);
	set("combat_exp", 1800000);
	set("daoxing", 2500000);

	set_skill("force", 250);
	set_skill("dodge", 240);
	set_skill("unarmed", 230);
	set_skill("hunyuan-zhang", 230);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("canxin-jian", 270);
	set_skill("zixia-shengong", 240);
	set_skill("seven-steps",240);
	set_skill("literate",120);
	set_skill("taoism",250);
	map_skill("spells", "taoism");
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "seven-steps");
	map_skill("parry", "canxin-jian");
	map_skill("sword", "canxin-jian");

	setup();
	create_family("��ɽ����", 3, "����");
	carry_object("/obj/cloth")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="��ɽ����" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
			else command("say ʦ�ü�Ц�ˡ�\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
			else command("say ʦ��̫�����ˡ�\n");
		}
		else 
		{
			command("consider");
			command("say ��������ĳ���ķ���,������Ϊͽ!\n");
			command("recruit " + ob->query("id") );
		}
	}
	    else
	{
		command("say ��������ĳ���ķ���,������Ϊͽ!\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "��ɽ��������ң����");
	      }
	      return 0;
}
