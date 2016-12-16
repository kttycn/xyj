#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_mieyao(object me);
string ask_cancel();
string avenge();

void create()
{
	set_name("����", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
	set("title", "����Ԫѫ");
	set("gender", "����");
	set("age", 43);
	set("str", 30);
	set("per", 26);
	set("int", 30);
	set("cor", 50);
	set("cps", 50);
	set("long", "���屦�Ǵ��ƹ���������������һλ�������佫��\n");
	set("combat_exp", 1200000);

	set_skill("literate", 220);
	set_skill("spear", 240);
	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 250);
	set_skill("mace", 300);
	set_skill("wusi-mace", 300);
	set_skill("yanxing-steps", 250);
	set_skill("bawang-qiang", 240);
	set_skill("lengquan-force", 260);
	set_skill("unarmed", 260);
	set_skill("changquan", 220);
	map_skill("mace", "wusi-mace");
	map_skill("force", "lengquan-force");
	map_skill("unarmed", "changquan");
	map_skill("spear", "bawang-qiang");
	map_skill("archery", "xuanyuan-archery");
	map_skill("parry", "bawang-qiang");
	map_skill("dodge", "yanxing-steps");
	set("max_sen", 2800);
	set("max_kee", 4400);
	set("force", 2000);
	set("max_force", 1800);
	set("force_factor", 80);
	set("inquiry", ([
		"name": "�����������屦��",
		"here": "������ǽ����������ѵ��㲻֪����",
		"rumors": "���²��ڽ������ߺܾ��ˣ������ϵ��������¿ɲ�̫�����",
		"����" : (: avenge :),
		"cancel": (: ask_cancel :),
		"��ħ": (: ask_mieyao :),
//		"�ӷ�": (: ask_bad :),
		"kill": (: ask_mieyao :),
		"ְλ": (: rank_me :),
 	]) );

	create_family("������", 2, "��");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "spear", "lianhuan" :),
		(: perform_action, "spear", "qiangjian" :),
		(: perform_action, "spear", "bugong" :),
	}) );

	setup();
	carry_object("/d/obj/weapon/spear/yinqiang")->wield();
	carry_object("/d/obj/armor/tiejia")->wear();
	carry_object("/d/obj/weapon/mace/copperjian");
}

string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("û�õĶ�����");
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="������") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"����ˬ�ʵ�Ц��������\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"������ħ�����ҹٸ�����֮���֡�\n"NOR;
	}
	return ("�㲻�ǹٸ����ˣ�");
}

int accept_fight(object me)
{
	command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������\n");
	return 0;
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "����������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "������"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIR"���ƽ���"NOR+RED"��"BLU"��Ժ�ױ�"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIR"���ƽ���"NOR+RED"��"YEL"�ȷ��"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIR"���ƽ���"NOR+RED"��"RED"�س��ᶽ"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIR"���ƽ���"NOR+RED"��"MAG"����Ԫ˧"NOR);
		} else {
			me->set("nick", HIR"���ƽ���"NOR+RED"��"CYN"����Ԫѫ"NOR);
		}

		tell_object(me, "�������˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"�����"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

int attempt_apprentice(object me)
{
	string myname=RANK_D->query_respect(me);
	if ((int)me->query("combat_exp")< 100000)
	{
		command("say ��λ"+myname+"������ȥ�������ҽ��������ɣ�");
		return 0;
	}
	command("haha");
	command("say �ܺã�ʱ����������֮�ʣ�"+myname+"���Ŭ�������ձض��гɡ�\n");
	command("recruit " + me->query("id") );
	return 1;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
	string myname=RANK_D->query_respect(me);

	if (me->query("combat_exp") < 100000)
	{
		command("emote ������üͷ��˵����"+myname+"��Ƿ�������Ϸ�����"+myname+"����������⡣");
		return 1;
	}
	return 0;
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="������")
		return ("�㲻�Ǳ������ӣ������뱾�����θɣ�");
	if(who->query("faith")<1000)
		return ("���ڱ���������������������Ŭ�����С�");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("������δ����Ѷ");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("����������������һ��");
	command("say ���������ȥΪ�㱧��");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"ֻ��������һ����\n");
	tell_room(where,"�����������ڣ���ȥ��"+killer->query("name")+"ץ����\n");
	tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")
+"ץ��������");
	killer->move(where);
	tell_room(where,killer->query("name")+"���ӿ�������������\n");
	command("say ������������ɱ���ҽ���������");
	this_object()->kill_ob(killer);
	return("��������");
}
