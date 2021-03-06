// zhenyuan.c...weiqi, 98.02.24.
// copied a lot of useful functions from "rulai.c"...thanks snowcat:)

#define DEBUG 0

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
string avenge();
string expell_me(object me);
string keyword(object me);
string sword_xiaofeng(object me);
string sword_sanqing(object me);
string asked_guo(object me);
string ask_mieyao(object me);
string ask_cancel();
int rank_me();

void create()
{
	set_name("镇元大仙", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
	set("title", "五庄观观主");
	set("gender", "男性" );
	set("age", 65);
	set("per", 24);
	set("str", 30);
	set("long", "交游遍三界，桃李漫五行。好一位地仙之祖！\n");
	set("class", "xian");
	set("combat_exp", 5600000);
	set("daoxing", 10000000);

	set("attitude", "peaceful");
	create_family("五庄观", 1, "祖师");
	set("rank_info/respect", "观主");

	set_skill("unarmed", 280);
	set_skill("wuxing-quan", 290);
	set_skill("dodge", 280);
	set_skill("baguazhen", 260);
	set_skill("parry", 280);
	set_skill("sword", 280);
	set_skill("sanqing-jian", 290);
	set_skill("staff", 260);
	set_skill("fumo-zhang", 290);
	set_skill("hammer", 260);
	set_skill("kaishan-chui", 290);
	set_skill("force", 280);
	set_skill("zhenyuan-force", 280);
	set_skill("literate", 280);
	set_skill("spells", 300);
	set_skill("taiyi", 300);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
	map_skill("dodge", "baguazhen");
	map_skill("staff", "fumo-zhang");
	map_skill("hammer", "kaishan-chui");

	set("max_kee", 4500);
	set("max_sen", 4500);
	set("force", 5000);
	set("max_force", 2500);
	set("mana", 7000);
	set("max_mana", 3500);
	set("force_factor", 200);
	set("mana_factor", 200);

	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
	set("chat_chance_combat", 90);
	set("chat_msg_combat",
	({
		(: cast_spell, "zhenhuo" :),
		(: cast_spell, "qiankun" :),
	}) );

	set("inquiry", ([
		"leave": (: expell_me :),
		"离开": (: expell_me :),
		"袖里乾坤": (: keyword :),
		"秘诀": (: keyword :),
		"name": "老夫镇元子。\n",
		"here": "这里是五庄观，不过住的可不是道士。\n",
		"三清剑法": (: sword_sanqing :),
		"晓风残月剑法": (: sword_xiaofeng :),
		"晓风残月剑": (: sword_xiaofeng :),
		"三清剑": (: sword_sanqing :),
		"sanqing-jian": (: sword_sanqing :),
		"xiaofeng-sword": (: sword_xiaofeng :),
		"人参果": (: asked_guo :),
		"灭妖": (: ask_mieyao :),
		"cancel": (: ask_cancel :),
		"复仇" : (: avenge :),
		"职位": (: rank_me :),
	]) );

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/ruler")->wield();
}

string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("没用的东西！");
}

string sword_xiaofeng(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="五庄观") {
		message_vision("\n镇元大仙低头想了一会儿。。。。。\n", me);
		if(me->query("faith")<1000)
			return ("这个，这个，你还是多多修炼去吧！\n");
		message_vision("镇元大仙低头仔细地想了一会儿。。。。。\n\n", me);
		if( me->query("sword_xiaofeng") == 1 )
			return ("刚才不是练给你看了吗？\n");
		message_vision("镇元大仙顺手拿起一把木剑，演练了一下！\n", me);
		if( (int) me->query("combat_exp") < 100000 ) return ("你现在道行太低，只看的云里雾里，一团模糊。\n");
		if( (int) me->query("max_mana") < 2200 ) return ("你现在法力太低，无法领悟。\n");
		if(!me->query_skill("xiaofeng-sword")) return ("你没有这门绝活，怎么也来凑热闹？\n");
		if(me->query_skill("sword",1)<180)
			return ("你基本剑法还没融会贯通，无法领悟这门外功。\n");
		if( (int)me->query_skill("xiaofeng-sword",1)<180)
			return ("你晓风残月剑法还没融会贯通，无法领悟这门外功。\n");
		message_vision("镇元大仙道：好！你再看一次...！\n", me);
		if( random( (int) me->query_skill("sword",1)) > 100
		&& random( (int) me->query("combat_exp")) > 100000
		&& random(me->query("int"))<15 )
		{
			me->set("sword_xiaofeng", 1);
			message_vision("$N会意地笑了，慢慢得深思起来......\n", me);
			command("haha");
			message_vision("镇元大仙点头道：果然是我的弟子！\n", me);
			message_vision("镇元大仙嘱咐道：这次下山当不可坠了我的名声！\n", me);
			return ("好好，你现在可以去了！\n");;
		}
		command("hmm");
		command("shrug");
		message_vision("镇元大仙叹气道：虽然是我的弟子，不过.....哎，不过....！\n", me);
		message_vision("镇元大仙似乎想起了什么往事.....\n", me);
		return ("唉，你现在可以去了！\n");
	}
	command("hmm");
	command("heng");
	message_vision("镇元大仙看起来想杀死你!!\n", me);
	return ("想刺探本门秘技，好大的胆子！\n");
}

