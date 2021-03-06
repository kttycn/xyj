#include <ansi.h>
inherit NPC;
int rank_me();

void create()
{
	set_name("胡秋娘", ({ "hu qiuniang", "hu" }));
	set("long", "一位娇俊无比的女子，不知站着干吗？\n");
	set("gender", "女性");
	set("age", 17);
	set("attitude", "heroism");
	set("per", 30);
	set("max_kee", 700);
	set("max_gin", 700);
	set("max_sen", 700);
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 60);
	set("max_mana", 700);
	set("mana", 400);
	set("mana_factor", 60);
	set("combat_exp", 410000);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("force", 50);
	set_skill("spells", 50);
	set_skill("unarmed", 50);
	set_skill("staff", 50);
	set_skill("gouhunshu", 50);
	set_skill("tonsillit", 50);
	set_skill("ghost-steps", 50);
	set_skill("jienan-zhi", 50);
	set_skill("lunhui-zhang", 50);
	map_skill("unarmed", "jienan-zhi");
	map_skill("force", "tonsillit");
	map_skill("spells", "gouhunshu");
	map_skill("staff", "lunhui-zhang");

	set("inquiry", ([
		"职位": (: rank_me :),
	]) );

	setup();
	carry_object("/d/obj/cloth/gongpao")->wear();
	carry_object("/d/qujing/biqiu/obj/ring")->wear();
	carry_object("/d/qujing/biqiu/obj/neck")->wear();
	carry_object("/d/qujing/biqiu/obj/wrists")->wear();
}


void die ()
{
	object me = this_object();
	object ob;
         ob=new("/d/qujing/xuanyuan/obj/pipa");
	message_vision ("\n$N扑在地上现了原身，原是一只琵琶精。\n",me);
          ob->move(environment());//原来ob->move(environment(this_object()));
//          call_out("destory",1,me); 
          destruct(me);
}

void destory(object me)
{
	destruct(me);
}

void unconcious ()
{
	die ();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "妖媚狐仙")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
	if( (string)me->query("family/family_name") == "轩辕古墓"){
		if( exp <= 500000 ) {
			return notify_fail("你现在武学太低，还不能来要什么职位．\n");
		} else if(exp <= 1000000 ){
			me->set("nick", WHT"轩辕古墓"NOR+RED"◆"BLU"偷情玄狐"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", WHT"轩辕古墓"NOR+RED"◆"YEL"离魂妖狐"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", WHT"轩辕古墓"NOR+RED"◆"RED"迷情狐王"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", WHT"轩辕古墓"NOR+RED"◆"MAG"天星鬼皇"NOR);
		} else {
			me->set("nick", WHT"轩辕古墓"NOR+RED"◆"CYN"轩辕天魔"NOR);
		}

		tell_object(me, "胡秋娘对你说：你可以做"+me->query("nick")+"。\n");
		tell_room(environment(me),
"胡秋娘对"+me->query("name")+"说：你可以做"+me->query("nick")+"。\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","现授予本门弟子"+me->query("name")+""+me->query("nick")+HIC"一职。恭请各位仙长多加捧场！");
		me->save();	
	}
	return 1;
}
