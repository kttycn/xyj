inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIM"���ǽ�����"NOR, ({"jieshou qi","qi"}));
	set_weight(500);
	set("unit", "̨");
	set("value",20000);
	set("long", "����ǵ��Ź�˾����ƭ������׵Ķ�����\n");
	setup();
}

int query_autoload() { return 1; }
