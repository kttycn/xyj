//EDIT BY LUCAS
inherit NPC;
#include <ansi.h>
int ask_zhong();

void create()
{
	set_name("��˳", ({"ao shun", "ao","shun","longwang","wang","aoshun"}));
	set("gender", "����");
	set("age", 30);
	set("long","��˳�������������˶�����������֮�ܡ�\n");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("age", 65);
	set("title", "��������");
	set("class","dragon");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("combat_exp", 1200000);
	set("rank_info/respect", "����");
	set("per", 20);
	set("str", 30);
	set("max_kee", 3000);
	set("max_gin", 400);
	set("max_sen", 800);
	set("force", 3000);
	set("max_force", 1500);
	set("force_factor", 120);
	set("max_mana", 800);
	set("mana", 1600);
	set("mana_factor", 40);

	set("combat_exp", 1200000);
	set_skill("unarmed", 200);
	set_skill("dodge", 150);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("fork", 150);
	set_skill("spells", 150);
	set_skill("seashentong", 150);
	set_skill("dragonfight", 200);
	set_skill("dragonforce", 150);
	set_skill("dragon-cha", 180);
	set_skill("dragon-steps", 150);
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "dragon-cha");
	map_skill("parry", "dragon-cha");
	map_skill("dodge", "dragon-steps");
	set("inquiry", ([
    	"��ڣ": (: ask_zhong:),
	]));

	setup();
	carry_object("/d/obj/cloth/longpao")->wear();
}


int ask_zhong()
{
	object me;
	me=this_player(); 
	if(me->query("xinguan/heishui")!="done") { 
		command("disagree");
		command("say ����ʲô�ˣ����Ҵ�������ʥ�ص����⣡\n");
		return 1;
	}
	else
	{
		if(!me->query_temp("��ڣ")){
			command("shake");
			command("say ��ڣ�����������尲Ϣ֮��,"+RANK_D->query_respect(me)+"��������");
			command("say ��Ȼ"+RANK_D->query_respect(me)+"����������������,С��Ҳ���һ�����������.");
			return 1;
		}
		command("consider");
		command("say ��Ȼ������Ȼ"+RANK_D->query_respect(me)+"Ҫȥ���ǡ�����ȥ�ɡ�\n");
		message_vision(HIG"��˳����һ�У�$N������ص���һ��İ���ĵط���\n"NOR,me);
		me->move("/d/qujing/xihai/zhong");
		return 1;
	}
	return 1;
}


int accept_object(object me,object ob)
{
	object who;
	me=this_object();
	who=this_player();

	if (ob->query("id")=="letter" )
	{
		if(who->query("xinguan/heishui")=="done")
		{ 
			command("hoho");
			command("say "+RANK_D->query_respect(who)+"������ô��\n");
			command("say ������֮�¶�л"+RANK_D->query_respect(who)+"��Ϊ���ڣ�С����ʤ�м���\n");
			command("say "+RANK_D->query_respect(who)+"��ι��ٺ��ᣬ�кι�ɣ�\n");
			call_out("destroy", 1, ob);
			who->set_temp("��ڣ",1);
			return 1;
		}
		if( who->query_temp("heshen")) {
			call_out("read", 2);
			return 1;
		}
		command("heng");
		command("say ��ƾ�޾ݣ��㲻����ԩ���˰ɡ�\n");
		command("say �Ϸ��Ѿ�֪���ˣ�"+RANK_D->query_respect(who)+ "��ذɡ�\n");
		call_out("destroy", 1, ob);
		return 1;
	}
}

void read()
{
	object who;
	who = this_player();

	message_vision ("��˳���ͷ,��������,����������\n",who);  

	call_out("say",2);
}

void say()
{
	object who;
	who = this_player();

	message_vision ("��˳ҡͷ̾���������Ų��ң����˰��࣡��\n",who);  
	call_out("cry",2);
}
void cry()
{
	object who;
	who = this_player();

	command("cry");
	call_out("man",2);
}
void man()
{
	object who;
	who = this_player();

	command("say " +RANK_D->query_respect(who)+ "���С��һ���������֪��ۣ�\n");
	call_out("zuo",2);
}
void zuo(object me,object ob)
{
	object who;
	who = this_player();

	command("say " +RANK_D->query_respect(who)+"����Ȯ��Ħ����ͬ����ˮ�ܴ�������\n");
	who->set_temp("����",1);
	call_out("destroy", 1, ob);
}
void destroy(object ob)
{
	destruct(ob);
	return;
}


void announce_success (object who) 
{
	int i;

	if (who->query("combat_exp") < 10000)
		return;
	if (who->query("xinguan/heishui") == "done")
		return; 
	if(!who->query_temp("fight"))
		return;
	if(!who->query_temp("killlong"))
		return;
	i = random(1000);
	who->add("obstacle/number",1);
	who->set("obstacle/heishui","done");
	who->add("daoxing",i+4000); 
	who->add("score", 10);
	command("chat "+who->query("name")+"��ˮ�����������ӵ���ħ��");
	message("channel:chat",HIW"������ն������˳(Ao shun)��"+who->query("name")+"��������ȡ����ʮ���أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	who->save(); 
}
