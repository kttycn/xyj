inherit ITEM;

void create()
{
	set_name("混元金斗", ({"hunyuan dou","dou"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "此斗开天长出来，内藏天地按叁才\n");
		set("unit", "件");
		set("owner_name","痴梦仙姑");
		set("owner_id","chi meng");
	}
}

