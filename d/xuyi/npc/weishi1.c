// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�س���ʿ", ({ "guard soldier", "soldier", "guard" }) );
        set("gender", "����");
        set("age", 25);
        set("long",

"����λ�ػ�ϙ�ǵ���ʿ������ͭ�ף���ִ���컭ꪡ�
��˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("combat_exp", 160000);
        set("attitude", "heroism");
        set("str", 25);
        set("max_kee", 1000);
        set("max_sen", 800);
        set("force", 800);
        set("max_force", 400);
        set("force_factor", 15);
        set("mana", 1000);
        set("max_mana", 500);
        set("mana_factor", 30);        
        set_skill("halberd", 40);
        set_skill("unarmed", 40);
        set_skill("tianlong-halberd", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        map_skill("halberd", "tianlong-halberd");
        map_skill("parry", "tianlong-halberd");
        set_skill("force", 50);
        set_temp("xuyi/monster", 1);
        set("no_cast", 1);
        set("no_ji", 1);
        setup();

        carry_object("/d/obj/weapon/halberd/sanchaji")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}


void check_kill (object me);
void check_follow (object me);

void init()
{
  check_follow (this_player());
  remove_call_out("check_kill");
  call_out("check_kill",1,this_object());
}

void check_follow (object who)
{
  object me = this_object();

  if (!who->query_temp("xuyi/monster"))
    return;
  if(me->query("guard")!=who->query("id")) return;
  
  if (me->query("following")!=who->query("id"))
  {
    command("follow "+who->query("id"));
    me->set("following",who->query("id"));
    me->set_temp("no_return",1);
    remove_call_out("remove_no_return");
    call_out("remove_no_return",3600,me);
  }
}

void check_kill (object me)
{
  object where = environment(me);
  object who = present ("monster",where);

  if (who && (! interactive(who)))
  {  
    if (me->query("killing")==0)
    {
      command ("kill monster");
      me->set("killing",1);
    }
    
    if (who)
    {
      who->kill_ob(me);
      me->kill_ob(who);
    }

  }
}

void remove_no_return(object me)
{
  me->set_temp("no_return",0);
}

