//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�������������ף����ܽ�����Щ�谵�ˣ���������ͷ���ĺ�����
Ͷ����������ʱҲ����ô�����ˣ��������������ߵ���ϼ��һֻ
�����ڽ�׵ĺ�ɳ������������һ�������ĺۼ���
LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiejiang" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"haidi2",
  "southwest" : __DIR__"haidi4",
]));
        setup();
}

