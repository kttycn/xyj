//Cracked by Roath
#include <room.h>
inherit HOCKSHOP;

void create ()
{
	set ("short", "�����䵱��");
	set ("long", @LONG

����һ����������ƽ���Ƶĵ䵱�У������������ɫ��ɷ�Ǻÿ�
��ǽ�Ϲ���һ���̴ľ����(paizi)����̨�������ϰ壬һ˫������
�������´������㡣
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"eshangjie2",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
�͹ٿ��������
    ������������������������������
    ��	�䵱(pawn)		��
    ��	����(sell)		��
    ��	����(value)		��
    ��	���(retrieve stamp)	��
    ��	����(buy) ��list�鿴��	��
    ������������������������������
���ֻ��ͭǮ���������ƽ𡢽�ҡ���Ʊһ��ͨ�á�

"]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss" : 1,
	]));
	set("no_clean_up", 1);
	set("no_fight", 1);
	set("no_cast", 1);
	setup();
}

int clean_up()
{
	return 0;
}

