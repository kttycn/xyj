// Natured.c

#include <ansi.h>
#define TIME_TICK ((time()-890000000)*60)
#define TIME_TICK1 ((time()-900000000)*60)
int current_day_phase, current_month;
void auto_save(object *user, int size, int i);
mapping *day_phase;
int night;
int online_user();
string ppl;

string *month_time = ({
	"�������ĵ������ˣ�",
	"��������ط���������ӣ�",
	"�����𽥱�ů�ˣ�",
	"�Ѿ��ǳ���ʱ���ˣ�",
	"֪�˵Ľ�������о�����ʢ�ĵ���Ϣ��",
	"������÷ǳ����ȣ�",
	"��Ȼ�������ˣ�����������Щ�ȣ�",
	"����ѽڿ쵽�ˣ�",
	"һ����紵���������˵��ϵ���Ҷ��",
	"��ȥ������",
	"����������",
	"�쵽����ˣ�",
});

string *month_desc = ({
	HIW"¡����"NOR,
	HIW"������"NOR,
	HIG"������"NOR,
	HIG"�紺���µ�"NOR,
	HIG"�������µ�"NOR,
	HIC"���ĵ�"NOR,
	HIC"ʢ�ĵ�"NOR,
	HIR"���ĵ�"NOR,
	HIY"�����"NOR,
	HIY"�����ˬ��"NOR,
	YEL"�����"NOR,
	WHT"������"NOR,
});

int query_current_day_phase() { return current_day_phase; }
mapping *read_table(string file);
void init_day_phase();

void create()
{
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
	"/obj/feizei/feizei.c"->choose_npc();
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);


	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		        
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}
void auto_save(object *user, int size, int i)
{
    int j;
    
    for(j=i;j<i+5;j++) {
		if(j>=size) return;
		if(!user[j]) continue;
		if(!environment(user[j])) continue; // skip those still in login.
		if(user[j]->save())
		    tell_object(user[j], HIB"�����̾��顿���ĵ����Ѿ��Զ��洢�ˡ�\n"NOR);
    }
    
    call_out("auto_save", 10, user, size, i+5);
}
void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];           // hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];

	// MUD ����ʱ����ˣ�ʱ�����ƫ������ǵ�������ÿСʱִ��һ��
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.
	remove_call_out("update_day_phase");	

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

int event_night()
{ 
	 night=1;
}

int set_night(int arg)
{
	night=arg;
	return 1;
}
int night()
{  
      return night;
}

void update_day_phase()
{
	int i;//,j;
	object *inusers,envroom;
	//string str;
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
//	i=0;
// here is modified by vikee 2001-2-15 13:15
	inusers=users();	
	
	for (i=(sizeof(inusers)-1);i>=0;i--)
	{
		envroom=environment(inusers[i]);
		if (envroom)
		{
			if ( intp(envroom->query("outdoors")))
			{
				if ( !envroom->query("outdoors") )
					tell_object(inusers[i],HIR"��"HIY"����"HIR"��"NOR+day_phase[current_day_phase]["time_msg"]+"\n");
				else 
					tell_object(inusers[i],HIR"��"HIG"����"HIR"��"NOR+day_phase[current_day_phase]["time_msg"]+"\n");
			}
			else
			{
				tell_object(inusers[i],HIR"��"HIG"����"HIR"��"NOR+day_phase[current_day_phase]["time_msg"]+"\n");
			}
		}     
	}
	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}


