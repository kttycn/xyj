inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL"����Ѱ����"NOR, ({"xunhu ji","xunhu"}));
	set_weight(500);
	set("unit", "̨");
	set("value",100);
	set("long", "����ǵ��Ź�˾����ƭ������׵Ķ�����\n");
	setup();
}

int query_autoload() { return 1; }

