inherit ITEM;
#include "task.h"
void create()
{
	set_name("������", ({"lan yuwang", "wang"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ã�ȴ����׽���㡣\n");
		set("unit", "��");
		set("owner_name","��˳");
		set("owner_id","zhang shun");
	}
}

