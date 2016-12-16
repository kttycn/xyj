#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string *list;
    string str;
    string *admin = ({}), *arch = ({}), *wizard = ({}),
        *apprentice = ({}), *immortal = ({}),*elder = ({}), *unknown = ({});
    int i;

	str = HIR"\n ��"HIM " ��"+ CHINESE_MUD_NAME+"��"HIY"��"NOR CYN+INTERMUD_MUD_NAME+HIW"����ʦ��Ա"+HIB"
��������������������������������������������������������������������������\n"NOR;
    list = SECURITY_D->query_wizlist();

    for( i = 0; i < sizeof( list ); i++ ) {
        switch( SECURITY_D->get_status( list[i] ) ) {
        case "(admin)":
            admin += ({ list[i] });
            break;
        case "(arch)":
            arch += ({ list[i] });
            break;
        case "(wizard)":
            wizard += ({ list[i] });
            break;
        case "(apprentice)":
            apprentice += ({ list[i] });
            break;
        case "(immortal)":
            immortal += ({ list[i] });
            break;
        case "(elder)":
            elder += ({ list[i] });
            break;

        default:
            unknown += ({ list[i] });
        }
    }

    str += HIW
"�� ϵͳ���� ���� adm  ��  ";
    if( admin )
        for( i = 0; i < sizeof( admin ); i++ ) {
            str += sprintf("%-8s%s", admin[i],
                (i % 4 == 3 ) ? "\n\t" : "");
                }
    str += "\n" + HIR +
"�� ���򿪷� ���� arch ��  ";
    if( arch )
        for( i = 0; i < sizeof( arch ); i++ ) {
            str += sprintf("%-8s%s", arch[i],
                (i % 4 == 3 ) ? "\n\t" : "");
        }
    str += "\n" + HIY +
"�� �������� ���� wiz  ��  ";
    if( wizard )
        for( i = 0; i < sizeof( wizard ); i++ ) {
            str += sprintf("%-8s%s", wizard[i],
                (i % 4 == 3 ) ? "\n\t" : "");
        }
    str += "\n" + HIG +
"�� ���¹��� ���� app  ��  ";
    if( apprentice )
        for( i = 0; i < sizeof( apprentice ); i++ ) {
            str += sprintf("%-8s%s", apprentice[i],
                (i % 4 == 3 ) ? "\n\t" : "");
        }
    str += "\n" + HIM +
"�� ʵϰ���� ���� imm  ��  ";
    if( immortal )
        for( i = 0; i < sizeof( immortal ); i++ ) {
            str += sprintf("%-8s%s", immortal[i],
                (i % 4 == 3 ) ? "\n\t" : "");
        }
    str += "\n" + HIB +
"�� ������� ���� eld  ��  ";
    if( elder )
        for( i = 0; i < sizeof( elder ); i++ ) {
            str += sprintf("%-8s%s", elder[i],
                (i % 4 == 3 ) ? "\n\t" : "");
        }

        str += HIB"\n��������������������������������������������������������������������������\n"NOR;
        str += sprintf(HIC"��Ŀǰһ����: "+HIR"%d"+HIC" λ����Ա \n"NOR,sizeof(list) );
        me->start_more(str);

    return 1;
}

int help(object me)
{
        write("\nָ���ʽ : wizlist\n"
        "��; : �г�Ŀǰ���е�ϵͳ����Ա������\n"
"������ finger   who -w \n"
        );
        return 1;
}
