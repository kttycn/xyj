// changan wusheng
// room4.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

�����޺��Ĵ������޺��������ڴ�����У�������ʥ������
һλ���ߡ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"southeast": __DIR__"room1",
]));
set("objects", ([
        __DIR__"npc/xianglong": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}
