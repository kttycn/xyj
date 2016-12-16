//puti.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string avenge();
string ask_chuxian(object me);
string ask_cancel();

void create()
{
	set_name("�ز�������", ({"dizang pusa", "pusa"}));
	set("long", "�������񣬴�����磬һ���ྲ��
�������������ܵظ������¹��ĵز���������\n");
	set("gender", "����");
	set("class", "youling");
	set("age", 70);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30+random(5));
	set("nkgain",790);
	set("max_kee", 3000);
	set("max_gin", 2500);
	set("max_sen", 2000);

	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 200);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 200);

	set("combat_exp", 2000000);
	set("daoxing", 4000000);

	set_skill("stick", 260);
	set_skill("kusang-bang", 260);
	set_skill("unarmed", 270);
	set_skill("whip", 300);
	set_skill("hellfire-whip", 300);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("literate", 250);
	set_skill("spells", 300);
	set_skill("force", 290);
	set_skill("tonsillit", 290);
	set_skill("ghost-steps", 280);
	set_skill("gouhunshu", 280);
	set_skill("jinghun-zhang", 270);
	set_skill("zhuihun-sword", 250);
	set_skill("sword", 250);

	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
	map_skill("dodge", "ghost-steps");
	map_skill("spells", "gouhunshu");
	map_skill("parry", "hellfire-whip");
	map_skill("whip", "hellfire-whip");
	map_skill("sword", "zhuihun-sword");
	map_skill("stick", "kusang-bang");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "whip", "three" :),
		(: perform_action, "whip", "lunhui" :),
		(: cast_spell, "curse" :),
		(: cast_spell, "inferno" :),
		(: cast_spell, "heiwu" :),
		(: cast_spell, "hunfei" :)
	}) );
	set("nk_gain", 600);
	set("inquiry",([
		"�л�": (: ask_chuxian :),
		"kill": (: ask_chuxian :),
		"cancel": (: ask_cancel :),
		"����": (: avenge :)
	]));

	set_temp("apply/armor", 50);
	set_temp("apply/dodge", 50);

	create_family("���޵ظ�", 1, "���");
	setup();

	carry_object("/d/obj/cloth/baipao")->wear();
	carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="���޵ظ�")
		return ("�㲻�Ǳ��ɵ��ӣ������뱾���θɣ�");
	if(who->query("faith")<1000)
		return ("���ڱ���������������������Ŭ�����С�");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("����δ����Ѷ");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("��������������һ��");
	command("say �������ȥΪ�㱧��");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"ֻ���ز������������һָ��\n");
	tell_room(where,"����С����ڣ���ȥ��"+killer->query("name")+"ץ����\n");
	tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")+"ץ��������");
	killer->move(where);
	tell_room(where,killer->query("name")+"���ӿ�������������\n");
	command("say ������������ɱ�������޵ظ�����");
	this_object()->kill_ob(killer);
	return("��������");
}
void attempt_apprentice(object ob, object me)
{
	if ( (string)ob->query("family/family_name")=="���޵ظ�") {
		if (((int)ob->query("combat_exp") < 350000 )) {
			command("say " + RANK_D->query_rude(ob) + "�������è�İ�ʽҲ�ҵ������ﶪ�����ۣ�");
			return;
		}
		command("grin");
		command("say �ܺã�" + RANK_D->query_respect(ob) +
			 "���Ŭ�������ձض��гɡ�\n");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
		 "������ȥѧЩ��������ɣ�\n");
	return;
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
	if((string)me->query("family/family_name")=="���޵ظ�") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"�ز�����������¶��а���Ц�ݣ�\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"���Ŭ�����������ձض��гɡ�\n"NOR;
	}
	return ("ƶɮ�����ס�");
}
