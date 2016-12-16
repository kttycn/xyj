// 竞速小姐
#include <ansi.h>
#define RaceLength 1000
#define WaitforplayerTime 20

inherit NPC;
inherit __DIR__+"chiplib.c";

void ChoiceNPC();
void raceloop();
void gameover(int target);
void Waitforplayer();
int to_say_play();
int do_see(string arg);
int do_seerace();
int do_stoprace();
int reset();
int reset_player();
int do_reset();
int Check_playerdata();
int Playing;
int Waitstatus;
int Checksum;
string Player;
string PlayerId;

int *NPCRace = ({       // 建议最高 100, 最低 1
		 60,  20,  70,  10,  70,
		 45,  90,  90,  95,  60,
		 85,   5,  75,  85,  60,
		 30,  40, 100,   3, 110,
		 75,  15,  80,  10,  50 });
int *NPCRacingRace = ({ 0,0,0,0,0,0 });
int *BetMutiple = ({ 0,0,0,0,0,0 });
int *RacingLenth = ({ 0,0,0,0,0,0 });
string *NPCName = ({
	"幽魂","天空骑士","默特","艾伦","乔邦飞",
	"星星点光","小熙熙","幸运","剑狂","陆仁贾",
	"天野魂","玩家","猪肉","酷哥","辣妹",
	"开喜婆婆","小丸子","小暴龙","ㄚ丝","恰吉",
	"SM女王","小红帽","樱木花道","ㄚ扁","MTV妹妹" });
string *NPCRacingName = ({ "None","None","None","None","None","None" });

void create()
{
	set_name("雪儿",({ "suet","racing lady","lady" }));
	set("level",9);
	set("title","竞速小姐");
	set("race", "人类");
	set("gender","女性");
	set("age", 19);
	set("long",@LONG
可爱美丽的小姐, 请让她为你下筹码吧. ( ask suet about play )
LONG	);
	set("attitude", "friendly");
	set("inquiry",([
	   "赛跑": (: to_say_play :),
	   "race": (: to_say_play :),
	   "玩法": (: to_say_play :),
	   "play": (: to_say_play :),
	   "规则": (: to_say_play :),
	   "rule": (: to_say_play :),
	]));
	setup();
	seteuid(getuid());
}

void init()
{
	if(this_player()->query_temp("GAME/Xrace/Checksum")!=Checksum)
		reset_player();
	add_action("do_see","see");
	add_action("do_seerace",".");
	add_action("do_bet","bet");
	add_action("do_start","start");
	add_action("do_knpc","k");
	if(wizardp(this_player()))
	{
		add_action("do_stoprace","stoprace");
		add_action("do_reset","r");
	}
}


int do_see(string arg)
{
	object me = this_player();

	if(!arg || arg!="race")
	{
		command("say "+me->query("name")+"，什麽事情让你东张西望的阿？");
		return 1;
	}
	do_seerace();
	return 1;
}


int do_seerace()
{
	string list;
	object me = this_player();
	int i;

	if(Playing==0 && PlayerId==0)
	{
		i = Game_can_afford(1,me);
		if(!me->query_temp("GAME/Xrace/Playing") && i!=0)
		{
			Playing = 1;		    
			PlayerId = me->query("id");     
			Player = me->query("name");
			Checksum = random(9999)+1;      
			ChoiceNPC();
			me->set_temp("GAME/Xrace/Checksum",Checksum);
			me->set_temp("GAME/Xrace/Playing",1);
		}
	}
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");
	message_vision("$N往比赛场望了过去！\n",me);
	list = "";
	list += "										\n";
	list += "  跑道编号:\t";
	list += sprintf("  %-10s%-10s%-10s%-10s%-10s%-10s%2s",
		"-=１=-","-=２=-","-=３=-","-=４=-","-=５=-","-=６=-","  ");
	list += "\n";
	list += "										\n";
	list += "  叁赛者：\t";
	list += sprintf("  %-10s%-10s%-10s%-10s%-10s%-10s%2s",
		NPCRacingName[0],NPCRacingName[1],NPCRacingName[2],
		NPCRacingName[3],NPCRacingName[4],NPCRacingName[5],"  " );
	list += "\n";
	list += "										\n";
	list += me->query_temp("GAME/Xrace/Playing")==1 ? "  预估速度：\t" : "  速度：\t";
	list += sprintf("  %-10d%-10d%-10d%-10d%-10d%-10d%2s",
		NPCRacingRace[0],NPCRacingRace[1],NPCRacingRace[2],
		NPCRacingRace[3],NPCRacingRace[4],NPCRacingRace[5],"  " );
	list += "\n";
	list += "										\n";
	list += "  赔率：\t";
	list += sprintf("  %-10d%-10d%-10d%-10d%-10d%-10d%2s",
		BetMutiple[0],BetMutiple[1],BetMutiple[2],
		BetMutiple[3],BetMutiple[4],BetMutiple[5],"  " );
	list += "\n";
	list += "										\n";
	list += "  距离终点距离：";
	list += sprintf("  %-10d%-10d%-10d%-10d%-10d%-10d%2s",
		RaceLength-RacingLenth[0],RaceLength-RacingLenth[1],RaceLength-RacingLenth[2],
		RaceLength-RacingLenth[3],RaceLength-RacingLenth[4],RaceLength-RacingLenth[5],"  " );
	list += "\n";
	list += "										";
	list += "\n";
	tell_object(me,list);
	if(Playing==1 && me->query_temp("GAME/Xrace/Playing")<=2
	&& me->query_temp("GAME/Xrace/Checksum")==Checksum)
	{
		Waitstatus = 0;
		call_out("Waitforplayer",0);
	}

	if(me->query_temp("GAME/Xrace/Playing")<2)
		return 1;
	return 1;
	
}