string sword_sanqing(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="五庄观") {
		message_vision("镇元大仙低头想了一会儿。。。。。\n", me);
		if(me->query("faith")<1000)
			return ("这个，这个，你还是多多修炼去吧！\n");
		message_vision("镇元大仙想到细处，不由笑了起来。。。。。\n\n", me);
		if( me->query("sword_sanqing") == 1 )
			return ("刚才不是练给你看了吗？\n");
		message_vision("镇元大仙顺手拿起一把木剑，演练了一下！\n", me);
		if( (int) me->query("combat_exp") < 100000 ) return ("你现在道行太低，只看的云里雾里，一团模糊。\n");
		if( (int) me->query("max_mana") < 2200 ) return ("你现在法力太低，无法领悟。\n");
		if(!me->query_skill("sanqing-jian")) return ("你没有这门绝活，怎么也来凑热闹？\n");
		if( me->query_skill("sanqing-jian",1) < 180 ) return ("你这门剑法还没融会贯通，无法领悟这门外功。\n");
		if( me->query_skill("sword",1) < 180 ) return ("你基本剑法还没融会贯通，无法领悟这门外功。\n");
		message_vision("镇元大仙道：好！你再看一次...！\n", me);
		if( random( (int) me->query_skill("sword",1)) > 100
		&& random( (int) me->query("combat_exp")) > 100000
		&& random(me->query("int"))<15 )
		{
			me->set("sword_sanqing", 1);
			message_vision("$N会意地笑了，慢慢得深思起来......\n", me);
			command("haha");
			message_vision("镇元大仙点头道：果然是我的弟子！\n", me);
			message_vision("镇元大仙嘱咐道：这次下山当不可坠了我的名声！\n", me);
			return ("好好，你现在可以去了！\n");;
		}
		command("hmm");
		message_vision("镇元大仙叹气道：虽然是我的弟子，不过.....哎，不过....！\n", me);
		command("shrug");
		message_vision("镇元大仙似乎想起了什么往事.....\n", me);
		return ("唉，你现在可以去了！\n");
	}
	command("heng");
	command("hmm");
	message_vision("镇元大仙看起来想杀死你!!\n", me);
	return ("想刺探本门秘技，好大的胆子！\n");
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="五庄观") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"镇元大仙念念有词.....\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return "灭妖除魔本就是我门中人应做之事。\n";
	}
	return ("贫道不知。");
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")=="dao" )
		command("say 好，好！道仙本一家。\n");

	if( (string)ob->query("family/family_name")=="五庄观" )
	{
		if( (int)ob->query("family/generation") > 3	)
		{
			command("say 福禄寿他们正想多收几个弟子，你先到那边看看吧。\n");
		}
		else
		{
			if( (int)ob->query("combat_exp")+(int)ob->query("daoxing") >= 600000 && (int)ob->query_skill("taiyi", 1) >= 120 )
			{
				command("nod ");
				command("say 好，" + RANK_D->query_respect(ob) + "不愧是本门的人才！\n");
				command("recruit " + ob->query("id") );
			}
			else
			{
				command("say 有心上进是不错，不过还是要循序渐进。\n");
			}
		}
	}
	else
	{
		command("nod");
		command("say 这位" + RANK_D->query_respect(ob) + "，本门讲究长幼之礼，尊卑之分。一下让你成为二代弟子恐人心不服。\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="五庄观") {
	message_vision("镇元大仙道：你既然要走，那也不能强留。但是太乙仙法是五庄观不传之秘，可不能带出观外。\n", me);
	me->set_temp("asked_leave_wzg", 1);
	return ("你可真是要走(true)？\n");
	}
	return ("清风，明月，送客！\n");
}

