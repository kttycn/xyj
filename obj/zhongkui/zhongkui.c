// zhongkui.c
// by fjz

#include <ansi.h>

inherit NPC;

int give_quest();

void create()
{
        set_name("钟馗", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"鬼见愁"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 40);
        set("long", "无人不知的抓鬼大仙。\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
        set("inquiry", ([
                "抓鬼"        :        (: give_quest :),
                "ghost"       :        (: give_quest :),
        ]));        
        setup();
        carry_object("/d/lingtai/obj/xiangpao")->wear();
	carry_object("/d/obj/weapon/sword/taomujian")->wield();

}


int give_quest()
{
        object who, seal;
        mapping room;
        
        who=this_player();
        if( who->is_busy() )
             return notify_fail(" 你正忙着呢，哪有空，过会再去要吧！\n");

        if((time()-who->query("catch_ghost/last_time"))<45)
        {
                command("say 现在还算比较太平，你先去歇着吧。");
                return 1;
        }
        seal=new("/obj/zhongkui/seal");
        seal->set("master", who);
        do {room=LOCATION_D->random_location(); } while(!strlen(room["long"]));
        seal->set("file_name", room["file"]);
        seal->set("desc", room["long"]);
        seal->move(who);
        who->set("catch_ghost/last_time", time());
        command("nod");
        message_vision("$N对$n说道：这张灵符给你，你看看符上写的符咒去抓鬼吧。\n", 
        this_object(), who);
//        who->start_busy(5)
        return 1;
}

int accept_object(object who, object ob)
{
        int reward, times;
        string msg;

        if(!ob->query("finished")||
                this_player()!=ob->query("master"))
                return 0;
        command("nod");
        message_vision("$N对$n说道：很好，很好！\n辛苦你了！\n", this_object(), who);
        times=who->query_temp("catch_ghost");
        reward=8000+random(200)*times+200*times;
        msg=HIG"被奖励了"NOR;
        switch(random(3))
        {
                case 0:
                        this_player()->add("combat_exp", reward/4);
                        this_player()->add("catch_ghost/cache/wuxue", reward/4);
                        msg+=HIY+chinese_number(reward/4)+HIG"点武学"HIG"。\n"NOR;
                        break;
                case 1:
                        this_player()->add("daoxing", reward/4);
                        this_player()->add("catch_ghost/cache/dx", reward/4);
                        msg+=HIY+COMBAT_D->chinese_daoxing(reward/2)+HIG"道行"HIG"。\n"NOR;
                        break;
                default:
                        this_player()->add("office_number", reward/1600);
                        this_player()->add("catch_ghost/cache/off", reward/1600);
                        msg+=HIY+chinese_number(reward/1600)+HIG"点官职"HIG"。\n"NOR;
        }
        this_player()->add_temp("catch_ghost", 1);
        if(who->query_temp("catch_ghost")>9)
                who->set_temp("catch_ghost", 0);
                message("channel:chat",    HIG"〖"HIY"钟馗抓鬼"HIG"〗：据说 "HIW+this_player()->query("name")+HIG" ["HIR"抓鬼"HIG"]"HIG+msg+HIG""NOR,users());
       tell_object(this_player(), HIG"你"NOR+msg);
        return 1;
}