int do_bet(string str)
{
	object me;
	int i,kind,bet;
	me = this_player();
	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"，目前已经有人在玩了喔，麻烦请您等下一轮吧。");
		return 1;
	}
	if(Check_playerdata()==0)
	return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");

	i = Game_can_afford(1,me);
	if(i!=1)
	{
		command("say "+me->query("name")+"，您的筹码呢？");
		return 1;
	}

	if(!me->query_temp("GAME/Xrace/Playing"))
	{
		command("say "+me->query("name")+"，您有没有先看看场上的情形ㄚ？");
		return 1;
	}
	if(me->query_temp("GAME/Xrace/Playing")>=2)
	{
		command("say "+me->query("name")+"，您已经压过了喔。");
		return 1;
	}

	if(!str)
	{
		command("say "+me->query("name")+"，请您看看玩法好吗？");
		return 1;
	}

	if( sscanf(str,"%d %d",kind,bet)!=2)
	{
		command("say "+me->query("name")+"，请您看看规则好吗？");
		return 1;
	}

	if( kind<1 || kind>6 )
	{
		command("say "+me->query("name")+"，您要压几号啊？");
		return 1;
	}

	me->set_temp("GAME/Xrace/Kind",kind);
	me->set_temp("GAME/Xrace/Bet",bet);
	me->set_temp("GAME/Xrace/Playing",2);
	Game_receive_chip(-bet,me);
	command("say 嗯，"+me->query("name")+"，您最看好的是 * "+NPCRacingName[kind-1]+" * ，赌金是"+chinese_number(bet)+"枚筹码。");
	message_vision("$N将"+chinese_number(bet)+"枚筹码拿给"+query("name")+"。\n",me);
	command("say "+me->query("name")+"，您可以按下 start 让比赛开始罗。");
	command("say 别忘了，您只有一次机会可以随时按 k 丢出保龄球干扰比赛喔！");
	if(Playing==1 && me->query_temp("GAME/Xrace/Playing")>=1)
	{
		Waitstatus = 0;
		call_out("Waitforplayer",0);
	}

	return 1;
}


int do_start()
{
	object me = this_player();

	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"，目前已经有人在玩了喔，麻烦请您等下一轮吧。");
		return 1;
	}

	if(me->query_temp("GAME/Xrace/Playing")>=3)
	{
		command("say "+me->query("name")+"，您已经按过开始钮了喔。");
		return 1;
	}
	if(Check_playerdata()==0)
		return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");
	if( me->query_temp("GAME/Xrace/Playing")<2 )
	{
		command("say "+me->query("name")+"，你还没押注耶！");
		return 1;
	}
	me->set_temp("GAME/Xrace/Playing",3);
	message_vision("$N很紧张的按下开始钮。\n",me);
	raceloop();
	return 1;
}


