inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG

�������Ȼ��Ѻ���̴��ı�����������˵��������ʱ��֪��
�Լ������꾫���Ի󣬶���ʱ���Ľ�ɽ�Ѿ������ˣ�����ô
�����ڻ����ţ�Ҳ���Ǻ��꾫����ʩ��������

LONG);
	set("exits", ([
		"north": __DIR__"mishi",
	]));
	set("objects", ([
		__DIR__"npc/zhouwang" : 1,
		__DIR__"npc/taijian" :2,
		__DIR__"obj/fengdao" :2,
	]) );
	setup();
}

