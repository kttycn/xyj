inherit ITEM;
#include "task.h"

void create()
{
	set_name("��ǹ", ({"shen spear", "spear"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�����޳ɵĹ��ñ�����\n");
		set("unit", "��");
		set("owner_name", "�޳�");
		set("owner_id", "luo cheng");
	}
}

