// happyboy.c �����к�

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����к�", ({ "happy boy", "boy" }));
	set("age", 18);
	set("gender", "����");
	set("long", "����Ů��һ�������ǻ��ֽӵ���ѡʹ�ߡ�\n");
	set("attitude", "friendly");
	set("nickname", HIC"����ʹ��"NOR);
	set("shen_type", 1);
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 26);
	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("unarmed", 35);
	set_skill("dodge", 35);
	set_skill("parry", 35);
	set_skill("force", 35);
       
        setup();
    carry_object("/d/city/liwu/obj/jiericloth")->wear();
}

