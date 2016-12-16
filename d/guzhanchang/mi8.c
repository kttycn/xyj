 // Room: /shulin/lin8.c
inherit ROOM;
int do_enter(string arg);
void create()
{
        set("short", "��������");
        set("long", @LONG
ǧ���������ߵ�������㶨��һ����ԭ��������������ĵش���
���۴�������һ�����õĴ��ӣ������ϲ����˶���������һ�����ر��
����������������ȥ(enter)��
                          z$$$b                                   
                        z$$$$$$$e                                 
                     .d$$$$$$$$$$$b.                              
                  zd$$$$$$$$$$$$$$$$$$e.                          
              z*************$*************4                       
              F         .*" $ "%c.         L                      
             d     .z*"     $     "*e.     4                      
             F .z*"         $         "*e.  L                     
            dP"             $             ^*$                     
            F$              $              .PL                    
           d *              $              4 3                    
          .F 4.             $              $  L                   
          d   F             $              F  3                   
          P   $             $             4%   L                  
         d    3             $             d    *                  
         P    4r            $             $    ^L                 
        '%=====%============*=============%=====*  
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
              "north" : __DIR__"mi7",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_enter","enter");
}
int do_enter(string arg)
{
 object room;
 object who = this_player();
 if(!arg || arg != "dong")
    return notify_fail("��Ҫ�����\n");
if(random(who->query_kar())>25 && who->query("max_mana")>1000)
 {
  if(!( room = find_object(__DIR__"pomiao")) )
                room = load_object(__DIR__"pomiao");
                if(objectp(room))
             {
              message_vision("$Nֻ������ǰһƬ�׹�����������һ��ԭ���Ǹ�����\n",who);
              who->move(room);
             }
         return 1;
     }
     else
{
message_vision("$N��������������ȴ��һ������˻�ȥ��\n",who);
who->recieve_damage(who->query("kee")/5);
who->recieve_wound(who->query("max_kee")/5);
who->start_busy(5);
return 1;
}
}

