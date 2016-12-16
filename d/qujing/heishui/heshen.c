inherit NPC;
#include <ansi.h>
int ask_guai();

void create()
{
       set_name("��ˮ����", ({"heishui heshen","heshen"})); 
       set("long","���Ǻ�ˮ���񣬵���Ҳ���ڴ�߳����ƣ����ȴ���������\n");
       set("gender", "����");
       set("age", 200);
       set("int", 25);
       set("attitude", "peaceful");
       set("combat_exp", 1000000);
       set("rank_info/respect", "����");
       set("per", 30);
       set("max_kee", 1000);
       set("max_sen", 8000);
       set("force", 1500);
       set("max_force", 1500);
       set("force_factor", 30);
       set("max_mana", 2000);
       set("mana", 2000);
       set("mana_factor", 50); 
        set("chat_msg", ({
                "����̾��:�������뿪����,��Ҫ�浽�����ǰ!\n",
                "�������������!����ռ�Ҹ�ۡ���������ڴˡ�\n",
        }) );
         set("inquiry", ([
     "����": (: ask_guai:),
        ]));
       set_skill("literate", 100);
       set_skill("unarmed", 100);
       set_skill("dodge", 150);
       set_skill("force", 120);
       set_skill("parry", 100);
       set_skill("sword", 150);
       set_skill("spells", 180);
       set_skill("dao", 180);
       set_skill("puti-zhi", 120);
       set_skill("wuxiangforce", 140);
       set_skill("liangyi-sword", 100);
       set_skill("jindouyun", 130);
       map_skill("spells", "dao");
       map_skill("unarmed", "puti-zhi");
       map_skill("force", "wuxiangforce");
       map_skill("sword", "liangyi-sword");
       map_skill("parry", "liangyi-sword");
       map_skill("dodge", "jindouyun");


        setup();

        carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

int ask_guai()
{       object me;        
        me=this_player();

        if(me->query("obstacle/heishui")=="done") {
                command("say �����鷳"+RANK_D->query_respect(me)+ ",�Ҷ�������˼�ˡ�\n");
                command("sigh2");
                return 1;
        }       
        if( me->query_temp("heshen")) {
                command("say "+RANK_D->query_respect(me)+ "��ûȥ������������\n");
                command("sigh2");
                command("say " +RANK_D->query_respect(me)+ "�뾡�춯��С��ֻ��ʱ���޶��ˡ�\n");
                return 1;
        }
        command("sigh");
        call_out("shen",2);
        me->set_temp("heshen",1);
        return 1;
}

void shen()
{
     object me;        
     me=this_player();
        
    command("say С���Ǵ˺Ӻ������ܺ�ˮ����Ҳ�����˳��\n");
   call_out("nie",2);
}
void nie()
{
     object me;        
     me=this_player();
        
        command("say ����������������֮������ǰЩ��˽������ˡ�\n");
   call_out("duo",2);
}

void duo()
{
     object me;        
     me=this_player();
        
   command("say Ȼ����Ҹ�ۡ�������ڴˣ��Ҷ෬��״��ȴ���������������¡�\n");
   call_out("jiu",2);
}
void jiu()
{
     object me;        
     me=this_player();
        
        command("say ����" +RANK_D->query_respect(me)+ "������ԩ��\n");
   call_out("bow",2);
}
void bow()
{
     object me;        
     me=this_player();
        
   command("bow");
}

