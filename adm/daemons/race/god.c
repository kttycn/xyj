// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N手一指，一道白光直击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N口喝一声：大胆狂徒！只见一只巨雕忽然出现，向$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":		"$N念念有词，身子一动也不动，$n的$l却忽然象是被人踢了一脚",
		"damage_type":	"瘀伤",
	]),
});

void create()
{
	seteuid(getuid());
}

void setup_human(object ob)
{
	mapping my;
	int  qi, shen;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;

	if( undefinedp(my["str"]) ) my["str"] = random(21) + 50;
	if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 50;
	if( undefinedp(my["int"]) ) my["int"] = random(21) + 50;
	if( undefinedp(my["spi"]) ) my["spi"] = random(21) + 50;
	if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 50;
	if( undefinedp(my["per"]) ) my["per"] = random(21) + 50;
	if( undefinedp(my["con"]) ) my["con"] = random(21) + 50;
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 50;

	qi= (my["con"]+my["str"])/2;
	shen= (my["spi"]+my["int"])/2;

	if( userp(ob) || undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 14 ) my["max_gin"] = 500;
		else if( my["age"] <= 30 ) my["max_gin"] = 500 + (my["age"] - 14) * my["spi"];
		else my["max_gin"] = 500 + 16 * my["spi"];

		if( my["max_atman"] > 1000 ) my["max_gin"] += 250;
		//here max_atman>1000 is no use.
		else if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;
		if(my["max_gin"]<1) my["max_gin"]=1;//mon 1/28/98
	}
	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		if( my["age"] <= 14 ) my["max_kee"] = 50*qi;
		else if( my["age"] <= 30 ) my["max_kee"] = (my["age"] - 4) * qi;
		else my["max_kee"] = 130 * qi; 
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] * 2;

		if(my["max_kee"]<1) my["max_kee"]=1;//mon 1/28/98
	}
	if( userp(ob) || undefinedp(my["max_sen"]) ) {
		if( my["age"] <= 14 ) my["max_sen"] = 50*shen;
		else if( my["age"] <= 30 ) my["max_sen"] = (my["age"] - 4) *
		shen;
		else my["max_sen"] = 26 * shen;
		if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"] * 2;
		if(my["max_sen"]<1) my["max_sen"]=1;//mon 1/28/98
	}

	if( undefinedp(my["unit"])) my["unit"]="位";
	if( undefinedp(my["gender"])) my["gender"]="男性";
	if( undefinedp(my["can_speak"])) my["can_speak"]=1;
	if( undefinedp(my["attitude"])) my["attitude"]="peaceful";
	if( undefinedp(my["limbs"])) my["limbs"]=({
		"头部",	"颈部",	"胸口",	"后心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
	}) ;

//	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 10000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
