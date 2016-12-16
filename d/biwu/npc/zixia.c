//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIM"��ϼ����"NOR, ({"zixia xianzi", "zixia", "xianzi","master"}));
	set("long", "��������˿���Ŀ�ɽ��ʦ,��˵���Ƿ����һ�õ�о��������޵���
��,����˼���½�ռ�˻���ɽһ������,��ɽ����,������ͽ��\n");
	set("title", HIB"��˿����"NOR);
	set("gender", "Ů��");
	set("age", 20);
	set("class","xian");
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("cor", 30);
	set("per", 40);
	set("max_kee", 4500);
	set("max_gin", 800);
	set("max_sen", 4500);
	set("force", 5000);
	set("max_force", 3000);
	set("force_factor", 125);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 250);
	set("combat_exp", 3000000);
	set("daoxing", 4000000);
	set_skill("literate", 180);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("spells", 170);
	set_skill("whip", 180);
	set_skill("pansi-dafa", 170);
	set_skill("lanhua-shou", 180);
	set_skill("jiuyin-xinjing", 180);
	set_skill("chixin-jian", 180);
	set_skill("qin", 180);
	set_skill("yueying-wubu", 180);
	set_skill("yinsuo-jinling", 200);
	map_skill("spells", "pansi-dafa");
	map_skill("unarmed", "lanhua-shou");
	map_skill("force", "jiuyin-xinjing");
	map_skill("sword", "chixin-jian");
	map_skill("parry", "yinsuo-jinling");
	map_skill("dodge", "yueying-wubu");
	map_skill("whip", "yinsuo-jinling");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", 
	({
		(: perform_action, "sword", "hongyan" :),
		(: perform_action, "whip", "tian" :),
		(: cast_spell, "wuzhishan" :),
		(: cast_spell, "ziqi" :),
	}) );
	create_family("��˿��", 1, "��");
	setup();

	carry_object("/d/obj/cloth/tianyi.c")->wear();
	carry_object("/d/pansi/obj/ziqing.c")->wield();
	carry_object("/d/ourhome/obj/shoes")->wear();
}

