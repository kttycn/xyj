// changan wusheng
// shijie4.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

����ʯ�̵�·����ʯ����ɽ����̤�ù����羵��ʯ·���Ի�����
�˸����ʻ��͹�ľ���羰֮����������ȴ��������ǰ�濴��һ��
�����ûʵĽ������֪��ʲô����������˼ӿ�Ų���
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"guangchang",
"southdown": __DIR__"shijie3",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

