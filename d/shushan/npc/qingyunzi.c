//qing yunzi-yushu 2000.10.24
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"qing yunzi", "yunzi", "zi"}));
	set("title", "��ɽ�������µ���");   
	set("long", "��ɽ�������µ��ӣ���������ң������������˼��޷���\n");
	set("gender", "Ů��");
	set("age", 32);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("str", 30);
	set("int", 30);
	set("per", 24);
	set("con", 30);
	set("combat_exp", 500000);
	set("daoxing", 500000);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("force", 3600);
	set("max_force", 1800);
	set("force_factor", 90);
	set("max_mana", 1800);
	set("mana", 3600);
	set("mana_factor", 90);
	set_skill("zixia-shengong", 120);
	set_skill("yiruwhip", 150);
	set_skill("dodge", 120);
	set_skill("literate", 120);
	set_skill("whip", 150);
	set_skill("force", 120);
	set_skill("parry", 150);
	set_skill("spells", 120);
	set_skill("taoism", 120);
	set_skill("seven-steps", 120);
	set_skill("unarmed", 120);
	set_skill("hunyuan-zhang", 120);
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("dodge", "seven-steps");
	map_skill("parry", "yiruwhip");
	map_skill("whip", "yiruwhip");
	map_skill("force", "zixia-shengong");
	map_skill("spells", "taoism");
	set("inquiry", ([
	]) );  	
	create_family("��ɽ����", 3, "����");
	setup();
	carry_object("d/obj/cloth/pink_cloth")->wear();
	carry_object("d/obj/weapon/whip/whip")->wield();
}

void attempt_apprentice(object ob)
{	
	ob=this_player();
	if( (string)ob->query("family/family_name")=="��ɽ����")
	{
		if ((int)ob->query("daoxing") < 100000 ) {
  			command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ�����С�\n");
			return;
		}
		if( (int)ob->query_skill("taoism", 1) < 80 ) {
			command("say ��λ" + RANK_D->query_respect(ob) + "�����ʦ�ɷ����������,�㻹�����ɶ��������Ű�!\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "��ɽ���ɵ��Ĵ�����");
	}
	return 0;
}
