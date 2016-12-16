#include "champion.h"

inherit NPC;
inherit F_SAVE;
int brag();
void loadall(object me);

int get_position_int ()
{
	return 1;
}

void create()
{
	set_name(get_honor_str(), ({ "meng zhu", "numberone", "mengzhu" }) );
	set("title", get_respect_str());
	set("gender", "����" );
	set("long",get_respect_str()+"��\n");
	set("current_player","none of us");
//	set("chat_chance", 40);
//	set("chat_msg", ({
//		HIR"�Ҿ������ǵ������������������������ԣ�\n"NOR,
//	}) );

	setup();
}

void init()
{
	object me = this_object();

	add_action("do_save", "save");
	add_action("do_bandage","bandage");
	add_action("do_kill", "kill");
	add_action("do_steal", "steal");
	add_action("do_ji", "ji");
	add_action("do_cast", "cast");
	add_action("do_exert", "exert");
	add_action("do_perform", "perform");
	add_action("do_bian", "bian");
	add_action("do_yao","yaozhang");

	if (me->query("current_player")=="none of us")
		me->reset_me(me);    
	me->restore();
	me->fully_recover(me);
	me->setup();
}

int do_yao()
{
	object zhang,me,ob;
	me = this_player();
	ob = this_object();
	zhang = new("/d/biwu/obj/zhang");
	if(ob->query("id") == me->query("id") && (!present("shenstaff",me)))
	{
//		find(id1);
		zhang->move(me);
		message_vision("$N����$nһ�����ȡ�\n",ob,me);
		return 1;
	}
	tell_object(me,"��ϹҪʲô��\n");
	return 1;
}
