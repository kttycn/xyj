//Cracked by Roath

inherit ROOM;

void create ()
{
	set ("short", "���ݳ�����");
	set ("long", @LONG

    ����ǽ��ݳǵ������ˣ�����ط����𳤰��ǿ����ǲ�Զ�ˡ�
 һ�۶��������Կ���·���������ʵļ������ˣ�������ſ�����
Ҳ�ܾ��ˡ����飺
[1;32m
                ������������������������
                ��                    ��
                ��    ��        ��    ��
                ��                    ��
                ������������������������
[m
LONG);

	set("exits",
	([ //sizeof() == 4
		"east" : __DIR__"chengen-2",
	]));

	set("objects",
	([ //sizeof() == 1
		"/d/city/npc/wujiang" : 1,
	]));

	set("outdoors", "jiangzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}