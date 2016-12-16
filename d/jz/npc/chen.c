// by snowcat 

inherit NPC;

void check(object who);

void create()
{
	set_name("�¹���", ({"chen guangrui", "chen", "guangrui"}));
	set("long", "�¹���������֮�������������������״Ԫ��\n");
	set("title", "�������");
	set("gender", "����");
	set("age", 26);
	set("per", 35);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("shen_type", 1);
	set("combat_exp", 40000);
	set("daoxing", 100000);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("literate", 180);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("spells", 50);
	set("max_gin",400);
	set("max_kee",400);
	set("max_sen",400);
	set("max_force",400);
	set("max_mana",400);
	set("force_factor",20);
	set("chat_chance",10);

	setup();
	carry_object("/d/obj/cloth/changpao")->wear();
}

void check(object who)
{
	if( !who->query_temp("obstacle/jz_libiao_killed") ||
	!who->query_temp("obstacle/jz_liuhong_killed") )
	{
		command("ah "+who->query("id"));
		command("sigh");
		remove_call_out("check");
		destruct(this_object());
		return;
	}
	who->set_temp("obstacle/can_see_king","begin");
	who->save();
	message_vision("���д���������������$N������¹���ȥ���̫�ڻʵۡ�\n", who);
	command("say ��л"+who->query("name")+"����֮����");
	command("follow "+who->query("id"));
	remove_call_out("check");
	return;
}

