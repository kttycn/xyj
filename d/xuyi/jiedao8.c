// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
	set ("short", "̫�ͽ�");
	set ("long", @LONG

һ���������ʯ·�棬·����Ȼ���Ǻܿ���������������Ҳ��һƬ����
�ľ��󡣽ֵ��Ƕ�������������һ����Ȫ��������ǳ��ţ�������ʿ��
������Ѳ�ӣ��鿴�����������ǡ�
LONG);

	set("exits", ([
		"west"   : __DIR__"jiedao7",
		"east"   : __DIR__"qingquan",
		"north"   : __DIR__"dongmen",        
	]));
	set("objects", ([
//        __DIR__"npc/people"   : 1,
	]));
	set("outdoors", __DIR__);

	setup();
}

