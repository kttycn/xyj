inherit ITEM;
#include "task.h"

void create()
{
	set_name("����", ({"tan zhu", "zhu"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����үСʱ����ĵ��顣\n");
		set("unit", "��");
		set("owner_name","����ү");
		set("owner_id","long shaoye");
	}
}

