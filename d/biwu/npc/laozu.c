//����ɽ���ɡ�mhxy-yushu 2001/2
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("��������", ({"master jingxu","jingxu", "master"}));
	set("title",HIC"��ɽ���ɿ�ɽ��ʦ"NOR);
	set("gender", "����");
	set("age", 220);
	set("class", "swordsman");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "��ʦ��");
	set("per", 26);
	set("looking", "������󣬳�����Ʈ��˫��΢���������Բ�üֱָ���ҡ�");
	set("int", 30);
	set("max_kee", 5000);
	set("max_gin", 1000);
	set("max_sen", 5000);
	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 150);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 150);
	set("combat_exp", 3000000);
	set("daoxing", 8000000);
	set_skill("literate", 220);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 290);
	set_skill("hunyuan-zhang", 290); 
	set_skill("sword", 300);
	set_skill("yujianshu", 300);
	set_skill("spells", 300);
	set_skill("taoism", 300);
	set_skill("zixia-shengong", 300);
	set_skill("force", 300);
	set_skill("seven-steps", 300);
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("spells","taoism");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	map_skill("unarmed","hunyuan-zhang");
	set("shushan/jiushen_cast",1);
	set("shushan/wanjian_perform",1);
	set("shushan/duanshui_perform",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", 
	({
		(: cast_spell, "fu" :),
		(: perform_action, "sword", "fumo" :),
		(: perform_action, "sword", "wanjianjue" :),
		(: perform_action, "sword", "duanshui" :),
	}) );
	 create_family("��ɽ����", 1, "����");
	 setup();

	 carry_object("/d/obj/cloth/mangpao")->wear();
	 carry_object("/d/shushan/obj/shenxue")->wear();
	 carry_object("/d/obj/weapon/sword/changjian")->wield();
}

