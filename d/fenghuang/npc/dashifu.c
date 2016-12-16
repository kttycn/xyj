#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("��ʦ��", ({ "da shifu", "shifu" }));
	set("long", "���Ƿ�˾�У�Ĵ�ʦ����ר�������ĵģ���������ʳ������顣\n");
	set("gender", "����");
	set("age", 41);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 26);
	set("str", 100);
	set("int", 28);
	set("con", 28);
	set("dex", 50);
	
	set("max_kee", 600);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);
	set("combat_exp", 1500000);
	set("score", 6000);
	set("inquiry", ([
		"�ò�" : (: ask_me :),
	]));

	setup();
	carry_object("/d/obj/weapon/blade/blade")->wield();
	carry_object("/d/obj/cloth/cloth")->wear();
}
string ask_me()
{
	object food, water;
	object me = this_player();
	if((int)me->query("food") >=(int)me->max_food_capacity()*90/100)
	{
		command("pat "+me->query("id"));
		return "��û��ʱ�䣬�ԡ��ԡ��ԣ����Գ����ˡ�����";
	}
	food = new("/d/fenghuang/food/hufan");
	food->move(me);
	message_vision("��ʦ����$Nһ�������͡���ϸ������س���������\n",me);
	return "�����ԣ�С�ı�ҭ�š�";
}
