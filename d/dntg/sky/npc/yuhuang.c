//By waiwai@mszj 2000/10/08

#include <ansi.h>

inherit NPC;

int promote_me();
int ask_pantao();

void create()
{
	set_name("玉皇大帝",({"yuhuang dadi","yuhuang","dadi","yudi","king"}));
	set("gender", "男性");
	set("title", HIR"天宫之主"NOR);
	set("age", 45);
	set("long", HIC"    \n这就是自幼修持，苦历过一千七百五十劫的玉皇大帝。\n"NOR);

	set("attitude", "peaceful");
	set("class", "xian");
	set("combat_exp", 4000000);
	set("daoxing", 4000000);
	set("kee", 2200);
	set("max_kee", 2200);
	set("sen", 2200);
	set("max_sen", 2200);
	set("force", 1200);
	set("max_force", 1200);

	set("mana", 2500);
	set("max_mana", 2500);
	set("force_factor", 0);
	set("mana_factor", 0);
	set("per", 30);
	set("kar", 30);

	set_skill("literate", 160);
	set_skill("sword", 80);
	set_skill("sanqing-jian", 40);
	set_skill("spells", 100);
	set_skill("force", 40);

	map_skill("sword", "sanqing-jian");

	set("inquiry", ([
		"here"   : "这里就是我的灵霄宝殿",
		"name"   : "哪里来的妖仙，真不懂规矩！",
		"官职": (:promote_me :),
		"position": (:promote_me :),
		"pantao": (: ask_pantao :),
		"蟠桃园":(:ask_pantao:),
	]));

	setup();
	carry_object("/d/obj/cloth/mangpao")->wear();
	add_money("gold", 10);
}

