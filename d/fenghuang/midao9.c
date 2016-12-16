inherit ROOM;

void create()
{
	set("short", "ÃÜµÀ");
	set("long", @LONG
Äã×ß×Å×ß×Å£¬Í»È»·¢ÏÖÄãÃÔÊ§ÁË·½Ïò£¬ÄãÍù»Ø×ßµÄÊ±ºòÈ´·¢ÏÖÄÇÒÑ²»
ÊÇÄãÀ´µÄµÀÂ·ÁË£¬Äã²»½ûĞÄÖĞÒ»Õó·¢Âé¡£Í»È»ÄãÔÚ»è»ÆµÄµÆ¹âÏÂ£¬ÒşÔ¼·¢
ÏÖÁËÊ²Ã´?£
LONG );
	set("exits", ([
		"south" : __DIR__"midao13",
		"north" : __DIR__"midao14",
		"east" : __DIR__"midao10",
		"west" : __DIR__"midao14",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

