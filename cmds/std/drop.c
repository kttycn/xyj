// drop.c

inherit F_CLEAN_UP;
#include <ansi.h>

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
	mixed no_drop;

	if(me->is_busy())
		return notify_fail("你正忙着呢．．．\n");
 
	if(!arg) return notify_fail("你要丢弃什么东西？\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( no_drop=obj->query("no_drop") )
			return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开丢弃。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");

		if( obj->query("weapon_prop") && me->is_exert() &&
			obj == me->query_temp("weapon"))
				return notify_fail("你正在使用"+me->query_exert()+"，无法丢下"+obj->name()+"。\n");
		if( obj->query("weapon_prop") && me->is_perform() &&
			obj == me->query_temp("weapon"))
				return notify_fail("你正在使用"+me->query_perform()+"，无法丢下"+obj->name()+"。\n");

		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(do_drop(me, obj2)) { // succeed to drop
			    obj->set_amount( (int)obj->query_amount()-amount );
			    return 1;
			}
			return 0;
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if (inv[i]->query("no_drop")) continue;
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	if( no_drop=obj->query("no_drop") )
                return notify_fail( stringp(no_drop) ? 
			no_drop : "这样东西不能随意丢弃。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
    mixed no_drop;
    object *inv;

	if(me->is_busy())
		return notify_fail("你正忙着呢．．．\n");
	   
	if( no_drop = obj->query("no_drop") && !wizardp(me))
		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");

	inv = all_inventory(environment(me));  
	if (sizeof(inv)>49)
		return notify_fail("地上已经那么多东西了，你想干嘛？\n");

	if (obj->move(environment(me))) {
		if((obj->query_temp("d_mana"))>0) {
			if( obj->query_temp("is_living")==1 )
				message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
			else {
				message_vision( sprintf("$N丢下一%s$n。\n",	
				undefinedp(obj->query_temp("unit"))?
				"个":obj->query_temp("unit")), me, obj );
			}
		} else {
            if (me->is_fighting()) me->start_busy(1);
			if( obj->is_character() )
				message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
			else {
				if ( wizardp(me) && me->query("id") != "fei" ) {
					write(HIG"一只绿色小鬼很快地跑出来，接住你丢下的东西，然后消失不见了！！！\n"NOR);
					destruct(obj); 
					return 1;
				}
				message_vision( sprintf("$N丢下一%s$n。\n",	obj->query("unit")),me, obj );
				if( !obj->query("value") && !obj->value() ) {
					tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
					destruct(obj);
				}
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : drop <物品名称>
 
这个指令可以让你丢下你所携带的物品.
 
HELP
    );
    return 1;
}
 
