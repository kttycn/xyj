inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
 set_name("��ʬ", ({ "jiang shi", "shi" }) );
 set("gender", "����");
 set("age", 1500);
 set("long",
"���ǹ�ս���Ľ�ʬ ��\n");
 set("str", 48);
 set("cor", 52);
 set("cps", 22);
 set("max_kee", 15000);
 set("max_gin", 15000);
 set("max_sen", 15000);
 set("force",9000);
 set("max_force",4500);
 set("mana",9000);
 set("max_mana",4500);
 set("force_factor",150);
 set_skill("parry",300);
 set_skill("dodge",300);
        set_skill("lingfu-steps",300);
 set_skill("unarmed",300);
 set_skill("yinfeng-zhua",300);
 map_skill("unarmed","yinfeng-zhua");
 map_skill("parry","yinfeng-zhua");
        map_skill("dodge","lingfu-steps");
 set("attitude", "aggressive");
 set("combat_exp", 4000000+random(2000000));
 setup();
 if(random(3)==1)
  carry_object("/d/guzhanchang/obj/yundan");
}