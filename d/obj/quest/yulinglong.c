inherit ITEM;
#include "task.h"

void create()
{
	set_name("������", ({"yu linglong" }));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "̽�����İ������\n");
		set("unit", "��");
		set("owner_name","̽��");
		set("owner_id","tan chun");
	}
}
