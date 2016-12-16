// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
string ask_aotang();

void create()
{
	set_name("����ƽ", ({ "wang fangping", "wang", "fangping" }));

	set("long","����ƽ����ɽ�е�ʿ�����ڷᶼɽͬ������ͬ�������ɣ�����(����������\n");
	set("attitude", "peaceful");
	set("per", 30);
	set("str", 25);
	set("int", 25);
	set("age", 30);
	set("title", "�ֻ�˾��");
	set("nickname", "����");
	set("combat_exp", 850000);
	set("daoxing", 600000);

	set("max_gin", 1400);
	set("max_kee", 1400);
	set("max_sen", 1400);
	set("class", "youling");
	set("force", 2500);
	set("max_force", 1500);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 2500);
	set("mana_factor", 100);

	set_skill("literate", 100);
	set_skill("ghost-steps", 120);
	set_skill("dodge", 120);
	set_skill("unarmed", 120);
	set_skill("parry", 120);
	set_skill("spells", 120);
	set_skill("gouhunshu", 80);
	set_skill("jinghun-zhang", 120);
	set_skill("force", 120);
	set_skill("tonsillit", 80);
	set_skill("stick", 120);
	set_skill("kusang-bang", 120);

	map_skill("stick","kusang-bang");
	map_skill("parry", "kusang-bang");
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
//                (: exert_function, "powerup" :),
		(: exert_function, "sheqi" :),
		(: cast_spell, "gouhun" :),
	}) );

    set("inquiry",([
		"��������" : (: ask_aotang :),
	]));

	set("nkgain", 400);

	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 50);


	create_family("���޵ظ�", 2, "���");

	setup();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
	carry_object("/d/obj/cloth/taijicloth")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
	command("grin");

	command("say �ܺã�" + RANK_D->query_respect(me) +
"���Ŭ�������ձض��гɡ�\n");
	command("recruit " + me->query("id") );
	me->set("class", "youling");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "youling");
	ob->set("title", HIB"�ظ��л�˾����"NOR);
}

string ask_aotang()
{
	object who = this_player();
	object me = this_object();
	if(who->query("family/family_name")!="���޵ظ�")
		return "�㲻�ǹ����ӣ�����Щ��ʲô��\n";
	if(who->query("faith")>500 || who->query("combat_exp")>50000
	|| who->query("daoxing")>50000 )
		return "�����ڵ������ô���Ը������";
	if(who->is_busy())
		return ("����æ���أ�");
	command("say �Ǻã���ȥ���Ұ�Щ����������");
	message_vision("$N��¯�������£��۾�����ؿ�������\n",who);
	who->start_busy(5);
	call_out("finish_aotang",5,who,me);
	command("nod");
	return ("��Ȼ��һ���ڿ��ˡ�");
}

void finish_aotang(object me,object master)
{
	message_vision("$N��¯�Ӹ�ǰ���˺þã������ڰ����ˣ�����һ������ֻ����˫�۱���Ѭ�ķ��ᣡ\n");
	me->receive_damage("sen",20);
	message_vision("$N�ߵ�$n��ǰ������������˵������������ү�������ˣ�û��\n",me,master);
	command("pat "+me->query("id"));
	command("say �õ��ӣ�");
	tell_object(me,HIY"����ö�����������һЩ����\n"NOR);
	me->add("faith",1);
	me->add("combat_exp",9);
	me->add("potential",3);
	me->improve_skill("tonsillit",random(me->query("int")),1);
}
