// changan wusheng
// room9.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

��������ڷ���ʮ�˰������������ڼ��ϻ������Ÿ����ɼұ�����
��������ֵ�����һ��������ʯ̨�ϣ��ý��˱������˴�һ�㣬
���ϴ�������Ŀ��ף���֪���к��ã�
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"room7",
]));
set("objects", ([
        __DIR__"npc/jinren": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
        
        setup();
        replace_program(ROOM);
}
