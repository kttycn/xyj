inherit ROOM;
void create()
{
set("short","����");
set("long",@LONG

���ﳱʪ���������ڹ����ֱ۴�ϸ��ţ���������������紵����
�����������������Ĵ�������ɧ�����㲻����ס�˱��ӣ������ȵ���
�ߣ��㻹����һ̲��Ѫ�������Ǻ��������֡�

LONG);
set("exits", ([
	"east" : __DIR__"nei3",
	"west" : __DIR__"nei1",
	"north": __DIR__"yongdao",
	"south":__DIR__"dadian",
]));
set("objects", ([
	__DIR__"npc/guard" : 2,
]) );
setup();

}
