//color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
        tell_object(me,MAG"��"HIY"ɫ�ʾ�����������"NOR MAG"��\n\n"NOR);
        tell_object(me,
"  ��ɫ- BLK"BLK"������                       BBLK"BBLK"������"NOR"\n"
"  ��ɫ- RED"RED"������"NOR" HIR"HIR"������"NOR" HBRED"HBRED"������"NOR" BRED"BRED"������"NOR"\n"
"  ��ɫ- GRN"GRN"������"NOR" HIG"HIG"������"NOR" HBGRN"HBGRN"������"NOR" BGRN"BGRN"������"NOR"\n"
"  ��ɫ- YEL"YEL"������"NOR" HIY"HIY"������"NOR" HBYEL"HBYEL"������"NOR" BYEL"BYEL"������"NOR"\n"
"  ��ɫ- BLU"BLU"������"NOR" HIB"HIB"������"NOR" HBBLU"HBBLU"������"NOR" BBLU"BBLU"������"NOR"\n"
"  ��ɫ- MAG"MAG"������"NOR" HIM"HIM"������"NOR" HBMAG"HBMAG"������"NOR" BMAG"BMAG"������"NOR"\n"
"  ��ɫ- CYN"CYN"������"NOR" HIC"HIC"������"NOR" HBCYN"HBCYN"������"NOR" BCYN"BCYN"������"NOR"\n"
"  ��ɫ- WHT"WHT"������"NOR" HIW"HIW"������"NOR" HBWHT"HBWHT"������"NOR"\n"
"  ��˸- FLA"FLA"������"NOR"\n"
"\n������ɫ�ʣ�\n"
"  REDGRN"REDGRN"������"NOR" REDYEL"REDYEL"������"NOR" REDBLU"REDBLU"������"NOR" REDMAG"REDMAG"������"NOR"\n"
"  REDCYN"REDCYN"������"NOR" REDWHI"REDWHI"������"NOR" GRNRED"GRNRED"������"NOR" GRNYEL"GRNYEL"������"NOR"\n"
"  GRNBLU"GRNBLU"������"NOR" GRNMAG"GRNMAG"������"NOR" GRNCYN"GRNCYN"������"NOR" GRNWHI"GRNWHI"������"NOR"\n"
"  YELRED"YELRED"������"NOR" YELGRN"YELGRN"������"NOR" YELBLU"YELBLU"������"NOR" YELMAG"YELMAG"������"NOR"\n"
"  YELCYN"YELCYN"������"NOR" YELWHI"YELWHI"������"NOR" BLURED"BLURED"������"NOR" BLUGRN"BLUGRN"������"NOR"\n"
"  BLUYEL"BLUYEL"������"NOR" BLUMAG"BLUMAG"������"NOR" BLUCYN"BLUCYN"������"NOR" BLUWHI"BLUWHI"������"NOR"\n"
"  MAGRED"MAGRED"������"NOR" MAGGRN"MAGGRN"������"NOR" MAGYEL"MAGYEL"������"NOR" MAGBLU"MAGBLU"������"NOR"\n"
"  MAGCYN"MAGCYN"������"NOR" MAGWHI"MAGWHI"������"NOR" CYNRED"CYNRED"������"NOR" CYNGRN"CYNGRN"������"NOR"\n"
"  CYNYEL"CYNYEL"������"NOR" CYNBLU"CYNBLU"������"NOR" CYNMAG"CYNMAG"������"NOR" CYNWHI"CYNWHI"������"NOR"\n");
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : color

���ָ���������֪����Ϸ�и���ɫ�ʵ�ANSI������Ԫ��ɫ�ʵ�
�������Ӷ�������ѡ�������ɫ�ʡ�

HELP
    );
    return 1;
}
