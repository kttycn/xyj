inherit __DIR__"fei.c";


void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("��ɽ����", 3, "����"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("sword",j); 
        me->set_skill("whip",j); 
        
        me->set_skill("yujianshu", j+random(15));
        me->set_skill("mindsword", j+random(15));        
        me->set_skill("spells",j+random(15));
        me->set_skill("seven-steps",j+random(15));
        me->set_skill("taoism", j+random(15));
        me->set_skill("unarmed", j+random(15));        
//      me->set_skill("fumozhang", j+random(15))
//������ļ�����˭��æcopyһ����BOW! jznt .
        me->set_skill("hunyuan-zhang", j+random(15));
        me->set_skill("yiruwhip", j+random(15));        

        me->map_skill("force", "zixia-shengong");
        me->map_skill("sword", "mindsword");        
        me->map_skill("parry", "mindsword");
        me->map_skill("spells", "taoism");
        me->map_skill("dodge", "seven-steps");
        me->map_skill("unarmed", "hunyuan-zhang");
        me->map_skill("whip", "yiruwhip");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "fenguang" :),
        (: perform_action,"sword", "tianjian" :),
        (: perform_action,"sword", "fumo" :),
        (: perform_action,"sword", "duanshui" :),
        (: perform_action,"sword", "wanjian" :),
        (: perform_action,"sword", "xiangsi" :),
        (: perform_action,"whip", "yue" :),
        (: perform_action,"whip", "snoke" :),
        (: perform_action,"unarmed", "shou" :),
        (: perform_action,"unarmed", "awn" :),
        (: exert_function, "huti" :),
        (: exert_function, "zhanqi" :),
        (: cast_spell, "jianshen" :),
        (: cast_spell, "fu" :),
        (: cast_spell, "jiushen" :),
        (: cast_spell, "chaoyuan" :),
        }) );        
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
     
        command("wield all");
}
