// jueqing-bian.c
// 痴心情长剑法
// Juney: 07/04/97: Genesis.
/*痴心情长剑为白晶晶所创，剑法缠绵如丝，如歌如泣，直叫人生死相许。
*/
//情投意合展欢颜 突来横祸阴阳隔 朝朝暮暮频思忆 千里婵娟只是空
//生生世世长相伴 却恨天公不作美 聚日无多相思苦 此恨绵绵无绝期
//黯然神伤泪满面 愿人长久空遗恨 今世未能偕白头 来生还盼续前缘
//此情不移坚似钢 质问天公不开眼 痴痴伤怀动情时 但舞痴心情长剑 

inherit SKILL;
#include <ansi.h>
mapping *action =
({
	([
		"skill_name" : "情投意合展欢颜",
		"action":     "$N使一式"HIC"『情投意合展欢颜』"NOR"，面露微笑，手中$w一抖，剑光
暴长，洒向$n的$l",
		"dodge":   10,
		"parry" : 0,
		"force": 30,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "突来横祸阴阳隔",
		"action":     "$N使一式"HIC"『突来横祸阴阳隔』"NOR"，身形骤闪，剑招陡变，手中$w
从一个绝想不到的方位斜斜刺向$n的$l",
		"dodge":   15,
        "parry" : 10,
        "force": 40,
		"damage_type":  "刺伤"
	]),
   ([
		"skill_name" : "朝朝暮暮频思忆",
		"action": "$N使一式"HIC"『朝朝暮暮频思忆』"NOR"，暴退数尺，低首抚剑片刻，随
后手中$w骤然穿上，刺向$n的$l",
		"dodge":   -10,
		"parry" : 10,
        "force": 50,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "千里婵娟只是空",
		"action": "$N使一式"HIC"『千里婵娟只是空』"NOR"，身形一晃，疾掠而上，手中$w
龙吟一声，对准$n的$l连递数剑",
		"dodge":   10,
		"parry" : -10,
		"force": 35,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "生生世世长相伴",
		"action": "$N使一式"HIC"『生生世世长相伴』"NOR"，一闪而上扑向$n，如影相随，
手中$w“铮”然有声，往$n的$l刺去",
		"dodge":   20,
        "parry" : -15,
        "force": 70,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "却恨天公不作美",
		"action": "$N使一式"+HIC"『却恨天公不作美』"NOR+"，一个侧身，手中$w疾往斜上挑
起，直指$n的$l",
		"dodge":   0,
        "parry" : 10,
        "force": 55,
		"damage_type":  "刺伤"
	]),
	(["skill_name" : "聚日无多相思苦",
	"action": "$N使一式"+HIC"『聚日无多相思苦』"NOR+"，微微一个转身，手中$w却已自
肋下穿出，罩向$n的$l",
		"dodge":  -10,
        "parry" : 10,
        "force": 30,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "此恨绵绵无绝期",
		"action": "$N使一式"+HIC"『此恨绵绵无绝期』"NOR+"，神色微变，剑招陡然变得凌厉无
比，手中$w如匹链般洒向$n的$l",
		"dodge":  10,
        "parry" : 10,
        "force": 60,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "愿人长久空遗恨",
		"action": "$N使一式"+HIC"『愿人长久空遗恨』"NOR+"，腾身飞跃，手中$w于半空中闪下，
化作一道白色长弧洒向$n的$l",
		"dodge":   30,
        "parry" : 10,
        "force": 50,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "今世未能偕白头",
		"action": "$N使一式"+HIC"『今世未能偕白头』"NOR+"，矮身侧步，手中$w反手疾挑而出，
“唰”的一声往$n的$l刺去",
		"dodge":   65,
        "parry" : 10,
        "force": 60,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "来生还盼续前缘",
		"action": "$N使一式"+HIC"『来生还盼续前缘』"NOR+"，蓦地疾退一步，又冲前三步，手中
$w化为光弧往$n的$l刺去",
		"dodge":   40,
        "parry" : 10,
        "force": 40,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "此情不移坚似钢",
		"action": "$N使一式"+HIC"『此情不移坚似钢』"NOR+"，纵身跃起，不见踪影，接着却又从
半空中穿下，双手握着$w，声势逼人地刺向$n的$l",
		"dodge":   60,
        "parry" : 10,
        "force": 90,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "质问天公不开眼",
		"action":     "$N使一式"+HIC"『质问天公不开眼』"NOR+"，手中$w“嗤”的一声斜刺向天空，
随即向下“唰唰”两下，划出一个叉字，往$n的$l刺去",
		"dodge":   45,
        "parry" : 10,
        "force": 40,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "痴痴伤怀动情时",
		"action": "$N使一式"+HIC"『痴痴伤怀动情时』"NOR+"，左腿微抬，手中$w自下方挑起，
激起一股劲风反挑$n的$l",
		"dodge":   50,
        "parry" : 10,
        "force": 40,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "但舞痴心情长剑",
		"action": "$N倾尽全力舞出"+HIC"『但舞痴心情长剑』"NOR+"，神色十分激动，眼中泪珠
滚动，手中$w疾舞不停，全身都已笼罩在迫人的剑气中，$n不由骇然，只见$N
身形微变，无数道剑气已逼向$n的$l",
		"dodge":   70,
        "parry" : 10,
        "force": 50,
		"damage_type":  "刺伤"
	]),
	([
		"skill_name" : "黯然神伤泪满面",
		"action": "$N使一式"+HIC"『黯然神伤泪满面』"NOR+"，缓缓低首，暗自叹了口气，眼中
莹光流动，接着手中$w中宫直进，迅捷无比地往$n的$l刺去",
		"dodge":  20,
        "parry" : 10,
        "force": 120,
		"damage_type":  "刺伤"
	])
});

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
	object ob;

	if (me->query("gender") != "女性")
		return notify_fail("只有女性才能领悟到痴心情长剑法的神髓！\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，无法学习痴心情长剑法。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习痴心情长剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
		return notify_fail("你的九阴心法为尚浅，没法学痴心情长剑！\n");
	if ((int)me->query_skill("yueying-wubu", 1) < 20)
		return notify_fail("你的月影舞步修为尚浅，没法学痴心情长剑！\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query_temp("CXJ_perform");
	if( !me->query_temp("CXJ_perform")) {
		return action[random(sizeof(action)-1)];
	}else {
		return action[i];
	}
}

int practice_skill(object me)
{
    object weapon;
    if (me->query("gender") != "女性")
		return notify_fail("只有女性才能学会痴心情长剑！\n");
    if (!objectp(weapon = me->query_temp("weapon")) ||
	(string)(weapon->query("skill_type")) != "sword")
	return notify_fail("你这才想起手里没剑，怎么练痴心情长剑啊？ :)\n");
	if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("痴心情长剑法必须配合盘丝洞的九阴心法才能练。\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
	if ((int)me->query("force") < 15)
		return notify_fail("你内力不足，强练痴心情长剑法有走火入魔的危险。\n");
    me->receive_damage("kee", 30);
	me->add("force", -15);
	message_vision(HIM"『痴痴伤怀动情时,但舞痴心情长剑』"NOR"$N倾情舞了一遍痴心情长剑。\n", me);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟痴心情长剑。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟痴心情长剑。\n");
	return 1;
}

void skill_improved(object me)
{
	if( (int)me->query_skill("chixin-jian", 1)  % 10 == 0 )
	{
		tell_object(me,RED "\n你突然觉得心头一阵烦恶，只觉得想杀人....\n\n" NOR);
		me->add("bellicosity", 50);
	}
}

string perform_action_file(string action)
{
        return CLASS_D("pansi") + "/chixin-jian/" + action;
}
