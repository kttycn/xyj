//Cracked by Roath
// zhike.c ֪��ɮ�
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("֪��ɮ", ({ "zhike seng", "seng" }));
	set("long", "һλ�����ɮ�ˣ��������Ǵ��������Ц�ݡ�\n�������ڴ�ӭ��ǰ����������Ŀ��ˡ�\n");
	set("gender", "����");
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

        create_family("�Ϻ�����ɽ", 4, "����");
	
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
	say( "֪��ɮ�����˵������λ" + RANK_D->query_respect(ob) + "����ӭ�����Ϻ�����ɽ��\n");
	say( "֪��ɮ˵�����������˿����ڴ��ػ�ɽ��(volunteer)��������ְ��\n");
}

int do_volunteer()
{
	object me=this_player();
	object* ob;
	int i;
	if((string)me->query("family/family_name")!="�Ϻ�����ɽ")
		return notify_fail("�����Ǳ������ˡ�\n");
	if(me->query("faith")>500)
		return notify_fail("���Ǳ��Ŵ�������֮�ˣ����������������������������أ�");
	if(me->query("combat_exp")<50000 || me->query("daoxing")<50000)
		return notify_fail("�����ǱȽ�Σ�յ���,�㻹�Ƕ����������а�!\n");
	if (me->query_temp("in_guard"))
		return notify_fail("֪��ɮ����˵:��ר���غ�ɽ�ţ���������ݹ���\n");
	if(time()-me->query("last_guard")<300)
		return notify_fail("֪��ɮ����˵������ô��ô����Ҫ�����ˣ�ЪЪ��!\n");
	ob = users();
	for (i=sizeof(ob); i>0; i--)
	{
		if (ob[i-1]->query_temp("in_guard"))
			return notify_fail("֪��ɮ����˵���Ѿ�������ɽ���ˣ���һ�������ɡ�\n");
	}
	tell_object(me,"�Ǻã���������һ���ɽ�Űɡ�\n");
	tell_room(environment(me),me->query("name")+"��ʼ��ɽ��ֵ�ء�\n");
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
	tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");
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
	tell_room(environment(me),me->query("name")+"��ɽ��ֵ����������\n");
	tell_object(me,"����ɽ��ֵ����������\n");
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
