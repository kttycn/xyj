inherit NPC;
string expell_me(object me);

void create()
{
	set_name("�㼧", ({"xiang ji", "xiang", "fox"}));
	set("gender", "Ů��");
	set("age", 18);
	set("long",
"�����������ޱȣ�ȴ�Ķ����ס������Ҳ�������Ǻ��������ˡ�\n"
"��Ϊ�����Ĵ���һ��������ʹ���б���ͬ�࣬����һֱ�ܹ¶���\n"
"�������������ôһ��ʡ�µĲ��¡���\n");
	set("title", "��Ĺٻ��");
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
	create_family("��ԯ��Ĺ", 2, "����");

	set("inquiry", ([
		"����": (: expell_me :),
		"leave": (: expell_me :),
	]) );
	setup();
	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/xuanyuan/obj/needle1")->wield();
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="��ԯ��Ĺ")
	{
		me->set_temp("xuanyuan/betray", 1);
		return ("Ҫ�ߣ��ȡ����������ˡ����������ܲ��˵ġ��㻹Ҫ����(zou)\n");
	}
	return ("�㲻�����ǵ��˰ɣ���Ҫ�߾��ߺ��ˡ���\n");
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
		message_vision("$N��������ʲô�ߣ�\n",this_object());
		message_vision("$N������������������������Ӷ�Ѭ���ˣ�\n", me);
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
		me->set("title", "��ͨ����");
		if( (int)me->query("score") < 1000 )
			me->set("score", 0);
		else
			me->add("score", -1000 );
		me->save();
}
