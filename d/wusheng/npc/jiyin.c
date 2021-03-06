inherit NPC;

int start_change(string arg);

void create()
{
	set_name("武圣门接引", ({"shi zhe"}));
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
	if (who->query("wusheng/changed")=="done")
	return notify_fail("你已经转换完毕，是武圣门下了。\n");

	if ((who->query("family/family_name")!="武圣门") )
		return notify_fail("你非武圣门下，无法转换。\n");

	if (who->query_skill("xiantian"))
	{
		force=(int)who->query_skill("xiantian", 1);
		who->delete_skill("xiantian");
		who->set_skill("xiantian-force",force);
		who->map_skill("force", "xiantian-force");
	}
	if (who->query_skill("feisheng-spells"))
	{
		spells=(int)who->query_skill("xiantian", 1);
		who->delete_skill("xiantian");
		who->set_skill("feisheng-spells",spells);
		who->map_skill("spells","feisheng-spells");
	}
	if (who->query_skill("wuying"))
	{
		sword=(int)who->query_skill("wuying", 1);
		who->delete_skill("wuying");
		who->set_skill("wuying-sword",sword);
	}

	who->set("force",who->query("max_force"));
	who->set("mana",who->query("max_mana"));
	who->set("family/family_name","武圣门");
	who->set("class","wusheng");
	command("smile");
	command("pat"+who->query("id"));
	command("say 转换完毕!(请检查一下您的enable)");
	who->set("wusheng/changed","done");

	return 1;
}
