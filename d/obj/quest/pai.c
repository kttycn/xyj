inherit ITEM;
#include "task.h"

void create()
{
	set_name("����", ({"zhao pai", "pai"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ϰ� �����ص����ֺ����ơ�\n");
		set("unit", "��");
		set("owner_name","������");
		set("owner_id","dai wenzhong");
	}
}
