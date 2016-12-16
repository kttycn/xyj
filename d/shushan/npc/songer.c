// songer.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
	set_name("�ɶ�", ({"song er", "er", "songer"}));
	set("gender", "����" );
	set("age", 22);
	set("per", 30);
	set("long", "��ɽ���ɵĵ��Ĵ����ӡ�\n");
	set("class", "swordsman");
	set("combat_exp", 120000);
	set("daoxing", 200000);
	set("attitude", "peaceful");
	create_family("��ɽ����", 4, "����");
	set_skill("unarmed", 60);
	set_skill("dodge", 80);
	set_skill("seven-steps", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("yujianshu", 80);
	set_skill("hunyuan-zhang", 60);
	set_skill("force", 70);
	set_skill("zixia-shengong", 70);
	set_skill("literate", 80);
	set_skill("spells", 80);
	set_skill("taoism", 80);
	map_skill("spells", "taoism");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	map_skill("unarmed", "hunyuan-zhang");
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
			command("snicker");
			command("say �����ʺ�һ������!\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say �ã�����ɽ����һ���˲ű�������ɵø�ʦ��������\n");
		command("recruit " + ob->query("id") );
	}

	return;
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting()
	&& !ob->query("env/invisibility") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "�ɶ������˵������λ" + RANK_D->query_respect(ob) + "����ӭ������ɽ��\n");
}
