// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created bye night

inherit NPC;

int fresh=1;
int MAX_MANA=1200, SPELLS=200, DAOXING=300000;
void copy_status(object me, object ob);

void create()
{
   set_name("����", ({ "qi lin", "qilin" }) );
   set("race", "Ұ��");
   set("gender", "����" );
   set("age", 120);
   set("long", "һֻ��˵�е����ޣ��������ۣ�¹�����롣\n");
   set("attitude", "heroism");
   set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��", "��Ƥ"}) );
   set("verbs", ({ "bite", "claw"}) );
   

   set("str", 40);
   set("cor", 25);
   set("cps", 25);
   set("int", 25);

   set("max_kee", 1000);
   set("max_gin", 1000);
   set("max_sen", 1000);
   set("max_force", 1000);
   set("max_mana", MAX_MANA);
   set("mana", MAX_MANA);

   set("combat_exp", DAOXING);

  set_temp("apply/attack", 50+random(50));
  set_temp("apply/damage", 50+random(50));
  set_temp("apply/armor", 100+random(100));

   set_skill("spells",SPELLS);
   set_skill("force", 140); 
   set_skill("unarmed", 140);
   set_skill("dodge", 140);
   set_skill("parry", 140);

        setup();

}

int accept_fight(object ob)
{
   object me;

   me = this_object();

   if (is_fighting()) return 0;

   copy_status(me,ob);

   return 1;
}

void kill_ob(object ob)
{
   object me=this_object();

   copy_status(me,ob);
   ::kill_ob(ob);
}

void copy_status(object me, object ob)
{
        mapping hp_status, skill_status, map_status;
        string *sname, *mname;
   int i,j;
        // delete old skills.
        if(skill_status = me->query_skills()) {
           sname  = keys(skill_status);
      j=sizeof(skill_status);
           for(i=0; i<j; i++) {
        me->delete_skill(sname[i]);
           }
        }
        //copy new skills.
   if (skill_status = ob->query_skills() ) {
      sname  = keys(skill_status);
      for(i=0; i<sizeof(skill_status); i++) {
     me->set_skill(sname[i], skill_status[sname[i]]-random(5));
      }
        }
   
      //delete old skill mappings.
   if(map_status = me->query_skill_map()) {
     mname  = keys(map_status);
     j=sizeof(map_status);
     for(i=0; i<j; i++) {
       me->map_skill(mname[i]);
          }
        }
         
        //add new skill mappings.
   if (map_status = ob->query_skill_map()) {
     mname  = keys(map_status);
     for(i=0; i<sizeof(map_status); i++) {
     me->map_skill(mname[i], map_status[mname[i]]);
     }
        }

   hp_status = ob->query_entire_dbase();

   me->set("str", hp_status["str"]);
   me->set("int", hp_status["int"]);
   me->set("con", hp_status["con"]);
   me->set("cps", hp_status["cps"]);
   me->set("cor", hp_status["cor"]);
   me->set("spi", hp_status["spi"]);
   me->set("per", hp_status["per"]);
   me->set("kar", hp_status["kar"]);
 
        if(fresh==1) {
           fresh=0;
     me->set("eff_kee",    hp_status["eff_kee"]);
     me->set("kee",        hp_status["kee"]);
     me->set("eff_gin",  hp_status["eff_gin"]);
     me->set("gin",      hp_status["gin"]);
     me->set("eff_sen",  hp_status["eff_sen"]);
     me->set("sen",      hp_status["sen"]);

                me->set("eff_dx", me->query("combat_exp"));
           if(COMBAT_D->check_family(ob->query("family/family_name"))
              >0)
           me->set("eff_dx", -me->query("eff_dx"));

     if(me->query("combat_exp")>10000)
       me->set("nkgain",150); //maximum gain for killing qm.
        }
   me->set("max_kee",    hp_status["max_kee"]);
   me->set("max_gin",  hp_status["max_gin"]);
   me->set("max_sen",  hp_status["max_sen"]);
   me->set("max_force", hp_status["max_force"]);
   me->set("force",     hp_status["force"]);
   me->set("max_mana", hp_status["max_mana"]);
   me->set("mana",     hp_status["mana"]);   
   me->set("force_factor",     hp_status["force_factor"]);
   me->set("mana_factor",     hp_status["mana_factor"]);
   me->set("combat_exp",hp_status["combat_exp"]+
           hp_status["combat_exp"]/50);

   return ;
}

void auto_recovery()
{
        object me=this_object();

   me->set("eff_gin", (int)me->query("max_gin"));
   me->set("gin", (int)me->query("max_gin"));
   me->set("eff_kee", (int)me->query("max_kee"));
   me->set("kee", (int)me->query("max_kee"));
   me->set("eff_sen", (int)me->query("max_sen"));
   me->set("sen", (int)me->query("max_sen"));
        
        me->set("force", (int)me->query("max_force"));
        me->set("atman", (int)me->query("max_atman"));
        me->set("mana", (int)me->query("max_mana"));

        me->delete("eff_dx");
   me->delete("nkgain");

   fresh=1;
}

void init()
{
        ::init();
        add_action("do_train", "train");
}

int do_train()
{
   object me,who;
   object rider;
   object ridee;
   
   me = this_object();
   who = this_player();

  ridee = who->query_temp("ridee");

        if(me->is_fighting())
        return notify_fail("��ֻ"+me->name()+"����ս����\n");

  if (ridee &&
      environment(ridee) != environment(who))
   ridee = 0;

  if (ridee)
    return notify_fail ("���Ѿ�"+ridee->query("ride/msg")+"��"+ridee->name()+"���ˣ�\n");

  rider = me->query_temp("rider");
  if (rider &&
      environment(rider) != environment(me))
   rider = 0;

  if (rider)
    return notify_fail (me->name()+"���������ˣ�\n");

        message_vision("$N��������$nŤ��һ��\n",who, me);
        me->kill_ob(who);
        who->kill_ob(me);
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
   me->set("trainer",who->query("id"));
   return 1;
}

void unconcious ()
{
  die ();
}

void die()
{
   string trainer;
   object trainer_ob;

   trainer = query("trainer");
   if(trainer) trainer_ob= find_player(trainer);

   if(trainer_ob &&  (object)query_temp("last_damage_from") == trainer_ob ) {
  set("eff_kee", 1000);
  set("eff_gin", 1000);
  set("eff_sen", 1000);
  set("kee", 1000);
  set("gin", 1000);
  set("sen", 1000);
  set("force", 1000);
  set("mana", MAX_MANA);
  set("ride/msg", "��");
    remove_all_killer();    
   trainer_ob->remove_all_killer();
  set("ride/dodge", trainer_ob->query_skill("dodge")/10+20);
     message_vision("$N��ͷ��β����ʾ������\n",this_object());
  set("owner",trainer);

     return;
     }
   ::die();
}

