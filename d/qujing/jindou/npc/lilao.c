// rewritten by snowcat on 4.12.1997
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���Ͼ�", ({"li laojun", "li", "laojun"}));
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("combat_exp", 1250000);
	set("daoxing", 10000000);

	set("per", 25);
	set_skill("dodge", 180);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("spells",180);
	set_skill("dao", 180);
	set_skill("puti-zhi", 180);
	set_skill("jindouyun", 180);
	map_skill("unarmed", "puti-zhi");
	map_skill("dodge", "jindouyun");
	map_skill("spells", "dao");
	set("max_sen",1800);
	set("max_gee",1800);
	set("max_gin",1800);
	set("force",1800);
	set("max_force",1800);
	set("max_mana",1800);
	set("force_factor",125);
	setup();

	carry_object("/d/obj/cloth/changpao")->wear();
}

void announce_success (object who)
{
	int i;

	if (who->query("combat_exp") < 10000)
		return;
	if (who->query("obstacle/jindou") == "done")
		return;
	if (! who->query_temp("obstacle/jindou_killed"))
		return;
	i = random(700);
	who->add("obstacle/number",1);
	who->set("obstacle/jindou","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"��ɽ��ս��������Ϸ��ջ���ţ��");
	message("channel:chat",HIW"������ն�������Ͼ�(Li laojun)��"+who->query("name")+"��������ȡ����ʮ�˹أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	who->save();
}