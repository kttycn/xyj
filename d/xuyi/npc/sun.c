// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// lancaihe.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
   set_name("孙神将", ({"sun shenjiang", "sun", "shenjiang"}));
   //set("title", "");
   set("gender", "男性" );
   set("age", 50);
   set("per", 20);
   set("long", "王府的老家将，被小太子派来守护花园。\n");
   set("class", "hero");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("盱眙山", 3, "弟子");
   set_skill("unarmed", 50);
   set_skill("dodge", 80); 
   set_skill("tianwei-shi", 80);
   set_skill("parry", 90); 
   set_skill("lianhuan-tui", 50);   
 set_skill("hammer",100);
   set_skill("pangu-hammer", 100);
   set_skill("force", 80);   
   set_skill("guiyuanforce", 80);   
   set_skill("literate", 70);
   set_skill("spells", 80);
   set_skill("fumozhou", 80);
   map_skill("hammer", "pangu-hammer");
   map_skill("parry", "pangu-hammer");  
   map_skill("dodge", "tianwei-shi");    map_skill("unarmed", "lianhuan-tui");   map_skill("force", "guiyuanforce");
   map_skill("spells", "fumozhou");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 1000);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);   
   set("force_factor", 40);
   set("mana_factor", 40);

   setup();
   carry_object("/d/obj/cloth/linen")->wear();
   carry_object("/d/obj/armor/tongjia")->wear();
  carry_object("/d/obj/weapon/hammer/kunwu")->wield();
}
void init()
{       
   object ob=this_player();
   object me=this_object();

   ::init();

   set("chat_chance", 10);
   set("inquiry", ([
     "flower" : "你能帮我把花送到娘娘那里吗？\n",
    ]) );

   set("chat_msg", ({
     "孙神将喃喃自语：我家公子对水母娘娘有意思，不知道什么时候能喝到喜酒。\n",   
     "孙神将喃喃自语：公子派我来帮娘娘守护花园，我一定要好好守护，不辜负公子的期望。\n",
     "孙神将喃喃自语：在这花园里面呆久了，我人都变得更有活力了。\n",
   }) );


}


void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="盱眙山" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
        else command("say 师姑见笑了。\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
        else command("say 师妹太客气了。\n");
     }
     else 
     {
        command("consider");
        command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "男性" ) ob->set("title", "盱眙山王宫侍卫");
        else ob->set("title", "盱眙山王宫侍女");

     }
   }

   else
   {
     command("say 好，那我就勉为其难吧。\n");
     command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "男性" ) ob->set("title", "盱眙山王宫侍卫");
        else ob->set("title", "盱眙山王宫侍女");

   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "hero");
}

int accept_fight(object me)
{
        command("say 我为王府神将，岂能与你村野匹夫较艺！");
        return 0;
}


