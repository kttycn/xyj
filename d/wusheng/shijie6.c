// changan wusheng
// shijie6.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

��������羰�����ɾ�����ɽǰ��ʯ·��ֱ��������Ȼ��ͬ��
�о���
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie7",
"southdown": __DIR__"shijie5",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

