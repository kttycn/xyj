//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG 
�����Ǻ��񸮵�ʯ�ҡ������������ţ����㨡�����
ȴ���������ӣ����������������������߰���������
��С�������ڵ��ϲ���ˣ�ӡ�
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"zoulang1",
  "south" : __DIR__"zoulang4",
  "east" : __DIR__"zoulang3",
]));

        set("objects", ([
                __DIR__"npc/guai" : 3,
        ])); 

        setup();
} 

