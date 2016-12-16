//Cracked by Roath
#include <room.h>
inherit HOCKSHOP;

void create ()
{
	set ("short", "龙升典当行");
	set ("long", @LONG

这是一家以买卖公平著称的典当行，建筑风格古香古色，煞是好看
，墙上挂着一块雕花檀木招牌(paizi)，柜台后坐着老板，一双精明的
上上下下打量着你。
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"eshangjie2",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客官可以在这里：
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
    ＊	典当(pawn)		＊
    ＊	卖断(sell)		＊
    ＊	估价(value)		＊
    ＊	赎回(retrieve stamp)	＊
    ＊	购买(buy) 用list查看。	＊
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
各种货物，铜钱、银两、黄金、金币、银票一概通用。

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

