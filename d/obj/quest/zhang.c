inherit ITEM;
#include "task.h"

void create()
{
	set_name("ߦ����", ({"ganmian zhang", "zhang"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����԰��Ԫ��ʱ�õ�ߦ���ȡ�\n");
		set("unit", "��");
		set("owner_name","����Բ");
		set("owner_id","ling tangyuan");
	}
}
