//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
ˮ������������������ˮ���沨������ɺ������Ҳʱ������һ����
ˮ������ĺ������걿�ص�Ų���������Ӵ����������ǹ����ʯ
���Ѱ����ʳ�����������������������Ϣ���޾�������������
�
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"haidi3",
  "west" : __DIR__"haidi5",
  "south" : __DIR__"jiaoshi",
]));
        setup();
}

