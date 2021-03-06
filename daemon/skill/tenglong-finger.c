// tenglong-finger.c 阴阳腾龙指

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([     "action" : HIM"$N两手外伸，双掌运出八成刚劲由外向内一合，漫天气劲将空气一压一放，立即带出了隐隐雷声，气劲随着$N的手，霎时往$n前方三公尺内集中"NOR,
        "force" : 10,
       "dodge" : 10,
        "parry" : 10,
       "damage" :100,
       "lvl" : 0,
        "damage_type" : "内伤"
]),
([      "action" : HIW"$N两掌一扬，一掌刚、一掌柔，阴阳两股力道向着$n直放了出去。。"NOR,
        "force" : 20,
       "dodge" : 10,
        "parry"    :   5,
            "damage" : 140,
        "lvl" : 10,
        "damage_type" : "内伤"
]),
([      "action" : HIG"$N两掌一出，阴阳两劲随掌向外而冲，两种劲力居然未能融合为一，正巧让敌人由劲力中间的缝隙穿入，却见$n在半空中急旋了起来"NOR,
        "force" : 40,
        "dodge" : -5,
        "parry"    :   10,
        "damage" : 180,
        "lvl" : 20,
        "damage_type" : "内伤"
]),
([      "action" : HIC"$N双掌一圈，刚柔分流，阴阳两劲由左右双掌奔腾而出；$n懵然不知，双掌聚力迎了 过来，与阴阳两劲一接，当场一掌击空，不受控制的旋转起来"NOR,
        "force" : 60,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 200,
        "lvl" : 30,
        "damage_type" : "内伤"
]),
([      "action" : HIY"$N双掌一凝，全力向上一送，四阴六阳，两股掌力破空而上，这时两股气劲已经急旋了起来，轰然一声爆响，炸向$n"NOR,
        "force" : 80,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 220,
        "lvl" : 40,
        "damage_type" : "内伤"
]),
([      "action" : HIB"$N体内阴阳劲力忽然分流，各循一掌奔腾而出，同时将双手往内一折，两劲一接触，随即开始交缠起来，攻向$n"NOR,
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" :230,
        "lvl" : 60,
        "damage_type" : "内伤"
]),
([      "action" : HIR"$N心念电转，一面抽身往后飞退，一面两掌全力推出劲力，光影散发成罩，牢牢的罩住$n"NOR,
        "force" : 120,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 290,
        "lvl" : 80,
        "damage_type" : "内伤"
]),
([     "action" : HIM"$N怒极大吼一声，十指同现光华，腾龙指向外四散，$n却见四面一片气劲织成的光网，连忙惊啸一声的折往上飞"NOR,
        "force" : 140,
       "dodge" : 10,
        "parry" : 10,
       "damage" :320,
       "lvl" : 100,
        "damage_type" : "内伤"
]),
([      "action" : HIW"$N左手腾龙指突发，一道光柱由食指冲出，直穿$n的$l"NOR,
        "force" : 160,
       "dodge" : 10,
        "parry"    :   5,
            "damage" : 340,
        "lvl" : 120,
        "damage_type" : "内伤"
]),
([      "action" : HIG"$N腾龙指立即发出，一道柱状光华转眼飞射十公尺，穿过$n的额头"NOR,
        "force" : 180,
        "dodge" : -5,
        "parry"    :   10,
        "damage" : 380,
        "lvl" : 140,
        "damage_type" : "内伤"
]),
([      "action" : HIC"$N连点八指，八道光华分头而出，将$n的劲流震散"NOR,
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 400,
        "lvl" : 160,
        "damage_type" : "内伤"
]),
([      "action" : HIY"$N腾龙指一出，沉雷般的震响随之而起，一道光柱矫腾如龙的往$n扑去"NOR,
        "force" : 220,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 420,
        "lvl" : 180,
        "damage_type" : "内伤"
]),
([      "action" : HIB"$N平伸约九掌蕙然往上一扬，一道光柱翻腾如能一般的往$n直迎过去，两方劲力相击，一神串的气爆声立即不断传出"NOR,
        "force" : 240,
        "dodge" : 15,
        "parry" : 15,
        "damage" :440,
        "lvl" : 200,
        "damage_type" : "内伤"
]),
([      "action" : HIR"$N两掌忽然放大一倍，呈现铁青色，一上一下的挡在胸前，便顶一击，只听当的一声传出，那股刀形内息四面溢散"NOR,
        "force" : 300,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 500,
        "lvl" : 250,
        "damage_type" : "内伤"
]),
});


int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry";
}

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 500)
		return notify_fail("你的气息不够。\n");
	if ((int)me->query_skill("wuzu-xinfa", 1) < 80)
		return notify_fail("你的无祖心法火候太浅。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tenglong-finger",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练腾龙指不能用武器。\n");
	if (((int)me->query("kee") < 100) || (int)me->query("sen")<60)
		return notify_fail("你的体力不能练腾龙指。\n");
	me->receive_damage("kee", random(80));
	me->receive_damage("sen", random(40));
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟腾龙指。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟腾龙指。\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("phoenix") + "/tenglong-finger/" + action;
}


