//stone created 20020312
inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("��ʥ��", 3, "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("sword", j+random(15));
        me->set_skill("wuying-sword", j+random(15));
        me->set_skill("mizong-steps", j+random(15));
        me->set_skill("fumobashi", j+random(15));
        me->set_skill("xiantian-force", j+random(15));
        me->set_skill("feisheng-spells", j+random(15));

        me->map_skill("force", "xiantian-force");
        me->map_skill("axe", "sanban-axe");
        me->map_skill("sword","wuying-sword");
        me->map_skill("parry", "wuying-sword");
        me->map_skill("spells", "feisheng-spells");
        me->map_skill("dodge", "mizong-steps");
        me->map_skill("unarmed", "fumobashi");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "wanfo" :),
        (: perform_action,"sword", "fenge" :),
        (: perform_action,"unarmed", "juechen" :),
        (: exert_function, "huti" :),
        (: exert_function, "qiankun" :),
        (: cast_spell, "feixian" :),
	(: cast_spell, "hufa" :),
	(: cast_spell, "wanying" :),
//        (: cast_spell, "escape" :),
        
        }) );

        weapon=new("/d/obj/weapon/sword/sword");
        weapon->move(me);
        
        command("wield all");
}

