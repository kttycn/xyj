inherit ITEM;
#include "task.h"

void create()
{
	set_name("����ľ" , ({"jingtang mu" }));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "˵���õļ�ʲ��\n");
		set("unit", "��");
		set("owner_name","˵����");
		set("owner_id","shuoshu lao");
	}
}
