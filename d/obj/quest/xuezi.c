inherit ITEM;
#include "task.h"

void create()
{
	set_name("��ѥ��", ({"po xuezi", "boot"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������֮ǰ���촩��Ь�ӡ�\n");
		set("unit", "˫");
		set("owner_name","�����");
		set("owner_id","duanzu gui");
	}
}
