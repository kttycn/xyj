//u/stone/d/stoneroom.c
//stone 2001/12/19


inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","石头的工作室");
	set ("long", @LONG
	
这是巫师石头的高级工作室，抬眼望去，墙上一面硕大的液晶墙（wall)
只见前方靠窗的一面放了一张写字卓，卓子有一台高级电脑（compute)，
旁边是个光盘储存塔（tower),右边一排书架（bookcase),左边是一个大
大的沙发。正中站着一个机器人（robot)。
楼下是管理员工作室，西面是健身房，东面是石头的藏书房，东南面
是洗手间，东北面是厨房，楼上是客房以及露天阳台。
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
                "wall"     : "好大的液晶屏，石头巫师经常在玩3D游戏以及看VCD，唱卡拉OK。\n",
                "compute"  : "这是石头巫师惯用的电脑，一看就是最新式的，屏幕上写着“请输入密码”（input)几个字。\n",
		"tower"    : "只见一张张的光盘排列得整整齐齐，等着随时的调看。\n",
		"bookcase"    : "书架上是一排排的书，包罗万像，无所不有。\n",
		"robot"    : "这是石头巫师的保安，警惕的望着你。\n",
	]));
	setup();
}
