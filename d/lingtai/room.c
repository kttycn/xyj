// Room: some place in ��ţ����
// inside2.c

inherit ROOM;

void create()
{
	set ("short", "��̨");
	set ("long", @LONG

һ����̨�߸����ϣ�����������ʦ������̨�ϣ���������ʮ��С
������̨�¡���Χ����ȫ���ɼ����ߣ���һ��˵��������ͣ���
͸��ׯ�ϡ�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"out": __DIR__"houlang5",
		"north":__DIR__"taiji",
	]));
	set("objects", ([
		__DIR__"npc/puti": 1 ]) );
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="north") {
		if(me->query("class")!="taoist")return notify_fail("�㱻һ�������˻�����\n");
		else if(me->query("faith")<8000)
			return notify_fail("�㱻һ�������˻�����\n");
	}
	return ::valid_leave(me,dir);    
}

