//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG 
�������������鷿��������ȻƧ����ˮ��ȴ������ǰȥ
��ʤ���ݣ�����֮�������������徭��ʫ�ʸ踳������
���鼮Ҳ�Ǻ�ţ�䶰���಻ʤ�����������и���ͭʨ��
��ֽ(zhenzhi)��������֣�����������
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang6", 
]));
        set("objects", ([
                __DIR__"obj/tong":1,
        ]));


        setup();
} 

