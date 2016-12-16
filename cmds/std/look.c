//#pragma save_binary
#include <room.h>
#include <ansi.h>
#include <combat.h>

#define TIME_TICK1 ((time()-900000000)*60)

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string do_query(object obj);

// mon 6/6/98
string *tough_level_desc = ({
        BLU "����һ��" NOR,BLU "��������" NOR,BLU "����ҳ�" NOR,BLU "��ѧէ��" NOR,BLU "����ǿǿ" NOR,
        HIB "�����ž�" NOR,HIB "����é®" NOR,HIB "��֪һ��" NOR,HIB "����ͨͨ" NOR,HIB "ƽƽ����" NOR,
        CYN "ƽ������" NOR,CYN "��ͨƤë" NOR,CYN "��������" NOR,CYN "������" NOR,CYN "����С��" NOR,
        HIC "����С��" NOR,HIC "������Ⱥ" NOR,HIC "�������" NOR,HIC "�������" NOR,HIC "�ڻ��ͨ" NOR,
        GRN "�������" NOR,GRN "¯����" NOR,GRN "��Ȼ����" NOR,GRN "���д��" NOR,GRN "���д��" NOR,
        YEL "��Ȼ��ͨ" NOR,YEL "�������" NOR,YEL "�޿�ƥ��" NOR,YEL "����Ⱥ��" NOR,YEL "����似" NOR,
        HIY "�����뻯" NOR,HIY "��ͬ����" NOR,HIY "����Ⱥ��" NOR,HIY "�Ƿ��켫" NOR,HIY "�����ױ�" NOR,
        HIM "��������" NOR,HIM "һ����ʦ" NOR,HIM "�������" NOR,HIM "�񹦸���" NOR,HIM "������˫" NOR,
        HIR "��������" NOR,HIR "���춯��" NOR,HIR "������" NOR,HIR "������ʥ" NOR,HIR "�������" NOR,
        RED "��ǰ����" NOR,RED "���˺�һ" NOR,MAG "��ز�¶" NOR,WHT "��ɲ�" NOR,HIW "��豹���" NOR
});

string *heavy_level_desc= ({
	"����",
	"����",
	"����",
	"��֪����",
	"����",
	"����",
	"����",
	"��������",
	"��������",
	"����ѽ���㾹Ȼ����������"
});

string *peep_msg = ({
	"��������̽ͷ̽�Ե�����������˼��ۡ�\n",
	"$N̽ͷ̽�Ե�����������˼��ۡ�\n",
	"���Ȼ�����ƺ���˫�۾��ڱ������㿴��\n",
	});

string *look_level_boy = ({
	BLU "ü����б����ͷѢ�ţ���������\n" NOR,
	BLU "�������죬������ף�����ޱ�\n" NOR,
	BLU "�����Ƥ��ͷ���������˲����ٿ��ڶ���\n" NOR,
	HIB "��ü���ۣ�������ߣ�������״\n" NOR,
	HIB "��ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц\n" NOR,
	NOR "��հ��ݣ��ݹ����꣬������̾\n" NOR,
	NOR "ɵͷɵ�ԣ��ճպ�����������Ҳ��ʵ\n" NOR,
	NOR "��òƽƽ�������������ʲôӡ��\n" NOR,
	YEL "�����Բ���������⣬���ζ���\n" NOR,
	YEL "��Բ���������ڷ����Ǹ񲻷�\n" NOR,
	RED "üĿ���㣬�����󷽣�һ���˲�\n" NOR,
	RED "˫�۹⻪Ө��͸���������ǵĹ�â\n" NOR,
	HIY "�ٶ���������ˮ�����̷��飬������������Ŀ��\n" NOR,
	HIY "˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ�\n" NOR,
	HIR "�����촽�����˿��Σ���ֹ��������\n" NOR,
	HIR "��������Ŀ�����ǣ����˹�Ŀ����\n" NOR,
	MAG "�������񣬷�ױ��������������\n" NOR,
	MAG "Ʈ�ݳ�������������\n" NOR,
	MAG "�����ʣ��������������������ٷ�\n" NOR,
	HIM "������ˬ���Ǹ����棬��������\n" NOR,
	HIM "һ���������ȣ��ɷ���ǣ���ֹ����\n" NOR,
});

