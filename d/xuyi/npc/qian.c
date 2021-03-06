// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */
 
// by night

inherit NPC;
#include <ansi.h>

int work_me();

void create()
{
   set_name("钱神将", ({"qian shenjiang", "qian", "shenjiang"}));
   //set("title", "");
   set("gender", "男性" );
   set("age", 30);
   set("per", 20);
   set("long", "一位沉稳的中年人。\n");
   set("class", "xian");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("盱眙山", 3, "弟子");
   set_skill("unarmed", 50);
   set_skill("dodge", 80); 
   set_skill("tianwei-shi", 80);
   set_skill("parry", 90); 
   set_skill("lianhuan-tui", 50);   
   set_skill("hammer", 70);
   set_skill("pangu-hammer", 80);
   set_skill("force", 80);   
   set_skill("guiyuanforce", 80);   
   set_skill("literate", 70);
   set_skill("spells", 80);
   set_skill("fumozhou", 80);
   map_skill("hammer", "pangu-hammer");
   map_skill("parry", "pangu-hammer");  
   map_skill("dodge", "tianwei-shi");
   map_skill("unarmed", "lianhuan-tui");
   map_skill("force", "guiyuanforce");
   map_skill("spells", "fumozhou");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 1000);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);   
   set("force_factor", 40);
   set("mana_factor", 40);
        set("inquiry", ([
        "kill": (: work_me :),
        "job": (: work_me :),
        "降妖": (: work_me :),
        "除魔": (: work_me :),
        ]));

   setup();
   carry_object("/d/obj/cloth/linen")->wear();
   carry_object("/d/obj/armor/tongjia")->wear();
   carry_object("/d/obj/weapon/hammer/kunwu")->wield();
}

void init()
{
    add_action("do_finish","finish");
    add_action("do_finish","jiaochai");
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="盱眙山" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
        else command("say 师姑见笑了。\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
        else command("say 师妹太客气了。\n");
     }
     else 
     {
        command("consider");
        command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "男性" ) ob->set("title", "盱眙山巡城武士");
        else ob->set("title", "盱眙山巡城女兵");

     }
   }

   else
   {
     command("say 好，那我就勉为其难吧。\n");
     command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "男性" ) ob->set("title", "盱眙山巡城武士");
        else ob->set("title", "盱眙山巡城女兵");

   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "hero");
}

int accept_fight(object me)
{
        command("say 我为王府神将，岂能与你村野匹夫较艺！");
        return 0;
}

int work_me()
{
   object monster, me, guard;
   int i, num;
   string* dirs;   

   dirs=({"/d/xuyi/"});
      
   me = this_player();
   
   if( (string)me->query("family/family_name")!="盱眙山" ) {
     message_vision("$N看了$n两眼，摇头道：多谢"+RANK_D->query_respect(me)+"美意，这是本门弟子的工作。\n", this_object(), me);
     return 1;
     }
     
   if (((int)me->query("combat_exp") < 120000 )) {
     command("say 劝你还是不要去送死了。\n");
     return 1;
     }
     
   if(me->query_temp("xuyi/monster")) {
     command("say 去吧，切记小心在意。");
     return 1;
     }
          
   if(this_object()->query("has_asked")) {
     command("say 今天已经有人去降妖荡魔了，你过阵子再来吧。");
     return 1;
     }
     
   num = random(3)+2;
   for(i=1;i<=num;i++)
    {
        monster = new(__DIR__"monster");
        call_out("random_go",1,monster, dirs);       
    }
    command("say 东门外的密林里有山精海妖出没，你带兵去铲除他们吧。");
    command("say 要小心从事。");
    me->set_temp("xuyi/monster", 1);
    me->set_temp("xuyi/num", num);    
    this_object()->set("has_asked", 1);
    guard = new(__DIR__"weishi1");
    guard->set("guard", me->query("id"));
    guard->move(environment(me));
    call_out("regenerate", 300);
    return 1;
}

void random_go(object monster, string* dirs)
{
        int i,j,k;
        object newob;
        mixed* file;   
        
        if( !sizeof(dirs) )  return;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }
    if( (newob=find_object(dirs[i]+file[j][0])) )   {
                if(!newob->query("dangerous") ){
        call_out("random_go",1,monster, dirs);   
                        return;
                }
                monster->move( newob ); 
message_vision("\n突然一阵阴风涌起，$N从中现出身形！\n", monster);
        }
        else  {
                seteuid(getuid());
                newob = load_object(dirs[i]+file[j][0]);
                if (newob)   // now this is not necessary, only for debug use
                {
                        if( !newob->query("dangerous")){
        call_out("random_go",1,monster, dirs);   
                                return;
                        }
                        monster->move(newob);
message_vision("\n突然一阵阴风涌起，$N从中现出身形！\n", monster);
        }
        else  {
                        tell_object(monster, "Error.\n");
                }
        }

        return;
}

int regenerate()
{
        set("has_asked", 0);
        return 1;
}

int do_finish()
{
        object me, reward, soldier;
        int pot,exp;
        int gold;
        
        me = this_player();
        
        if(!me->query_temp("xuyi/monster")) return notify_fail("你没做差事，不要在这里捣乱。\n");
        
        if((int)me->query_temp("xuyi/num")>1 && (int)me->query_temp("xuyi/kill_monster")<= 1)
        {
        command("sigh");
        command("say 怎么做得这么差劲？");
        command("shrug");
        if (objectp(soldier=present("guard soldier", environment(me)))) destruct(soldier);
        me->delete_temp("xuyi/monster");
        return 1;
        }
        soldier=present("guard soldier", environment(me));
        if(!soldier)
        {
        command("angry " + me->query("id"));
        command("say 你连手下的士兵都无法保护，怎能为官？");
        me->delete_temp("xuyi/monster");
        return 1;
        }        
    exp=(160+(random(5))*40);
    pot=(50+random(50));
    if (pot > 80) pot=80;

    me->add("combat_exp",exp);
    me->add("potential",pot);
    if(me->query("xuyi/kill"))
    {
    me->set("job/xuyi_kill", me->query("xuyi/kill"));
    me->delete("xuyi/kill");
    }
    me->add("job/xuyi_kill", 1);
    
   tell_object(me,HIW"任务完成了，你被奖励了：\n" + 
                COMBAT_D->chinese_daoxing(exp) + "道行、" +
                chinese_number(pot) + "点潜能。\n"+
                NOR);
    
        if((int)me->query("job/xuyi_kill")%60 == 0)
        {
     message_vision("$N对$n笑道：“这位"+RANK_D->query_respect(me)+"立下了汗马功劳，"+RANK_D->query_self(this_object())+"另有酬答。”\n",this_object(),me);
        me->add("jieshu",1);
        tell_object(me,HIG"你获得了"+chinese_number(1)+"点劫数。\n"NOR);
        }
        
        gold = (int)me->query_temp("xuyi/kill_monster");
        gold = random(gold)+random(2);

        if(gold >= 1)
        {
        add_money("gold", gold);

        command("give "+gold+" gold to " + me->query("id"));
        command("say 这是饷银。");
        command("say 你再进宫找皇上要封赏吧。");
        }
        message_vision(CYN"$N对$n笑道：“这位"+RANK_D->query_respect(me)+"辛苦了。”\n"NOR,this_object(),me);
        me->delete_temp("xuyi/monster");
        me->delete_temp("xuyi/num");        
        if (objectp(soldier=present("guard soldier", environment(me)))) destruct(soldier);

        return 1;
}       

