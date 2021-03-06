// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"九天玄女"NOR, ({"zong guan", "vikee"}));
	set("long", "她是专为巫师发送各种补品和礼品的总管"HIG"九天玄女"NOR",你可以(list)查看想要(yao xxx)的东西。\n");
	set("gender", "女性");
	set("age", 20);
	set("per", 40);
	set("title",""MAG"补品和礼品总管"NOR);
	set_skill("literate", 141);
	setup();
	carry_object("/d/obj/cloth/female-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_fight", "fight");
	add_action("do_kill", "kill");
	add_action("do_steal", "steal");
	add_action("do_cast", "cast");
	add_action("do_ji","ji");
	add_action("do_throw","throw");
	add_action("do_list","list");
	add_action("do_yao","yao");
}

int do_fight(string arg)
{
	object who = this_player();
	object me = this_object();

	if (arg && present(arg,environment(who))==me)
	{
		message_vision("$N看样子想打架，但"HIG"九天玄女"NOR"很有涵养,不和$N动粗。\n",who,me);
		return 1;
	}
	return 0;
}

int do_kill(string arg)
{
	object who = this_player();
	object me = this_object();

	if (arg && present(arg,environment(who))==me)
	{
		message_vision("$N看样子想杀死"HIG"九天玄女"NOR"，但"HIG"九天玄女"NOR"是文化人,没跟$N一般见识。\n",who,me);
		return 1;
	}
	return 0;
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N对着"HIG"九天玄女"NOR"结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who,me);
	return 1;
}

int do_steal(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N想偷东西，但总是有贼心没贼胆。\n",who,me);
	return 1;
}


int do_ji(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N想对"HIG"九天玄女"NOR"祭法宝，前思后想，还是没敢。\n",who,me);
	return 1;
}

int do_throw(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N掏出暗器，看了看"HIG"九天玄女"NOR"，信心不足，又把暗器收了起来。\n",who,me);
	return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
	message("vision",""HIG"\n─────────────────────────────────────
          \n"HIY"补品："HIC"
          1.火龙肝(gan)         2.万年朱果(zhuguo)     3.人参果(guo)
          4.交梨(li)            5.火枣(zao)            6.灵芝草(lingzhi)
          7.碧藕(ou)            8.猕猴桃(tao)          9.仙酒(jiu)
         10.冷香丸(lengxiang)  11.仙桃(xiantao)
          \n"HIY"礼品："HIC" 
          1.神力丸(wan)         2. 洗髓丹(dan)         3.万年灵芝(zhi)
          4.仙丹(xiandan)       5. 冰糖葫芦(hulu)      6.蟠龙拐(staff)
          7.宣花斧(axe)         8. 月牙铲(fork)        9.梅花锤(hammer)
         10.沥泉枪(spear)      11.凤凰琴(qin)         12.弓箭(archery)
         13.金装锏(mace)       14.天龙戟(halberd)
"HIG"\n─────────────────────────────────────\n"NOR"",who,me);

	return 1;
}

int do_yao(string arg)
{
	string type;
	object ob, ob1, ob2;
	object who=this_player();
	object me=this_object();

	if (!wizardp(who))
		return notify_fail("你不是巫师，还是自己去想办法吧! :P\n");

    if (!arg)
		return notify_fail("你想要什么？补品？礼品？(比如:yao gan)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//补品
			case "gan":
				ob=new("/d/fenghuang/obj/huologgan.c.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "zhuguo":
				ob=new("/d/fenghuang/obj/xiandan.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "guo":
				ob=new("/d/obj/drug/renshen-guo.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "lingzhi":
				ob=new("/d/xuyi/obj/lingzhi.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "zao":
				ob=new("/d/obj/drug/huozao.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "li":
				ob=new("/d/obj/drug/jiaoli.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "ou":
				ob=new("/d/obj/drug/biou.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "tao":
				ob=new("/d/obj/drug/mihoutao.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "jiu":
				ob=new("/d/obj/drug/xianjiu.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "lengxiang":
				ob=new("/d/obj/drug/lengxiangwan.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;	
			case "jiu":
				ob=new("/d/obj/drug/xianjiu.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "xiantao":
				ob=new("/d/obj/drug/xiantao.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;		
				//礼品
			case "dan":
				ob=new("/d/obj/story/xisuidan.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "zhi":
				ob=new("/d/obj/story/lingzhi.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "xiandan":
				ob=new("/d/obj/story/xiandan.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "wan":
				ob=new("/d/obj/story/shenliwan.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "spear":
				ob=new("/d/obj/weapon/wizard/spear.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "fork":
				ob=new("/d/obj/weapon/wizard/fork.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "hammer":
				ob=new("/d/obj/weapon/wizard/hammer.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "qin":
				ob=new("/d/obj/weapon/wizard/qin.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "xiandan":
				ob=new("/d/obj/story/xiandan.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "staff":
				ob=new("/d/obj/weapon/wizard/staff.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "hulu":
				ob=new("/d/obj/story/bingtang.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "mace":
				ob=new("/d/obj/weapon/wizard/goldjian.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "halberd":
				ob=new("/d/obj/weapon/wizard/tianlong.c");
				ob->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "arrow":
				ob1=new("/d/obj/weapon/archery/qiankun-bow.c");
				ob2=new("/d/obj/weapon/archery/zhentian-arrow.c");
				ob1->move(who);
				ob2->move(who);
				tell_object(who,HIG"九天玄女"NOR"把"+ob1->query("name")+"和"+
				ob2->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			default:
				tell_object(who,HIG"九天玄女"NOR"说道：这里没有"+type+",若想要，你做好了，给我就行了。\n");
				break;
			}
	}
	return 1;
}
