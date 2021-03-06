// 神话世界·西游记之（世纪）
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit NPC;
#include <ansi.h>       
string ask_title();
string ask_need();

string *titles6 = ({
  "镇南王",
  "征西王",
  "定邦王",
  "安疆王",
});
string *titles5 = ({
  "荡寇元帅",
  "伏魔元帅",
  "护国元帅",
  "卫国元帅",
  "定远元帅",
  "镇军元帅", 
  "辅国元帅",
  "征虏元帅",
});
string *titles4 = ({
  "伏波将军",
  "征东将军",
  "定北将军",
  "平西将军",
  "镇南将军",
  "建武将军",
  "建威将军",
  "振武将军",
  "振威将军",
});
string *titles3 = ({
  "前将军",
  "后将军",
  "卫将军",
  "左将军",
  "右将军",
  "上将军",
  "左辅",
  "右弼",
});
string *titles2 = ({
  "骠骑大将",
  "车骑大将",
  "安远大将",
  "平寇大将",
  "保国大将",
  "安邦大将",
  "威西大将",
  "奋威大将",  
});
string *titles1 = ({
  "偏将",
  "裨将",
  "参将",
  "副将",
  "牙将",
});
void create()
{
  set_name("国王", ({"guo wang", "king" }));
  set("title","蠙城");
  set("gender", "男性");
  set("rank_info/respect", "陛下");
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
     "封赏" : (: ask_title :),
     "功劳" : (: ask_need :),           
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
        
        if(me->query("family/family_name")!="盱眙山") return "这位"+RANK_D->query_respect(me)+"是不是搞错了？";

        if(!me->query_temp("xuyi/kill_monster")) return "你今天是不是忘了做点什么？";
        
        if(!me->query("job/xuyi_kill")) return "你毫无战功，何来封赏？";
                
        if(num >= 1000){
        me->set_temp("xuyi/title", 6);
        command_function("say 这位"+RANK_D->query_respect(me)+"，你立下无数功劳，小王无以为报，愿与你共理此国，封你为王。");
        }
        else if(num >= 600){
        me->set_temp("xuyi/title", 5);
        command_function("say 这位"+RANK_D->query_respect(me)+"战功赫赫，威名远播，是国之栋梁！");
        }
        else if(num >= 300){
        me->set_temp("xuyi/title", 4);
        command_function("say 这位"+RANK_D->query_respect(me)+"灭妖无数，功劳显赫，小王必加重用！");
        }
        else if(num >= 200){
        me->set_temp("xuyi/title", 3);
        command_function("say 这位"+RANK_D->query_respect(me)+"保我疆国，卫我臣民，小王自有封赏！");  
        }
        else if(num >= 100){
        me->set_temp("xuyi/title", 2);
        command_function("say 这位"+RANK_D->query_respect(me)+"常年征战，捷报频传，小王自有答谢！");
        }
        else if(num >= 50){
        me->set_temp("xuyi/title", 1);
        command_function("say 这位"+RANK_D->query_respect(me)+"协助我军降妖除魔，理当得获官职！");    
        }
        else return "你的功劳太低，还不能获得爵位。";
        
        return "跪下(kneel)接旨！";
}

string ask_need()
{
        object me = this_player();
        int times;

        times = (int)me->query("job/xuyi_kill");

        if(me->query("family/family_name")!="盱眙山") return RANK_D->query_respect(me)+"非我家臣，有否功劳与小王何干？";
        if(times == 0) return "你还没立过功呢！";

        command_function("say 你已经立下了"+chinese_number(times)+"件汗马功劳。");

        if(times < 50 ) return "还差"+chinese_number(50-times)+"件功劳就可以获得官位啦。";
        if(times < 100 ) return "还差"+chinese_number(100-times)+"件功劳就可以晋升了。";        
        if(times < 200 ) return "还差"+chinese_number(200-times)+"件功劳就可以晋升了。";        
        if(times < 300 ) return "还差"+chinese_number(300-times)+"件功劳就可以晋升了。";        
        if(times < 600 ) return "还差"+chinese_number(600-times)+"件功劳就可以晋升了。";
        if(times < 1000 ) return "还差"+chinese_number(1000-times)+"件功劳就可以晋升了。";

        else return "你已经官居极品了！";
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
        
//    if (base_name(environment(me))!="/d/xuyi/qiandian") return notify_fail("这里不是金銮殿，怎么能接旨？\n");
        
        if(!me->query_temp("xuyi/title")) return notify_fail("你要行君臣大礼吗？\n");
        
        if( me->query_temp("xuyi/title") == 1) title = titles1[random(sizeof(titles1))];
        else if( me->query_temp("xuyi/title") == 2) title = titles2[random(sizeof(titles2))];
        else if( me->query_temp("xuyi/title") == 3) title = titles3[random(sizeof(titles3))];   
        else if( me->query_temp("xuyi/title") == 4) title = titles4[random(sizeof(titles4))];
        else if( me->query_temp("xuyi/title") == 5) title = titles5[random(sizeof(titles5))];
        else if( me->query_temp("xuyi/title") == 6) title = titles6[random(sizeof(titles6))];
        else title = me->query("title");

        message_vision("$N伏身跪在金銮殿下，恭听圣旨。\n",me);  
        message_vision("一个太监接过圣案上的文书，高声宣道：\n“奉天呈运，皇上昭曰：\n\t兹有"+me->name()+"为国尽忠，降妖除魔。朕封其为"+HIR+title+NOR+"！\n\t\t\t钦此。”\n",me);
        message_vision("太监合上文书，将文书交给$N。$N恭恭敬敬地接过圣旨，三呼万岁，然后才站了起来。\n",me);
        
        me->set("title", "盱眙山蠙城"+title);
        me->delete_temp("xuyi/title");
        me->delete_temp("xuyi/kill_monster");   
        return 1;
}                                       

