// honey.c 蜂王蜜露
// stone 20020415
//add_mana 4

#include <ansi.h>
inherit ITEM;

void init();
void drink();

void create()
{
	set_name("蜂王蜜露",({HIY"honey"NOR,"fengwang milu", "milu"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "百花仙子以蓬莱仙岛百花谷中的百只蜂王蜜玉
浆，以山泉水秘法酿造，对修仙练道大有益处。\n");
		set("unit", "碗");
		set("value", 3000);
		set("no_drop","这么宝贵的蜂王蜜露，扔了多可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
        set("remaining", 4);
        set("water_supply", 30);
    }
	
	setup();
}

void init()
{
	add_action("do_he", "drink");
}


int do_he(string arg)
{
	object me = this_player();
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝得太多了，再吃就胀死了。\n");

    this_player()->add("water", (int)query("water_supply"));
//    	me->add_maximum_force(4);
	me->add_maximum_mana(1);

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N拿起一碗蜂王蜜露吃了几口。一股香甜直透肺腑，$N觉得精神好多了。\n", this_player());
   		 tell_object(me, "你只觉一股灵气上冲灵台，下达泥丸，全身舒泰......\n" NOR);
	} else 
	{ 
   		 message_vision("$N把碗里的最后一点蜂王蜜露舔得干乾净净，不禁啧了啧嘴，回味无穷。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
