// ZHANGM 1999/12/18 
#include <ansi.h>
inherit BANK;

void reset_balance(object me);

void create()
{
	set("short", HIY "��˴�����" NOR);
	set("long", @LONG
����һ�����ֺŵ����ţ����н�ǧ�����ʷ���ڷ���Ǹ��������ǳǶ��зֵꡣ����
�еĵ������ÿ������ǳ��ã����ҷǳ����㣬ͨ��ȫ����
    �ڶ����ǽ�ϵĵ�����Ļ(pingmu)����ʾ�������°�ҵ��
LONG );
	set("exits", ([
		"south" : __DIR__"eshangjie1",
	]));
	set("item_desc", ([
		"pingmu" : @TEXT
       �������ṩ���·���
       ת��      zhuanzhang <ĳ��> <�ƽ�����>
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/banker" : 1
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
}
