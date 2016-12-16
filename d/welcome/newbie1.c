// Room: /d/welcome/newbie1
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "ÈëÊÀÖ®Â·");
	set ("long", @LONG
ÔÂÓ°ÆæÔµµÄÈëÊÀÖ®Â·ÊÇÒ»Ìõ»ìãçÖ®Â·£¬ÕâÂ·Í¨ÏòµÄÊÇ¹îÒìµÄ¡°ÈË¡¢
Éñ¡¢¹í¡±Èı½ç£¬ÎªÁËÄãÄÜÔÚ½ñºóµÄ½­ºşÂ·ÉÏ¹ıµÃÒ»·«·çË³£¬½¨ÒéÄãÏÈ
¿´Ò»±é[1;33m help newbie[2;37;0m£¬ÔÚÄÇÀïÃæÏêÏ¸µÄ½âËµÁËÒ»¸öĞÂÊÖÔÚÄàÌ¶ÖĞµÄÉú
´æÖ®µÀ¡£ÒªÈëÊÀ£¬¿´ËüÊÇ±Ø²»¿ÉÉÙ¡£
LONG);

	set("no_magic", 1);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"newbie2",
	]));
	set("no_beg", 1);
	set("pingan", 1);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
