// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// created by jing&night

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("����", ({"zhao shenjiang", "zhao", "shenjiang"}));
   //set("title", "");
   set("gender", "����" );
   set("age", 28);
   set("per", 20);
   set("long", "һλ���ȵ������ˣ��ػ���ϙ���ٺ��ĳ��š�\n");
   set("class", "xian");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("����ɽ", 3, "����");
   set_skill("unarmed", 60);
   set_skill("dodge", 70); 
   set_skill("tianwei-shi", 70);
   set_skill("parry", 80); 
   set_skill("lianhuan-tui", 60);   
     set_skill("halberd", 80);
   set_skill("tianlong-halberd", 80);
   set_skill("force", 70);   
   set_skill("guiyuanforce", 70);   
   set_skill("literate", 80);
   set_skill("spells", 80);
   set_skill("fumozhou", 80);
   map_skill("halberd", "tianlong-halberd");
   map_skill("parry", "tianlong-halberd");  
   map_skill("dodge", "tianwei-shi");   
     map_skill("unarmed", "lianhuan-tui");          
     map_skill("force", "guiyuanforce");
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
   carry_object("/d/obj/weapon/halberd/huaji")->wield();
}


void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="����ɽ" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
        else command("say ʦ�ü�Ц�ˡ�\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        if ( (string)ob->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
        else command("say ʦ��̫�����ˡ�\n");
     }
     else 
     {
        command("consider");
        command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "����" ) ob->set("title", "����ɽ�س���ʿ");
        else ob->set("title", "����ɽ�س�Ů��");
     }
   }

   else
   {
     command("say �ã����Ҿ���Ϊ���Ѱɡ�\n");
     command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "����" ) ob->set("title", "����ɽ�س���ʿ");
        else ob->set("title", "����ɽ�س�Ů��");

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
        command("say ��Ϊ�����񽫣����������Ұƥ����գ�");
        return 0;
}


