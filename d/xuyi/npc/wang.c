// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// lancaihe.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
   set_name("����", ({"wang shenjiang", "wang", "shenjiang"}));
   //set("title", "");
   set("gender", "����" );
   set ("age", 40);
   set("per", 20);
   set("long", "�������ϼҽ���Ϊ�������ºպ�ս����\n");
   set("class", "hero");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("����ɽ", 3, "����");
   set_skill("unarmed", 50);
   set_skill("dodge", 80); 
   set_skill("tianwei-shi", 80);
   set_skill("parry", 90); 
   set_skill("lianhuan-tui", 50);   
   set_skill("halberd", 70);
   set_skill("tianlong-halberd", 80);
   set_skill("force", 80);   
   set_skill("guiyuanforce", 80);   
   set_skill("literate", 70);
   set_skill("spells", 80);
   set_skill("fumozhou", 80);
   map_skill("halberd", "tianlong-halberd");
   map_skill("parry", "tianlong-halberd");  
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
        if ( (string)ob->query("gender") == "����" ) ob->set("title", "����ɽ������ʿ");
        else ob->set("title", "����ɽ����Ůʷ");

     }
   }

   else
   {
     command("say �ã����Ҿ���Ϊ���Ѱɡ�\n");
     command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "����" ) ob->set("title", "����ɽ������ʿ");
        else ob->set("title", "����ɽ����Ůʷ");

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


