// �����硤���μǣ����ͣ�
// Room: /d/xuyi/xiaolu18-22.h

inherit ROOM;

void create ()
{
  set ("short", "��С·");
  set ("long", @LONG
  
ɽ·˳��ɽ���������·��խ��͹����ƽ������ܲ���Զ���紵����ľ��
��֮�����ϴ���������Ϊ֮һ��������ԶԶ����������ʥ���´���������
������
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaolu21",
  "north" : __DIR__"frontgate",
]));
  set("outdoors", "xuyi");

  setup();
}

