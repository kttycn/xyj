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

	set("exits", ([
		"east" : __DIR__"mishi1",
		"north" : __FILE__,
		"south" : __FILE__,
		"west" : __DIR__"mishi8",
	]));

	setup();
	replace_program(ROOM);
}

