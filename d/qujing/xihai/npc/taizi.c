//EDIT BY LUCAS
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_chubing();
string expell_me(object me);



void create()
{
       set_name("Ħ��", ({"mo ang","mo","ang"}));

        set("long","������̫�ӣ����������ۡ���Х�ĺ�������������\n");
       set("gender", "����");
       set("age", 20);
       set("int", 25);
       set("title", "����̫��");
       set("attitude", "peaceful");
       set("combat_exp", 3000000);
       set("rank_info/respect", "̫�ӵ���");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 2000);
       set("max_sen", 1000);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor", 50);
       set("max_mana", 2000);
       set("mana", 2000);
       set("mana_factor", 100); 
         set("inquiry", ([
     "����": (: ask_chubing:),
     "����": (: ask_chubing:),
     "����": (: ask_chubing:),
     "����": (: ask_chubing:),
        ]));
       set_skill("literate", 100);
       set_skill("unarmed", 200);
       set_skill("dodge", 150);
       set_skill("force", 120);
       set_skill("parry", 150);
       set_skill("fork", 150);
       set_skill("spells", 180);
       set_skill("seashentong", 140);
       set_skill("dragonfight", 150);
       set_skill("dragonforce", 160);
       set_skill("dragon-cha", 150);
       set_skill("dragon-steps", 130);
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "dragon-cha");
       map_skill("parry", "dragon-cha");
       map_skill("dodge", "dragon-steps");


    create_family("��������", 2, "ˮ��");
        setup();

        carry_object("/d/sea/obj/longpao")->wear();
        carry_object("/d/sea/obj/tuotiancha")->wield();
}

int ask_chubing()
{
   object me, ob;
   me = this_player();
   ob = this_object();

            if(me->query("xinguan/heishui")=="done") { 
            command("say �ѵ����Ǳ��������ʲô���캦�������\n");
    return 1;
   } 

    if( environment(this_object())->query("short") != "���Ӿ�"){ 
    command("say ���ǲ����Ѿ������������콵���ɡ�\n");
    return 1;
   } 
   if(!me->query_temp("����")){
    command("say "+RANK_D->query_respect(me)+"δ�ø���ͬ�⣬С���������Գ�����");
    command("say "+RANK_D->query_respect(me)+"�����������游���ɡ�");
    return 1;
   }

   command("ah");
   command("kick");
   call_out("zuo",2);
   return 1;
}
void zuo()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   command("say ������������񣬵�����Ϊ����Ȼ����������С��Ը������֮��");
   call_out("dun",2);
}
void dun()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   command("say "+RANK_D->query_respect(me)+"����С��һ������ˮ��������");
   call_out("xian",2);
}
void xian()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   message_vision(HIW"$N���һ�����������ӣ��ֳ�����ֻ�����ƶ�䣬���������ԭ���ǰ�צ������\n"NOR,ob);
   call_out("shui",1);
}
void shui()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   message_vision(HIC"$N���һ�ţ�ֻ������֮ˮ��ӿ��������Ȼ������ţ����������ȺϺ��з��ϯ�����ڡ�\n"NOR,ob,me); 
   call_out("wait",2);
}
void wait()
{
   object me, ob;
   me = this_player();
   ob = this_object();

   me->move("/d/qujing/xihai/water");
   ob->move("/d/qujing/xihai/water");
   me->delete_temp("����");
   call_out("swim_in_water",1,me);
}
void swim_in_water(object me)
{
  object ob = this_object();

  string *msgs = ({
    "$Nֻ������ˮĻ��Ө��͸��ˮĻ������ˮ�����и��Ρ�\n",
    "ˮĻ��һ���������ſ�Ѫ���ڣ���$N�ٺټ�Ц�˼�����\n",
    "ˮĻ���������֮�£�����ȴ�������⣬$N������Ľ����������\n",
  });

  message_vision(msgs[random(sizeof(msgs))],me);
  me->add_temp("swiming",1);
  if(me->query_temp("swiming")>5+random(7)){
   me->move("/d/qujing/heishui/xuanya");
   ob->move("/d/qujing/heishui/xuanya");
  message_vision(HIC"$N���һ�����ٱ����߽�������ǰ��������ˮĻ����ɢ����ȴ�Ѿ����˺�ˮ֮����\n"NOR,ob);
  call_out("nofight",2);
    return;
  }
  call_out("swim_in_water",random(9),me);
}  
void nofight()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
   command("say С��������������ף����㶯�䡣");
   call_out("xia",2);
}
void xia()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
  command("say "+RANK_D->query_respect(me)+"����ˮ������С���ڴ��޹�������");
  call_out("shout",1);
}
void shout()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
  command("say С���ǣ���Ϊ"+RANK_D->query_respect(me)+"�޹�������");
  call_out("bing",1);
}
void bing()
{
   object me, ob;
   me = this_player();
   ob = this_object();
        
  message_vision(HIY"һ��Ϻ��з���������"+RANK_D->query_respect(me)+"��ʤ��"+RANK_D->query_respect(me)+"��ʤ��\n"NOR,me);
    me->delete_temp("swiming");
    me->add_temp("fight",1);
}

