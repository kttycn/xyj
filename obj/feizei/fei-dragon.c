inherit __DIR__"fei.c";

void set_skills()
{
        object me=this_object();
        object weapon;
        int j;
        j=200+random(150);
        create_family("��������", 3, "ˮ��");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("fork", j+random(15));
        me->set_skill("dragon-cha", j+random(15));
        me->set_skill("hammer",j+random(15));
        me->set_skill("huntian-hammer",j+random(15));
        me->set_skill("dragon-steps", j+random(15));
        me->set_skill("dragonfight", j+random(15));
        me->set_skill("dragonforce", j+random(15));
        me->set_skill("seashentong", j+random(15));

        me->map_skill("force", "dragonforce");
        me->map_skill("fork", "dragon-cha");
        me->map_skill("hammer","huntian-hammer");
        me->map_skill("parry", "huntian-hammer");
        me->map_skill("spells", "seashentong");
        me->map_skill("dodge", "dragon-steps");
        me->map_skill("unarmed", "dragonfight");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "sheshen" :),
        (: perform_action,"unarmed", "leidong" :),
        (: perform_action,"hammer", "dragon" :),
        (: perform_action,"hammer", "break" :),
        (: perform_action,"fork", "xizhu" :),
        (: cast_spell, "freez" :),
        (: cast_spell, "water" :),
        (: cast_spell, "hufa" :),
        (: cast_spell, "dragonfire" :),
//        (: exert_function, "roar" :),
        (: exert_function, "shield" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/hammer/jingua");
        else
           weapon=new("/d/obj/weapon/fork/gangcha");
        weapon->move(me);
        command("wield all");
}

