inherit ROOM;
void create()
{  
	set("short", "ģ��ʵս��");
	set("long", @LONG
�����Ǿ�Уѧ��ѵ���ĵط����м��������û����˰�������м��������ֳ�
�����������˻�����С�
LONG );
	set("objects", ([
		__DIR__"obj/jqr1" : 1,         
	]));
	set("exits", ([
		"north" : __DIR__"wuchang",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

