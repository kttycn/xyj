//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
����������֮�¡��˴����Ʋ���̫����ܵ����Ƚ�������
��������ͷ���ĺ�����Ͷ�������յĵ��������õġ�һ
���ƻ��㻩��һ�������Ա��ι���СС��β��ž�ط�����
���ϡ�
LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiabing" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"haidi1",
  "southdown" : __DIR__"haidi3",
]));
        setup();
}

