inherit __DIR__"guai.c";

#include <ansi.h>

void create()
{ set("title", HIY "霸王不攻" NOR);
  set("nickname", HIY"梅花六出"NOR);
  create_family("将军府",3,"弟子");
  ::create();
}

void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);

        if (level==1) guai_value = max_value+max_value/8;
        else if (level==2) guai_value = max_value+max_value/6;
        else guai_value = max_value+max_value/4;

        set_skill("changquan", guai_value+random(16));
        set_skill("yanxing-steps", guai_value+random(16));
        set_skill("spear", guai_value+random(16));
        set_skill("bawang-qiang", guai_value+random(16));
        set_skill("lengquan-force", guai_value+random(16));
        set_skill("literate", 180);
        set_skill("baguazhou", guai_value+20+random(16));
        map_skill("spells", "baguazhou");
        map_skill("force", "lengquan-force");
        map_skill("unarmed", "changquan");
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
        (: perform_action,"spear", "daohai" :),
        (: perform_action,"spear", "bugong" :),
        (: perform_action,"spear", "jingyan" :),
        (: perform_action,"spear", "sanban" :),
        (: perform_action,"spear", "meihua" :),
        (: exert_function, "jingxin" :),        
        }) );

        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("d/obj/weapon/spear/tieqiang.c")->wield();
}

void heart_beat() {
   if (is_fighting())
      command("perform bugong");
      command("exert jingxin");
    ::heart_beat();
}
