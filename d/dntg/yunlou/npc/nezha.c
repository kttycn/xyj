// created 4/12/1998 by bbs
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);
string avenge();

void create()
{
  set_name("哪吒", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "三坛海会之神");
  create_family("陷空山无底洞", 1, "弟子");
  set("class", "xian");
  set("long", "一位唇红齿白的美少年。\n");
  set("gender", "男性");
  set("age", 16);
  set("attitude", "heroism");
  set("rank_info/respect", "小太子");
  set("rank_info/rude", "乳臭未干的小儿");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("con", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 2000);
  set("max_gin", 1800);
  set("max_sen", 3000);
  set("force", 2600);
  set("max_force", 4000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 5000);
  set("mana_factor", 120);
  set("combat_exp", 1500000);
  set("daoxing", 2000000);

  set_skill("spells", 280);
  set_skill("dao", 250);
  set_skill("unarmed", 280);
  set_skill("yinfeng-zhua", 280);
  set_skill("dodge", 280);
  set_skill("literate", 220);
  set_skill("lingfu-steps", 280);
  set_skill("parry", 280);
  set_skill("force", 280);
  set_skill("huntian-qigong", 280);
  set_skill("blade", 280);
  set_skill("sword", 300);
  set_skill("qixiu-jian", 290);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("parry", "huoyun-qiang");
  map_skill("sword", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
  set("inquiry", ([
	"name": "我乃托塔天王三太子李哪吒是也。",
	"here": "这里是托塔天王府。",
	"rumors": "玉帝敕封家严为降魔大元帅，在下为三坛海会之神，专管降妖除魔。",
	"玉鼠精": "无底洞的玉鼠精？那是我爹的义女。",
	"火尖枪": "送人了！",
	"复仇" : (: avenge :),
	]));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: cast_spell, "bite" :),
		(: cast_spell, "huanying" :),
		(: cast_spell, "jushu" :),
		(: perform_action, "sword", "qijian" :),
		(: perform_action, "sword", "yaowu" :)
	}) );
  setup();
  carry_object("/d/obj/cloth/taijicloth")->wear();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/sword/qingfeng")->wield();
  if ("/d/obj/fabao/huntian-ling"->in_mud())
    carry_object("/d/obj/fabao/huntian-fake");
  else
    carry_object("/d/obj/fabao/huntian-ling");
  if ("/d/obj/fabao/qiankun-quan"->in_mud())
    carry_object("/d/obj/fabao/qiankun-fake");
  else
    carry_object("/d/obj/fabao/qiankun-quan");
}

void attempt_apprentice(object ob)
{
  if ((string)ob->query("family/family_name")=="陷空山无底洞") {
	if(ob->query("obstacle/wudidong")=="done") {
		command("say 其实武功并无正邪之分，重要的是人心善恶。");
		command("say "+RANK_D->query_respect(ob)+"既然有心向善，看在我妹子的份上，就收下你吧。");
		command("recruit "+ob->query("id"));
	}
	else {
		command("say "+RANK_D->query_respect(ob)+"是无底洞的弟子，拜我不大合适吧！");
		command("say "+RANK_D->query_respect(ob)+"若愿意学，看在我妹子的份上，我到可以点拨一二。");
	}
  }
  else {
  	command("say 我不认识你。");
	command("sorry");
  }
}

int prevent_learn(object me, string skill)
{
  int myyaofa=me->query_skill("yaofa",1);

  if (skill == "dao") {
	if(myyaofa!=0) {
		command("sigh");
		command("say "+RANK_D->query_respect(me)+"妖气太重，不能学道家仙法。");
		return 1;
	}
  }
  return 0;
}

void die()
{
  int i;
  object *inv;
  string msg;

  if(environment()) {
    msg="$N恨恨地道：小爷我这就去告御状，有种你就在这儿等着！\n";
    msg+="$N化道金光，径往南天门方向而去。\n\n";
    message_vision(msg, this_object(), this_player());
    inv=all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
      if (inv[i]->query("no_drop")) continue;
      do_drop(this_object(), inv[i]);
    }
  }
  destruct(this_object());
}

int do_drop(object me, object obj) 
{
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
            else {
                 message_vision( sprintf("$N丢下一%s$n。\n", undefinedp(obj->query_temp("unit"))? "个":obj->query_temp("unit") ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
           else {
             message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")), me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
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

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="陷空山无底洞")
		return ("你不是洞内弟子，生死与我何干？");
	if(who->query("faith")<1000)
		return ("你在本门名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("本太子未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，本太子还得想一想");
	command("say 本太子这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见哪吒向空中一指：\n");
	tell_room(where,"护洞老魔何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我陷空山无底洞弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}
