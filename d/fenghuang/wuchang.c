inherit ROOM;
void create()
{
	set("short", "ģ��ʵս�����");
	set("long", @LONG
�����Ƿ�˾�У��ģ��ʵս�ҵ���ڣ�������һ���߿Ƽ���ģ��
ʵս�ң�
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"lian1",
	]));
	set("objects", ([
		__DIR__"npc/master3" : 1,         
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}


