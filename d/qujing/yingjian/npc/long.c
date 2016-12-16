//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("С����", ({"bai long","long","dragon"}));
          set("long","������������������֮�ӣ���������֮��������˼䡣\n");
          set("gender", "����");
          set("age", 23);
          set("per",30);        
          set("combat_exp", 500000);
          set("daoxing", 500000);
          set("per", 30);
          set("str", 30);
          set("max_kee", 1200);
          set("kee",1200);
          set("force_factor",20);
          set("max_sen", 800);
          set("env/wimpy",50);
          set("sen",800);
          set("force", 3000);
          set("max_force", 1500);
          set("max_mana", 800);
          set("mana", 1600);
          set_skill("unarmed", 100);
          set_skill("dodge", 80);
          set_skill("force", 80);
          set_skill("parry", 80);
          set_skill("hammer", 90);
          set_skill("fork", 80);
          set_skill("spells", 100);
          set_skill("seashentong", 100);
          set_skill("dragonfight", 100);
          set_skill("dragonforce", 90);
          set_skill("huntian-hammer", 90);
          set_skill("dragon-cha", 100);
          set_skill("dragon-steps", 80);
          map_skill("spells", "seashentong");
          map_skill("unarmed", "dragonfight");
          map_skill("force", "dragonforce");
          map_skill("fork", "dragon-cha");
          map_skill("parry", "dragon-cha");
          map_skill("dodge", "dragon-steps");

         setup();
        carry_object("/d/sea/obj/longpao")->wear();
        carry_object("/d/sea/obj/dragonfork")->wield();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}
void destruct_me (object me)
{
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
  call_out ("move_to_cave",1,this_object());
}

void move_to_cave (object me)
{
        tell_room(environment(me),HIY"С����ҡ��һ�䣬��ú�С����һģһ����\n"NOR);
        tell_room(environment(me),"С��������ʧ��.....\n");
        this_object()->set_name("[31mС����[m",({"xiao yumiao","fish"}));
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
    ob->set_temp("obstacle/long_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("\nֻ��С����˻��һ�����������ԭ������������\n",ob);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/yingjian/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}

void unconcious ()
{
  die ();
}