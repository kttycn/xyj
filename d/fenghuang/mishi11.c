inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������������µ����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵ�
������ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�����������
�����Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ���ơ�
LONG
	);
	set("objects", ([
//		__DIR__"npc/zchenxin" : 1,
		__DIR__"npc/fenghuang" : 1,
	]));
	set("exits", ([
		"up" : __DIR__"mishi6",
	]));

	setup();
	replace_program(ROOM);
}

