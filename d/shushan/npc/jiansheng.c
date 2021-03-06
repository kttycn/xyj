//jiansheng.c by fei 2001.02
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_mieyao(object me);
int rank_me();
string ask_cancel();
string avenge();

void create()
{
	set_name("剑圣", ({"shushan jiansheng","jiansheng", "master"}));
	set("title", "蜀山剑派掌门人");
	set("gender", "男性");
	set("age", 65);
	set("class", "swordsman");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "掌门");
	set("per", 26);
	set("looking", "蜀山剑派祖师爷，满头白发的老人，两眼炯炯有神。");
	set("int", 30);
	set("max_kee", 5000);
	set("max_gin", 1000);
	set("max_sen", 5000);
	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 150);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 150);
	set("combat_exp", 800000);
	set("daoxing", 5000000);
	set_skill("literate", 180);
	set_skill("dodge", 180);
	set_skill("parry", 190);
	set_skill("mindsword", 200);
	set_skill("hunyuan-zhang", 180);
	set_skill("unarmed", 180);
	set_skill("spells", 180);
	set_skill("taoism", 180);
	set_skill("yujianshu", 200);
	set_skill("zixia-shengong", 190);
	set_skill("force", 190);
	set_skill("seven-steps", 180);
	map_skill("spells", "dao");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("spells","taoism");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	map_skill("unarmed", "hunyuan-zhang");
	set("shushan/wanjian_perform",1);
	set("shushan/duanshui_perform",1);
	set("inquiry", ([
		"灭妖": (: ask_mieyao :),
		"cancel": (: ask_cancel :),
		"职位": (: rank_me :),
	]));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword", "wanjianjue" :),
		(: perform_action, "sword", "duanshui" :),
		(: cast_spell, "fu" :),
	}) );
	create_family("蜀山剑派", 2, "掌门人");
	setup();
	carry_object("/d/obj/cloth/jinpao")->wear();
	carry_object("/d/shushan/obj/jueshi")->wield();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "蜀山剑派掌门大师兄" 
	|| me->query("title") == "蜀山剑派掌门大师姐")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "蜀山派"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIG"蜀山剑派"NOR+RED"◆"BLU"迎客剑童"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIG"蜀山剑派"NOR+RED"◆"YEL"斩妖剑客"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIG"蜀山剑派"NOR+RED"◆"RED"伏魔剑侠"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIG"蜀山剑派"NOR+RED"◆"MAG"伤心剑神"NOR);
		} else {
			me->set("nick", HIG"蜀山剑派"NOR+RED"◆"CYN"通天剑圣"NOR);
		}

		tell_object(me, "蜀山派剑圣对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"蜀山派剑圣对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	if ( !((string)ob->query("gender")=="男性")){
		command("shake");
		command("say 我只收男徒，这位" +RANK_D->query_respect(ob) + "还是去找酒剑仙吧。\n");
		return;
	}
	if( (string)ob->query("family/family_name")=="蜀山剑派") {
		if ((int)ob->query("daoxing") < 600000 ) {
	  		command("say 你的道行还不够，对我的招法难以领悟。\n");
			return;
		}
		if( (int)ob->query_skill("taoism", 1) < 150 ) {
			command("say 这位" + RANK_D->query_respect(ob) + "你的天师仙法还不到火候,你还是找追云子他们练着吧!\n");
			command("sigh");
			return;
		}
		if (ob->query_skill("sword",1) < 130) {
			command("say 我蜀山剑派，最注重御剑术的修行，依我看" + RANK_D->query_respect(ob) + "是不是该多下下苦功呢？");
			return ;
        }
        if ((int)ob->query_int() < 35) {
			command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我蜀山剑派武功？");
			return;
        }
		command("smile");
		command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，为蜀山争光。");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
	return;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "蜀山剑圣亲传第子");
	}
	return 0;
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
	if((string)me->query("family/family_name")=="蜀山剑派") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"剑圣念念有词......\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"降妖伏魔，乃我蜀山中人之本分。\n"NOR;
	}
	return ("贫道不明白。");
}


string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="蜀山剑派")
		return ("你不是本派弟子，生死与老夫何干？");
	if(who->query("faith")<1000)
		return ("你在本派名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("老夫未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，老夫还得想一想");
	command("say 老夫这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见剑圣向空中一指：\n");
	tell_room(where,"护法何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")
+"抓了起来！");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我蜀山剑派弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}
