inherit ITEM;
#include "task.h"
void create()
{
	set_name("����֦", ({"liushu zhi", "shizhi"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����Ǿ��з�������֦!\n");
		set("unit", "��");
		set("owner_name","��������");
		set("owner_id","guanyin pusa");
	}
}
