// changan wusheng
// room6.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

�������ôӽ�����񡢽������ϡ�װ�޲��ֶ������ϵ��칬����
�ơ��������ܾŲ�����Χ��Ʈ�죬�����滹͸������ׯ��֮����
���������𾴡�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"room7",
"south": __DIR__"shijie9",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}
