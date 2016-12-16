
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_chuxian(object me);
string ask_cancel();
string give_zui(object me);
void create()
{
	set_name(HIC"��ϼ����"NOR, ({"qingxia xianzi", "qingxia", "xianzi","master"}));
	set("long", "������ϼ���ӵ��������,���������������ϼ��������һ�õ�о�������ϼ����˼��
�½翪ɽ����,��׷���˴���\n");
	set("title", HIY"�����о"NOR);
	set("gender", "Ů��");
	set("age", 20);
	set("class","xian");
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("cor", 30);
	set("per", 21);
	set("max_kee", 4500);
	set("max_gin", 800);
	set("max_sen", 4500);
	set("force", 4000);
	set("max_force", 2400);
	set("force_factor", 125);
	set("max_mana", 1800);
	set("mana", 3000);
	set("mana_factor", 150);
	set("combat_exp", 1600000);
	set("daoxing", 3000000);

	set_skill("literate", 210);
	set_skill("unarmed", 230);
	set_skill("dodge", 210);
	set_skill("force", 210);
	set_skill("parry", 200);
	set_skill("sword", 300);
	set_skill("spells", 200);
	set_skill("whip", 230);
	set_skill("pansi-dafa", 210);
	set_skill("lanhua-shou", 210);
	set_skill("jiuyin-xinjing", 200);
	set_skill("qingxia-jian", 300);
	set_skill("yueying-wubu", 200);
	set_skill("yinsuo-jinling", 200);
	map_skill("spells", "pansi-dafa");
	map_skill("unarmed", "lanhua-shou");
	map_skill("force", "jiuyin-xinjing");
	map_skill("sword", "qingxia-jian");
	map_skill("parry", "yinsuo-jinling");
	map_skill("dodge", "yueying-wubu");
	map_skill("whip", "yinsuo-jinling");
	set("chat_chance_combat", 50);
	set("inquiry", ([
//		"����" : (: avenge :),
//	 "��������" : (: give_zui :),
		"����": (: ask_chuxian :),
		"ְλ": (: rank_me :),
		"cancel": (: ask_cancel :),
]));
	set("no_zui", 0);
	create_family("��˿��", 1, "��");
	setup();

	 carry_object("/d/obj/cloth/tianyi.c")->wear();
	 carry_object("/d/obj/weapon/sword/qinghong")->wield();
	 carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
	add_action("do_yes", "yes");
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "��Ե��Ů")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "��˿��"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", MAG"��˿�ɸ�"NOR+RED"��"BLU"Ѳ��С��"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", MAG"��˿�ɸ�"NOR+RED"��"YEL"ϼ��ʹ��"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", MAG"��˿�ɸ�"NOR+RED"��"RED"�һ�����"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", MAG"��˿�ɸ�"NOR+RED"��"MAG"��о����"NOR);
		} else {
			me->set("nick", MAG"��˿�ɸ�"NOR+RED"��"CYN"�����ʥ"NOR);
		}

		tell_object(me, "��ϼ���Ӷ���˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"��ϼ���Ӷ�"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	/*if ( !((string)ob->query("gender")=="Ů��")){
		command("shake");
		command("say ������˿��ֻ��Ůͽ����λ" + RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
		return;
	}*/

	if ( (string)ob->query("family/family_name")=="��˿��") {
		if (((int)ob->query("daoxing") < 500000 )) {
			command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
			return;
		}
		command("pat "+ob->query("id"));
		command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������˿��������\n");
		command("recruit " + ob->query("id") );
		ob->set("title", "��˿����ϼ���Ӵ���");
		ob->set("class", "yaomo");
		return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
	return;
}
int accept_fight(object me)
{
	return 0;
}
string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("û�õĶ�����");
}
string ask_chuxian(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="��˿��") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"��ϼ����£ָһ�㣺\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"��־����\n"NOR;
	}
	return ("�����Ӳ����ס�");
}
