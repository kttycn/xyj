inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
 set_name("����", ({ "gui wang", "gui" }) );
 set("gender", "����");
 set("age", 1500);
 set("long",
"���ǹ�ս�����ϣ�Ҳ�����׺ݵ�һ��������Ϊ���� ��\n");
 set("str", 48);
 set("cor", 52);
 set("cps", 22);
 set("max_kee", 15000);
 set("max_gin", 15000);
 set("max_sen", 15000);
 set("force",4500);
 set("max_force",4500);
 set("mana",4500);
 set("max_mana",4500);
 set("force_factor",100);
 set_skill("parry",300);
 set_skill("dodge",300);
        set_skill("lingfu-steps",300);
 set_skill("unarmed",350);
 set_skill("yinfeng-zhua",300);
 map_skill("unarmed","yinfeng-zhua");
 map_skill("parry","yinfeng-zhua");
        map_skill("dodge","lingfu-steps");
 set("attitude", "aggressive");
 set("combat_exp", 4000000+random(2000000));
 setup();
 carry_object("/obj/money/gold")->set_amount(20);
  carry_object("/d/guzhanchang/obj/piduzhu");
}
void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="piduzhu" || inv[i]->query("id")=="pidu zhu")
                {
                   inv[i]->move(me);
                   message_vision("$N�ſ������³�һ����ɫ�ı��飬$n��æһ��ץ�����\n",this_object(),me);
            message("channel:rumor",RED+"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ��ٶ����ˣ�\n"+NOR,users());
         }
        }
  }
 ::die();
}
