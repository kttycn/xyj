inherit ITEM;
#include "task.h"

void create()
{
	set_name("������", ({"tu lingzhu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","��˵�е����б���֮һ����֮�ɱ�ʯ�ң����ɷ�����ϵ������\nΪ����������֮�");
		set("owner_name","��������");
		set("owner_id","guanyin pusa");
	}
	setup();
}
