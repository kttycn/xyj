// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("���½�ʥ", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ��ڶ�������ػ���----��ɽ������½�ʥ\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("family/family_name","��ɽ����");

  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "�ػ���");
  set("combat_exp", 4000000);
  set("daoxing", 4000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 10000); 
  set("max_force", 6000);
  set("force_factor", 200);
  set("max_mana", 6000);
  set("mana", 10000);
  set("mana_factor", 200);
	
        set_skill("spells",350);
        set_skill("force", 350);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("sword", 350);
        set_skill("zixia-shengong", 350);
        set_skill("seven-steps", 350);
        set_skill("hunyuan-zhang", 350);
        set_skill("literate", 350);
        set_skill("unarmed", 350);
        set_skill("mindsword", 350);
	set_skill("canxin-jian", 350);
        set_skill("taoism",350);
        map_skill("spells", "taoism");
        map_skill("dodge", "seven-steps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "mindsword");
        map_skill("sword", "mindsword");
        map_skill("unarmed", "hunyuan-zhang");
       set("chat_chance_combat", 50);
              set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(: perform_action,"sword", "tianjian" :),
		(: perform_action,"sword", "fumo" :),
		(: perform_action,"sword", "duanshui" :),
		(: perform_action,"sword", "wanjian" :),
		(: perform_action,"unarmed", "shou" :),
		(: cast_spell, "jianshen" :),
		(: cast_spell, "fu" :),
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

        if((ob&&ob->query("9sky/yi")=="done") && (ob&&ob->query("9sky/er")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "�����˶��ء�������\n"NOR,users());
        ob->set("9sky/er","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 20000);
           ob->save();
         tell_object(ob,"��Ӯ���˶�ʮ�����");

        }
       ::die();
}

