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
  "southwest" : __DIR__"sleeproom",
  "north" : __DIR__"zoulang2",
]));

        set("objects", ([
                __DIR__"npc/guai" : 3,
        ])); 

        setup();
} 

