// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("��������", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ�����������ػ���----�ĺ�������������\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("family/family_name","��������");
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "�ػ���");
  set("combat_exp", 6000000);
  set("daoxing", 6000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 10000); 
  set("max_force", 6000);
  set("force_factor", 200);
  set("max_mana", 10000);
  set("mana", 6000);
  set("mana_factor", 200);
       set_skill("literate", 400);
       set_skill("unarmed", 400);
       set_skill("dodge", 400);
       set_skill("force", 400);
       set_skill("parry", 400);
       set_skill("fork", 400);
       set_skill("spells", 400);
       set_skill("seashentong", 400);
       set_skill("dragonfight", 400);
       set_skill("dragonforce", 400);
//       set_skill("fengbo-cha", 400);
       set_skill("dragon-cha", 400);
       set_skill("dragon-steps", 400);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
//       map_skill("fork", "fengbo-cha");
       map_skill("fork", "dragon-cha");
       map_skill("parry", "dragon-cha");
       map_skill("dodge", "dragon-steps");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
		(: cast_spell, "freez" :),
		(: cast_spell, "water" :),
		(: cast_spell, "dragonfire" :),
		(: exert_function, "roar" :),
		(: exert_function, "shield" :),
     		(: perform_action,"hammer", "dragon" :),
       		(: perform_action,"fork", "fengbo" :),
                }) );

	setup();
        carry_object("/d/obj/weapon/fork/fork")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
//        add_action("do_none","perform");
//        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("������磬������������\n",me);
        return 1;
} 

void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("9sky/san")=="done") && (ob&&ob->query("9sky/si")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "���������ء�¥����\n"NOR,users());
        ob->set("9sky/si","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 40000);
           ob->save();
         tell_object(ob,"��Ӯ������ʮ�����");

        }
       ::die();
}


