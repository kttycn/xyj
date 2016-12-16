// By canoe 2001.03.25
#include <ansi.h>

inherit __DIR__"troops.c";
	
void create()
{
	set_name("���", ({ "yang jian","yang" }));
	set("title", HIG"֯Ů�ı��ֵ�"NOR);
	create_family("����ɽ���Ƕ�", 1, "����");
	set("class", "xian");
	set("long", "һλ����ݰ׵������ꡣ\n");
	set("gender", "����");
	set("age", 26);
	set("attitude", "friendly");
	set("rank_info/respect", "����");
	set("rank_info/rude", "��ȮС��");
	set("per", 40);
	set("str", 30);
	set("cor", 40);
	set("con", 40);
	set("int", 40);
	set("spi", 40);
	set("cps", 40);
	set("kar", 40);
	set("max_kee", 3000);
	set("max_sen", 3000);
	set("force", 3600);
	set("max_force", 4000);
	set("force_factor", 100);
	set("max_mana", 3000);
	set("mana", 5000);
	set("mana_factor", 120);
	set("combat_exp", 1500000);
	set("daoxing", 2000000);
	set_skill("literate", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	set_skill("stick", 150);
	set_skill("spells", 200);
	set_skill("dao", 180);
	set_skill("puti-zhi", 150);
	set_skill("wuxiangforce", 180);
	set_skill("force", 200);
	set_skill("qianjun-bang", 180);
	set_skill("jindouyun", 180);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
		(: cast_spell, "thunder" :)
	}) );
	setup();

	carry_object("/d/obj/cloth/taijicloth")->wear();
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/meishan/npc/obj/spear")->wield();
}
