inherit ITEM;
#include "task.h"

void create()
{
	set_name("��Ѫ", ({"ren xue", "xue"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "������ԵĶ�����\n");
		set("unit", "��");
		set("owner_name","����");
		set("owner_id","bi shu");
	}
}
