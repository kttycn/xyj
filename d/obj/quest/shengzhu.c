inherit ITEM;
#include "task.h"

void create()
{
	set_name("ʥ����", ({"sheng lingzhu"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","��س���ʱ�����߹����ϣ����߹����£���һ�ְ�����ǹ����У���Ϊ�˱���\n������н�Ϊ���ӡ�\n");
		set("owner_name","��������");
		set("owner_id","guanyin pusa");
	}
	setup();
}
