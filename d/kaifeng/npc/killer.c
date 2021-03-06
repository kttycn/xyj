// killer.c

inherit NPC;
#include <ansi.h>;

string ask_me();

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("long","这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",60000);
	set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_gin", 800);
	set("max_kee", 800);
	set("max_sen", 800);
	set("max_force", 800);
	set("max_mana", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("inquiry", ([
		"比武大会" : (: ask_me :),
	]));

	setup();

	carry_object("/d/obj/cloth/cloth")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void init()
{
	::init();	
	add_action("do_bihua", ({ "fight", "kill" }));
	add_action("do_halt", "halt");
}

string ask_me()
{
	object* ob;
	int i;
	ob = users();

	if ( !wizardp(this_player()) ) return "你无权召开比武大会！\n";

	command("chat* hi");
	command("chat 现在比武大会正式开始，全体集合！");
	for ( i=sizeof(ob); i>0; i-- ) {
		ob[i-1]->move(environment());
	}

	return "好，现在比武大会正式开始，全体集合！\n";
}

int do_bihua(string arg)
{     
	object ob1, ob2;

	ob1 = this_player();
        
	if (!arg) return 0;
	ob2 = present(arg, environment(ob1));
	if (!ob2) return 0;
	if ( ob2 == this_object() )
	{
		command("say " + ob1->name() + "，你不能跟我比划！");
		return 1;
	}

	if ( query_temp("busy") ) {
		write("每次只能有两人参加比武。\n");
		return 1;
	}

	if( !ob1->query_temp("dagu") ) {
        write("公平子说道: 比擂者必须先打鼓比擂！\n");
		return 1;
	}

	if( !ob2->query_temp("dagu") ) {
		write("公平子说道: 比擂者必须先打鼓比擂！\n");
		return 1;
	}

	if( query_verb()=="fight" && userp(ob2) && ob2->query_temp("pending/fight") !=ob1 )
		return 0;

	if (!ob2->is_character()) return 0;

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");             
        
	CHANNEL_D->do_channel(this_object(), "chat", ob1->name() 
		+ "与" + ob2->name() + "，现在" + environment()->query("short") + "开始比武论剑！\n");

	set_temp("busy",1);
	call_out("observe",1,ob1,ob2);

	return 0;
}

int observe(object ob1,object ob2)
{
	if(ob1->is_fighting()) 
	{
		call_out("observe",1,ob1,ob2);
		return 1;
	}

	this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

	if (ob1->is_ghost()) {
		command("chat " + ob1->name() + "不幸身亡了！\n");
		return 1;
	}

	if (ob2->is_ghost()) {
		command("chat " + ob2->name() + "不幸身亡了！\n");
		return 1;
	}

	if ( !present(ob1, environment()) ) 
	{
		command("chat " + ob1->name() + "落荒而逃了！\n");
		return 1;
	}

	if ( !present(ob2, environment()) ) 
	{
		command("chat " + ob2->name() + "落荒而逃了！\n");
		return 1;
	}
           
        if (ob1->query_temp("halted"))
         {
	       ob1->delete_temp("halted");
               command("chat " + ob1->name() + 
                       "中途放弃比武！\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->name() + 
                       "中途放弃比武！\n");
                return 1;
         }

	if ( ob1->query("kee")*2 > ob1->query("max_kee")) 
	{
		if  (ob2->query("kee")*2 > ob2->query("max_kee")) {
			command("chat " + ob1->name() 
				+ "与" + ob2->name() + "比武不分胜负！\n");
			return 1;
		}
		command("chat " + ob1->name() 
			+ "比武战胜" + ob2->name() + "！\n");
	}
	else
	{
		command("chat " + ob2->name() 
			+ "比武战胜" + ob1->name() + "！\n");
	}
	ob1->delete_temp("dagu");
	ob2->delete_temp("dagu");
	return 1;

}

int do_halt()
{
	object me = this_player();

	if (me->is_fighting())
	me->set_temp("halted",1);
	return 0;
}
