// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"



void create()
{
        set_name("��Ħ��ʦ", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ�����������ػ���----���֮�� ��Ħ��ʦ\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("family/family_name","�Ϻ�����ɽ");

  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "�ػ���");
  set("combat_exp", 3400000);
  set("daoxing", 3400000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 10000); 
  set("max_force", 6000);
  set("force_factor", 200);
  set("max_mana", 6000);
  set("mana", 10000);
  set("mana_factor", 200);
        set_skill("literate", 350);
        set_skill("spells", 350);
        set_skill("buddhism", 350);
        set_skill("unarmed", 350);
        set_skill("jienan-zhi", 350);
        set_skill("dodge", 350);
        set_skill("lotusmove", 350);
        set_skill("parry", 350);
        set_skill("force", 350);
        set_skill("lotusforce", 350);
        set_skill("staff", 350);
        set_skill("lunhui-zhang", 350);
        map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action,"staff", "pudu" :),
		(: perform_action,"staff", "forudiyu" :),
		(: perform_action,"staff", "poche" :),
		(: perform_action,"staff", "fuhu" :),
		(: perform_action,"staff", "shenlong" :),
		(: perform_action,"hammer", "bighammer" :),
		(: perform_action,"unarmed", "storm" :),
		(: cast_spell, "bighammer" :),
	
}) );

	setup();
        carry_object("/d/obj/weapon/staff/budd_staff")->wield();
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

        if((ob&&ob->query("9sky/er")=="done") && (ob&&ob->query("9sky/san")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "���������ء��ն���\n"NOR,users());
        ob->set("9sky/san","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 30000);
           ob->save();
         tell_object(ob,"��Ӯ������ʮ�����");

        }
       ::die();
}


