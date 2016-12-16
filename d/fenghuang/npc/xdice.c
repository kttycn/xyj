// �����ӱȴ�С�ȵ�������Ϸ
#include <ansi.h>
inherit NPC;
inherit __DIR__+"chiplib.c";
int to_say_rule();
int to_say_play();
int check_dice(int x, int y, int z);
int show_dice(int x,int y,int z);
string betkind(int kind);
string *Dice = ( {      "        ",
                     HIR"   ��   "NOR,
                        "        ",
                        "   ��   ",
                        "        ",
                        "   ��   ",
                        "   ��   ",
                        "   ��   ",
                        "   ��   ",
                        "��    ��",
                        "        ",
                        "��    ��",
                        "��    ��",
                        "   ��   ",
                        "��    ��",
                        "��    ��",
                        "��    ��",
                        "��    ��"
                } );

void create()
{
        set_name("��˿",({ "rose","dice lady","lady" }));
        set("level",200);
        set("title","����С��");
        set("race", "����");
        set("gender","Ů��");
        set("age", 23);
        set("long",@LONG
�����ֿɰ���Ů�ӣ�˫������Ū���������ӡ�
LONG        );
        set("attitude", "friendly");
        set("inquiry",([
           "����": (: to_say_play :),
           "dice": (: to_say_play :),
           "�淨": (: to_say_play :),
           "play": (: to_say_play :),
           "����": (: to_say_rule :),
           "rule": (: to_say_rule :),
        ]));
        setup();
        seteuid(getuid());
}

int talk_action(object me)      
{
        command("say ���Ҫ֪�������밴 ask rose about rule��");
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
                command("say "+me->query("name")+"�����ĳ����أ�");
                return 1;
        }
        if(me->query_temp("GAME/Xdice/Playing")==1)
        {
                command("say "+me->query("name")+"�����Ѿ�ѹ����ม�");
                return 1;
        }
        command("say "+me->query("name")+"����ӭ����������!!!");
        if(!arg)
        {
                command("say "+me->query("name")+"����Ҫѹ���ѹС��");
                return 1;
        }
        if( sscanf(arg,"%d %d",kind,bet)!=2)
        {
                command("say "+me->query("name")+"�����������������");
                return 1;
        }
        if( (kind<=0 || kind==3 || kind>=18)
        && !(kind==111 || kind==222 || kind==333
          || kind==444 || kind==555 || kind==666) )
        {
                command("say "+me->query("name")+"����Ҫѹ��һ�ఢ��");
                return 1;
        }
        if(Game_can_afford(bet,me)==0)
        {
                command("say "+me->query("name")+"����Ҳ�������Լ��ĳ��빻������");
                return 1;
        }
        me->set_temp("GAME/Xdice/Kind",kind);
        me->set_temp("GAME/Xdice/Bet",bet);
        me->set_temp("GAME/Xdice/Playing",1);
        Game_receive_chip(-bet,me);
        command("say �ţ�"+me->query("name")+"����ѹ����"+betkind(kind)+"���Ľ���"+chinese_number(bet)+"ö���롣\n");
        message_vision("$N�ó�"+chinese_number(bet)+"ö����������ϡ�\n",me);
        return 1;
}

int do_start()
{
        object me;
        int i, x, y, z;
        me = this_player();
        if(me->query_temp("GAME/Xdice/Playing")<1)
        {
                command("say "+me->query("name")+"������ûѹ����Ү��");
                return 1;
        }
        message_vision("$N�����������ӣ��������Ĵ��˼�������\n",me);
        message_vision("$N�����е����������ϵĴ��빫һ�������ӿ���˵������...��...��...��\n",me);
        
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
                command("say "+me->query("name")+"����ϲ��������"+chinese_number(i-me->query_temp("GAME/Xdice/Bet"))+"ö�ĳ��롣");
                message_vision("$N��������"+chinese_number(i)+"ö���롣\n",me);
        }
        else command("say "+me->query("name")+"���汧Ǹ�������µ�"+betkind(me->query_temp("GAME/Xdice/Kind"))+"������ͬ��");
        
        command("say "+me->query("name")+"����ӭ���´�������");
        me->delete_temp("GAME/Xdice");
        return 1;
}

string betkind(int kind)
{
        string str;
        switch(kind)
        {
                case 1: str=" * �� * "; break;
                case 2: str=" * С * "; break;
                case 111: str=" * ����һ * "; break;
                case 222: str=" * ������ * "; break;
                case 333: str=" * ������ * "; break;
                case 444: str=" * ������ * "; break;
                case 555: str=" * ������ * "; break;
                case 666: str=" * ������ * "; break;
                default: str=" "+chinese_number(kind)+"�� ";
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
                command("say "+me->query("name")+"����������"+betkind(i)+"��");
                if(me->query_temp("GAME/Xdice/Kind")==i)
                {
                        return 10;
                }
        }
        i = x+y+z+3;
        command("say "+me->query("name")+"����������"+betkind(i)+"��");
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
        command("say ����ܼ򵥣�ֻҪ���ó�����ѹ������Ҫ�ĵ����༴�ɡ�");
        command("say ��ѹ�ĳ��벻�ô��һǧร�");
        command("say Ҫ֪���淨�밴 ask rose about play��");
        return 1;
}

int to_say_play()
{
write(@HELP
        ָ  ��                         ˵    ��
=====================================================================
        bet <����> <������>     ѡ��Ҫѹ�����༰Ҫ�ĵĳ�����
        start                   ������
=====================================================================
�������:
                                                                      
    ����                ��                        ��                  
                                                                      
    ����       1->�� (��10��)   2->С (��11С)                        
                                                                      
    �屶       4->4    5->5    6->6    7->7    8->8    9->9   10->10  
              11->11  12->12  13->13  14->14  15->15  16->16  17->17  
                                                                      
    ʮ��     111->111        222->222        333->333                 
             444->444        555->555        666->666                 
                                                                      
HELP);
        return 1;
}

