#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "嫺�����");
        set("long",@LONG
����һ��̴��ľ��ɵ������ǽ����������ϰ����˾�ʷ�伮����
����������һ�����������ϱ�īֽ��һӦ��ȫ��ǽ�Ϲ���һ
������(tiaofu)�����������������������ﲩ��Ⱥ�顣
LONG );
     set("objects", ([
           __DIR__"obj/book1": 1,
           __DIR__"npc/yanbixue": 1,
        ]));
     set("exits", ([
            "north": __DIR__"zhengting",
        ]));

        set("item_desc",([
                          "tiaofu" : HIR "
              ̤ѩ����Ц��������
              ���귭���۰����¡� \n\n\n "NOR,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

