// happygirl.c ����Ů��

#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;
//inherit F_DEALER;

void create()
{
	set_name("����Ů��", ({ "happy girl", "girl" }));
//	set("title", "���ֽ�����");
	set("nickname", HIR"����ʹ��"NOR);
	set("shen_type", 1);

	set("str", 16);
	set("gender", "Ů��");
	set("age", 18);
	set("long",
		"����������ǰ����һ�����ΰ��Ů����������ʹ�����գ�ħ�����ģ�\n"
		"����������������һ�㡣\n");
	set("combat_exp", 4000);
	set("attitude", "friendly");
	set_skill("unarmed",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set_skill("force",30);

	set("inquiry", ([
		"����" : "�����ǽ���Ү������������ɡ�\n",
		"����" : "��ϲ�����ҳ�����\n",
	]));
    setup();	
    carry_object("/d/city/liwu/obj/jiericloth")->wear();
}

