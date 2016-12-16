#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("大师傅", ({ "da shifu", "shifu" }));
	set("long", "他是凤凰军校的大师傅，专门做饭的的，可以问他食物的事情。\n");
	set("gender", "男性");
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
		"用餐" : (: ask_me :),
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
		return "还没到时间，吃、吃、吃，你快吃成猪了。。。";
	}
	food = new("/d/fenghuang/food/hufan");
	food->move(me);
	message_vision("大师傅给$N一份自助餐。你细条慢理地吃了起来。\n",me);
	return "慢慢吃，小心别噎着。";
}
