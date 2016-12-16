#include <ansi.h>
#include <command.h>
#include <mudlib.h>
#pragma save_binary

string *quests;
string *roomlines;
mapping maps;

varargs void init_dynamic_quest(int hard);
varargs int spread_quest(string one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
int locate_quest(object me,string arg);
string dyn_quest_list();
string query_city(object loc);

void create()
{
   string file,dir,name;
   string* buf1;
   int i,size;

   maps=([]);
   file = read_file("/d/obj/quest/dynamic_location");
   roomlines = explode(file,"\n");
   file = read_file("/d/obj/quest/dynamic_quest");
   quests = explode(file,"\n");
//    file = read_file("/cmds/std/find.map");
    file = read_file("/adm/daemons/find.map");
   buf1 = explode(file,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
	 maps+=([dir:name]);
       }
     }
   }
   CRON_D->set_last_hard_dis();
//   init_dynamic_quest(1);
//	seteuid(getuid());
}

int quest_reward(object me, object who,object quest_item)
{
	int dx,exp,pot,score;

	if(who->query("name")!= quest_item->query("owner_name")) return 0;
		if(userp(who)) return 0;
	dx =200+random(200);
	exp =200+random(200);
	pot = dx/4;
	me->add("daoxing",dx);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("task_job",1);
	tell_object(me, sprintf("������"HIR"%s"NOR"���С�"HIR"%d"NOR"����ѧ��"HIY"%d"NOR"��Ǳ�ܣ�\n"NOR, COMBAT_D->chinese_daoxing(dx),exp,pot) );
	MONITOR_D->report_system_object_msg(me, HIG"�ҵ���"+quest_item->name()+",����"+who->name()+"�õ���"+COMBAT_D->chinese_daoxing(dx)+"���С�"+chinese_number(exp)+"����ѧ��"+chinese_number(pot)+"��Ǳ�ܡ�\n"NOR);
	log_file("task", sprintf("%s(%s) Ѱ��%s���õ�%d����%d��ѧ��%dǱ�ܣ�ʱ�䣺%s\n",me->name(1),geteuid(me),quest_item->name(),dx,exp,pot,ctime(time())));
    score=me->query_temp("dynamic_find");
	if(score+1==10){
		me->delete_temp("dynamic_find");
		me->add("daoxing",2000);
		me->add("score", 1);
		tell_object(me,"�����У���õ��� ������еĸ��ӽ�����\n");
		log_file("task", sprintf("%s(%s) ���õ�������еĸ��ӽ�����ʱ�䣺%s\n",me->name(1),geteuid(me),ctime(time())));
	}
	else me->set_temp("dynamic_find",score+1);

	return 1;
}

varargs void init_dynamic_quest(int hard)
{
	int i;
	object *user ;
	user = users();
	message("channel:chat",HIR"����Ӱ��ԵTASK�����Զ�������Ӱ��Ե�����\n"NOR,users());
	for( i=0; i < sizeof(quests)/2; i++)
		spread_quest(quests[i*2],hard);
}

varargs int spread_quest(string quest, int hard)
{
	object obj0,obj1,obj2,obj3;
	object cur_obj;
	object next_obj;
	object tar;
	object *inv;
	object *target=({});
	int i;
	string location;
	if(already_spreaded(quest,hard)) return 0;
	reset_eval_cost();
	location = roomlines[random(sizeof(roomlines))];
	obj0=find_object(location);
	if(obj0)
		obj0->reset();
	else
		obj0=load_object(location);
	cur_obj =obj0;
	if(cur_obj)
	{
		inv = all_inventory(cur_obj);
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->is_character() && !userp(inv[i]))
				target += ({ inv[i] });
			if(inv[i]->is_container()) target += ({ inv[i] });
		}
	}
	if(sizeof(target)) cur_obj = target[random(sizeof(target))];
	if(cur_obj)
	{
		tar = new(quest);
		tar->set("value",0);
		tar->move(cur_obj);
		write_file("/log/task",tar->query("name")+"---"+cur_obj->query("short")+location+"\n",0);
	}
	return 1;
}

