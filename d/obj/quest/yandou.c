inherit ITEM;
#include "task.h"
void create()
{
	set_name("�̶�", ({"yan dou", "dou"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��ѻ������ϲ���õ��̶���\n");
		set("unit", "��");
		set("owner_name","��ѻ����");
		set("owner_id","wuya xianshen");
	}
}
