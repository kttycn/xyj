//By waiwai@mszj 2000/10/08

#include <ansi.h>

inherit NPC;

int promote_me();
int ask_pantao();

void create()
{
	set_name("��ʴ��",({"yuhuang dadi","yuhuang","dadi","yudi","king"}));
	set("gender", "����");
	set("title", HIR"�칬֮��"NOR);
	set("age", 45);
	set("long", HIC"    \n����������޳֣�������һǧ�߰���ʮ�ٵ���ʴ�ۡ�\n"NOR);

	set("attitude", "peaceful");
	set("class", "xian");
	set("combat_exp", 4000000);
	set("daoxing", 4000000);
	set("kee", 2200);
	set("max_kee", 2200);
	set("sen", 2200);
	set("max_sen", 2200);
	set("force", 1200);
	set("max_force", 1200);

	set("mana", 2500);
	set("max_mana", 2500);
	set("force_factor", 0);
	set("mana_factor", 0);
	set("per", 30);
	set("kar", 30);

	set_skill("literate", 160);
	set_skill("sword", 80);
	set_skill("sanqing-jian", 40);
	set_skill("spells", 100);
	set_skill("force", 40);

	map_skill("sword", "sanqing-jian");

	set("inquiry", ([
		"here"   : "��������ҵ���������",
		"name"   : "�����������ɣ��治����أ�",
		"��ְ": (:promote_me :),
		"position": (:promote_me :),
		"pantao": (: ask_pantao :),
		"���԰":(:ask_pantao:),
	]));

	setup();
	carry_object("/d/obj/cloth/mangpao")->wear();
	add_money("gold", 10);
}

