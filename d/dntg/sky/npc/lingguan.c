#include <ansi.h>
inherit NPC;
void create()
{
  set_name("���",({"ling guan","ling","guan"}));
  set("gender", "����");
  set("age", 45);
  set("long", HIC"    \n��ʥ���������,�����ޱȡ�\n"NOR);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 800000);
  set("daoxing", 2000000);
  set("kee", 2500);
  set("max_kee", 2500);
  set("sen", 2500);
  set("max_sen", 2500);
  set("force", 3500);
  set("max_force", 3500);
  set("mana", 5000);
  set("max_mana", 3500);
  set("force_factor", 100);
  set("mana_factor", 100);


        set_skill("unarmed", 150);
        set_skill("wuxing-quan", 150);

        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("spear", 150);
        set_skill("spells", 150);
        set_skill("taiyi", 150);
        set_skill("baguazhen", 150);
        set_skill("force", 150);   
        set_skill("zhenyuan-force", 150);
        map_skill("force", "zhenyuan-force");
        map_skill("dodge", "baguazhen");
        map_skill("unarmed", "wuxing-quan");
        map_skill("spells", "taiyi");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
          (: cast_spell, "zhenhuo" :),
           }) );


setup();

carry_object("/d/obj/cloth/jinpao")->wear();

}
