/* <SecCrypt CPL V3R05> */

inherit ITEM;

void create()
{
	set_name("�������֮��", ({"tiaobo book", "book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name": "tiaobo",
			"sen_cost": 20,
			"difficulty": 20,
			"max_skill":120,
		]) );
	}
}
