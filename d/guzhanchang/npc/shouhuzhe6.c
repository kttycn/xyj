// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("������", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ�����������ػ���----���ʥ��������\n"
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
  set("title", "�ػ���");
  set("combat_exp", 6000000);
  set("daoxing", 6000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 10000); 
  set("max_force", 6000);
  set("force_factor", 100);
  set("family/family_name","��ʥ��");

  set("max_mana", 6000);
  set("mana", 10000);
  set("mana_factor", 100);
        set_skill("unarmed", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("spells", 400);  
        set_skill("feisheng-spells", 400);
        set_skill("literate", 400);
        set_skill("sword", 400);  
        set_skill("wuying-sword", 400);
        set_skill("fumobashi", 400);  
        set_skill("mizong-steps", 400);
        set_skill("dodge", 400);  
        set_skill("force", 400);   
        set_skill("xiantian-force", 400);

        map_skill("spells", "feisheng-spells");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian-force");
        map_skill("sword", "wuying-sword");
        map_skill("parry", "wuying-sword");
        map_skill("dodge", "mizong-steps");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "feixian" :),
        (: cast_spell, "hufa" :),
        (: cast_spell, "wanying" :),
        (: perform_action, "sword","juechen" :),
        (: perform_action, "sword","fenge" :),
        (: perform_action, "unarmed","wanfo" :),
        (: exert_function, "qiankun" :),
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

        if((ob&&ob->query("9sky/wu")=="done") && (ob&&ob->query("9sky/liu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "���������ء���ϼ��\n"NOR,users());
        ob->set("9sky/liu","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 60000);
           ob->save();
         tell_object(ob,"��Ӯ������ʮ�����");

        }
       ::die();
}

