//stone 20020613
// /d/guzhanchang/cave.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����һ���ڶ�������Ѩ�����Ϻܸ�������Ÿ�Ӳ���������洦
�ɼ�һ�Ѷѵİ׹ǡ��ڶ��Ľ����̾���һ�Ѱ���ɫ����Ӱ����֪��
��ʲô�������м�Ŀյ��ϳ���һ����������۲�(longcao)��
LONG);
  set("item_desc", ([GRN"longcao" : "һ����̷������۲ݣ����������ѹ�ȶ��������й̱���Ԫ֮��Ч��\n"NOR ]));
  set("exits", ([
        "out": __DIR__"dongkou",
        "up": __DIR__"shuitan",
        ]));
  set("objects", ([
        __DIR__"npc/dragon":1,
        __DIR__"obj/skull" : 1,
        ]));
  set("no_lingzhi", 0);
  
  setup();
}

void init()
{
   add_action("do_dig", "dig");
   add_action("do_dig", "wa");
}

int do_dig(string arg)
{

   object ob, me;
   
   me=this_player();

   if( (!arg) || (arg != "long cao" && arg != "longcao" && arg !="���Ѳ�") )
     return notify_fail("��Ҫ��ʲô��\n");

        if (objectp(present("chi jiao", environment(me))))
        return notify_fail(RED"ǧ���������ŭĿ���ӣ�������צ��\n"NOR);

   if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword"  && (string)ob->query("skill_type")!="halberd" &&
     (string)ob->query("skill_type")!="halberd") ) 

     return notify_fail("���Ҹ��ù��߰ɡ�\n");

   if (query("no_lingzhi"))
     return notify_fail("������һ�������Ѳ��ѱ��˲����ˣ�\n");


   ob=new("/d/guzhanchang/obj/longcao");
           ob->move(me);
   message_vision("$N�ڳ�һ��"+HIG"���Ѳ�"NOR+"��С����������뻳�\n", me);
   set("no_longcao", 1);
   call_out("regenerate", 6000);
   return 1;
}

int regenerate()
{
   set("no_longcao", 0);
   return 1;
}