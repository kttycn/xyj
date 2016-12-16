
#include <ansi.h>
inherit NPC;
 
void create()
{
        set_name(HIY"ħ����"NOR, ({ "tian wang", "chiguo tianwang", "shou", "tianwang", "wang" }) );
        set("gender", "����" );
        set("long",HIC"
�Ĵ�����֮һ�����ű����󹬰�ȫ���ص�����ͬС�ɡ���
���书�ƺ�������һ�ɣ������������������ɱ�־��У���
û����֪����ʲô��Ҳ������Ϊ��ˣ���ʲŷ�����������
���Ρ�\n"NOR);
        set("class", "xian");
	 set("nickname", HIW"�ֹ�����"NOR);
	 set("title", HIG"�Ĵ�����"NOR);
        set("age",43);
        set("str",30);
        set("int",37);
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

        set_skill("unarmed",140);
        set_skill("changquan", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("mace",180);
        set_skill("spells", 180);
        set_skill("wusi-mace",180);
        set_skill("force",180);
        set_skill("moshenbu", 180);

        map_skill("dodge", "moshenbu");
        map_skill("mace","wusi-mace");
        map_skill("parry","lunhui-zhang");
        map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "���¾��ǳֹ���������ʥ�Ͱ��ر����š�",
                "here" : "������Ǳ����ţ������Ǻ󹬽��ء�",
        ]) );
        setup();
        carry_object("/d/dntg/laojunlu/obj/goldjian")->wield();
        carry_object("/d/dntg/laojunlu/obj/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("huahudiao",5+random(5),me,ob);  
  ::kill_ob(ob);
}




void huahudiao (object me, object ob)
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

  message_vision ("$N"HIC"������ȡ��"HIR"��"HIB"��"HIM"�� "HIC"���ڿ��У�����һֻ"HIW"����"
       HIR+"����Ѫ�裬������������$nҧ����\n"NOR,me,ob);

  if ( (ob->query("force")+random(1000)) > 4000 )


     message_vision (HIY"$N���һ�����󵨣�\n"
       +HIR"��"HIB"��"HIM"��"HIY" �ŵ���æ���$n"HIY"�����С�\n"NOR,ob,me);
  else 
    {
     message_vision (HIR"���$N��ҧ��һ��Ѫ��ģ���Ŀ��ӣ�\n"NOR,ob,me);
     damage=(me->query("force"))/5; 
     if ( ob->query("kee") < damage ) ob->unconcious();
     else ob->add("kee",-damage);
    } 

  remove_call_out ("huahudiao");  
  call_out ("huahudiao",random(15)+15,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision ("$N"HIY"�ŵ����Ⱦ���......\n"NOR,me);
  destruct (this_object());
  return ;
}