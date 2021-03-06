inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
string join_me(object me);

void create()
{
        set_name(HIW "天杀"NOR, ({ "tian sha" }) );
        set("title",HIC "凤凰星杀手楼楼主");
        set("long",
                "凤凰星杀手楼楼主负责向门下众杀手分派任务。\n");

        set("gender", "男性" );
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
                "杀手楼": "你敢乱说, 小心老子宰了你! \n",
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
        command("say 小子！你赶惹杀手楼, 不要命了！");
        return 0;
}

void init()
{
        add_action("give_quest", "quest");
}

string join_me(object me)
{
        if((me->query("quest")))
                return  "这位" + RANK_D->query_respect(me) + ", 你已经是杀手楼的弟兄了。";
        else
                return "哦...加入杀手楼是有风险的哟...";
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
                message_vision("天杀对$N哼了一声道: 这种小角色还进杀手楼, 你也真好意思开口....\n", me);
                return 1;
        }
 
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() )
                        return 0;
                else
                {
                        message_vision("天杀对$N哼了一声道: 真给天杀门丢脸, 就再给你一次机会试试。\n", me);
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
        tell_object(me, "杀了『" + quest["quest"] + "』为杀手楼立功。\n" NOR);
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
                time = chinese_number(d) + "天";
        else
                time = "";

        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "天杀说道：\n在" + time + "内");
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
                   message_vision("天杀笑道：那我可就不客气了。\n",who);
                   return 1;
             }
             if ( ob->value() < 5000)
             {
message_vision("天杀一双尖针般的眼睛直盯着$N：这点钱可不够我们的开销！\n", who);
                   return 1;
             }
             else
             {
message_vision("天杀笑道：那好，咱们买卖不成仁义在。想要好处再找我吧！\n",who);
                   who->set("quest",0);
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"天杀说道：这不是我想要的。\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"天杀说道：这是什么东西？我叫你办的事你就这样糊弄我？！\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"天杀说道：真是废物！你没有在指定的时间内回来！\n");
             destruct(ob);
             return 0;
        }
        else
        {
             tell_object(who,"天杀赞许地点头说道：不错！差使办得还不错！\n");
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
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，"+ chinese_number(pot) + "点潜能，"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("quest", 0 );
             tell_object(who,HIW"恭喜你完成一个差使！\n"NOR);
             return 0;
        }
        return 1;
}


