// mudage.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int sec, min, hrs, day, mon, age;
	string out_str;
	
	if( me->query("sen") < 10 )
		return notify_fail("��ľ����ܼ��������Լ������ꡣ\n");
		
	out_str = FINGER_D->age_string( (int)me->query("mud_age") + (int)me->query("age_modify"));
/*	age = (int)me->query("mud_age") + (int)me->query("age_modify");		
	sec = age % 60;
	age /= 60;
	min = age % 60;
	age /= 60;
	hrs = age % 24;
	age /= 24;
	day = age % 30;
	mon = age / 30;
	
	out_str = (mon? chinese_number(mon)+"��":"")
		+ (day? chinese_number(day)+"��":"")
		+ (hrs? chinese_number(hrs)+"Сʱ":"");
*/
	me->add("sen", -5);
//          write("���Ѿ�Ϊ���������ܶ�" + out_str + "�ˡ�\n");
              write("���Ѿ�Ϊ"HIM"��Ӱ"HIG"��Ե"NOR"�ܶ�" + out_str + "�ˡ�\n");
	return 1;
}
