inherit ITEM;
#include "task.h"

void create()
{
	set_name("���", ({"jie chi", "chi"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ƽ��������ִ���Ľ�ߡ�\n");
		set("unit", "��");
		set("owner_name","ƽ����");
		set("owner_id","pingdeng wang");
	}
}
