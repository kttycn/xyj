#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int rank_me();
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name("水母娘娘", ({ "shuimu niangniang", "shuimu","niangniang" }) );
	set("loc_name", "水母娘娘");
	set("gender", "女性" );
	set("age", 26);
	set("int", 30);
	set("con", 30);
	set("per", 35);
	set("class", "hero");
	set("attitude", "friendly");
	set("rank_info/respect", "娘娘");
	set("apprentice_available", 50);
	create_family("盱眙山", 2, "弟子");
	set("long",
		"昔年曾水底为妖，为祸人间。后被小张太子并四大神将\n"
		"收服，大圣国师王菩萨念其千年道行来之不易，遂收为\n"
		"弟子。\n"
		);
	set("force_factor", 100);
	set("chat_chance", 5);
	set("max_gin", 3000);
	set("max_kee", 3000);
	set("max_sen", 3000);
	set("eff_gin", 3000);
	set("eff_kee", 3000);
	set("eff_sen", 3000);
	set("gin", 3000);
	set("kee", 3000);
	set("sen", 3000);
	set("max_force", 1000);
	set("force", 2000);
	set("max_mana", 1500);
	set("mana", 3000);
	set("combat_exp", 1000000);

	set_skill("unarmed", 100);
	set_skill("sword", 140);
	set_skill("force", 100);
	set_skill("literate", 60);
	set_skill("dodge", 100);
	set_skill("tianwei-shi", 100);
	set_skill("qixi-sword", 180);
	set_skill("parry", 100);
	set_skill("fumozhou", 100);
	set_skill("guiyuanforce", 100);
	set_skill("lianhuan-tui", 100);
	set_skill("spells", 110);

	map_skill("sword", "qixi-sword");
	map_skill("dodge", "tianwei-shi");
	map_skill("spells", "fumozhou");
	map_skill("force", "guiyuanforce");
	map_skill("unarmed", "lianhuan-tui");
	map_skill("parry", "qixi-sword");
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword","quewu" :),
		(: cast_spell, "freeze" :),
		(: exert_function, "hanxing shuimu" :),
	}) );
	set("inquiry", ([
		"卫道": (: ask_mieyao :),
		"cancel": (: ask_cancel :),
		"职位": (: rank_me :),
	]) );

	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/weapon/sword/wsword")->wield();
}
void reset()
{
	delete_temp("learned");
	set("apprentice_available", 1);
}
int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "伏魔神将")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "盱眙山"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", GRN"南赡盱眙"NOR+RED"◆"BLU"巡城小将"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", GRN"南赡盱眙"NOR+RED"◆"YEL"忘情太保"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", GRN"南赡盱眙"NOR+RED"◆"RED"天龙法王"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", GRN"南赡盱眙"NOR+RED"◆"MAG"归魔天皇"NOR);
		} else {
			me->set("nick", GRN"南赡盱眙"NOR+RED"◆"CYN"入圣菩萨"NOR);
		}

		tell_object(me, "水母娘娘对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"水母娘娘对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 1, ob);
	} else {
		command("say 本夫人一天只收一个徒弟。");
	}
}
void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "女性" )
	  {
      command("say 我只收女弟子，你还是去拜小张太子吧！");
	 return;
	 }
/*
	if(ob->query("betray/xuyi")){
      command("say 你曾经对门派不忠，我不能收你。");
	  }
*/
   if (((int)ob->query("combat_exp") < 20000 )) {
   command("say 这位" + RANK_D->query_respect(ob) + "修行不足，还需多加努力才是。\n");
   return;
   }
	else {

		command("smile");
		command("say 你日后可要光大我的武功哟！");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "hero");
	add("apprentice_availavble", -1);
}
int accept_object(object me,object ob)
{
	object m;
	if (ob->query("id")=="mo li") {
		command("pat" + this_player()->query("id") );
		m=new("/d/obj/book/halberd");
		m->move(this_player());
		message_vision("水母娘娘交给$N一本书，这是师傅传我的东西，就送给你吧。\n", this_player());
		call_out("destroy", 1, ob);
	return 1;
	}
	else return 0;
}
void destroy(object ob)
{
	destruct(ob);
	return;
}

void announce_gift()
{
	object *alluser,obj,gift;
	int s;
	object me = this_object();

	alluser=users();

	CHANNEL_D->do_channel(this_object(),"party","七夕佳节，我派弟子可得礼物。");
	s=sizeof(alluser);
	for (int i=0;i<s;i++) {
	    obj=alluser[i];
	    if (obj!=me && obj->query("family/family_name")=="盱眙山")
	    {
	    gift=new(__DIR__"moli");
	    gift->move(obj);
	    message("vision",me->query("name")+"给你一"+gift->query("unit")+gift->name()+"。\n",obj);
	    }
	}

	destruct(me);
	return;
}

string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("没用的东西！");
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="盱眙山") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"水母娘娘举起手中的长剑，顿时一道光芒射出。\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"即我门人,当以除魔卫道为己任。\n"NOR;
	}
	return ("本夫人不明白。");
}

