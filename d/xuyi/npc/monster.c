// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created by night 7/26/2000

inherit NPC;

string *names1 = ({
  "����",
  "ˮ��",
  "����",
  "����",
  "����",
  "����",
  "����",
  "����",
});

string *names2 = ({
  "Ұ��",
  "����",
  "��צ",
  "�̾�",
  "��ë",
  "Գ��",
  "����",
  "��ʨ",
});

string *names = ({
  "��",
  "��",
  "��",
});

void create()
{
        if(random(4)<2)
        {
        set_name(names1[random(sizeof(names1))]+names[random(sizeof(names))], ({ "monster" }));
        set("title", "����");
        }
        else
        {
        set_name(names2[random(sizeof(names2))]+names[random(sizeof(names))], ({ "monster" }));
        set("title", "ɽ��");
        }        
        set("long",
                "����һֻ"+this_object()->name()+"������������Ϊ���ķ���\n");
        set("gender",(random(2)?"����":"Ů��"));
        set("age", 30);
        set("attitude", "aggressive");

        set("str", 30);
        set("int", 30);
        set("con", 35);
        set("spi", 30);
        set("cps", 100);
        set("combat_exp", 50000+random(600000));
        set("kee", 1000+random(1000));
        set("sen", 1200+random(1800));
        set("max_kee", 1000+random(1000));
        set("max_sen", 1200+random(1800));
        set("force", 600+random(1000));
        set("max_force", 600+random(1000));
        set("mana", 800+random(1000));
        set("max_mana", 800+random(1000));
        set("force_factor", 10+random(20));
        set("mana_factor", 80+random(100));
        
        set_skill("force", 30+random(60));
        set_skill("dodge", 30+random(60));
        set_skill("unarmed", 30+random(60));
        set_skill("parry", 30+random(60));
        set_skill("fork", 30+random(60));
        set_skill("yueya-chan", 30+random(60));
        set_skill("moshenbu", 30+random(60));
        set_skill("moyun-shou", 30+random(60));                        
    map_skill("unarmed", "moyun-shou");
    map_skill("dodge", "moshenbu");
    map_skill("fork","yueya-chan");
    map_skill("parry", "yueya-chan");
        set("chat_chance", 25);
        set("chat_msg", ({
            (: random_move :),
            (: random_move :),
        }) );

        setup();
    carry_object("/d/obj/weapon/fork/gangcha")->wield();
    carry_object("/d/obj/armor/gujia")->wear();        

}

void init()
{
        object ob;

        remove_call_out("destme");
        call_out("destme", 10+random(50));
        
        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object *guard,me;
        int i;
        me=this_object();
        guard = all_inventory(environment(me));
        for(i=0; i<sizeof(guard); i++)
        {
                if( !living(guard[i]) || guard[i]==me ) continue;
                if(guard[i]->query("id")=="monster") continue;
                me->kill_ob(guard[i]);
                guard[i]->kill_ob(me);
        }
}

void die ()
{
  object me = this_object();
  object ob;
   if(me->query_temp("is_dead")) return;

   if( !ob = query_temp("last_damage_from") )
                ob= this_player();
        if(!userp(ob)){
                ::die();                
                return;
        }
     if(!ob->query_temp("xuyi/monster")){
             ::die();
             return;
                }
        
                
  ob->add_temp("xuyi/kill_monster",1);
  message_vision ("\n$N�Һ�һ�������ڵ�������ԭ�Ρ�\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
   me->set_temp("is_dead",1);
  call_out ("destruct_me",3,me);
} 

void destruct_me (object me)
{
  destruct (me);
}

void destme()
{
     object ob = this_object(); 

     remove_call_out("destme");

  message_vision("$N��Ц��һ��������һ������Ϊһ�����̷�ɢ�ˡ�\n",ob);
     destruct(ob);
     return;
}

