//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
	set ("short","ɽ��");
	set ("long", @LONG
��������ɽ���ɵ�ɽ�ţ�����ɽ��ǰ�ɴ�����ʯ�̳ɣ���Ϊ
ƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г�
�˳������㳡��Χ�������ܵ������֣��Ľ��ϸ����˼���ʯ����
�ּ�����Ϊģ������ǰ����ǽ���ߣ��������ݣ�����һ��������
���������ߵ����ɼľ��ͭ����(door)���Ϸ�һ����ң�����
��������š�[1;36m �� ɽ �� �� [2;37;0m���ĸ����֡�
LONG);

	set("outdoors", "shushan");
	set("exits", ([   
		"enter" : __DIR__"yongdao",
		"southdown" : __DIR__"yingketing",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/songer" : 1,
	]));

	create_door("enter", "����", "out", DOOR_CLOSED);
	setup();
}

