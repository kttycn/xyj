// changan wusheng
// room1.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

��ʥ�ŵ��������ĵط�����ľ�˺�ͭ�˹��������������һ��в�
ˮ�䣬���˵ĵ��Ӷ��ڲ�ˮ��������Ϣ٩̸����ʥ�Ź�Ȼ��һ��
�õط�������
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"room1",
]));
        set("no_fight", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
        "/obj/board/wsboard"->foo();
}

