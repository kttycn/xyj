// Room: /u/wuliao/firemount/nonameroad

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG
ǰ�����ɽ���ˣ���Լ�ɼ�ɽ�Ǳ���һ����ɽ��ɽ�ϰ������̣�����
һ����ء�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"nonamemount",
  "northdown" : __DIR__"nonameroad3",
]));
  set("outdoors", "/u/wuliao");

  setup();
}
