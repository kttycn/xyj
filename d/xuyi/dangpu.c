// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit HOCKSHOP;

void create ()
{
	set ("short", "��ǵ���");
	set ("long", @LONG

����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨
�ϰ���һ������(sign)����̨���������ϰ壬һ˫�������۾����´�����
�㡣

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"jiedao4",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"sign" : "
�����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ�
�͹ٿ��������
   ��=======================��
   ||  �䵱(pawn)           ||   
   ||  ����(sell)           ||
   ||  ����(value)          ||
   ||  ���(retrieve stamp) ||
   ||  ����(buy) ��list�鿴 ||
   ��=======================��

���ֻ��ͭǮ���������ƽ���Ʊһ��ͨ�á�

	"]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/pablo" : 1,
	]));
	set("no_clean_up", 1);

	setup();
}

int clean_up()
{
	return 0;
}

