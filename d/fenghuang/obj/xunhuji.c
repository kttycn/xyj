inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL"无线寻呼机"NOR, ({"xunhu ji","xunhu"}));
	set_weight(500);
	set("unit", "台");
	set("value",100);
	set("long", "这就是电信公司用来骗大家米米的东东。\n");
	setup();
}

int query_autoload() { return 1; }

