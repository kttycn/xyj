//by yxm@hxxt.hz
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short", BLK"�ڰ�֮Ԩ"NOR);
	set ("long", @LONG
[1;31m�������ͨ�������޽�֮·,һ��ͨ������,[2;37;0m
[1;31mͨ��ʹ��,ͨ�����ĺڰ�֮·.[2;37;0m
[1;31m����ħ��ɭɭ,���˲�������![2;37;0m
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"enter" : __DIR__"lu2",
	]));
	setup();
}
