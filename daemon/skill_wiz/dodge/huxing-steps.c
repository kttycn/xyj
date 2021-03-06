// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit SKILL;

string *dodge_msg = ({
        "$n一式「天外飞狐」身形急转，跃了起来．\n",
   "$n一伏身，身体象泥鳅一般，滑出两丈开外。\n",
   "只见$n身体一晃，一个「神狐再现」，轻轻的躲开。\n",
   "$n一声狐鸣，$N顿时举手无措，$n趁机闪在一旁。\n",
"$n忽然对$N一声媚笑，$N顿时忘记了自己身处战斗之中。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("你的气或内力不够，不能练雁行步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60)
		return notify_fail("你现在脚下虚浮，先休息一阵吧。\n");
	if( (int)me->query("sen") < 60)
		return notify_fail("你的精神无法集中了，休息一下再进行参悟吧。\n");
	if((int)me->query("force") < 6 )
		return notify_fail("你现在内力不够，难以继续参悟下去了。\n");
	me->receive_damage("kee", 60);
	me->add("force", -6);
	return 1;
}
