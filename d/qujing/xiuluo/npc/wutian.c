inherit NPC;
#include <ansi.h>
string ask_jiangli();
void create()
{
	set_name(HIR"����"NOR, ({"wu tian"}));
	set("long","�������������ͷ���ڰ�֮��\n");
	set("gender", "����");
	set("age", 50000);
	set("title", HIB"ħ��"NOR);
	set("str",100);
	set("per",100);
	set("max_kee", 10000);
	set("max_gin", 10000);
	set("max_sen", 10000);
	set("force", 10000);
	set("max_force", 10000);
	set("force_factor", 500);
	set("max_mana", 10000);
	set("mana", 10000);
	set("mana_factor", 500);
	set("combat_exp", 4000000);
	set("daoxing", 10000000);

	set_skill("literate", 300);
	set_skill("spells", 300);
	set_skill("buddhism", 300);
	set_skill("unarmed", 300);
	set_skill("jienan-zhi", 300);
	set_skill("dodge", 300);
	set_skill("lotusmove", 300);
	set_skill("parry", 300);
	set_skill("force", 300);
	set_skill("lotusforce", 300);
	set_skill("staff", 300);
	set_skill("lunhui-zhang", 300);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
	}) );
	set("inquiry", ([
		"����" : (: ask_jiangli :),
		"Ǭ��ͼ" : (: ask_jiangli :),
		"ͼ" : (: ask_jiangli :),
		"��ѧ" : (: ask_jiangli :),
	]) );

	setup();
	carry_object("/d/obj/cloth/jia_sha")->wear();
}

string ask_jiangli()
{
	object me = this_player();
	object tu;
	if(me->query("xiuluo/jinchanzi")!="done" )
		return "����ȵ����𣿺ߣ�\n";
	if ( (string)me->query("xiuluo/tu") == "done")
		return "�Ҳ����Ѿ���������\n";
	if ( (string)me->query("xiuluo/tu") == "done")
		return "�Ѿ������ˣ�\n";
	command("say ����Ҫ������\n");
	command("hmm ");
	command("say ���ˣ�����ɡ�\n");
	me->set("xiuluo/tu","done");
	tu = new("obj/tu");
	tu->move(me);
	return "����һ��ҪΪ��ħ��Ч����֪����\n";
}
