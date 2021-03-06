// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//master.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("大圣国师王菩萨", ({"guoshiwang pusa","pusa", "guoshiwang"}));
       set("long", "南赡奇人，古武学的一代宗师，面目间仍然流露出一种萧杀之气。\n");
       set("title", "普度众生");
       set("gender", "男性");
       set("age", 90);
   set("class", "hero");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "大圣国师王");
       set("per", 26);
   set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 2000000);

       set_skill("literate", 250);
       set_skill("unarmed", 250);
       set_skill("dodge", 280);
       set_skill("parry", 300);
   set_skill("halberd", 280);
   set_skill("spells", 270);
   set_skill("fumozhou", 280);
   set_skill("lianhuan-tui", 250);
   set_skill("guiyuanforce", 280);
   set_skill("force", 270);
   set_skill("hammer", 250);
   set_skill("pangu-hammer", 250);
   set_skill("tianlong-halberd", 300);
   set_skill("tianwei-shi", 280);
   map_skill("spells", "fumozhou");
   map_skill("unarmed", "lianhuan-tui");
   map_skill("hammer", "pangu-hammer");
   map_skill("force", "guiyuanforce");
   map_skill("halberd", "tianlong-halberd");
   map_skill("parry", "tianlong-halberd");
   map_skill("dodge", "tianwei-shi");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
//      (: cast_spell, "freeze" :),
     (: cast_spell, "wanlei" :),
     (: cast_spell, "sword" :)
        }) );

create_family("盱眙山", 1, "蓝");
setup();

        carry_object("/d/obj/cloth/xianpao")->wear();
        carry_object("/d/xuyi/obj/shield")->wear();
        carry_object("/d/xuyi/obj/tianlong")->wield();
}

void attempt_apprentice(object ob)
{   ob=this_player();
   if( (string)ob->query("family/family_name")=="盱眙山") {
   if ((int)ob->query("combat_exp") < 250000 ) {
     command("say 凭你这么点道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
   return;
   }

   if( (int)ob->query_skill("fumozhou", 1) < 110 ) {
   command("say 这位" + RANK_D->query_respect(ob) + "身入我门，就要有一定的法术基础。你的伏魔咒法太低，不能传我衣钵。\n");
   command("sigh");
   return;
   }
        command("smile");
        command("say 很好，这位" + RANK_D->query_respect(ob) + "入我门下，从此天下又多了一个侠士。");
        command("recruit " + ob->query("id") );
     ob->set("mark/xuyi_pusa",1);
   return;
   }
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "hero");
}

int accept_fight(object me, object ob)
{   ob=this_player();
   command("say " + RANK_D->query_rude(ob) + "，江湖恩怨何时了，何必要打打杀杀呢？\n");
   return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n大圣国师王菩萨叹道：“长江后浪推前浪，以后就是你们年轻人的天下了！”\n\n", environment());
        command("sigh");
        message("sound", "\n大圣国师王菩萨身形一晃，飘然引去……\n\n", environment());
        }

        destruct(this_object());
}


