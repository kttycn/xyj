//heshang.c
//4/12/2000
//NPC

inherit NPC;

void create()
{
   set_name("����", ({ "heshang", "bonze" }));
   set("gender", "����");
   set("age", 50);
   set("attitude", "peaceful");
   set("class", "bonze");
   set("max_kee", 500);
   set("max_gin", 500);
   set("max_sen", 500);
   set("force", 550);
   set("force", 550);
   set("max_force", 550);
   set("force_factor", 20);
   set("max_mana", 450);
   set("mana", 450);
   set("mana_factor", 20); 
   set("str",28);   set("combat_exp", 200000);
   set("per",28);

   set_skill("literate", 70);
   set_skill("spells", 60);
   set_skill("unarmed", 40);
   set_skill("dodge", 40);
   set_skill("parry", 60);
   set_skill("force", 50);
   set_skill("staff", 20);
   //set("chat_chance",3); 
   setup();   add_money("silver",20);
   carry_object("/d/nanhai/obj/sengpao")->wear();
}


   
