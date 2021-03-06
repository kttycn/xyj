#include <ansi.h>
#include <mudlib.h>
inherit NPC;
string ask_me();

void create()
{
	set_name(MAG"月影使者"NOR, ({ "xiake shizhe", "shizhe" }) );
	set("nickname", CYN"不知情愁枉少年"NOR);
	set("gender", "男性" );
	set("age", 18);
	set("long", YEL"这位是〖月影奇缘〗的使者，向他打听“月影奇缘”，他会带给您想不到的惊喜。\n"NOR);
	set("shen_type", 1);
	set("combat_exp", 1000000);
	set("str", 30);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("per", 30);
	set("attitude", "friendly");
	set("max_kee", 100000);
	set("force", 100000);
	set("max_force", 100000);
	set("score", 100000);

	set("inquiry", ([
		"月影奇缘" : (: ask_me :)
	]));
	setup();
}

void init()
{
	object ob;
	ob = this_player();     
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("whisper " + ob->query("id") + " "HIW"欢迎光临〖月影奇缘〗"+HIR+"(ask shizhe about 月影奇缘)\n"+NOR+HIW+"小的助您行走江湖．"NOR);
}

string ask_me()
{
	object me = this_player();
//	mapping fam; 

	if ((int) me->query("welcomexhc"))
		return "呵呵～这就是您的不是了！小的已经对您施过法力了！";
	else
	{
		me->set("welcomexhc", 1);
		me->add("food", 10000);
		me->add("water", 10000);
		CHANNEL_D->do_channel(me, "chat", sprintf("在下%s今日光临〖月影奇缘〗"
		"\n　　　　现已得到月影使者的帮助！即日起开始行走江湖了！请各位仙长多多捧场！", me->name(1)));
		return "欢迎光临"NOR+HIR"〖月影奇缘〗"NOR"，小的护驾来迟，罪该万死！在下可助您行走江湖！\n"
		HIW"突然天空中一道"HIM"七"HIY"彩"HIR"霞"HIC"光"HIW"笼罩四方，转瞬即逝！"NOR;
	}
}

