// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

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

string skill_level(string, int);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, str;
	int i, j;
	str = "";

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的技能？\n");
	}
	if( ob!=me && ob->query("env/invisibility")&&!wizardp(me) )
		return notify_fail("你要察看谁的技能？\n");

	if( ob!=me && !wizardp(me) 
	&& !ob->is_apprentice_of(me) 
	&& !me->is_apprentice_of(ob) 
	&& getuid(ob)!=me->query("bonze/dadangid")
	&& getuid(ob)!=me->query("couple/id"))
		return notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
	j = (int)sizeof(skl);
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( (ob==me ? HIR"你" : ob->name()) + "目前所掌握的技能有："NOR);

	str = "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		str = sprintf("%s%s%s%-40s" NOR " - %-10s %3d/%5d\n", str,
			(member_array(sname[i], mapped)==-1? "  ": HIR"★"NOR),
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			SKILL_D(sname[i])->level_description(skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	str += "━━━━━━━━━━━━━━━━━━━━  "MAG"月影奇缘"NOR"  ━━━━━━━\n";
	str += "\n					 "HIR"目前共学会 "+HIW""+ chinese_number(j) + ""HIR" 种技能" NOR;
	write("\n");
	this_player()->start_more(str);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : skills|jineng [<某人>]

这个指令可以让你查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
