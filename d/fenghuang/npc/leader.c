
#include <ansi.h>
#include <login.h>

inherit NPC;
        
void create()
{
        set_name("��ѩһ���峤", ({ "ice leader", "lea","l","ice","i"}) );
        set("chat_chance", 15);
        set("chat_msg", ({
            "�峤˵��:İ���˰�...!!���Ѿ�����ܾ���....\n",
            "�峤˵��:��Ϊ��ص����,ʹ����������������ȥ,����ֻʣ����һ����....\n",
            "�峤˵��:ȥ��!!İ����!!ȥ�ı��������!!\n",
           }));
       
        set("age",60);
        set_temp("apply/damage", 5);
        set_temp("apply/armor", 5);
        set("combat_exp", 30);
        setup();
        carry_object("/u/zhangm/fenghuang/obj/ice_sword");
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage",0,previous_object());
}


void death_stage(object ob)
{
   string event;
   write(HIB"\n��ѩһ���峤���:���Ŵ���Ů�������,������!!"NOR+HIY"������!!\n"NOR);
   message_vision("$N����$N���ϵ�����������....\n",ob);
   command("give all to "+ob->query("id"));
   write(">");
   ob->set("combat_exp",20);
   event=ob->query("event");
   event[2..2]="3";             
   ob->set("event",event) ;      
}

