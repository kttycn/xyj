inherit ROOM;
void create()
{
set("short","����");
set("long",@LONG

	�谵�ĵƹ⣬���ŵ���ζ�������ס�����ֵط�����
�������Ź��أ�������������Ǿ�������ˣ�����
���ܲ��˵ľ��ǣ����������ܿ���һЩ����ȥ�Ķ�����
���Ǻ����������ţ�������òҲ��̶á�

LONG);
set("exits", ([
	"east" : __DIR__"nei2",
	"west" : __DIR__"road4",
	"north": __DIR__"chufang",
	"south":__DIR__"lian",
]));
set("objects", ([
	__DIR__"npc/meifu" : 1,
]) );
setup();

}

