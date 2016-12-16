// modified by vikee
//����ɽ���ɡ�dhxy-evil 2000.7.5
//fei �޸� 2001.3
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int do_report();

void create()
{
	set_name("����ң", ({ "li xiaoyao", "li", "xiaoyao" }));
	set("title","��ɽ�������ŵ���");
	set("long", "����������Ľ��ݣ���ȴŨü���ۣ������Ѱ���\n");
	set("gender", "����");
	set("age", 18);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("per", 30);
	set("kee", 2800);
	set("max_kee", 2800);
	set("sen", 1600);
	set("max_sen", 1600);
	set("force", 4800);
	set("max_force", 2400);
	set("mana", 4800);
	set("max_mana", 2400);
	set("force_factor", 60);
	set("mana_factor", 60);

	set("combat_exp", 1800000);
	set("daoxing", 2500000);

	set_skill("force", 170);
	set_skill("dodge", 180);
	set_skill("parry", 160);
	set_skill("sword", 200);
	set_skill("canxin-jian", 200);
	set_skill("zixia-shengong", 150);
	set_skill("whip", 200);
	set_skill("yiruwhip", 200);
	set_skill("seven-steps",180);
	set_skill("literate", 100);
	set_skill("taoism",150);
	set_skill("spells",150);
	map_skill("whip", "yiruwhip");
	map_skill("spells", "taoism");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "seven-steps");
	map_skill("parry", "canxin-jian");
	map_skill("sword", "canxin-jian");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword","xiangsi" :),
		(: perform_action, "sword","jinsheng" :),
	}) );

	set("inquiry", ([
		"�����" : "���ܰ���ȥ��������ҿɻᱨ����ģ�\n",
		"���ʿ" : "�þ�û��ʦ���ˣ�\n",
		"�ƽ���" : "�þ�û��ʦ���ˣ�\n",
		"�������"     : (: do_report :),
		"done"     : (: do_report :),
		"�ȳ�����"     : (: do_report :),
	]));
	setup();
	create_family("��ɽ����", 3, "δ���ŵ���");
	carry_object("/obj/cloth")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

int attempt_apprentice(object me)
{
	me =this_player();
	if( (string)me->query("family/family_name")=="��ɽ��" || 
	( !me->query("family") && me->query("zhanyi/zhenyaota") != "done") )
	{
		if( (int)me->query("family/generation") > 3  )
		{
			if ( (string)me->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
			else command("say ʦ�ü�Ц�ˡ�\n");
		}
		else if( (int)me->query("family/generation") ==3  )
		{
			if ( (string)me->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
			else command("say ʦ��̫�����ˡ�\n");
		}
		command("say �����ɽ���ӣ�Ҳûȥ�Ȼ�������Ҳ�������ġ�");
		return 0;
	}
	command("consider");
	command("say ��������ĳ���ķ���,������Ϊͽ!\n");
	command("recruit " + me->query("id") );
	me->set("shushan/xiangsi_perform",1);
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "��ɽ�����ɽ�����");
	}
	return 0;
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "����ң˵������λ" + RANK_D->query_respect(ob) +
"���ܲ��ܰ��Ҿȳ�����������ؽ����������ˣ�\n");
}

int do_report()
{
	int i=random(500)+1;
	object who = this_player();
	object me = this_object();
	if(who->query("nyj/shushan") == "done"){
		command("shake "+who->query("id"));
		return 1;
	}
	if(me->query("obstacle/shushan") == "done")
		return 0;
	if (objectp(present("zhao linger", environment(who))) 
	&& who->query_temp("shushan/linger_daying") ){
		who->set("zhanyi/zhenyaota","done");
		who->delete("shushan/linger_daying");
		who->add("daoxing",4000+i);
		who->add("potential",1000);
		who->add("obstacle/number",1);
		who->set("obstacle/shushan","done");
		who->add("score", 10);
		command("thank "+who->query("id"));
		command("u&me "+who->query("id"));
		command("chat "+who->query("name")+"�������������ȳ����������������������û�����������������ļ�¼��\n");
		message("channel:chat",HIW"������ն��������ң(Li xiaoyao)��"+who->query("name")+"��������ȡ������ʮ�˹أ�\n"NOR,users());
		tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��к�"+chinese_number(1000)+"��Ǳ�ܵĽ�����\n");
		me->save();
        return 1;
	}
	command("? "+who->query("id"));
	return 1;
}
