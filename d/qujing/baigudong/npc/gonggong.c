#include <ansi.h>
inherit NPC;

void check_kill(object me,object who);

void create()
{
  set_name("�Ϲ���", ({"gong gong", "gong"}));
  set("gender", "����");
   set("long",@LONG
�׷������棬���������ǡ����������ͣ�����Ͻ��ǡ�
������ͷ�գ��������ᡣ���������У��������޾���
LONG);
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 400000);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("gouhunshu", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jinghun-zhang", 50);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 700);
  set("max_kee", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("mana", 800);
  set("max_mana", 800);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/qujing/baoxiang/obj/longtou");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();

    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;

  if (! who ||
      environment(who) != environment(me))
  return;

  message_vision ("$N��$n˵�����������ɼ���СŮ���ޣ�\n",me,who);
}

void unconcious()
{
  die();
}

void die ()
{
	object me = this_object();
	object ob = query_temp("my_killer");
	object corpse;

	if (ob)
		ob->set_temp("obstacle/sanda_gonggong_killed",1);
	message_vision ("\n$N�����ڵ��ϣ����ˣ��ֳ�һ�Ѱ׹ǡ�\n",me);
	corpse = CHAR_D->make_corpse(me,ob);
	corpse->move(environment(me));
	if (ob->query("obstacle/sanda") == "done")
		return;
	if (! ob->query_temp("obstacle/sanda_nuzi_killed"))
		return;
	if (! ob->query_temp("obstacle/sanda_furen_killed"))
		return;
	if (! ob->query_temp("obstacle/sanda_gonggong_killed"))
		return;
	check_kill(me,ob);
	destruct(me);
}

void kill_ob (object ob)
{
	set_temp("my_killer",ob);
	::kill_ob(ob);
}

void check_kill(object me,object who)
{
	who->set_temp("obstacle/killed_num",0);
	if(who->query_temp("obstacle/sanda_nuzi_killed")) 
		who->set_temp("obstacle/killed_num",who->query_temp("obstacle/killed_num")+1);
	if(who->query_temp("obstacle/sanda_furen_killed"))
		who->set_temp("obstacle/killed_num",who->query_temp("obstacle/killed_num")+1);
	if(who->query_temp("obstacle/sanda_gonggong_killed"))
		who->set_temp("obstacle/killed_num",who->query_temp("obstacle/killed_num")+1);
	if(who->query_temp("obstacle/killed_num")>=3)
		who->set_temp("obstacle/sanda_yao_killed","done");
	message_vision(HIY "\nͻȻһ����ι�����ʱ���Ʊ��գ�һ�ɺ�����ɽʯ�µ��¶�����\n"+
	"����ԼԼ����һ���޴�İ������������У�ֻ����һ����Ц��������ô��ʰ�㣡\n"+
	"˵�գ�����һ����������ȥ!\n" NOR,who);
}
