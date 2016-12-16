// alias.c
#include <ansi.h>
//#pragma save_binary
#include <command.h>
#define MAX_REPEAT 50
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10

mapping alias;

nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int last_time=time(), cmd_cnt=0, kill_time=0, cmd_cnt1=0, cmd_cnt2=0;

// speed of player input commands.
int query_cmd_count() {return cmd_cnt2;}

string process_input(string str)
{
	string *args, cmd, argstr;
	int i, j, curr_time;//count, 
   // object ob,dest;
    object me = this_player();

	if (!query_heart_beat(me))
	{
		write("������û�������������µ�½!!\n");
		"/cmds/usr/quithy"->main(me);
	}

    if( me->query_temp("disable_inputs") )   return HIR"ʲô��\n"NOR;
    if( me->query_temp("block_msg/all") )   return HIR"�㿴����ʲô,ʲô��������!\n"NOR;
	       
	reset_eval_cost();
	// added by mon 5/18/98 to clear up eval_counter.
	// it seems that if one input many commands in a raw,
	// then the eval_counter is not cleared in time, and
	// thus causing Too long evaluation error.

	str = CONVERT_D->input(str,this_object());

// by mon 7/19/97. command counting.
	cmd_cnt++;
	if(cmd_cnt>100) {  //threshold for how many commands can be
	                  //input every few seconds.(determined below)
		curr_time=time();
		if(curr_time-last_time<5) {
			if(cmd_cnt1==0){
				cmd_cnt2=cmd_cnt/(curr_time-last_time+1);
				write("��һ������̫�������ˡ�\n");
			}
			cmd_cnt1++;
			if(cmd_cnt1>30) cmd_cnt1=0;
				last_time=curr_time; 
	     //in case of flooding, has to wait a few
	     //seconds without input to be able to
	     //input again.
			return HIR"ʲô��\n"NOR;;  //flooding detected. ignore input.
		} else {
			cmd_cnt2=cmd_cnt/(curr_time-last_time+1);
			last_time=curr_time;
			cmd_cnt=0;
			cmd_cnt1=0;
		}
	}


	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) ) {
			        if(i<0) i=0;
			        else i=i%HISTORY_BUFFER_SIZE;
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			}  else
				str = history[last_cmd];
			if(!str) return "";
		} else
			return ""; 
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}

	if( mapp(alias) ) {

		if( !undefinedp(alias[str]) )
			return replace_string( alias[str], "$*", "" );

		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}

	return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
	if( !replace ) {
		if( mapp(alias) ) map_delete(alias, verb);
		return 1;
	} else {
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
		else alias[verb] = replace;
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}

