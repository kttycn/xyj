//Cracked by Roath
inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

�������Ϸ�������������Ǻ�ȥ������������Ұ������Զ�����ܣ�
��������ɫ�������������Զ������������ƽ����ɽ���ϳ���
������ݣ�Ʈ�ŵ���������
LONG);
  set("exits", ([ /* sizeof() == 3 */
//  "south" : __DIR__"road1",
]));
        set("outdoors", "penglai");
  setup();
}
void grass_grow()
{
        object grass;
        seteuid(getuid());
        if(grass=new("/d/obj/drug/qiongcao")){
                grass->move(this_object());
                grass->invocation();
        }
        return;
}


void init()
{
   object cao;
    object me=this_player();
   if (!cao=present("qiong cao",environment(me)) )
     {
        grass_grow();
        return ;
     }
   return ;
}   
        


