inherit ROOM;
void create()
{        
set("short", "С��");        
set("long",@LONG
����һ���������е�С�ݣ������м���ż��Ŵ󴲣��������ӣ�
�����Ǹ���Ϣ�ĵط������й�����ͣ�ʹ�˸���˯�⡣
LONG );
        set("exits", ([                 
           "west" : __DIR__"houting",
         ]));          set("no_fight",1);
       set("no_steal",1);
       set("sleep_room",1);
       set("no_clean_up", 0);
       setup();       
       replace_program(ROOM);
}

