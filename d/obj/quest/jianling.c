inherit ITEM;
#include "task.h"

void create()
{
	set_name("��β����", ({"fengwei jianling", "jianling"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ǵ�����������ʱʣ�µ�һ����β���ᡣ\n");
		set("unit", "֧");
		set("owner_name","����");
		set("owner_id","hou yi");
	}
}
