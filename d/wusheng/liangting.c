// changan wusheng
// liangting.c

inherit ROOM;

void create()
{
  set ("short", "����ͤ");
  set ("long", @LONG

һ���ð��������˶��������Ĵ�ľ��֧�Ž�����ɵ�ʯͤ������
�Ϻ�����ī������˵�����������������ʿ������ͤ�ӵ�ľ���ϣ�
����Ϊ��ó��ӣ���������Ѿ�ģ�����壬������������
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"shijie3",
]));
        set("no_clean_up", 0);
        set("outdoors", 0);
        setup();
}

