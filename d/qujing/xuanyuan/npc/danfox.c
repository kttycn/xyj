// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit NPC;
string ask_dan();
#include <ansi.h>
void create()
{
	set_name("����С����", ({"fox"}));
	set("long",
"һ��ר�Ÿ���������С����.\n");
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
	set("inquiry", ([
		"����": (: ask_dan :),
	]));

	create_family("��ԯ��Ĺ", 3, "����");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/xuanyuan/obj/needle1")->wield();
	carry_object("/d/qujing/xuanyuan/obj/tool");
}
void init()
{
	object me = this_object();
	remove_call_out("des");
	call_out("des",20,me);
}
void des(object me)
{
	destruct(me);
}
string ask_dan()
{
	object me=this_player();
	if((string)me->query("family/family_name")!="��ԯ��Ĺ")
		return ("�����Ǳ������ˡ�");
	if(me->query("faith")>200||me->query("combat_exp")>100000)
		return ("���Ǳ��Ŵ�������֮�ˣ����������������������أ�");
	me->set("gm/dan",1);
	return ("�õģ��������ȥ�����ɡ���zao dan��\n");
}
