inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("���ƶ�", 3, "����"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("spear", j+random(15));
        me->set_skill("wuyue-spear", j+random(15));
        me->set_skill("moyun-shou",j+random(15));
        me->set_skill("moshenbu",j+random(15));
        me->set_skill("huomoforce", j+random(15));
        me->set_skill("pingtian-dafa", j+random(15));
        me->set_skill("dali-bang", j+random(15));
        me->set_skill("stick", j+random(15));

        me->map_skill("force", "huomoforce");
        me->map_skill("spear", "wuyue-spear");
        me->map_skill("stick","dali-bang");
        me->map_skill("parry", "dali-bang");
        me->map_skill("spells", "pingtian-dafa");
        me->map_skill("dodge", "moshenbu");
        me->map_skill("unarmed", "moyun-shou");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "juesha" :),
        (: perform_action,"unarmed", "zhangxinlei" :),
        (: perform_action,"stick", "shenli" :),
        (: perform_action,"spear", "fengshan" :),
        (: perform_action,"spear", "buhui" :),
        (: exert_function, "fire" :),
        (: cast_spell, "sanmei" :),
        (: cast_spell, "niushi" :),
        (: cast_spell, "zhuang" :),
        }) );

        weapon=new("/d/obj/weapon/stick/xiangmo");
        weapon->move(me);
        command("wield all");
}

