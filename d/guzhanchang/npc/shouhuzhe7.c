// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("Ů�����", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ�����������ػ���----����֮ĸŮ�����\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("family/family_name","�¹�");

  set("title", "�ػ���");
  set("combat_exp", 8000000);
  set("daoxing", 8000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 10000); 
  set("max_force", 6000);
  set("force_factor", 200);
  set("max_mana", 6000);
  set("mana", 10000);
  set("mana_factor", 200);
       set_skill("literate", 450);
       set_skill("unarmed", 450);
       set_skill("dodge", 450);
       set_skill("force", 450);
       set_skill("parry", 450);
       set_skill("sword", 450);
       set_skill("spells", 450);
   set_skill("moonshentong", 450);
   set_skill("baihua-zhang", 450);
   set_skill("moonforce", 450);
   set_skill("snowsword", 450);
   set_skill("moondance", 450);
   map_skill("spells", "moonshentong");
   map_skill("unarmed", "baihua-zhang");
   map_skill("force", "moonforce");
   map_skill("sword", "snowsword");
   map_skill("parry", "snowsword");
   map_skill("dodge", "moondance");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(: cast_spell, "arrow" :),
		(: cast_spell, "mihun" :),
		(: cast_spell, "shiyue" :),
		(: cast_spell, "huimeng" :),
                (: perform_action,"sword", "tian" :),
                (: perform_action,"sword", "wuxue" :),
                (: perform_action,"sword", "huifeng" :),
                (: perform_action,"whip", "qingwang" :),
        }) );



	setup();
   carry_object("/d/obj/weapon/sword/qingfeng")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
 //       add_action("do_none","perform");
 //       add_action("do_none","cast");
        add_action("do_none","ji");
        add_action("do_none","exert");

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

        if((ob&&ob->query("9sky/liu")=="done") && (ob&&ob->query("9sky/qi")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "���������ء�������\n"NOR,users());
        ob->set("9sky/qi","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 70000);
           ob->save();
         tell_object(ob,"��Ӯ������ʮ�����");

        }
       ::die();
}


