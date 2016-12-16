#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <obstacle.h>
#define FILE "/d/obj/npc/emery.c"

int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
void dianmao();
void emery();

void create()
{
	seteuid( ROOT_UID );
	TASK_D->init_dynamic_quest();
	MONEY_D->move_money(random(5000));
	init_cron();
}

int query_last_hard_dis()
{
        return LAST_HARD_DIS;
}

int set_last_hard_dis()
{
        LAST_HARD_DIS = time();
        return time();
}

void init_cron()
{
	mixed *local;
	local = localtime(time());
	if ( !((local[1]+1)%30)) autosave();

//	if ( !((local[1]+1)%50)) dianmao();
	if ( !((local[1]+1)%15)) emery();

	if ( !((local[1]+1)%30)) TASK_D->init_dynamic_quest();
	call_out("init_cron", 60);//60 By waiwai@mszj 2000/12/02 
}

void autosave()
{
	object *user ;
	int i;
	user = users();
//	message("system", HIR "\n��Ӱ��Ե������Զ����¡�\n"NOR, users());
//	message("channel:chat",HIR"����Ӱ��ԵTASK����"HIY"�Զ�������Ӱ��Ե�����\n"NOR,users());
	for(i=0; i<sizeof(user); i++) 
        user[i]->save();
}
/*
void dianmao()
{
	object *user;
	int size1,i;
	size1 = sizeof(obstacles);
	user = users();
	message("channel:chat",HIY+"\n������ʢ������ï��(Xu maogong)��ʱ���ѵ�����λͬ���ٵ�����î��\n"+NOR,users());
	for(i=0; i<sizeof(user); i++)
	{
		user[i]->set("dianmao",1);
        user[i]->save();
	}
}         
*/
void emery()
{
	object me,emery,*user;
	object xu=load_object("/d/huanggong/npc/dachen2");

	int i,x,m,n;
	string *dirs;

	dirs = ({"/d/gao/","/d/jz/", "/d/changan/","/d/eastway/",});

	user= users();
	i = random(sizeof(dirs));

	n =  (int)(sizeof(users())/7+random(sizeof(users())/7)+1);
	message("system",HIW "\n����ɫ������Ȼһ��ѣĿ�İ׹�����һ�У�һ��Բ�εĶ������ڸ߿գ�\n"NOR, users());
	for(x=0;x<n;x++)
	{
		emery=new("/d/obj/npc/emery.c");
		emery->random_go(me,dirs,i);
	}
	message("system",HIW"��ï����ָһ�㣺����"+chinese_number(n)+"����������"+TASK_D->query_city(environment(find_living("guai shou")))+"���ң�\n"NOR,users());
	xu->set("mark",time());
	remove_call_out("check_guaiwu");
	call_out("check_guaiwu",120,xu);

	for(m=0;m<sizeof(user);m++)
	{
		user[m]->set("kill_guaishou",1);
	}
}
       
void check_guaiwu(object xu)
{
	if( time() - xu->query("mark") > 10*60 )
	{
		remove_call_out("end");
		call_out("end",3);
		return;     
	}

	if(sizeof(filter_array(children(FILE),(:clonep:))) > 1)
	{      
		message("system",HIW"��ï����������Ҽ��Ͱ������޻�û��ɱ�꣡\n"NOR,users());
		remove_call_out("check_guaiwu");
		call_out("check_guaiwu",120,xu);
		return;
	}
	else 
	{
		message("system",HIW"��ï��һ��ȭ����ϲ��λɱ�����еĹ��ޣ����ұ�����������ҵ��Ͱɣ���\n"NOR,users());
		remove_call_out("reward");
		call_out("reward",3);
		return;
	}
}

void end()
{
	object *user;
	string str;

	object tang=find_living("tang taizong");
	int i;
	user=users();

	if(sizeof(filter_array(children(FILE),(:clonep:)))>=1)
	{
		message("system",HIM"��ҥ������ĳ�ˣ����������޳Ե��ˣ�\n"NOR,users());
		for(i=0;i<sizeof(user);i++)
		{
			if(user[i]->query_temp("guaishou_number"))
			{
				str = HIG"������Ŭ��ɱ�֣���õ���"NOR;
				switch(random(3)) {
					case 0:
						user[i]->add("daoxing",(int)user[i]->query_temp("guaishou_number")*100);
						str += HIG+COMBAT_D->chinese_daoxing(user[i]->query_temp("guaishou_number")*100)+"���еĽ�����\n"NOR;
						break;
					case 1:
						user[i]->add("combat_exp",(int)user[i]->query_temp("guaishou_number")*100);
						str += HIG+chinese_number(user[i]->query_temp("guaishou_number")*100)+"����ѧ����Ľ�����\n"NOR;
						break;
					case 2:
						user[i]->add("potential",(int)user[i]->query_temp("guaishou_number")*10);
						str += HIG+chinese_number(user[i]->query_temp("guaishou_number")*10)+"��Ǳ�ܵĽ�����\n"NOR;
						break;
				}
				tell_object(user[i],str);
				user[i]->delete_temp("guaishou_number");
			}
		}
		if( tang )
			destruct(tang);
	}
}

void reward()
{
	object tang, *user;
	int i,number;
	string str;
	user=users();

	tang=find_living("tang taizong");
	if( tang )
	{
		CHANNEL_D->do_channel(tang,"chat","��л��λ���Ҵ��ƣ����˶���������λ��\n");
	}
	for(i=0;i<sizeof(user);i++)
	{
		user[i]->delete("kill_guaishou");
		if(number=user[i]->query_temp("guaishou_number"))
		{
			user[i]->add("office_number",number);
			str = HIG"������Ŭ��ɱ�֣�������������õ���"+number+"�㹦ѫ��"NOR;
			switch(random(3)) {
				case 0:
					user[i]->add("daoxing",number*300);
					str += HIG+COMBAT_D->chinese_daoxing(number*300)+"���еĽ�����\n"NOR;
					break;
				case 1:
					user[i]->add("combat_exp",number*300);
					str += HIG+chinese_number(number*300)+"��ѧ����Ľ�����\n"NOR;
					break;
				case 2:
					user[i]->add("potential",number*30);
					str += HIG+chinese_number(number*30)+"��Ǳ�ܵĽ�����\n"NOR;
					break;
			}
			tell_object(user[i],str);
			user[i]->delete_temp("guaishou_number");
		}
	}
}

