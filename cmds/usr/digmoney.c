//by����Ӣ��--kicker(hisy@163.net)

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object room,ob;
	mapping baobiao_path;
	int value,number;

	if(me->is_busy()) return notify_fail("����æ���أ�\n");
	room=environment(me);
        message_vision(HIY"����ν��Ϊ��������Ϊʳ����$N��ʼ�����ھ��Ƿ���������Ǯ����·�ϣ�\n"NOR,me);
        me->receive_damage("kee",random(10)+5);

	if( !(baobiao_path=room->query("dig_money")) ) return 1;
	if( !mapp(baobiao_path) || random(4) ) return 1;

	if(!(value=baobiao_path["value"])) return 1;
	if(!(number=baobiao_path["number"])) return 1;
	room->delete("dig_money");	

	ob=new("/obj/money/gold");
	if(!ob) return 1;
	message_vision(CYN"
ͻȻ���������䣬��$N�ڵ���һ�޲Ʊ�����ϸһ������Ȼ��
"+chinese_number(value)+"���ƽ�\n"NOR,me);
	ob->set_amount(value);
	"/adm/daemons/moneyd"->del_log(""+number);
	ob->move(room);
	return 1;
}
