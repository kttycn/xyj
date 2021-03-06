#include <ansi.h>
inherit NPC;
int laojun_yao(object me);
int check();

void create()
{
	set_name("唐太宗", ({"tang taizong", "tang", "tai zong", "zong", "king", "emperor"}));
	set("long", "大唐国之太宗皇帝李世民。\n");
	set("title", HIY"大唐皇帝"NOR);
	set("gender", "男性");
	set("rank_info/respect", "陛下");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("int", 30);
	set("max_kee", 700);
	set("max_gin", 700);
	set("max_sen", 700);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 800);
	set("mana", 800);
	set("mana_factor", 40);
	set("combat_exp", 220000);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("spells", 50);
	set_skill("force", 50);
	set_skill("seashentong", 50);
	set_skill("dragonforce", 50);
	set_skill("dragon-steps", 50);
	set_skill("dragonfight", 50);
	map_skill("unarmed", "dragonfight");
	map_skill("dodge", "dragon-steps");
	map_skill("force", "dragonforce");
	map_skill("spells", "seashentong");
	set("inquiry",([
		"陈光蕊" :(: check :),
		"妖怪"	:(: laojun_yao :),
		"犀牛精"	:(: laojun_yao :),
		"灭妖"	:(: laojun_yao :),
	]));
	set_weight(5000000);	
	setup();
	carry_object("/d/obj/cloth/mangpao")->wear();
}

void init ()
{
	object who=this_player();
	if(!who) return;

	call_out ("test_player",1,this_player());
	if ((int)who->query("quest/reward") ){
		who->start_busy(2);
	}
}

string *strs = ({
	"$N对$n惊叹道：",
	"$N对$n赞赏道：",
	"$N微笑着对$n说道：",
	"$N赞许地对$n说道：",
});

void test_player (object who)
{
	object me = this_object();
	object where = environment (me);
	object dachen;
	string str;
	int rand, reward, color;
	mapping colors;

	if (who->query("quest/reward") < 1)
		return;

	colors=who->query("quest/colors");
	color=sizeof(colors);
//		if(!color) return;
	switch(color) {
		case 1: reward=1;break;
		case 2: reward=1;break;
		case 3: reward=3;break;
		case 4: reward=7;break;
		case 5: reward=10;break;
		case 6: reward=15;break;
		case 7: reward=25;break;
		case 8: reward=30;break;
		case 9: reward=35;break;
		default: reward=1;
	}
		
	// mon 12/17/98
	if(((int)who->query("combat_exp")+(int)who->query("daoxing"))/2
	<20000) { // for newbie, no color request.
			 // for older players, rewards depends on number of colors.
		if(color<2) color=2;
		if(reward<10) reward=10;
	}

	who->set_temp("quest/reward_point",(int)who->query("quest/reward")*reward/6);

	message_vision ("\n一进大殿，$N身上涌起淡淡的"+
		(color>2?chinese_number(color)+"彩":"")+
		"祥云。\n",who);

	if(color==1) { // no dx & pot rewards.
		rand=random(6);
	} else {
		rand=random(100);
	}
		
	if(rand==0)
		str = "zhang shiheng";	
	else if(rand<3)
		str = "meng ziru";
	else if(rand<6)
		str = "du ruhui";			 
	else if(rand<53)
		str = "duan zhixian";
	else if(rand<79)
		str = "xiao yu";
	else 
		str = "xu maogong";		 

	dachen = present (str, where);

	if (! dachen) {
		dachen = present ("da chen", where);
		//someone took dachen out of this room. nobody should do this.
		//here only give minimum reward as penalty.
		who->set_temp("quest/reward_point",0);
	}

	if (! dachen ||
	!living(dachen))
	{
		message_vision ("$N对$n说道：大臣们不在，"+RANK_D->query_respect(who)+
			"稍候也。\n",me,who);
		return;
	}
	message_vision (strs[random(sizeof(strs))]+RANK_D->query_respect(who)+
		"祥云缭绕，面生瑞气，朕果然有赏御赐与你！\n",me,who);
	message_vision ("\n$N走上前，赶紧在$n的殿前俯身跪下。\n",who,me);
	who->start_busy (3,3);
	call_out ("reward_player",2,me,who,dachen);
}

