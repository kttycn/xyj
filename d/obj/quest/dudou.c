inherit ITEM;
#include "task.h"

void create()
{
	set_name("�Ƕ�", ({"du dou", "dou"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�캢�����ĶǶ���\n");
		set("unit", "��");
		set("owner_name","�캢��");
		set("owner_id","honghai er");
	}
}