string *look_level_girl = ({
	BLU "�������Σ�״��ҹ��\n" NOR,
	BLU "���б�ۣ���ɫ�Ұܣ�ֱ����һ��\n" NOR,
	BLU "����ü�������ۣ���Ƥ�Ʒ�������һ��������\n" NOR,
	HIB "��С�綹��üëϡ�裬�����צ����������\n" NOR,
	HIB "һ�����������һ����û�ø�\n" NOR,
	NOR "�������Ƥɫ�ֺڣ���ª����\n" NOR,
	NOR "�ɻƿ��ݣ���ɫ���ƣ�����Ů��ζ\n" NOR,
	YEL "�����С�������޹⣬��������\n" NOR,
	YEL "�䲻���£���Ҳ�׾�����Щ����֮��\n" NOR,
	RED "����΢�ᣬ�ŵ��������¿���\n" NOR,
	RED "�������ģ�����Ө͸��������˼\n" NOR,
	HIR "��С���磬���������������������\n" NOR,
	HIR "�������󣬼���ʤѩ��Ŀ����ˮ\n" NOR,
	HIW "���۰���������ҩ���̣����￴��\n" NOR,
	HIW "����ϸ������欶��ˣ�����һ������������\n" NOR,
	MAG "�����������������£�����ܳ�������\n" NOR,
	MAG "üĿ�续������ʤѩ�����ν�����߻�\n" NOR,
	MAG "�������������Ż���ɽ�����˼�֮����\n" NOR,
	HIM "������ϼ���������񣬻�����������\n" NOR,
	HIM "�������ɣ���մһ˿�̳�\n" NOR,
	HIM "����"+HIW+"������"+HIM+"�������ƻã��Ѳ����Ƿ�������\n" NOR,
});

string *per_msg_kid1 = ({
	CYN "��ü���ۣ�����ʮ�㡣\n" NOR,
	CYN "������ã���̬�Ƿ���\n" NOR,
	CYN "�������£�ɫ��������\n" NOR,
});

string *per_msg_kid2 = ({
	CYN "¡����ۣ���ɫ����\n" NOR,
	CYN "�����ལ�����ϲ����\n" NOR,
	CYN "ϸƤ���⣬�ڳ�������\n" NOR,
});

string *per_msg_kid3 = ({
	CYN "����󰫣�ɵ��ɵ����\n" NOR,
	CYN "�ʷ����֣�С��С�ۡ�\n" NOR,
	CYN "��ͷ���ԣ����ֱ��š�\n" NOR,
});

string *per_msg_kid4 = ({
	CYN "��ͷ���ţ����Ƽ��ݡ�\n" NOR,
	CYN "����ľ�������в�ɫ��\n" NOR,
	CYN "��ٲ�������֫���ࡣ\n" NOR,
});

string *per_msg_wiz = ({
	HIY "ȫ��ɢ����ҫ�۵Ľ�⣬����������֮������� \n" NOR,
	MAG "ȫ��ɢ����ҫ�۵Ľ�⣬����������֮������� \n" NOR,
});

