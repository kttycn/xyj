// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("������", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ��ھ�������ػ���----��ռʤ��������\n"
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
  set("combat_exp", 8000000);
  set("daoxing", 8000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("family/family_name","����ɽ���Ƕ�");

  set("force", 10000); 
  set("max_force", 6000);
  set("force_factor", 200);
  set("max_mana", 6000);
  set("mana", 10000);
  set("mana_factor", 200);
       set_skill("literate", 500);
       set_skill("unarmed", 500);
       set_skill("dodge", 500);
       set_skill("parry", 500);
        set_skill("stick", 500);
        set_skill("sword", 500);
        set_skill("liangyi-sword", 500);
        set_skill("spells", 500);
        set_skill("dao", 500);
        set_skill("puti-zhi", 500);
        set_skill("wuxiangforce", 500);
        set_skill("force", 500);
        set_skill("qianjun-bang", 500);
        set_skill("jindouyun", 500);
        map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: perform_action,"stick", "pili" :),
		(: perform_action,"stick","qiankun" :),
		(: perform_action,"stick","leiting" :),
		(: perform_action,"unarmed","jingmo" :),
		(: cast_spell, "thunder" :),
		(: cast_spell, "light" :),
		(: cast_spell, "taijitu" :),
		(: cast_spell, "dingshen" :),
		(: exert_function, "jldl" :),
        }) );

	setup();
   carry_object("/d/obj/weapon/stick/fake-jingubang")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
 //       add_action("do_none","perform");
 //       add_action("do_none","cast");
        add_action("do_none","exert");
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

        if((ob&&ob->query("9sky/ba")=="done") && (ob&&ob->query("9sky/jiu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "�����˾��ء������\n"NOR,users());
        ob->set("9sky/jiu","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 90000);
           ob->save();
         tell_object(ob,"��Ӯ���˾�ʮ�����");

        }
       ::die();
}


