//stone created 20020312
inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("����ɽ", 3, "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
         
        me->set_skill("halberd", j+random(15));
        me->set_skill("tianlong-halberd", j+random(15));
        me->set_skill("hammer",j+random(15));
        me->set_skill("pangu-hammer",j+random(15));
        me->set_skill("tianwei-shi", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("qixi-sword",j+random(15));
        me->set_skill("lianhuan-tui", j+random(15));
        me->set_skill("guiyuanforce", j+random(15));
        me->set_skill("fumozhou", j+random(15));

        me->map_skill("force", "guiyuanforce");
        me->map_skill("halberd", "tianlong-halberd");
        me->map_skill("hammer","pangu-hammer");
        me->map_skill("parry", "tianlong-halberd");
        me->map_skill("spells", "fumozhou");
        me->map_skill("dodge", "tianwei-shi");
        me->map_skill("unarmed", "lianhuan-tui");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"halberd", "tiandihunran" :),
        (: perform_action,"sword", "quewu" :),
        (: exert_function, "hanxing" :),
        (: cast_spell, "freeze" :),
	(: cast_spell, "sword" :),
	(: cast_spell, "wanlei" :),
        (: cast_spell, "sixiang" :),
        }) );

        weapon=new("/d/obj/weapon/halberd/halberd");
        weapon->move(me);
        
        command("wield all");
}

