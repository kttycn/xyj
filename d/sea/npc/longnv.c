// Changed by sjmao  09-11-97
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int rank_me();
string expell_me(object me);

void create()
{
	set_name("ÁúÅ®", ({"long nv","gongzhu","long","princess"}));
	set("long","×ÏÔÆ¹¬Ö÷ÈË£¬ÁúÍõµÄÅ®¶ù£®\n");
	set("gender", "Å®ĞÔ");
	set("age", 20);
	set("int", 25+random(5));
	set("title", "×ÏÔÆ¹«Ö÷");
	set("attitude", "peaceful");
	set("combat_exp", 350000);
	set("daoxing", 100000);

	set("rank_info/respect", "¹«Ö÷µîÏÂ");
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
		"Àë¹¬": (: expell_me :),
		"Ö°Î»": (: rank_me :),
		"leave": (: expell_me :),
	]));

	create_family("¶«º£Áú¹¬", 2, "Ë®×å");
	setup();

	carry_object("/d/obj/cloth/pinkskirt")->wear();
	carry_object("/d/sea/obj/yincha")->wield();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "¶«º£ÁúÉñ")
		return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
	if( (string)me->query("family/family_name") == "¶«º£Áú¹¬"){
		if( exp <= 100000 ) {
			return notify_fail("ÄãÏÖÔÚÎäÑ§Ì«µÍ£¬»¹²»ÄÜÀ´ÒªÊ²Ã´Ö°Î»£®\n");
		} else if(exp <= 500000 ){
			me->set("nick", HIC"¶«º£Áú¹¬"NOR+RED"¡ô"BLU"Ñ²µîÏº±ø"NOR);
		} else if(exp <= 1000000 ){
			me->set("nick", HIC"¶«º£Áú¹¬"NOR+RED"¡ô"YEL"Ñ²º£Ò¹²æ"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIC"¶«º£Áú¹¬"NOR+RED"¡ô"RED"»¤¹¬Ê¹Õß"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIC"¶«º£Áú¹¬"NOR+RED"¡ô"MAG"ÎŞµĞ½«¾ü"NOR);
		} else {
			me->set("nick", HIC"¶«º£Áú¹¬"NOR+RED"¡ô"CYN"µ¸º£ÁúÍõ"NOR);
		}

		tell_object(me, "ÁúÅ®¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("nick")+"¡£\n");
		tell_room(environment(me),
"ÁúÅ®¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("nick")+"¡£\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""+me->query("nick")+HIC"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	 command("jump");
	command("say ÎÒÓÖ¶àÁËÒ»¸öµÜ×ÓÒ®£¡\n");
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
  if((string)me->query("family/family_name")=="¶«º£Áú¹¬")
    {
      message_vision("×ÏÔÆ¹«Ö÷ÄÑ¹ıµØÍû×Å$N£¬ÓûÑÔÓÖÖ¹¡£\n", me);
      return ("ÄãÈ¥ÎÊÎÒ¸¸Íõ°É¡£\n");
    }
  return ("È¥ÎÊÎÊ±ğÈË°É£¡ÎÒÔõÃ´»áÖªµÀ£¡¡\n");
}
ÿ