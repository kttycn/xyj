inherit NPC;

int start_change(string arg);

void create()
{
	set_name("ѩɽ����", ({"shi zhe"}));
	setup();
}

void init()
{
	::init();
	add_action("start_change", "change");
}

int start_change(string arg)
{
	int sword,force,spells,dodge,unarmed,whip;
	object who=this_player();
	if (who->query("xueshan/changed")=="done")
	return notify_fail("���Ѿ�ת����ϣ��Ǵ�ѩɽ�����ˡ�\n");

	if (who->query("family/family_name")!="��ѩɽ")
		return notify_fail("��Ǵ�ѩɽ���£��޷�ת����\n");

	if (who->query_skill("ningxie-force"))
	{
		force=(int)who->query_skill("ningxie-force", 1);
		who->delete_skill("ningxie-force");
		who->set_skill("ningxue-force",force);
		who->map_skill("force", "ningxue-force");
	}

	who->set("force",who->query("max_force"));
	who->set("mana",who->query("max_mana"));
	who->set("family/family_name","��ѩɽ");
	who->set("class","yaomo");
	command("smile");
	command("pat"+who->query("id"));
	command("say ת�����!(����һ������enable)");
	who->set("xueshan/changed","done");

	return 1;
}
