// rewritten by snowcat on 4.12.1997
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����ǹ�", ({"maoxiu xingguan", "xingguan", "guan"}));
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("combat_exp", 1250000);
	set("daoxing", 1500000);

	set("per", 25);
	set_skill("dodge", 120);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("spells",160);
	set_skill("dao", 120);
	set_skill("dragonforce", 120);
	set_skill("dragon-steps", 120);
	set_skill("dragonfight", 120);
	map_skill("unarmed", "dragonfight");
	map_skill("dodge", "dragon-steps");
	map_skill("spells", "dao");
	set("max_sen",1600);
	set("max_gee",1600);
	set("max_gin",1600);
	set("force",1800);
	set("max_force",1800);
	set("max_mana",1800);
	set("force_factor",125);
	setup();

	carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
	int i;

	if (who->query("combat_exp") < 10000)
		return;
	if (who->query("obstacle/dudi") == "done")
		return;
	if (! who->query_temp("obstacle/dudi_killed"))
		return;
	i = random(800);
	who->add("obstacle/number",1);
	who->set("obstacle/dudi","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"����ɽ��ʥ�������ö���Ы�֣�");
	message("channel:chat",HIW"������ն���������ǹ�(Maoxiu xingguan)��"+who->query("name")+"��������ȡ���ڶ�ʮ�أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	who->save();
}

