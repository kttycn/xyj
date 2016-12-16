//color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
        tell_object(me,MAG"★"HIY"色彩精灵向您报告"NOR MAG"★\n\n"NOR);
        tell_object(me,
"  黑色- BLK"BLK"■■■                       BBLK"BBLK"■■■"NOR"\n"
"  红色- RED"RED"■■■"NOR" HIR"HIR"■■■"NOR" HBRED"HBRED"■■■"NOR" BRED"BRED"■■■"NOR"\n"
"  绿色- GRN"GRN"■■■"NOR" HIG"HIG"■■■"NOR" HBGRN"HBGRN"■■■"NOR" BGRN"BGRN"■■■"NOR"\n"
"  黄色- YEL"YEL"■■■"NOR" HIY"HIY"■■■"NOR" HBYEL"HBYEL"■■■"NOR" BYEL"BYEL"■■■"NOR"\n"
"  蓝色- BLU"BLU"■■■"NOR" HIB"HIB"■■■"NOR" HBBLU"HBBLU"■■■"NOR" BBLU"BBLU"■■■"NOR"\n"
"  粉色- MAG"MAG"■■■"NOR" HIM"HIM"■■■"NOR" HBMAG"HBMAG"■■■"NOR" BMAG"BMAG"■■■"NOR"\n"
"  青色- CYN"CYN"■■■"NOR" HIC"HIC"■■■"NOR" HBCYN"HBCYN"■■■"NOR" BCYN"BCYN"■■■"NOR"\n"
"  白色- WHT"WHT"■■■"NOR" HIW"HIW"■■■"NOR" HBWHT"HBWHT"■■■"NOR"\n"
"  闪烁- FLA"FLA"■■■"NOR"\n"
"\n　其它色彩：\n"
"  REDGRN"REDGRN"■■■"NOR" REDYEL"REDYEL"■■■"NOR" REDBLU"REDBLU"■■■"NOR" REDMAG"REDMAG"■■■"NOR"\n"
"  REDCYN"REDCYN"■■■"NOR" REDWHI"REDWHI"■■■"NOR" GRNRED"GRNRED"■■■"NOR" GRNYEL"GRNYEL"■■■"NOR"\n"
"  GRNBLU"GRNBLU"■■■"NOR" GRNMAG"GRNMAG"■■■"NOR" GRNCYN"GRNCYN"■■■"NOR" GRNWHI"GRNWHI"■■■"NOR"\n"
"  YELRED"YELRED"■■■"NOR" YELGRN"YELGRN"■■■"NOR" YELBLU"YELBLU"■■■"NOR" YELMAG"YELMAG"■■■"NOR"\n"
"  YELCYN"YELCYN"■■■"NOR" YELWHI"YELWHI"■■■"NOR" BLURED"BLURED"■■■"NOR" BLUGRN"BLUGRN"■■■"NOR"\n"
"  BLUYEL"BLUYEL"■■■"NOR" BLUMAG"BLUMAG"■■■"NOR" BLUCYN"BLUCYN"■■■"NOR" BLUWHI"BLUWHI"■■■"NOR"\n"
"  MAGRED"MAGRED"■■■"NOR" MAGGRN"MAGGRN"■■■"NOR" MAGYEL"MAGYEL"■■■"NOR" MAGBLU"MAGBLU"■■■"NOR"\n"
"  MAGCYN"MAGCYN"■■■"NOR" MAGWHI"MAGWHI"■■■"NOR" CYNRED"CYNRED"■■■"NOR" CYNGRN"CYNGRN"■■■"NOR"\n"
"  CYNYEL"CYNYEL"■■■"NOR" CYNBLU"CYNBLU"■■■"NOR" CYNMAG"CYNMAG"■■■"NOR" CYNWHI"CYNWHI"■■■"NOR"\n");
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : color

这个指令可以让你知道游戏中各种色彩的ANSI控制字元及色彩的
试样，从而方便您选择中意的色彩。

HELP
    );
    return 1;
}