// snowcat 12/20/97
string ride_suffix (object me)
{
	string ridemsg = 0;
	object ridee = 0;

	ridee = me->ride();
	if (ridee)
		ridemsg = ridee->query("ride/msg")+"��"+ridee->name()+"��";
	return ridemsg;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str, str1="", str2="", *dirs;
	string ridemsg = "";

	if( !env ) {
		write(WHT"������ܻ����ɵ�һƬ��ʲôҲû�С�\n"NOR);
		return 1;
	}
	str = sprintf( "%s%s\n%s%s",
	env->query("short")?(env->query("outdoors")?HIR"��"HIG+(string)env->query("short")+HIR"��"NOR:HIR"��"HIY+(string)env->query("short")+HIR"��"NOR): "",
	wizardp(me)?WHT+"   - "+file_name(env)+NOR: "",
	env->query("long")? env->query("long"): "\n",
	env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if ( env->query("outdoors") &&
		!present("fire", this_player()) &&
		!this_player()->query_temp("armor/lamp") &&
		!wizardp(this_player()) &&
		((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ")>0 ) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ")>0 ) ||
		(strsrch(CHINESE_D->chinese_date(TIME_TICK1), "��ʱ")>0 )))
			str += BLU + "    ��ɫ̫���ˣ��㿴�������Եĳ�·��\n"NOR;
		else if (env->query("no_look") && !wizardp(me))
			str += HIB"    ����ĳ�·���������\n"NOR;
		else if( sizeof(dirs)==0 )
			str += HIM"    ����û���κ����Եĳ�·��\n"NOR;
		else if( sizeof(dirs)==1 ) {
			str += HIC"    ����Ψһ�ĳ����� " +NOR+HIG+BOLD + dirs[0] + NOR;
			if (env->query("no_look"))
			    	str += HIB"<������>"NOR;
			str += "��\n";

		} else {
			str += sprintf(HIW"    �������Եĳ����� "+NOR+HIG + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR,
				implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
			if (env->query("no_look"))
				str += " <������>";
			str += "��\n";
		} 
	}
//	str += env->door_description();

/*	if( mapp(exits =env->query("exits")) ) {
		dirs=keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
			dirs -= ({ 0 });
		if (sizeof(dirs)!=0)
		{  
			write(SAVEC);

			for (i=0;i<sizeof(dirs);i++)
			switch(dirs[i]) {
			case "north":
				write(SETDISPLAY(3,72)+"����");
				room=load_object(exits["north"]);
				write(SETDISPLAY(2,70)+clean_color(room->query("short")));
				break;
			case "south":
				write(SETDISPLAY(5,72)+"����");
				room=load_object(exits["south"]);
				write(SETDISPLAY(6,70)+clean_color(room->query("short")));
				break;
			case "east":
				room=load_object(exits["east"]);
				write(SETDISPLAY(4,80)+clean_color(room->query("short")));
				write(SETDISPLAY(4,78)+"��");
				break;
			case "west":
				
				room=load_object(exits["west"]);
				write(SETDISPLAY(4,60)+clean_color(room->query("short")));
				write(SETDISPLAY(4,68)+"��");
				break;
			case "westup":
				
				room=load_object(exits["westup"]);
				write(SETDISPLAY(4,60)+clean_color(room->query("short")));
				write(SETDISPLAY(4,68)+"��");
				break;
			case "eastup":
				
				room=load_object(exits["eastup"]);
				write(SETDISPLAY(4,80)+clean_color(room->query("short")));
				write(SETDISPLAY(4,78)+"��");
				break;
			case "northup":
				write(SETDISPLAY(3,72)+"����");
				room=load_object(exits["northup"]);
				write(SETDISPLAY(2,70)+clean_color(room->query("short")));
				break;
			case "southup":
				write(SETDISPLAY(5,72)+"����");
				room=load_object(exits["southup"]);
				write(SETDISPLAY(6,70)+clean_color(room->query("short")));
				break;
			case "southdown":
				write(SETDISPLAY(5,72)+" ���� ");
				room=load_object(exits["southdown"]);
				write(SETDISPLAY(6,70)+clean_color(room->query("short")));
				break;
			case "northdown":
				write(SETDISPLAY(3,72)+" ���� ");
				room=load_object(exits["northdown"]);
				write(SETDISPLAY(2,70)+clean_color(room->query("short")));
				break;
			case "eastdown":
				room=load_object(exits["eastdown"]);
				write(SETDISPLAY(4,80)+clean_color(room->query("short")));
				write(SETDISPLAY(4,78)+"=��");
				break;
			case "westdown":
				room=load_object(exits["westdown"]);
				write(SETDISPLAY(4,60)+clean_color(room->query("short")));
				write(SETDISPLAY(4,68)+"-=");
				break;
			case "northwest":
				write(SETDISPLAY(3,68)+"\\\\");
				room=load_object(exits["northwest"]);
				write(SETDISPLAY(2,60)+clean_color(room->query("short")));
				break;
			case "southwest":
				write(SETDISPLAY(5,68)+"////");
				room=load_object(exits["southwest"]);
				write(SETDISPLAY(6,60)+clean_color(room->query("short")));
				break;
			case "northeast":
				write(SETDISPLAY(3,76)+"////");
				room=load_object(exits["northeast"]);
				write(SETDISPLAY(2,80)+clean_color(room->query("short")));
				break;
			case "southeast":
				write(SETDISPLAY(5,76)+"\\\\");
				room=load_object(exits["southeast"]);
				write(SETDISPLAY(6,80)+clean_color(room->query("short")));
				break;
		}
	}
*/
	inv = all_inventory(env);
	i=sizeof(inv);
	str2 = "";
	while(i--) {
	    	str1 = "";
		if( !me->visible(inv[i]) ) continue;
		if( inv[i]==me ) continue;
		if (env->query("no_look"))
		{
		    	str1 += HIB"  " + "ģ����Ӱ��"NOR;
			if (! wizardp(me))
			{
			    	str1 += "\n";
				str += str1;
			    	continue;
			}
		}
		if (ridemsg = ride_suffix(inv[i]))
			str1 += "  " + inv[i]->short() + " <"+ridemsg +
			  ">";
		else	
			str1 += "  " + inv[i]->short();
		if (env->query("no_look"))
		    	str1 += HIB" <������>"NOR;
	    	str1 += "\n";
		str2 = str1 + str2;
	}
	write(str+str2);

	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;

//	write(obj->long());

	me->start_more(obj->long());
	
	//added by weiqi for self-made fabao
	if( obj->query("series_no") && obj->query("fabao") ) 
	    write(obj->show_status());
	
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("�����У�\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}
string per_status_msg(int age, int per, string gender)
{
	// added by snowcat 
	if (age < 14) {
		if ( per>=25 )
			return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
		else if ( per>=20 )
			return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
		else if ( per>=15 )
			return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
		else 	return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
		}
		
	if ( gender == "����" ) {
		if ( per>=10&&per<=30 )
			return ( look_level_boy[per-10]);
		else if (per>30)
		       return ( look_level_boy[20]);
		else return "����������ûʲô���\n";

		}
		
	if ( gender == "Ů��" ) {
		if ( per>=10&&per<=29 )
			return ( look_level_girl[per-10]);
		else if (per>29)
		       return ( look_level_girl[20]);
		else return "����������ûʲô���\n";

                }
	else return "";
//	else return "����������ûʲô���\n";
}

int look_living(object me, object obj)
{
	string str, ridemsg, pro;//, limb_status
	mixed *inv;
	mapping my_fam, fam;
// added for bian by mon.
	mapping ofamily;
	string ogender,orace;
	int oage, equip, wearornot;
 
	if(obj->query_temp("d_mana")>0) 
	{
		ofamily=obj->query_temp("family");
		ogender=obj->query_temp("gender");
		orace=obj->query_temp("race");
		oage=obj->query_temp("age");
	} 
	else 
	{
		ofamily=obj->query("family");
		ogender=obj->query("gender");
		orace=obj->query("race");
		oage=obj->query("age");
//fake_age is set as the age when player �����ֻء�
//so later on, he/she always looks like the age of that time:)
//but need a "look" to activate all the relatived settings...weiqi
//only when one is not in the status of "bian", check his/her
//fake_age. mon 9/4/97
/*
		if(obj->query("life/live_forever") ) 
		{ 
			//set the fake_age if not set...
			if( obj->query("fake_age") ) obj->set("fake_age", oage);

			if( oage>obj->query("fake_age") ) 
			{
			//if "age" is less than fake_age, reset fake_age.
			//mon 9/4/97
				oage=obj->query("fake_age");
			}
			else if( oage<obj->query("fake_age") ) 
			{
				obj->set("fake_age", oage);
			}
		}
	}


*/
     if(obj->query("life/live_forever") )
       {
          if (!obj->query("fake_age")) obj->set("fake_age",oage);
         if (oage > obj->query("fake_age")) oage=obj->query("fake_age");       }
     if (obj->query_condition("makeup"))
     if (obj->query("fake_age_x"))
         oage=obj->query("fake_age_x");
//done with fake_age
     }
	if( me!=obj && obj->visible(me) && environment(me) &&
	    !environment(me)->query("no_look") )
		message("vision", MAG+me->name() + "�������㿴����֪����Щʲô���⡣\n"NOR, obj);

	str = obj->long();

	str = replace_string(str, "$n", me->name());
	str = replace_string(str, "$N", obj->name());
    str = replace_string(str, "$C", RANK_D->query_respect(obj));
    str = replace_string(str, "$c", RANK_D->query_rude(obj));
	str = replace_string(str, "$R", RANK_D->query_respect(me));
	str = replace_string(str, "$r", RANK_D->query_rude(me));


	pro = (obj==me) ? gender_self(ogender) : gender_pronoun(ogender);

        if(obj->query_temp("d_mana")==0 || obj->query_temp("is_character")) {
	
	if( orace=="����"
	&&	intp(oage) )
		if(oage<10) {
			str += sprintf("%s��������Ȼ������ʮ�ꡣ\n", pro);
		}
		else{
			str += sprintf("%s��һλ%s�����%s��\n", pro, chinese_number(oage / 10 * 10),RANK_D->query_respect(obj));
		}

	if((obj->parse_command_id_list())[0]==me->query("couple/id") ) {
		if( (string)me->query("gender")=="Ů��" ){
		str += sprintf("%s������ɷ�\n", pro);
		}
		else{
			str += sprintf("%s��������ӡ�\n", pro);
		}
	}
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = ofamily)
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
	
		if( fam["generation"]==my_fam["generation"] ) {
			if( ogender == "����" )
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( member_array(my_fam["master_id"],
			    obj->parse_command_id_list())>-1  )
				str += pro + "�����ʦ����\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "�����ͬ�ų�����\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "�����ʦ����\n";
			else
				str += pro + "�����ʦ�塣\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "�����ͬ������\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "����ĵ��ӡ�\n";
			else
				str += pro + "�����ʦֶ��\n";
		}
	}

/*	if( obj->query("max_kee") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";
*/

//here, if per>=100, no rong-mao description, it'll be necessary sometimes.
//return special looking first if he/she has one.

	if( wizardp(obj)) {
		if( obj->query("looking") ){
			str += pro + (string)obj->query("looking") + "\n";
		} else {
			string looking= per_msg_wiz[random(sizeof(per_msg_wiz))];
			if( strlen(looking)>1 && obj->query("per") < 100 )
				str += pro + looking;
		}
	}
	else if( obj->query("looking") ){
		str += pro + "����" + (string)obj->query("looking") + "\n";
	} else {
	  string looking= per_status_msg((int)obj->query("age"),
	         (int)obj->query_per(), ogender);
              if( strlen(looking)>1 && obj->query("per") < 100 )
        	         str += pro + "����" + looking;
	}

//	str+=getper(me,obj);
	str += pro + sprintf("���书����������");
	str+=gettof(me,obj);
	str += sprintf("��");
	str +=sprintf("\n�����ƺ�");
	str +=getdam(me,obj);
	str += sprintf("��\n");

	ridemsg = ride_suffix(obj);
	if (ridemsg)
		str += pro + "��" + ridemsg + "��\n";
		
   wearornot = 0;
   inv = all_inventory(obj);
	for(equip=0; equip<sizeof(inv); equip++)
	{
		if( inv[equip]->query("equipped") ) wearornot = 1;
	}
	if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
		str += pro+HIY"ȫ������һ˿����, �ѵ����㱼��������\n"NOR;

	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "ֻ��%s��\n%s\n",
				pro, implode(inv, "\n") );
	}
        
	}

        me->start_more(str);

	if( obj!=me 
	&&	living(obj)
	&&	random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
		write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
		return 1;
	}

