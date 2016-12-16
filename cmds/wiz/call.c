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
		if( sscanf(arg, "-%s %s", euid, arg)==2 )//��ʱ�ı�euid�������������뼴��
		{
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("�㲻���趨�Լ��� euid��\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );

		if( sscanf(arg, "%s->%s(%s", objname, func, param)!=3 ||param[<1]!=')')
			return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
	} else
		return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
	
	if( param[<1]==')')param=param[0..<2];//ȥ�������� )
	
	param=replace_string( param ," ","");//ȥ��һ�пո�
	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("�Ҳ���ָ���������\n");
 
	if(wizardp(obj) && wiz_level(me) < wiz_level(obj))
	   return notify_fail("�㲻���趨�ȼ�����ߵ���ʦ״̬��\n");
	   
	if (wiz_level(me) < 5 && !wizardp(obj) )
		return notify_fail("�㲻��������ҵ����ݣ�\n");
 
	if( userp(obj) ){
		if( obj != me ) log_file("static/CALL_PLAYER",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
				ctime(time()) ) );
	} else if( !master()->valid_write( base_name(obj), me, "set" ) )
		return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

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
		//�������Ŀ�����array
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
		//�������Ļ�������mapping      
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
			  sscanf(b, "%d", b);//��������־�ת������
			  maps[a]=b;
			  }
			}
			temp=maps;
			break;
		}
 		//����˲������ַ���������
        if( sscanf(args[i], "\"%s\"", args[i]) ) continue;//�ַ���
	 	if( sscanf(args[i], "%d",args[i]) ) continue;//����
	}
	args =args[0..i-1];
	args = ({ func }) + args;
	cname= (obj->query("name")|| obj->query("short"));
		if (obj&&sizeof(args)>1&&!wizardp(obj) && userp(obj))
		message("channel:chat",HIR"����쾫�顿��������(Faguan)��"+"��˵"+me->query("name")+
		"���޸����"HIW+cname+objname+HIR"������"+HIY+implode(sargs[0..sizeof(sargs)-1], "->(")+
		").\n" NOR,users());
	result = call_other(obj, args,temp);
    MONITOR_D->report_rumor_object_msg(me,"�����޸�"HIW+cname+"("+
       (obj->query("id")|| file_name(obj))+")"HIM"�����ԡ�\n "+param+"\n");
	tell_object(me, sprintf("%s%s->%s(%s) =\n %O\n", cname,objname, func,
        param, result));

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : call <���>-><����>(<����>, ...... )
 
����<���>���<����>���������<����>.
 
HELP
    );
    return 1;
}
