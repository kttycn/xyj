// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
	set_name("ˮԳ��ʥ", ({"shuiyuan dasheng","shuiyuan", "dasheng"}));
	set("long","����ϙ�Ǻ��ף������ɾ���������������ϙ���������������\n");
	set("gender", "����");
	set("age", 60);
	set("int", 25);
	set("attitude", "heroism");
	set("combat_exp", 1200000);
	set("daoxing", 500000);

	set("eff_dx", -50000);
	set("nkgain", 500);

//	set("class","yaomo");
	set("per", 10);
	set("str", 30);
	set("max_kee", 1600);
	set("max_sen", 1600);
	set("force", 2000);
	set("max_force", 1500);
	set("force_factor", 70);
	set("max_mana", 1000);
	set("mana", 2000);
	set("mana_factor", 60);
	set_skill("unarmed", 120);
	set_skill("dodge", 110);
	set_skill("force", 110);
	set_skill("parry", 110);
	set_skill("spells", 120);
	set_skill("fork", 110);
	set_skill("yueya-chan", 140);
	map_skill("parry", "yueya-chan");
	map_skill("fork", "yueya-chan");
	setup();

	carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
}

void die ()
{
	object me = this_object();
	object ob, corpse;

	if( !ob = query_temp("last_damage_from") )
		ob= this_player();
	ob->set_temp("kill_yuan", 1);
	message_vision ("\n$N�����ڵأ����ˡ�\n",me);
	corpse = CHAR_D->make_corpse(me,ob);
	corpse->move(environment(me));
	load_object("/obj/empty");
	me->move("/obj/empty");
	call_out ("destruct_me",3,me);
} 


void unconcious ()
{
	die ();
}


void destruct_me (object me)
{
	destruct (me);
}
