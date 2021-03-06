//stone 20020614
// /d/guzhanchang/obj/jiaosword1.c

#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;
int close(object me, object ob);

void create()
{
        set_name(HIR"赤蛟血剑"NOR, ({ "xuesword", "xue sword","sword" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", HIR"一柄森森泛光，红光流动的剑，剑身现出亮赤色
光华。经过鲜血开锋后，红光缠绕，剑脊现出一
条恶蛟，剑尖血红光芒伸缩吞吐不定，锋芒毕露。"NOR);
		set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
		set("no_put", 1);
		set("no_drop", "这么稀罕的宝剑，你不觉可惜吗？\n");
		set("no_give", "这可是千年一见的神兵宝刃啊，哪能随便给人？\n");
		set("no_get", "你被剑上的杀气一逼，心中一寒，忙不迭地丢下赤蛟血剑。\n");
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/xijian");
		set("material", "steel");		
		set("wield_msg", HIR"$N往反手背后一拔，“呛”的一声拔出$n"+HIR"，顿时亮起一团耀目的赤红之光。\n赤红光芒犹如蛟龙翻腾，直冲云霄。
$N脸上顿时现起一股森寒的杀气。 \n"NOR);
		set("unwield_msg", "随$N一声无奈的叹息，红光疾闪，$N把$n插回背后。\n");
		set("weapon_prop/courage", 8);
	}
	init_sword(135);
	set("is_monitored",1);
	setup();
}

void init()
{
    add_action("do_wield","wield");
}
int do_wield(string arg)
{
    	object me,ob;
	me = this_player();
	ob = this_object();
//if( !arg ) return 0;
	if(arg == "xuesword" || arg == "sword") {    
	if((int)me->query("max_force", 1) < 2500 ||
    	(int)me->query("force", 1) < 1000  ){
 	tell_object(me,"你感觉全身气息翻腾，原来你内力不够，提不起这把赤血神兵。\n");
  	return 1;
  	}
	if((int)me->query_str() < 20){
   	tell_object(me,"你想举起这把赤血神兵，怎奈力量不够，只好作罢。\n");
  	return 1;
	}
	ob->wield();
	message_vision(HIY"$N一声长啸，“呛”的一声从背后拔出赤蛟血剑，顿时亮起一团耀目的赤红之光。
赤红光芒犹如蛟龙翻腾，直冲云霄。
$N脸上顿时现起一股森寒的杀气。\n"NOR, me);
	me->add("force", -100);
	remove_call_out("close");
	call_out("close",900, me,ob);
  	return 1;
  	}
}

int close(object me, object ob)
{
	object jiaosword;
	tell_room(environment(me), ob->query("name")+"的红光渐渐暗去，又恢复成赤蛟剑......\n");
	jiaosword= new("/d/guzhanchang/obj/jiaosword");
	jiaosword->move(me);
        destruct(ob);
	return 1;
}