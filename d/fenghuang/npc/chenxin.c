inherit NPC;
#include <ansi.h>;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "chen xin", "chen" }));
	set("nickname", MAG "�����޵�" NOR);
	set("long", 
		"�����Ƿ���ǵ��������\n"
		"���������١�\n");
	set("gender", "����");
	set("age", 56);
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 24);
	set("str", 50);
	set("int", 55);
	set("con", 50);
	
	set("max_kee", 3000);
	set("max_gin", 1000);
	set("max_sen", 3000);
	set("force", 6000);
	set("max_force", 4000);
	set("force_factor", 200);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 150);
	set("daoxing", 5000000);
	set("combat_exp", 6400000);
	set("score", -7000);

	set_skill("force", 200);
	set_skill("tenglong-finger", 200);
	set_skill("liedi-stick", 200);
	set_skill("stick", 190);
	set_skill("wuzu-xinfa", 200);
	set_skill("spells", 180);
	set_skill("yufeng-shu", 180);
	set_skill("jile-dao", 200);
	set_skill("dodge", 180);
	set_skill("fenghuang-shenfa", 180);
	set_skill("tenglong-finger", 200);
	set_skill("parry", 200);
	set_skill("literate", 180);
	set_skill("blade",200);
	set_skill("unarmed",200);
	set_skill("wudi-zhan",200);
	map_skill("force", "wuzu-xinfa");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("parry", "jile-dao");
	map_skill("stick", "liedi-stick");
	map_skill("unarmed", "tenglong-finger");
	map_skill("spells","yufeng-shu");
	map_skill("blade","jile-dao");

	create_family("�����", 2, "����");

	set("chat_chance", 1);
	set("chat_msg", ({
		"���Ű��ַŽ������\n",
		"�������������˵��Ҫһͳ���±����ĺ�������\n",
		"�������ϵĿ�����һ����\n",
	}) );

	setup();
	carry_object("/d/fenghuang/obj/key");
	carry_object("/d/fenghuang/obj/blade")->wield();
    carry_object("/d/fenghuang/obj/jia")->wear();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="�����") {
		if ( (int)ob->query("combat_exp") < 500000 ) {
		  	command("say ������л����������ҵ��з���������\n");
			return;
		}
		if( (int)ob->query_skill("wuzu-xinfa", 1) < 130 ) {
			command("say ��λ" + RANK_D->query_respect(ob) + "��������ķ����������,�㻹���Ҹ� λ������������!\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say �ðɣ��Ҿ��������ˡ�");
		command("say ϣ��������������һͳ���£�");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say ���Ǳ��ǵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", HIR"��˳ǹ���������"NOR);
	}
	return 0;
}
