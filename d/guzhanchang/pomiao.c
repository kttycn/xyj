// /d/guzhanchang/pomiao.c
inherit ROOM;
int do_out();
void create()
{
        set("short", "����");
         set ("long", @LONG
 "������һ������
���������˷����������൱���졣
*/.    .   .    *      .
  .\*    .    []           *  __
  */ .   ./\~~~~~~~~~~~~'\. |��  
   \*   ,/,..,\,...........,\.��  
   ||  ..��#  ����  �� �� | ����
   ||  &&��   ��       ��'|'�� o   
   || ##����������������������   
LONG);
                     
set("exits", ([
                "down" : __DIR__"road0",
                
        ]));
  set("objects", ([
             __DIR__"npc/guiwang" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_out","out");
}
int do_out()
{
 object room;
 object who = this_player();
  message_vision("$N����Ҫ�뿪�ˣ���������һ�ᣬ��һ������˳�ȥ��\n",who);
  who->recieve_damage(who->query("kee")/5);
  who->recieve_wound(who->query("max_kee")/5);
  who->start_busy(5);
  who->move("/d/guzhanchang/mi8");
  return 1;
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "down") {
                if(objectp(a=present("guiwang", environment(me))) && living(a) )
                return notify_fail("������У��������ܣ���������������˾����죡��������\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}

