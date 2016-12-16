//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����ɹ�",({"chi meng","dream", "fairy"}));
	set("long",
"�����Խ�����ɹ�Ҳ�����ܽ���֮л��������Ե�߶�֮��\n");
	set("title", "�Խ����");
	set("gender", "Ů��");
	set("age", 18);
	set("class", "xian");
	set("attitude", "friendly");
	set("rank_info/respect", "�ɹ�");
	set("per", 30);
	set("int", 30);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("max_sen", 1000);

	set("force", 8000);
	set("max_force", 4000);
	set("force_factor", 150);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 140);
	set("combat_exp", 1000000);
	set("daoxing", 500000);


	set("eff_dx", 100000);
	set("nkgain", 300);

	set_skill("literate", 190);
	set_skill("unarmed", 180);
	set_skill("dodge", 200);
	set_skill("force", 220);
	set_skill("parry", 220);
	set_skill("whip", 280);
	set_skill("unarmed", 180);
	set_skill("spells", 220);
	set_skill("baihua-zhang", 220);
	set_skill("moonshentong",240);
	set_skill("jueqing-whip", 280);
	set_skill("moonforce", 220);
	set_skill("moondance", 200);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("whip", "jueqing-whip");
	map_skill("parry", "jueqing-whip");
	map_skill("dodge", "moondance");

	create_family("�¹�", 2, "����");
	setup();

	carry_object("/d/obj/cloth/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("title")=="�㺮������")
	{
		command("jump");
		command("say ��Ȼ���Ž��Ը������ѧϰ,�Һܸ���!\n");
		command("recruit " + ob->query("id") );
		return;
	}
	if ( !((string)ob->query("gender")=="Ů��")){
		command("shake");
		command("say �����¹�ֻ��Ůͽ����λ" +
		RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
		return ;
	}
	if (random(this_player()->query_kar()) < 20 || this_player()->query("mark/moon_chimeng")){
		this_player()->set("mark/moon_chimeng", 1);
		command("shake");
		command("say ������Ե����������߾Ͱɡ�\n");
		return ;
	}
	else{
		command("pat "+ob->query("id"));
		command("say ��Ȼ" + RANK_D->query_respect(ob) +
"������Ե���Ҿ��������ˡ�\n");
		command("recruit " + ob->query("id") );
		return ;
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}
