// qianjinzi.c

#include "herb.h"

void create()
{
	set_name(HIY "ǧ����" NOR, ({ "qian jinzi", "herb_qianjinzi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 3000);
        	set("weight", 20);
set("base_unit","��");
	}
	setup();
}
