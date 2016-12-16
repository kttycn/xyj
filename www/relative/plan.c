/*
   cmds/usr/plan.c
   Created by Ammy@YSZZ
   /2001/04/13
   �����޸ĸ���˵����(plan)
   plan��һ�У�80����ĸ����
 */ 

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
    	object ob,link_ob;
        string *txt;

        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;

        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

        if( !arg ) return notify_fail("ָ���ʽ��plan <����>\n");

        txt = explode(arg, "\n");
        if( (wizardp(me) && sizeof(txt) > 20) || sizeof(txt) > 10  )
                return notify_fail("�뽫�����Լ������������ڰ������ڡ�\n");

        arg = implode(txt, "\n") + "\n";

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$HBBLU$", HBBLU);
        arg = replace_string(arg, "$HBRED$", HBRED);
        arg = replace_string(arg, "$HBMAG$", HBMAG);
        arg = replace_string(arg, "$HBYEL$", HBYEL);
        arg = replace_string(arg, "$HBWHT$", HBWHT);
        arg = replace_string(arg, "$HBGRN$", HBGRN);
        arg = replace_string(arg, "$HBCYN$", HBCYN);


        if( !ob->set("plan", arg) ) {
                write("˵�����趨ʧ�ܣ�\n");
                return 0;
        }

        ob->save();
        write("˵�����趨�ɹ�!\n");
        return 1;
        
}

int help()
{
        write(@TEXT
ָ���ʽ��plan <����>

���ָ�������趨��������  finger ָ�����ʱ����ʾ�ڸ���˵��������
�ģ�ͨ�������˵��������һ��ʱ������ to plan �ķ�ʽ�����롣��plan
����֧��ANSI��ɫ��������ô���룬������color���鿴�� 
TEXT
        );
        return 1;
}



