inherit ROOM;
void create()
{
	set("short","��԰");
	set("long",@LONG
�������ŷ�˳����еķ���β���滨��ݣ���������ʤ�ڰ��ˣ���
��ȫ�������õĻ�����������Щ���ݣ�ʹ��һ�����͸е�����
�泩��
LONG);
	set("objects", ([
//	   __DIR__"obj/hua1": 2,
//	   __DIR__"obj/hua2": 2,
	]));
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"zoulang1",
	    "west"  : __DIR__"qianyuan",
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

