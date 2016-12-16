inherit NPC;

void create()
{
       set_name("����С��", ({"songxin xiaoyao", "xiaoyao"}));

        set("long","��ˮ�ӵ�С������Ϊ�ų̿죬���Ա�������ȥ���š�\n");
       set("gender", "����");
       set("age", 20);
        set("per", 10); 
        set("con",30);
        set("str", 25);
        set("combat_exp", 100000);

        set("class", "scholar");
        set("attitude","heroism");
        set("chat_chance",20);
        set("chat_msg", ({
        "С�����ŵؿ��˿����ܣ��ֹ������ص���ͷȥ��\n", 
        "С�����ֽ�������������ɵЦ��������\n",
        }));

        set_skill("parry", 60);  
        set_skill("force", 40); 
        set_skill("spells", 50); 
        set_skill("seashentong", 20); 
        set_skill("dragon-steps", 40); 
        set_skill("fork", 60); 
        set_skill("dragon-cha", 40); 
        set_skill("dragonfight", 40); 
        set_skill("dodge", 60);
        set_skill("unarmed", 40); 

        map_skill("parry", "dragon-cha");
        map_skill("fork", "dragon-cha");
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragon-steps"); 
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20); 
        set("mana", 600);
        set("max_mana", 600);
        set("mana_factor", 30);
        set("max_kee", 600);
        set("max_sen", 500);
        setup();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
        carry_object("/d/qujing/heishui/obj/xiazi");  
}
void kill_ob (object ob)
{
  ::kill_ob(ob);
  call_out ("flee",1,this_object());
}

void flee (object me)
{
   object room = load_object("/obj/empty.c");
 if (random(4) != 1) 
   {
   command("jiuming");
  message_vision ("\nС��ƴ����·��һ����ٿ��һ��ˮ����ʧ�ˡ�\n",me);
  me->move(room);
   }
 else
   {
  message_vision ("\nС���е������ˣ����ˡ��������ŵ��ĵ����ѣ������ڵء�\n",me);
  me->die();
  return ;
   }
}

void die (object me)
{
    ::die();
  message_vision ("\nС���Һ�һ���������ڵ�\n",me);
}