void init()
{
	object who;

	::init();
	if( interactive(who = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}

void greeting(object who)
{
	int i,ii,dx;
	string strluzi;
	object luzi;

	if ( !who || environment(who) != environment() ) return;
	if (who->query("dntg/number") <=0 )  
	{
		message_vision("���ŭ��һ������������"+RANK_D->query_rude(who)
			+"��������ּ�����������ﻹ�������\n",who);
		message_vision("��ۺȵ��������ģ����������ҹ������\n",who);
		call_out ("throws1",1,who);
		return ;
	}
	else if (who->query("dntg/number") == 9 )  
	{
		if (who->query("dntg/laojunlu")=="finish")
		{
			who->set("startroom","/d/city/kezhan");
			who->add("dntg/number",1);
			who->set("dntg/bagualu","done");
			who->add("kar",5);
			tell_object(who,HIC"��ͻȻ֮�����ȫ��������һ��˵��������̩�����ø�Ե�����Ĺۣ�\n"NOR);
			dx  = 50000 + random(3000); 
			who->add("daoxing",dx);
			tell_object(who,HIY"��Ӯ���� "HIR+COMBAT_D->chinese_daoxing(dx)+HIY" ���С�\n"NOR);
			who->set("life/live_forever", 1);
			who->set("life/live_forever_announced", 1);
			who->delete("dntg/laojunlu");
			who->add("score", 520);
			if (who->query("dntg/number") == 10)
				who->set("master/dntg",HIR"�����ʥ"NOR);
			command("chat* ��ʴ�ۡ�������һ��̾�˿�����");
			command("chat "HIY"���ˣ����ˣ�"HIR+who->name()+HIY"������������
         ���칬�ڽ�����������֣������Ҫ�����������ɣ�\n"NOR);
			command("chat* ��ʴ�۾��������ң�ŵ����칬���κβ��˸���������������\n");
			message("channel:rumor", HIW"����Ӱ�񼣡���˵"+who->name()+"("+who->query("id")+")˳�����������칬�����ѹ� ������ \n\n"NOR, users());
			log_file("dntg",sprintf("%s(%s) passed laojun-lu on %s\n",who->name(1), geteuid(who), ctime(time()) ) );
			who->save();
			return ;
		}
		for (ii=0;ii<8;ii++)
		{
			strluzi="/d/dntg/laojunlu/laojunlu"+(string)ii;
			luzi = load_object(strluzi);
			if (luzi->query("has_ppl")=="yes")
				this_object()->set("laojunlu","passing");
		}   
		if (this_object()->query("laojunlu") == "passing") 
		{
			this_object()->command("hmm");
			return ;
		}
		else 
		{
			command("chat " HIR+ who->name() + HIC" ���� " HIY+ RANK_D->query_rude(who) +HIC " ���½�ʱ�ŷ���������һ������......\n");
			command("chat �������͵�ң�͵�ƣ�͵�ɵ��������ս����㣬�㾹��˼�ڸģ�");
			command("chat ���ˣ����������ӽ�����¯�ж���������ʮ���գ���֮��Ϊ�ҽ���");
			call_out ("throw_to_lu",1,who);
			return ;
		}
	}
	else if (who->query("dntg/lijing") == "done" )  
	{
		message_vision(CYN"��������������"HIY+who->query("name")
			+ HIG" ��� "HIY+RANK_D->query_rude(who)
			+NOR HIG" Խ��Խû����ˣ���Ȼ������ּ������\n"NOR,who);
		return ;
	}
	else   
	{
		message_vision("����������������½�����"+who->query("name")
			+"������ͥ����ʶ�������ޱ����������Դ���֮�\n",who);
		return ;
	}
	return ;
}



void throw_to_lu (object who)

{
	message_vision(HIY"������������콫����$N�����������˳�ȥ��\n"NOR,who);
	who->move("/d/dntg/laojunlu/laojunlu4");
	tell_room( environment(who),"�����"+who->query("name")+"����ֱ�����˽�����\n", ({who}));
	tell_object(who,HIW"��������һ�����㱻Ͷ������¯�С�\n"NOR);
	who->set("startroom","/d/dntg/laojunlu/laojunlu");
	who->set("dntg/laojunlu","begin");
	who->set_temp("dntg/laojunlu_day",0);
}

int promote_me() 
{
	object me=this_object();
	object who=this_player();
	if (who->query("combat_exp")<1000000)  {
		message_vision("��ʴ�۲�м����Ц������������ "HIR+RANK_D->query_rude(who)+NOR" ��֪��ߵغ�\n",who);
		message_vision(CYN"ƾ����㱾�£�Ҳ�����칬��ٵ���\n"NOR,who);
		message_vision(HIR"��ʴ�ۺȵ��������ģ����������ҹ������\n"NOR,who);
		call_out ("throws1",1,who);
		return 1;
	}
	else if (who->query("dntg/bmw")=="done") 
	{
		message_vision("����������ߣ�"+RANK_D->query_respect(who)+"��Ȼ��Ը�������£�
�����칬��Ҳû�б��ְλ��"+RANK_D->query_respect(who)+"������������ȥ�ɣ�\n",who);
		return 1;
	} 
	else if (objectp(present("wuqu xingjun", environment(me))))
	{
		message_vision("�Ա�ת�������Ǿ�������������칬�����������������������ٹ٣�ֻ�������ȱ�����ù��¡���\n",who);
		message_vision("��۵��˵�ͷ˵�������ͳ��������������¡��ա���\n",who);
		who->set("dntg/bmw","allow");
		return 1;
	}
	else 
	{
		message_vision("��۵��˵�ͷ˵������"+RANK_D->query_respect(who)+"�Ժ���Ҳ鿴�Ĵ�������ְ����\n",who);
		return 1;
	}
}

void throws1 (object who)
{
	message_vision("ֻ�������������������콫�����ְ˽ŵ�����$N���˳�ȥ��\n",who);
	who->move("/d/dntg/sky/qianyuangong");
	tell_room( environment(who),"ֻ��"+who->query("name")+"���������ĵ����˳�����\n", ({who}));

	call_out ("throws2",2,who);
}

void throws2 (object who)
{
	message_vision("�����콫���һ������ȥ��$N���ӻ����½硣\n",who);
	who->move("/d/changan/bridge");
	tell_room( environment(who),"�����"+who->query("name")+"��ֱ��ˤ��������\n", ({who}));
}

void die()
{
	if (environment())
		message("sound", HIR"\nֻ����ʴ��������һ����������ң�\n"NOR, environment());

	set("eff_kee", 2200);
	set("eff_gin", 2200);
	set("eff_sen", 2200);

	set("kee", 2200);
	set("gin", 2200);
	set("sen", 2200);
	set("force", 1200);
	set("mana", 2500);
}

void unconcious()
{
	die ();
}

int ask_pantao() {
	object who=this_player();

	if (this_player()->query("dntg/pantao")=="done")
	{
		message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
		command("say ����ȥ�����԰��û�Ŷ���");
		command("slogan "+this_player()->query("id"));
		return 1;
	}
	if (this_player()->query_temp("dntg/pantao")=="doing")
	{
		command("say �����Ѿ�����ȥ����԰���𣿻���ʲô��");
		return 1;
	}

	if (who->query("combat_exp")<500000)  {
		message_vision("��ʴ�۲�м����Ц������������ "HIR+RANK_D->query_rude(who)+NOR" ��֪��ߵغ�\n",who);
		message_vision(CYN"ƾ����㱾�£�Ҳ��ִ�����԰��\n"NOR,who);
		message_vision(HIR"��ʴ�ۺȵ��������ģ����������ҹ���� ������\n"NOR,who);
		call_out ("throws1",1,who);
		return 1;
	}
	if (who->query_temp("dntg/pantao")=="denied") {
		command("heng");
		command("slap " + who->query("id"));
		command(CYN"say ˵���оͲ��У�����Ҳû�� ������"NOR);
		message_vision(HIR"��ʴ�ۺȵ��������ģ����������ҹ���� ������\n"NOR,who);
		call_out ("throws1",1,who);
		return 1;
	}
	command("hmm");
	command("consider");
	if (random(3)) {
		command("say �����˲��ɿ����ҿɲ����İ����԰������ܡ�");
		who->set_temp("dntg/pantao","denied");
		return 1;
	}
	this_player()->set_temp("dntg/pantao","doing");
	this_player()->set("dntg/pantao","doing");
	message_vision("$N�������"+who->query("name")+"��"+RANK_D->query_rude(who)
		+"���ţ�ֻ�»�����Щ�Ƿǡ�����Ҳ�ա�\n",this_object());
	command("ok "+this_player()->query("id"));
	command("say ������ȥ����ĸ��������԰�������鷳�úøɣ�");
	return 1;
}
