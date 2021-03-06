// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int rank_me();
int do_drop(object, object);
string ask_me();
int ask_tree();
string avenge();

void create()
{
	set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "救苦救难大慈大悲");
	set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
	set("gender", "女性");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "贫僧");
	set("rank_info/respect", "菩萨娘娘");
	set("class", "bonze");
        	set("str",24);
	set("per",100);//means no rong-mao description.
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 145);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

	set_skill("literate", 280);
	set_skill("spells", 300);
	set_skill("buddhism", 300);
	set_skill("unarmed", 250);
	set_skill("jienan-zhi", 250);
	set_skill("dodge", 280);
	set_skill("lotusmove", 280);
	set_skill("parry", 280);
	set_skill("force", 280);
	set_skill("lotusforce", 280);
	set_skill("staff", 280);
	set_skill("lunhui-zhang", 280);
	set_skill("hammer",290);
	set_skill("bighammer",290);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	map_skill("hammer", "bighammer");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: perform_action, "staff", "fuhu" :),
	}) );
	set("inquiry", ([
		"复仇" : (: avenge :),
		"伏魔" : (: ask_me :),
		"医树" : (: ask_tree :),
		"净瓶" : (: ask_tree :),
		"职位": (: rank_me :),
	]));

	create_family("南海普陀山", 1, "菩萨");

	setup();
	carry_object("/d/nanhai/obj/jiasha")->wear();
	carry_object("/d/nanhai/obj/nine-ring")->wield();
}

string ask_me()
{
	object obj;
	if((int)this_player()->query("combat_exp") < 280000 )
		return "你那点道行还想伏魔？\n";
	message_vision("观音对$N笑道：你用howdo试试缘分\n", this_player());
	return "快试...";
}

void init()
{
	add_action("do_how", "howdo");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate_book", 36000);//10 hours
	}
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "普陀山弘法大师")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "南海普陀山"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIY"南海普陀"NOR+RED"◆"BLU"知客小僧"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIY"南海普陀"NOR+RED"◆"YEL"戒律首座"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIY"南海普陀"NOR+RED"◆"RED"罗汉首座"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIY"南海普陀"NOR+RED"◆"MAG"观音护法"NOR);
		} else {
			me->set("nick", HIY"南海普陀"NOR+RED"◆"CYN"逍遥菩萨"NOR);
		}
		tell_object(me, "观音菩萨对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"观音菩萨对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

void generate_book()
{
	remove_call_out("generate_book");
	set("available", 1);
}

int do_how(string arg)
{
	object me, book;

	me = this_player();
	if( query("available") == 1 )
	{
		set("available", 0);
		book = new("/d/obj/book/forcebook2");
		book -> move(this_player());
		message_vision("真有缘，给你。\n", me);
		command("chat "+this_player()->query("name")+"有缘，得到《伏魔山心经下卷》！");
		remove_call_out("generate_book");
		call_out("generate_book", 36000);//10 hours
		return 1;
	}
	else return notify_fail("你来的不是时候。\n");
}

int clean_up()
{
	return 0;
}

void attempt_apprentice(object ob)
{
	if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say 我佛门神通广大，" + RANK_D->query_respect(ob) + "欲成正果，先入我门。\n");
		write("看样子观音菩萨对你未剃度出家颇为不快。\n");
		return;
	}	
	if (((int)ob->query_skill("buddhism", 1) < 100 )) {
		command("say " + RANK_D->query_respect(ob) + "不在佛法上苦修，恐怕难成正果。\n");
		return;
	}
	command("pat " + ob->query("id") );
	command("say 好！这才是我佛门的好弟子。只要多加努力，定可早成正果。\n");

	command("recruit " + ob->query("id") );
	return;	
}
void die()
{
	int i;
	string file;
	object *inv;

        if( environment() ) {
        message("sound", "\n\n观音菩萨摇头叹道：刚离迷障，又入魔障，世间疾苦，何人度之！\n\n", environment());
        command("sigh");
        message("sound", "\n观音菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
        inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("no_drop")) continue;
		do_drop(this_object(), inv[i]);
//		if (stringp(file = find_command("drop")) && 
//			call_other(file, "do_drop", this_object(), inv[i])) ;
	}
	}

	destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
            else {
                 message_vision( sprintf("$N丢下一%s$n。\n",
                 undefinedp(obj->query_temp("unit"))?
	                 "个":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
           else {
             message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在
		   。\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
	die();
}
void announce_success (object who)
{
	int i;

	if (who->query("obstacle/meihouwang") == "done" ||
	! who->query_temp("liuer-mihou_killed") )
	{
		destruct(this_object());
		return;
	}
	i = random(600);
	who->add("obstacle/number",1);
	who->set("obstacle/meihouwang","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"识破假猴王，取回包裹！");
	message("channel:chat",HIW"【过关斩将】观音菩萨(Guanyin pusa)："+who->query("name")+"闯过西行取经第三十六关！\n"NOR,users());
	tell_object (who,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行！\n");
	destruct (this_object());
	who->save();
	return;
}
int ask_tree()
{
	object who=this_player();

	if ( !who->query_temp("kill_tree")||who->query("ask_jingping"))
		return notify_fail("泼猴无事，何来骚扰贫尼？");
	switch(who->query_temp("guanyin_ask_tree")) {
		case 0:
			tell_object(who,"观音菩萨说道：“你这泼猴，不知好歹！他那人参果树，乃天开地辟的灵根。镇元子乃地仙之\n祖，我也让他三分，你怎么就打伤他树！”\n");
			who->set_temp("guanyin_ask_tree",1);
			break;
		case 1:
			tell_object(who,"观音菩萨说道：“我这净瓶底的甘露水，善治得仙树灵苗。”\n");
			who->set_temp("guanyin_ask_tree",2);
			break;
		case 2:
			command("sigh");
			command("say 你这惹祸的猴头，可是，我的净瓶被福星借去了，你去问问他吧。");
			who->set_temp("guanyin_ask_tree",3);
			who->set_temp("ask_jingping",1);
			break;
		default:
			command("say 你这惹祸的猴头，歪歪唧唧，没完没了，此时不去更待何时？");
			break;
	}
	return 1;
}
string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="南海普陀山")
		return ("你不是本门弟子，生死与我何干？");
	if(who->query("faith")<1000)
		return ("你在本门名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("贫尼未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，贫尼还得想一想");
	command("say 贫尼这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见观音菩萨向空中一指：\n");
	tell_room(where,"护法金刚何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我南海普陀山弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}
int accept_object(object who, object ob)
{
	if ( ob->query("id") == "sheng lingzhu" )
	{
		if( who->query("obstacle/zhu") )
		{
			command("say "+who->query("name")+"，你已经找回圣灵珠啦呀。\n");
			return 1;
		}
		command("wa");
		remove_call_out("check");
		call_out("check",2,who);
		return 1;
	}
	return 1;
}
void check(object who)
{
	int i;
	if (who->query("combat_exp") < 10000)
		return;
	if ( who->query("obstacle/zhu") == "done" )
		return ;
	i = random(600);
	who->add("obstacle/number",1);
	who->set("obstacle/zhu","done");
	who->add("daoxing",i+10000);
	who->add("score", 10);
	command("chat "+who->query("name")+"替我佛如来找回圣灵珠！");
	message("channel:chat",HIW"【过关斩将】观音菩萨(Guanyin pusa)："+who->query("name")+"闯过西行取经第四十关！\n"NOR,users());
	tell_object (who,"你赢得了"+COMBAT_D->chinese_daoxing(i+10000)+"的道行！\n");
	who->save();
	who->start_busy(2);
}
        
