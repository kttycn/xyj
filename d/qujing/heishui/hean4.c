//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "�Ӱ�");
  set ("long", @LONG
��ˮ�ӣ�ˮĭ�������̿���˻�Ʈ���Ʒ�ú����ˮ����ţ��
��������ѻȸ�ѷɡ� ţ��������ڣ� ѻȸ�ѷ������֡�
ˮ�沨��ӿ�𣬶ѳ������ĭ�������������ᡣ
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"hean3",
  "east" : __DIR__"hean5",
]));
        set("outdoors", "heishui");


  setup();
}

