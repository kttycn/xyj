#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�ϱ�ѩ", ({ "yan bixue", "yan" }));
	set("nickname", HIM "����˫ȫ" NOR);
	set("age", 25);
	set("title", HIR "���罫��" NOR);
	set("gender", "Ů��");
	set("long", "�����������״����ӣ��Ṧ�˵ã�����˫ȫ�ʵ������罫����\n");
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 40);
	set("str", 40);
	set("int", 25);
	set("con", 30);

	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 1000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 2000);
	set("mana", 4000);
	set("mana_factor", 100);
	set("daoxing", 4000000);
	set("combat_exp", 800000);
	set("score", -7000);

	set_skill("unarmed", 100);
	set_skill("literate", 120);
	set_skill("dodge", 140);
	set_skill("parry", 130);
	set_skill("sword", 130);
	set_skill("force", 120);
	set_skill("blade", 120);
	set_skill("spells", 140);
	set_skill("jile-dao", 120);
	set_skill("yufeng-shu", 140);
	set_skill("wuzu-xinfa", 120);
	set_skill("fenghuang-shenfa", 140);
	map_skill("spells", "yufeng-shu");
	map_skill("blade", "jile-dao");
	map_skill("parry", "jile-dao");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 80);

	create_family("�����",3,"��");
	set("chat_chance_combat", 10);
	setup();
	carry_object("/d/fenghuang/obj/blade")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "�����")
	     {
	       message_vision("�ϱ�ѩ����$N���ͷ��΢΢Ц��Ц��\n",ob);
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
