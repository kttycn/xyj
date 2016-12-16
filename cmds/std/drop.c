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
		return notify_fail("����æ���أ�����\n");
 
	if(!arg) return notify_fail("��Ҫ����ʲô������\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( no_drop=obj->query("no_drop") )
			return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");

		if( obj->query("weapon_prop") && me->is_exert() &&
			obj == me->query_temp("weapon"))
				return notify_fail("������ʹ��"+me->query_exert()+"���޷�����"+obj->name()+"��\n");
		if( obj->query("weapon_prop") && me->is_perform() &&
			obj == me->query_temp("weapon"))
				return notify_fail("������ʹ��"+me->query_perform()+"���޷�����"+obj->name()+"��\n");

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
		return notify_fail("������û������������\n");
	if( no_drop=obj->query("no_drop") )
                return notify_fail( stringp(no_drop) ? 
			no_drop : "���������������ⶪ����\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
    mixed no_drop;
    object *inv;

	if(me->is_busy())
		return notify_fail("����æ���أ�����\n");
	   
	if( no_drop = obj->query("no_drop") && !wizardp(me))
		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");

	inv = all_inventory(environment(me));  
	if (sizeof(inv)>49)
		return notify_fail("�����Ѿ���ô�ණ���ˣ�������\n");

	if (obj->move(environment(me))) {
		if((obj->query_temp("d_mana"))>0) {
			if( obj->query_temp("is_living")==1 )
				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
			else {
				message_vision( sprintf("$N����һ%s$n��\n",	
				undefinedp(obj->query_temp("unit"))?
				"��":obj->query_temp("unit")), me, obj );
			}
		} else {
            if (me->is_fighting()) me->start_busy(1);
			if( obj->is_character() )
				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
			else {
				if ( wizardp(me) && me->query("id") != "fei" ) {
					write(HIG"һֻ��ɫС��ܿ���ܳ�������ס�㶪�µĶ�����Ȼ����ʧ�����ˣ�����\n"NOR);
					destruct(obj); 
					return 1;
				}
				message_vision( sprintf("$N����һ%s$n��\n",	obj->query("unit")),me, obj );
				if( !obj->query("value") && !obj->value() ) {
					tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
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
ָ���ʽ : drop <��Ʒ����>
 
���ָ��������㶪������Я������Ʒ.
 
HELP
    );
    return 1;
}
 
