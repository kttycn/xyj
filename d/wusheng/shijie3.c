// changan wusheng
// shijie3.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

����ʯ�̵�·����ʯ����ɽ����̤�ù����羵��ʯ·���Ի�����
�˸����ʻ��͹�ľ���羰֮����������ȴ���������Ա߻���һ��
��·����Ϣ�õ���ͤ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie4",
"west": __DIR__"liangting",
"southdown": __DIR__"shijie2",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

