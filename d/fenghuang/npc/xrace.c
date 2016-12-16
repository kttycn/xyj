// ����С��
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

int *NPCRace = ({       // ������� 100, ��� 1
		 60,  20,  70,  10,  70,
		 45,  90,  90,  95,  60,
		 85,   5,  75,  85,  60,
		 30,  40, 100,   3, 110,
		 75,  15,  80,  10,  50 });
int *NPCRacingRace = ({ 0,0,0,0,0,0 });
int *BetMutiple = ({ 0,0,0,0,0,0 });
int *RacingLenth = ({ 0,0,0,0,0,0 });
string *NPCName = ({
	"�Ļ�","�����ʿ","Ĭ��","����","�ǰ��",
	"���ǵ��","С����","����","����","½�ʼ�",
	"��Ұ��","���","����","���","����",
	"��ϲ����","С����","С����","��˿","ǡ��",
	"SMŮ��","С��ñ","ӣľ����","�ڱ�","MTV����" });
string *NPCRacingName = ({ "None","None","None","None","None","None" });

void create()
{
	set_name("ѩ��",({ "suet","racing lady","lady" }));
	set("level",9);
	set("title","����С��");
	set("race", "����");
	set("gender","Ů��");
	set("age", 19);
	set("long",@LONG
�ɰ�������С��, ������Ϊ���³����. ( ask suet about play )
LONG	);
	set("attitude", "friendly");
	set("inquiry",([
	   "����": (: to_say_play :),
	   "race": (: to_say_play :),
	   "�淨": (: to_say_play :),
	   "play": (: to_say_play :),
	   "����": (: to_say_play :),
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
		command("say "+me->query("name")+"��ʲ���������㶫�������İ���");
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
	message_vision("$N�����������˹�ȥ��\n",me);
	list = "";
	list += "										\n";
	list += "  �ܵ����:\t";
	list += sprintf("  %-10s%-10s%-10s%-10s%-10s%-10s%2s",
		"-=��=-","-=��=-","-=��=-","-=��=-","-=��=-","-=��=-","  ");
	list += "\n";
	list += "										\n";
	list += "  �����ߣ�\t";
	list += sprintf("  %-10s%-10s%-10s%-10s%-10s%-10s%2s",
		NPCRacingName[0],NPCRacingName[1],NPCRacingName[2],
		NPCRacingName[3],NPCRacingName[4],NPCRacingName[5],"  " );
	list += "\n";
	list += "										\n";
	list += me->query_temp("GAME/Xrace/Playing")==1 ? "  Ԥ���ٶȣ�\t" : "  �ٶȣ�\t";
	list += sprintf("  %-10d%-10d%-10d%-10d%-10d%-10d%2s",
		NPCRacingRace[0],NPCRacingRace[1],NPCRacingRace[2],
		NPCRacingRace[3],NPCRacingRace[4],NPCRacingRace[5],"  " );
	list += "\n";
	list += "										\n";
	list += "  ���ʣ�\t";
	list += sprintf("  %-10d%-10d%-10d%-10d%-10d%-10d%2s",
		BetMutiple[0],BetMutiple[1],BetMutiple[2],
		BetMutiple[3],BetMutiple[4],BetMutiple[5],"  " );
	list += "\n";
	list += "										\n";
	list += "  �����յ���룺";
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
		command("say "+me->query("name")+"��Ŀǰ�Ѿ�����������ร��鷳��������һ�ְɡ�");
		return 1;
	}
	if(Check_playerdata()==0)
	return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");

	i = Game_can_afford(1,me);
	if(i!=1)
	{
		command("say "+me->query("name")+"�����ĳ����أ�");
		return 1;
	}

	if(!me->query_temp("GAME/Xrace/Playing"))
	{
		command("say "+me->query("name")+"������û���ȿ������ϵ����Ψڣ�");
		return 1;
	}
	if(me->query_temp("GAME/Xrace/Playing")>=2)
	{
		command("say "+me->query("name")+"�����Ѿ�ѹ����ม�");
		return 1;
	}

	if(!str)
	{
		command("say "+me->query("name")+"�����������淨����");
		return 1;
	}

	if( sscanf(str,"%d %d",kind,bet)!=2)
	{
		command("say "+me->query("name")+"�����������������");
		return 1;
	}

	if( kind<1 || kind>6 )
	{
		command("say "+me->query("name")+"����Ҫѹ���Ű���");
		return 1;
	}

	me->set_temp("GAME/Xrace/Kind",kind);
	me->set_temp("GAME/Xrace/Bet",bet);
	me->set_temp("GAME/Xrace/Playing",2);
	Game_receive_chip(-bet,me);
	command("say �ţ�"+me->query("name")+"������õ��� * "+NPCRacingName[kind-1]+" * ���Ľ���"+chinese_number(bet)+"ö���롣");
	message_vision("$N��"+chinese_number(bet)+"ö�����ø�"+query("name")+"��\n",me);
	command("say "+me->query("name")+"�������԰��� start �ñ�����ʼ�ޡ�");
	command("say �����ˣ���ֻ��һ�λ��������ʱ�� k ������������ű���ร�");
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
		command("say "+me->query("name")+"��Ŀǰ�Ѿ�����������ร��鷳��������һ�ְɡ�");
		return 1;
	}

	if(me->query_temp("GAME/Xrace/Playing")>=3)
	{
		command("say "+me->query("name")+"�����Ѿ�������ʼť��ม�");
		return 1;
	}
	if(Check_playerdata()==0)
		return 1;
	if(me->query_temp("GAME/Xrace/Playing")>=1)
		remove_call_out("Waitforplayer");
	if( me->query_temp("GAME/Xrace/Playing")<2 )
	{
		command("say "+me->query("name")+"���㻹ûѺעҮ��");
		return 1;
	}
	me->set_temp("GAME/Xrace/Playing",3);
	message_vision("$N�ܽ��ŵİ��¿�ʼť��\n",me);
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
				message_vision(NPCRacingName[target]+"��������ļ�����������ж��ţ�"+NPCRacingName[target]+"���ٶ������Ϊ"+chinese_number(i)+"�ˣ�\n",ob);
			}
			else
			{
				i = random(6)+1;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+"ͻȻ�����ٶ�������"+chinese_number(i)+"����\n"NOR,ob);
			}
			break;
		case 1:
			i = (1+target+random(30)%5)%6;
			NPCRacingRace[target] = NPCRacingRace[i];
			RacingLenth[target] += NPCRacingRace[target];
			message_vision(HIG+NPCRacingName[target]+NOR"������"HIM+NPCRacingName[i]+NOR"���ٶȸ�"+NPCRacingName[i]+"һ���ˣ�\n",ob);
			break;
		case 2:
			i = random(200)+1;
			RacingLenth[target] += i;
			message_vision(NPCRacingName[target]+"�ȵ�"HIY"�㽶Ƥ"NOR"��ǰ����"+chinese_number(i)+"��\n",ob);
			break;
		case 3:
			if(NPCRacingRace[target]<=0)
			{
				i = random(100)+1;
				NPCRacingRace[target] += i;
				message_vision(HIC+NPCRacingName[target]+"�Ӿ���������ĵõ�С��ʹ�Ĺ������ٶ������Ϊ"+chinese_number(i)+"�ˣ�\n"NOR,ob);
			}
			else if( random(5)==1 )
			{
				NPCRacingRace[target] = 0;
				message_vision(GRN+NPCRacingName[target]+"�����ⶪ�����ı�����K�����ٶȱ�Ϊ���ˣ�\n"NOR,ob);
			}
			break;
		case 4:
			i = (1+target+random(30)%5)%6; j = random(100);
			NPCRacingRace[i] -= ( (NPCRacingRace[i]-j)<=0 ? NPCRacingRace[i] : j );
			message_vision(NPCRacingName[target]+"��"+NPCRacingName[i]+HIR"����ɵ�"NOR"��������"+NPCRacingName[i]+"���ٶ��½�"+chinese_number(j)+"�㣡\n",ob);
			break;
		case 5:
			if(NPCRacingRace[target]<=0)
			{
				i = 200+random(100)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"������Ϊ������ͻȻ����Ϊ "+HIM+"* ��̬"+NPCRacingName[target]+" *"+NOR+" ���ٶ������Ϊ"+chinese_number(i)+"�ˣ�\n",ob);
			}
			else
			{
				i = random(6)+10;
				NPCRacingRace[target] *= i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"ͻȻ����Ϊ "+HIY+"* ����"+NPCRacingName[target]+" *"+NOR+" ���ٶ�������"+chinese_number(i)+"����\n",ob);
			}
			break;
		case 6:
			if(NPCRacingRace[target]<=0)
			{
				i = random(10)+1;
				NPCRacingRace[target] += i;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(NPCRacingName[target]+"����һ��"+GRN+"��ţ"+NOR+"��"+NPCRacingName[target]+"���ٶ������Ϊ"+chinese_number(i)+"�ˣ�\n",ob);
			}
			else
			{
				NPCRacingRace[target] -= NPCRacingRace[target]/2;
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIM"��!!"+NPCRacingName[target]+"�ڳ��ϵ����ˣ��ٶȼ��ٶ���֮һ��\n"NOR,ob);
			}
			break;
		default:
			if(NPCRacingRace[target]<=0)
				message_vision(CYN"������"+NPCRacingName[target]+"������ԭ�ز�����\n"NOR,ob);
			else if(random(2)==1) {
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIG+NPCRacingName[target]+NOR+HIW"����������ǰ�ܡ�\n"NOR,ob);
			} else {
				RacingLenth[target] += NPCRacingRace[target];
				message_vision(HIC+NPCRacingName[target]+NOR+HIW"��Ŭ������ǰ��̡�\n"NOR,ob);
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
		command("say "+me->query("name")+"��Ŀǰ�Ѿ�����������ร��鷳��������һ�ְɡ�");
		return 1;
	}

	if(Check_playerdata()==0)
		return 1;

	if(me->query_temp("GAME/Xrace/Playing")<2)
	{
		command("say "+me->query("name")+"���������ðɣ���Ϸ�ֻ�û��ʼ��");
		return 1;
	}
	if(me->query_temp("GAME/Xrace/K"))
	{
		message_vision("$N��Ҫ����ĳ�ˣ�ȴ����û�б������ˡ�\n",me);
	}
	else
	{
		target = (me->query_temp("GAME/Xrace/Bet")+random(30)%5)%6;
		NPCRacingRace[target] = 0;
		message_vision(GRN"$N�����ذѱ���������һ�������"+NPCRacingName[target]+"���ҵر�������K�����ٶȱ�Ϊ���ˣ�\n"NOR,me);
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
			command("shout �ۣ� * "+NPCRacingName[target]+" * �õ���ʤ����");
			command("say �ף�"+Player+"��֪���ܵ��Ƕ��ˡ�");
		}
		else
		{
			do_seerace();
			command("shout �ۣ� * "+NPCRacingName[target]+" * �õ���ʤ����");
			command("say "+me->query("name")+"���ܱ�Ǹ���µ�"+NPCRacingName[i-1]+"��û�л�ùھ���");
			command("say Ҳ��\�´ε����������ร�������ڣ�"+Player+"��");
		}
	}
	else if(!objectp(me = present(PlayerId, environment(this_object()))))
	{
		command("shout �ۣ� * "+NPCRacingName[target]+" * �õ���ʤ����");
		command("say �ף�"+Player+"��֪���ܵ��Ƕ��ˡ�û�취�������ܸ����ޡ�");
		command("giggle");
	}
	else
	{
		do_seerace();
		command("shout �ۣ� * "+NPCRacingName[target]+" * �õ���ʤ����");
		bet = BetMutiple[target] * me->query_temp("GAME/Xrace/Bet");
		Game_receive_chip(bet,me);
		command("applaud "+me->query("id"));
		command("say "+me->query("name")+"����ϲ�������˱��α����Ĺھ�������"+NPCRacingName[target]+"��");
		message_vision(query("name")+"��"+chinese_number(bet)+"ö�������$N��\n",me);
		command("say ��ӭ�´������ϡ�");
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
		command("say ������˶�û�������ðɣ��ⳡ�������ϡ�");
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
			command("say "+me->query("name")+"��������ڱ����ڼ����������������뿪���λ�����");
			command("say �������ڱ���Ϸ������һ����ʧ�ˡ�(�뿴���������)");
			remove_call_out("raceloop");
			message_vision("��Ϸ����ֹ�ˣ�\n",me);
			reset();
			return 0;
		}
	}
	return 1;
}


int do_stoprace()
{
	remove_call_out("raceloop");
	write("������ĳ���ж���...\n");
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
	command("say �淨�ܼ򵥣�ֻҪ��¶���һλ�����߻�ùھ�������߶���������ˡ�");
write(@HELP

	ָ  ��			 ˵    ��
====================================================================
	see race		���������������
	.		       ���������������
	bet <�ܵ����> <������> ��ѹ�𣬲»�ùھ���������
	start		   ��ʼ����
	k		       �ñ������㳡�ϵ�������
=====================================================================

����:   1. һ������ֻ������һ��Ѻע������ֻ�ܲ�����һλ�ǹھ���
	2. ֻ��һ�λ�������ñ������㳡�ϵ������ߡ�
	3. �����ڼ䲻���뿪�������أ���������Ը���
HELP);
	return 1;
}

