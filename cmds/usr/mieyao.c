// mieyao.c modified by xuer
// 01-15-2001
// ���������������գ��ø��ˣ�

#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;
int where_all();
string whereguai(string str);

int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;
	string here;

	if (!str) return where_all();
	else return notify_fail(HIC"�ٺ١���������Ҫ����������ҵ�λ�����Һ����¡�����\n"NOR);
	ob = find_player(str);
	
	if( !ob ) ob = find_living(str);

	if( !ob ) ob = LOGIN_D->find_body(str);
	if( !ob ) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		
		if(sizeof(ob_list)<1)
		    return notify_fail("û���ҵ������֣�����������ƴд��\n");

		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}

	where = environment(ob);
	if (!where) return notify_fail("����("+file_name(ob)+
	   ")��֪��������Ү������\n");
	printf("\n");
	printf(HIM"��������������������������������������������������������������\n"NOR);
	printf(HIM"��"HIC"%10s(%16s)��"HIR"������"HIC"��%8s(%8s)��"HIR"��\n"NOR,
		(string)ob->name(),
		(string)ob->query("id"),
		(string)MISC_D->find_place(where),
		undefinedp(where->query("short"))?
                  where->short():
                  where->query("short"),
		(string)file_name(where));
printf(HIM"��������������������������������������������������������������\n"NOR);
	return 1;
}

int where_all()
{
    int t;
    mixed* lt;
    string str;
    string output, yao_name, yao_id;
    string test;
    object *list;
    int i, j, ppl_cnt;
    string  hr, min, sec;
    object me, ob, where, where2;
	me = this_player();
        
	str = HIR"���� " + MUD_NAME + "\n";
	str += HIM "����������������������������������������������������������������������������\n"NOR;
	str += HIC"���������          ��������             ����λ��             ��ʼ����ʱ��  \n"NOR;
	str += HIM"����������������������������������������������������������������������������\n"NOR;
	list = users();
    j = sizeof(list);
    while( j-- ) {
		where=environment(list[j]);
        if( !where ) continue;
		if (!list[j]->query("mieyao/id") 
		|| list[j]->query("mieyao/id") == "") continue;
        yao_id = list[j]->query("mieyao/id");
		ob = find_player(list[j]->query("mieyao/id"));
		if( !find_living(list[j]->query("mieyao/id")) ) continue;
		where2=environment(find_living(list[j]->query("mieyao/id")));
		if ( !where2 ) continue;
		if (list[j]->query("mieyao/time_start"))
			t=list[j]->query("mieyao/time_start");
		else
			t=list[j]->query("mieyao/time_start1");
		if (list[j]->query("mieyao/name"))
			yao_name = list[j]->query("mieyao/name");
		else
			yao_name = list[j]->query("mieyao/name1");
//		if (!list[j]->query("mieyao/done1")&&!list[j]->query("mieyao/done"))
//			continue;
		lt=localtime(t);
		if( lt[LT_HOUR] < 10 )
			hr = sprintf("0%d", lt[LT_HOUR]);
		else 
			hr = sprintf("%d", lt[LT_HOUR]);
		if( lt[LT_MIN] < 10 )
			min = sprintf("0%d", lt[LT_MIN]);
		else 
			min = sprintf("%d", lt[LT_MIN]);
		if( lt[LT_SEC] < 10 )
			sec = sprintf("0%d", lt[LT_SEC]);
		else 
			sec = sprintf("%d", lt[LT_SEC]);
		if (ob) where2 = environment(ob);
		test=hr+":"+min+":"+sec;
		str += HIC;
		str = sprintf("%10s%-8s%10s(%-14s)%10s(%-12s)",
			str,"��"+list[j]->query("name"),
			yao_name,yao_id,
			(string)MISC_D->find_place(where2),
			undefinedp(where2->query("short"))?
                  where2->short():
                  where2->query("short"),
//			list[j]->query("mieyao/where"),
		);
        str+="	"+test;
        str +="\n"NOR;
	}

	str += HIM"����������������������������������������������������������������������������\n"NOR;
	me->start_more(str);
    return 1;
}

string whereguai(string str)
{
	object ob,me,where,*ob_list;
	int i;
	string here;
	me=this_player();
	ob = find_player(str);
	if( !ob ) 
	ob = find_living(str);
	ob = LOGIN_D->find_body(str);

	if( !ob ) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		
		if(sizeof(ob_list)<1)
		    return "û���ҵ������֣�����������ƴд��\n";

		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return "here";
	}
	where = environment(ob);
	here = where->query("short");
	if(where)
		here="��"+MISC_D->find_place(where);
	return here;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: mieyao [����id]

���ָ����������֪����Ŀǰ���ڵ�λ�ã����޲���ʱ���鿴��
����ҵ���������

HELP
	);
	return 1;
}

