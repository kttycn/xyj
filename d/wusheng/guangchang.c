// changan wusheng
// guangchang.c

inherit ROOM;

void create()
{
  set ("short", "�㳡");
  set ("long", @LONG

һ���������������ǧ�˵Ĵ�㳡����ǰһ����˶��Ľ��Ҿ͹�
���Ƕ������Ĵ����ϣ�������д���������֡�������۵
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"room1",
"southdown": __DIR__"shijie4",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

