//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�������׽ྻ�羵�����к��塢���٣�ѩ�׵ĺ�ɳ��Ө��
���ں��ף�����ʤ�ա�ȺȺ���������Եõ��������Ʈ����
ǰ�治Զ����һ���޴�Ĺ���������ɺ��Χ������˸
���ԡ�
LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yecha" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"xihai",
  "southwest" : __DIR__"haidi2",
]));
        setup();
}

