inherit __DIR__"fei.c";


void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("�Ϻ�����ɽ", 3, "����"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("staff", j+random(15));
        me->set_skill("lunhui-zhang", j+random(15));
        me->set_skill("hammer", j+random(15));
        me->set_skill("bighammer", j+random(15));
        me->set_skill("lotusmove", j+random(15));
        me->set_skill("buddhism", j+random(15));
        me->set_skill("jienan-zhi", j+random(15));
        me->set_skill("lotusforce", j+random(15));

        me->map_skill("force", "lotusforce");
        me->map_skill("staff", "lunhui-zhang");
        me->map_skill("parry", "lunhui-zhang");
        me->map_skill("spells", "buddhism");
        me->map_skill("dodge", "lotusmove");
        me->map_skill("unarmed", "jienan-zhi");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"staff", "pudu" :),
        (: perform_action,"staff", "forudiyu" :),
        (: perform_action,"staff", "poche" :),
        (: perform_action,"staff", "fuhu" :),
        (: perform_action,"staff", "shenlong" :),
        (: perform_action,"hammer", "dashi" :),
        (: perform_action,"unarmed", " storm" :),
        (: perform_action,"staff", "shenlong" :), 
        (: cast_spell, "bighammer" :),
        (: cast_spell, "lianhua" :),
        }) );

        weapon=new("/d/obj/weapon/staff/budd_staff");
        weapon->move(me);
        
        command("wield all");
}

