#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�������������Ĵ��š���ǰ����ǽ���ߣ��������ܣ�����һ��������
���������ߵ����ɼľ�������(gate)���Ϸ�һ����ң�����
��������š����������������֡���������һ����������˵����������
д�ġ�
����������
                      ˳ �� �� ��
                   

             ��                            ��
             ��                            ��
             ��                            ��
             ��                            ��
             Ψ                            ��
             ��                            ��
             ��                            һ
             ��                            ͳ
             ��                            ��
             ��                            ��

LONG );
	set("exits", ([
		"north" : __DIR__"qianyuan",
		"south" : __DIR__"bjie3",
	]));

	set("objects", ([
		__DIR__"npc/weishi1" : 4,
		__DIR__"npc/tongling" : 2,
		__DIR__"obj/shishi" : 2,
	]));
//   set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
