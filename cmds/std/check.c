#include <ansi.h>

inherit F_CLEAN_UP;

mapping sx_name=([
	"jin" : HIY"��ϵ"NOR,
	"mu"  : HIG"ľϵ"NOR,
	"shui": HIC"ˮϵ"NOR,
	"huo" : HIR"��ϵ"NOR,
	"tu"  : YEL"��ϵ"NOR,
]);

int main(object me,string arg)
{
	object ob, env=environment(me);
	int mana_cost;
	int sen_cost;
	string msg, mana_sx;

	if(env->query("no_fight") || env->query("no_magic") )
		return notify_fail("��ȫ���ڲ����õض��顣\n");
	if(!arg) 
		return notify_fail("�������˭��״̬��\n");
	if((int)me->query("combat_exp")<5000)
		return notify_fail("��ĵ��в������ò��˵ض��顣\n");
	if((int)me->query("mana")<60) 
		return notify_fail("��ķ����������ò��˵ض��顣\n");
	if((int)me->query("sen")<=50)
		return notify_fail("������̫���ˣ���Ϣ��Ϣ�ɣ�\n");
	mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
	mana_cost=mana_cost+10;
	if(mana_cost > -50) mana_cost=-50;
	me->add("mana", mana_cost);
	sen_cost=50;
	message_vision(HIY "$N�������˼������ģ�����ͻȻ����һ�������һ����˳������ڣ���\nֻ���ٺټ�����Ц����֪�����������һ����ͷ����ļһ��$N���ߵ���˵�˼��仰��\n" NOR, me);
	ob = find_player(arg);
	if(!ob) {
	    ob=present(arg,environment(this_player()));
	    if(ob && !living(ob)) ob=0;
	}
	if( !ob ) ob = find_living(arg);
	if(!ob || (ob->query("env/invisibility") && wizardp(ob) ))
		return notify_fail("˳��������㣺��֣��Ҳ�������ˣ�����\n");
	if((int)ob->query("age") <= 16 && userp(ob) && ob!=me)
		return notify_fail("˳��������㣺�㾹Ҫ��ȥ����С���ӣ���û�и��\n");
	if( wizardp(ob) && !wizardp(me) && userp(me) )
		return notify_fail("˳���ϡ�ﻩ������һ�أ�˵��������ʦ��Ҳ��飡\n");
	
        write("˳��������㣺"+ob->query("name")+"�ĵ����Ѵ�"+RANK_D->describe_dx((int)ob->query("daoxing"))+"�ľ��硣\n");  
	write("˳��������㣺"+ob->query("name")+"���书�Ѵ�"+RANK_D->describe_exp((int)ob->query("combat_exp"))+"�ľ��硣\n");
	write("˳��������㣺"+ob->query("name")+"�ķ�����Ϊ�Ѵ�"+RANK_D->describe_fali((int)ob->query("max_mana"))+"�ľ��硣\n");	
	write("˳��������㣺"+ob->query("name")+"��������Ϊ����"+RANK_D->describe_neili((int)ob->query("max_force"))+"�Ļ��\n");	
/*	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)ob->query("daoxing") ) ) 
	> RANK_D->grade_dx(HIB "Ԫ�����" NOR) )
	{
		if(ob->query("family/family_name"))
			write("˳��������㣺"+ob->query("name")+"������"+ob->query("family/family_name")+"�ĵ��ӡ�\n");
		else write("˳��������㣺"+ob->query("name")+"������ز��ܣ������գ���û������Ү��\n");
	}
*/
	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
	> RANK_D->grade_dx(HIB "����Ѿ�" NOR) )
	{
		if( !ob->query_skill_mapped("spells") )
			write("˳��������㣺"+ob->query("name")+"����û��ʹ���κξ��������������֮��ķ�����\n");
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
			write("˳��������㣺"+ob->query("name")+"�����õ���"+sx_name[mana_sx]+"������\n");
		}
	}
	message_vision("$N��ȻĪ������ض�����һ�¡�\n",ob); 
	msg="�㼱æ��ָһ�㣬";
	if(ob->query("daoxing")>me->query("daoxing")/5)
		msg+="ԭ����"+me->name()+"("+me->query("id")+")"+
			"���ڴ�����ĵ��С�\n";
	else
		msg+="����ȴֻ��һƬãȻ��\n";
	tell_object(ob, msg);

	return 1;
}

int help(object me)
{
	string desc_dx, desc_fali, desc_exp;

	write(@HELP
ָ���ʽ : check|cha [<ĳ��>]

�ض���: �����������ڵĵ���,�������书����

HELP
    );

	write("���о��磺\n\n");
	write(RANK_D->query_description(0));
	write("\n��ѧ���磺\n\n");
	write(RANK_D->query_description(1));
	write("\n������Ϊ��\n\n");
	write(RANK_D->query_description(2));
	write("\n\n");	
		
    return 1;
}

