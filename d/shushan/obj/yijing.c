inherit ITEM;
void create()
{
	set_name( "〖蜀山仙术〗", ({ "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "上面写了密密麻麻的字,看来象是一本关于蜀山天师仙法的书。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name": "taoism",
			"dx_required": 1000,
			"sen_cost": 30,
			"difficulty": 30,
			"max_skill": 50,
		]) );
	}
}

