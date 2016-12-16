// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

int do_hesword();

void create()
{
//      set_name(HIR"紫"HIG"郢"HIC"剑"NOR, ({ "ziying sword","sword","ziying","ziying-sword"}));
	set_name(MAG"紫郢剑"NOR, ({ "ziying-sword","sword","ziying sword"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","一柄古剑,剑柄上刻有"+MAG"「紫郢」"NOR+"两字,剑身有一层紫气隐隐笼罩。\n");
		set("value", 9000);
		set("no_give","这么好的宝物，给别人? 你入党了没有? \n");
       		set("no_drop","这么好的宝物，你去扔 ! 原来吃饱了没事干呀 !!!\n");
       		set("no_sell", 1);
       		set("no_get", "你被剑刃上的寒气一激，一个哆嗦，手里一松，宝剑从手中滑落！\n");
		set("material", "blacksteel");
		set("wield_msg",MAG"$N右手微张，一声龙吟过后,紫气自东而来,钻入$N右手。\n");
		set("unwield_msg","$N右肩轻摇,"+MAG"紫郢剑"NOR+"便自行飞回鞘中.\n");
		set("weapon_prop/spirituality", 3);
	}
	init_sword(130);//原来是100攻击力，太低了
	set("is_monitored",1);
	setup();
}

int init()
{
	add_action("do_hesword", "hesword");
	return 1;
}
int do_hesword()
{
	object who = this_player();
	object ziyingjian,qingsuojian;
	object doublesword;
	string doublesword_given;
	doublesword_given = "/d/huanggong/doublesword/obj/doublesword.c";
//	qingsuojian="/d/ourhome/honglou/dreamland/obj/qingsuo-sword.c";

	if(who->is_fighting())
		return notify_fail("你正打仗呢！想死啊！\n");
	if(who->is_busy())
		return notify_fail("你还有这工夫?正忙着呢!\n");
//         if(!ziyingjian = present("ziying sword",who))
//		return notify_fail("你还缺少"+HIM "紫郢剑" NOR +",怎么["+HIR"双剑合壁"NOR+"]呢?\n");
         if(!qingsuojian = present("qingsuo-sword",who))
		return notify_fail("你还缺少"+HIC "青索剑" NOR +",怎么["+HIR"双剑合壁"NOR+"]呢?\n");
//	if( ! who->query("sword_hesword") == 1 ) 
//		return notify_fail("没学双剑合剑之技怎么敢合剑呢?\n");
//	if ( !(ziqing_given->in_mud()) ) 
	{
		
		if ( !(doublesword_given->in_mud())){		
			message_vision("$N轻轻将双剑和体,向上天祈祷 !\n\n
突然,一声龙吟过后,"+MAG"紫气"NOR+"自东而来,钻入你右手 \n
你心念方才一动,一声凤鸣过后,"+HIC"青气"NOR+"从天而降,钻入你左手\n\n剑身有一层"+HIC"青"NOR+"气与"+MAG"紫"NOR+"气隐隐笼罩,且渐渐融和...\n 
一道眩光，$N手中多出一把"+HBRED"紫青双剑\n\n"NOR,who);
			tell_object(who,"你不由得微微一笑......\n");
			doublesword = new("/d/huanggong/doublesword/obj/doublesword");
			doublesword->move(who);
			message("channel:rumor",HIR+"【谣言】某人："+who->query("name")+"拿到 ["+HBRED"紫青双剑"NOR+HIR"] 了！\n"+NOR,who);
		} else {
			message_vision("$N轻轻将双剑和体,向上天祈祷 !\n\n突然,一声龙吟过后,"+MAG"紫气"NOR+"自东而来,钻入你右手 \n你心念方才一动,一声凤鸣过后,"+HIC"青气"NOR+"从天而降,钻入你左手\n\n剑身有一层"+HIC"青"NOR+"气与"+MAG"紫"NOR+"气隐隐笼罩,且渐渐融和...\n
\n又待片刻，双剑呼的一闪，一切都消失了。\n",who);
			}
			destruct(this_object());
			destruct(qingsuojian);
		return 1;
		}
//	}
//return notify_fail("宝剑必须摘下才能合剑！\n");
}