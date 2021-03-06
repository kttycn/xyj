inherit NPC;

int start_change(string arg);

void create()
{
	set_name("月宫接引", ({"shi zhe"}));
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
	return notify_fail("你已经转换完毕，是月宫门下了。\n");

	if ((who->query("family/family_name")!="月宫"))
		return notify_fail("你非月宫门下，无法转换。\n");

	if (who->query_skill("jueqingbian"))
	{
		force=(int)who->query_skill("jueqingbian", 1);
		who->delete_skill("jueqingbian");
		who->set_skill("jueqing-whip",force);
		who->map_skill("whip", "jueqing-whip");
	}

	who->set("family/family_name","月宫");
	who->set("class","xian");
	command("smile");
	command("pat"+who->query("id"));
	command("say 转换完毕!(请检查一下您的enable)");
	who->set("moon/changed","done");

	return 1;
}
