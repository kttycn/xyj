//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","���䳡");
	set("long", @LONG

����¶�����䳡���ö�����������������ţ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ���
LONG);
        set("outdoors", "shushan");
        set("exits", ([
	    "east" : __DIR__"yongdao",
   	]));
        set("objects", ([ 
             __DIR__"obj/muren" : 4,
             __DIR__"npc/dizi" : 1,
             __DIR__"npc/dizi1" : 1,
       ]));
        setup();
}

