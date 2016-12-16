inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
	set_name("�ظ�", ({"qin fu", "qin", "fu", "master"}));
	set("title", "�������ܼ�");
	set("gender", "����");
	set("age", 38);
	set("str", 30);
	set("int", 25);
	set_skill("spear", 60);
	set_skill("force", 75);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("yanxing-steps", 60);
	set_skill("bawang-qiang", 60);
	set_skill("lengquan-force", 75);
	set_skill("unarmed", 75);
	set_skill("changquan", 75);
	map_skill("force", "lengquan-force");
	map_skill("unarmed", "changquan");
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
	map_skill("dodge", "yanxing-steps");
	set("max_sen", 200);
	set("max_kee", 700);
	set("force", 550);
	set("max_force", 500);
	set("force_factor", 30);
	set("combat_exp", 75000);
	set("inquiry", ([
		"תҵ": (: expell_me :),
		"leave": (: expell_me :),
	]) );

	create_family("������", 3, "��");

	setup();

	carry_object("/d/qujing/kusong/obj/tongjia")->wear();
	carry_object("d/obj/weapon/stick/mugun")->wield();
}

void attempt_apprentice(object ob)
{
	ob=this_player();

	if( (string)ob->query("family/family_name") == "������") {
		command("say ���ͬ�����ˣ����ҵ������ҵ���\n");
		return;
	}
	command("haha");
	command("recruit " + ob->query("id"));              
	return ;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "fighter");
		ob->set("title", "���������Ĵ�����");
	}
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="������") {
		me->set_temp("betray", 1);
		return ("���Ҵ����ɷ���ȴ���ܷ������Ը��(agree)?");
	}
	return ("ȥ����Ԭ�����ɣ�������֪����");
}

void init()
{
	::init();
	add_action("do_agree", "agree");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray"))
	{
		message_vision("$N���������Ը�⡣\n\n", this_player());
		command("say �����ȥ�ɣ������ն񣬺���Ϊ֮������");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/fighter", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		if( this_player()->query_skill("lengquan-force") )
			this_player()->delete_skill("lengquan-force");
		if( this_player()->query_skill("baguazhou") )
			this_player()->delete_skill("baguazhou");
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "��ͨ����");
		this_player()->set_temp("betray", 0);
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->save();
		return 1;
		}
	return 0;
}
