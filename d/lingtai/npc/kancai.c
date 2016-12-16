// worker.c

inherit NPC;
string ask_kancai();

void create()
{
	set_name("�����ʿ", ({ "kancai taoist", "dao shi", "dao" }) );
	set("gender", "����" );
	set("age", 35);
	set("per", 30);
	set("class", "taoist");
	set("long", "һλ����������ɽ�е�����ġ�\n");
	set("combat_exp", 10000);
	set("daoxing", 20000);

	set("attitude", "peaceful");
	set_skill("axe", 10);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("unarmed", 20);
	set("chat_chance",5);
	set("chat_msg",({
		"ֻ�������ʿ�������Ƽ������Ͼ��֣����»Ĳ�·��Ѱ��\n",
		"�����ʿ��������ɽ���������꣬�Ͻ���ʱ�ɴ��\n",
		"�����ʿ������������ã���ľ�������Ʊ߹ȿ����У���н���ƣ���Ц�����顣\n",
		"�����ʿ������������괦�����ɼ�������������ͥ��\n",
	}));
	set("inquiry", ([
		"����": (: ask_kancai :),
	]));

	setup();
	add_money("coin", 50);
	carry_object("/d/lingtai/obj/axe")->wield();
}

int accept_fight(object me)
{
	me=this_player();
	if((int)this_player()->query("combat_exp") < 30000) {
		this_object()->set("combat_exp", (int)this_player()->query("combat_exp")+500);
	}
	return 1;
}

string ask_kancai()
{
	object me=this_player();
	object futou=present("lumber axe",this_object());
	if((string)me->query("family/family_name")!="����ɽ���Ƕ�")
		return ("�����Ǳ������ˡ�");
	if(me->query("faith")>200)
		return ("���Ǳ��Ŵ�������֮�ˣ����������������������أ�");
	if(!("lumber axe"))return ("�Ѿ�����ȥ�����ˡ�");
	me->set("lingtai/kancai",1);
	futou->move(me);
	return ("��������������ȥ���ҿ�����ɡ�");
}
