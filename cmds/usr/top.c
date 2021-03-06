// CMDS USR top.c
// Created by kittt@刀剑笑
// Last modified by kittt@DJX 4/13/2000
// 用于给玩家查看在线玩家的高手排行。MUD_NAME那里如果图形对不上
// 就自己改改啦。给出的score当然可以按自己的想法修改。

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
	
	object *list,*ob;
	int i;
	string msg;

	ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
	list = sort_array(ob, (: top_list :));
	msg =  "\n              ┏ "+BCYN HIW+CHINESE_MUD_NAME+"在线高手排行榜"NOR" ┓\n";
	msg += "┏━━━┯━━┻━━━━━━━┯━━━━┻━┯━━━━┓\n";
	msg += "┃ 名次 │    高        手    │  门    派  │综合评价┃\n";
	msg += "┠───┴──────────┴──────┴────┨\n";
	for (i = 0 ;i < 10 ; i++) {
		if( i >= sizeof(list)) msg += "┃暂时空缺。　　    　　　　　　　　　　　　　　　　　┃\n";
		else {
			if( !list[i] ) continue;
			if( !list[i]->query("id") ) continue;
			if(list[i] == me) msg += BBLU HIY;
			msg += sprintf("┃  %-5s %-22s%-14s %5d  ┃\n"NOR,chinese_number(i+1),list[i]->query("name")+"("+
			list[i]->query("id")+")",
			list[i]->query("family")?list[i]->query("family/family_name"):"普通百姓",
			get_score(list[i]));
		}
	}
	msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	msg += "  " + NATURE_D->game_time() + "记。\n";
	write(msg);
	return 1;

}
int top_list(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score(ob1);
	score2 = get_score(ob2);

	return score2 - score1;
}

int get_score(object ob)
{
	int tlvl,i,score;
	string *ski;
	mapping skills;

    reset_eval_cost();
	skills = ob->query_skills();
	if (!sizeof(skills)) return 1; 
	ski  = keys(skills);
	for(i = 0; i<sizeof(ski); i++) {
		tlvl += skills[ski[i]];
	}  // count total skill levels
 	score = tlvl/10;
	score += ob->query("max_force")/10;
	score += ob->query_str() + ob->query_int() + ob->query_spi() + ob->query_con();
	score += (int)ob->query("combat_exp")/2500;
	score += (int)ob->query("daoxing")/2500;

	return score;
}

int help(object me)
{
write(@HELP
指令格式 : top 
 
这个指令可以让你知道在线十大高手是哪些，别去惹他们。 
 
HELP
    );
    return 1;
}
 
