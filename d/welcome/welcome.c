// /d/welcome/welcome.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "»ìãçÖ®³õ");
	set ("long", @LONG
»ìÔª¿ªÊÀ£¬ÄàÌ¶ÖĞ¾ÍÓĞÁËÕâÒ»Æ¬¼«ÀÖÖ®¾»ÍÁ£¬ºÎÈ¥ºÎ´Ó£¿Å¶£¡Èç
¹ûÄãÊÇÀÏÄà°Í×ªÊÀÓÚ´Ë£¬»¹ÇëÏò[1;33m oldplayer[2;37;0mÕâÌõÂ·×ß£¬ÄãËùÒª×öµÄÖ»
ÊÇÓÃ[1;33m news [2;37;0mÀ´¿´¿´ÕâÀï¶¼ÓĞĞ©Ê²Ã´ĞÂ¶«Î÷¡£Èç¹ûÄãÊÇ³õÍæÄà°Í£¬ºÇºÇ£¡
ÄÇÃ´»¹ÊÇÇëÄã×ß[1;33mnewbie[2;37;0mÕâÌõÂ·°É¡£
[1;31mĞÂÊÖÍ¨¸æ:ĞÂÊÖÇë¿´Ò»ÏÂ!!!!
[1;30m
ĞÂÊÖÓÃhelp »ò²é¿´ÆäÖĞ·ÖÏî£¬Èçhelp task,help wlzb,help
 qujing,help aboutquestÕâÊÇÎÒÃÇMUDµÄ»ù±¾Éú´æ·½·¨.Ò²ÊÇ
ÎÒÃÇÓë±ğµÄÎ÷ÓÎMUD²»Í¬µÄµØ·½.ÎÒÃÇËùÓĞµÄpfm,Ò²ÊÇÓëÆäËüÎ÷ÓÎ
£Í£Õ£Ä²»Í¬µÄ,ÎÒÃÇµÄpfmÊ®·Ö»ªÀö,»ù±¾ÉÏÈ«²¿È«ĞÂµÄ,ÓÃverify
 ¿ÉÒÔ²é¿´ÄãËùÑ§µÄPFM.ÎÒÃÇ»¹ÓĞÀàUOµÄÉú´æ¼¼ÄÜ,´ó¼Ò¿ÉÒÔÓÃ
skills2²é¿´.²éµØÍ¼ÓÃhelp maps
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
