// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("������ʿ", ({ "wei shi", "shi", "guard" }) );
        set("gender", "����");
        set("age", 25);
        set("long",

"����λ�ػ���������ʿ������ͭ�ף���ִ���컭ꪡ�
��˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("combat_exp", 160000);
        set("attitude", "heroism");
        set("str", 25);
        set("max_kee", 750);
        set("max_sen", 600);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 15);
        set_skill("halberd", 60);
        set_skill("unarmed", 60);
        set_skill("tianlong-halberd", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        map_skill("halberd", "tianlong-halberd");
        map_skill("parry", "tianlong-halberd");
   set_skill("force", 50);
        setup();

        carry_object("/d/obj/weapon/halberd/sanchaji")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}


int accept_fight(object me)
{
        message_vision("������ʿ��$N���һ�������ò��ͷ��ˣ�����ǰҲ�Һ��֣�\n", me);
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