string keyword(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="五庄观") {
		message_vision("镇元大仙道：你是指袖里乾坤的六字真诀吧。\n", me);
		if( me->query("spell_qiankun_on") == 1 ) return ("不是已经告诉你了吗？\n");
		if( (int) me->query("combat_exp") < 10000 ) return ("你现在道行太低，施用袖里乾坤恐危及性命。\n");
		if( (int) me->query("max_mana") < 300 ) return ("你现在法力太低，施用袖里乾坤恐危及性命。\n");
			message_vision("镇元大仙道：好！你听着...言罢伸掌在$N头顶一拍！\n", me);
		me->set("spell_qiankun_on", 1);
		return ("六字真诀已经告诉你了，去罢！\n");
	}
	command("kick");
	return ("想刺探本门秘技，好大的胆子！\n");
}

void init()
{
	object ob = this_player();
	if( ob->query_temp("kill_tree") )
	{
		command("say 小杂毛，如果不把我的人参果树救活，别怪老夫不客气了。");
		command("slap "+ob->query("id"));
	}
	add_action("do_true", "true");
	add_action("do_back", "back");
}

int do_true(string arg)
{
	if(this_player()->query_temp("asked_leave_wzg")) {
		message_vision("$N答道：弟子真的想走！\n\n", this_player());
		message_vision("镇元大仙叹了口气道：好！回来还是客。\n", this_player());
		this_player()->add("betray/wuzhuangguan", 1);
		this_player()->add("betray/count", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if(this_player()->query_skill("taiyi"))
			this_player()->delete_skill("taiyi");
		this_player()->delete("sword_sanqing");
		this_player()->delete("sword_xiaofeng");
		this_player()->delete("spell_qiankun_on");
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "普通百姓");
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->delete_temp("asked_leave_wzg");
		this_player()->save();
		message_vision("说罢在$N头上一按，$N只觉浑身一轻，空荡荡地好像丢了什么。\n", this_player());
		return 1;
	}
	return 0;
}

//the following is for renshen dahui...

void announce (object me, string str)
{
	if (DEBUG)
	{
		object weiqi = find_player ("weiqi");
		if (weiqi && wizardp(weiqi))
			tell_object (weiqi,"◆ "+str+"\n");
	}
	else
	{
		CHANNEL_D->do_channel(me,"chat",str);
	}
}

void start_renshen()
{
	object me;

	me = this_object();

	set_temp("invite","public");

	announce (me, "五庄观人参果品尝大会即将开始！\n");
	announce (me, "诸位仙贤如愿观礼，使accept zhenyuan daxian便可！\n");
	remove_call_out ("inviting");
	call_out ("inviting",1,me);

	call_out("ready1", 180);
	set_temp("ready0", 1);
}

void ready1()
{
	object me;

	me = this_object();

	announce (me, "五庄观人参果品尝大会马上就要开始！\n");
	announce (me, "诸位仙贤如愿观礼，使accept zhenyuan daxian便可！\n");
	call_out("ready2", 180);
	set_temp("ready1", 1);
}

void ready2()
{
	object me;

	me = this_object();

	announce (me, "五庄观人参果品尝大会现在开始！\n");
	announce (me, "诸位仙贤如愿观礼，使accept zhenyuan daxian便可！\n");
	set_temp("ready2", 1);
}

