//2001.03.22 at fei
inherit NPC;
#include <ansi.h>
int give_bonnet();
int give_dan();
int answer_me();
int accept_object(object who, object ob)
{
	if( (string)ob->query("id")=="loyal bonnet" )
	{
		who->set("fei/bonnet",0);
		command("say 好借好还，再借不难。");
		return 1;
	}
}
void create()
{
	set_name(HIY"菲飞"NOR, ({"guan jia","guanjia"}));
	set ("long", @LONG
    他是在这里负责给大家发礼物(gift)哦，
    他身上还有天师法冠(bonnet)呢!
    不信你就去问问(ask)他。记得，天师法冠用完了要还哦！
LONG);
	set("gender", "男性");
	set("title",HIG"超级管家"NOR);
	set("age", 20);
	set("per", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("inquiry", ([
		"bonnet":(:give_bonnet:),
		"gift":(:give_dan:),
		"礼物":(:give_dan:),
		"天师法冠":(:give_bonnet:),
		"法冠":(:give_bonnet:),
		"name":(:answer_me:),
	]));
	setup();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int answer_me()
{
	command("say 我是超级管家雨点，在这里发放天师法冠和送礼物给大家的。\n");
	return 1;
}
int give_dan()
{
	int i,lvl = 50;
	object dan;
	object who=this_player();
	mapping skills;
	string *sk;
	if (!userp(who))
	{
		command("heng");
		command("say 什么小猫小狗也来要礼物？！");
		command("qi");
		return 1;
	}
	if (who->query("fei/gift")==2)
	{
		message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
		command("say 礼物只能领两次！领过就不给了！");
		return 1;
	}
	skills = who->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if (skills[sk[i]]>55 
			|| who->query("daoxing")>51000
			|| who->query("combat_exp")>51000
			|| who->query("max_force")>510
			|| who->query("max_mana")>510)
			{
				message_vision(CYN"$N对着$n叹了口气。\n"NOR,this_object(),who);
				command("say 你已经过了领礼物的时候了。再领礼物对你有害无益！");
				return 1;
			}
	}
	if (!who->query("fei/gift"))
	{
		who->set("combat_exp",50000);
		who->set("daoxing",50000);
		who->set("maximum_force",500);
		who->set("max_force",500);
		who->set("force",500);
		who->add("potential",10000);
	}
	who->set("maximum_mana",500);
	who->set("max_mana",500);
	who->set("mana",500);
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]]=lvl;
	}
	message_vision("$N念动咒语："HIR"哈库那玛他他!"NOR"\n$N手一指，$n只觉得周身气血翻腾，似乎武学、道行都有所进境。\n",this_object(),this_player());
	who->add("fei/gift",1);
	return 1;
}
int give_bonnet()
{
	object bonnet;
	object who=this_player();
	if (!userp(who))
	{ 
		command("heng");
		command("say 什么小猫小狗也来要东西？！");
		command("qi");
		return 1;
	}
	if (this_player()->query("fei/bonnet")=="got")
	{
		message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
		command("say 上次给你的还没还呢！不给了！");
		return 1;
	}
	bonnet=new("/d/lingtai/obj/faguan");
	bonnet->move(who);
	message_vision("$N念动咒语：哈库那玛他他!只见漫天雪飞，$N变出一个天师法冠。\n$N给$n一顶天师法冠。\n",this_object(),this_player());
	who->set("fei/bonnet","got");
	command("say 用完了记得还我哦，否则下次不给了！");
	return 1;
}
void greeting(object ob)
{
	int i;
	mapping skills;
	string *sk;

	if( !ob || !visible(ob) || environment(ob) != environment() )
		return;
	if( ob->query("fei/gift")==2 || ob->query("age")>16 || ob->query_temp("ask_feigift"))
		return;
	skills = ob->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if (skills[sk[i]]>=55
			|| ob->query("daoxing")>51000
			|| ob->query("combat_exp")>51000
			|| ob->query("max_force")>510
			|| ob->query("max_mana")>510)
				return;
	}
	tell_object(ob,name()+"神秘地说：“想要礼物吗？找我啊！不过，你只有两次机会哦！哈哈！”\n"NOR);
	tell_object(ob,name()+"神秘地说：“不过老手可千万不要乱试，听那个菲飞说，有什么损失，他可不管！”\n"NOR);
	tell_object(ob,name()+"神秘地说："HIR"“首先你要先拜师，学好功夫后，来这里领一回礼物。”\n"NOR);
	tell_object(ob,name()+"神秘地说："HIR"“然后再去把以前不能学的功夫再学回来，再来领一加礼物！”\n"NOR);
	tell_object(ob,name()+"神秘地说："HIR"“别弄错噢，你自己弄错了，我可不会赔偿你的。”\n"NOR);
	ob->set_temp("ask_feigift",1);
/*
if (random(10))
{
  switch(random(19))
  {
   case 0:
	message("system", HIM"空气中流淌着浓浓的节日气氛,春节就要到了!\n"NOR,users());
	break;
   case 1:
	message("system", HIR"轰地一个大地红在空中绚烂地绽开...\n"NOR,users());
	break;
   case 2:
	message("system", HIG"月影奇缘全体巫师祝您新春愉快!\n"NOR,users());
	break;
   case 3:
	message("system", HIM"月影奇缘全体巫师祝您新的一年万事如意!!\n"NOR,users());
	break;
   case 4:
	message("system", HIY"月影奇缘全体巫师祝您新的一年工作顺利!\n"NOR,users());
	break;
   case 5:
	message("system", HIY"月影奇缘全体巫师祝您新你的一年学习进步!\n"NOR,users());
	break;
   case 6:
	message("system", HIG"月影奇缘全体巫师祝您新你的一年身体健康!\n"NOR,users());
	break;
   default:
	break;
  }
}
*/
}
