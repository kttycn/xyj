// guanyin.c �ݰ�����
// By Dream Dec. 20, 1996
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "place.h"

string ask_for_partner();
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name("�ݰ�����", ({ "huian xingzhe", "huian", "xingzhe" }));
	set("title", "������ͽ");
	set("long", @LONG
��������̫��ľ�棬�Ϻ�������ͽ�ܻݰ����ߡ�
LONG);
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("rank_info/self", "ƶɮ");
	set("class", "bonze");

    set("max_kee", 1000);
	set("max_gin", 600);
	set("max_sen", 1000);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 75);
	set("max_mana", 1000);
	set("mana", 2000);
	set("mana_factor", 55);
	set("combat_exp", 750000);

	set("eff_dx", 150000);
	set("nkgain", 300);

	set_skill("literate", 100);
	set_skill("spells", 120);
	set_skill("buddhism", 120);
	set_skill("unarmed", 100);
	set_skill("jienan-zhi", 100);
	set_skill("dodge", 100);
	set_skill("lotusmove", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("lotusforce", 100);
	set_skill("staff", 110);
	set_skill("hammer",100);
	set_skill("bighammer",100);
	set_skill("lunhui-zhang", 110);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	map_skill("hammer", "bighammer");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :)
	}) );

	set("inquiry", ([
		"dadang" : (: ask_for_partner :),
		"partner" : (: ask_for_partner :),
		"�": (: ask_for_partner :),
	   "cancel": (: ask_cancel :),
		"����": (: ask_mieyao :),
		]) );

	create_family("�Ϻ�����ɽ", 2, "����");

	setup();
	carry_object("/obj/money/gold");
	carry_object("/d/nanhai/obj/sengpao")->wear();
	carry_object("/d/nanhai/obj/budd_staff")->wield();
}

void attempt_apprentice(object ob)
{
	if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say " + RANK_D->query_respect(ob) + "δ����ţ�ˡƶɮ���ܽ��ɡ�\n");
		return;
	}
	if (((int)ob->query_skill("buddhism", 1) < 50 )) {
		command("say " + RANK_D->query_respect(ob) + "�������ޣ��������𷨡�\n");
		return;
	}
	command("nod");
	command("say �ܺã�ƶɮ�������㣬ϣ������Ŭ�������������\n");

	command("recruit " + ob->query("id") );
	return;
}

string ask_for_partner()
{

	object me = this_player();
	string dadang;

	if ( (string)me->query("family/family_name")!="�Ϻ�����ɽ")
		return "ֻ���Ϻ�����ɽ���Ӳ���Ѱ�Ҵ��\n";
	if( (string)me->query("bonze/class")!="bonze" )
		return "ʩ���ȷǷ������ˣ��αض��ʣ�\n";
	if( (dadang=(string)me->query("bonze/dadang")) !=0 )
		return "��Ĵ��"+dadang+"��\n";

	me -> set_temp("pending/dadang_inquiry", 1);

	return RANK_D->query_respect(me)+"���� \"dadang <id>\" ��ѡ����Ĵ��\n";
}

int do_dadang(string arg)
{
object obj, me=this_player();
string dadang;

	if ( (string)me->query("family/family_name")!="�Ϻ�����ɽ")
		return notify_fail("ֻ���Ϻ�����ɽ���Ӳ���Ѱ�Ҵ��\n");
	if( (string)me->query("bonze/class")!="bonze" )
		return notify_fail("ʩ���ȷǷ������ˣ��αض��ʣ�\n");
	if( (dadang=(string)me->query("bonze/dadang")) !=0 )
		return notify_fail("��Ĵ��"+dadang+"��\n");
	if( !me->query_temp("pending/dadang_inquiry") )
		return notify_fail("�㻹û�ʹ�"+this_object()->query("name")+"�أ�\n");
	me->delete("pending/dadang_inquiry");

	if (!arg)
		return notify_fail("��Ҫ��˭�����\n");

	obj = present(arg, environment(me));
	if (!userp(obj)) return notify_fail("\n");

	if (me->query("gender") == obj->query("gender") )
		return notify_fail("��ֻ��������ͬ�������\n");

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if( obj->query_temp("pending/dadang") != me) {
		message_vision("\n$N����"+this_object()->query("name")+"���棬��$n˵����"
			+ RANK_D->query_self(me)+ me->name()
			+ "������" + RANK_D->query_respect(obj)
			+ "��һ�Դ���պ�һ�����߽�����ͬ�����������ѣ�"
			+ RANK_D->query_respect(obj) + "������Σ�\n\n", me, obj);
		me->set_temp("pending/dadang", obj);
		return 1;
	}

	obj->delete_temp("pending/jiebai");
	message_vision("\n$N����"+this_object()->query("name")+"���棬��$n˵����"
		+ RANK_D->query_self(me)+ me->name()
		+ "��Ը��" + RANK_D->query_respect(obj)
		+ "��һ�Դ��\n\n", me, obj);

	obj->set("bonze/dadang", me->query("name"));
	obj->set("bonze/dadangid", me->query("id"));
	me->set("bonze/dadang", obj->query("name"));
	me->set("bonze/dadangid", obj->query("id"));
	return 1;


}

void init()
{
	add_action("do_dadang", "dadang");
}

string ask_cancel()
{
	object me=this_player();
	return "/d/obj/yao/mieyao"->delete_mieyao(me);
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="�Ϻ�����ɽ") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"�ݰ����߶�����˵�ͷ��\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"������ħ�����ҷ�������֮���֡�\n"NOR;
	}
	return ("ƶɮ�����ס�");
}
