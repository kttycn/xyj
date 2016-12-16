inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
string join_me(object me);

void create()
{
        set_name(HIW "��ɱ"NOR, ({ "tian sha" }) );
        set("title",HIC "�����ɱ��¥¥��");
        set("long",
                "�����ɱ��¥¥��������������ɱ�ַ�������\n");

        set("gender", "����" );
        set("age", 28);

        set("str", 30);
        set("int", 23);
        set("dex", 30);
        set("con", 30);

        set("combat_exp", 200000000);
        set("attitude", "heroism");

        set("neili", 1000);
        set("max_neili", 1000);
        set("max_qi", 10000);
        set("jiali", 10);

        set("food", 3000);
        set("water", 3000);

        set("inquiry", ([
                "join": (: join_me :),
                "ɱ��¥": "�����˵, С������������! \n",
        ]) );

        set_skill("sword", 220);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);

        setup();
        carry_object("/d/fenghuang/fenghuang/obj/sword")->wield();
        carry_object("/d/fenghuang/fenghuang/obj/junfu")->wear();
}

int accept_fight(object me)
{
        command("say С�ӣ������ɱ��¥, ��Ҫ���ˣ�");
        return 0;
}

void init()
{
        add_action("give_quest", "quest");
}

string join_me(object me)
{
        if((me->query("quest")))
                return  "��λ" + RANK_D->query_respect(me) + ", ���Ѿ���ɱ��¥�ĵ����ˡ�";
        else
                return "Ŷ...����ɱ��¥���з��յ�Ӵ...";
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep, factor, num;
        string tag = "1000000";
        string *levels = ({
                "1000000"
        });
        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

        if(combatexp < 1000)
        {
                message_vision("��ɱ��$N����һ����: ����С��ɫ����ɱ��¥, ��Ҳ�����˼����....\n", me);
                return 1;
        }
 
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() )
                        return 0;
                else
                {
                        message_vision("��ɱ��$N����һ����: �����ɱ�Ŷ���, ���ٸ���һ�λ������ԡ�\n", me);
                        me->set("qi", (int)(me->query("qi")/2+10));
                }
        }

        for(j = sizeof(levels) - 1 ; j >= 0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                {
                        num = j;
                        factor = 10;
                        break;
                }
        }
        if(num > 0)
        {
                if (random(50) > 45)
                {
                        num = num - 1;
                }
        }
        else
        {
                if ((num < sizeof(levels) - 1) && (random(100) > 95))
                {
                        num = num + 1;
                        factor = 15;
                }
        }
        tag = levels[num];
        quest = QUESTH_D(tag)->query_quest();
        timep = quest["time"];

        time_period(timep, me);
        tell_object(me, "ɱ�ˡ�" + quest["quest"] + "��Ϊɱ��¥������\n" NOR);
        quest["exp_bonus"] = quest["exp_bonus"];
        quest["pot_bonus"] = quest["pot_bonus"];
        quest["score"] = quest["score"];

        me->set("quest", quest);
        me->set("task_time", (int)time() + (int)quest["time"]);
        me->set("quest_factor", factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "��";
        else
                time = "";

        if(h)
                time += chinese_number(h) + "Сʱ";
        if(m)
                time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me, HIW "��ɱ˵����\n��" + time + "��");
                return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                   message_vision("��ɱЦ�������ҿɾͲ������ˡ�\n",who);
                   return 1;
             }
             if ( ob->value() < 5000)
             {
message_vision("��ɱһ˫�������۾�ֱ����$N�����Ǯ�ɲ������ǵĿ�����\n", who);
                   return 1;
             }
             else
             {
message_vision("��ɱЦ�����Ǻã������������������ڡ���Ҫ�ô������Ұɣ�\n",who);
                   who->set("quest",0);
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"��ɱ˵�����ⲻ������Ҫ�ġ�\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"��ɱ˵��������ʲô�������ҽ����������������Ū�ң���\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"��ɱ˵�������Ƿ����û����ָ����ʱ���ڻ�����\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"��ɱ����ص�ͷ˵����������ʹ��û�����\n");
             exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
             pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
             score = quest["score"]/2 + random(quest["score"]/2);
             factor=who->query("quest_factor");
             destruct(ob);

             if (factor)
             {
                  exp=exp*factor/10;
                  pot=pot*factor/10;
                  score=score*factor/10;
             }
             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             if( bonus > 300) bonus = 300;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܣ�"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->set("quest", 0 );
             tell_object(who,HIW"��ϲ�����һ����ʹ��\n"NOR);
             return 0;
        }
        return 1;
}


