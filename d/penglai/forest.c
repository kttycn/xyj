//Room /d/penglai/forest.c

inherit ROOM;

void create()
{
	set("short","����");
    set("long", @LONG

����羰�续���������ϣ����ܹ����д������������滨������涷��
��ȻҲ��һЩ����֮��ģ��������㿴������Ұ�޳�û�ĺۼ���
LONG);
	set("objects",([
		__DIR__"npc/snake" : 1,
	]));
	set("exits",([
		"east" : __DIR__"yaxia",
		"west" : __DIR__"forest1",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object snake;
  
	if( dir=="west")
	{
		if(objectp(snake = present("ju mang",environment(me))))
		return notify_fail(snake->query("name")+"'��'��һ����ס�����ȥ·��\n");
	}
	return ::valid_leave(me,dir);
}
