// Changed by sjmao  09-11-97
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int rank_me();
string expell_me(object me);

void create()
{
	set_name("龙女", ({"long nv","gongzhu","long","princess"}));
	set("long","紫云宫主人，龙王的女儿．\n");
	set("gender", "女性");
	set("age", 20);
	set("int", 25+random(5));
	set("title", "紫云公主");
	set("attitude", "peaceful");
	set("combat_exp", 350000);
	set("daoxing", 100000);

	set("rank_info/respect", "公主殿下");
	set("class","dragon");
	set("per", 30);
	set("max_kee", 900);
	set("max_sen", 700);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("max_mana", 500);
	set("mana", 400);
	set("mana_factor", 30);

	set_skill("literate", 90);
	set_skill("unarmed", 100);
	set_skill("dodge", 120);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("fork", 100);
	set_skill("spells", 100);
	set_skill("seashentong", 100);
	set_skill("dragonfight", 100);
	set_skill("dragonforce", 100);
	set_skill("dragon-cha", 100);
	set_skill("dragon-steps", 120);
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "dragon-cha");
	map_skill("parry", "dragon-cha");
	map_skill("dodge", "dragon-steps");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		  (: cast_spell, "hufa" :),
		  (: perform_action, "fork", "fengbo" :),
	}) );
	set("inquiry", ([
		"离宫": (: expell_me :),
		"职位": (: rank_me :),
		"leave": (: expell_me :),
	]));

	create_family("东海龙宫", 2, "水族");
	setup();

	carry_object("/d/obj/cloth/pinkskirt")->wear();
	carry_object("/d/sea/obj/yincha")->wield();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "东海龙神")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "东海龙宫"){
		if( exp <= 100000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 500000 ){
			me->set("nick", HIC"东海龙宫"NOR+RED"◆"BLU"巡殿虾兵"NOR);
		} else if(exp <= 1000000 ){
			me->set("nick", HIC"东海龙宫"NOR+RED"◆"YEL"巡海夜叉"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIC"东海龙宫"NOR+RED"◆"RED"护宫使者"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIC"东海龙宫"NOR+RED"◆"MAG"无敌将军"NOR);
		} else {
			me->set("nick", HIC"东海龙宫"NOR+RED"◆"CYN"蹈海龙王"NOR);
		}

		tell_object(me, "龙女对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"龙女对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	 command("jump");
	command("say 我又多了一个弟子耶！\n");
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
      message_vision("紫云公主难过地望着$N，欲言又止。\n", me);
      return ("你去问我父王吧。\n");
    }
  return ("去问问别人吧！我怎么会知道！n");
}
