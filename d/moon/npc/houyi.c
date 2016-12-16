#include <ansi.h>

inherit NPC;

void wield_arrow();
int do_kill();

void create()
{
	set_name("����", ({"hou yi"}));
	set("gender", "����" );
	set("title",HIY"�������"NOR);
	set("long", "�����Ǵ�˵������Ÿ�̫���Ĵ�Ӣ�ۡ�\n");
	set("age", 35);
	set("per", 25);
	set("attitude", "friendly");
	set("rank_info/respect", "Ӣ��");
	set("combat_exp", 2000000);
	set("daoxing", 500000);
	set("max_kee", 2700);
	set("max_sen", 1500);
	set("attitude", "friendly");
	set("per", 30);
	set("str", 50);
	set("int", 28);

	set_skill("force",180);
	set_skill("spells",180);
	set_skill("archery",200);
	set_skill("dodge",180);
	set_skill("unarmed",180);
	set_skill("parry",180);
	set_skill("luori-archery",200);
	set_skill("seashentong", 170);
	set_skill("dragonfight", 200);
	set_skill("dragonforce", 180);
	set_skill("dragon-steps", 180);
	map_skill("archery","luori-archery");
map_skill("parry","luori-archery");
	map_skill("dodge","dragon-steps");
	map_skill("spells","seashentong");
	map_skill("unarmed","dragonfight");

	set("force",3000);
	set("max_force",6000);
	set("force_factor",150);

	set("eff_dx", 500000);
	set("nkgain", 650);
	set("inquiry",([
		"����" : (: do_kill :),
	]));

	setup();
	carry_object("/d/obj/cloth/surcoat")->wear();
	carry_object("/d/obj/weapon/archery/qiankun-bow")->wield();
	carry_object("/d/obj/weapon/archery/zhentian-arrow")->wield();
}
void init()
{
	object ob;
	::init();
	set("chat_chance", 60);
	set("chat_msg", ({
		"�������쳤̾��\n",
		"������˲���ͷ�ϵĺ�ˮ��\n",
		"����������¶��һ˿��Թ��\n",
		(: random_move :)
	}) );
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "archery", "riyue" :),
	}) );
	set("inquiry", ([
		"name" : "�Ҿ������յĺ��ࡣ\n",
	]) );
	add_action("do_cast","cast");
}

int do_cast(string arg)
{
	object who = this_player();
	object me = this_object();
	message_vision("$N����$n���Ͱ͵��������ȴ��ôҲ�Ų����졣\n",who,me);
	return 1;
}

/*void attempt_apprentice(object ob)
{
	if ( !((string)ob->query("gender")=="Ů��")){
		command("shake");
		command("say �����϶���������Ů�ˣ��¹�ֻ��Ůͽ���Ҿ�ƫ����ͽ����λ" +
		RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
		return;
	}
	if ( (int)ob->query("str") <28){
		command("shake");
		command("say ���ҿ���λ" +
		RANK_D->query_respect(ob) + "�����ʲ�������ѧϰ�ҵ��书����������߾Ͱɡ�\n");
		ob->set_temp("denied_by_hou_yi",1);
		return;
	}
	if ( (int)ob->query("kill_xiwangmu") ) {
		command("hate");
		command("say ��ȥ����ĸ�ǻ쵰����ɱ�ˣ��Ҿ�����Ϊͽ��\n");
		ob->set_temp("kill_xiwangmu_hou",1);
		return;
	}
    if ( ((int)ob->query("combat_exp") < 800000) || ((int)ob->query("daoxing")<100000)) {
		command("say " + RANK_D->query_respect(ob) +
		"�ĵ��в��������Щ��ѧ�ط�������������\n");
		return;
	}

	if ( !(int)ob->query("family") ) {
		command("kick");
		command("say �����"+RANK_D->query_respect(ob)+"���������ң�\n");
		this_object()->kill_ob(ob);
		return;
	}

	command("pat "+ob->query("id"));
	command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
	"���Ŭ�����ŵ�����ĸ�Ǹ�����̫��ƨҲ���ҷ�һ����\n");
	command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}

void wield_arrow()
{
	if (!this_object()->query_temp("weapon"));
	{
		carry_object("/d/obj/weapon/archery/zhentian-arrow")->wield();
		message_vision("$N��һ�У����ó�һ��������\n",this_object());
	}
	message_vision((string)this_object()->query_temp("weapon"));
	remove_call_out("wield_arrow");
	call_out("wield_arrow",10);
}

int do_kill()
{
	object who = this_player();

	command("pat " + who->query("id") );
	command("say �ã�ֻҪ��ȥɱ������ĸ�����ҳ����������һ�к�������\n");
	who->delete_temp("kill_xiwangmu");
	who->set_temp("kill_xiwangmu", 1);
	return 1;
}
*/
