// changan wusheng
// shijie1.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

����ʯ�̵�·����ʯ����ɽ����̤�ù����羵��ʯ·���Ի�����
�˸����ʻ��͹�ľ���羰֮����������ȴ��������
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie2",
"east" : "/d/changan/zhongnan",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

