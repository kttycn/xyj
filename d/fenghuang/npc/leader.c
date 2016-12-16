
#include <ansi.h>
#include <login.h>

inherit NPC;
        
void create()
{
        set_name("冰雪一族族长", ({ "ice leader", "lea","l","ice","i"}) );
        set("chat_chance", 15);
        set("chat_msg", ({
            "族长说道:陌生人啊...!!我已经等你很久了....\n",
            "族长说道:因为大地的异变,使得我族的族人相继死去,现在只剩下我一人了....\n",
            "族长说道:去吧!!陌生人!!去改变这世界吧!!\n",
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
   write(HIB"\n冰雪一族族长大喝:藉着创造女神的力量,出来吧!!"NOR+HIY"冰冻剑!!\n"NOR);
   message_vision("$N觉得$N身上的力量减弱了....\n",ob);
   command("give all to "+ob->query("id"));
   write(">");
   ob->set("combat_exp",20);
   event=ob->query("event");
   event[2..2]="3";             
   ob->set("event",event) ;      
}

