inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIM"卫星接收器"NOR, ({"jieshou qi","qi"}));
	set_weight(500);
	set("unit", "台");
	set("value",20000);
	set("long", "这就是电信公司用来骗大家米米的东东。\n");
	setup();
}

int query_autoload() { return 1; }
