#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�һ�����");
	set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�������һƬ��
���֣�����Զ��ңң�������¡¡��ˮ��,�ƺ��и��ٲ���
LONG );
	set("exits", ([
		"south" : __DIR__"tao_in",
		"north" : __DIR__"pubu",
	]));
	set("outdoors", "pansidong");
	set("no_clean_up", 0);
	setup();
}
