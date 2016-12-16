inherit F_CLEAN_UP;
int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, string dir, string text);
#define SCORE_COST 2000
#define GOLD_COST  500
#define MIN_EXP	5000000
#define MIN_DX	5000000
int main(object me, string arg)
{
	int flag;
	string stitle;
	string ltitle;
	string dir;
	object env;
	object gold;
	seteuid(getuid());
	if(!arg || sscanf(arg,"%s %s",dir,stitle) != 2)
		return notify_fail("指令格式：　buildrest north 天地阁休息室 \n");
	if(me->query("family/privs") != -1) 
		return notify_fail("你没有这种权力。\n");
	if((int)me->query("score") < SCORE_COST)
		return notify_fail("你的三界评价不够"+chinese_number(SCORE_COST)+
		"点。\n");
	if((int)me->query("combat_exp") < MIN_EXP)
		return notify_fail("你的实战经验不够"+chinese_number(MIN_EXP)+
		"点。\n");
	if((int)me->query("daoxing") < MIN_DX)
		return notify_fail("你的道行不够"+chinese_number(MIN_EXP)+
	"点。\n");
	gold = present("gold-coin_money",me);
	if(!gold) return notify_fail("你身上没有带月影金币。\n");
	if((int) gold->query_amount() < GOLD_COST)
	return notify_fail("你身上没有"+chinese_number(GOLD_COST)+"枚月影金币。\n");
	env = environment(me);
	if((int)me->query("rest_room") > 0)
		return notify_fail("你不可再建休息室了！\n");
	if(!env->query("owner") && (string)env->query("owner") != (string) me->query("id"))
		return notify_fail("你不可在这建休息室！\n");
	if(check_legal_name(stitle))
		me->edit( (: enter_desc , me,gold, stitle, dir :) );
	return 1;
	
}
void enter_desc(object me,object gold, string s_title,string dir,string text)
{
string *direc= ({"north", "south", "east", "west", "northup", 
"southup", "eastup", "westup", "northdown",
"southdown", "eastdown", "westdown", "northeast", 
"northwest", "southeast", "southwest", "up", "down"});
	int i;
	int record = 2;
	int okey=0;
	object env;
	if(!check_legal_long(text)) return;
	for (i = 0; i < sizeof(direc); i++)
	if(direc[i] == dir) {okey=1; break;}
	if(okey)	
	{
	env = environment(me);
	if(env->query("exits/"+dir))
		{
		tell_object(me,"这个方向已经有房屋了！\n");
		return;
		}
// I think by now, we should checked all conditions,
// deduct the cost and go build it!
		gold->add_amount(-GOLD_COST);
		me->add("score",-SCORE_COST);
		BR_D->buildroom(me,s_title,text,dir,record);
	}
	else
	{
	tell_object(me,"你要往哪个方向建？\n");
	return;
	}
}
int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 20 ) ) {
		write("对不起，中文名字必须是一到十个中文字。\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("对不起，中文名字不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("对不起，名字必需是中文。\n");
			return 0;
		}
	}
	return 1;
}
int check_legal_long(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 60) || (strlen(name) > 200 ) ) {
		write("对不起，中文描述必须是三十到一百个中文字。\n");
		return 0;
	}
	while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
		if( name[i]<' ' ) {
			write("对不起，中文描述不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("对不起，描述必需是中文。\n");
			return 0;
		}
	}
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: buildrest <讯息>
用来给自己的帮派加一间休息室 

HELP
	);
	return 1;
}
