//by欢乐英雄--kicker(hisy@163.net)

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object room,ob;
	mapping baobiao_path;
	int value,number;

	if(me->is_busy()) return notify_fail("你正忙着呢！\n");
	room=environment(me);
        message_vision(HIY"正所谓人为财死，鸟为食亡，$N开始疯狂的挖掘是否有人埋了钱财在路上！\n"NOR,me);
        me->receive_damage("kee",random(10)+5);

	if( !(baobiao_path=room->query("dig_money")) ) return 1;
	if( !mapp(baobiao_path) || random(4) ) return 1;

	if(!(value=baobiao_path["value"])) return 1;
	if(!(number=baobiao_path["number"])) return 1;
	room->delete("dig_money");	

	ob=new("/obj/money/gold");
	if(!ob) return 1;
	message_vision(CYN"
突然，火星四射，被$N挖到了一罐财宝！仔细一看，竟然是
"+chinese_number(value)+"两黄金！\n"NOR,me);
	ob->set_amount(value);
	"/adm/daemons/moneyd"->del_log(""+number);
	ob->move(room);
	return 1;
}
