// rewritten by snowcat on 4/11/1997
// room: huoyan

inherit ROOM;

void create ()
{
  set ("short", "»ğÑæÉ½");
  set ("long", @LONG

[31m»ğ£¬»ğ£¬»ğ£¡£¡£¡[2;37;0m

´ó»ğÃàÑÓ°Ë°ÙÀï£¬ËÄÖÜ´ç²İ²»Éú¡£¾İËµµ±ÄêÌ«ÉÏÀÏ¾ıµÄÁ¶µ¤Â¯±»µÅ
·­£¬¼¸¿éÂ¯×©µôÔÚ´Ë´¦£¬¼´»¯Îª»ğÑæÉ½¡£ÈËÒ»×ß½øÈ¥¼È³ÉÑÌ»Ò£¬¸ü
ÎğÌá¶«ÄÏÎ÷±±¡£

LONG);

  set("exits", ([
        "westdown" : __DIR__"huoyan",
        "eastdown" : __DIR__"huoyan",
        "northup"  : __DIR__"huoyan",
        "southup"  : __DIR__"huoyan",
      ]));
  set("outdoors", "firemount");
  set("burning_mount",1);
  setup();
}

void init()
{
  add_action("do_all", "");
  add_action("do_fly", "fly");
  add_action("do_extinguish", "extinguish");
  add_action("do_extinguish", "fan");
  add_action("do_extinguish", "shan");
}

int do_fly (string arg)
{
  object me = this_player();

  if (! this_object()->query("burning_mount"))
    return 0;

  message_vision("Ö»¼û$NÏòÉÏÒ»·É£¬ÓÖ±»Ò»¸öÈÈÀËÖØÖØµØ´òÁËÏÂÀ´¡£\n", me);
  return 1;
}

void burnt (object me)
{
  if (! me)
    return;

  if (environment(me) != this_object())
  {
    me->set_temp("burnt_in_mount",1);
    return;
  }

  if (! this_object()->query("burning_mount"))
    return;

  if (random(8) == 0)
  {
    message_vision("Ò»¹ÉÈÈÀËÏ®À´£¬½«$NÍùÉÏÒ»Å×£¬$N·ÉÁË³öÈ¥£¡\n",me);
    me->move(__DIR__"shanbian");
    message_vision("$NÃ°×ÅÅ¨ÑÌ´ÓÉ½ÉÏ¹öÁËÏÂÀ´£¡\n",me);
    me->unconcious();
    me->set_temp("burnt_in_mount",0);
    me->set_temp("fanned_in_mount",0);
    me->set_temp("fan_times_in_mount",0);
    me->set_temp("fainted_in_mount",1);
    return;
  }
  else if (random(2) == 0)
  {
    object ob;
    object *inv = all_inventory(me);
    if (sizeof(inv) == 0)
      return;
    ob = inv[random(sizeof(inv))];
    if (ob->query("id") != "tie shan")
    {
      if (ob->move(this_object()))
      {
        message_vision("Ö»¼û»ğÑæÒ»Ìò£¬$NµÄ$n¶ÙÊ±»¯Îª»Ò½ı£¡\n",me,ob);
        destruct(ob);
      }
    }
  }
  else 
  {
    switch (random(4))
    {
      case 0:
        { message_vision("$NµÄÍ··¢Ã°ÆğÒ»¹ÉÇàÑÌ£¡\n",me); break; }
      case 1:
        { message_vision("$NÉíÉÏ×Ì×Ì×÷Ïì£¡\n",me); break; }
      case 2:
        { message_vision("$NµÄÁ³ÉÏÅòÆğ¼¸¸ö´óË®ğå£¡\n",me); break; }
      case 3:
        { message_vision("$N·¢³öÒ»¹É½¹Î¶£¡\n",me); break; }
    }
  }
  if(me->query("kee") > 15)
    me->add("kee",-5-random(10));
  if(me->query("sen") > 15)
    me->add("sen",-5-random(10));
  call_out ("burnt",random(5)+15,me);
}

void get_burnt (object me)
{
  if (!me || me->query_temp("burnt_in_mount"))
    return;

  if (! this_object()->query("burning_mount"))
    return;

  call_out ("burnt",1,me);
}

int do_all ()
{
  object me;
  me = this_player();

  call_out ("get_burnt",random(2)+10,me);
  return 0; // return 0 to invoke normal commands
}

void announce_success (object me)
{
  object princess = new (__DIR__"npc/princess");

  princess->announce_success(me);
  destruct(princess);
}

void success_quest (object me)
{
  object where = this_object();
  message_vision("\nÉ²ÄÇ¼äÌì»èµØ°µ£¬ºäÂ¡Â¡¼¸Éù¾çÏìÖ®ºó£¬Ò»ÇĞ¶¼Æ½¾²ÁË£¡\n", me);
  message_vision("$NÒÖÖÆ×¡ÅéÅéĞÄÌø£¬¶¨¾¦Ò»¿´£º´ó»ğÒÑ¾­±»ÆËÃğÁË£¡\n", me);
  where->set ("long", @LONG

´ó»ğÒÑ¾­±»ÈËÆËÃğÁË£¬ËÄ´¦»¹Ã°×ÅÒ»Ë¿Ë¿µÄ²ĞÑÌ¡£

Ôø¼¸ºÎÊ±ÕâÀïµÄ´ó»ğÃàÑÓ°Ë°ÙÀï£¬ËÄÖÜ´ç²İ²»Éú¡£¾İËµµ±ÄêÌ«ÉÏÀÏ
¾ıµÄÁ¶µ¤Â¯±»µÅ·­£¬¼¸¿éÂ¯×©µôÔÚ´Ë´¦£¬¼´»¯Îª»ğÑæÉ½¡£ÈËÒ»×ß½ø
È¥¼È³ÉÑÌ»Ò£¬¸üÎğÌá¶«ÄÏÎ÷±±¡£

ÏÖÔÚÒ»ÇĞ¶¼ºÜÆ½¾²ÁË£¬Äã×ßÔÚÕâÀï£¬¸ĞÌ¾²»ÒÑ¡£

LONG);

  where->set("exits", ([
               "northwest" : __DIR__"shanwai",
               "eastdown"  : __DIR__"shanbian",
             ]));
  where->set("burning_mount",0);
  call_out ("announce_success",1,me);
  call_out ("creat",1800);
}

void test_result (object me)
{
  if (random(5) == 0 &&
      me->query_temp("fainted_in_mount") &&
      me->query_temp("fan_times_in_mount") >= 4)
  {
    success_quest(me);
    return;
  }
  message_vision("\n»©À²À²£¬É½ÉÏµÄ»ğÑæÍËÈ¥Ò»´óÆ¬£¬ÓÖÂıÂıÂûÑÓ»Øµ½½Å±ß¡£\n", me);
}

void can_fan (object me)
{
  me->set_temp("fanned_in_mount",0);
}

int do_extinguish (string arg)
{
  object me = this_player();

  if (wizardp(me) && me->query("env/override"))
  {
    success_quest(me);
    return 1;
  }
  if (! present("tie shan",me))
    return 0;

  if (! this_object()->query("burning_mount"))
  {
    message_vision("¼ûµ½É½ÉÏÒÑÃ»ÓĞ»ğÁË£¬$NÉÈÁËÉÈ×Ô¼ºµÄÀäº¹¡£\n", me);
    return 1;
  }

  call_out ("get_burnt",random(2)+10,me);

  message_vision("Ö»¼û$NÆ´ÃüµØÂÕÆğ´óÌúÉÈÖ»Ò»ÉÈ¡£\n", me);
  if (me->query_temp("fanned_in_mount"))
  {
    message_vision("¿ÉÏ§·çÁ¦²»×ã£¬Ê²Ã´Ææ¼£¶¼Ã»·¢Éú¡£\n", me);
    return 1;
  }

  me->set_temp("fanned_in_mount",1);
  me->set_temp("fan_times_in_mount",me->query_temp("fan_times_in_mount")+1);
  message_vision("Ò»¹É¿ñì­Ï¯µØ¶øÆğ£¬ÅÅÉ½µ¹º£°ãµØ¾íÏòÂşÉ½±éÒ°µÄ»ğÑæ£¡\n", me);
  call_out ("test_result",1,me);
  call_out ("can_fan",random(2)+3,me);
  return 1;
}
