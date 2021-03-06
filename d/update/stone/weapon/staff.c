//stone created
//20020322

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit STAFF;

int ji(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
void remove_ding(object me, object victim);

void create()
{
	set_name(HIG"天龙玉杖"NOR, ({"tianlong zhang", "zhang", "staff"}));
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 0);
		set("material", "jade");
		set("value", 10000000);
//		set("no_give","天龙玉杖对对方而言太重了。\n");
//	 	set("no_drop", 1);
	        set("no_put", 1);
//		set("no_sell","小店小本经营，买不起这么贵重的宝物。\n");
		set("long", "这根绿玉佛杖，颜色就象普通碧绿竹子，沉重异常，比同样长短大小的
铁杖还重。径口不过三寸左右，上端形似莲花，杖身上刻一十三个蝇
头小字："HIG"即慈航成普渡，玄玉祛群魔，无量佛！"NOR"，并且布满鳞形的花
纹与各种奇异的符录，光华隐现，一望而知是一件佛门降魔至宝。\n");
		set("wield_msg", "$N一声清咤，反手拔取背上天龙玉杖，一声拂号，竹吐青光。\n");
		set("unequip_msg", "$N擦拭几下，将$n插负回背上。\n");
	}
	init_staff(140);
	set("is_monitored",1);
	setup();
}

void init()
{
  ::init();
  if (!wizardp(this_player()))
  {
      set("no_drop","这么好的宝物，扔了多可惜呀！\n");
      set("no_give","这么好的宝物，留着自己用吧！\n");
      set("no_sell", "小店小本经营，买不起这么贵重的宝物。\n");
  }
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name();
    
    if (this_object()->query("in_use"))
	return notify_fail("青龙已经离杖而去，现在的"+objname+"不过是一条普通的青玉杖罢了。\n");
    if (!target)
	return notify_fail("你想用对谁用"+objname+"？\n");
    
    if(!objectp(victim=present(target,environment(me))))
	return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim))
	return notify_fail("你的目标不是活物！\n");
    if(!me->is_fighting())
	return notify_fail("只有战斗中才能祭"+objname+"。\n");  
    if(victim->query("no_move"))
	return notify_fail("对方已经无暇自顾了，有必要用"+objname+"么？\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("你的精神无法集中！\n");
    msg="$N从背后抽出一条"HIG"天龙玉杖"NOR"，手挽卍字诀，将"+objname+"对空一丢，喝道：“请佛宝降魔！”\n";
    msg+="蓦闻霹雷一声，竹杖上迸出万道青露，千重碧彩，那竹枝已幻作青龙，\n在空中上下飞腾，探出龙爪向$n扑去。\n";
    msg+=HIG"只见那由竹杖幻化的青龙，青麟银须，拥着一片碧云，带着千重银彩，振甲腾挪，神骏无匹。\n"NOR;
    condition=determine_success(me, victim);
    switch(condition)
    {
      case 1:
	msg+=HIR"$n被青龙抓个正着，顿时手忙脚乱，不知所措。\n" NOR;
	msg+=CYN"$n被"+objname+CYN"的法力定住了！\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random(mykar);
	if (dingtime < 1) dingtime=1;
	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"被定住了"+chinese_number(dingtime)+"秒。\n" NOR);
	this_object()->set("in_use", 1);
	call_out("remove_ding", dingtime, me, victim);
	break;
      case 0:
	msg+=HIB"$n伸手一指，大喝一声“落！”只见青龙变回天龙玉杖，落回$N手中。\n"NOR;
	break;
      case -1:
	msg+=HIB"$n伸手一指，大喝一声“回！”只见青龙反将$N抓住了！\n"NOR;
	dingtime=random(victim->query_kar());
	if (dingtime<1) dingtime=1;
	me->set_temp("no_move");
	this_object()->set("in_use");
	call_out("remove_ding", dingtime, victim, me);
	break;
      case -2:
	msg+=HIB"$n伸手一指，大喝一声“收！”只见青龙变回天龙玉杖，落入$n手中。\n"NOR;
	this_object()->move(victim);
	break;
    }
    message_vision(msg,me,victim);
    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    return 1;
}
int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    cost=me->query(variable)/4;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

void remove_ding(object me, object victim)
{
    string msg=CYN"只见青龙腾空而起，附回了"+query("name")+CYN"。\n"NOR;
    this_object()->delete("in_use");
    
    if(!victim) return;

    if (living(victim))
	msg += CYN"$n又恢复了自由。\n"NOR;
    message_vision(msg, me, victim);
    victim->delete_temp("no_move");
    return;
}
int determine_success(object me, object victim)
{
    int myspells, mydx, victimspells, victimdx;
    int ap, dp, attackfactor, condition;

    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;

    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;

    attackfactor=random(ap+dp);

    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}

