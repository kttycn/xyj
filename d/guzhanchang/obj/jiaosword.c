//stone 20020614
// /d/guzhanchang/obj/jiaosword.c

#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;
void init();
void kaifengs();

void create()
{
        set_name(RED"赤蛟剑"NOR, ({ "jiaosword", "chijiao sword","sword" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", RED"一柄森森泛光，红光流动的软剑，剑身隐现暗赤
色光华，剑中似有一条蛟龙翻飞，栩栩欲活，望
之如生，极为醒目。相传道行高深之士可以血开
锋（kaifengs)。"NOR);
		set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
		set("no_put", 1);
		set("no_drop", "这么稀罕的宝剑，你不觉可惜吗？\n");
		set("no_give", "这可是千年一见的神兵宝刃啊，哪能随便给人？\n");
		set("no_get", "你被剑上的煞气一逼，心中一寒，忙不迭地丢下赤蛟剑。\n");
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/xijian");
		set("material", "steel");		
		set("wield_msg", RED"$N往腰间一探，“唰”的一声抽出$n"+RED"，顿时亮起一团耀目的赤红之光。\n"NOR);
		set("unwield_msg", RED"随$N一声无奈的叹息，红光一闪，$N把$n别回腰中。\n"NOR);
		set("weapon_prop/courage", 3);
	}
	init_sword(90);
	set("is_monitored",1);
	setup();
}

void init()
{
	add_action("do_kaifeng", "kaifengs");
}
int do_kaifeng(string arg)
{
	object who = this_player();
	object jiaosword;
	object newjiaosword;
	string newjiaosword_given;
	newjiaosword_given = "/d/guzhanchang/obj/jiaosword1.c";

	if(who->is_fighting())
		return notify_fail("你正打仗呢！想死啊！\n");
	if(who->is_busy())
		return notify_fail("你还有这工夫?正忙着呢!\n");
	if(!jiaosword = present("jiaosword",who))
		return notify_fail("你还缺少"+RED "赤蛟剑" NOR +",怎么能施展「血符开锋」呢?\n");
	if ( jiaosword->query("equipped")=="wielded" )
		return notify_fail("赤蛟剑必须摘下才能开锋！\n");
	 if( (!arg) || !((arg == "jiaosword") || (arg == "赤蛟剑")))
                return notify_fail("你要以血开锋什么？\n");
        if( who->query("kee") < (int)(who->query("max_kee")/3))
//                who->receive_damage("kee",(int)who->query("max_kee")*20/100);
                return notify_fail("你现在伤太重，要以血开锋的话，驾驭不了赤蛟血剑。\n"); 
        if( (int)who->query("force") < 1000 )
                return notify_fail("你的真气不足，要以血开锋的话，恐怕会受赤蛟反噬。\n");
        if( (int)who->query("mana") < 2000 )
                return notify_fail("你的法力还不充盈，不能施展「血符开锋」神通。\n");
        if( (int)who->query("bellicosity") < 100 )
                return notify_fail("你的杀气还不重，不能施展「血符开锋」神通。\n");                                                                       
        if ( !(newjiaosword_given->in_mud()) ) 
	{			
		message_vision("$N眼射神光，伸出右手剑指，吐劲震破指头，于剑上划符......\n\n
"+HIR"$N怒喝道：“以吾之血，为尔开锋！”"NOR+"\n\n
"+RED"突见，软剑吸血，红光闪耀，精炼锐狂，笔直刚挺，犹如脱胎换骨，异常锋利。"NOR+"\n
"+RED"剑中现出一条威猛凶恶的赤蛟缠绕翻腾......"NOR+"\n
"+HIR"$N手中的赤蛟剑变为“赤蛟血剑”。\n\n"NOR,who);
		message_vision("$N脸上浮现出一丝冷笑......\n\n",who);
		newjiaosword= new("/d/guzhanchang/obj/jiaosword1");
		newjiaosword->move(who);
		who->add("kee", -(int)who->query("max_kee")*10/100);
//		who->add("max_kee", -(int)who->query("max_kee")*10/100);
		who->start_busy(4);
		destruct(this_object());
		MONITOR_D->report_rumor_object_msg(who, "以血画符开锋得到了【"+HBRED"赤蛟血剑"NOR+HIR"】 了！");		
	} else {
		message_vision("$N眼射神光，伸出右手剑指，吐劲震破指头，于剑上划符......\n\n
"+HIR"$N怒喝道：“以吾之血，为尔开锋！”"NOR+"\n\n
只见赤蛟剑吸血，红光一闪，赤蛟剑化作一道红光直飞云宵，消失了...\n",who);
	}
	destruct(this_object());
	return 1;
}