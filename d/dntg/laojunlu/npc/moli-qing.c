
#include <ansi.h>
inherit NPC;

void create()
{
        object ob;

        set_name(HIC"ħ����"NOR, ({ "tian wang", "zengzhang tianwang", "qing", "tianwang" }) );
        set("gender", "����" );
        set("long",HIC
                "��������Ϊ�Ĵ�����֮��, ��߶����ĳ�, ����һ�˳�ǹ, \n"
                "ǹ���Ƿ��켫, �����ܴ������Ʊ�����, ���أ�ˮ���𣬷硹\n"
                "��ʽһ��, ���޽���Ҳ���ӡ�\n"NOR);

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
        set("force",6000);
        set("max_force",3000);
        set("mana",6000);
        set("max_mana",3000);
        set("force_factor", 150);
        set("mana_factor",150);

        set("eff_dx", 4500000);
        set("nkgain", 1500);

        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("sword",180);
        set_skill("ningxue-force",180);
        set_skill("bainiao-jian",180);
        set_skill("force",180);
        set_skill("spells", 180);

        set_skill("moshenbu", 180);
        map_skill("dodge", "moshenbu");
        map_skill("force", "ningxue-force");
        map_skill("parry", "bainiao-jian");
        map_skill("sword","bainiao-jian");
        map_skill("unarmed", "yingzhaogong");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "chaofeng" :),
        }) );

        setup();

        ob=carry_object("/d/dntg/laojunlu/obj/qingfeng");
        ob->wield();
        ob->set_name(HIC"���Ʊ���"NOR, ({ "sword", "bao jian" }) );

        carry_object("/d/dntg/laojunlu/obj/jinjia")->wear();
}





void die ()
{
  object me = this_object();
  message_vision ("$N"HIY"�ŵ����Ⱦ���......\n"NOR,me);
  destruct (this_object());
  return ;
}