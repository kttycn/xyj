inherit ITEM;
#include <ansi.h>
#include "task.h"
void create()
{
	set_name("��Ƥñ", ({"hupi mao", "mao"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ʥȡ��ʱ������ñ�ӡ�\n");
		set("unit", "��");
		set("owner_name",HIW"�����"NOR);
		set("owner_id","sun wukong");
	}
}
