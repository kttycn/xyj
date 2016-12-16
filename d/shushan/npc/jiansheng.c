//jiansheng.c by fei 2001.02
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_mieyao(object me);
int rank_me();
string ask_cancel();
string avenge();

void create()
{
	set_name("��ʥ", ({"shushan jiansheng","jiansheng", "master"}));
	set("title", "��ɽ����������");
	set("gender", "����");
	set("age", 65);
	set("class", "swordsman");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 26);
	set("looking", "��ɽ������ʦү����ͷ�׷������ˣ����۾�������");
	set("int", 30);
	set("max_kee", 5000);
	set("max_gin", 1000);
	set("max_sen", 5000);
	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 150);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 150);
	set("combat_exp", 800000);
	set("daoxing", 5000000);
	set_skill("literate", 180);
	set_skill("dodge", 180);
	set_skill("parry", 190);
	set_skill("mindsword", 200);
	set_skill("hunyuan-zhang", 180);
	set_skill("unarmed", 180);
	set_skill("spells", 180);
	set_skill("taoism", 180);
	set_skill("yujianshu", 200);
	set_skill("zixia-shengong", 190);
	set_skill("force", 190);
	set_skill("seven-steps", 180);
	map_skill("spells", "dao");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("spells","taoism");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	map_skill("unarmed", "hunyuan-zhang");
	set("shushan/wanjian_perform",1);
	set("shushan/duanshui_perform",1);
	set("inquiry", ([
		"����": (: ask_mieyao :),
		"cancel": (: ask_cancel :),
		"ְλ": (: rank_me :),
	]));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword", "wanjianjue" :),
		(: perform_action, "sword", "duanshui" :),
		(: cast_spell, "fu" :),
	}) );
	create_family("��ɽ����", 2, "������");
	setup();
	carry_object("/d/obj/cloth/jinpao")->wear();
	carry_object("/d/shushan/obj/jueshi")->wield();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "��ɽ�������Ŵ�ʦ��" 
	|| me->query("title") == "��ɽ�������Ŵ�ʦ��")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "��ɽ��"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIG"��ɽ����"NOR+RED"��"BLU"ӭ�ͽ�ͯ"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIG"��ɽ����"NOR+RED"��"YEL"ն������"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIG"��ɽ����"NOR+RED"��"RED"��ħ����"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIG"��ɽ����"NOR+RED"��"MAG"���Ľ���"NOR);
		} else {
			me->set("nick", HIG"��ɽ����"NOR+RED"��"CYN"ͨ�콣ʥ"NOR);
		}

		tell_object(me, "��ɽ�ɽ�ʥ����˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"��ɽ�ɽ�ʥ��"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	if ( !((string)ob->query("gender")=="����")){
		command("shake");
		command("say ��ֻ����ͽ����λ" +RANK_D->query_respect(ob) + "����ȥ�Ҿƽ��ɰɡ�\n");
		return;
	}
	if( (string)ob->query("family/family_name")=="��ɽ����") {
		if ((int)ob->query("daoxing") < 600000 ) {
	  		command("say ��ĵ��л����������ҵ��з���������\n");
			return;
		}
		if( (int)ob->query_skill("taoism", 1) < 150 ) {
			command("say ��λ" + RANK_D->query_respect(ob) + "�����ʦ�ɷ����������,�㻹����׷�����������Ű�!\n");
			command("sigh");
			return;
		}
		if (ob->query_skill("sword",1) < 130) {
			command("say ����ɽ���ɣ���ע�������������У����ҿ�" + RANK_D->query_respect(ob) + "�ǲ��Ǹö����¿๦�أ�");
			return ;
        }
        if ((int)ob->query_int() < 35) {
			command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ����ɽ�����书��");
			return;
        }
		command("smile");
		command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ����Ϊ��ɽ���⡣");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
	return;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "��ɽ��ʥ�״�����");
	}
	return 0;
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
	if((string)me->query("family/family_name")=="��ɽ����") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"��ʥ�����д�......\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"������ħ��������ɽ����֮���֡�\n"NOR;
	}
	return ("ƶ�������ס�");
}


string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="��ɽ����")
		return ("�㲻�Ǳ��ɵ��ӣ��������Ϸ�θɣ�");
	if(who->query("faith")<1000)
		return ("���ڱ���������������������Ŭ�����С�");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("�Ϸ�δ����Ѷ");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("�����Ϸ򻹵���һ��");
	command("say �Ϸ����ȥΪ�㱧��");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"ֻ����ʥ�����һָ��\n");
	tell_room(where,"�������ڣ���ȥ��"+killer->query("name")+"ץ����\n");
	tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")
+"ץ��������");
	killer->move(where);
	tell_room(where,killer->query("name")+"���ӿ�������������\n");
	command("say ������������ɱ������ɽ���ɵ���");
	this_object()->kill_ob(killer);
	return("��������");
}
