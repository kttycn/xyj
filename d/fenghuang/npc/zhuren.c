#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("乐主任", ({ "le zhuren", "le" }));
	set("title", "凤凰军校接待员");
	set("long", "
他是凤凰军校的主任，专门接待新生的，可以问他入学的事情。\n");
	set("gender", "男性");

	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "主任");
	set("per", 24);
	set("str", 22);
	set("int", 28);
	set("con", 30);

	set("max_kee", 800);
	set("max_gin", 300);
	set("max_sen", 800);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 25);
	set("combat_exp", 420000);
	set("score", 6000);

	set("inquiry", ([
		"入学" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/d/obj/weapon/blade/blade")->wield();
	carry_object("/d/obj/cloth/cloth")->wear();
}
init()
{
	add_action("do_decide", "decide");
}

string ask_me()
{
	object me = this_player();
	if(me->query("str") < 21 || me->query("con") < 28 || me->query("cor") < 20)
		return "这位"+RANK_D->query_respect(me)+"还是另谋高就吧。\n";
	me->set_temp("xuexiao/decide",1);
	return "入学以后要严格遵守学校规定，如果"+RANK_D->query_respect(me)+"有意(decide)，我马上给办理入学手续。\n";
}

int do_decide()
{
	object ob, me;
	me = this_player();
	if (!me->query_temp("xuexiao/decide"))
	{
		message_vision("$N对$n奇怪地说道：你要决定干嘛？\n", this_object(), me);
		return 1;
	}
	me->delete_temp("xuexiao/decide");
	ob = new("/d/fenghuang/obj/zhengshu");
	ob->move(me);
	me->set("xmark/学员", 1);
	me->set("title", HIM "凤凰军校学员"NOR);
       message_vision("$N说道：好！\n", this_object());
	message_vision("$N给$n一本学生证。\n", this_object(), me);
	message_vision("$N说道：这位"+RANK_D->query_respect(me) + "以后就是学员了，要勤学苦练呀。\n", this_object());
	return 1;
}
