#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "huang xiang", "huang" }));
	set("nickname", HIW "��������" NOR);
	set("age", 25);
	set("title", HIR "��������" NOR);
	set("gender", "����");
	set("long", "�����������״����ӣ��Ʒ��˵ã��������ˣ��˳�����������\n");
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 22);
	set("str", 32);
	set("int", 25);
	set("con", 30);


	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 1000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 3000);
	set("mana_factor", 90);
	set("daoxing", 2000000);
	set("combat_exp", 800000);
	set("score", -5000);

	set_skill("literate", 100);
	set_skill("unarmed",140);
	set_skill("dodge", 110);
	set_skill("parry", 130);
	set_skill("force", 140);
	set_skill("wuzu-xinfa", 140);
	set_skill("fenghuang-shenfa", 140);
	set_skill("tenglong-finger",140);
	set_skill("spells", 120);
	set_skill("yufeng-shu", 120);
	map_skill("spells", "yufeng-shu");
	map_skill("unarmed","tenglong-finger");
	map_skill("parry", "tenglong-finger");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 80);

	create_family("�����",3,"��");
	setup();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "�����")
	{
		message_vision("�������$N���ͷ��΢΢Ц��Ц��\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	ob = this_player();
	if (!(int)this_player()->query("bmark/��ҵ��"))
		command("say �㻹��ȥ��˾�Уȥ����һ�°ɡ�\n");
	else
	{
		command("say �ðɣ��������㡣\n");
		command("recruit "+ob->query("id"));
		return;
	}
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", HIC"��˳ǹ�������У"NOR);
	}
	return 0;
}
