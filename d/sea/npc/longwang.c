//modified by sgzl for dntg/donghai quest
#include <skill.h>
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string expell_me(object me);
int donghai_quest(object who);
string ask_mieyao(object me);
string ask_cancel();
string avenge();

void create()
{
	set_name("敖广", ({"ao guang", "ao","guang","longwang","wang"}));
	set("long","敖广是东海的龙王，其兄弟分别掌管东，西，南，北四海。
由余其水族众多，声势浩大，俨然独霸一方。\n");
	set("gender", "男性");
	set("age", 66);
	set("title", "东海龙王");
	set("class","dragon");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("rank_info/respect", "陛下");
	set("per", 20);
	set("str", 30);
	set("max_kee", 3000);
	set("max_gin", 400);
	set("max_sen", 1500);
	set("force", 3000);
	set("max_force", 1500);
	set("force_factor", 120);
	set("max_mana", 800);
	set("mana", 1600);
	set("mana_factor", 40);
	set("combat_exp", 1200000);
	set("daoxing", 1500000);

	set_skill("huntian-hammer", 270);
	set_skill("hammer", 270);
	set_skill("literate", 220);
	set_skill("unarmed", 300);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("parry", 290);
	set_skill("fork", 290);
	set_skill("spells", 270);
	set_skill("seashentong", 270);
	set_skill("dragonfight", 300);
	set_skill("dragonforce", 280);
	set_skill("dragon-cha", 290);
	set_skill("dragon-steps", 280);

	map_skill("hammer", "huntian-hammer");
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "dragon-cha");
	map_skill("parry", "dragon-cha");
	map_skill("dodge", "dragon-steps");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: cast_spell, "freez" :),
		(: cast_spell, "water" :),
		(: cast_spell, "dragonfire" :),
		(: exert_function, "roar" :),
		(: exert_function, "zhenshen" :),
		(: perform_action, "hammer", "break" :),
		(: perform_action, "unarmed", "sheshen" :),
		(: perform_action, "unarmed", "leidong" :)
	}) );
	set("inquiry", ([
		"离宫": (: expell_me :),
		"leave": (: expell_me :),
		"灭妖": (: ask_mieyao :),
		"kill": (: ask_mieyao :),
		"cancel": (: ask_cancel :),
		"兵器": (: donghai_quest :),
		"weapon": (: donghai_quest :),
		"复仇" : (: avenge :)
	]) );

	create_family("东海龙宫", 1, "水族");
	set_temp("apply/armor",50);
	set_temp("apply/damage",25);
	setup();

	carry_object("/d/sea/obj/longpao")->wear();
}
void init()
{
	::init();
	add_action("do_agree", "agree");
	add_action("do_learn", "xuexi");
}


void destroy(object ob)
{
        destruct(ob);
        return;
}

void unsetlearn(object ob)
{
	if (find_player(ob->query("id"))) {
		ob->set_temp("temp/learn", 0);
		ob->save();
		}
}


string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

