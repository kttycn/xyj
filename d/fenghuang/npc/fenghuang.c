inherit NPC;
#include <ansi.h>;
inherit F_MASTER;

void create()
{
	set_name(HIC"��"HIR"��"NOR, ({ "feng huang", "feng" }));
	set("nickname", MAG "��˹���" NOR);
	set("long", 
		"����ԭ����ǵĹ�����\n"
		"������"HIW"���������ܣ������ƻã��Ѳ����Ƿ�������.\n"NOR);
	set("gender", "Ů��");
	set("age", 22);
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 100);
	set("str", 50);
	set("int", 55);
	set("con", 50);

	set("max_kee", 5000);
	set("max_gin", 1000);
	set("max_sen", 5000);
	set("force", 8000);
	set("max_force", 4000);
	set("force_factor", 250);
	set("max_mana", 4000);
	set("mana", 8000);
	set("mana_factor", 250);
	set("daoxing", 10000000);
	set("combat_exp", 10000000);
	set("score", 0);

	set_skill("force", 280);
	set_skill("wuzu-xinfa", 260);
	set_skill("yufeng-shu", 250);
	set_skill("dodge", 270);
	set_skill("fenghuang-shenfa", 270);
	set_skill("spells", 240);
	set_skill("parry", 280);
	set_skill("literate", 250);
	set_skill("unarmed",300);
	set_skill("tenglong-finger",300);
	set_skill("jile-dao", 280);
	set_skill("blade", 280);
	map_skill("force", "wuzu-xinfa");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("unarmed", "tenglong-finger");
	map_skill("parry", "tenglong-finger");
	map_skill("spells","yufeng-shu");
	map_skill("blade","jile-dao");

	create_family("�����", 1, "����");
	set("chat_chance", 1);
	set("chat_msg", ({
		HIC"��"HIR"��"NOR"��ȻһЦ��\n",
	}) );

	setup();
	carry_object("/d/fenghuang/obj/jia")->wear();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="�����") {
		if ( (int)ob->query("combat_exp") < 1000000 ) {
		  	command("say ������л����������ҵ��з���������\n");
			return;
		}
		if( (int)ob->query("betray/phoenix")) {
			command("say ��λ" + RANK_D->query_respect(ob) + "���鷴���޳����Ҳ�ԭ����Ϊͽ��\n");
			command("sigh");
			return;
		}
		if( (int)ob->query_skill("wuzu-xinfa", 1) < 200 ) {
			command("say ��λ" + RANK_D->query_respect(ob) + "��������ķ����������,�㻹���Ҹ� λ������������!\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say �ܺã��Ҿ��������ˣ�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
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
		ob->set("title", HIY"��˳ǹ�������˧"NOR);
	}
	return 0;
}