string asked_guo(object me)
{
	int i, total;
	object guo;
	object *inv ;

	me=this_player();

	//if no renshenguo party at all...
	if( query_temp("ready0") != 1 ) return ("人参果可是个好东西。\n");

	//if not in the right place, no guo...
	//need the right name, also right outdoors(so ppls can not use fake room).
	if( (environment(this_object()))->query("short") != "人参果园" ||
	(environment(this_object()))->query("outdoors") != "wuzhuang" )
	{
		return ("这里又不是果园，哪来的人参果。\n");
	}

	//if waiting for ppls...
	if( query_temp("ready1") != 1 ) return ("不要急，再等等。\n");

	//if ready to begin...
	if( query_temp("ready2") != 1 ) return ("不要急，马上就有。\n");

	//if finished...
	if( query_temp("finished") == 1 ) return ("人参果已分发完了。\n");

	//now check how many people here...
	total = 0;
	inv = all_inventory( environment(this_object()) );
	for(i=0; i<sizeof(inv); i++)
	{
		if( userp(inv[i]) && (!wizardp(inv[i]))  ) total++;
	}

	if( total > 3 ) return ("哎呀！这么多人，现在只有三枚成熟的人参果。\n");
	else if ( total <= 3 && total > 0 )
	{
		for(i=0; i<sizeof(inv); i++)
		{
			if( userp(inv[i]) && (!wizardp(inv[i]))  )
			{//wiz not counted...
				guo = new("/d/obj/drug/renshen-guo");
				guo->move(inv[i]);
			 message_vision("$N给$n一枚人参果。\n", this_object(), inv[i]);
			 announce (this_object(), "恭喜恭喜！" + inv[i]->query("name") + "获得人参果一枚。\n");
		}
	}

	set_temp("finished", 1);
	call_out("finishing", 5);

	return ("好！人参果分发完毕，诸位仙贤尽情享用吧。\n");
	}
	else return ("谁要人参果？\n");

}

void finishing()
{
	message_vision("$N哈哈大笑几声，顿时无影无踪了。\n", this_object());
	delete_temp("invite");//this is necessary if not going to destruct this obj.
	destruct(this_object());
}

void inviting (object me)
{
	int i;
	object *list;

	if (! me->query_temp("invite"))
	return;

	remove_call_out ("inviting");
	call_out ("inviting",4+random(4),me);

	list = users();
	i = sizeof(list);
	while  (i--)
	{
		string here, there;

		reset_eval_cost();

		if (!environment(list[i]))
			continue;

		if (environment(list[i])->query("unit")) // not a room
			continue;

		if (list[i]->is_fighting())
			continue;

		if (list[i]->is_busy())
			continue;

		if (list[i]->query_temp("no_move"))
			continue;

		if (list[i]->is_ghost())
			continue;

		if (!living(list[i]))
			continue;

		if ((string)list[i]->query_temp("accept")!=me->query("id"))
			continue;

		list[i]->set_temp("accept",0);
		here = (string)environment(me);
		there = (string)environment(list[i]);
		if (here == there)
			continue;

		message_vision("$N的大袖往外一罩…\n",me);
		list[i]->set_temp("accept",0);
		list[i]->set_temp("wzg/from",there);

		message_vision("一团祥云飘来，云中伸出一只巨大的衣袖将$N轻轻一罩，消失在天空。\n",list[i]);
		list[i]->move(here);
		message_vision("…$N大袖轻轻一抖，$n滑了出来。\n",me,list[i]);
		break;
	}
}

int do_back(string arg)
{
	object who = this_player();
	object me = this_object();
	string here = (string)environment(me);
	string there = who->query_temp("wzg/from");

	message_vision("$N请求$n送$N回返。\n",who,me);

	 //if (!there)
	// there = "/d/city/kezhan";
	there = "/d/city/kezhan";

	who->set_temp("accept",0);
	message_vision("$N的大袖朝着$n轻轻一罩…\n",me,who);
	who->move(there);
	message_vision("…云中伸出一只巨大的衣袖轻轻一抖，只见$N从里面滑了出来。\n",who);

	return 1;
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="五庄观")
		return ("你不是本观弟子，生死与我何干？");
	if(who->query("faith")<1000)
		return ("你在本门名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("老夫未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，老夫还得想一想");
	command("say 老夫这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见镇元大仙向空中一指：\n");
	tell_room(where,"护法天尊何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我五庄观弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "大罗真仙")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "五庄观"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", YEL"万寿五庄"NOR+RED"◆"BLU"清风道童"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", YEL"万寿五庄"NOR+RED"◆"YEL"八卦道长"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", YEL"万寿五庄"NOR+RED"◆"RED"三界散仙"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", YEL"万寿五庄"NOR+RED"◆"MAG"闲云大仙"NOR);
		} else {
			me->set("nick", YEL"万寿五庄"NOR+RED"◆"CYN"地仙之祖"NOR);
		}

		tell_object(me, "镇元大仙对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"镇元大仙对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}