int do_learn(string arg)
{
	string skill, teacher, master;
	object me= this_player(), ob;
	int master_skill, my_skill, sen_cost;

	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
		return notify_fail("指令格式：xuexi <技能> from <某人>\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯．．．你得先把" + ob->name() + "弄醒再说。\n");

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	if (skill != "unarmed" || !me->query_temp("temp/learn") )
		return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

	notify_fail(ob->name() + "不愿意教你这项技能。\n");
	if( ob->prevent_learn(me, skill) )
		return 0;

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	sen_cost = 250 / (int)me->query_int();

	if( !my_skill ) {
		sen_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
	printf("你向%s请教有关%s的疑问。\n", ob->name(),
		to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

	tell_object(ob, sprintf("%s向你请教有关%s的问题。\n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("sen") > sen_cost/5 + 1 ) {
		if( userp(ob) ) ob->receive_damage("sen", sen_cost/5 + 1);
	} else {
		write("但是" + ob->name() + "显然太累了，没有办法教你什么。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}


	if( (int)me->query("sen") > sen_cost ) {
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是道行不够，你对%s的回答总是无法领会\n", ob->name() );
		} else {
			printf("你听了%s的指导，似乎有些心得。\n", ob->name());
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} else {
		sen_cost = me->query("sen");
		write("你今天太累了，结果什么也没有学到。\n");
	}

	me->receive_damage("sen", sen_cost );

	return 1;
}

void attempt_apprentice(object ob)
{
	if( (int)ob->query_skill("dragonforce",1) < 50
	|| (int)ob->query_skill("seashentong", 1) < 50) {
	command("say " + RANK_D->query_respect(ob) +
		"还是先到大将军或小女处把基础打好了再来我这儿吧。\n");
	return;
	}
        command("smile");
        command("say 难得" + RANK_D->query_respect(ob) +
		"有此心志，还望日后多加努力，为我东海龙宫争光。\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="东海龙宫")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("你要离开我也不能强留。只是按我东海规矩，却须受罚。
恐怕既是身非龙类，这龙神心法与博击并不能如前般运转，你可愿意(agree)?\n");
    }
  return ("去问问袁先生吧，或许他知道！\n");
}

int do_agree(string arg)
{
	object me;
	me = this_player();
	if(me->query_temp("betray"))
	{
		message_vision("$N答道：弟子愿意。\n\n", me);
		command("say 人各有志，既是" + RANK_D->query_respect(me) +
        "不愿留在东海，就请出宫去吧。只是江湖险恶，" + RANK_D->query_respect(me) +
	"当好自为之。。。\n");
		me->set_skill("dragonforce", (int)me->query_skill("dragonforce",1)/2);
		me->set_skill("dragonfight", (int)me->query_skill("dragonfight",1)/3);
		me->set("combat_exp", me->query("combat_exp")*80/100);
		me->set("daoxing", me->query("daoxing")*80/100);
		me->delete("family");
		me->delete("class");
		me->delete("faith");
		me->delete("family_wp");
		me->set("title", "普通百姓");
		me->set_temp("betray", 0);
		me->add("betray/count", 1);
		me->add("betray/longgong", 1);
		if( (int)me->query("score") < 1000 )
			me->set("score", 0);
		else
			me->add("score", -1000 );
		me->save();
		return 1;
	}
	return 0;
}

int donghai_quest(object who)
{
  object me=this_object();
  object fighter;
  string weapon_name,weapon_id,weapon_unit,temp_flag;

  who=this_player();
  if (who->query("dntg/donghai")=="done") {
    message_vision("$N面色惨淡，不情愿地说：“那神兵还在老地方，且随我来。”\n",this_object());
    call_out("sendto_maze",2,who);
    return 1;
  }

  if (
      who->query("dntg/donghai") == "begin"
      || who->query("dntg/donghai") == "da kan dao"
      || who->query("dntg/donghai") == "jiu gu cha"
      || who->query("dntg/donghai") == "mei hua chui"
     )

    {
        if (who->query("dntg/donghai") == "begin")
           {weapon_name="大砍刀"; weapon_id="da kan dao";weapon_unit="柄";temp_flag="try_dao";}
        if (who->query("dntg/donghai") == "da kan dao")
           {weapon_name="九股叉"; weapon_id="jiu gu cha";weapon_unit="支";temp_flag="try_cha";}
        if (who->query("dntg/donghai") == "jiu gu cha")
           {weapon_name="梅花锤"; weapon_id="mei hua chui";weapon_unit="对";temp_flag="try_chui";}
        if (who->query("dntg/donghai") == "mei hua chui")
           {weapon_name="画杆戟"; weapon_id="hua gan ji";weapon_unit="柄";temp_flag="try_ji";}


        if (present(weapon_id, this_player()) && present("ye cha", environment()))
          message_vision("龙王道：您先拿这"+weapon_name+"和夜叉练练吧！\n",me);
        else if (present(weapon_id, environment()) && present("ye cha", environment()))
          message_vision("龙王道：您先拿这"+weapon_name+"和夜叉练练吧！\n",me);
        else if (present(weapon_id, this_player()) || present(weapon_id, environment()))
          {
          message_vision("东海龙王说道：让我找个人先陪您练练？\n",me);
          message_vision("东海龙王一招手，一个夜叉走了过来。\n",me);
          fighter = new ("/d/dntg/donghai/npc/fighter");
          fighter->move(environment(me));
          }
        else if (present("ye cha", environment()))
          message_vision("龙王道：不知那"+weapon_name+"被谁拿去了！\n",me);
        else
          {
          message_vision("$N连忙起身说道："+RANK_D->query_respect(who)+"稍侯，待我想想？\n",me,who);
          message_vision("我这龙宫中有"+weapon_unit+weapon_name+"还凑合着能使，"+RANK_D->query_respect(who)+"若不嫌弃，就送与"+RANK_D->query_respect(who)+"用吧！\n",who);
          who->set_temp("dntg/donghai",temp_flag);
          call_out ("fight_quest",2,who);
          }
        return 1;
    }

  else if (who->query("dntg/donghai") == "hua gan ji" )
    {
    me->command("consider");
    message_vision("从后宫跑来一个龙婆，在龙王耳边小声说了几句话。\n",me);
    call_out ("sendto_maze",3,who);
    return 1;
    }
   command("nod");
  message_vision("$N懒洋洋的说：“要兵器啊？傲来国有的是，去那里弄些吧。”\n",me);
  message_vision("$N顿了顿，又说：“我龙宫的兵器，谅你们这些凡夫俗子也使不了。”\n",me);
  command("wave");
  return 1;
}

void fight_quest (object who)
{
  object me=this_object();
  object fighter,fa_bao;
  string weapon_name,weapon_id,weapon_unit;


  if (who->query("dntg/donghai") == "begin")
    {weapon_name="大砍刀"; fa_bao = new ("/d/dntg/donghai/obj/dakandao");weapon_unit="柄";}
  if (who->query("dntg/donghai") == "da kan dao")
    {weapon_name="九股叉"; fa_bao = new ("/d/dntg/donghai/obj/jiugucha");weapon_unit="支";}
  if (who->query("dntg/donghai") == "jiu gu cha")
    {weapon_name="梅花锤"; fa_bao = new ("/d/dntg/donghai/obj/meihuachui");weapon_unit="对";}
  if (who->query("dntg/donghai") == "mei hua chui")
    {weapon_name="画杆戟"; fa_bao = new ("/d/dntg/donghai/obj/huaganji");weapon_unit="柄";}

  message_vision("东海龙王一招手，一个夜叉抬过一"+weapon_unit+weapon_name+"。\n",me);
  fighter = new ("/d/dntg/donghai/npc/fighter");
  fighter->move(environment(me));
  fa_bao->move(environment(me));
  message_vision("东海龙王说道：＂要我要和我的手下先练练？＂\n",me);
}

void sendto_maze (object who)
{
  object me=this_object();
  message_vision("$N说道："+RANK_D->query_respect(who)+"武功盖世，可到后面的海藏中试一试定海神针铁。\n",me,who);
  call_out ("send_maze",3,who);
}

void send_maze (object who)
{
  object me=this_object();
  message_vision("说着，东海龙王把$N送到了一个地方。\n",who);
  who->move("/d/dntg/donghai/haidimigong");
  message_vision("$N一拱手道："+RANK_D->query_respect(who)+"向前走即可看到那神铁，恕老夫不奉陪了。\n",me,who);
  message_vision("说罢，龙王转身回宫了。\n",me);
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
	if((string)me->query("family/family_name")=="东海龙宫") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"龙王低头想了想：\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"即我门人,当以扫清妖氛为己任。\n"NOR;
	}
	return ("神龙无敌。");
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="东海龙宫")
		return ("你不是本派弟子，生死与本王何干？");
	if(who->query("faith")<1000)
		return ("你在本门名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("本王未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，本王还得想一想");
	command("say 本王这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见敖广向空中一指：\n");
	tell_room(where,"四海神龙何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")
+"抓了起来！");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我东海龙宫弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}


