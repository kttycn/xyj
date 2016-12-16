
inherit NPC;

void create()
{
	set_name("毛毛虫", ({ "south com", "south"}));
	set("age", 40);
	set("gender", "男性");
	set("long", "他就是毛毛虫，常不来MUD里转，菲飞就请他到这里来和大家砌城啦。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 33);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}

        
	setup();
	
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) )
		
		command( "addin" );
	
}

