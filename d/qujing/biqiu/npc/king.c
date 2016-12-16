#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({"guo wang", "wang", "king"}));
	set("long", "������Ĺ������������ۣ�ͷ������ڡ�\n");
	set("title", "�����");
	set("gender", "����");
	set("age", 56);
	set("per", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("combat_exp", 200000);
	set("daoxing", 100000);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set("max_gin",800);
	set("max_kee",800);
	set("max_sen",800);
	set("max_force",1000);
	set("max_mana",1000);
	set("force_factor",120);
	set("eff_dx",15000);
	set("nkgain",90);

	setup();
	carry_object("/d/obj/cloth/longpao")->wear();
}

void announce_success (object who)
{
	int i;

	if (who->query("combat_exp") < 10000)
		return;
	if (who->query("obstacle/biqiu") == "done")
		return;
	if (who->query_temp("obstacle/biqiu_xiaoer") < 2 ||
			who->query_temp("obstacle/biqiu_zuochan") < 17 ||
			who->query_temp("obstacle/biqiu_hou") < 1 ||
			who->query_temp("obstacle/biqiu_guozhang") < 1)
		return;
	i = random(700);
	who->add("obstacle/number",1);
	who->set("obstacle/biqiu","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"����������޹�Сͯ�廪���η�����");
	message("channel:chat",HIW"������ն�����ϼ�����(Nanji xianweng)��"+who->query("name")+"��������ȡ���ڶ�ʮ�˹أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	who->save();
}

