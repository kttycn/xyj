// changan wusheng
// room8.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

���а���һ�Ŵ��������������������һ�ױ��̣���������֮��
����Ƿ������С�
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"room7",
]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);
        setup();
        
        setup();
        replace_program(ROOM);
}
