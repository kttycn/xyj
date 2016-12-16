//modified by sgzl for dntg/donghai quest
#include <skill.h>
inherit NPC;

void create()
{
	set_name("����", ({"ao guang", "ao","guang","longwang","wang"}));
	set("long","�����Ƕ��������������ֱֵܷ��ƹܶ��������ϣ����ĺ���
������ˮ���ڶ࣬���ƺƴ�ٲȻ����һ����\n");
	set("gender", "����");
	set("age", 66);
	set("title", "��������");
	set("class","dragon");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 20);
	set("str", 30);
	set("max_kee", 3000);
	set("max_gin", 400);
	set("max_sen", 1500);
	set("force", 3000);
	set("max_force", 1500);
	set("force_factor", 120);
	set("max_mana", 800);
	set("mana", 1600);
	set("mana_factor", 40);
	set("combat_exp", 1200000);
	set("daoxing", 1500000);

	set_skill("huntian-hammer", 180);
	set_skill("hammer", 180);
	set_skill("literate", 120);
	set_skill("unarmed", 200);
	set_skill("dodge", 180);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("fork", 180);
	set_skill("spells", 170);
	set_skill("seashentong", 170);
	set_skill("dragonfight", 200);
	set_skill("dragonforce", 180);
	set_skill("dragon-cha", 180);
	set_skill("dragon-steps", 180);

	map_skill("hammer", "huntian-hammer");
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "dragon-cha");
	map_skill("parry", "dragon-cha");
	map_skill("dodge", "dragon-steps");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: cast_spell, "freez" :),
		(: cast_spell, "water" :),
		(: cast_spell, "dragonfire" :),
		(: exert_function, "roar" :),
		(: perform_action, "hammer", "break" :),
		(: perform_action, "unarmed", "sheshen" :),
		(: perform_action, "unarmed", "leidong" :)
	}) );
	create_family("��������", 1, "ˮ��");
	set_temp("apply/armor",50);
	set_temp("apply/damage",25);
	setup();

	carry_object("/d/sea/obj/longpao")->wear();
}
