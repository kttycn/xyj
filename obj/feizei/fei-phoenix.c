//stone created 20020312
inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("�����", 3, "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(15));
        me->set_skill("jile-dao", j+random(15));
        me->set_skill("liedi-stick",j+random(15));
        me->set_skill("stick",j+random(15));
        me->set_skill("fenghuang-shenfa", j+random(15));
        me->set_skill("tenglong-finger", j+random(15));
        me->set_skill("wuzu-xinfa", j+random(15));
        me->set_skill("yufeng-shu", j+random(15));

        me->map_skill("force", "wuzu-xinfa");
        me->map_skill("blade", "jile-dao");
        me->map_skill("stick","liedi-stick");
        me->map_skill("parry", "jile-dao");
        me->map_skill("spells", "yufeng-shu");
        me->map_skill("dodge", "fenghuang-shenfa");
        me->map_skill("unarmed", "tenglong-finger");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "guangqiu" :),
        (: perform_action,"unarmed", "fengdao" :),
        (: exert_function, "powerup" :),
        (: exert_function, "tongtie" :),
        
        }) );

        weapon=new("/d/obj/weapon/blade/blade.c");
        weapon->move(me);
        
        command("wield all");
}

