// literate.c

inherit ITEM;

void create()
{
	set_name("〖舞戟图〗", ({"wuji tu", "tu", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 0);
		set("no_sell", 1);
		set("no_put", 1);
		set("no_give", 1);
		set("long","一张画有各色舞戟小人的锦纶。\n");
		set("material", "paper");
		set("skill", ([
			"name": "halberd",
			"dx_required": 40000,
			"sen_cost": 40,
			"difficulty": 40,
			"max_skill": 100,
		]) );
	}
}

