inherit ITEM;
#include "task.h"

void create()
{
	set_name("��ڴ�", ({"feng kou dai" , "koudai" }));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "������װ���õĴ�ڴ���\n");
		set("unit", "��");
		set("owner_name","����");
		set("owner_id","feng po");
	}
}