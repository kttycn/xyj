inherit ITEM;
#include "task.h"

void create()
{
	set_name("����", ({"bao nang", "nang"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "̫�׽�������װ�����Ĵ��ӡ�\n");
		set("unit", "��");
		set("owner_name","̫�׽���");
		set("owner_id","tai bai");
	}
}
