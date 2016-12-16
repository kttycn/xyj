// heer.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
	set_name("�׶�", ({"he er", "er", "heer"}));
	set("gender", "����" );
	set("age", 20);
	set("per", 30);
	set("long", "��ɽ���ɵĵ��Ĵ����ӡ�\n");
	set("class", "swordsman");
	set("combat_exp", 120000);
	set("daoxing", 200000);
	set("attitude", "peaceful");
	create_family("��ɽ����", 4, "����");
	set_skill("dodge", 80);
	set_skill("seven-steps", 80);
	set_skill("parry", 80);
	set_skill("sword", 90);
	set_skill("yujianshu", 80);
	set_skill("force", 80);
	set_skill("zixia-shengong", 80);
	set_skill("literate", 90);
	set_skill("spells", 80);
	set_skill("taoism", 80);
	set_skill("unarmed", 80);
	set_skill("hunyuan-zhang", 80);
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("spells", "taoism");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
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
			command("say �����Լ�Ҫ�ݵģ��ɱ���Ұ�!��\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say �ã�����ɽ������һ���˲ű�������ɵø�ʦ��������\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
