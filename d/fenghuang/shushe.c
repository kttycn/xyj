inherit ROOM;
void create()
{        
set("short", "ѧ������");        
set("long",@LONG
���Ǳ�Уѧ����Ϣ�ĵط������й�����ͣ�ʹ�˸���˯�⡣
LONG );
       set("exits", ([                 
           "west" : __DIR__"guangchang",
           "up" : __DIR__"shushe1",
         ]));
       set("no_fight",1);
       set("no_steal",1);
       set("sleep_room",1);
       set("no_clean_up", 0);
       setup();       
       replace_program(ROOM);
}

