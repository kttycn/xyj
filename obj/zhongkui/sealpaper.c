// stone 20020617
//sealpaper.c

inherit ITEM;

void create()
{
	set_name("黄纸", ({"seal paper", "paper"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long","这是一张黄纸，纸上有一些模模糊糊的字迹，可惜已经看不清楚了。\n");
	set("unit", "张");
	set("value", 0);
	}
	setup();
}

