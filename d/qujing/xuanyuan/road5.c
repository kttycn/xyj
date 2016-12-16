inherit ROOM;
void create()
{
	set("short","[1;36m±øÆ÷¿â");
	set("long",@LONG

	 ÕâÀïÃæ´æ·Å×Åµ±Äêæ§¼ºĞŞÁ·Ê±Ôì¾ÍµÄÒ»Ğ©±øÆ÷£¬Ã¿
Ò»¼ş¶¼ÈÃÄã°®²»ÊÍÊÖ¡£

LONG);
	set("exits", ([
		"south" : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"obj/needle1" : 2,
	]) );
	setup();
}

