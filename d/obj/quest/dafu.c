inherit ITEM;
#include "task.h"
void create()
{
	set_name("��",({"big axe", "axe"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���ǳ�ҧ��Ĺ��ñ�����\n");
		set("unit", "��");
		set("owner_name", "��ҧ��");
		set("owner_id", "cheng yaojin");
	}
}

