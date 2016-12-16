// ����Сɮxiaoseng.c

#include <ansi.h>
inherit NPC;
string ask_for_zhulan();

void create()
{
	set_name("����Сɮ", ({ "daza xiaoseng", "xiaoseng" }) );

	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 200);
	set("max_atman", 200);

	set("force", 150);
	set("max_force", 150);
	set("force_factor", 5);

	set("mana", 200);
	set("max_mana", 200);

	set("combat_exp", 10000);

	set("inquiry", ([
		"����" : (: ask_for_zhulan :),
	]) );

	set_skill("blade", 20);
	set_skill("unarmed", 30);
	set_skill("force", 25);
	set_skill("dodge", 20);
	set_skill("literate", 20);
	set_skill("parry", 20);
	set_skill("spells", 10);

	set_skill("lotusforce", 20);
	set_skill("buddhism", 20);

	map_skill("force", "lotusforce");
	map_skill("spells", "buddhism");

	create_family("�Ϻ�����ɽ", 4, "����");

	setup();

	carry_object("/d/nanhai/obj/sengpao")->wear();
	carry_object("/d/nanhai/obj/kandao")->wield();  
}

string ask_for_zhulan()
{
	object me=this_player();
	object kandao=present("kan dao",this_object());

	if((string)me->query("family/family_name")!="�Ϻ�����ɽ")
		return ("�����Ǳ������ˡ�");
	if(me->query("faith")>300||me->query("combat_exp")>50000)
		return ("���Ǳ��Ŵ�������֮�ˣ����������������������أ�");
	if(!kandao) return ("�Ѿ�����ȥ�������������ˡ�");

	me->set("nanhai/zhulan",1);
	kandao->move(me);
	message_vision("$N�ݸ���һ�ѿ�����\n",this_object());
	return ("��������������ȥ��Щ���ӡ�");
}
