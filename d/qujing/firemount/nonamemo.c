// Room: /u/wuliao/firemount/nonameroad

inherit ROOM;

void create ()
{
  set ("short", "����Сɽ");
  set ("long", @LONG
ɽ����ʲôҲû�У�ɽ����´��һ����ʯ�������Լ�����ֻҰ�á�
������ȥ���Ǵ���ɽ�ˡ����汻��𿾵�һƬͨ�졣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"southside1",
  "eastdown" : __DIR__"nonameroad4",
]));
  set("outdoors", "/u/wuliao");

  setup();
}
