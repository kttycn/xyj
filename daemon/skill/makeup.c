// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "beauty"; }

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "Èç»¨ËÆÓñ" NOR,
		BLU "·ôÈôÄýÖ¬" NOR,
		HIB "ÖéÔ²ÓñÈó" NOR,
		HIB "ÍÂÆøÈçÀ¼" NOR,
		YEL "Ã÷íøð©³Ý" NOR,
		YEL "±ù¼¡Óñ¹Ç" NOR,
		CYN "À¼ÖÊ»ÝÐÄ" NOR,
		HIW "Çà´ºÓÀ×¤" NOR
		//ÐãÍâ»ÛÖÐ
		//Óñ½à±ùÇå
	});

	grade = level / 20;	
	
	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
