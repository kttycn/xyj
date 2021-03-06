// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"音子"NOR, ({"zong guan", "vikee"}));
	set("long", "她是专为巫师发送装备的总管"HIG"音子"NOR",你可以(list)查看想要(yao xxx)的东西。\n");
	set("gender", "女性");
	set("age", 20);
	set("per", 40);
	set("title",""MAG"装备总管"NOR);
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
		message_vision("$N看样子想打架，但"HIG"音子"NOR"很有涵养,不和$N动粗。\n",who,me);
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
		message_vision("$N看样子想杀死"HIG"音子"NOR"，但"HIG"音子"NOR"是文化人,没跟$N一般见识。\n",who,me);
		return 1;
	}
	return 0;
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N对着"HIG"音子"NOR"结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who,me);
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

	message_vision("$N想对"HIG"音子"NOR"祭法宝，前思后想，还是没敢。\n",who,me);
	return 1;
}

int do_throw(string arg)
{
	object who = this_player();
	object me = this_object();

	message_vision("$N掏出暗器，看了看"HIG"音子"NOR"，信心不足，又把暗器收了起来。\n",who,me);
	return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
	message("vision",""HIG"\n─────────────────────────────────────
          \n"HIY"盔甲："HIC"
          1.软猬甲(armor)   2. 锦衣披风(pifeng) 3.盾牌(shield)
          4.翠羽(head)      5. 金刚罩(cloth)   6.魅影神靴(shoes)
          7.指环(belt)      8. 青衫(dress)     9.冰玉戒指(ring)
          \n"HIY"兵器："HIC" 
          1.降魔棒(stick)   2. 倚天剑(sword)  3.软龙筋(whip)
          4.屠龙刀(blade)   5. 短铁爪(zhua)   6.蟠龙拐(staff)
          7.宣花斧(axe)     8. 月牙铲(fork)   9.梅花锤(hammer)
          10.沥泉枪(spear)  11.凤凰琴(qin)    12.弓箭(archery)
          13.金装锏(mace)   14.天龙戟(halberd)
"HIG"\n─────────────────────────────────────\n"NOR"",who,me);

	return 1;
}

int do_yao(string arg)
{
	string type;
	object ob, ob1, ob2;
	object who=this_player();
	//object me=this_object();

	if (!wizardp(who))
		return notify_fail("你不是巫师，还是自己去打装备吧! :P\n");

    if (!arg)
		return notify_fail("你想要什么？兵器？还是盔甲？(比如:yao sword)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//盔甲
			case "armor":
				ob=new("/d/obj/weapon/wizard/ruanwei.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "pifeng":
				ob=new("/d/obj/weapon/wizard/jinyipifeng.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shield":
				ob=new("/d/obj/weapon/wizard/shield.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shoes":
				ob=new("/d/obj/weapon/wizard/meiying_boots.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "cloth":
				ob=new("/d/obj/weapon/wizard/cloth.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "head":
				ob=new("/d/obj/weapon/wizard/cuiyu.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "belt":
				ob=new("/d/obj/weapon/wizard/seven_belt.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "dress":
				ob=new("/d/obj/weapon/wizard/green_dress.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "ring":
				ob=new("/d/obj/weapon/wizard/ring.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
				//兵器
			case "sword":
				ob=new("/d/obj/weapon/wizard/yitian-jian.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "whip":
				ob=new("/d/obj/weapon/wizard/whip.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "blade":
				ob=new("/d/obj/weapon/wizard/tulong-dao.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "stick":
				ob=new("/d/obj/weapon/wizard/stick.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "spear":
				ob=new("/d/obj/weapon/wizard/spear.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "fork":
				ob=new("/d/obj/weapon/wizard/fork.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "hammer":
				ob=new("/d/obj/weapon/wizard/hammer.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "qin":
				ob=new("/d/obj/weapon/wizard/qin.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "axe":
				ob=new("/d/obj/weapon/wizard/axe.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "staff":
				ob=new("/d/obj/weapon/wizard/staff.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "zhua":
				ob=new("/d/obj/weapon/wizard/zhua.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "mace":
				ob=new("/d/obj/weapon/wizard/goldjian.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "halberd":
				ob=new("/d/obj/weapon/wizard/tianlong.c");
				ob->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "arrow":
				ob1=new("/d/obj/weapon/archery/qiankun-bow.c");
				ob2=new("/d/obj/weapon/archery/zhentian-arrow.c");
				ob1->move(who);
				ob2->move(who);
				tell_object(who,HIG"音子"NOR"把"+ob1->query("name")+"和"+
				ob2->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			default:
				tell_object(who,HIG"音子"NOR"说道：这里没有"+type+",若想要，你做好了，给我就行了。\n");
				break;
			}
	}
	return 1;
}
