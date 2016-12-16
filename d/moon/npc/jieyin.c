inherit NPC;

int start_change(string arg);

void create()
{
	set_name("�¹�����", ({"shi zhe"}));
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
	if (who->query("moon/changed")=="done")
	return notify_fail("���Ѿ�ת����ϣ����¹������ˡ�\n");

	if ((who->query("family/family_name")!="�¹�"))
		return notify_fail("����¹����£��޷�ת����\n");

	if (who->query_skill("jueqingbian"))
	{
		force=(int)who->query_skill("jueqingbian", 1);
		who->delete_skill("jueqingbian");
		who->set_skill("jueqing-whip",force);
		who->map_skill("whip", "jueqing-whip");
	}

	who->set("family/family_name","�¹�");
	who->set("class","xian");
	command("smile");
	command("pat"+who->query("id"));
	command("say ת�����!(����һ������enable)");
	who->set("moon/changed","done");

	return 1;
}
