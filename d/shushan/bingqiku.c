//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","������");
	set("long", @LONG

���Ǳ����⣬һ������ӡ�����ŵ��������룬��������Ĺܼ���
�����渺��ģ�һЩ�����ڸ��ܱ����Ĺܼ�˵��ʲô��
LONG);
        set("no_fight",1);
        set("exits", ([
		"west" : __DIR__"eastway2",
         ]));
        set("objects", ([ 
        __DIR__"npc/lingyunzi" : 1,
        __DIR__"npc/guanjia" : 1,
        "/d/obj/weapon/sword/qingfeng" :1,
        "/d/obj/weapon/sword/qinghong" :1,
         ]));

       setup();
}

