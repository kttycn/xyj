#include <ansi.h>
#define SCORE_COST 50000
#define GOLD_COST 20
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
	object gold;
	string e_name,c_name,title;	
	string *dir;
	int i;
	seteuid(getuid());
	if(!arg || sscanf(arg,"%s %s %s",e_name, c_name, title) != 3)
		return notify_fail("Ö¸Áî¸ñÊ½£º¡¡bang xuelianjiao Ñ©Á«½Ì ½ÌÖ÷\n");
	if((int)me->query("score") < SCORE_COST)
		return notify_fail("ÄãµÄ½­ºşÔÄÀú²»¹»"+chinese_number(SCORE_COST)+"µã¡£\n");
	if((int)me->query("combat_exp") < 5000000)
		return notify_fail("ÄãµÄ¾­Ñé²»¹»"+chinese_number(5000000)+"µã¡£\n");
	if((int)me->query("daoxing") < 5000000)
		return notify_fail("ÄãµÄµÀĞĞ»¹²»µ½ÎåÇ§Äê¡£\n");
	gold = present("gold-coin_money",me);
	if(!gold) return notify_fail("ÄãÉíÉÏÃ»ÓĞÔÂÓ°½ğ±Ò¡£\n");
	if((int) gold->query_amount() < GOLD_COST)
		return notify_fail("ÄãÉíÉÏÃ»ÓĞ"+chinese_number(GOLD_COST)+"Ã¶ÔÂÓ°½ğ±Ò¡£\n");	
	if(!check_legal_name(c_name) || !check_legal_name(title))
		return 1;
	c_name += " ";
	e_name += "_";
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
		return notify_fail("ÄãÏë´´Á¢µÄ°ïÅÉÖĞÎÄ»òÓ¢ÎÄÃû×ÖÒÑ¾­±»±ğÈËÕ¼ÓÃÁË£¡\n");	
	if(!BR_D->touch_file(DATA_DIR+"guild/"+e_name) ||
	!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
		return notify_fail("ÓÎÏ·ÏµÍ³³öÏÖÎÊÌâ£¡ÇëÍ¨Öª¹ÜÀíÈËÔ±£¡\n");
	me->create_family(c_name,1,title);
	me->set("class",e_name);
	me->add("score",-SCORE_COST);
	gold->add_amount(-GOLD_COST);
	me->set("title",HIR+c_name+title+NOR);
	message("channel:es",
	HIM"\n\n¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î \n\n"HIC
		"\t\t    ¡º "+c_name+"¡»"+"ÔÚ½­ºşÖĞ³ÉÁ¢ÁË£¡\n"HIM
	    "\n¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î ¡î \n"NOR,
	users() );
	return 1;
}
/*
string replace(string arg)
{
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

	newarg=arg;


	while(sscanf(newarg,"%s%*sm%s",str1,str2)==3)
		newarg=str1+str2;
	arg = arg + NOR;
	return arg;
}
*/
int help(object me)
{
    write(@HELP
ÈÃÄãÔÚº£ÑóÖĞ³ÉÁ¢×Ô¼ºµÄ°ïÅÉ£¡

Ö¸Áî¸ñÊ½: 
bang xuelianjiao Ñ©Á«½Ì ½ÌÖ÷

´ËÖ¸ÁîÈÃÄã´´Á¢Ò»¸öĞÂµÄ°ï£¬ÅÉ£¬»ò½Ì¡£ 
²¢·âÄãÎªÑ©Á«½Ì½ÌÖ÷¡£

ÓÖÀı£º

bang bluedress ÇàÒÂÂ¥ ×Ü¹Ü
´´Á¢ÇàÒÂÂ¥²¢·âÄãÎªÇàÒÂÂ¥×Ü¹Ü¡£
HELP
    );
	return 1;
}
 
int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
		write("¶Ô²»Æğ£¬ÖĞÎÄÃû×Ö±ØĞëÊÇÈıµ½Ê®Îå¸öÖĞÎÄ×Ö¡£\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("¶Ô²»Æğ£¬ÖĞÎÄÃû×Ö²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("¶Ô²»Æğ£¬Ãû×Ö±ØĞèÊÇÖĞÎÄ¡£\n");
			return 0;
		}
	}
	return 1;
}

