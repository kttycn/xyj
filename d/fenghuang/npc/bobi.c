#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
void create()
{
        set_name( "����" ,({ "bo bi", "bo" }));
        set("nickname", HIW "���" NOR);
        set("gender", "����");
        set("age", 52);
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 28);
        set("con", 30);
        set("dex", 30);
        set("chat_chance", 1);
        set("max_qi",1500);
        set("max_jing",500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("shen_type",1);

        set("combat_exp", 3000000);
        setup();
}

int accept_object(object who, object ob)
{
  object me=this_player();
        int i,exp,pot;
        if (query("sharen") < 0)
        {
                command("say " + RANK_D->query_respect(who) + "�Һ��ۣ����ͷ�������Ͱɡ�");
                return 0;
        }
        if (strsrch(ob->query("name"), "̩����") < 0 &&
            strsrch(ob->query("name"), "����ȹ") < 0 &&
            strsrch(ob->query("name"), "�޼�") < 0 &&
            strsrch(ob->query("name"), "��Ƥѥ") < 0 &&
            strsrch(ob->query("name"), "��Ƥ����") < 0 &&
            strsrch(ob->query("name"), "ҩ") < 0 &&
            strsrch(ob->query("name"), "����ذ��") < 0 &&
            strsrch(ob->query("name"), "�ֹ�") < 0 &&
            strsrch(ob->query("name"), "����") < 0 &&
            strsrch(ob->query("name"), "�������") < 0 &&
            strsrch(ob->query("name"), "�ֲ�װ��") < 0 &&
            strsrch(ob->query("name"), "�Ͻ�����") < 0 &&
            strsrch(ob->query("name"), "��ȹ") < 0 &&
            strsrch(ob->query("name"), "Ǭ������") < 0 &&
            strsrch(ob->query("name"), "��װ") < 0 &&
            strsrch(ob->query("name"), "����ǹ") < 0 &&
            strsrch(ob->query("name"), "�߷��ӿ���") < 0 &&
            strsrch(ob->query("name"), "̼����ˮƿ") < 0 &&
            strsrch(ob->query("name"), "�����") < 0 &&
            strsrch(ob->query("name"), "����") < 0 &&
            strsrch(ob->query("name"), "С�⽣") < 0 &&
            strsrch(ob->query("name"), "��ͨ�����Ʒ�") < 0) 
        {
                command("say ������Щ������ʲô�ã�\n");
                return 0;
        }
        else
        {
                command("say ��������һֱ��Ҫ��Щ������л������ˡ�");
        } 
        pot=20+random(30);
        exp=20+random(100);
me->add("combat_exp",exp);
me->add("potential",pot);
        tell_object(who,HIW"���Ƚ�������\n"NOR);
     } 
