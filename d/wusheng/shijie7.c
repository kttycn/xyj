// changan wusheng
// shijie7.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

��������羰�����ɾ�����ɽǰ��ʯ·��ֱ��������Ȼ��ͬ��
�о���
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie8",
"southdown": __DIR__"shijie6",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

