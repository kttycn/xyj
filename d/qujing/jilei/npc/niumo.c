// created 12/18/1997 by snowcat
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_chuxian(object me);
string ask_cancel();

void create()
{
	set_name("ţħ��", ({ "niumo wang", "niumo", "wang" }));
	set("title", "������");
	set("long", "һλ���Ŀ�ΰ�����ޱȵ�ħ����һ˫ţ������ɷ��һ������㡣\n");
	set("gender", "����");
	set("age", 70);
	set("attitude", "heroism");
	set("class", "yaomo");
	set("per", 10);
	set("str", 40);
	set("con", 30);
	set("max_kee", 1700);
	set("max_gin", 1700);
	set("max_sen", 1700);
	set("force", 1700);
	set("max_force", 1700);
	set("force_factor", 90);
	set("max_mana", 1700);
	set("mana", 1700);
	set("mana_factor", 45);
	set("combat_exp", 1250000);
	set("daoxing", 1500000);

	set_skill("spells", 180);
	set_skill("stick", 160);
	set_skill("dali-bang", 160);
	set_skill("unarmed", 160);
	set_skill("moyun-shou", 160);
	set_skill("dodge", 120);
	set_skill("moshenbu", 120);
	set_skill("parry", 160);
	set_skill("force", 180);
	set_skill("huomoforce", 160);
	set_skill("pingtian-dafa", 180);
	map_skill("force", "huomoforce");
	map_skill("spells", "pingtian-dafa");
	map_skill("stick", "dali-bang");
	map_skill("parry", "dali-bang");
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");

	set("nb_heads",30);
	create_family("���ƶ�", 2, "��");
	set("inquiry", ([
		"cancel": (: ask_cancel :),
		"����": (: ask_chuxian :),
		"kill": (: ask_chuxian :),
	]) );

	setup();
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	call_out ("riding",1);
}

string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("û�õĶ�����");
}
string ask_chuxian(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="���ƶ�") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"ţħ������¶��а���Ц�ݣ�\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"��־����\n"NOR;
	}
	return ("���������ס�");
}

void attempt_apprentice(object ob)
{
	ob=this_player();

	if( (string)ob->query("family/family_name") == "���ƶ�") {
		if( (int)ob->query_skill("pingtian-dafa", 1) < 70 ) {
			command("say ��λ" + RANK_D->query_respect(ob) + "���ƽ�����ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
			command("sigh");
			return;
		}
		if( (int)ob->query("max_mana") > 200
		&& (int)ob->query("max_force") > 200 ) {
			command("nod");
			command("recruit " + ob->query("id"));
			return ;
		}
	}
	command("shake");
	command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "yaomo");
		ob->set("title", "����ɽĦ�ƶ�С��");
		ob->set("kusong/Teach_Niu", 1);
	}
}

void riding ()
{
	command ("mount jinjing shou");
}

void destruct_me (object me)
{
	destruct (me);
}

int check_heads (object me, object ob)
{
	int nb_heads = query("nb_heads")-1;
	object weapon;
	object head;

	me->set("nb_heads",nb_heads);
	if (! ob)
		return nb_heads;
	if (nb_heads <= 0)
		return nb_heads;

	weapon = ob->query_temp("weapon");

	if (! weapon)
		message_vision ("\n$N���һ������$n������ɽ����֮�ƽ�$n��ţͷ����������\n",ob,me);
	else if (weapon->query("skill_type") == "axe")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "blade")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "sword")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "dagger")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "fork")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "hammer")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "spear")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "staff")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷɨ��������\n",ob,weapon);
	else if (weapon->query("skill_type") == "stick")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷɨ��������\n",ob,weapon);
	else if (weapon->query("skill_type") == "throwing")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "whip")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else if (weapon->query("skill_type") == "mace")
		message_vision ("\n$N�߸߾���$n����ɽ�����ش��һ������ţͷ����������\n",ob,weapon);
	else
		message_vision ("\n$N���һ������$n������ɽ����֮�ƽ�$n��ţͷ����������\n",ob,me);

	head = new ("/d/qujing/jilei/obj/head");
	head->move(environment(me));
	return nb_heads;
}

