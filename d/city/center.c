//changan city

inherit ROOM;

#include <ansi.h>

void create ()
{
	set ("short","ʮ�ֽ�ͷ");
	set ("long", @LONG

������ǳ����ǵ����ģ�������ֽ����ڴˡ�һ��Ρ��ߴ����¥��
����ǰ��������Щ���ơ�ÿ���峿�����������������ŵ���������
�򳤰��ǵĴ��С�·�ڳ�ˮ�����������˳����ϡ�
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"zhuque-s1",
		"north" : __DIR__"xuanwu-n0",
		"west" : __DIR__"baihu-w1",
		"east" : __DIR__"qinglong-e1",
		"down" : __DIR__"droproom",
     //       	"up" : "d/city/zhuxian/entrance",
		"northwest" : __DIR__"yanbing",
		"northeast" : __DIR__"liwu/happyjie",
	]));
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/libai" : 1,
		__DIR__"npc/man" : 1,
		"/d/qujing/wuzhuang/npc/zhangguolao": 1,
//		"/obj/zhongkui/zhongkui": 1,
	]));

	set("outdoors", "changan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
