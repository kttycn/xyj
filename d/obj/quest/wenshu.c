inherit ITEM;
#include "task.h"

void create()
{
	set_name("����", ({"wen shu", "shu"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����˾���������������������顣\n");
		set("unit", "��");
		set("owner_name","������");
		set("owner_id","yin changsheng");
	}
}
