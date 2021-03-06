inherit NPC;
string expell_me(object me);

void create()
{
	set_name("香姬", ({"xiang ji", "xiang", "fox"}));
	set("gender", "女性");
	set("age", 18);
	set("long",
"她长的美艳无比，却媚而不俗——半点也看不出是狐而不是人。\n"
"因为生来的带的一股香气，使她有别于同类，所以一直很孤独。\n"
"所以这才找了这么一个省事的差事……\n");
	set("title", "古墓倩狐");
	set("per", 40);
	set("int", 40);
	set("cor",40);
	set("class", "huli");
	set("combat_exp",400000);
	set_skill("force",120);
	set_skill("parry",120);
	set_skill("dodge",120);
	set_skill("literate",120);
	set_skill("needle",120);
	set_skill("spells",120);
	set_skill("xuanhu-xinfa",120);
	set_skill("tianyi-zhen",120);
	set_skill("huxing-steps",120);
	set_skill("xuanhu-shentong",120);
	map_skill("force","xuanhu-xinfa");
	map_skill("needle","tianyi-zhen");
	map_skill("dodge","huxing-steps");
	map_skill("spells","xuanhu-shentong");
	set("attitude", "heroic");
	create_family("轩辕古墓", 2, "弟子");

	set("inquiry", ([
		"叛门": (: expell_me :),
		"leave": (: expell_me :),
	]) );
	setup();
	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/xuanyuan/obj/needle1")->wield();
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="轩辕古墓")
	{
		me->set_temp("xuanyuan/betray", 1);
		return ("要走？咳……你可想好了——会让你受不了的。你还要走吗？(zou)\n");
	}
	return ("你不是我们的人吧？你要走就走好了——\n");
}
void init()
{
	add_action("do_accept", "zou");
}
void do_accept()
{
	object weapon;
	object me=this_player();
	if(!me-query_temp("xuanyuan/betray"))
		message_vision("$N道：你走什么走？\n",this_object());
		message_vision("$N道：不错，我整天在这儿，鼻子都熏坏了！\n", me);
		me->add("betray/count", 1);
		me->add("betray/xuanyuan", 1);
		if(me->query_skill("xuanhu-shentong"))
			me->delete_skill("xuanhu-shentong");
		if(me->query_skill("tianyi-zhen"))
			me->delete_skill("tianyi-zhen");
		if(me->query("family_wp/id")&&weapon = present(me->query("family_wp/id"),me))
			destruct(weapon);
		me->set("combat_exp", me->query("combat_exp")*80/100);
		me->set("daoxing", me->query("daoxing")*80/100);
		me->delete("faith");
		me->delete("family");
		me->delete("class");
		me->delete("family_wp");
		me->set("title", "普通百姓");
		if( (int)me->query("score") < 1000 )
			me->set("score", 0);
		else
			me->add("score", -1000 );
		me->save();
}
