//Cracked by Roath
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "�ڶ�������ڴ�");
  set ("long", @LONG

������Ǵ�˵�еĵڶ����������ˡ�
����㲻Ը�������Ļ��������뿪�����ļ���
 ==============================
      / \| O   O |
      \ /  \v_'/
       #   _| |_
      (#) (     )
       #\//|* *|\\     ��
       #\/(  *  )/     ��
       #   =====       ��
       #   (\ /)       ��
       #   || ||        ��
      .#---'| |----.
       #----' -----'
===============================
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "north": __DIR__"tian2",
]));
set("objects", ([
        "/d/guzhanchang/npc/shouhuzhe2": 1]));
        set("no_clean_up", 0);
        set("outdoors","guzhanchang");
        setup();


}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "north") {
                if(objectp(a=present("shouhuzhe", environment(me))) && living(a) )
                return notify_fail("�ػ��ߺ���Ը�����ȥ��\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}


