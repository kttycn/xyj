//Cracked by Roath
// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *ob,*target;
        int i;
	string mebang,obbang;

	mebang = (string)me->query("marks/����");
	if ((mebang==0) || (mebang=="��")) return 1;
        ob=users();
        i = sizeof(ob);
        while (i--) {
		obbang = (string)ob[i]->query("marks/����");
		if ( (obbang!=0) && (obbang!="��") && (mebang == obbang) )
		{
			if (sizeof(target)==0)
			{
				target=({ob[i]});
			} else {
				target+=({ob[i]});
			}
		}
	}
	
	message("vision", HIW "����᡿" + me->name(1) + "��" + arg + "\n" NOR, target);	
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ulist

������������ҵ�/obj/user number ��ʾ������
HELP
    );
    return 1;
}
