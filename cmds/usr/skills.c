// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
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

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,BLU "�����ž�" NOR,HIB "��֪һ��" NOR,HIB "��������" NOR,
	CYN "������" NOR,CYN "����С��" NOR,HIC "�ڻ��ͨ" NOR,HIC "�������" NOR,
	GRN "��Ȼ���" NOR,GRN "���д��" NOR,YEL "��ͬ����" NOR,YEL "������˫" NOR,
	HIY "������" NOR,RED "�����ױ�" NOR,WHT "������ʥ" NOR,HIW "��ǰ����" NOR,
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, str;
	int i, j;
	str = "";

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}
	if( ob!=me && ob->query("env/invisibility")&&!wizardp(me) )
		return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");

	if( ob!=me && !wizardp(me) 
	&& !ob->is_apprentice_of(me) 
	&& !me->is_apprentice_of(ob) 
	&& getuid(ob)!=me->query("bonze/dadangid")
	&& getuid(ob)!=me->query("couple/id"))
		return notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");

	skl = ob->query_skills();
	j = (int)sizeof(skl);
	if(!sizeof(skl)) {
		write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	write( (ob==me ? HIR"��" : ob->name()) + "Ŀǰ�����յļ����У�"NOR);

	str = "\n������������������������������������������������������������������\n";
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		str = sprintf("%s%s%s%-40s" NOR " - %-10s %3d/%5d\n", str,
			(member_array(sname[i], mapped)==-1? "  ": HIR"��"NOR),
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			SKILL_D(sname[i])->level_description(skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	str += "����������������������������������������  "MAG"��Ӱ��Ե"NOR"  ��������������\n";
	str += "\n					 "HIR"Ŀǰ��ѧ�� "+HIW""+ chinese_number(j) + ""HIR" �ּ���" NOR;
	write("\n");
	this_player()->start_more(str);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills|jineng [<ĳ��>]

���ָ����������ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
