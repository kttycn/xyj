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
		"south" : __DIR__"mishi4",
		"east" : __FILE__,
		"north" : __FILE__,
		"west" : __DIR__"mishi",
	]));

	setup();
	replace_program(ROOM);
}

