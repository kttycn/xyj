#include <ansi.h>;
inherit BULLETIN_BOARD;

string chinese_time(int type,string get_time)
{
	string e_time, week, month, year;
	string c_week, c_year, c_month, c_time;
	int day, hour, minute, second;
	string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
		"Aug","Sep","Oct","Nov","Dec"});
	string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

	if ( stringp(get_time) )
		e_time = get_time;
	else e_time = ctime(time());

	sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

	c_week  = chinese_number(member_array(week, week_name) + 1);
	c_month = chinese_number(member_array(month, month_name) + 1);

	c_year  = sprintf("%s%s%s%s",
		chinese_number(year[0]-48),
		chinese_number(year[1]-48),
		chinese_number(year[2]-48),
		chinese_number(year[3]-48));

	c_year = c_year + "��";
	c_month  = c_month + "��";
	c_week = " ����"+c_week;

	c_time = chinese_number(day) + "��";
	c_time += chinese_number(hour) + "��";
	c_time += chinese_number(minute) + "��";
// maybe not need srcond to show
	c_time += chinese_number(second) + "��";

	if (type) {
		switch( type ) {
			case 5: return c_year+c_month+c_time+c_week;
			case 2: return c_year+c_month+c_time;
			case 3: return c_month+c_time+c_week;
			case 4: return c_month+c_time;
			case 1: return year+"��"+(member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��"+second+"��";
			case 6: return (member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��";
			case 7: return year+"/"+(member_array(month, month_name) + 1)+
				"/"+day+"";
			default: return c_year+c_month+c_time+c_week;
		}
	}
	return c_year+c_month+c_time+c_week;
}

void create()
{
	set_name(MAG"��Ӱ��Ե"HIY"���ŷ�������"NOR, ({ "newsboard"}) );
	set("location", "/d/wiz/newsroom"); // ��������һ��ROOM������BOARD
	set("board_id", "news_b");
	setup();
	set("capacity", 1000);
	set("no_clean_up", 1);
}

// ���������������loginʱ���õġ�
int check_news(object me)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg="";
	
	notes = query("notes");
	last_read_time = me->query("board_last_read");
	myid = query("board_id");
	
	if( !pointerp(notes) || !sizeof(notes) ) return 1;

 	if(userp(me))
	{
		i=sizeof(notes)-me->query("LastReadNews");
		
		if(i < 6 && i > 0) // С��6�����Ų���ʾ���⣬��Ȼ��FLOOD
		{
			msg = "\n\n    ������������������������ "HIW"��Ӱ��Ե������Ϣ"NOR" ������������������������    \n";
			
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
				
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
					
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>num-2 ; i--)
			{
				msg += sprintf("<%3d>"NOR,i+1);
				msg += sprintf("     %-=36s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
//					CHINESE_D->chinese_time(5, ctime(notes[i]["time"])));
					chinese_time(7,(string)localtime(time()) ));
			}
			msg += "                                                  ��"MAG"��Ӱ��Ե"NOR" ��ʦ�顽\n";
			msg += HIC"��������������������������������������������������������������������������\n\n"NOR;
			
			me->start_more(msg);
		}
		
		i=sizeof(notes)-me->query("LastReadNews");
		
		write("\n�����ϴ��Ķ�������"+((i==0)? "û���κ�":"����"+HIY+chinese_number(i)+NOR"��")+"���š�\n\n");
		if(i>10) write("����� Help news ���鿴��Ӱ��Ե����ϵͳ��ʹ�÷�����\n"); // ���Ѳ�֪����NEWSϵͳ�����ʹ��news
	}
}

