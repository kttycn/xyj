// changan wusheng
// shijie5.c

inherit ROOM;

void create()
{
  set ("short", "ʯ�׷");
  set ("long", @LONG

��������������羰�����ɾ�����ɽǰ��ʯ·��ֱ������
��Ȼ��ͬ�ĸо���̧ͷ��ȥ��һ���������Ƶ��ͱڶ��������
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie6",
"south": __DIR__"room1",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

