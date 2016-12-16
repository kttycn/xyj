// call.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string objname,cname, func, euid, param;
	object obj;//,jingling;
	mixed *args, *sargs,result,maps,*temp,checking;
	int i;

	if( arg )
	{
		if( sscanf(arg, "-%s %s", euid, arg)==2 )//临时改变euid方法，这样输入即可
		{
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("你不能设定自己的 euid。\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );

		if( sscanf(arg, "%s->%s(%s", objname, func, param)!=3 ||param[<1]!=')')
			return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");
	} else
		return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");
	
	if( param[<1]==')')param=param[0..<2];//去掉最后面的 )
	
	param=replace_string( param ," ","");//去掉一切空格
	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("找不到指定的物件。\n");
 
	if(wizardp(obj) && wiz_level(me) < wiz_level(obj))
	   return notify_fail("你不能设定等级比你高的巫师状态。\n");
	   
	if (wiz_level(me) < 5 && !wizardp(obj) )
		return notify_fail("你不能设置玩家的数据！\n");
 
	if( userp(obj) ){
		if( obj != me ) log_file("static/CALL_PLAYER",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
	} else if( !master()->valid_write( base_name(obj), me, "set" ) )
		return notify_fail("你没有直接呼叫这个物件的函数的权力。\n");

	if (!userp(obj))
	{
	  log_file("static/CALL_NPC",
			sprintf("%s(%s) call %s(NPC)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1),func, param,
				ctime(time()) ) );
	}
 
	args = explode(param, ",");
	sargs=({})+args	;
	for(i=0; i<sizeof(args); i++) {
		//传进来的可能是array
		if(args[i][0..1]=="({"&&args[sizeof(args)-1][<2..<1]=="})")
		{
			temp=({});
			args[i]=args[i][2..];
			args[sizeof(args)-1]=args[sizeof(args)-1][0..<3]; 
            foreach(checking in args[i..])
            {              
              sscanf(checking, "\"%s\"", checking);
              sscanf(checking, "%d", checking);
              temp+=({checking});;
            }
			break;
		}
		//传进来的还可能是mapping      
		if(args[i][0..1]=="(["&&args[sizeof(args)-1][<2..<1]=="])")
		{		
			args[i]=args[i][2..];
			args[sizeof(args)-1]=args[sizeof(args)-1][0..<3];			
			maps=([]);
			foreach(checking in args[i..])
			{
			mixed a,b;
			if( sscanf(checking, "%s:%s", a, b)==2 ) 
			 { 
              sscanf(a, "\"%s\"", a);
              sscanf(b, "\"%s\"", b);
			  sscanf(b, "%d", b);//如果是数字就转成数字
			  maps[a]=b;
			  }
			}
			temp=maps;
			break;
		}
 		//输入端参数是字符串或数字
        if( sscanf(args[i], "\"%s\"", args[i]) ) continue;//字符串
	 	if( sscanf(args[i], "%d",args[i]) ) continue;//数字
	}
	args =args[0..i-1];
	args = ({ func }) + args;
	cname= (obj->query("name")|| obj->query("short"));
		if (obj&&sizeof(args)>1&&!wizardp(obj) && userp(obj))
		message("channel:chat",HIR"【监察精灵】公正法官(Faguan)："+"听说"+me->query("name")+
		"在修改玩家"HIW+cname+objname+HIR"的属性"+HIY+implode(sargs[0..sizeof(sargs)-1], "->(")+
		").\n" NOR,users());
	result = call_other(obj, args,temp);
    MONITOR_D->report_rumor_object_msg(me,"正在修改"HIW+cname+"("+
       (obj->query("id")|| file_name(obj))+")"HIM"的属性。\n "+param+"\n");
	tell_object(me, sprintf("%s%s->%s(%s) =\n %O\n", cname,objname, func,
        param, result));

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : call <物件>-><函数>(<参数>, ...... )
 
呼叫<物件>里的<函数>并传入相关<参数>.
 
HELP
    );
    return 1;
}
