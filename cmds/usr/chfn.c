//Cracked by Roath
// chfn.c
// created by xigua@dhxyii
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
 int email_flag,icq_flag,webpage_flag;
int main(object me, string arg)
{
        object link;
       
        if( link = me->query_temp("link_ob") ) {
        	email_flag = link->query("email")?1:0;
        	icq_flag = link->query("icq")?1:0;
        	webpage_flag = link->query("webpage")?1:0;
        	if(email_flag ==0) link->set("email","");
        	if(icq_flag ==0) link->set("icq","");
        	if(webpage_flag ==0) link->set("webpage","");
                write("���ĵ����ʼ�"+(email_flag?(" [" + link->query("email") + "]��"):"��"));
                input_to("get_email", link);
                return 1;
        }
        return 0;
}
string rp_color(string arg)
{
     if (!arg) return "";
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
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$NOR$", NOR);
        return arg+NOR;
}

void get_email(string new_email, object link)
{
        if( new_email != ""&&strlen(new_email) < 50)
                link->set("email", new_email);
        write("���ĸ�����ҳ"+(webpage_flag?(" [" + link->query("webpage") + "]��"):"��"));
        input_to("get_webpage", link);
}
void get_webpage(string new_webpage, object link)
{
        if( new_webpage != ""&&strlen(new_webpage) < 300)
                link->set("webpage", new_webpage);

        write("����ICQ/OICQ"+(email_flag?(" [" + link->query("icq") + "]��"):"��"));
         input_to("get_icq", link);
}
void get_icq(string new_icq, object link)
{
        if( new_icq != ""&&strlen(new_icq) < 10)
                link->set("icq", new_icq);

        write("������ҽ���(fingerʱ��ʾ)��\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_profile", link:));
}
void get_profile(object link,string str)
{
        str=rp_color(str);
        if(strlen(str) > 5000)
        {
         write("�������ֹ��࣬�������趨��\n\n");
         write("�������ҽ���: (fingerʱ��ʾ)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_profile", link:));
        }
         else {
        link->set("profile", str);
        write("����ǩ����ʽ: (postʱ��)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_signature", link :));
        }
}

void get_signature(object link, string str)
{
         if( strlen(str) > 1400 )
         {
                write("ǩ����ʽ̫�����������趨��\n\n");
                write("����ǩ����ʽ: (postʱ��)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_signature", link :));
        }
        else{
                str=rp_color(str);
                link->set("signature", str);
                 write("�������޸�"HIR" save "NOR"�����Ч����\n");
        }
       
}

int help(object me)
{
write(@HELP
ָ���ʽ : chfn

��; : �����޸���ĸ������ϡ�
�÷� ��ϵͳ������ʾ������:
       �����ʼ���ַ��  �����e-mail,��������޸ģ���س�������
       ������ҳ��      ����ĸ�����ҳ��ַ����������޸ģ���س�����)
       OICQ/ICQ���룺  �����ICQ����OICQ���룬���û�п���ȥ����һ����
                              (www.icq.com / www.tencent.com)
       ������ҽ��ܣ�  ��finger ʱ������
       ��ĸ��Ի�ǩ������post ʱ�ã�
������Ϻ�һ��Ҫ save ���������á�
������ñ��˿��������Ϣ���㻹��Ҫ��
1. set pub_email 1    ������������Ҳ쿴��ĵ����ʼ���ַ
2. set pub_webpage 1  ������������Ҳ쿴��ĸ�����ҳ��ַ
3. set pub_icq 1      ������������Ҳ쿴���icq/oicq��ַ
HELP
     );
     return 1;
}


