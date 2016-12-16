
//	����֮�� ������
//	by happ@YSZZ 2000.4.15
//	/d/qujing/xuanyuan/npc/jiang.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("������", ({ "jiang ziya", "jiang" }));
	set("long", "�������Ǹ�����Ľ�̫����\n");
	set("gender", "����");
	set("age", 57);
	set("attitude", "heroism");
	set("str", 50);
	set("attitude","aggressive");
	set("max_kee", 1200);
	set("max_sen", 1200);
	set("force", 3000);
	set("max_force", 2000);
	set("force_factor", 60);
	set("max_mana", 2000);
	set("mana", 2000);
	set("mana_factor", 60);
	set("combat_exp", 1500000);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("force", 150);
	set_skill("spells", 150);
	set_skill("unarmed", 150);
	set_skill("staff", 150);
	set_skill("gouhunshu", 150);
	set_skill("tonsillit", 150);
	set_skill("ghost-steps", 150);
	set_skill("jienan-zhi", 150);
	set_skill("lunhui-zhang", 150);
	map_skill("unarmed", "jienan-zhi");
	map_skill("force", "tonsillit");
	map_skill("spells", "gouhunshu");
	map_skill("staff", "lunhui-zhang");
	setup();
	carry_object("/d/obj/cloth/gongpao")->wear();
	carry_object("/d/qujing/biqiu/obj/ring")->wear();
	carry_object("/d/qujing/biqiu/obj/neck")->wear();
	carry_object("/d/qujing/biqiu/obj/wrists")->wear();
}

void kill_ob (object ob)
{
	set_temp("my_killer",ob);
	::kill_ob(ob);
}

void die ()
{
	 object ob = query_temp("my_killer");
	 message_vision (HIR"\n��������$Nŭ������������ΪŰ���Ϸ�����Ǹ���һ״��\n"NOR,ob);
	 message_vision (HIR"ֻ�����������Ű׺���ʧ����ߡ�\n",ob);
	 message_vision (HIR"槼���Ц������������������ɣ������ܳԵ���������\n",ob);
	 tell_object(ob,"����һ�����ְ���ץ���ˡ�\n");
	 ob->move("/d/qujing/xuanyuan/dadian");
	 destruct(this_object());
}

void unconcious ()
{
	die ();
}
