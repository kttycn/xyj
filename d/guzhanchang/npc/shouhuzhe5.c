// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("������", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ�����������ػ���----�������߽�����\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("family/family_name","��ׯ��");

  set("con", 40);
  set("spi", 40);
  set("title", "�ػ���");
  set("combat_exp", 6000000);
  set("daoxing", 6000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 10000); 
  set("max_force", 6000);
  set("force_factor", 100);
  set("max_mana", 6000);
  set("mana", 10000);
  set("mana_factor", 100);
   set_skill("unarmed", 400);
   set_skill("wuxing-quan", 400);
   set_skill("dodge", 400);
   set_skill("baguazhen", 400);
   set_skill("parry", 400);
   set_skill("sword", 400);
   set_skill("sanqing-jian", 400);
   set_skill("staff", 400);
   set_skill("fumo-zhang", 400);
   set_skill("hammer", 400);
   set_skill("kaishan-chui", 400);
   set_skill("blade", 400);
   set_skill("yange-blade", 400);
   set_skill("force", 400);   
   set_skill("zhenyuan-force", 400);
   set_skill("literate", 400);
   set_skill("spells", 400);
   set_skill("taiyi", 400);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "fumo-zhang");
   map_skill("blade", "yange-blade");
   map_skill("hammer", "kaishan-chui");

   set("chat_chance_combat", 90);
   set("chat_msg_combat", 
   ({
		(: perform_action,"sword", "juejian" :),
		(: perform_action,"sword", "hammer" :),
		(: perform_action,"sword", "staff" :),
		(: perform_action,"sword", "jianmang" :),
		(: perform_action,"sword", "jianzhang" :),
		(: perform_action,"sword", "jianqi" :),
		(: perform_action,"staff", "luanwu" :),
		(: perform_action,"hammer", "danshan" :),
		(: cast_spell, "zhenhuo" :),
		(: cast_spell, "qiankun" :),
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

        if((ob&&ob->query("9sky/si")=="done") && (ob&&ob->query("9sky/wu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "���������ء�ǧ����\n"NOR,users());
        ob->set("9sky/wu","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 50000);
           ob->save();
         tell_object(ob,"��Ӯ������ʮ�����");

        }
       ::die();
}


