// guanshi.c �ϳǳǿ�ջ����
#include <ansi.h>
#include <command.h>
inherit NPC;

string ask_gongzuo();
void create()
{
        set_name("����", ({"guan shi", "guan"}));
        set("gender", "����");
        set("age", 35);
        set("long", 
                "�����ϳǿ�ջ�Ĺ��£���Ȼ��æ����ȴ�ܿ��ġ�\n");
        set("max_kee", 100);
        set("max_sen", 100);
        set("per", 22);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "����" : (: ask_gongzuo :),
                "panzi": (: ask_gongzuo :),
        ]) );

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

string ask_gongzuo()
{
        object me,ob;
        me = this_player(); 

        if( me->query_temp("gongzuo/xipanzi")< 1)
                return "�㻹����ȥ����С������к��ɡ�\n";
        if( me->query_temp("gongzuo/gepanzi")> 0)
                return "�Ҳ��Ǹ��������������ѵ��㶪������";
        ob = new("/d/city/obj/zhangpanzi");
        ob->move(me);
        me->set_temp("gongzuo/gepanzi", 1);
        message_vision("���¸���$Nһ�������ӡ�\n",me);
        return "�ðɣ����ȥ����ϴ�ϸɾ���Щ���Ӱɡ�";

}
