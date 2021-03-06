// by night
// fid 修改

#include <ansi.h>

inherit NPC; 
//inherit F_DEALER; 
void consider();
int ask_gift(); 
int ask_cake();
void create()
{
	set_name(HIB"夜"NOR+HIG"精灵"NOR, ({ "spirit" }) );
	set("nickname", MAG "生辰" NOR);
	set("gender", "女性" );
	set("age", 16);
	set("long", 
"精灵楼的主人，管理着精灵楼的一切事务。\n" );
	set("attitude", "friendly");
	set("shen_type", 1);
	set("class", "phoenix");

	set("str",21);
	set("int",28);
	set("con",40);
	set("per",40);

	set("kee", 2000);
	set("max_kee", 2000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("force", 6000);
	set("max_force", 3000);
	set("mana", 6000);
	set("max_mana", 3000);
	set("force_factor", 300);
	set("combat_exp", 1000000);
	set("daoxing", 2500000);
	set_skill("blade",300);
	set_skill("dodge",300);

	set("inquiry", ([
		"精灵物语" : "“那是我最喜欢的书哦，绝对不给人！”\n", 
		"礼物" : (: ask_gift :),
		"节日礼物" : (: ask_gift :),
		"仟禧俱乐部" : (: ask_gift :), 
		"生日礼物" : (: ask_cake :),      ]));

	set("chat_chance",30);
	set("chat_msg", ({
		"生辰精灵拿出一本"+HIW"《精灵物语》"NOR+"，专心地读了起来。\n", 
		"生辰精灵随着光芒一闪一闪，无聊地说：“怎么没人来领礼物呢？”\n",
		"生辰精灵笑嘻嘻地说：“要节日礼物，找我就对了。”\n",      }) );
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "shield" :),
	}) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: exert_function, "eyes" :),
	}) ); 
	set("vendor_goods", ({
		"/d/city/obj/candle",//礼物的路径，自定义。
	}));
	setup();
	carry_object("/d/city/obj/moon-dress")->wear();
	carry_object("/d/obj/weapon/blade/blade")->wield(); 
//        carry_object("/u/jave/obj/gun");
} 

int ask_cake()
{ 
	object ob;
	if (this_player()->query("birth"))
	{
		command("say 恭喜恭喜，祝你生日快乐！\n");
		ob=new("/d/city/obj/cake");  //礼物的路径，自定义。
		ob->move(this_player()); 
		message_vision("\n$N给了$n一个特制的生日蛋糕。\n",  this_object(),this_player());
		this_player()->delete("birth"); 
		return 1;
	}
	return 0;
}
 
int ask_gift()
{
	if ( (string)this_player()->query("id")=="fid" )    {
		command("say 请进，嘻嘻。\n");
		this_player()->move("d/city/clubgate");
	}
	else
	{
		command("say 要礼物是吧？进去吧。\n"); 
		this_player()->move("d/city/clubgate");
		this_player()->delete("giftsp");
	}
	return 1;
}
void init()
{ 
	add_action("do_list", "list");
	add_action("do_buy", "buy"); 
	add_action("do_faint", "18mo");
	add_action("do_faint", "kiss");
	add_action("do_faint", "taste"); 
	add_action("do_faint", "hug");
	add_action("do_faint", "beg");
}
 
void unconcious ()
{
	die ();
}  
void die()
{
	object ob;
	command("sigh");
	message_vision(HIW"\n$N背上长出一对透明的羽翼，一开一合间，$N又变得神采奕奕。\n"NOR, this_object());
	set("kee", 2000);
	set("max_kee", 2000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("force", 3000);
	set("max_force", 3000);
} 


int do_faint()
{
	object me, ob;
	me=this_object();
	ob=this_player();
	message_vision("$N脸一红，说：“哎呀，你怎么能对我做这么丢脸的事呢？”\n" NOR, me);
	message_vision("说罢，口中念了句咒语，$N眼前一黑，晕了过去。\n",ob);
	ob->set("immortal",0);
	ob->delete("immortal");
	ob->unconcious();
	return 1;
}
