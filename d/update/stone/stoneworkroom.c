//u/stone/d/stoneroom.c
//stone 2001/12/19


inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","ʯͷ�Ĺ�����");
	set ("long", @LONG
	
������ʦʯͷ�ĸ߼������ң�̧����ȥ��ǽ��һ��˶���Һ��ǽ��wall)
ֻ��ǰ��������һ�����һ��д��׿��׿����һ̨�߼����ԣ�compute)��
�Ա��Ǹ����̴�������tower),�ұ�һ����ܣ�bookcase),�����һ����
���ɳ��������վ��һ�������ˣ�robot)��
¥���ǹ���Ա�����ң������ǽ�����������ʯͷ�Ĳ��鷿��������
��ϴ�ּ䣬�������ǳ�����¥���ǿͷ��Լ�¶����̨��
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"east" : "/d/update/stone/d/bookroom",
		"west" : "/d/update/stone/d/jianshenfang",
		"southeast" : "/d/update/stone/d/waterroom",
		"northeast" : "/d/update/stone/d/cookroom",
		"up": "/d/update/stone/d/sfloor",
		"down": "/d/wiz/workroom",
	]));
	
	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
//	set("freeze",1);
	set("no_time", 1);
	
	set("objects", ([ /* sizeof() == 2 */
//		__DIR__"npc/robot1" : 1,
		"/d/update/stone/npc/xuannv" : 1,
        ]));
	set("item_desc", ([
                "wall"     : "�ô��Һ������ʯͷ��ʦ��������3D��Ϸ�Լ���VCD��������OK��\n",
                "compute"  : "����ʯͷ��ʦ���õĵ��ԣ�һ����������ʽ�ģ���Ļ��д�š����������롱��input)�����֡�\n",
		"tower"    : "ֻ��һ���ŵĹ������е��������룬������ʱ�ĵ�����\n",
		"bookcase"    : "�������һ���ŵ��飬���������������С�\n",
		"robot"    : "����ʯͷ��ʦ�ı���������������㡣\n",
	]));
	setup();
}
