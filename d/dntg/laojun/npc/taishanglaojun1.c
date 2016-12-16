
#include <ansi.h>

inherit NPC;

int ask_ziying(object me);
int out_master();

void create()
{
	set_name("̫���Ͼ�",({"taishang laojun","laojun","dao"}));
	set("gender", "����");
	set("age", 55);
	set("long", "		\n̫���Ͼ���\n");
	set("per", 40);
	set("str",20);
	set("attitude", "peaceful");
	set("class", "taoist");
	set("combat_exp", 2000000);
	set("daoxing", 4000000);
	set("kee", 4000);
	set("max_kee", 4000);
	set("sen", 4000);
	set("max_sen", 4000);
	set("force", 4000);
	set("max_force", 4000);
	set("mana", 4000);
	set("max_mana", 4000);
	set("force_factor", 115);
	set("mana_factor", 115);

	set_skill("spells", 230);
	set_skill("taiyi", 220);
	set_skill("force",220);
	set_skill("zhenyuan-force",220);
	set_skill("parry", 220);
	set_skill("dodge", 220);
	set_skill("baguazhen", 200);
	set_skill("unarmed", 200);
	set_skill("wuxing-quan", 200);
	set_skill("sword",220);
	set_skill("sanqing-jian",220);
	set_skill("blade",210);
	set_skill("yange-blade",220);

	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("dodge", "baguazhen");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
	map_skill("blade", "yange-blade");
	
	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
        set("chat_chance_combat", 50);
        set("chat_msg_combat",
        ({
                (: cast_spell, "zhenhuo" :),
                (: cast_spell, "qiankun" :),
        }) );



	set("inquiry", ([
		"ziying-sword"	:(: ask_ziying :),
		"��۫��"	:(: ask_ziying :),
		"here"	 : "������Ƕ��ʹ������������ʲô��",
		"���": (: out_master :),
		"done": (: out_master :),
	]));

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}


int ask_ziying(object me)	
{
//	object ob, me;
	me=this_player();
	
	if(this_object()->query("ziying")=="done" )
		command("say �Բ���,��۫���Ѿ����˽�����!");
	
		if( me->query_temp("ask_ziying") == "tang1" ) 
	{
		command("consider");
		command("say �㸩��������");
		command("say ��˵������ׯ�ۺ�԰����Ϭţ����������Ƚ����������ȥ������");
		command("say �ϵ�һ��Ϊ�ˣ��Ἲ�����С���ø����ˣ��ѷ��������Լ���");
		me->set_temp("ask_ziying","laojun1");
		return 1;
	}
	else if( me->query_temp("ask_ziying") == "tieguaili" ) 
	{
		command("say ����ȴ��£���");
		message_vision("$N��ָһ��.....\n", this_object());
		message_vision("$N����ž��ɿ���Լ����������ƣ����������˻���Ϊʲô������ĵ���!\n", this_object());
		message_vision("��$N˵�����϶����ڻʹ�!\n", me);
		me->set_temp("ask_ziying","laojun2");
		me->set_temp("ask_ziying_laojun",1);
		return 1;
	}

/*	if(!(me->query_temp("ask_ziying") == "tang2" )
	&& !(me->query_temp("kill_ziying_dragon"))
	&& !(me->query_temp("kill_ziying_nvjing"))
	&& !(me->query_temp("ask_ziying_laojun")))*/
	{
		tell_object(me,"̫���Ͼ�����˵������λ���ѻ����Լ���ĥ�ɣ�\n");
		command("heng");
		return 1;
	}
}	

init()
{
	add_action("do_accept","accept");
}

int out_master()
{
	object ob,me;
	me = this_player();
/*	if(!(me->query_temp("ask_ziying") == "tang2" )
		&&!me->query_temp("kill_ziying_dragon")
		&&!me->query_temp("kill_ziying_nvjing")
		&&!me->query_temp("ask_ziying_laojun"))*/
//	if( me->query_temp("ask_ziying") == "tang2"
//	&& me->query_temp("kill_ziying_dragon")
//	&& me->query_temp("kill_ziying_nvjing")
//	&& me->query_temp("ask_ziying_laojun"))
	if( !(me->query_temp("kill_ziying_nvjing")==1))
	{
		tell_object(me,"̫���Ͼ�����˵������λ���ѻ����Լ���ĥ�ɣ�\n");
		command("heng");
		return 1;		
	} else {
		tell_object(me,"̫���Ͼ�������һ��,��"+me->query("name")+"˵��:Ҫ������۫��,
		�����������(accept test).\n");
		me->set_temp("ziying/test",1);
		return 1;
		}
	
}


int do_accept(string arg)
{
//	int i;
//	object ziying;
//	string ziying_given
//	,ziqing_given;
//	ziying_given = "/d/huanggong/doublesword/obj/doublesword.c";
	mapping guild;
	object ob,me,ziying;
	 me = this_player();
//	 ziying=/d/huanggong/doublesword/obj/doublesword.c;

	if( !me->query_temp("ziying/test") )
		return 0;
	if( arg== "test" )
	{
		say("\n̫���Ͼ�˵�����ܺã�С���ˣ����ǵ�һ�С�\n\n");
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment()))
		{
			say("̫���Ͼ�̾�˿�����˵��������������һ�ж��Ų����������Բ�����....\n");
			return 1;
		}
		say("\n̫���Ͼ�˵�����ڶ��У�С���ˡ�\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("̫���Ͼ�̾�����������ӻ�������۫������.....\n");
			return 1;
		}
		say("\n̫���Ͼ�˵������ע����!....�����С�\n\n");
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment()))
		{
			say("̫���Ͼ�˵�����ٺ٣��ܾ�ס�������Ѿ��������ˣ�����Ϳ�����������������ܲ����ˣ�\n");
			return 1;
		}
		say("\n̫���Ͼ�˵����С���ˣ������С�\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("̫���Ͼ�Ц�����㻹�ǻ�ȥ�����ϰ��.....\n");
			return 1;
		}
		if(ziying = present("ziying-sword", me))
			destruct(ziying);
//		if(zheng = present("xuesheng zheng", me))
//			destruct(zheng);
		command("say �úã�����ǵ���һ�ɣ����书���Ƕ����Ƿ������������㡣");
		message_vision ("̫���Ͼ����������������ҿ�����Ϊ��������Ī�����ĺ�������\n\n",me);
		message_vision ("̫���Ͼ��͸���һ����۫����\n\n",me);
		ob = new("/d/huanggong/doublesword/obj/ziying-sword");
		ob->move(me);
//			return 1;
//		}
//		if (ziying->query("id")=="ziying sword" && ziying->query("id")=="ziying")
		MONITOR_D->report_rumor_object_msg(me, "�õ�����۫�����ˣ�");
		this_object()->set("ziying","done");
		me->delete_temp("ziying/test");
		me->delete_temp("ask_ziying");		
		me->delete_temp("kill_ziying_dragon");
		me->delete_temp("kill_ziying_nvjing");
		me->delete_temp("ask_ziying_laojun");
		return 1;
	}
	return 0;
}

