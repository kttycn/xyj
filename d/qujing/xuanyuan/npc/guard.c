// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("Ů����", ({"guard"}));
	set("long",
"һ��槼��ĸ߼�����,�����������Ż�.���ݱ��ɵ��Ӵ���.\n");
	set("gender", "Ů��");
	set("age", 20);
	set("class", "yaomo");
	set("attitude", "friendly");
	set("per", 30);
	set("int", 30);
	set("max_kee", 800);
	set("max_gin", 500);
	set("max_sen", 800);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 20);
	set("max_mana", 300);
	set("mana", 300);
	set("mana_factor", 20);
	set("combat_exp", 500000);

	set("eff_dx", 70000);
	set("nkgain", 260);

	set_skill("literate", 20);
	set_skill("unarmed", 50);
	set_skill("dodge", 80);
	set_skill("needle",80);
	set_skill("tianyi-zhen",80);
	set_skill("force", 50);
	set_skill("xuanhu-shentong", 60);
	set_skill("xuanhu-xinfa",80);
	set_skill("fox-hand",60);
	set_skill("huxing-steps",80);
	set_skill("parry", 50);
	set_skill("spells", 50);
	map_skill("spells", "xuanhu-shentong");
	map_skill("force", "xuanhu-xinfa");
	map_skill("unarmed", "fox-hand");
	map_skill("needle", "tianyi-zhen");
	map_skill("dodge", "huxing-steps");

		
	create_family("��ԯĹ", 3, "����");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/xuanyuan/obj/needle1")->wield();
}
void init()
{
	add_action("do_answer", "answer");
}

int do_answer(string arg)
{
	if( !arg ) return notify_fail("��˵ʲô��\n");
	this_player()->set_temp("pending/jiangjun_answer", 0);
	message_vision("$N�����" + arg + "\n", this_player());
	if( arg== "�ΰ�" ) {
		command("haha");
		command("say ԭ���ǲΰ����������ѽ,��ӭ��ӭ��\n");
		this_player()->set_temp("pending/jiangjun_answer", 1);
	} else {
		command("say �㵽��Ҫ��ʲô��˵����ٹ�ȥ��\n");
	}
	return 1;
}
