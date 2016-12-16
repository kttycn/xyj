#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
void create()
{
        set_name( "波比" ,({ "bo bi", "bo" }));
        set("nickname", HIW "库管" NOR);
        set("gender", "男性");
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
                command("say " + RANK_D->query_respect(who) + "我很累，你回头再来领赏吧。");
                return 0;
        }
        if (strsrch(ob->query("name"), "泰古神剑") < 0 &&
            strsrch(ob->query("name"), "超短裙") < 0 &&
            strsrch(ob->query("name"), "兽甲") < 0 &&
            strsrch(ob->query("name"), "兽皮靴") < 0 &&
            strsrch(ob->query("name"), "兽皮背心") < 0 &&
            strsrch(ob->query("name"), "药") < 0 &&
            strsrch(ob->query("name"), "激光匕首") < 0 &&
            strsrch(ob->query("name"), "钢棍") < 0 &&
            strsrch(ob->query("name"), "天驱") < 0 &&
            strsrch(ob->query("name"), "琼花皎月裳") < 0 &&
            strsrch(ob->query("name"), "手部装甲") < 0 &&
            strsrch(ob->query("name"), "合金手套") < 0 &&
            strsrch(ob->query("name"), "彩裙") < 0 &&
            strsrch(ob->query("name"), "乾坤宝剑") < 0 &&
            strsrch(ob->query("name"), "西装") < 0 &&
            strsrch(ob->query("name"), "激光枪") < 0 &&
            strsrch(ob->query("name"), "高分子盔甲") < 0 &&
            strsrch(ob->query("name"), "碳素汽水瓶") < 0 &&
            strsrch(ob->query("name"), "反光甲") < 0 &&
            strsrch(ob->query("name"), "长剑") < 0 &&
            strsrch(ob->query("name"), "小光剑") < 0 &&
            strsrch(ob->query("name"), "交通警察制服") < 0) 
        {
                command("say 给我这些东西有什么用？\n");
                return 0;
        }
        else
        {
                command("say 不错不错，我一直想要这些东西，谢你代劳了。");
        } 
        pot=20+random(30);
        exp=20+random(100);
me->add("combat_exp",exp);
me->add("potential",pot);
        tell_object(who,HIW"波比奖励了你\n"NOR);
     } 
