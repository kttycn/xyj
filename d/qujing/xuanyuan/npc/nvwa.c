#include <ansi.h>
inherit NPC;
void announce_success (object who);

void create()
{
	set_name("Ů�", ({"nv wa", "master"}));
	set("gender", "Ů��");
	set("age", 60);
	set("class", "xian");
	set("attitude", "friendly");
	set("per", 30);
	set("int", 30);
	set("max_kee", 6800);
	set("max_gin", 1000);
	set("max_sen", 6800);
	set("force", 3000);
	set("max_force", 1500);
	set("force_factor", 150);
	set("max_mana", 1800);
	set("mana", 3600);
	set("mana_factor", 140);
	set("combat_exp", 6400000);
	set("daoxing", 6400000);

	set("eff_dx", 200000);
	set("nkgain", 350);

	set_skill("literate", 280);
	set_skill("unarmed", 230);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("parry", 280);
	set_skill("needle",290);
	set_skill("blade", 280);
	set_skill("spells", 280);
	set_skill("xuanhu-shentong", 260);
	set_skill("fox-hand", 260);
	set_skill("xuanhu-xinfa", 280);
	set_skill("xuanhu-blade", 280);
	set_skill("tianyi-zhen", 290);
	set_skill("huxing-steps", 270);
	map_skill("spells", "xuanhu-shentong");
	map_skill("unarmed", "fox-hand");
	map_skill("force", "xuanhu-xinfa");
	map_skill("blade", "xuanhu-blade");
	map_skill("needle","tianyi-zhen");
	map_skill("parry", "xuanhu-blade");
	map_skill("dodge", "huxing-steps");

	create_family("��ԯ��Ĺ", 1, "��ʦ");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/xuanyuan/obj/needle")->wield();
}

void announce_success (object who)
{
	int i;
	object wang;

	if (who->query("combat_exp") < 10000)
		return;
	if (who->query("obstacle/xuanyuan") == "done")
		return;
	if(!who->query_temp("obstacle/daji_killed"))
		return;
	if(! who->query_temp("can_in") )
		return;
	if(! wang = present("zhou wang",environment(who) ) )
		return ;

	i = random(600);
	who->add("obstacle/number",1);
	who->set("obstacle/xuanyuan","done");
	who->add("daoxing",i+4000);
	who->delete_temp("gumupass");
	who->add("score", 10);

	command("chat "+who->query("name")+"��ԯĹ��������������");
	message("channel:chat",HIW"������ն����Ů�(Nv wa)��"+who->query("name")+"��������ȡ������ʮ�߹أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	destruct (this_object());
	destruct (wang);
	who->save();
	return;
}

