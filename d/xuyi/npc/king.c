// �����硤���μ�֮�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit NPC;
#include <ansi.h>       
string ask_title();
string ask_need();

string *titles6 = ({
  "������",
  "������",
  "������",
  "������",
});
string *titles5 = ({
  "����Ԫ˧",
  "��ħԪ˧",
  "����Ԫ˧",
  "����Ԫ˧",
  "��ԶԪ˧",
  "���Ԫ˧", 
  "����Ԫ˧",
  "��²Ԫ˧",
});
string *titles4 = ({
  "��������",
  "��������",
  "��������",
  "ƽ������",
  "���Ͻ���",
  "���佫��",
  "��������",
  "���佫��",
  "��������",
});
string *titles3 = ({
  "ǰ����",
  "�󽫾�",
  "������",
  "�󽫾�",
  "�ҽ���",
  "�Ͻ���",
  "��",
  "����",
});
string *titles2 = ({
  "�����",
  "�����",
  "��Զ��",
  "ƽ�ܴ�",
  "������",
  "�����",
  "������",
  "������",  
});
string *titles1 = ({
  "ƫ��",
  "�Խ�",
  "�ν�",
  "����",
  "����",
});
void create()
{
  set_name("����", ({"guo wang", "king" }));
  set("title","ϙ��");
  set("gender", "����");
  set("rank_info/respect", "����");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 50);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 220000);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 50);
  set_skill("force", 50);
  set_skill("fumozhou", 50);
  set_skill("guiyuanforce", 50);
  set_skill("tianwei-shi", 50);
  set_skill("lianhuan-tui", 50);
  map_skill("unarmed", "lianhuan-tui");
  map_skill("dodge", "tianwei-shi");
  map_skill("force", "guiyuanforce");
  map_skill("spells", "fumozhou");
  set("eff_dx",15000);
  set("nkgain",110);
  set("inquiry", ([
     "����" : (: ask_title :),
     "����" : (: ask_need :),           
   ]) );

  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

string ask_title()
{
        object me;
        int num;
        
        me = this_player();
        num = (int)me->query("job/xuyi_kill");
        
        if(me->query("family/family_name")!="����ɽ") return "��λ"+RANK_D->query_respect(me)+"�ǲ��Ǹ���ˣ�";

        if(!me->query_temp("xuyi/kill_monster")) return "������ǲ�����������ʲô��";
        
        if(!me->query("job/xuyi_kill")) return "�����ս�����������ͣ�";
                
        if(num >= 1000){
        me->set_temp("xuyi/title", 6);
        command_function("say ��λ"+RANK_D->query_respect(me)+"���������������ͣ�С������Ϊ����Ը���㹲��˹�������Ϊ����");
        }
        else if(num >= 600){
        me->set_temp("xuyi/title", 5);
        command_function("say ��λ"+RANK_D->query_respect(me)+"ս���պգ�����Զ�����ǹ�֮������");
        }
        else if(num >= 300){
        me->set_temp("xuyi/title", 4);
        command_function("say ��λ"+RANK_D->query_respect(me)+"���������������Ժգ�С���ؼ����ã�");
        }
        else if(num >= 200){
        me->set_temp("xuyi/title", 3);
        command_function("say ��λ"+RANK_D->query_respect(me)+"���ҽ��������ҳ���С�����з��ͣ�");  
        }
        else if(num >= 100){
        me->set_temp("xuyi/title", 2);
        command_function("say ��λ"+RANK_D->query_respect(me)+"������ս���ݱ�Ƶ����С�����д�л��");
        }
        else if(num >= 50){
        me->set_temp("xuyi/title", 1);
        command_function("say ��λ"+RANK_D->query_respect(me)+"Э���Ҿ�������ħ�����û��ְ��");    
        }
        else return "��Ĺ���̫�ͣ������ܻ�þ�λ��";
        
        return "����(kneel)��ּ��";
}

string ask_need()
{
        object me = this_player();
        int times;

        times = (int)me->query("job/xuyi_kill");

        if(me->query("family/family_name")!="����ɽ") return RANK_D->query_respect(me)+"���Ҽҳ����з�����С���θɣ�";
        if(times == 0) return "�㻹û�������أ�";

        command_function("say ���Ѿ�������"+chinese_number(times)+"�������͡�");

        if(times < 50 ) return "����"+chinese_number(50-times)+"�����;Ϳ��Ի�ù�λ����";
        if(times < 100 ) return "����"+chinese_number(100-times)+"�����;Ϳ��Խ����ˡ�";        
        if(times < 200 ) return "����"+chinese_number(200-times)+"�����;Ϳ��Խ����ˡ�";        
        if(times < 300 ) return "����"+chinese_number(300-times)+"�����;Ϳ��Խ����ˡ�";        
        if(times < 600 ) return "����"+chinese_number(600-times)+"�����;Ϳ��Խ����ˡ�";
        if(times < 1000 ) return "����"+chinese_number(1000-times)+"�����;Ϳ��Խ����ˡ�";

        else return "���Ѿ��پӼ�Ʒ�ˣ�";
}
                
void init()
{
    add_action("do_kneel","kneel");
    add_action("do_kneel","guixia");
}

int do_kneel(string arg)
{
        object me;      
        string title;
        
        me = this_player();
        
//    if (base_name(environment(me))!="/d/xuyi/qiandian") return notify_fail("���ﲻ�ǽ��ǵ��ô�ܽ�ּ��\n");
        
        if(!me->query_temp("xuyi/title")) return notify_fail("��Ҫ�о���������\n");
        
        if( me->query_temp("xuyi/title") == 1) title = titles1[random(sizeof(titles1))];
        else if( me->query_temp("xuyi/title") == 2) title = titles2[random(sizeof(titles2))];
        else if( me->query_temp("xuyi/title") == 3) title = titles3[random(sizeof(titles3))];   
        else if( me->query_temp("xuyi/title") == 4) title = titles4[random(sizeof(titles4))];
        else if( me->query_temp("xuyi/title") == 5) title = titles5[random(sizeof(titles5))];
        else if( me->query_temp("xuyi/title") == 6) title = titles6[random(sizeof(titles6))];
        else title = me->query("title");

        message_vision("$N������ڽ��ǵ��£�����ʥּ��\n",me);  
        message_vision("һ��̫��ӹ�ʥ���ϵ����飬����������\n��������ˣ�������Ի��\n\t����"+me->name()+"Ϊ�����ң�������ħ���޷���Ϊ"+HIR+title+NOR+"��\n\t\t\t�մˡ���\n",me);
        message_vision("̫��������飬�����齻��$N��$N���������ؽӹ�ʥּ���������꣬Ȼ���վ��������\n",me);
        
        me->set("title", "����ɽϙ��"+title);
        me->delete_temp("xuyi/title");
        me->delete_temp("xuyi/kill_monster");   
        return 1;
}                                       

