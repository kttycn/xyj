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
		"west" : __DIR__"mishi6",
		"south" : __FILE__,
		"north" : __FILE__,
		"east" : __DIR__"mishi9",
	]));

	setup();
	replace_program(ROOM);
}

