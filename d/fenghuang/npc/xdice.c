// 丢骰子比大小比点数的游戏
#include <ansi.h>
inherit NPC;
inherit __DIR__+"chiplib.c";
int to_say_rule();
int to_say_play();
int check_dice(int x, int y, int z);
int show_dice(int x,int y,int z);
string betkind(int kind);
string *Dice = ( {      "        ",
                     HIR"   ●   "NOR,
                        "        ",
                        "   ●   ",
                        "        ",
                        "   ●   ",
                        "   ●   ",
                        "   ●   ",
                        "   ●   ",
                        "●    ●",
                        "        ",
                        "●    ●",
                        "●    ●",
                        "   ●   ",
                        "●    ●",
                        "●    ●",
                        "●    ●",
                        "●    ●"
                } );

void create()
{
        set_name("萝丝",({ "rose","dice lady","lady" }));
        set("level",200);
        set("title","骰子小姐");
        set("race", "人类");
        set("gender","女性");
        set("age", 23);
        set("long",@LONG
美丽又可爱的女子，双手正玩弄着三粒骰子。
LONG        );
        set("attitude", "friendly");
        set("inquiry",([
           "骰子": (: to_say_play :),
           "dice": (: to_say_play :),
           "玩法": (: to_say_play :),
           "play": (: to_say_play :),
           "规则": (: to_say_rule :),
           "rule": (: to_say_rule :),
        ]));
        setup();
        seteuid(getuid());
}

int talk_action(object me)      
{
        command("say 如果要知道规则，请按 ask rose about rule。");
        command("smile "+me->query("id") );
        return 1;
}

void init()
{
        add_action("do_bet","bet");
        add_action("do_start","start");
}

int do_bet(string arg)
{
        object me;
        int i, kind, bet;
        
        me = this_player();
        i = Game_can_afford(1,me);
        if(i!=1)
        {
                command("say "+me->query("name")+"，您的筹码呢？");
                return 1;
        }
        if(me->query_temp("GAME/Xdice/Playing")==1)
        {
                command("say "+me->query("name")+"，您已经压过了喔。");
                return 1;
        }
        command("say "+me->query("name")+"，欢迎来玩西八啦!!!");
        if(!arg)
        {
                command("say "+me->query("name")+"，您要压大或压小？");
                return 1;
        }
        if( sscanf(arg,"%d %d",kind,bet)!=2)
        {
                command("say "+me->query("name")+"，请您看看规则好吗？");
                return 1;
        }
        if( (kind<=0 || kind==3 || kind>=18)
        && !(kind==111 || kind==222 || kind==333
          || kind==444 || kind==555 || kind==666) )
        {
                command("say "+me->query("name")+"，您要压哪一类阿？");
                return 1;
        }
        if(Game_can_afford(bet,me)==0)
        {
                command("say "+me->query("name")+"，您也看看您自己的筹码够不够？");
                return 1;
        }
        me->set_temp("GAME/Xdice/Kind",kind);
        me->set_temp("GAME/Xdice/Bet",bet);
        me->set_temp("GAME/Xdice/Playing",1);
        Game_receive_chip(-bet,me);
        command("say 嗯，"+me->query("name")+"，您压的是"+betkind(kind)+"，赌金是"+chinese_number(bet)+"枚筹码。\n");
        message_vision("$N拿出"+chinese_number(bet)+"枚筹码放在桌上。\n",me);
        return 1;
}

int do_start()
{
        object me;
        int i, x, y, z;
        me = this_player();
        if(me->query_temp("GAME/Xdice/Playing")<1)
        {
                command("say "+me->query("name")+"，您还没压筹码耶。");
                return 1;
        }
        message_vision("$N拿起三粒骰子，并向手心吹了几口气。\n",me);
        message_vision("$N将手中的骰子往桌上的大碗公一丢，并从口中说出：西...八...啦...。\n",me);
        
        x = random(6);
        y = random(6);
        z = random(6);
        show_dice(x,y,z);
        i = check_dice(x,y,z);
        if(i!=0)
        {
                i *= me->query_temp("GAME/Xdice/Bet");
                Game_receive_chip(i,me);
                command("applaud "+me->query("id"));
                command("say "+me->query("name")+"，恭喜您蠃得了"+chinese_number(i-me->query_temp("GAME/Xdice/Bet"))+"枚的筹码。");
                message_vision("$N拿起桌上"+chinese_number(i)+"枚筹码。\n",me);
        }
        else command("say "+me->query("name")+"，真抱歉这与您猜的"+betkind(me->query_temp("GAME/Xdice/Kind"))+"并不相同。");
        
        command("say "+me->query("name")+"，欢迎您下次再来。");
        me->delete_temp("GAME/Xdice");
        return 1;
}

string betkind(int kind)
{
        string str;
        switch(kind)
        {
                case 1: str=" * 大 * "; break;
                case 2: str=" * 小 * "; break;
                case 111: str=" * 三个一 * "; break;
                case 222: str=" * 三个二 * "; break;
                case 333: str=" * 三个三 * "; break;
                case 444: str=" * 三个四 * "; break;
                case 555: str=" * 三个五 * "; break;
                case 666: str=" * 三个六 * "; break;
                default: str=" "+chinese_number(kind)+"点 ";
        }
        return str;
}

int check_dice(int x, int y, int z)
{
        object me;
        int i;
        me = this_player();
        if( x==y && y==z )
        {
                i = x*100+y*10+z+111;
                command("say "+me->query("name")+"，您丢出了"+betkind(i)+"。");
                if(me->query_temp("GAME/Xdice/Kind")==i)
                {
                        return 10;
                }
        }
        i = x+y+z+3;
        command("say "+me->query("name")+"，您丢出了"+betkind(i)+"。");
        if(me->query_temp("GAME/Xdice/Kind")==i)
                return 5;
        
        if( me->query_temp("GAME/Xdice/Kind")==1 && i>=11)
                return 2;
        else
        if( me->query_temp("GAME/Xdice/Kind")==2 && i<=10)
                return 2;
        return 0;               
}

int show_dice(int x,int y,int z)
{
        int i,j;
        object me;

        me = this_player();
        message_vision("\n"NOR,me);
        message_vision(GRN"\t\t            "GRN"            "GRN"            \n"NOR,me);
        for(i=0;i<3;i++)
                message_vision(GRN"\t\t  "NOR+Dice[3*x+i]+GRN"    "NOR+Dice[3*y+i]+GRN"    "NOR+Dice[3*z+i]+GRN"  \n"NOR,me);
        message_vision(GRN"\t\t            "GRN"            "GRN"            \n\n"NOR,me);
        return 1;
}

int to_say_rule()
{
        command("smile");
        command("say 规则很简单，只要你拿出筹码压在你想要赌的种类即可。");
        command("say 所压的筹码不得大於一千喔！");
        command("say 要知道玩法请按 ask rose about play。");
        return 1;
}

int to_say_play()
{
write(@HELP
        指  令                         说    明
=====================================================================
        bet <种类> <筹码数>     选定要压的种类及要赌的筹码数
        start                   丢骰子
=====================================================================
种类代码:
                                                                      
    赔率                代                        码                  
                                                                      
    两倍       1->大 (比10大)   2->小 (比11小)                        
                                                                      
    五倍       4->4    5->5    6->6    7->7    8->8    9->9   10->10  
              11->11  12->12  13->13  14->14  15->15  16->16  17->17  
                                                                      
    十倍     111->111        222->222        333->333                 
             444->444        555->555        666->666                 
                                                                      
HELP);
        return 1;
}

