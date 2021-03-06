// deergao.c 鹿茸膏
// stone 20020415
//add_force 4

#include <ansi.h>
inherit ITEM;

void init();
void eat();

void create()
{
	set_name("鹿茸膏",({YEL"deer gao"NOR,"cream", "gao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "南极仙翁以产自蓬莱仙岛的仙鹿之鹿茸精华，
再配以百草洞中的各种药材，细细熬练而成。\n");
		set("unit", "块");
		set("value", 4000);
		set("no_drop","这么宝贵的鹿茸膏，扔了多可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
        set("remaining", 4);
        set("food_supply", 30);
    }
	
	setup();
}

void init()
{
	add_action("do_chi", "eat");
}


int do_chi(string arg)
{
	object me = this_player();
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("你已经吃得太多了，再吃就撑死了。\n");

    this_player()->add("food", (int)query("food_supply"));
    	me->add_maximum_force(4);
//	me->add_maximum_mana(1);

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N拿起一块鹿茸膏吃了几口。一股香甜直透肺腑，$N觉得精神好多了。\n", this_player());
//   		 tell_object(me, "你只觉一股灵气上冲灵台，下达泥丸，全身舒泰......\n" NOR);
   		 tell_object(me, "你只觉丹田中慢慢地升起了一团热气，浑身暧洋洋的......\n" NOR);
	} else 
	{ 
   		 message_vision("$N把最后一点鹿茸膏吃得干干净净，不禁啧了啧嘴，回味无穷。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
