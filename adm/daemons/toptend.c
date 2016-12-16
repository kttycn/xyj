#include <ansi.h>
#include <mudlib.h>

void topten_checkplayer(object);
int get_all_data(object,string);
int topten_del(string,string);
int topten_add(object,string);
int topten_save(string,string,string);
int get_score(object ob);
string topten_query(string);
string query_type();


void topten_checkplayer(object player)
{//������ò�����������컹�Ǻ����أ�������Щ����Ҫ�е����ֵģ�������Ů�Ա�
	topten_add(player,"rich");
	topten_add(player,"quests");
	topten_add(player,"pker");
	topten_add(player,"killer");
	topten_add(player,"spells");
	topten_add(player,"exp");
	topten_add(player,"dx");
	topten_add(player,"force");
	topten_add(player,"per1");
	topten_add(player,"per2");	
	topten_add(player,"age");
	topten_add(player,"master");
	topten_add(player,"task");
	return;
}

string query_type()
{
	return HIY+CHINESE_MUD_NAME+"�������������͵����а�\n"+
		HIC"master\t"HIW+MASTER_B+"\n"+
		HIC"rich\t"HIW+RICH_B+"\n"+
		HIC"exp\t"HIW+EXP_B+"\n"+
		HIC"dx\t"HIW+DX_B+"\n"+
		HIC"pker\t"HIW+PKER_B+"\n"+
		HIC"force\t"HIW+FORCE_B+"\n"+
		HIC"killer\t"HIW+KILL_B+"\n"+
		HIC"spells\t"HIW+SPELLS_B+"\n"+
		HIC"per1\t"HIW+PER1_B+"\n"+
		HIC"per2\t"HIW+PER2_B+"\n"+
		HIC"age\t"HIW+AGE_B+"\n"+
		HIC"quests\t"HIW+QUESTS_B+"\n"+
		HIC"task\t"HIW+TASK_B+"\n"+
		NOR;
}

int topten_save(string f_name,string b_name,string str)
{
	string *astr;
	int i;
	astr=explode(str,"\n");
	str="";
	for(i=0;i<sizeof(astr)&&i<10;i++)
		str+=astr[i]+"\n";
	if(!write_file(f_name,str,1))
		return notify_fail("�޷�д�ļ�"+f_name+"��Ȩ�޲���!���ܸ���"+b_name+"!\n");
	return 1;
}

string topten_query(string type)
{
	string b_name,f_name,str,*astr,*bstr,name,id;
	int i,j,data;
	switch(type)
	{
		case "master":
			b_name=MASTER_B;
			f_name=TOPTEN_MASTER;
			break;
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "killer":
			b_name=KILL_B;
			f_name=TOPTEN_KILL;
			break;
		case "spells":
			b_name=SPELLS_B;
			f_name=TOPTEN_SPELLS;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per1":
			b_name=PER1_B;
			f_name=TOPTEN_PER1;
			break;
		case "per2":
			b_name=PER2_B;
			f_name=TOPTEN_PER2;
			break;
		case "task":
			b_name=TASK_B;
			f_name=TOPTEN_TASK;
			break;
		default:
			return "û��"+type+"�������а�\n";
	}
	if(file_size(f_name)==-1)
		return HIG+b_name+"�������ļ���û�д�����\n"NOR;
	astr=explode(read_file(f_name),"\n");
	str = HIC"��"+b_name+"\n"NOR+
		HIM"����������������������������������������������������\n"NOR;
//	str=HIY+CHINESE_MUD_NAME+"��\n"NOR+HIC+b_name+"\n"NOR;
//	str+=HIC+"������������������������������������������\n"NOR;
	for(i=0;i<sizeof(astr);i++)
	{
		bstr=explode(astr[i],";");
		str+=HIR"���� "HIC"���е�"+chinese_number(i+1)+"��"HIW;
		for(j=0;j<sizeof(bstr);j++)
		{
			if(sscanf(bstr[j],"%s(%s)%d",name,id,data)!=3)
				return "���ݴ���!�ļ���"+f_name+"��"+i+"�е�"+j+"�\n"+
					"�������ݣ�"+bstr[j]+"\n";
			str+=name+"("+id+")\t";
		}
		str+="\n"NOR;
	}
	str+=HIM"����������������������������������������������������\n"NOR;
	return str;
}
int get_all_data(object player,string type)
{
	int total;
	switch(type)
	{
		case "rich":
			total=(int)player->query("balance");
			break;
		case "quests":
			total=(int)player->query("quest/number");
			break;
		case "master":
			total=(int)get_score(player);
			break;
		case "pker":
			total=(int)player->query("PKS");
			break;
		case "exp":
			total=((int)player->query("combat_exp"));
			break;
		case "dx":
			total=((int)player->query("daoxing"));
			break;
		case "killer":
			total=(int)player->query("PKS")+(int)player->query("MKS");
			break;
		case "spells":
			total=(int)player->query("maximum_mana");
			break;
		case "force":
			total=(int)player->query("maximum_force");
			break;
		case "age":
			total=(int)player->query("mud_age");
			break;
		case "per1":
			if (((string)player->query("gender")) == "����")
				total=player->query_per();
			else total=-1;
			break;
		case "per2":
			if (((string)player->query("gender")) == "Ů��")
				total=player->query_per();
			else total=-1;
			break;
		case "task":
			total=(int)player->query("task_job");
			break;			
		default:
			return -1;//��-1��־���ͳ���
	}
	return total;
}

