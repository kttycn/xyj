inherit ITEM;
#include "task.h"

void create()
{
	set_name("������", ({"feng lingzhu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��˵�е����б���֮һ����֮�ɱܷ紵�����ɷ�����ϵ������\nΪ����������֮�\n");
		set("unit", "ֻ");
		set("owner_name","��������");
		set("owner_id","guanyin pusa");
	}
}