//this part is  taken from attack.c
//mon 1/22/98
/*
	if( obj!=me 
	&& living(obj)
	&& userp(obj)
        && random((int)obj->query("bellicosity")/40) > (int)obj->query("cps") ) 
	  COMBAT_D->auto_fight(obj, me, "berserk");
*/

	return 1;
}

string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	int attack_points;
	if( objectp(weapon = ob->query_temp("weapon")) )
	{
		skill_type = weapon->query("skill_type");
		parry_type = "parry";
	}
	else
	{
		skill_type = "unarmed";
		parry_type = "unarmed";
	}

//	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	attack_points = ob->query_skill(skill_type,1);

	return  tough_level(attack_points);
}

string inventory_look(object obj, int flag)
{
	string str;
	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  ��" NOR + do_query(obj);
	else if( !flag )
		str = "    " + str;
	else return 0;
	return str;
}


int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
			
		return 1;
	}
    	if (env->query("no_look"))
  		return notify_fail("��ʲôҲ��������\n");
	if( mapp(exits = env->query("exits")) && exits[arg] && !undefinedp(exits[arg]) ) {
		if( (objectp(exits[arg]) && env=exits[arg]) ||
		    objectp(env = load_object(exits[arg])) ) {
			look_room(me, env);
			if(!me->query("env/invisibility") && random(3)==0
				&& env!=environment(me) ) {
			    string msg=peep_msg[random(sizeof(peep_msg))];
			    msg=replace_string(msg,"$N",me->name());
			    tell_room(env, msg);
			}
		} else {
		  return notify_fail("��ʲôҲ��������\n");
		}
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	int spi, weight;//, level

	spi = this_player()->query_spi();
// ���Բ���˿��Ĳ�׼
	if(power<0) power=0;
	rawlvl = power/10;
	lvl = to_int(rawlvl/grade);
	if( lvl >= sizeof(tough_level_desc) )
		lvl = sizeof(tough_level_desc)-1;

//	write ( printf("\n������ԣ�%d��ԭ�ȼ�%d��\n",spi, lvl));
	if (spi>35) weight = 0;
	else weight = random((35 - spi)/4);
	if (lvl > sizeof(tough_level_desc)/2) lvl = lvl - weight;
	else lvl = lvl + weight;

	if (lvl<0) lvl = 0;
//	write ( printf("\n���ת����ȼ���%d��\n",lvl));
	return tough_level_desc[((int) lvl)];
}

