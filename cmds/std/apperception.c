// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;
int check_valid_create(string arg);

int main(object me, string arg)
{
	int skill, amount, qskill, qlearned, upper;

	seteuid(getuid());

//	if( !environment(me)->query("canwu") )
//		return notify_fail("这里不是参悟的地方。\n");

	if( !arg )
		return notify_fail("你要参悟什么？(apperception <技能名称>)\n");

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	skill = me->query_skill(arg, 1);

	if(!check_valid_create(arg) && !me->query("guild") )
	{
		return notify_fail("这不是你创建的功夫呀？\n");
	}
	if( me->is_busy() )
		return notify_fail("你现在很忙，不能练习。\n");

	if( !arg ) return (__DIR__"skills")->main(me, arg);

	if( skill < 1 )
		return notify_fail("瞎参悟什么呀，你对这方面的技能还是一窍不通呢！\n");

	if(skill<250)
		return notify_fail(CYN"你对「"+to_chinese(arg)+"」的理解还不足以让你参悟到更深层次的东西。\n"NOR);

	if( (string)SKILL_D(arg)->type()=="martial" && 
	skill*skill*skill/10 > (int)me->query("combat_exp") )
		return notify_fail("你的武学修为还没到这个境界，参悟得再多也没用。\n");
	else if( (string)SKILL_D(arg)->type()=="magic" && 
	skill*skill*skill/10 > (int)me->query("daoxing") )
		return notify_fail("你的道行修为还没到这个境界，参悟得再多也没用。\n");

	upper= (int)me->query("potential")-(int)me->query("learned_points");
	if(upper<10)
		return notify_fail("你的潜能已经发挥到极限了，没有办法再继续进行参悟武学了。\n");

	if(MISC_D->random_capture(me,20000,0)) return 1;

	if(!skill) {
		qskill=1; qlearned=0; amount=0;
	} else {
		qskill=me->query_skills()[skill]+1;
		qskill*=qskill;
		qlearned=me->query_learned()[skill];
		amount = qlearned;
	}
	amount += random(me->query_int())+1;
	amount -= qlearned;

	notify_fail("你试着参悟" + to_chinese(arg) + "，但是并没有任何进步。\n");

        //added by mon. 7/24/97
	if( SKILL_D(arg)->apperception_skill(me) ) {
		me->improve_skill(arg, amount,(qlearned<2*qskill) ?0:1);
		me->add("learned_points", 10);
		write( HIY "你的" + to_chinese(arg) + "进步了！\n" NOR);
		me->start_busy(1);
		return 1;
	}
	else return 0;
}

int check_valid_create(string arg)
{
	string file,*list,playername;
	object me;

	me=this_player();
	file=read_file(SKILL_D(arg+".c"));
	if(!file) 
		return 0;
	list = explode(file, "\n");
	playername=geteuid(me);

	if(list[0]=="// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由swallow@xjqy修改")
	{
		if(list[1]=="// "+playername) return 1;
		else return 0;
	}
	return 1;
}

int help(object me)
{
	write(@TEXT
指令格式：apperception|canwu <技能种类>

这个指令让你参悟某个种类的技能，这个技能的等级必须在250级以上。而且
你已经开帮立派成为一派宗主。

如果你该项的技能足够高，可以经由参悟来直接升级，每进行一次参悟损耗10
点潜能。而且升级的上限只跟你从实际运用中获得足够的经验有关。
TEXT
	);
	return 1;
}
