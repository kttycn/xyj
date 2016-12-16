//Cracked by Roath
// zhike.c Öª¿ÍÉ®º
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("Öª¿ÍÉ®", ({ "zhike seng", "seng" }));
	set("long", "Ò»Î»ÄêÇáµÄÉ®ÈË£¬Á³ÉÏ×ÜÊÇ´ø×ÅÈÈÇéµÄĞ¦Èİ¡£\nËû¸ºÔğÔÚ´ËÓ­½ÓÇ°À´²Îìø½øÏãµÄ¿ÍÈË¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);

	set_skill("literate", 20);
	set_skill("unarmed", 25);
	set_skill("dodge", 20);
	set_skill("parry", 25);
	set_skill("force", 10);
	set_skill("spells", 10);
	set_skill("buddhism", 10);
	set_skill("unarmed", 30);
	map_skill("spells", "buddhism");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

        create_family("ÄÏº£ÆÕÍÓÉ½", 4, "µÜ×Ó");
	
	setup();
	add_money("silver", 20);
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting()
	&& !ob->query("env/invisibility") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
    add_action("do_volunteer","volunteer");
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "Öª¿ÍÉ®ÈÈÇéµØËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob) + "£¬»¶Ó­À´µ½ÄÏº£ÆÕÍÓÉ½£¡\n");
	say( "Öª¿ÍÉ®Ëµ£º·²ÆÕÍÓÃÅÈË¿ÉÒÔÓÚ´ËÊØ»¤É½ÃÅ(volunteer)£¬ÒÔÆÚÉıÖ°¡£\n");
}

int do_volunteer()
{
	object me=this_player();
	object* ob;
	int i;
	if((string)me->query("family/family_name")!="ÄÏº£ÆÕÍÓÉ½")
		return notify_fail("Äú²»ÊÇ±¾ÃÅÖĞÈË¡£\n");
	if(me->query("faith")>500)
		return notify_fail("ÄúÊÇ±¾ÃÅ´óÓĞÃûÍûÖ®ÈË£¬Ôõ¸ÒÓĞÀÍÄú×ö¿´ÃÅÕâÑùµÄÔÓÎñÄØ£¿");
	if(me->query("combat_exp")<50000 || me->query("daoxing")<50000)
		return notify_fail("ÊØÃÅÊÇ±È½ÏÎ£ÏÕµÄÊÂ,Äã»¹ÊÇ¶à×ö»ù±¾ĞŞĞĞ°É!\n");
	if (me->query_temp("in_guard"))
		return notify_fail("Öª¿ÍÉ®¶ÔÄãËµ:Äã×¨ĞÄÊØºÃÉ½ÃÅ£¬±ğÏë´òÁ½·İ¹¤¡£\n");
	if(time()-me->query("last_guard")<300)
		return notify_fail("Öª¿ÍÉ®¶ÔÄãËµ£ºÄãÔõÃ´ÕâÃ´¿ìÓÖÒªµ±°àÁË£¿ĞªĞª°É!\n");
	ob = users();
	for (i=sizeof(ob); i>0; i--)
	{
		if (ob[i-1]->query_temp("in_guard"))
			return notify_fail("Öª¿ÍÉ®¶ÔÄãËµ£ºÒÑ¾­ÓĞÈËÊØÉ½ÃÅÁË£¬ÄãÒ»»áÔÙÀ´°É¡£\n");
	}
	tell_object(me,"ÄÇºÃ£¬¾ÍÇëÄãÊØÒ»»á¶ùÉ½ÃÅ°É¡£\n");
	tell_room(environment(me),me->query("name")+"¿ªÊ¼ÔÚÉ½ÃÅÖµÊØ¡£\n");
	me->set("last_guard",time());
	me->set_temp("in_guard","1");
	me->save();
	remove_call_out("end_guard");
	call_out("end_guard",70,me);
	call_out("clone_meng",20,me);
	return 1;
}

void clone_meng(object me)
{
	object ob;
	tell_room(environment(me),"É½ÏÂÍ»È»³åÉÏÀ´Ò»»ïÃÉÃæ´óºº¡£\n");
	ob=new("/d/obj/npc/mengmian");
	ob->set("combat_exp",me->query("combat_exp"));
	ob->move("/d/nanhai/gate");
	call_out("clone_meng", 20, me);
}

void end_guard(object me)
{
	object ob;
	int reward=me->query("combat_exp")/5000;

	me->delete("guard");
	me->add("faith",2+random(4));
	me->add("combat_exp",100+random(reward));
	me->add("potential",30+random(reward/4));
	me->delete_temp("in_guard");
	me->save();
	remove_call_out("clone_meng");
	tell_room(environment(me),me->query("name")+"ÔÚÉ½ÃÅÖµÊØÆÚÒÑÂú¡£\n");
	tell_object(me,"ÄãÔÚÉ½ÃÅÖµÊØÆÚÒÑÂú¡£\n");
	while(ob = present("dahan",environment(me)))
	destruct(ob);
}
void die()
{
	object *me;
	int i;
	me = users();
	for (i = 0; i < sizeof(me); i ++)
		me[i]->delete_temp("in_guard");
	::die();
}
