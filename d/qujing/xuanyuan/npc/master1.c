// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("������", ({"lin meiniang", "lin"}));
	set("long",
"��������ԯ��Ĺ���ɳ�����ͽ��С����.\n");
	set("title",HIR"����"NOR );
	set("gender", "Ů��");
	set("age", 20);
	set("class", "huli");
	set("attitude", "friendly");
	set("per", 30);
	set("int", 30);
	set("max_kee", 500);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 20);
	set("max_mana", 300);
	set("mana", 300);
	set("mana_factor", 20);
	set("combat_exp", 200000);

	set("eff_dx", 70000);
	set("nkgain", 260);

	set_skill("literate", 20);
	set_skill("unarmed", 70);
	set_skill("dodge", 80);
	set_skill("needle",80);
	set_skill("tianyi-zhen",80);
	set_skill("force", 80);
	set_skill("xuanhu-shentong", 75);
	set_skill("xuanhu-xinfa",80);
	set_skill("fox-hand",70);
	set_skill("huxing-steps",80);
	set_skill("parry", 90);
	set_skill("spells", 90);
	map_skill("needle","tianyi-zhen");
	map_skill("dodge","huxing-steps");
	map_skill("force","xuanhu-xinfa");
	map_skill("unarmed","fox-hand");
	map_skill("parry","fox-hand");
	map_skill("spells","xuanhu-shentong");


	create_family("��ԯ��Ĺ", 3, "����");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/xuanyuan/obj/needle1")->wield();
}

void attempt_apprentice(object ob)
{
	if ( !((string)ob->query("gender")=="Ů��")){
		command("shake");
		command("say ������ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
		return;
	}

	command("pat "+ob->query("id"));
	command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ���������ǹ�Ĺ������\n");
	command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class","huli");
}
