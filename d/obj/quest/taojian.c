inherit ITEM;
#include "task.h"
void create()
{
	set_name("��ľ��", ({"mutao jian", "jian"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ԭ���ʩ��ʱ�õ��ҽ���\n");
		set("unit", "��");
		set("owner_name","Ԭ���");
		set("owner_id","yuan tiangang");
	}
}
