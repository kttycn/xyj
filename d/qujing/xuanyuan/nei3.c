inherit ROOM;
void create()
{
set("short","��Ĺ����");
set("long",@LONG

	��������ԯĹ�Ľ��أ�����ֻС������ΪҪ�뿪����ط���
�ڴ��ܵ��ͷ�������������ط�Ҳû�ж�����������ֻ��ϲ����
��Щ�������������ǡ�

LONG);
set("exits", ([
	"west" : __DIR__"nei2",
]));
set("objects", ([
	__DIR__"npc/xian": 1,
]) );
setup();

}