string dyn_quest_list()
{
	string output;
	object item;
	int i;

	output="";
	for( i=0; i < sizeof(quests)/2; i++)
	{
		if(!objectp(item= find_object(quests[i*2])))
			item = load_object(quests[i*2]);
		if(already_spreaded(quests[i*2]))
		{
			if(random(2))
				output += sprintf(HIG"%10s"NOR"��"HIW"%10s"NOR"��%s��\n",
				item->query("owner_name"),item->query("name"),item->query("id"));
			else
				output=sprintf(HIG"%10s"NOR"��"HIW"%10s"NOR"��%s��\n",
				item->query("owner_name"),item->query("name"),item->query("id"))+output;
		}
		else
			if(random(2))
				output += sprintf(HIG"%10s"NOR"��"HIY"%10s"NOR"��%s�� [1;31m�� [32m�����[31m ��[m\n",
				item->query("owner_name"),item->query("name"),item->query("id"));
			else
				output=sprintf(HIG"%10s"NOR"��"HIY"%10s"NOR"��%s��[1;31m �� [32m �����[31m ��[m\n",
				item->query("owner_name"),item->query("name"),item->query("id"))+output;
	}
	output =" ��"HIM " ��"+ CHINESE_MUD_NAME+"��"HIY"��"NOR CYN+INTERMUD_MUD_NAME+HIG"  ʹ����\n"+
		"������������������������������������������������������\n"+output+
		"������������������������������������������������������\n\n";
	return output;
}

varargs int already_spreaded(string str,int hard)
{
	object ob,*ob_list;
	int i;
	if(!str) return 0;
	if(hard)
	{
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			ob=find_env(ob_list[i]);
			if(ob)
			{
				ob_list[i]->move(VOID_OB);
				destruct(ob_list[i]);
			}
		}
		return 0;
	}
	else
	{
		if(!str) return 0;
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			ob=find_env(ob_list[i]);
			if(ob)
				return 1;
		}
		return 0;
	}
}

object find_env(object ob)
{
	while(ob)
	{
		if(ob->query("exits") ) return ob;
		else ob=environment(ob);
	}
	return ob;
}

int locate_quest(object me, string arg)
{
	object loc;
	string qloc,msg,quest;
	string* exlst;
	object* itemlist;
	mapping exits;
	int index,i;

	if( ! arg)
		return notify_fail("locate <��Ʒid>\n");
	if(present(arg,me))
		return notify_fail("�����������������\n");

	if((index=member_array(arg,quests,0))>0)quest=quests[index-1];
	else return 1;

	if(!already_spreaded(quest)){
		tell_object(me,MAG"ˮ����"NOR"һ�㷴ӦҲû�У��·���������������������ϡ�\n");
		return 0;
	}

	itemlist = children(quest);
	for(index=0;index<sizeof(itemlist);index++){
		if(objectp(loc=find_env(itemlist[index]))){
			qloc = query_city(loc);
			exits=loc->query("exits");
			exlst=keys(exits);
			msg=HIW+itemlist[index]->query("name")+NOR"�·���"HIG+qloc+NOR"һ����";
			if(sizeof(exlst)){
				for(i=0;i<sizeof(exlst)-1;i++) msg+=exlst[i]+"��";
				msg+=exlst[sizeof(exlst)-1]+"���ڵĵط���\n";
				tell_object(me,MAG"ˮ����"NOR"��ʾ��\n"+msg);
				return 1;
			}
		}
	}
	tell_object(me,MAG"ˮ����"NOR"һ�㷴ӦҲû�С�\n");
    return 1;
}

string query_city(object loc)
{
	string filename,filename1;
	int len;

	filename=file_name(loc);
	len=strlen(filename);
	if(len<2) return "???";

	len--;
	while(filename[len]!='/' && len>0) {
		len--;
	}
	if(len<2) return "???";

	filename1=filename[1..(len-1)];
	return maps[filename1];
}
