#include <ansi.h>

inherit NPC;

void create()
{
	set_name("护法", ({ "baobiao" }) );
	set("long", "这是盟主身边的一位护法。\n");
	set("attitude", "friendly");
	set("class", "fighter");

	set("max_sen", 1200);
	set("max_kee", 1500);
	set("max_mana", 4000);
	set("mana", 8000);
	set("max_force", 5000);
	set("mana_factor", 200);
	set("force_factor", 200);
	set("force",1000);
	set("combat_exp", 400000);   
	set("daoxing", 400000);
	set("str", 40);
	set("con", 80);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("force", 250);
	set_skill("moonforce", 250);
	set_skill("spells", 250);
	set_skill("buddhism", 250);
	set_skill("sword", 250);
	set_skill("bainiao-jian", 250);
	set_skill("xiaoyaoyou", 250);
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "moonforce");
	map_skill("sword", "bainiao-jian");
	map_skill("parry", "bainiao-jian");
	map_skill("spells", "buddhism");
	setup();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

void leave()
{
	object owner = this_player();
	message("vision", name() + "向四周张望了一下,说道：既然无事，属下先行告退。\n", environment(), this_object() );
	if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("number",-1);
	destruct(this_object());
}

void show(object who)
{
	string *cname = ({"左护法", "右护法"});
	string *ename = ({"-left", "-right"});

	int current = 0;
	current = (int)who->query_temp("number");

	if(current < 1 || current > 2 )
	{
		destruct(this_object());
		return;
	}

	this_object()->set_name(cname[current-1], ({ (string)who->query("id")+ename[current-1] }) );   

	message_vision("一阵黑风刮过，从中走出一个人，到$N面前行了个礼，大声说道：在下随时听调！\n", who);
	command("follow "+who->query("id"));

	set("owner_id", (string)who->query("id")); 
	set_leader(who);
}

void relay_whisper(object me, string msg)
{
	if (query("owner_id") != me->query("id"))
	{
		message_vision((string)this_object()->query("name") + "对着$N冷哼了一声。\n", me);
		return;
	}
   
	if( strsrch(msg, "chat") != -1 ||
	strsrch(msg, "tell") != -1 ||
	strsrch(msg, "apprentice") != -1 ||
	strsrch(msg, "recruit") != -1 ) 
		return;

	message_vision((string)this_object()->query("name") + "对着$N点了点头。\n", me);
	if (msg)
	{
		call_out ("relaying", 1+random(3), msg);
	}
}

void relaying (string msg)
{
	command ("follow none");
	command (msg);
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 120);
		return 1;
	}
	return ::heal_up() + 1;
}


void init()
{
	object me=this_player();
	object owner;
	int i;
	::init();

	if ( (string)this_object()->query("owner_id") == (string)me->query("id") )
	{
		this_object()->set_leader(me);
	}

	if( this_object()->query("owner_id") != 0 )
	{
		owner = find_player( (string)this_object()->query("owner_id") );
		if( !owner ) owner=find_living( (string)this_object()->query("owner_id") );
		if( !owner )
		{
			call_out ("leave", 1);
		}
	}
}

void die()
{
	object owner;
	if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("number",-1);
	::die();
}