int topten_del(string pid,string type)
{
	string str,*astr,*bstr,b_name,f_name;
	int i,j,k;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "master":
			b_name=MASTER_B;
			f_name=TOPTEN_MASTER;
			break;
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "killer":
			b_name=KILL_B;
			f_name=TOPTEN_KILL;
			break;
		case "spells":
			b_name=SPELLS_B;
			f_name=TOPTEN_SPELLS;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per1":
			b_name=PER1_B;
			f_name=TOPTEN_PER1;
			break;
		case "per2":
			b_name=PER2_B;
			f_name=TOPTEN_PER2;
			break;		
		case "task":
			b_name=TASK_B;        
			f_name=TOPTEN_TASK;
			break;
		default:
			return notify_fail("û��"+type+"�������а�\n");
	}
	if(file_size(f_name)==-1)
		return notify_fail(b_name+"��û�д�����\n");
	str=read_file(f_name);
	astr=explode(str,"\n");
	for(i=0;i<sizeof(astr);i++)
	{
		if(strsrch(astr[i],pid)!=-1)//���а���id��Ϊ��
		{
			if(strsrch(astr[i],";")==-1)
			//Ϊ���ʾ����ֻ��һ��id����pid
			{
				str="";
				for(j=0;j<sizeof(astr);j++)
					if(j!=i)
						str+=astr[j]+"\n";
				return topten_save(f_name,b_name,str);
			}
			else
			{
				bstr=explode(astr[i],";");
				for(j=0;j<sizeof(bstr);j++)
					if(strsrch(bstr[j],pid)!=-1)//˵�����pid,Ӧ��ȥ��
					{
						astr[i]="";
						for(k=0;k<sizeof(bstr);k++)
							if(k!=j)
							{
								if((k+1)!=sizeof(bstr)
									&&!((j+1)==sizeof(bstr)&&j==(k+1))
								)
									astr[i]+=bstr[k]+";";
								else
									astr[i]+=bstr[k];
							}
						//����ȥ����j��ѭ��Ӧ��ֹͣ,���ǲ�Ӱ����
					}
				str=implode(astr,"\n");
				return topten_save(f_name,b_name,str);
			}
		}
	}
	return 1;
}

int topten_add(object player,string type)
{
	string str,name,id,b_name,f_name;
	string *astr;
	int i,j,data;
	if(wizardp(player) )//��ֹ��ʦ�μ����а�
		return 0;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "master":
			b_name=MASTER_B;
			f_name=TOPTEN_MASTER;
			break;
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "killer":
			b_name=KILL_B;
			f_name=TOPTEN_KILL;
			break;
		case "spells":
			b_name=SPELLS_B;
			f_name=TOPTEN_SPELLS;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per1":
			b_name=PER1_B;
			f_name=TOPTEN_PER1;
			break;
		case "per2":
			b_name=PER2_B;
			f_name=TOPTEN_PER2;
			break;
		case "task":
			b_name=TASK_B;
			f_name=TOPTEN_TASK;
			break;	
		default:
			return notify_fail("û��"+type+"�������а�\n");
	}
	if(!objectp(player)||!userp(player))
		return 0;
	if(file_size(f_name)==-1)
	{
		str=player->query("name")+"("+player->query("id")+")"+
			get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	//��Ҫ����
	if(get_all_data(player,type)==-1)
		return notify_fail("���ݲ�ѯ���󣬿����ǲ�ѯ���ʹ���\n");
	//Ӧ�����ų���player��id!
	topten_del(player->query("id"),type);
	str=read_file(f_name);
	astr=explode(str,"\n");
	i=0;
	while(i<sizeof(astr))
	{
		if(sscanf(astr[i],"%s(%s)%d",name,id,data)!=3)
			if(sscanf(astr,"%s(%s)%d;%*s",name,id,data)!=3)
				return notify_fail(b_name+"�ļ����ݴ����������ʦ��\n");
		str="";
		if(data<(int)get_all_data(player,type))
		{
			//�������룬��ʱû������������ʮ�У�
			for(j=0;j<sizeof(astr);j++)
			{
				if(j==i)
					str+=player->query("name")+"("+player->query("id")+")"+
						get_all_data(player,type)+"\n";
				str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		else
		if(data==(int)get_all_data(player,type))
		{
			//���ż���
			for(j=0;j<sizeof(astr);j++)
			{
				if(j==i)
					str+=astr[j]+";"+player->query("name")+
						"("+player->query("id")+")"+get_all_data(player,type)+"\n";
				else
					str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		i++;
	}
	if(sizeof(astr)<10)
	{
		str=implode(astr,"\n")+"\n"+player->query("name")+"("+player->query("id")+
			")"+get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	return 0;
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
