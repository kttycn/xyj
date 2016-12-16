// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "¸®ÃÅ");
  set ("long", @LONG

¸®ÃÅ¸ß´óĞÛÎ°£¬ºç¹âÉÁË¸¡£Ò»±ßÊÇ½ğÁú³öË®£¬ÁíÒ»±ßÊÇÒø·ï³¯
Ñô£¬ÃÅéÜÉÏÓñ÷è÷ëÍÌÔÆÍÂÎí¡£ÔÙÍùÀï¿´£¬Â¥¸ó¹¬µî×ÏÆøÈğÈğ£¬Ïé
ÔÆçÔÈÆ¡£

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie7",
        "south"   : __DIR__"dayuan",
        "west"   : __DIR__"jitan",
      ]));
  set("objects", ([
        __DIR__"npc/bing"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "south")
  		return 0;
  if(dir =="west" && who->query("id")=="fei zei" ||("id") == "thief" ||("id") == "zei")
		return 0;
  return 1;
}

