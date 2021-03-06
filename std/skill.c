//Cracked by Roath
//	skill.c
//
// 	This is the standard skill daemon object. All objects defining a skill
//	should inherit this as its skeleton.

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.

int valid_learn(object me) { return 1; }

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
		return 1;
}

// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )。
// Currently we have only 2 types of skill: "martial" and "knowledge".

string type() { return "martial"; }

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>]). When <target> is not present,
// use the character himself as default.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 

int exert_function(object me, string arg)
{
	string func, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else {
		func = arg;
		target_ob = me;
	}

	if( !stringp(file = (string)this_object()->exert_function_file(func))
	||	file_size(file + ".c") <= 0 )
		return 0;
//	tell_object(me,func);
	me->set_temp("kill_msg","exert_"+func);
	return (int)call_other( file, "exert", me, target_ob);
}

int perform_action(object me, string arg)
{
	string action, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", action, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else {
		action = arg;
	}

	if( !stringp(file = (string)this_object()->perform_action_file(action))
	||	file_size(file + ".c") <= 0 ) {
	   // write(file+" "+file_size(file + ".c"));
		return 0;
	}

	//write(file);
	me->set_temp("kill_msg","perform_"+action);
	return (int)call_other( file, "perform", me, target_ob);
}

int cast_spell(object me, string spell, object target)
{
	string file;

//	notify_fail("你所选用的咒文系中没有这种咒文。\n");

	if( !stringp(file = (string)this_object()->cast_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;
	me->set_temp("kill_msg","cast_"+spell);
	return (int)call_other( file, "cast", me, target);
}

int conjure_magic(object me, string spell, object target)
{
	string file;

	notify_fail("你所选用的法术系中没有这种法术。\n");

	if( !stringp(file = (string)this_object()->conjure_magic_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;
	me->set_temp("kill_msg","conjure"+spell);
	return (int)call_other( file, "conjure", me, target);
}

int scribe_spell(object me, object ob, string spell)
{
	string file;

	if( !stringp(file = (string)this_object()->scribe_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;
	me->set_temp("kill_msg","scribe"+spell);
	return (int)call_other( file, "scribe", me, ob );
}

//weiqi, 981115
//string level_description(int level)
//this function is to allow customerized description of skill level...
//just override this default one.
string level_description(int level)
{
	int grade;
/*	string *skill_level_desc = ({
		BLU "初学乍练" NOR,
		BLU "初窥门径" NOR,
		HIB "粗通皮毛" NOR,
		HIB "略知一二" NOR,
		YEL "半生不熟" NOR,
		YEL "马马虎虎" NOR,
		HIY "已有小成" NOR,
		HIY "渐入佳境" NOR,
		HIM "驾轻就熟" NOR,
		HIM "了然于胸" NOR,
		HIR "出类拔萃" NOR,
		HIR "心领神会" NOR,
		MAG "神乎其技" NOR,
		MAG "出神入化" NOR,
		CYN "豁然贯通" NOR,
		CYN "登峰造极" NOR,
		HIC "举世无双" NOR,
		HIC "一代宗师" NOR,
		HIC "震古铄今" NOR,
		HIW "深不可测" NOR
	});
	string *knowledge_level_desc = ({
		BLU "新学乍用" NOR,
		HIB "初窥门径" NOR,
		HIB "略知一二" NOR,
		YEL "马马虎虎" NOR,
		YEL "已有小成" NOR,
		CYN "心领神会" NOR,
		CYN "了然于胸" NOR,
		CYN "豁然贯通" NOR,
		HIC "举世无双" NOR,
		HIC "震古铄今" NOR,
		HIW "深不可测" NOR
	});

	grade = level / 15;
*/
string *skill_level_desc = ({
        BLU "不堪一击" NOR,BLU "毫不足虑" NOR,BLU "不足挂齿" NOR,BLU "初学乍练" NOR,BLU "勉勉强强" NOR,
        HIB "初窥门径" NOR,HIB "初出茅庐" NOR,HIB "略知一二" NOR,HIB "普普通通" NOR,HIB "平平淡淡" NOR,
        CYN "平淡无奇" NOR,CYN "粗通皮毛" NOR,CYN "半生不熟" NOR,CYN "马马虎虎" NOR,CYN "略有小成" NOR,
        HIC "已有小成" NOR,HIC "鹤立鸡群" NOR,HIC "驾轻就熟" NOR,HIC "青出于蓝" NOR,HIC "融会贯通" NOR,
        GRN "心领神会" NOR,GRN "炉火纯青" NOR,GRN "了然于胸" NOR,GRN "略有大成" NOR,GRN "已有大成" NOR,
        YEL "豁然贯通" NOR,YEL "出类拔萃" NOR,YEL "无可匹敌" NOR,YEL "技冠群雄" NOR,YEL "神乎其技" NOR,
        HIY "出神入化" NOR,HIY "非同凡响" NOR,HIY "傲视群雄" NOR,HIY "登峰造极" NOR,HIY "无与伦比" NOR,
        HIM "所向披靡" NOR,HIM "一代宗师" NOR,HIM "精深奥妙" NOR,HIM "神功盖世" NOR,HIM "举世无双" NOR,
        HIR "惊世骇俗" NOR,HIR "撼天动地" NOR,HIR "震古铄今" NOR,HIR "超凡入圣" NOR,HIR "威镇寰宇" NOR,
        RED "空前绝后" NOR,RED "天人合一" NOR,MAG "深藏不露" NOR,WHT "深不可测" NOR,HIW "返璞归真" NOR
});

string *knowledge_level_desc = ({
	BLU "新学乍用" NOR,BLU "初窥门径" NOR,HIB "略知一二" NOR,HIB "半生不熟" NOR,
	CYN "马马虎虎" NOR,CYN "已有小成" NOR,HIC "融会贯通" NOR,HIC "心领神会" NOR,
	GRN "了然於胸" NOR,GRN "已有大成" NOR,YEL "非同凡响" NOR,YEL "举世无双" NOR,
	HIY "震古铄今" NOR,RED "无与伦比" NOR,WHT "超凡入圣" NOR,HIW "空前绝后" NOR,
});

	switch(type()) {
		case "knowledge":
			grade = level / 20;
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			grade = level / 10;
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int sum(int n,int base,int d)
{
	return (n*(2*base+(n-1)*d)/2);
}

int NewRandom(int n,int base,int d)
{ 
	int i = 1;
	int randnum = random(sum(n,base,d));

	if (sum(6,base,d) < randnum)
	{
		i = 7;
		while (sum(i,base,d) < randnum)
			i++;
	}
	else {
		while (sum(i,base,d) < randnum)
			i++;
	} 
	return (i-1);
}
