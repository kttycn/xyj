//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "�Ӱ�");
  set ("long", @LONG
��ǰ��������·�������ĺ�ˮ���ˡ����Ũ�ˣ������벨��
���Ũ�˷����ʣ������벨����ͣ���ˮ�ڳ�����������
�������������л����������ˮ�����ˣ���֮��ɳ�ӣ�
Ҳ����ѷɫ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"hean1",
  "southup" : __DIR__"shan",
  "east" : __DIR__"hean3",
]));
        set("outdoors", "heishui");


  setup();
}