void raceloop()
{
	object ob = this_object();
	int target,i,j;
	remove_call_out("raceloop");

	target = random(30)%6;

	switch(random(600)%20)
	{
		case 0:
			if(NPCRacingRace[target]<=0)
			{
				i = random(10)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"听到场外的加油声而深深感动着，"+NPCRacingName[target]+"的速度由零变为"+chinese_number(i)+"了！\n",ob);
			}
			else
			{
				i = random(6)+1;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+"突然发狂，速度增加了"+chinese_number(i)+"倍！\n"NOR,ob);
			}
			break;
		case 1:
			i = (1+target+random(30)%5)%6;
			NPCRacingRace[target] = NPCRacingRace[i];
			RacingLenth[target] += NPCRacingRace[target];
			message_vision(HIG+NPCRacingName[target]+NOR"爱上了"HIM+NPCRacingName[i]+NOR"，速度跟"+NPCRacingName[i]+"一样了！\n",ob);
			break;
		case 2:
			i = random(200)+1;
			RacingLenth[target] += i;
			message_vision(NPCRacingName[target]+"踩到"HIY"香蕉皮"NOR"，前进了"+chinese_number(i)+"格！\n",ob);
			break;
		case 3:
			if(NPCRacingRace[target]<=0)
			{
				i = random(100)+1;
				NPCRacingRace[target] += i;
				message_vision(HIC+NPCRacingName[target]+"从绝望中意外的得到小天使的鼓励，速度由零变为"+chinese_number(i)+"了！\n"NOR,ob);
			}
			else if( random(5)==1 )
			{
				NPCRacingRace[target] = 0;
				message_vision(GRN+NPCRacingName[target]+"被场外丢进来的保龄球K到，速度变为零了！\n"NOR,ob);
			}
			break;
		case 4:
			i = (1+target+random(30)%5)%6; j = random(100);
			NPCRacingRace[i] -= ( (NPCRacingRace[i]-j)<=0 ? NPCRacingRace[i] : j );
			message_vision(NPCRacingName[target]+"向"+NPCRacingName[i]+HIR"发射飞弹"NOR"，结果造成"+NPCRacingName[i]+"的速度下降"+chinese_number(j)+"点！\n",ob);
			break;
		case 5:
			if(NPCRacingRace[target]<=0)
			{
				i = 200+random(100)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"化悲愤为力量，突然化身为 "+HIM+"* 变态"+NPCRacingName[target]+" *"+NOR+" ，速度由零变为"+chinese_number(i)+"了！\n",ob);
			}
			else
			{
				i = random(6)+10;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"突然变身为 "+HIY+"* 超级"+NPCRacingName[target]+" *"+NOR+" ，速度增加了"+chinese_number(i)+"倍！\n",ob);
			}
			break;
		case 6:
			if(NPCRacingRace[target]<=0)
			{
				i = random(10)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"喝了一罐"+GRN+"蛮牛"+NOR+"，"+NPCRacingName[target]+"的速度由零变为"+chinese_number(i)+"了！\n",ob);
			}
			else
			{
				NPCRacingRace[target] -= NPCRacingRace[target]/2;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIM"哇!!"+NPCRacingName[target]+"在场上跌倒了，速度减少二分之一！\n"NOR,ob);
			}
			break;
		default:
			if(NPCRacingRace[target]<=0)
				message_vision(CYN"绝望的"+NPCRacingName[target]+"正待在原地不动。\n"NOR,ob);
			else if(random(2)==1) {
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+NOR+HIW"正奋力的向前跑。\n"NOR,ob);
			} else {
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIC+NPCRacingName[target]+NOR+HIW"正努力的向前冲刺。\n"NOR,ob);
			}
	}
	if(RacingLenth[target]>=RaceLength)
	{
		remove_call_out("raceloop");
		gameover(target);
	}
	else
	{
		call_out("raceloop",1);
	}
	return;
}

int do_knpc()
{
	object me = this_player();
	int target;
	if(Playing && PlayerId != me->query("id"))
	{
		command("say "+me->query("name")+"，目前已经有人在玩了喔，麻烦请您等下一轮吧。");
		return 1;
	}

	if(Check_playerdata()==0)
		return 1;

	if(me->query_temp("GAME/Xrace/Playing")<2)
	{
		command("say "+me->query("name")+"，这样不好吧，游戏又还没开始。");
		return 1;
	}
	if(me->query_temp("GAME/Xrace/K"))
	{
		message_vision("$N想要暗算某人，却发现没有保龄球了。\n",me);
	}
	else
	{
		target = (me->query_temp("GAME/Xrace/Bet")+random(30)%5)%6;
		NPCRacingRace[target] = 0;
		message_vision(GRN"$N用力地把保龄球往外一丢，结果"+NPCRacingName[target]+"不幸地被保龄球K到，速度变为零了！\n"NOR,me);
		me->set_temp("GAME/Xrace/K",1);
	}
	return 1;
}


