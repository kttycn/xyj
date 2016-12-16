// by happ@YSZZ

inherit NPC;
string ask_cloth();
#include <ansi.h>

void create()
{
	set_name(HIM"�ŵ���"NOR, ({ "athena", "yadianna", "shen" }));
	set("long", @LONG
������˵�е����ƺ��׵�������ߣ����Ů�񣬺�ƽ�Ͷ��ıӻ��ߡ�
�ŵ����������ս�ۣ��ֳֳ�ǹ�����ƣ�ͷ��ս����
LONG);
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "peaceful");
	set("per",100);//means no rong-mao description.

	set("max_force", 7500);
	set("force", 15000);
	set("force_factor", 375);
	set("mana", 15000);
	set("max_mana", 7500);
	set("mana_factor", 375);
	set("max_kee", 20000);
	set("max_gin", 20000);
	set("max_sen", 20000);
	set("combat_exp", 12500000);
	set("daoxing", 12500000);

	set_skill("spells", 501);
	set_skill("buddhism", 501);
	set_skill("unarmed", 501);
	set_skill("tenglong-finger", 501);
	set_skill("dodge", 501);
	set_skill("lotusmove", 501);
	set_skill("force", 501);
	set_skill("lotusforce", 501);
	set_skill("staff", 501);
	set_skill("parry", 501);
	set_skill("lunhui-zhang", 501);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "tenglong-finger");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");

	set("chat_chance_combat", 90);
	set("inquiry",([
		"�ƽ�ʥ��": (: ask_cloth:)
	]));

	setup();
	carry_object("/d/12gong/obj/armor")->wear();
	carry_object("/d/12gong/obj/cloth")->wear();
	carry_object("/d/12gong/obj/pifeng")->wear();
	carry_object("/d/12gong/obj/shield")->wear();
	carry_object("/d/12gong/obj/stick")->wield();
}

string ask_cloth()
{
	object ob = this_object();
	object me = this_player();
	object cloth;
	if( me->query("12gong/number") >= 12 && !me->query("12gong/all") )
	{
		command_function("chat "HIY+me->name()+"����ĥ�ѣ����ڵõ��˻ƽ�ʥ�ף�");
		me->set("12gong/all",1);
		cloth=new("/d/12gong/obj/gold_cloth.c");
		cloth->move(me);
		me->add("daoxing",300000);
		me->add("combat_exp",300000);
		me->add("potential",30000);
		return "��õ���300�����,30����ѧ,3��Ǳ��,�ƽ�ʥ��һ��!\n
���Ҫע����,���������,�������Լ���ʥ�¸�(drop)��,�ɱ����������Ҫʥ��!";
	}
	return "Ҫ���˻���Ҫʲô?";
}
