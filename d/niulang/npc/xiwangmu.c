// By canoe 2001.03.25
#include <ansi.h>
inherit NPC;
object dog() {return query("dog");}
object juling() {return query("juling");}
object yangjian() {return query("yangjian");}
object target() {return query("target");}

int die() {return 1;}
int unconcious() {return 1;}
int valid_killer(object);
void time_up();
void go_home();
int do_jianmian();
void start();
void call_juling();
void call_yangjian();
void retreat();
void create()
{
	set_name("��ĸ����", ({"xi wangmu", "xi", "wangmu","master"}));
	set("long", "����������������������������ء�\n");
	set("title", WHT"֯Ů֮ĸ"NOR);
	set("gender","Ů��");
	set("age", 100);
	set("class","xian");
	set("attitude", "friendly");
	set("rank_info/respect", "��̫̫");
	set("cor", 30);
	set("per", 30);
	set("looking", "��ɫ����������̬��");
	set("max_kee", 4500);
	set("max_gin", 800);
	set("max_sen", 4500);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 125);
	set("max_mana", 2000);
	set("mana", 4000);
	set("mana_factor", 100);
	set("combat_exp", 2000000);
	set_skill("literate", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("force", 180);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("spells", 180);
	set_skill("moonshentong", 180);
	set_skill("baihua-zhang", 180);
	set_skill("moonforce", 180);
	set_skill("snowsword", 200);
	set_skill("moondance", 150);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	set("chat_chance_combat", 50);
	set("inquiry", ([
		"jianmian" : (: do_jianmian :),
		"����" : (: do_jianmian :),
	]) );
	call_out("time_up",600);   
	setup();
}
int do_jianmian()
{
	object me=this_player();
	object ob=this_object();
	if (!me->query_temp("ask_niulang")) return notify_fail("��˵ʲô�Ҳ�֪��Ү��\n");
	set("target",me);
	start();
	return 1;
}
   
void time_up() {
	if (target()) {
		command("say ���������������������ˣ��������ǽ��겻�ܼ����ˣ�");
		command("say ������ֻ�����������ˣ�");
		target()->delete_temp("askd_niulang");
	}
	go_home();
}

void heart_beat()
{
	object target=target();

	set("eff_kee", 2000);
	set("eff_sen", 2000);
	set("kee",2000);
	set("sen",2000);
	set("force",4000);
	set("mana",4000);

	if (target && target->is_ghost()) {
		message_vision(HIY"$N������Ц��������ˮƽҲ���ֹ�����������ȭͷ�����������\n"NOR,this_object());
		command("kick corpse");
		go_home();
		return;
	}
	if (!target || environment(this_object())!=environment(target)) {
		message_vision(HIY"$N������Ц������������Ҳ�������ֹ�������\n"NOR,this_object());
		command("puke");
		go_home();
		return;
	}
	::heart_beat();
}

int valid_killer(object killer)
{
	object target=target();
	object me=this_object();

	if (target!=killer && environment(me)==environment(target)) {
		command("sneer");
		command("say �ж�ȡʤ��"+target->query("name")+
		"ԭ��Ҳ���˵�����֮������");
		command("bye");
		target->delete_temp("askd_niulang");
		go_home();
		return 0;
	}
	return 1;
}

void kill_ob(object ob)
{
	object me=this_object();
	object target=me->query("target");

	if (!target) ::kill_ob(ob);
	if (valid_killer(ob)) ::kill_ob(ob);
}
	 
void go_home()
{
	object me=this_object();

	message_vision(HIY"$N��һ�ӣ�һ�����֮��$N������Ӽ��ƶ�ȥ��\n"NOR,me);	   
	remove_call_out("call_juling");
	remove_call_out("call_yangjian");
	remove_call_out("retreat");
	destruct(dog());
	destruct(juling());
	destruct(yangjian());
	destruct(me);
}

void start()
{
	object me=this_object();
	object target=target();
	object dog=new(__DIR__"dog");
	object yangjian=new(__DIR__"yangjian");
	object juling=new(__DIR__"juling");

	set("dog",dog);
	set("yangjian",yangjian);
	yangjian->set("master",me);
	set("juling",juling);
	juling->set("master",me);
	dog->move(environment(me));
	yangjian->move(environment(me));
	juling->move(environment(me));

	message_vision(HIY"��ĸ����˵��������!����!�ҵļ��²�����ܣ���\n"NOR,me);
	message_vision(HIY"��ĸ������մ�ŭ����Ȼ��ɫ�������ˣ�������������������\n"NOR,me);
	message_vision(HIY"ֻ��Զ��Ʈ��һ�������ƣ����ƹ�������������ƶˡ�\n"NOR,me);
	message_vision(HIY"һ�����һ�����ڣ���꯴�����������Ȯ����ͷ����������\n"NOR,me);
	call_out("call_juling",5);
}

void call_juling()
{
	object me=this_object();
	object juling=me->juling();
	object target=me->target();

	if (!target || !juling) return;

	tell_object(target,"��ĸ����һָ���ȵ��������������ˣ���\n\n");
	message_vision(HIY"$N��һ�ӣ��ȷ�پ���������ͷ��$n��ɱ����\n\n"NOR,me,target);
	message_vision(HIY"$N����������"+RANK_D->query_rude(target)+
	"�����Ͷ����û�ô�ү�����˸�ͷ����\n"NOR,juling());

	juling->kill_ob(target);
	juling->set("on_job",1);
}

void lose(object loser)
{
	object me=this_object();

	command("kick "+loser->query("id"));
	if (loser==juling()) call_out("call_yangjian",5);
	if (loser==yangjian())   call_out("retreat",5);
}

void call_yangjian()
{
	message_vision(HIY"$N������üͷ����꯻��⣬��Ȯɱ��������\n"NOR,this_object());
	yangjian()->kill_ob(target());
	dog()->kill_ob(target());
	yangjian()->set("on_job",1);
}

void retreat()
{
	command("chat ���˰��ˣ����콫�����㲻�Σ����Լ��뷨�����Ǽ���ɡ�");
	command("grin");
	command("say ���û�����ˣ���������ô�죡������");
	go_home();
}
