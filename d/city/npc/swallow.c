// kid.c

inherit NPC;

int ask_faith();

void create()
{
	set_name("���ϼ",({ "swallow jiashen","god" }) );
	set("gender", "����" );
	set("race","����");
	set("long",
		"�ף�������ϼ��ô�����ǵ���ʦ����һģһ�����Ǻ�...\n"
		"���������ﴦ��һЩ���⣬�������������������񣬿�����������faith�����ҳϵ��£�\n"
		"�������ԭ���������޸�Ϊ�������õķ�ʽ��\n"
		"������Ҫ�ǲ�Ը�������ģ�����Ҳ���ֵ������ˡ�\n" );
	set("age", 21);
	set("kar",110);
	set("str",30);
	set("cps",25);
	set("int",40);
	set("cor",19);
	set("con",42);
	set("spi",40);
	set("per",30);
	set("combat_exp",3012688);
	set("daoxing", 3157343);
	set("force",12000);
	set("max_force",6000);
	set("mana",6000);
	set("max_mana",3000);
	set("force_factor",300);
	set("mana_factor",300);
	set("degree","������");
	set("xuewei","ʥ��");
	set("eff_gin",740);
	set("eff_kee",12576);
	set("eff_sen",12640);
	set("party/rank","�ˡ��񡤹� ����������");
	set("party/obstacle","��սʤ��");
	set("party/dntg","�����ʥ");
	set("title","��ɽ��ʥ����");
	set("gender","����");
	
	set_skill("literate",201);
	set_skill("hunyuan-zhang",401);
	set_skill("zixia-shengong",401);
	set_skill("taoism",401);
	set_skill("canxin-jian",450);
	set_skill("parry",401);
	set_skill("sword",401);
	set_skill("dodge",401);
	set_skill("unarmed",401);
	set_skill("yujianshu",400);
	set_skill("spells",401);
	set_skill("seven-steps",401);
	set_skill("force",401);

	map_skill("dodge","seven-steps");
	map_skill("unarmed","hunyuan-zhang");
	map_skill("spells","taoism");
	map_skill("parry","canxin-jian");
	map_skill("sword","canxin-jian");
	map_skill("force","zixia-shengong");

	set("attitude", "peaceful");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "jianshen" :),
		(: perform_action, "sword", "xiangsi" :),
	}) );
	set("inquiry", ([
		"faith" : (: ask_faith :),
		"�ҳ�" : (: ask_faith :),
	]));

	setup();

	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

int ask_faith()
{
	object who=this_player();
	int faith;

	
	if(faith = who->query(who->query("class")+"_faith") )
	{
		command("say �ð������ҿ�����\n");
		printf("��ԭ���������ҳ϶��ǣ�%d\n",faith);
		command("say �ã�����͸���ġ�");
		who->set("faith",faith);
		who->delete(who->query("class")+"_faith");
		command("say ���ˣ����ĵ�ȥ�ɡ�");
		return 1;
	}
	return notify_fail("�㲢û�����κα�ʾ���������ʦ�ŵ���ѽ��\n");
}