int main(object me, string arg)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg,title,number;

	last_read_time = me->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");
	i=sizeof(notes)-me->query("LastReadNews");
	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail(HIC"��"NOR+MAG"��Ӱ��Ե"HIC"��Ŀǰû���κ����š�\n"NOR);
		
	if( !arg ) 
	{
		if(i>10)
			write(HIC"�����"HIR" Help news "HIC"���鿴"NOR+MAG"��Ӱ��Ե"HIC"����ϵͳ��ʹ�÷�����\n"NOR);
		if(i<0){
			me->set("LastReadNews",sizeof(notes));
			i=0;
		}
		return notify_fail(
			"����Ӱ��Ե��Ŀǰ����"+HIW+chinese_number(sizeof(notes))+NOR"������"+((i==0)? "��":"������"+HIY+chinese_number(i)+NOR"��������δ�Ķ���")+"\n");
	}

	if (sscanf(arg,"add %s",title)==1) {
		if (!title) return notify_fail("��ָ��һ�����ŵı��⡣\n");
		if (!wizardp(me)) return notify_fail("�Բ���ֻ��"MAG"��Ӱ��Ե"NOR"����ʦ�ſ��Է������š�\n");
		else {
			do_post(title);
			return 1;
		}
	}

	if (sscanf(arg,"del %s",number)==1)
	{
		if (!number) return notify_fail("��Ҫɾ����һ����ŵ����ţ�\n");
		if (!wizardp(me)) return notify_fail("�Բ���ֻ��"MAG"��Ӱ��Ե"NOR"����ʦ�ſ���ɾ�����š�\n");
		else {
			do_discard(number);
			return 1;
		}
	}

	if( arg=="all") // ��ʾ��������
	{
		msg = "\n\n���������������������������� "MAG"��Ӱ��Ե"HIW"����һ��"NOR" ��������������������������������\n";
		notes = query("notes");

		if (mapp(last_read_time)) last_time_read = last_read_time[myid];
		for(i=sizeof(notes)-1 ; i>-1 ; i--)
		{
			msg += sprintf("%s<%3d>" NOR,
				notes[i]["time"] > last_time_read ? HIY: "", i+1);
				msg += sprintf("     %-=36s %18s (%s)\n",
				notes[i]["title"], notes[i]["author"],
//				ctime(notes[num]["time"])[0..15]);
				chinese_time(7,(string)localtime(time())) );
		}
		msg += "\n";
		me->start_more(msg);
		return 1;
	}
	if ( arg=="new" )  // ��ʾ��������
	{
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("�㵽��Ҫ���ڼ�������ѽ��\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("������㣬����û����������Ү��\n");
		
	num--;
	me->start_more( sprintf("\n\n%s\n"HIY"�������⣺"NOR"%s\n"HIY"������ʦ��"NOR"%s\n"HIY"����ʱ�䣺"NOR"%s\n"NOR
	CYN"-------------------------------------------------------------------------------\n"NOR,
		BBLU HIG"��"NOR+MAG"��Ӱ��Ե"HIG"����"+chinese_number(num + 1)+"������"NOR, 
		notes[num]["title"], notes[num]["author"],
		chinese_time(7,(string)localtime(time())) )
		+ notes[num]["msg"]+
	CYN"-------------------------------------------------------------------------------\n\n"NOR, );

	if( !mapp(last_read_time) )
		me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	if(me->query("LastReadNews") > num )
		me->set("LastReadNews",num);
	if(me->query("LastReadNews") < num + 1)
		me->add("LastReadNews",1);

	return 1;
}

void init()
{
	object me=this_player();
	if (wizardp(me) &&  wiz_level(me) > wiz_level("(apprentice)") )
	{
		add_action("do_post", "post");
		add_action("do_discard", "discard");
	}
}

int do_discard(string arg)
{
	mapping *notes;
	int num;
	object me = this_player();
	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("ָ���ʽ��discard <���Ա��>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	if( notes[num]["author"] != (string) this_player(1)->query("name")+
	"("+capitalize(this_player(1)->query("id"))+")"
	&& (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
	&& (string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
		log_file("POSTING", ctime( time() )+": "
		+me->query("name")+"("+me->query("id")+")"
		+" discarded "+(num+1)+".\n");
	return 1;
}

int do_post(string arg)
{
	mapping note;

	if(!arg) return notify_fail("����Ҫ������Ŀ��\n");

	note = allocate_mapping(4);
	note["title"] = arg;
      note["author"] = this_player()->query("name")+"("+this_player()->query("id")+")";
	note["id"] = this_player()->query("id"); 
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}

void done_post(object me, mapping note, string text)
{
	mapping *notes;

	note["time"] = time();
	note["msg"] = text;
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	if( sizeof(notes) > query("capacity"))
		notes = notes[query("capacity")/2 .. query("capacity")];

	set("notes", notes);
	save();
	restore();
// ʹ��channel��ʾ��ʾ������������
//	message("channel:chat", HIC"�����ŷ�������"NOR MAG"��Ӱ��Ե"FLA YELCYN"�������¸������ţ����� "NOR HIR"news"FLA YELCYN" �鿴������ \n"NOR, users());
	message("channel:chat", HIC"�����ŷ���������Ӱ��Ե�������¸������ţ����� "FLA HIR"news"NOR HIC" �鿴������ \n"NOR, users());

	tell_object(me, "���ŷ�����ϡ�\n");

	return;
}

int help(object me)
{
    write(@HELP
����Ӱ��Ե������ϵͳָ�� 

ָ���ʽ :
news                    �鿴���еĺ����·��������š�
news all                ��Ӱ��Ե����һ���� 
news new                �Ķ����µ����š� 
news del <���ű��>     ɾ�����š�
news add <���ű���>     д�µ����š�
news <���ű��>         �鿴�˱�����ŵ���ϸ���ݡ� 
HELP
    );
    return 1;
}