void event_midnight()
{       
	
	string get_month, get_day;
	mixed *local;
	
	
	local = localtime(TIME_TICK1);
	"/obj/feizei/feizei.c"->choose_npc();
	get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     
		     case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

int online_user()
{
	int i,ppl_cnt;
	object *usr = users();
	for(i=0; i<sizeof(usr); i++)
	{
		if( !environment(usr[i]) ) continue;
		ppl_cnt++;
	}
	return ppl_cnt;
}
void event_sunrise()
{
	int i,avg_num,record_num,online_num,total_num,times;
	string avg_temp,total_temp,times_temp;
	object *user=users();
	online_num = online_user();
	times = atoi(read_file(__DIR__"record_times",1));
	times++;
	record_num = atoi(read_file(__DIR__"total_num",1));
	total_num = online_num + record_num;
	avg_num = total_num / times;
	total_temp = sprintf("%d",total_num);
	times_temp = sprintf("%d",times);
	avg_temp = sprintf("%d",avg_num);
	write_file(__DIR__"total_num",total_temp,1);
	write_file(__DIR__"record_times",times_temp,1);
	write_file(__DIR__"avguser",avg_temp,1);

	message("channel:chat", CYN +"�����ġ�̫�ࣺ�����糯������ٹ�������\n"+ NOR, users());
	for(i=0; i<sizeof(user); i++)
	{
		user[i]->set_temp("dianmao",1);
		user[i]->save();
	}
	remove_call_out("auto_save");
	call_out("auto_save", 10, user, sizeof(user), 0);
	return;
}
void event_dawn()
{
	object room;
	room = find_object("/d/city/center");
	if( !room) room = load_object("/d/city/center");
	if(room)
	room->set("enter_permission", 0);
	night=0;
	return;
}
/***********
void event_evening()
{
//        object room;
//	room = find_object("/d/city/center");
//        if( !room) room = load_object("/d/city/center");
//        if( room )
//        room->set("enter_permission", 1);
//        return;
	object area,who;
	mixed file,dir;
	int amount,i;
	dir=get_dir("/data/city/");
	if(!dir) return; 
	if(!random(10)) return;

	for(i=0;i<sizeof(dir);i++)
		if( sscanf(dir[i], "%s.o", file) )
		{
			area=new("/obj/area1.c");
			area->create(file);
			if(area->query("no_use"))
			{
				destruct(area);
				continue;
			} 
			if(area->query("owner"))  
			{
				amount=(area->query("people")/10000)*(area->query("farm")+
				area->query("trade"))*(area->query("faith")/10)*area->query("tax")/5;				if(amount <=0) return;
				who=find_player(area->query("owner"));
				if(who)
				{
					if(area->query("tax")>=100) {
						area->set("faith",0);
						area->set("farm",0);
						area->set("trade",0);
						area->set("people",area->query("people")/5);
					}else if(area->query("tax")>80) {
						area->set("faith",area->query("faith")/10);
						area->set("farm",area->query("farm")/10);
						area->set("trade",area->query("trade")/10);
						area->set("people",area->query("people")/4);
						area->set("faith",100);
					}else if(area->query("tax")>60) {
						area->set("faith",area->query("faith")/3);
						area->set("farm",area->query("farm")/3);
						area->set("trade",area->query("trade")/3);
						area->set("people",area->query("people")/3);
					}else if(area->query("tax")>40) {
						area->set("faith",area->query("faith")*2/3);
						area->set("farm",area->query("farm")*2/3);
						area->set("trade",area->query("trade")*2/3);
						area->set("people",area->query("people")/2);
					}else if(area->query("tax")>30) {
						area->add("faith",-20);
						area->add("farm",-30);
						area->add("trade",-30);
					}
					if(area->query("tax")>60)
						tell_object(who,"�������"+area->query("short")+"ʵʩ��ѹ���ߣ�"+area->query("short")+"�������ŭ�ˡ�\n");
					else if(area->query("tax")>30)
						tell_object(who,"�������"+area->query("short")+"˰�ն����е㲻����"+area->query("short")+"��״�������������������\n");
					who->add("balance",amount);
					if(!who->save())
					{
						log_file("city_log","Failed to return "+amount+
						" coin to "+area->query("owner")+"\n");
						return;
					}
					log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
					tell_object(who,area->query("short")+"˰��"+MONEY_D->money_str(amount)+",�Ѿ�������Ļ�ͷ��\n");
				} else {
					who=new(USER_OB);
					who->set("id",area->query("owner"));
					if(!who->restore()) {
						log_file("city_log","Failed to return "+amount+
						" coin to "+area->query("owner")+"\n");
						destruct(who);
						return;
				} else {
					who->add("balance",amount);
					if(!who->save(1)) { // save(1) will not erase autoload.
						log_file("city_log","Failed to return "+amount+
						" coin to "+area->query("owner")+"\n");
						destruct(who);
						return;
					} 
					log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
					destruct(who);
				}
			}
		}
	}
	return;
}
******/
void event_noon()
{
	object *ob;
	int i, skill,con,con1,con2,con3;
	string get_month,ill,msg;
	object *user=users();

	get_month = CHINESE_D->chinese_month(TIME_TICK1);
	switch(get_month)
	{
		case "��":
		case "��":
		case "��":
			ill = "ill_kesou";
			msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
			break;
		case "��":
		case "��":
		case "��":
			ill = "ill_zhongshu";
			msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
			break;
		case "��":
		case "ʮ":
		case "ʮһ":
			ill = "ill_shanghan";
			msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
			break;
		case "ʮ��":
		case "һ":
		case "��":
			ill = "ill_dongshang";
			msg = HIG+"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"+NOR;
			break;
	}
	if(random(2))
	{
		ill = "ill_fashao";msg = HIG+"��ż�з纮����������������\n"+NOR;
	}
	ob = users();
	for(i=0; i<sizeof(ob); i++)
	{
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( ob[i]->query("age")==14 ) continue;
		con1 = ob[i]->query("kee");
		con2 = ob[i]->query("max_kee");
		(int)con = con1/con2*50;//�γɵ�һ�������ж�����
		con3 = ob[i]->query("force");
		con2 = ob[i]->query("max_force");
		if( con2 == 0) con2 = 1;
		(int)con1 = con3/con2*50;//�γɵڶ��������ж�����
		if(random(con)+random(50)+random(con1)<25)
		{
			ob[i]->apply_condition(ill, 10);
			tell_object(ob[i], msg);
		}
	}
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "�����һ����ѣ��������һ�����������ϱ��������ˡ�\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "����̫��������յ������룬�������ķ�����ʼ��ʧ�ˡ�\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
	message("channel:chat", CYN +"�����ġ�̫�ࣺʱ�������������˳�������ٹ��µ\n"+ NOR, users());
	for(i=0; i<sizeof(user); i++)
	{
		user[i]->delete_temp("dianmao");
		user[i]->save();
	}
}

string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
                month_desc[current_month]) + "��\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }
