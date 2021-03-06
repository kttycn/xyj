// created by snowcat 

inherit ITEM;

void create()
{
  set_name("自动售货机", ({ "automat", "shouhuo ji" }) );
  set_weight(250000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "台");
    set("long", "这是一台沉重的自动售货机，一眼望去里面装满了各种商品(good)。\n");
    set("value", 2000);
  }
}

int is_container()
{
  return 1;
}

void init ()
{
  add_action ("do_donate","donate");
}

int do_donate (string arg)
{
  object who = this_player ();
  object silver = present ("silver",who);
  int amount, val;
  string item;
  object obj;

  if(arg && sscanf(arg, "%d %s", amount, item)==2) {
    if( !objectp(obj = present(item, who)) )
      return notify_fail("你身上没有这样东西。\n");

    if(!obj->value() || obj->query("base_value")<100) 
       return notify_fail("这里只接受金银捐款。\n");

    if( amount < 1 )
       return notify_fail(obj->name()+"的数量至少是一个。\n");
    if( amount > obj->query_amount() )
       return notify_fail("你没有那么多的" + obj->name() + "。\n");
  } else {
    if (! silver)
      return notify_fail("你身上没有银子。\n");
    obj=silver;
    amount=1;
  }

  val=obj->query("base_value")*amount/1000;
  // each gold will reduce total waiting time by 30 sec.
  // mon 4/5/98
//  if(val<1) val=1;

  if (! who->query_temp("kaifeng_donate_silver")) 
      who->set_temp("kaifeng_donate_silver", 1);
  else if(val>0)
      who->add_temp("kaifeng_donate_silver", val);

  message_vision ("$N从身上取出"+chinese_number(amount)+
     "两"+obj->name()+"投到自动售货机里。\n",who);
  
  if(val>0)
    write("好！你在宫中三拜所需的时间将减少"+
	  chinese_number(val*3)+"秒！\n");

  obj->set_amount( (int)obj->query_amount()-amount );
  if (obj && obj->query_amount() == 0)
    destruct (obj);

  return 1;
}

