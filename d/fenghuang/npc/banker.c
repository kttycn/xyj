// originally coded by xiang
#include <ansi.h>
#include <dbase.h>
inherit NPC;

void create()
{
	set_name("露和笙", ({"banker", "zhiyuan"}));
	set("title", HIR "凤凰大银号职员" NOR);
	set("nickname", HIM "凤凰之花" NOR);
	set("gender", "女性");
	set("age", 24);
	set("str", 20);
	set("int", 24);
	set("dex", 40);
	set("per", 40);
	set("con", 18);
	set("kee", 1000);
	set("max_kee", 1000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
		"露和笙对你嫣然一笑：本银号已是千年老店，在凤凰星可以说是第一家。\n",
		"露和笙笑着说道：在本店存钱无利息，还可以在这里申请(apply)电子信用卡。\n"
	}));
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	add_money("gold", 5);
	setup();
}

void init()
{
	add_action("do_zhuanzhang", "zhuanzhang");
}

int do_zhuanzhang(string arg)
{     
	object ob,me;
	string str;
	int num, num0;
	me=this_player();
	if (!arg) return notify_fail("你要干什么？\n");
	if(sscanf(arg, "%s %d", str, num)==2 );
	else return notify_fail("你要转给谁？\n");
	ob = find_player(str);
	num0 = num / 10000;
	if (num<0) return notify_fail("别想些歪门邪道来骗钱！\n");
	if (num0>me->query("money")) return notify_fail("你没有这么多黄金了！\n");
	if (!ob) return notify_fail("现在没这个人.\n");

	me->add("balance",-num0);
	ob->add("balance",num0);
	tell_object(me,sprintf(HIC"你转了%d黄金给%s！\n"NOR,num,ob->query("name")));
	tell_object(ob,sprintf(HIC"%s转了%d黄金给你！\n"NOR,me->query("name"),num));

	return 1;                                                               
}
