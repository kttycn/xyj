#include <ansi.h>

inherit F_CLEAN_UP;

mapping sx_name=([
	"jin" : HIY"金系"NOR,
	"mu"  : HIG"木系"NOR,
	"shui": HIC"水系"NOR,
	"huo" : HIR"火系"NOR,
	"tu"  : YEL"土系"NOR,
]);

int main(object me,string arg)
{
	object ob, env=environment(me);
	int mana_cost;
	int sen_cost;
	string msg, mana_sx;

	if(env->query("no_fight") || env->query("no_magic") )
		return notify_fail("安全区内不能用地耳灵。\n");
	if(!arg) 
		return notify_fail("你想打听谁的状态？\n");
	if((int)me->query("combat_exp")<5000)
		return notify_fail("你的道行不够，用不了地耳灵。\n");
	if((int)me->query("mana")<60) 
		return notify_fail("你的法力不够，用不了地耳灵。\n");
	if((int)me->query("sen")<=50)
		return notify_fail("你现在太累了，休息休息吧！\n");
	mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
	mana_cost=mana_cost+10;
	if(mana_cost > -50) mana_cost=-50;
	me->add("mana", mana_cost);
	sen_cost=50;
	message_vision(HIY "$N口中念了几句咒文，眼中突然精光一闪，大喝一声“顺风耳何在！”\n只听嘿嘿几声奸笑，不知从哪里钻出来一个肥头大耳的家伙，在$N耳边低声说了几句话。\n" NOR, me);
	ob = find_player(arg);
	if(!ob) {
	    ob=present(arg,environment(this_player()));
	    if(ob && !living(ob)) ob=0;
	}
	if( !ob ) ob = find_living(arg);
	if(!ob || (ob->query("env/invisibility") && wizardp(ob) ))
		return notify_fail("顺风耳告诉你：奇怪，找不到这个人．．．\n");
	if((int)ob->query("age") <= 16 && userp(ob) && ob!=me)
		return notify_fail("顺风耳告诉你：你竟要我去打听小孩子，有没有搞错！\n");
	if( wizardp(ob) && !wizardp(me) && userp(me) )
		return notify_fail("顺风耳稀里哗啦吐了一地，说道：连巫师你也想查！\n");
	
        write("顺风耳告诉你："+ob->query("name")+"的道行已达"+RANK_D->describe_dx((int)ob->query("daoxing"))+"的境界。\n");  
	write("顺风耳告诉你："+ob->query("name")+"的武功已达"+RANK_D->describe_exp((int)ob->query("combat_exp"))+"的境界。\n");
	write("顺风耳告诉你："+ob->query("name")+"的法力修为已达"+RANK_D->describe_fali((int)ob->query("max_mana"))+"的境界。\n");	
	write("顺风耳告诉你："+ob->query("name")+"的内力修为已有"+RANK_D->describe_neili((int)ob->query("max_force"))+"的火候。\n");	
/*	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)ob->query("daoxing") ) ) 
	> RANK_D->grade_dx(HIB "元神初具" NOR) )
	{
		if(ob->query("family/family_name"))
			write("顺风耳告诉你："+ob->query("name")+"好象是"+ob->query("family/family_name")+"的弟子。\n");
		else write("顺风耳告诉你："+ob->query("name")+"好象天地不管，鬼神不收，他没有门派耶！\n");
	}
*/
	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
	> RANK_D->grade_dx(HIB "渐入佳境" NOR) )
	{
		if( !ob->query_skill_mapped("spells") )
			write("顺风耳告诉你："+ob->query("name")+"好象并没有使用任何具有五行相生相克之理的法术！\n");
		else
		{
			switch( ob->query_skill_mapped("spells") )
			{
				case "buddhism":
					mana_sx = "tu";
					break;
				case "dao":
					mana_sx = "mu";
					break;
				case "moonshentong":
					mana_sx = "shui";
					break;
				case "seashentong":
					mana_sx = "shui";
					break;
				case "gouhunshu":
					mana_sx = "shui";
					break;
				case "yaofa":
					mana_sx = "tu";
					break;
				case "pingtian-dafa":
					mana_sx = "huo";
					break;
				case "dengxian-dafa":
					mana_sx = "mu";
					break;
				case "taiyi":
					mana_sx = "huo";
					break;
				case "taoism":
					mana_sx = "jin";
					break;
				case "baguazhou":
					mana_sx = "mu";
					break;
				case "pansi-dafa":
					mana_sx = "tu";
					break;
				case "feisheng-spells":
					mana_sx = "jin";
					break;
				case "fumozhou":
					mana_sx = "jin";
					break;
				case "yufeng-shu":
					mana_sx = "huo";
					break;
				case "xuanhu-shentong":
					mana_sx = "jin";
					break;
			}
//		write(ob->query_skill_mapped("spells")+"\n");
			write("顺风耳告诉你："+ob->query("name")+"好象用的是"+sx_name[mana_sx]+"法术。\n");
		}
	}
	message_vision("$N忽然莫名其妙地哆嗦了一下。\n",ob); 
	msg="你急忙掐指一算，";
	if(ob->query("daoxing")>me->query("daoxing")/5)
		msg+="原来是"+me->name()+"("+me->query("id")+")"+
			"正在打听你的道行。\n";
	else
		msg+="心中却只是一片茫然。\n";
	tell_object(ob, msg);

	return 1;
}

int help(object me)
{
	string desc_dx, desc_fali, desc_exp;

	write(@HELP
指令格式 : check|cha [<某人>]

地耳灵: 打听别人现在的道行,法力及武功级别。

HELP
    );

	write("道行境界：\n\n");
	write(RANK_D->query_description(0));
	write("\n武学境界：\n\n");
	write(RANK_D->query_description(1));
	write("\n法力修为：\n\n");
	write(RANK_D->query_description(2));
	write("\n\n");	
		
    return 1;
}