void die ()
{
	object me = this_object();
	object ob = query_temp("last_damage_from");
	object killer=query_temp("my_killer");
	object last =query_temp("last_killed_by");
	string faint=query_temp("last_fainted_from");

	// mon 10/3/98
	if(faint && ob) {
		if(faint!=ob->query("id"))
		set("nb_heads",40); // someone else help, reset count.
	}
	delete_temp("last_fainted_from");
	if(killer!=ob)
		set("nb_heads",40); // someone else help, reset count.

	// mon 7/30/98
	// to prevent other players help to kill niu.
	if(!last) last=ob;
	else if(last!=ob)
			set("nb_heads",40); // someone else help, reset count.

	set_temp("last_killed_by",ob);

	if (check_heads (me, ob) > 0)
	{
		set("kee", 1700);
		set("gin", 1700);
		set("sen", 1700);
		set("eff_kee", 1700);
		set("eff_gin", 1700);
		set("eff_sen", 1700);
		set("force", 1700);
		set("mana", 1700);
		message_vision ("\nֻ��ţǻ��ҡҡ�λ������һ��ţͷ����\n",me);
		if (ob)
			message_vision ("\n$N�����ӵ�����$n���𹥻���\n",me,ob);
		return;
	}

	if (ob)
	{
		ob->set_temp("obstacle/jilei_niumo_killed",1);
		call_out ("li_appearing",1,ob);
	}
	message_vision ("\n�����������������һ����ţħ���Ҳ��\n",me);
	message_vision ("\n$N����������������ԭ��һֻ���ţ������������\n",me);
	message_vision ("�������߹������ý���˩��ţ�����ϣ���$Nǣ���ˡ�\n",me);
	load_object("/obj/empty");
	me->move("/obj/empty");
	call_out ("destruct_me",3,me);
}

void li_appearing (object who)
{
	object li = new ("/d/qujing/jilei/npc/li");

	li->announce_success (who);
	destruct (li);
}

void unconcious ()
{
	die ();
}

int accept_fight(object ob)
{
	ob->apply_condition("killer", 100);
	kill_ob(ob);
	ob->kill_ob(this_object());
	return 1;
}

int test_player (object who)
{
	string *names;
	string name;

	names = who->query_temp("apply/name");
	if (! names)
		return 0;

	if (sizeof(names) < 1)
		return 0;

	name = names[0];

	if (name == "���ȹ���")
		return 1;
	return 0;
}

void kill_ob (object ob)
{
	object me = this_object();
	object where = environment (me);
	object yumian = present ("yumian gongzhu", where);

	if (! test_player (ob))
	{
		message_vision ("$Nһ˫ţ���۵����㣬���һ�����㣡�㣡����\n",me);
		message_vision ("$N���˴��ţ��ԭ����$n���������ص�ͷһ����\n",me,ob);
		message_vision ("$Nһ�����ֲ�������շ���\n",ob);
		ob->move("/d/qujing/jilei/shidong");
		message_vision ("���䡱��$Nˤ��������\n",ob);
		ob->unconcious();
		return;
	}
	message_vision ("\n$N��ŭ���ĸ�������ð�䰳��ң�\n",me);

	set_temp("my_killer",ob);
	call_out ("checking",1,me,ob);
	::kill_ob(ob);
	if (yumian && (! interactive(yumian)) && !yumian->is_fighting())
		yumian->kill_ob(ob);
}

void checking (object me, object ob)
{
	object fabao = present ("fabao",me);

	if (me->is_fighting())
	{
		remove_call_out ("checking");
		call_out ("checking",1,me,ob);
	}
	else
	{
		int i = 45 - ob->query("kar");

		if (i < 10)
			i = 10;
		me->set("nb_heads",i+random(10));
	}
}

