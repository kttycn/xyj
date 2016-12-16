// kongwu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string avenge();

void create()
{
	set_name(HIW"������"NOR, ({"master dadi", "dadi", "master"}));
	set("long", "�й���ǧ�괫��������̹ſ����������ƹ������е��似��\n");
	set("title", HIC"���ʥ��"NOR);
	set("gender", "����");
	set("age", 100);
	set("class", "wusheng");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "���");
	set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
	set("max_kee", 6000);
	set("max_gin", 1000);
	set("max_sen", 6000);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 150);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2500000);
	set("daoxing", 7500000);

	set_skill("unarmed", 270);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("spells", 290);  
	set_skill("feisheng-spells", 290);
	set_skill("literate", 280);
	set_skill("sword", 300);
	set_skill("wuying-sword", 300);
	set_skill("fumobashi", 280);  
	set_skill("mizong-steps", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("xiantian-force", 280);

	map_skill("spells", "feisheng-spells");
	map_skill("unarmed", "fumobashi");
	map_skill("force", "xiantian-force");
	map_skill("sword", "wuying-sword");
	map_skill("parry", "wuying-sword");
	map_skill("dodge", "mizong-steps");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: cast_spell, "feixian" :),
		(: perform_action, "sword", "juechen" :),
		(: perform_action, "sword", "fenge" :),
	}) );
	set("inquiry", ([
		"����" : (: avenge :),
	]));

	create_family("��ʥ��", 1, "����");
	
	setup();
	carry_object("/d/obj/cloth/writepao")->wear();
	carry_object("/d/qujing/huangfeng/obj/jinyipifeng")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	if( (string)ob->query("family/family_name")=="��ʥ��") {
		if ((int)ob->query("daoxing") < 500000 ) {
  			command("say ���ǽ�ħ����֮�����صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
			return;
		}
/*
		if( (int)ob->query("pending/kick_out")) {
			command("say ��λ" + RANK_D->query_respect(ob) + "�����޳����Ϸ�ԭ������Ϊͽ�ˣ�\n");
			command("sigh");
			return;
		}
*/
		if ((int)ob->query_int() < 40) {
			command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
			command("sigh");
			return;
		}
		if( (int)ob->query_skill("feisheng-spells", 1) < 120 ) {
			command("say ��λ" + RANK_D->query_respect(ob) + "���ҷ�������ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
	return;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	ob->set("class", "wusheng");
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="��ʥ��")
		return ("�㲻�Ǳ��ŵ��ӣ��������Һθɣ�");
	if(who->query("faith")<1000)
		return ("���ڱ���������������������Ŭ�����С�");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("����δ����Ѷ");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("��������������һ��");
	command("say �������ȥΪ�㱧��");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"ֻ�������������һָ��\n");
	tell_room(where,"�������ڣ���ȥ��"+killer->query("name")+"ץ����\n");
	tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")+"ץ���ˡ�\n");
	killer->move(where);
	tell_room(where,killer->query("name")+"���ӿ�������������\n");
	command("say ������������ɱ������ʥ�ŵ���");
	this_object()->kill_ob(killer);
	return("��������");
}
