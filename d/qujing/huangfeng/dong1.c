// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong1.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "¶´ÄÚ");
  set ("long", @LONG

¶´ÄÚ¹âÏß»è°µ£¬ÇÒÓÐÕóÕóÐÈ³ôÆË±Ç¡£Ñýºü½ÆÍÃÔÚÄãÉí±ß´Ú
À´ÌøÈ¥¡£Íù±±Í¨Ïò¶´µÄÉî´¦£¬ÄÏ±ßÊÇ³ö¶´µÄ¶´¿Ú¡£

LONG);

  set("exits", ([
        "south" : __DIR__"dongkou",
	"north" : __DIR__"dong3",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 2,
  ]));
 
  setup();
}

int valid_leave (object who, string dir)
{
	if (! interactive(who) &&
	dir == "south")
		return 0;
	return ::valid_leave(who,dir);
}

void init()
{
	object obj;
	object ob = this_player();
	
	if ( !ob->query_temp("winded") && (! ob->query_temp("apply/name") 
	||ob->query_temp("apply/name")[0] != "[31m»¨½ÅÎÃ×Ó[m")
	&& userp(ob) && !ob->query("obstacle/huangfeng") )
//&& !wizardp(ob) )
	{
		message_vision(HIY"ºöÈ»»Æ·ç¹Ö´óº°Ò»Éù£ºÔõÃ´Ã»¼û¹ýÕâ¸öÈË£¡\n"NOR,ob);
		message_vision(HIY"Ö»¼û»Æ·ç¹Ö´ó×ìÒ»¹Ä£¬´µÆðÁËÈýÃÁÉñ·ç¡£\n"NOR,ob);
		message_vision(HIY"Ö»¼û$NÈç¿ñ·çÖÐµÄ·çÉ³Ò»Ñù·ÉÉÏÁËÌì¿Õ¡£\n"NOR,ob);
		ob->apply_condition("eyeill",50);
		ob->unconcious();
		ob->set_temp("winded",1);
		if( ob->query_temp("lingji1_done") == "yes" )
		{
			ob->move("/d/qujing/huangfeng/huangfeng5");
			return;
		}
		ob->move("/d/qujing/huangfeng/huangfeng5new");
	}
	return;
}
