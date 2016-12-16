inherit NPC;

int start_change(string arg);

void create()
{
	set_name("��ɽ����", ({"shi zhe"}));
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
	if (who->query("shushan/changed")=="done")
	return notify_fail("���Ѿ�ת����ϣ�����ɽ�����ˡ�\n");

	if ((who->query("family/family_name")!="��ɽ") && 
	(who->query("family/family_name")!="��ɽ����") &&
	(who->query("family/family_name")!="��ɽ��"))
		return notify_fail("�����ɽ���£��޷�ת����\n");

	if (who->query_skill("shushan-force"))
	{
		force=(int)who->query_skill("shushan-force", 1);
		who->delete_skill("shushan-force");
		who->set_skill("zixia-shengong",force);
		who->map_skill("force", "zixia-shengong");
	}
	if (who->query_skill("xianfeng-spells"))
	{
		spells=(int)who->query_skill("xianfeng-spells", 1);
		who->delete_skill("xianfeng-spells");
		who->set_skill("taoism",spells);
		who->map_skill("spells","taoism");
	}
	if (who->query_skill("songhe-sword"))
	{
		sword=(int)who->query_skill("songhe-sword", 1);
		who->delete_skill("songhe-sword");
		if(!who->query_skill("yujianshu"))
			who->set_skill("yujianshu",sword);
	}
	if (who->query_skill("zuixianbu") )
	{							
		dodge=(int)who->query_skill("zuixianbu", 1);
		who->delete_skill("zuixianbu");
		if(!who->query_skill("seven-steps"))
			who->set_skill("seven-steps",dodge);
	}
	if (who->query_skill("sevensteps") )
	{							
		dodge=(int)who->query_skill("sevensteps", 1);
		who->delete_skill("sevensteps");
		if(!who->query_skill("seven-steps"))
			who->set_skill("seven-steps",dodge);
	}
	if (who->query_skill("fumozhang"))
	{
		unarmed=(int)who->query_skill("fumozhang", 1);
		who->delete_skill("fumozhang");
		if(!who->query_skill("hunyuan-zhang"))
			who->set_skill("hunyuan-zhang",unarmed);
	}
	if ( who->query_skill("snowwhip") )
	{
		unarmed=(int)who->query_skill("snowwhip", 1);
		who->delete_skill("snowwhip");
		who->set_skill("yiruwhip",unarmed);
	}
	if (who->query_skill("yirubian") )
	{
		unarmed=(int)who->query_skill("yirubian", 1);
		who->delete_skill("yirubian");
		if(!who->query_skill("yiruwhip"))
			who->set_skill("yiruwhip",unarmed);
	}

	who->set("force",who->query("max_force"));
	who->set("mana",who->query("max_mana"));
	who->set("family/family_name","��ɽ����");
	who->set("class","swordsman");
	command("smile");
	command("pat"+who->query("id"));
	command("say ת�����!(����һ������enable)");
	who->set("shushan/changed","done");

	return 1;
}
