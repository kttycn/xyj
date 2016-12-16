
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB"ħ��"NOR, ({ "tian wang", "duowen tianwang", "hai", "tianwang" }) );
        set("gender", "����" );
        set("long",HIC
                "ħ���Ľ�֮һ��ʹһ��������������һ�����ã����������ң�Ҳ��\n"
                "�ء�ˮ���𡢷磬������������������������ƽ�һ�㡣\n"NOR);

        set("age",50);
	 set("nickname", HIW"��������"NOR);
	 set("title", HIG"�Ĵ�����"NOR);
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
        set("max_kee",3100);
        set("kee",3100);
        set("max_sen",3100);
        set("sen",3100);
        set("combat_exp",4000000);
        set("daoxing",3500000);
        set("force",5000);
        set("max_force",3000);
        set("mana",5000);
        set("max_mana",3000);
        set("force_factor", 120);
        set("mana_factor",120);

        set("eff_dx", 4500000);
        set("nkgain", 1500);
        
        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("stick",180);
        set_skill("kusang-bang",180);
        set_skill("force",180);
        set_skill("spells", 180);
        set_skill("moshenbu", 180);
        map_skill("dodge", "moshenbu");
        map_skill("parry", "bawang-qiang");
        map_skill("spear","bawang-qiang");
        map_skill("unarmed", "yingzhaogong");
        set("inquiry", ([
                "name" : "���¶�������ħ�񺣣���ʥ�Ͱ��������š�",

                "here" : "�������������, ���ھ�������ˡ�",
        ]) );

        setup();
        carry_object("/d/dntg/laojunlu/obj/dragonstick")->wield();
        carry_object("/d/dntg/laojunlu/obj/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("pipa",5+random(5),me,ob);  
  ::kill_ob(ob);
}


void pipa (object me, object ob)
{
  object huobing;
  int damage;


  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  message_vision ("$N"HIY"�ͳ��������ã�����ս������Ȼ�Եõĵ���������������\n"NOR,me);

  if ( (ob->query("mana")+random(1000)) > 3500 )
     message_vision (HIW"$N"HIC"������ţ���Ϊ������\n"NOR,ob);
  else 
    {
     message_vision (HIW"$N"HIY"��������ħһ�����ٸ�ͷ�����ǣ�\n"NOR,ob);
     damage=(me->query("mana"))/5; 
     if ( ob->query("sen") < damage ) ob->unconcious();
     else ob->add("sen",-damage);
    } 


  remove_call_out ("pipa");  
  call_out ("pipa",random(15)+15,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision ("$N"HIY"�ŵ����Ⱦ���......\n"NOR,me);
  destruct (this_object());
  return ;
}