//stone 20020613
///d/guzhanchang/dong.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ºÚ¶´");
  set ("long", @LONG

Ë®Á÷ÔÚÉÏÃæ½á³ÉÎÞÊý¸öÐ¡µÄäöÎÐ£¬ÒÔ·É¿ìµÄËÙ¶È£¬Ðý×ª×ÅÏòÏÂÂäÈ¥£¬
¶øÄã¾Í´¦ÔÚÕâäöÎÐµÄÖÐÐÄ£¬Ë®Á÷µÄ¿ì½µÊ¹¸÷¸öÐ¡äöÎÐÏà»¥ÎüÒý£¬²»
¶Ï»ý¾Û£¬×îºó½á³ÉÒ»¸öË¶´óÎÞ±ÈµÄ´óäöÎÐ£¬äöÎÐµÄÖÐÐÄ¾¹È»Á¢×ÅÒ»
¸ùÌúÖù£¬ÌúÖùµ×²¿ÓÐ×ÅÒ»¸ö²»Ð¡µÄÈ±¿Ú£¬Ì¶Ë®¾Í´ÓÕâÀï·ÉÐ¹¶ø³ö¡£
È±¿ÚÏÂÃæÉî²»¿É²â£¬Èç¹ûÄã²»¸Ï¿ì£¨[1;35mout[m£©µÄ»°£¬²»¾ÃÄã¾ÍÒª
±»ºÚ¶´ÍÌÊÉ£¡

LONG);
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("down");
        call_out("down",2,ob);
        add_action("do_out","out");
}
int do_out()
{
    object ob = this_player();

    string place = "/d/guzhanchang/tandi1";
    place[strlen(place)-1] = '0'+random(11);

    message_vision(HIC"Ö»¼û$NÊÖ×¥½ÅµÅ£¬ÈÌ×ÅÈ«ÉíµÄËáÍ´£¬Æ´ÄÃµØµØÑØ×ÅÌúÖùÏòÉÏÅÀ¡£\n"NOR,ob);
    ob->move(place);
    return 1;
}

void down(object ob)
{

        message_vision(HIW"$N¾õ×Å×Ô¼ºµÄÉíÌåÒÑ¾­½û²»×¡ÐýÎÐµÄÇ£³¶£¬$NºÃÏó¿´¼ûÀ´×ÔµØ¸®µÄÅ£Í·ÂíÃæÏòÄã×ßÀ´¡£\n",ob);
        message_vision("Ëæ×Å$N×îºóÒ»µãÔªÆøµÄºÄ¾¡£¬$NµÄÉíÌå¾Í¿ìÒª±»ºÚ°µÖ®Ô¨ÍÌÃ»ÁË£¡£¡£¡\n"NOR,ob);
        ob->add("kee",-50);
//        ob->start_busy(2);
}

