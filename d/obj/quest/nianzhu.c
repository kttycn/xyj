inherit ITEM;
#include "task.h"

void create()
{
	set_name("����", ({"nian zhu" }));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������·����õ����顣\n");
		set("unit", "��");
		set("owner_name","����");
		set("owner_id","fang zhang");
	}
}
