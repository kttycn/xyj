//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_for_leave();
void create()
{
	set_name("����", ({"xiang xiang", "xiang","master"}));
	set("long",
"ţħ��������,����ɽһս֮�������ִ���ţħ������,�����һ����Ӵ�ʮ��������
�⻨��ɽ,����������֮�����˿����,������������ҡ�\n");
	set("title", "��˿������������");
	set("gender", "Ů��");
	set("age", 20);
	set("class", "yaomo");
	set("attitude", "friendly");
	set("rank_info/respect", "ţ��");
	set("per", 10);
	set("int", 30);
	set("max_kee", 2900);
//	set("max_gin", 2600);
	set("max_sen", 1000);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 20);
	set("max_mana", 800);
	set("mana", 800);
	set("mana_factor", 40);
	set("combat_exp", 800000);
	set("daoxing", 800000);
	set("eff_dx", 800000);
	set("nkgain", 350);
	set_skill("literate", 80);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("spells", 80);
	set_skill("whip", 100);
	set_skill("pansi-dafa", 100);
	set_skill("lanhua-shou", 100);
	set_skill("jiuyin-xinjing", 100);
	set_skill("qingxia-jian", 100);
	set_skill("yueying-wubu", 100);
	set_skill("yinsuo-jinling", 150);
	map_skill("spells", "pansi-dafa");
	map_skill("unarmed", "lanhua-shou");
	map_skill("force", "jiuyin-xinjing");
	map_skill("sword", "qingxia-jian");
	map_skill("parry", "qingxia-jian");
	map_skill("dodge", "yueying-wubu");
	map_skill("whip", "yinsuo-jinling");
//   set("chat_chance_combat", 50);
	set("inquiry", ([
		"��ɽ" : (: ask_for_leave :),
		"leave" : (: ask_for_leave :),
	]) );
	set("chat_chance",5);
	set("chat_msg", ({
		HIM"�������쳤̾:�һ���������ݲ�����\n"NOR,
		HIR"�������쳤̾:��Ǯ�䴦����ͷ������\n"NOR,
	}));

	create_family("��˿��", 3, "����");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/shendian/babu/obj/qin");
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if ( !((string)ob->query("gender")=="Ů��")){
		command("shake");
		command("say ������˿��ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
		return;
	}
	else
	{
		command("curtain");
		command("say �ã�" + RANK_D->query_respect(ob) + "Ͷ���ҵ����£����ձ������ɣ�\n");
		command("recruit " + ob->query("id") );
		ob->set("class", "yaomo");
			ob->set("title", "��˿���һ�������ʹ��");
	}
}
void init()
{
	 add_action("do_agree", "agree");
}

string ask_for_leave()
{
	object me=this_player();

	if (me->query("family/family_name") == "��˿��" ) {
		command("say �����ִ����ɽ����ȴ�м��仰˵��");
		me->set_temp("betray", 1);
		return ("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��(agree)��");
	}

	return ("��֪����\n");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N���������Ը�⡣\n\n", this_player());
		command("say ����������˿����Ե�������ɽȥ�ɣ�");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/pansi", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("pansi-dafa") )
		    this_player()->delete_skill("pansi-dafa");
		if( this_player()->query_skill("jiuyin-xinjing") )
		     this_player()->delete_skill("jiuyin-xinjing");

		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "��ͨ����");
		this_player()->set_temp("betray", 0);
		this_player()->save();
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
		return 1;
	}
}
