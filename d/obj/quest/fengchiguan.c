inherit ITEM;
#include <ansi.h>
#include "task.h"
void create()
{
	set_name("����Ͻ��", ({"fengchi guan"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�Ϻ����������͸����ʥ�����\n");
		set("unit", "��");
		set("owner_name",HIW"�����"NOR);
		set("owner_id","sun wukong");
	}
}
