// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
	set ("short", "�ֵ�");
	set ("long", @LONG

̫�ͽִ�ϙ�����Ĺ㳡ֱ�ﶫ���⣬��������ǳ�����Ҫ�ֵ���������
����ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ����ֵ���������һ�����ӣ�
��дһ�����ġ������֡�������һ���ߴ����¥��
LONG);

	set("exits", ([
		"east"   : __DIR__"dongmen",
		"west"   : __DIR__"center",
		"south"   : __DIR__"feiyue",
		"north"   : __DIR__"dangpu",
	]));
	set("objects", ([
//        __DIR__"npc/people"   : 1,
	]));
	set("outdoors", __DIR__);

	setup();
}

