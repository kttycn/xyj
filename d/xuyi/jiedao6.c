// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
	set ("short", "�ֵ�");
	set ("long", @LONG

һ���������ʯ·�棬·����Ȼ���Ǻܿ����ǽֵ��Ե������������ֹ�
�ӣ������۴��αȣ�����������������Ȼ��һƬ̫ƽ���־��󡣽ֱ�����
�к����ҫ��ͨ��ˮĸ���︮ۡ�Ĺ��š�

LONG);

	set("exits", ([
		"east"   : __DIR__"jiedao5",
		"north"   : __DIR__"jiedao2",
	]));
	set("objects", ([
//        __DIR__"npc/people"   : 1,
	]));
	set("outdoors", __DIR__);

	setup();
}