void reward_player (object me, object who, object dachen)
{

	// added by mon 5/29/98 to prevent players repeatedly
	// get reward.
	if ((int)who->query("quest/reward") < 1)
		return;

	message_vision ("\n旁边闪过大臣$N低声向$n说了几句，$n点了点头。\n",dachen,me);
	dachen->reward(who);
	message_vision ("\n$N连忙俯身一拜，小心翼翼地站起来。\n",who,me);
	who->delete("quest/reward");
	who->interrupt_me();
}

int check()
{
	object me=this_player();
	int i;
	object jiasha, chen;

	chen = present("chen guangrui", environment(me));
	if( chen )
		destruct(chen);

	if ( me->query("obstacle/jz") == "done" )
		return 0;
	if ( me->query("combat_exp") < 10000)
		return 0;
	if( !me->query_temp("obstacle/can_see_king") )
		return 0;
	i = random(600);
	me->add("obstacle/number",1);
	me->set("obstacle/jz","done");
	me->add("daoxing",i+4000);
	me->delete_temp("obstacle");
	me->add("score", 10);
	command("oh "+me->query("id"));
	command("say 这是袈裟你拿去吧，希望你取经路上一路平安。");
	jiasha = new("/d/obj/cloth/jiasha2");
	jiasha->move(me);	
	command("chat "+me->query("name")+"杀死刘洪等人，救出贤臣光蕊。");
	message("channel:chat",HIW"【过关斩将】唐太宗(Tang taizong)："+me->query("name")+"闯过西行取经第一关！\n"NOR,users());
	tell_object (me,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行！\n");
	me->save();
	return 1;
}

void reset()
{
	this_object()->delete_temp("given");
}
/*
string laojun_yao(object me)	
{
	me=this_player();
	if( me->query("laojun_jing") != 1 ) 
	{
		command("say 你去问过太上老君了吗!");
		command("shake");
		return ("别在相信这么无聊的人了 \n");
	}
	if( me->query("laojun_killjing") != 1 ) 
	{
		command("say 太上老君说在五庄观......");
		command("hmm");
		return ("你去五庄观呀!!\n");
	}
	command("say 这是真的吗？");
	message_vision ("唐太宗有些慌张起来.\n",me);
	command("say 上仙还请后堂");
	me->set("enter", 1);
	return ("这次就多多感谢上仙了。。。\n");
}
*/

int laojun_yao(object me)	
{
	me=this_player();
//	object ziyingjian,doublesword;

//	if( me->query("ziying")=="done" )
//		return "对不起,紫郢剑已经被人拿走了!\n";	
//	if(ziyingjian == present("ziying sword",me) && doublesword == present("ziqing shuangsword",me))
//	if ( present("ziying sword",me) || present("ziqing shuangsword",me) )
//                return "可你现在不正拿着一柄吗，人可不能太贪心啊。\n";
	if( !me->query_temp("ask_ziying") ) 
	{
		command("consider");
		command("say 谣言呀，这个你都相信？");
		command("bug1");
		me->set_temp("ask_ziying","tang1");
		return 1;
	}
	else if( me->query_temp("ask_ziying") == "laojun2" ) 
	{
		command("say 太上老君那里且去？！");
		message_vision("唐太宗声嘶力竭地大声叫道：哈！砍头不过头点地，老子十八年後又是一条好汉！\n", me);
//		me->set_temp("ask_ziying","tang2");
		return 1;
	}
	command("say 这是真的吗？");
	message_vision ("唐太宗有些慌张起来.\n",me);
	command("say 上仙还请后堂");
//	me->set("enter", 1);
        message_vision ("这次就多多感谢上仙了。。。\n",me);
        return 1;
}

