// /d/welcome/welcome.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "����֮��");
	set ("long", @LONG
��Ԫ��������̶�о�������һƬ����֮��������ȥ�δӣ�Ŷ����
�����������ת���ڴˣ�������[1;33m oldplayer[2;37;0m����·�ߣ�����Ҫ����ֻ
����[1;33m news [2;37;0m���������ﶼ��Щʲô�¶�����������ǳ�����ͣ��Ǻǣ�
��ô����������[1;33mnewbie[2;37;0m����·�ɡ�
[1;31m����ͨ��:�����뿴һ��!!!!
[1;30m
������help ��鿴���з����help task,help wlzb,help
 qujing,help aboutquest��������MUD�Ļ������淽��.Ҳ��
������������MUD��ͬ�ĵط�.�������е�pfm,Ҳ������������
�ͣգĲ�ͬ��,���ǵ�pfmʮ�ֻ���,������ȫ��ȫ�µ�,��verify
 ���Բ鿴����ѧ��PFM.���ǻ�����UO�����漼��,��ҿ�����
skills2�鿴.���ͼ��help maps
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"newbie" : __DIR__"newbie1",
		"oldplayer" : "/d/city/kezhan",
	]));
	set("objects", ([
		"/d/city/npc/shizhe" : 1,
	]));
	set("no_beg", 1);
	set("valid_startroom", "1");
	set("pingan", 1);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