void init()
{
	object who;

	::init();
	if( interactive(who = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}

void greeting(object who)
{
	int i,ii,dx;
	string strluzi;
	object luzi;

	if ( !who || environment(who) != environment() ) return;
	if (who->query("dntg/number") <=0 )  
	{
		message_vision("玉帝怒喝一声：哪里来的"+RANK_D->query_rude(who)
			+"，不经传旨擅自入殿，你眼里还有王法嘛？\n",who);
		message_vision("玉帝喝道：来人哪！将他给我乱棍打出！\n",who);
		call_out ("throws1",1,who);
		return ;
	}
	else if (who->query("dntg/number") == 9 )  
	{
		if (who->query("dntg/laojunlu")=="finish")
		{
			who->set("startroom","/d/city/kezhan");
			who->add("dntg/number",1);
			who->set("dntg/bagualu","done");
			who->add("kar",5);
			tell_object(who,HIC"你突然之间觉得全身上下有一种说不出的舒泰，觉得福缘有所改观！\n"NOR);
			dx  = 50000 + random(3000); 
			who->add("daoxing",dx);
			tell_object(who,HIY"你赢得了 "HIR+COMBAT_D->chinese_daoxing(dx)+HIY" 道行。\n"NOR);
			who->set("life/live_forever", 1);
			who->set("life/live_forever_announced", 1);
			who->delete("dntg/laojunlu");
			who->add("score", 520);
			if (who->query("dntg/number") == 10)
				who->set("master/dntg",HIR"齐天大圣"NOR);
			command("chat* 玉皇大帝“哎”的一声叹了口气。");
			command("chat "HIY"罢了，罢了，"HIR+who->name()+HIY"～～～～～～
         我天宫众将都不是你对手，今后你要怎样便怎样吧！\n"NOR);
			command("chat* 玉皇大帝觉得万念俱灰，诺大个天宫竟奈何不了个泼妖，唉！！！\n");
			message("channel:rumor", HIW"【月影神迹】听说"+who->name()+"("+who->query("id")+")顺利闯过大闹天宫所有难关 ！！！ \n\n"NOR, users());
			log_file("dntg",sprintf("%s(%s) passed laojun-lu on %s\n",who->name(1), geteuid(who), ctime(time()) ) );
			who->save();
			return ;
		}
		for (ii=0;ii<8;ii++)
		{
			strluzi="/d/dntg/laojunlu/laojunlu"+(string)ii;
			luzi = load_object(strluzi);
			if (luzi->query("has_ppl")=="yes")
				this_object()->set("laojunlu","passing");
		}   
		if (this_object()->query("laojunlu") == "passing") 
		{
			this_object()->command("hmm");
			return ;
		}
		else 
		{
			command("chat " HIR+ who->name() + HIC" 你这 " HIY+ RANK_D->query_rude(who) +HIC " 在下界时屡犯天条，朕一再容你......\n");
			command("chat 如今你又偷桃，偷酒，偷仙丹，天神收降于你，你竟不思悔改！");
			command("chat 来人！把他给我扔进八卦炉中缎烧七七四十九日，将之烧为灰烬！");
			call_out ("throw_to_lu",1,who);
			return ;
		}
	}
	else if (who->query("dntg/lijing") == "done" )  
	{
		message_vision(CYN"玉帝自言自语道："HIY+who->query("name")
			+ HIG" 这个 "HIY+RANK_D->query_rude(who)
			+NOR HIG" 越来越没规矩了，竟然不经传旨擅自入殿。\n"NOR,who);
		return ;
	}
	else   
	{
		message_vision("玉帝郎声宣道道：下界妖仙"+who->query("name")
			+"初来天庭，不识王法，朕便赦了你擅自闯殿之罪。\n",who);
		return ;
	}
	return ;
}



void throw_to_lu (object who)

{
	message_vision(HIY"四面冲上无数天将，将$N绳捆索绑，拖了出去。\n"NOR,who);
	who->move("/d/dntg/laojunlu/laojunlu4");
	tell_room( environment(who),"半空中"+who->query("name")+"被笔直的扔了进来。\n", ({who}));
	tell_object(who,HIW"“当”的一声，你被投进八卦炉中。\n"NOR);
	who->set("startroom","/d/dntg/laojunlu/laojunlu");
	who->set("dntg/laojunlu","begin");
	who->set_temp("dntg/laojunlu_day",0);
}

int promote_me() 
{
	object me=this_object();
	object who=this_player();
	if (who->query("combat_exp")<1000000)  {
		message_vision("玉皇大帝不屑的冷笑道：哪里来的 "HIR+RANK_D->query_rude(who)+NOR" 不知天高地厚！\n",who);
		message_vision(CYN"凭你这点本事，也想在天宫混官当？\n"NOR,who);
		message_vision(HIR"玉皇大帝喝道：来人哪！将他给我乱棍打出！\n"NOR,who);
		call_out ("throws1",1,who);
		return 1;
	}
	else if (who->query("dntg/bmw")=="done") 
	{
		message_vision("玉帝慎道：哼！"+RANK_D->query_respect(who)+"既然不愿当弼马温，
我这天宫里也没有别的职位，"+RANK_D->query_respect(who)+"还是哪凉快哪去吧！\n",who);
		return 1;
	} 
	else if (objectp(present("wuqu xingjun", environment(me))))
	{
		message_vision("旁边转过武曲星君，启奏道：“天宫里各宫各殿，各方各处，都不少官，只是御马监缺个正堂管事。”\n",who);
		message_vision("玉帝点了点头说道：“就除你做个‘弼马温’罢。”\n",who);
		who->set("dntg/bmw","allow");
		return 1;
	}
	else 
	{
		message_vision("玉帝点了点头说道：“"+RANK_D->query_respect(who)+"稍侯，待我查看哪处少甚官职。”\n",who);
		return 1;
	}
}

void throws1 (object who)
{
	message_vision("只见殿外冲进来几个护宫天将，七手八脚地拖着$N走了出去。\n",who);
	who->move("/d/dntg/sky/qianyuangong");
	tell_room( environment(who),"只见"+who->query("name")+"被踉踉跄跄的推了出来。\n", ({who}));

	call_out ("throws2",2,who);
}

void throws2 (object who)
{
	message_vision("护宫天将大喝一声：下去！$N被扔回了下界。\n",who);
	who->move("/d/changan/bridge");
	tell_room( environment(who),"半空中"+who->query("name")+"笔直的摔了下来。\n", ({who}));
}

void die()
{
	if (environment())
		message("sound", HIR"\n只听玉皇大帝仰天大叫一声：上天救我！\n"NOR, environment());

	set("eff_kee", 2200);
	set("eff_gin", 2200);
	set("eff_sen", 2200);

	set("kee", 2200);
	set("gin", 2200);
	set("sen", 2200);
	set("force", 1200);
	set("mana", 2500);
}

void unconcious()
{
	die ();
}

int ask_pantao() {
	object who=this_player();

	if (this_player()->query("dntg/pantao")=="done")
	{
		message_vision("$N狠狠地瞪了$n一眼。\n",this_object(),this_player());
		command("say 还想去管蟠桃园？没门儿！");
		command("slogan "+this_player()->query("id"));
		return 1;
	}
	if (this_player()->query_temp("dntg/pantao")=="doing")
	{
		command("say 不是已经让你去管桃园了吗？还问什么？");
		return 1;
	}

	if (who->query("combat_exp")<500000)  {
		message_vision("玉皇大帝不屑的冷笑道：哪里来的 "HIR+RANK_D->query_rude(who)+NOR" 不知天高地厚！\n",who);
		message_vision(CYN"凭你这点本事，也想执掌蟠桃园？\n"NOR,who);
		message_vision(HIR"玉皇大帝喝道：来人哪！将他给我乱棍打出 ！！！\n"NOR,who);
		call_out ("throws1",1,who);
		return 1;
	}
	if (who->query_temp("dntg/pantao")=="denied") {
		command("heng");
		command("slap " + who->query("id"));
		command(CYN"say 说不行就不行，再问也没用 ！！！"NOR);
		message_vision(HIR"玉皇大帝喝道：来人哪！将他给我乱棍打出 ！！！\n"NOR,who);
		call_out ("throws1",1,who);
		return 1;
	}
	command("hmm");
	command("consider");
	if (random(3)) {
		command("say 你这人不可靠，我可不放心把蟠桃园交给你管。");
		who->set_temp("dntg/pantao","denied");
		return 1;
	}
	this_player()->set_temp("dntg/pantao","doing");
	this_player()->set("dntg/pantao","doing");
	message_vision("$N喃喃自语：让"+who->query("name")+"这"+RANK_D->query_rude(who)
		+"闲着，只怕会生出些是非。。。也罢。\n",this_object());
	command("ok "+this_player()->query("id"));
	command("say 就让你去管王母娘娘的蟠桃园，少惹麻烦好好干！");
	return 1;
}