string getdam(object me, object obj)
{
	int level;
	object weapon;
	string skill_type;

	if( objectp(weapon = obj->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	level = COMBAT_D->skill_power(obj, skill_type, SKILL_USAGE_ATTACK);
	level = level / 500000;
	if( level >= sizeof(heavy_level_desc) )
		level = sizeof(heavy_level_desc)-1;
	if (level<0) level = 0;
	return heavy_level_desc[((int) level)];
}

string do_query(object obj)
{
        string str,units;

        units =obj->query("unit");
        str = obj->short();
        if (obj->query("armor_type"))
        switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":
                        str = "��һ"+ units + str;
                        break;
                case "boots":
                        str = "���ϴ���һ" + units + str;
                        break;
                case "head":
                        str ="ͷ��һ"+ units + str;
                        break;
                case "neck":
                case "wrists":
                case "waist":
                case "finger":
                case "hands":
                        str ="����һ"+ units + str;
                        break;
                case "waist":
                        str = "��������һ"+units+str;
                        break;
                case "surcoat":
                        str = "����һ"+units+str;
                        break;
                case "lamp":
                        str = "��������һ"+units+str;
                        break;
                case "flower":
                        str = "ͷ�ϴ���һ"+units+str;
                        break;
                default:
                        str = "װ����"+str; 
                        }
        else
        if( obj->wield() )
                if (obj->query("skill_type")=="throwing")
                str ="���ϴ���"+str;
                else
                str ="�ֳ�һ" + units + str;
        return str;     
}

int help (object me)
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
	return 1;
}