void gameover(int target)
{
	object me = this_player();
	object me2;
	int i,bet;

	if(Check_playerdata()==0)
		return;
	me->set("GAME/Xrace/Playing",4);
	Playing = 0;
	i = me->query_temp("GAME/Xrace/Kind");
	if( i != target+1 )
	{
		if(!objectp(me = present(PlayerId, environment(this_object()))))
		{
			command("shout 哇！ * "+NPCRacingName[target]+" * 得到了胜利！");
			command("say 咦？"+Player+"不知道跑到那儿了。");
		}
		else
		{
			do_seerace();
			command("shout 哇！ * "+NPCRacingName[target]+" * 得到了胜利！");
			command("say "+me->query("name")+"，很抱歉您猜的"+NPCRacingName[i-1]+"并没有获得冠军。");
			command("say 也许\下次的运气会更好喔，後会有期，"+Player+"。");
		}
	}
	else if(!objectp(me = present(PlayerId, environment(this_object()))))
	{
		command("shout 哇！ * "+NPCRacingName[target]+" * 得到了胜利！");
		command("say 咦？"+Player+"不知道跑到那儿了。没办法，奖金不能给你罗。");
		command("giggle");
	}
	else
	{
		do_seerace();
		command("shout 哇！ * "+NPCRacingName[target]+" * 得到了胜利！");
		bet = BetMutiple[target] * me->query_temp("GAME/Xrace/Bet");
		Game_receive_chip(bet,me);
		command("applaud "+me->query("id"));
		command("say "+me->query("name")+"，恭喜您猜中了本次比赛的冠军得主是"+NPCRacingName[target]+"。");
		message_vision(query("name")+"将"+chinese_number(bet)+"枚筹码给了$N！\n",me);
		command("say 欢迎下次再来呦。");
	}
	reset();
	return;
}


void Waitforplayer()
{
	Waitstatus += 1;
	if( Waitstatus == 1)
		call_out("Waitforplayer",WaitforplayerTime);
	else
	{
		command("say 这麽久了都没动作，好吧，这场比赛作废。");
		reset();
	}
}

int Check_playerdata()
{
	object me;
	if(!PlayerId)
		return 1;
	if(objectp(me = present(PlayerId, environment(this_object()))))
	{
		if(PlayerId==me->query("id") && !me->query_temp("GAME/Xrace/Playing"))
		{
			command("say "+me->query("name")+"，你可能在比赛期间曾经死亡或曾经离开过梦幻七域。");
			command("say 所以你在本游戏的资料一并消失了。(请看规则第三条)");
			remove_call_out("raceloop");
			message_vision("游戏被终止了！\n",me);
			reset();
			return 0;
		}
	}
	return 1;
}


int do_stoprace()
{
	remove_call_out("raceloop");
	write("比赛被某人中断了...\n");
	return 1;
}


int reset()
{
	int i;

	Playing = 0;
	PlayerId = 0;
	Player = 0;
	Checksum = 0;
	for(i=0;i<sizeof(NPCRacingName);i++)
	{
		NPCRacingRace[i] = 0;
		BetMutiple[i] = 0;
		RacingLenth[i] = 0;
		NPCRacingName[i] = "None";
	}
	reset_player();
	return 1;
}


int reset_player()
{
	object me = this_player();
	me->delete_temp("GAME/Xrace");
	return 1;
}


int do_reset()
{
	reset();
	write("Reset was Okay...\n");
	return 1;
}


void ChoiceNPC()
{
	int i,j,k,tmp,allsize, racesize;
	int *betmul = ( { 0,0,0,0,0,0 }) ;
	string list;

	allsize = sizeof(NPCName);
	racesize = sizeof(NPCRacingName);
	for(i=0;i<racesize;i++)	 
	{
		NPCRacingRace[i] = random(allsize)+1;
		for(j=0;j<i;j++)
		{
			if(NPCRacingRace[i]==NPCRacingRace[j])
				i--;
		}
	}
	for(i=0;i<racesize;i++)	 
	{
		NPCRacingRace[i]--;
		NPCRacingName[i] = NPCName[NPCRacingRace[i]];
		NPCRacingRace[i] = NPCRace[NPCRacingRace[i]];
		betmul[i] = NPCRacingRace[i];
	}
	for(i=0;i<racesize;i++)	 
	for(j=i;j<racesize;j++)	 
	{
		if(betmul[i] < betmul[j])
		{
			tmp = betmul[j];
			for(k=j;k>=i+1;k--)
				betmul[k] = betmul[k-1];
			betmul[i] = tmp;
		}
	}
	tmp = betmul[0]-betmul[5];      
	tmp = tmp/10;
	j = tmp-2;
	k = betmul[0]-betmul[5];
	for(i=0;i<racesize;i++)	 
	{
		BetMutiple[i] = tmp-j*(NPCRacingRace[i]-betmul[5])/k;
	}

	return;
}

int to_say_play()
{
	object me = this_player();
	command("say 玩法很简单，只要你猜对哪一位叁赛者会得冠军，那麽高额奖金就是你的了。");
write(@HELP

	指  令			 说    明
====================================================================
	see race		看看比赛场的情况
	.		       看看比赛场的情况
	bet <跑道编号> <筹码数> 下压金，猜会得冠军的叁赛者
	start		   开始比赛
	k		       拿保龄球暗算场上的叁赛者
=====================================================================

规则:   1. 一个场次只可以有一人押注，而且只能猜其中一位是冠军。
	2. 只有一次机会可以拿保龄球暗算场上的叁赛者。
	3. 比赛期间不得离开比赛场地，否则後果自负。
HELP);
	return 1;
}

