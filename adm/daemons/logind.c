// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <runtime_config.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>     // for GB_AND_BIG5 define.

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
	"Äã", "ÎÒ", "Ëû", "Ëı", "Ëü", "Ëü", "½­ÔóÃñ", "µËĞ¡Æ½", "ÀîÅô", "ÖìéÅ»ù",
	"×Ô¼º", "Ä³ÈË", "Ê¬Ìå", "ÎÒÃÇ","ÄãÃÇ", "ËûÃÇ", "´ó¼Ò",
	"ËûÂèµÄ", "È¥ÄãµÄ", "Ã«Ôó¶«", "Î×Ê¦", "ËûÄÌÄÌµÄ",
});


string Rname;
string default_name()
{
	string *lname = ({
"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ","½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ğí","ºÎ","ÂÀ","Ê©","ÕÅ",
"¿×","²Ü","ÑÏ","»ª","½ğ","Îº","ÌÕ","½ª","Æİ","Ğ»","×Ş","Ó÷","°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ğ","ŞÉ","·¶","Åí","ÀÉ",
"Â³","Î¤","²ı","Âí","Ãç","·ï","»¨","·½","Éµ","ÈÎ","Ô¬","Áø","µË","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","ÌÀ",
"ÌÙ","Òó","ÂŞ","»ª","ºÂ","Úù","°²","³£","ÀÖ","´ô","Ê±","¸¶","Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","Ó¯","Æ½","»Æ",
"ºÍ","ÄÂ","Ğ¤","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ","Ã×","±´","Ã÷","²Ø","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ",
"ĞÜ","¼Í","Êæ","Çü","Ïî","×£","¶­","Áº","·®","ºú","Áè","»ô","Óİ","Íò","Ö§","¿Â","êÃ","¹Ü","Â¬","Ó¢","Íò","ºò","Ë¾Âí",
"ÉÏ¹Ù","Å·Ñô","ÏÄºò","Öî¸ğ","ÎÅÈË","¶«·½","ºÕÁ¬","»Ê¸¦","Î¾³Ù","¹«Ñò","å£Ì¨","¹«ÖÎ",
"×ÚÕş","å§Ñô","´¾ÓÚ","µ¥ÓÚ","Ì«Êå","ÉêÍÀ","¹«Ëï","ÖÙËï","Ô¯Ğù","Áîºü","ÖÓÀë","ÓîÎÄ",
"³¤Ëï","Ä»Èİ","Ë¾Í½","Ê¦¿Õ","ò§¿×","¶ËÄ¾","Î×Âí","¹«Î÷","Æáµñ","ÀÖÕı","ÈÀæá","¹«Á¼",
"ÍØÖº","¼Ğ¹È","Ô×¸¸","¹ÈÁº","³ş½ú","ÑÖ·¨","ÈêÛ³","Í¿ÇÕ","¶ÎÇ§","°ÙÀï","¶«¹ù","ÄÏ¹ù",
"ºôÑÓ","¹éº£","ÑòÉà","Î¢Éú","ÔÀ","Ë§","çÃ","¿º","¿ö","ºó","ÓĞ","ÇÙ","ÁºÇğ","×óÇğ","¶«ÃÅ","Î÷ÃÅ",
	});
	return (lname[random(200)] + chinese_number(random(20)));
}


void logind_user_log(); // mon 11/5/98
int total_count;
int howmany_user();
protected void encoding(string arg, object ob);
protected void if_young(string arg, object ob);
protected void get_id(string arg, object ob);
protected void confirm_id(string yn, object ob);
object make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string dis_attr(int value);
protected void confirm_gift(string yn,object ob,object user);

int howmany_user()
{
	int i,reg_cnt;
	string *dir , *ppls;
	seteuid(getuid());
	reg_cnt=0;
	dir=get_dir(DATA_DIR+"login/");
	for(i=0; i<sizeof(dir);i++)	{
		reset_eval_cost();
		ppls=get_dir(DATA_DIR+"login/"+dir[i]+"/");
		reg_cnt+=sizeof(ppls);
	}
	return reg_cnt;
}

void create() 
{
	seteuid(getuid());
	set("channel_id", "Á¬Ïß¾«Áé");
        set("id", "logind");
}

// mon 11/7/98
void logind_user_log()
{
    int user=sizeof(users());
    int total;

    remove_call_out("logind_user_log");
    rm("/log/user_count");
    log_file("user_count",""+
            ((total=total_count)?total:user)+"\n"+
            user+"\n"+
            UPTIME_CMD->report_str()+"\n"+
            "ÊÀ¼ÍÎ÷ÓÎÖ®"MAG"ÔÂÓ°ÆæÔµ\n"NOR);
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998


void logon(object ob)
{
	object *usr;
	int i, login_cnt;

// ·ÀÖ¹ÓĞ¶ñÒâµÄÍæ¼ÒÓÃ KMUD µÈ¹¤¾ßµ·ÂÒ
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	login_cnt = 0;
	while (i--) if (query_ip_number(usr[i]) == query_ip_number(ob)) login_cnt++;
	if (login_cnt > 3) {
		destruct(ob);
		return;
	}

#ifdef GB_AND_BIG5
    cat("/adm/etc/banner"+sprintf("%d",random(9)));
	write("\n              [4;53mÎÒÃÇ½¨ÒéÊ¹ÓÃ 800 * 600 µÄ·Ö±æÂÊ½øÈë"+MUD_NAME+"¡£\n"NOR);
    write("                [4;53m   Best view with 800 * 600    \n"NOR);
    write("\n            ÔÂÓ°ÆæÔµ»¶Ó­ÄúÀ´·Ã£¡Ê¹ÓÃ¹ú±êÂëµÄÍæ¼ÒÇë¼üÈë£ºgb\n");
    write("            ¤ë¼v©_½tÅwªï±z¨Ó³X¡I¨Ï¥Î¤j¤­½Xªºª±®a½ĞÁä¤J¡Gbig5\n\n");
    write("    [If there is no response after ENTER, please try Ctrl-ENTER]\n");
    write("        [ÌáÊ¾£ºÈç¹û°´"HIC"ENTER"NOR"¼üºóÏµÍ³Ã»ÓĞÏìÓ¦£¬ÇëÊÔ Ctrl-ENTER]\n\n");
    write("          Welcome to Moon Love Story! Select GB or BIG5 (gb/big5):");
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
		destruct(ob);
	}
    input_to( (: encoding :), ob );
#else
    encoding("gb",ob);
#endif

}

protected void encoding(string arg, object ob)
{
	object *usr;
	int i, ttl_cnt, wiz_cnt, ppl_cnt, login_cnt, max_online,avg_online;
	string ip_name, ip_number, online_num;
 	int ii, iplimit;
	mixed info;
	int encode;
	

	if(!arg || arg=="") {
	    write("\nSelect ¹ú±êÂë GB or ¤j¤­½X BIG5 (gb/big5):");
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
	    input_to( (: encoding :), ob );
	    return;
	} else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    encode=1;
	else {
	    write("\nSelect ¹ú±êÂë GB or ¤j¤­½X BIG5 (gb/big5):");
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
	    input_to( (: encoding :), ob );
	    return;
	}
	
	ob->set_encoding(encode);

	ip_name = query_ip_name(ob);
	ip_number = query_ip_number(ob);



// snowcat dec 10 1997
// try strict ban here...weiqi.

	if ("/adm/daemons/band"->is_strict_banned(query_ip_number(ob)) == 1) {
	   	write(HIR"ÄúµÄµØÖ·ÔÚ±¾ MUD Ö®ĞÅÓş±»ÈËÆÆ»µÁË¡£\n"NOR);
	   	destruct(ob);
		log_file( "ALLCONT", sprintf("kicked out, strict_banned\n"));
	   	return;
	}

	
	// try not accept "name" as IP

	if (!ip_name) {
		destruct(ob);
		log_file( "ALLCONT", sprintf("kicked out, No IP\n"));
		return;
	}

	for(ii=0; ii<sizeof(ip_number); ii++) {
		if( (ip_number[ii] != '.')&&(ip_number[ii]>'9') ){
			destruct(ob);
			log_file( "ALLCONT", sprintf("kicked out, Non_number\n"));
			return;
		}
	}
	
	write(CLR);
	cat(WELCOME);
	UPTIME_CMD->report();

	// children will show both netdead and interactive users.
	usr = children(USER_OB);
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	iplimit = 0;
	for(i=0; i<sizeof(usr); i++) {
		if( query_ip_name(usr[i])==query_ip_name(ob)) iplimit++;
		if( !environment(usr[i]) ) login_cnt++;
		else if( (wizardp(usr[i]) && (string)wizhood(usr[i])!="(elder)")&& !usr[i]->query("env/invisibility") ) wiz_cnt++;
		else ppl_cnt++;
	}

	max_online = atoi(read_file(__DIR__"maxonline",1));
	avg_online = atoi(read_file(__DIR__"avguser",1));
	if(ppl_cnt > max_online)
	{
		online_num = sprintf("%d",ppl_cnt);
		write_file(__DIR__"maxonline",online_num,1);
	}
	printf(MAG+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") ÏÖÓĞ×¢²áÍæ¼Ò"HIR"%s"NOR"Î»¡£",
	chinese_number(howmany_user()));
	write("\n"+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") Ä¿Ç°ÈËÊıÏŞÖÆ£º" HIY + chinese_number(MAX_USERS)+NOR);
	write("\n"+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") Ê¹ÓÃMUDOS°æ±¾£º" HIY + "MudOS v22pre11"NOR);
	write("\n");

	printf(MAG+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") ¿ªÕ¾ÒÔÀ´£¬×î¸ßÔÚÏßÊıÄ¿£º"HIY"%s"NOR
	" ÈË£¬Æ½¾ùÔÚÏßÊıÄ¿£º"HIY"%s"NOR" ÈË¡£\n",chinese_number(max_online),chinese_number(avg_online));
	printf(	"\nÄãÏÖÔÚ´Ó%sÁ¬Ïß½øÈë¡£\n",CYN+query_ip_number(ob)+NOR);
	if (iplimit>1)
		write("ÄúËùÔÚµÄµØÖ·ÒÑÓĞ"HIY+chinese_number(iplimit-1)+NOR+"Î»Íæ¼ÒÔÚÏßÉÏ¡£\n");
	if (ttl_cnt == 0) 
		printf("\nÄ¿Ç°"); // info not available
	else 
		printf("\nÄ¿Ç°¹²ÓĞ%dÎ»Íæ¼ÒÔÚÏßÉÏ¡£±¾Õ¾", ttl_cnt );
	printf("¹²ÓĞ"HIW"%sÎ»¹ÜÀíÈËÔ±"NOR"¡¢"HIY"%sÎ»Íæ¼Ò"NOR"£¬ÒÔ¼°"HIC"%sÎ»Ê¹ÓÃÕßÔÚ³¢ÊÔÁ¬Ïß"NOR"¡£\n\n",
	chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );

	// mon 11/7/98
	//check whether user_log still running.
	info = filter_array(call_out_info(), (: $1[1]=="logind_user_log" :));
	if(!sizeof(info)) logind_user_log();


      /* move this check to after user input id.
	 
// mon 4/19/98
// reduce number of pending login users.
#ifdef MAX_USERS
	if(sizeof(usr)>(MAX_USERS+10)) {
	    write("¶Ô²»Æğ£¬"+MUD_NAME+"µÄÍæ¼ÒÒÑ¾­Ì«¶àÁË£¬Çë´ı»á¶ùÔÙÀ´¡£\n");
	    destruct(ob);
	    return;
	}
#endif

*/

	if (ob) ob->set_temp("id_count",0);
	//mon 10/15/97 to prevent flooding illegal ID after login.

#ifndef GB_AND_BIG5
#endif
        
	//we do not welcome young kid playing mud. weiqi...971220.
	write(CYN"¼øÓÚÕâÀïÊÇÄÚ²¿Íø£¬ÎÒÃÇµÄÖ÷ÒªÈÎÎñÊÇ¹¤×÷£¬±¾ÓÎÏ·²»»¶Ó­ÓĞ¹¤×÷ÈÎÎñµÄÅóÓÑÀ´Íæ¡£\n"NOR);
	write(CYN"ÄúÊÇ·ñÊÇ»¹ÓĞºÃ¶à¹¤×÷Ã»ÓĞ×öÍê£¿£¿(yes/no)"NOR);
	input_to( (: if_young :), ob );
}

protected void if_young(string arg, object ob)
{
        int id_count;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id.
        id_count++;
        ob->set_temp("id_count",id_count);
        if(id_count>3) {
          destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
          return;
        }

        if(arg=="\n" || arg=="") {
	    write(CYN"\nÄúÊÇ·ñÊÇ»¹ÓĞºÃ¶à¹¤×÷Ã»ÓĞ×öÍê£¿(yes/no)"NOR);
	    input_to( (: if_young :), ob );
	    return;
	}

	if( arg[0..0] == "y" || arg[0..0] == "Y" )
	{
		write(HIG"\nºÃ£¬»¶Ó­Äã¹¤×÷Íê³ÉºóÔÙÀ´¡£\n"NOR);
		destruct(ob);
		return;
	}

	if( arg[0..0] != "n" && arg[0..0] != "N" ) {
	    write(CYN"\nÄúÊÇ·ñÊÇ»¹ÓĞºÃ¶à¹¤×÷Ã»ÓĞ×öÍê£¿(yes/no)"NOR);
	    input_to( (: if_young :), ob );
	    return;
	}

	cat(XYJ_SITES);
	write(CYN"\nÄúµÄÓ¢ÎÄÃû×Ö£¨ĞÂÍæ¼ÒÇë¼üÈë "HIW"New"NOR CYN" ×¢²á£©£º"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
		destruct(ob);
	}
	input_to( (: get_id :), ob);
}

protected void get_id(string arg, object ob)
{
	object ppl, *usr = children(USER_OB);
	int id_count;

//edw 6/2/98
	int NowLogin, MaxLimit, login_site, i;
	string my_ip, new_ip;
//end edw

        if(!ob) return;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id. 
        id_count++;
        ob->set_temp("id_count",id_count);
	if(id_count>6) {
	  destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
	  return;
        }

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write(CYN"ÄúµÄÓ¢ÎÄÃû×Ö£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_id", ob);
		return;
	}

	ppl = find_body(arg);

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
	&& sizeof(users()) >= MAX_USERS ) {
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		// i.e., ppl exist. (has nothing to do with whether it interactive) -- mon 3/15/99
		//if( !ppl || !interactive(ppl) ) 
		if( !ppl ) {
		  write(HIR"¶Ô²»Æğ£¬"+MUD_NAME+"µÄÍæ¼ÒÒÑ¾­Ì«¶àÁË£¬Çë´ı»á¶ùÔÙÀ´¡£\n"NOR);
		  destruct(ob);
		  return;
		} 
	}
#endif

	if( wiz_level(arg) < wiz_lock_level ) {
		write(HIR"¶Ô²»Æğ£¬" + MUD_NAME + "Ä¿Ç°ÏŞÖÆÎ×Ê¦µÈ¼¶ " + WIZ_LOCK_LEVEL
			+ " ÒÔÉÏµÄÈË²ÅÄÜÁ¬Ïß¡£\n"NOR);
		destruct(ob);
		return;
	}
	
//edw@zju.mirror.xyj 6/2/98 (limit multi-login)
// MAX_LOGIN and LOGIN_SITE should be defined in login.h
#ifdef MAX_LOGIN
	
	if(!ppl) { // only check this for new login.
	         // allow existing players to reconnect.
		my_ip=query_ip_number(ob);

		MaxLimit="/adm/daemons/band"->allow_multi_login(my_ip);
		if(!MaxLimit) MaxLimit=MAX_LOGIN;
#ifdef LOGIN_SITE
		login_site=LOGIN_SITE;
#else
		login_site=0;
#endif
		if(my_ip && login_site==0) // ignore the last field of the IP
			my_ip=my_ip[0..strsrch(my_ip, ".", -1)];

		NowLogin=0;

		for(i=0;i<sizeof(usr);i++) 
			if(ob!=usr[i]) {
				new_ip=query_ip_number(usr[i]);
	    
	    // for net_dead players.
				if(!new_ip && !interactive(usr[i]))
					new_ip=usr[i]->query_temp("netdead_ip");

				if(new_ip && login_site==0)
					new_ip=new_ip[0..strsrch(new_ip, ".", -1)];

				if(my_ip==new_ip) {
					NowLogin++;
			}
		}

		if(NowLogin>=MaxLimit) {
			write(sprintf("¶Ô²»Æğ£¬´ÓÄãµÄIPµØÖ·²»ÄÜÍ¬Ê±µÇÂ¼%sÎ»ÈËÎï¡£\n",
				chinese_number(MaxLimit+1)));
			destruct(ob);
			return;
		}
	}
#endif

	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

	if( arg=="guest" ) {
		// If guest, let them create the character.
//		confirm_id("Yes", ob);
//		return;
	} else if (arg=="new") { // new player login
		write(CYN"\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_new_id",ob);
		return;
	} else if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			write(CYN"ÇëÊäÈëÏàÓ¦ÃÜÂë£º"NOR);
			ob->add_temp("input",1);
			if (ob->query_temp("input")>120)
			{
				write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
				destruct(ob);
			}
			input_to("get_passwd", 1, ob);
			return;
		}
		write(HIW"ÄúµÄÈËÎï´¢´æµµ³öÁËÒ»Ğ©ÎÊÌâ£¬ÇëÀûÓÃ guest ÈËÎïÍ¨ÖªÎ×Ê¦´¦Àí¡£\n"NOR);
		write(HIW"ÃÜÂë£º"HIR"password"HIW"(ÎªÁËËûÈËÕı³£Ê¹ÓÃ¸ÃÓÃ»§£¬Çë²»ÒªĞŞ¸ÄÃÜÂë£¡)\n"NOR);
		destruct(ob);
		return;
	} 
	
	write(HIR"Ã»ÓĞÕâ¸öÍæ¼Ò£®£®£®\n"NOR);
	write(CYN"ÄúµÄÓ¢ÎÄÃû×Ö£º£¨ĞÂÍæ¼ÒÇë¼üÈë "HIR"new"NOR CYN" ×¢²á£©"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
		destruct(ob);
	}
	input_to("get_id", ob);
	return;
}

protected void get_new_id(string arg, object ob)
{
	object *usr, ppl;
	int id_count, i;

	if(!ob) return;

	id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id. 
	id_count++;
	ob->set_temp("id_count",id_count);
	if(id_count>6) {
		destruct(ob);
		log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
		return;
	}
// ·ÀÖ¹Á½¸öÒÔÉÏµÄÍæ¼ÒÓÃÍ¬Ò» id
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
	if (i >= 0) {
		write("ÓĞÆäËûÍæ¼ÒÕıÔÚÊ¹ÓÃÕâ¸ö ID£¬ÇëÖØĞÂÊäÈë¡£\n");
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_new_id", ob);
		return;
	}
	if(!arg) {
		write(CYN"\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_new_id", ob);
		return;
	}

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write(CYN"\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_new_id", ob);
		return;
	}

	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

	ppl = find_body(arg);
	if(ppl || arg=="guest" || arg=="new") {
	    write(HIR"Õâ¸öÃû×ÖÒÑ¾­±»±ğµÄÍæ¼ÒÊ¹ÓÃÁË£®£®£®"NOR);
		write(CYN"\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
	    input_to("get_new_id",ob);
	    return;
	}

	if( arg=="tmd" || arg=="fuck") {
	    write(HIR"ÕâÑùµÄÃû×ÖÄãÒ²Òª£®£®£®£¿"NOR);
		write(CYN"\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
	    input_to("get_new_id",ob);
	    return;
	}
	if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
	    write(HIR"Õâ¸öÃû×ÖÒÑ¾­±»±ğµÄÍæ¼ÒÊ¹ÓÃÁË£®£®£®"NOR);
		write(CYN"\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
	    input_to("get_new_id",ob);
	    return;
	} 

	confirm_id("Yes", ob);
	return;
}

protected void get_passwd(string pass, object ob)
{
	string my_pass,id,temps;
	int time_rl;
	object user;

	write("\n");
	my_pass = ob->query("password");
	if( crypt(pass, my_pass) != my_pass ||
	!SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
		write(HIR"ÃÜÂë´íÎó£¡"NOR);
		write(HIW"ÇëÖØĞÂÁ¬Ïß£¬¼üÈëÕıÈ·µÄÃÜÂë»òÁíÈ¡Ò»¸öĞÂµÄÓ¢ÎÄÃû×Ö¡£\n"NOR);
		if((id=ob->query("id")) && member_array(id,
		SECURITY_D->get_wizlist())!=-1)
			log_file("wizlogin_failed",ctime(time())+" "+id+
				" failed login from "+query_ip_number(ob)+"\n");
		log_file("login_failed",ctime(time())+" "+id+
			" failed login from "+query_ip_number(ob)+"\n");
		destruct(ob);
		return;
	}
	time_rl = time() - ob->query("last_on");
	// Check if logout recently
 	if (time_rl >= 0 && time_rl <= 20)
	{
		temps = sprintf("Äã¾àÉÏ´ÎÍË³ö½ö %d Ãë?\n", time_rl);
		write(temps);
		if ((string)SECURITY_D->get_status(ob->query("id")) == "(player)")
		{
			write(HIR"¶Ô²»Æğ£¬ÎªÁË½µµÍÏµÍ³¸ººÉ£¬ÇëÉÔºóÔÙlogin£¬¶àĞ»ÄúµÄºÏ×÷¡£\n"NOR);
			destruct(ob);
			return;
		} 
		else
		{
			write(HIR"ËäÈ»ÄãÊÇÎ×Ê¦£¬Ò²²»ÒªÆµ·±µÄloginÅ¶¡£\n"NOR);
		}
	}
 
	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
	    
	    // netdead is delayed being set
	    // after disconnected, so should use interactive.
	    // mon 7/5/98
		if( !interactive(user) ) {
			reconnect(ob, user);
			return;
		}
		write(HIR"ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( objectp(user = make_body(ob)) ) {
		if( user->restore() ) {
			log_file( "login", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
				user->query("id"), query_ip_number(ob), ctime(time()) ) );
			if(!user->query("write_name"))
			{
				write_file("/adm/etc/banned_name",(string)user->query("name")+"\n",0);
				user->set("write_name","done");
			}

			enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write(HIR"ÇëÄúÖØĞÂ´´ÔìÕâ¸öÈËÎï¡£\n"NOR);
	confirm_id("y", ob);
}


protected void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write(HIR"ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
	    // user may be destructed during the process.
	    // so I put in this check. mon 4/15/98
		write(HIY"ºÃ°É£¬»¶Ó­ÏÂ´ÎÔÙÀ´¡£\n"NOR);
		destruct(ob);
		return;
	} else {
		tell_object(user, "ÓĞÈË´Ó±ğ´¦( " + query_ip_number(ob)
			+ " )Á¬ÏßÈ¡´úÄãËù¿ØÖÆµÄÈËÎï¡£\n");
		log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n",
		user->query("name"), user->query("id"),
			query_ip_number(ob), ctime(time()) ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");

//	if( old_link ) {
	// mon 7/5/98
	// need to check user is interactive before exec.
	// user may become non-interactive after the input_to.
	if( old_link && interactive(user)) {
	        // 5/11/98 mon
	        user->set_encoding(ob->query_encoding());

		exec(old_link, user);
	}
	if(old_link)      // mon 9/14/98
		destruct(old_link);

	reconnect(ob, user);	
}

protected void confirm_id(string yn, object ob)
{
	write( @TEXT
[35m
ÇëÄú¸ø×Ô¼ºÏëÒ»¸ö·ûºÏ¡¼Î÷ÓÎ¼Ç¡½Éñ»°ÊÀ½çµÄÖĞÎÄÃû×Ö¡£Õâ
¸öÃû×Ö½«´ú±íÄãÔÚÔÂÓ°ÆæÔµÖĞµÄÈËÎï£¬¶øÇÒÍùºó½«²»ÄÜÔÙ¸ü
¸Ä¡£Çë²»ÒªÈ¡Ò»Ğ©²»ÑÅ»òÊÇÈİÒ×Ôì³ÉËûÈËÀ§ÈÅµÄÃû×Ö¡£
[37m
[1;31m
Èç¹ûÄãÓĞÀ§ÄÑÊäÈëÖĞÎÄÃû×Ö£¬ÇëÖ±½ÓÇÃ»Ø³µ¼ü£Û£Ò£Å£Ô£Õ£Ò£Î£İ¡£
[37m

TEXT
	);
	write(CYN"ÄúµÄÖĞÎÄÃû×Ö£º"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
		destruct(ob);
	}
	ob->set_temp("get_name",0);
	input_to("get_name", ob);
}

protected void get_resp(string arg, object ob)
{
	if( arg=="" ) {
		write(CYN"ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}

	if( arg[0]=='y' || arg[0]=='Y' )
	{
//        printf("%O\n", ob);
		ob->set("name", Rname);
		write(CYN"ÇëÉè¶¨ÄúµÄÃÜÂë£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}
	else if( arg[0]=='n' || arg[0]=='N')
	{
		Rname = default_name();
		write(CYN"ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿"NOR);
		printf( HIY" -- %s £º"NOR, Rname);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}
	else {
		write(HIR"¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÂúÒâ(y)²»ÂúÒâ(n)£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}
}

protected void get_name(string arg, object ob)
{
	//arg = CONVERT_D->input(arg,ob);

	if( arg =="")
	{
		Rname = default_name();
		write(CYN"¿´À´ÄúÒª¸öËæ»ú²úÉúµÄÖĞÎÄÃû×Ö£®£®\n"NOR);
		write(CYN"ÄúÂúÒâ(y)²»ÂúÒâ(n)Õâ¸öÖĞÎÄÃû×Ö£¿"NOR);
		printf( HIY" -- %s £º"NOR, Rname);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}
	if( !check_legal_name(arg) ) {
		ob->add_temp("get_name",1);
		if(ob->query_temp("get_name")>2) {
	        // the user can't input proper chinese name.
	        // assign one for him/her.    mon 4/19/98

			arg = default_name();

			write(HIR"ÒòÎªÄã²»ÄÜÊäÈëÊÊµ±µÄÖĞÎÄÃû×Ö£¬ÏµÍ³Ö¸¶¨ÄãµÄÃû×ÖÎª£º"+arg+"\n"NOR);
			write(HIR"ÇëÔÚ½øÈëÓÎÏ·ºóÇëÎ×Ê¦°ïÖúĞŞ¸Ä¡£\n"NOR);
		} else {
			write(CYN"ÄúµÄÖĞÎÄÃû×Ö£º"NOR);
			ob->add_temp("input",1);
			if (ob->query_temp("input")>120)
			{
				write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
				destruct(ob);
			}
			input_to("get_name", ob);
			return;
		}
	}

	printf("%O\n", ob);
	ob->set("name", arg);
	write(CYN"ÇëÉè¶¨ÄúµÄÃÜÂë£º"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
		destruct(ob);
	}
	input_to("new_password", 1, ob);
}

protected void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 ) {
		write(HIR"ÃÜÂëÖÁÉÙÒªÓÉÎå¸ö×Ö·û×é³É£¬ÇëÖØÉèÄúµÄÃÜÂë£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write(CYN"ÇëÔÙÊäÈëÒ»´ÎÄúµÄÃÜÂë£¬ÒÔÈ·ÈÏÄúÃ»¼Ç´í£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
	input_to("confirm_password", 1, ob);
}

protected void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write(HIR"ÄúÁ½´ÎÊäÈëµÄÃÜÂë²¢²»Ò»Ñù£¬ÇëÖØĞÂÉè¶¨Ò»´ÎÃÜÂë£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}

	write(CYN"ÄúµÄµç×ÓÓÊ¼şµØÖ·(???@ccb)£º"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
		destruct(ob);
	}
	input_to("get_email",  ob);
}

protected void get_email(string email, object ob, mapping my)
{
	object user;

	ob->set("email", email);

	write("\n");
	if (email == "" || strsrch(email, "@ccb") == -1) {
		write(HIR"µç×ÓÓÊ¼şµØÖ·ĞèÒªÊÇ id@ccb µÄ¸ñÊ½¡£\n"NOR);
		write(CYN"ÄúµÄµç×ÓÓÊ¼şµØÖ·£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_email", ob, my);
		return;
	}
	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) ) {
	    if(ob) destruct(ob);
	    return;
	}

	write(CYN"ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
		destruct(ob);
	}
	input_to("get_gender", ob, user);
}

protected void get_gender(string gender, object ob, object user)
{
	if( gender=="" ) {
		write(CYN"ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "ÄĞĞÔ");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Å®ĞÔ" );
	else {
		write(HIR"¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÄĞĞÔ(m)»òÅ®ĞÔ(f)µÄ½ÇÉ«£º"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\nÄãÊäÈëµÄÖ¸Áî¹ı¶àÁË!!\n");
			destruct(ob);
		}
		input_to("get_gender", ob, user);
		return;
	}

	confirm_gift("n",ob,user);
}

object make_body(object ob)
{
	string err;
	object user;

        if(!ob->query("body")) {
	  return 0;
        }
	user = new(ob->query("body"));
	if(!user) {
		write(HIR"ÏÖÔÚ¿ÉÄÜÓĞÈËÕıÔÚĞŞ¸ÄÍæ¼ÒÎï¼şµÄ³ÌÊ½£¬ÎŞ·¨½øĞĞ¸´ÖÆ¡£\n"NOR);
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

protected void confirm_gift(string yn, object ob, object user)
{

	if(!ob || !user) {
		if(user) {
			destruct(user);
			return;
		}
		if(ob) destruct(ob);
			return;
	}

	user->set("kar", 20 );
	user->set("str", 20 );
	user->set("cps", 20 );
	user->set("int", 25 );
	user->set("cor", 20 );
	user->set("con", 20 );
	user->set("spi", 25 );
	user->set("per", 20 );

	// mon 3/21/99 allow players to choose gift after login.
	user->set("no_gift",1);

	CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
	user->set("title", "ÆÕÍ¨°ÙĞÕ");
	user->set("birthday", time() );
	user->set("potential", 299);
	user->set("food", user->max_food_capacity());
	user->set("water", user->max_water_capacity());
	user->set("channels", ({ "chat","rumor","moon","sldh","es","new","yyqy" }) );
	log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
	query_ip_number(ob), ctime(time()) ) );
	write_file("/adm/etc/banned_name",(string)user->query("name")+"\n",0);

	ob->set("last_from",query_ip_number(ob));
	ob->set("last_on",time());

	return enter_world(ob, user);
}

string dis_attr(int value)
{       int gift=20;
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}

varargs void enter_world(object ob, object user, int silent)
{
	object  mbx, login_ob;
	string startroom="";
	int num, i, newsnum;
	string *f_ids;
	mapping friends;

	reset_eval_cost();

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);

	// 5/11/98 mon
	//user->set_encoding(ob->query_encoding());

	exec(user, ob);
	write(HIW"\nÄ¿Ç°È¨ÏŞ£º" + wizhood(user) + "\n\n"NOR);
	user->setup();

	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();

	if( !silent ) {
		if(file_size(MOTD)>0)
			user->start_more(read_file(MOTD));
		
	     // mon 3/21/99 
	     // new user login.
		if(user->query("no_gift")) {
			user->move("/d/wiz/init",1);
		} else {
			if( wizardp(user))
				startroom = "/d/wiz/wizroom";
			if( user->is_ghost() )
				startroom = DEATH_ROOM;
			else if( strlen(startroom = user->query("startroom"))<2 )
				startroom = START_ROOM;

		if(!wizardp(user) && startroom[0..2]=="/u/") {
			startroom = START_ROOM;
			user->set("startroom",startroom);
		}

		// the following 7 lines are aded by snowcat dec 10 1997
		if ( wiz_level( user->query("id") ) > 1 )
		{
			user->move("/d/wiz/wizroom");
			CHANNEL_D->do_channel( user, "wiz*",
			sprintf("Á¬Ïß½øÈë"+get_config(__MUD_NAME__)+"¡£") );
		}
		else if (("/adm/daemons/band"
		    ->create_char_banned(query_ip_number(user)) == 1 ||
	    	    "/adm/daemons/band"->is_banned(query_ip_number(user))
		    == 1) && !wizardp(user)) {
			user->move("/d/wiz/guest");
			log_file( "ALLCONT", sprintf("from banned site\n"));
		}
		else if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		if(!wizardp(user) || !user->query("env/invisibility"))
			tell_room(startroom, user->query("name") + "Á¬Ïß½øÈëÕâ¸öÊÀ½ç¡£\n",
			({user}));
		friends=user->query("friendof");
		if(!friends|| !mapp(friends)||  (sizeof(friends) == 0))
			friends=([]);
		f_ids = keys(friends);
		for(i=0;i<sizeof(f_ids);i++)
		{
			if( ! find_player(f_ids[i]) && wizardp(user) ) continue;
			tell_object(find_player(f_ids[i]),HIG"¡¸¶£ßË¡¹ĞÅÏ¢¾«ÁéÍµÍµµÄ¸æËßÄã:¡°ÄãµÄºÃÓÑ"+user->name()+"ÒÑ¾­ÉÏÏßÀ­£¡\n"NOR);
		}
	}
//xuer 2001¡£02 Ôö¼Ó¡£
   
		mbx=ob->query_temp("mbox_ob");
		if (!mbx) {
		  mbx=new(MAILBOX_OB);
		  mbx->set_owner(ob->query("id"));
                }
		num=mbx->query_new_mail();
		if( num>0 ) {
	          write( GRN + "\nÇ§ÀïÑÛ¸æËßÄã£ºÓĞÄú"
		    +chinese_number(num)+
		    "·âĞÅ£¡Çëµ½ÄÏ³Ç¿ÍÕ»À´Ò»ÌË£®£®£®\n\n" + NOR);
		}
		destruct(mbx);
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%sÓÉ%sÁ¬Ïß½øÈë¡£", user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user)) );
	}
	if(user->query("last_on"))
		write(HIW"\nÄãÉÏ´Î¹âÁÙ"NOR MAG"ÔÂÓ°ÆæÔµ"HIW"ÊÇ " + HIG +ctime(user->query("last_on"))+ NOR + " ´Ó " + HIR +user->query("last_from") + NOR + " Á¬½ÓµÄ¡£\n\n"NOR);
	login_ob=new(LOGIN_OB);
	login_ob->set("id",user->query("id"));
	login_ob->restore();

	newsnum = sizeof("cmds/usr/news"->query("notes"));
	if( user->query("LastReadNews") != newsnum )
		write(MAG"\n ÔÂÓ°ÆæÔµ "HIW"ÓĞ×îĞÂ±ä¶¯£¡ÇëÓÃ "BLINK HIR"news new"NOR HIW" À´²é¿´¡£\n\n"NOR);

//¼ì²éÊÇ·ñ½øÈëÅÅĞĞ°ñ£¡add by jackyboy@cctx 1999/3/8
	TOPTEN_D->topten_checkplayer(user);

	UPDATE_D->check_user(user, 0);
	if( user->query("max_force") != user->query("maximum_force") )
		user->set("maximum_force", user->query("max_force") );
	if( user->query("max_mana") != user->query("maximum_mana") )
		user->set("maximum_mana", user->query("max_mana") );
	user->set_temp("temp/combat_exp",user->query("combat_exp"));
	user->set_temp("temp/daoxing",user->query("daoxing"));
	user->set_temp("temp/max_mana",user->query("max_mana"));
	user->set_temp("temp/max_force",user->query("max_force"));
	user->set_temp("temp/mud_age",user->query("mud_age"));
	user->set_temp("temp/login_time",time());
	if(wizardp(user)) {
//		CHANNEL_D->do_channel( this_object(), "wiz",
//		sprintf(NOR "%s" HIY " ´Ó " HIG "%s" HIY " ½øÈëÁ¬Ïß¡£", user->short(1), query_ip_name(user)) );
		/*if ( wizhood(user)=="(admin)")	{
			if( user->query("wiz_check/FILES") != file_size("/log/FILES") ) 
			{
				user->set("wiz_check/FILES", file_size("/log/FILES"));
				write(HIW"ÓĞÎ×Ê¦ÓĞ·Ç·¨Ğ´²Ù×÷£¬Á¢¼´²é¿´ /log/FILES ¡£\n"NOR);
			}
			if( user->query("wiz_check/CALL_PLAYER") != file_size("/log/static/CALL_PLAYER") ) 
			{
				user->set("wiz_check/CALL_PLAYER", file_size("/log/static/CALL_PLAYER"));
				write(HIW"ÓĞÎ×Ê¦ĞŞÊ¹ÓÃ¹ıcall£¬Á¢¼´²é¿´ /log/static/CALL_PLAYER ¡£\n"NOR);
			}
			if( user->query("wiz_check/jiangli") != file_size("/log/jiangli") ) 
			{
				user->set("wiz_check/jiangli", file_size("/log/jiangli"));
				write(HIW"ÓĞÎ×Ê¦½±Àø¹ıÍæ¼Ò£¬Á¢¼´²é¿´ /log/jiangli ¡£\n"NOR);
			}
			if( user->query("wiz_check/log") != file_size("/log/log") ) 
			{
				user->set("wiz_check/log", file_size("/log/log"));
				write(HIW"ÓĞĞÂÎÄ¼şupdate´íÎó£¬Á¢¼´²é¿´ /log/log ¡£\n"NOR);
			}
		}*/
		return;
	} 
      {object caishen;
	if(objectp(caishen=find_object("/d/wiz/npc/caishen"))) {
	  caishen->check_one(user);
        }
      }
}

varargs void reconnect(object ob, object user, int silent)
{
        object old_link;
	
	// mon 9/15/98
	old_link=user->query_temp("link_ob");
	if(old_link && old_link!=ob)
	    destruct(old_link);

	user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
  
	// 5/11/98 mon
	user->set_encoding(ob->query_encoding());

	exec(user, ob);

	user->reconnect();
	if( !silent && !user->query("env/invisibility")) {
		tell_room(environment(user), user->query("name") + "ÖØĞÂÁ¬Ïß»Øµ½Õâ¸öÊÀ½ç¡£\n",
		({user}));
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%sÓÉ%sÖØĞÂÁ¬Ïß½øÈë¡£", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_number(user)) );
	}
	UPDATE_D->check_user(user, 1); // this is for reconnect.
}

int check_legal_id(string id)
{
	int i;
	string *legalid;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
		write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×Ö±ØĞëÊÇ 3 µ½ 8 ¸öÓ¢ÎÄ×ÖÄ¸¡£\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×ÖÖ»ÄÜÓÃÓ¢ÎÄ×ÖÄ¸¡£\n");
			return 0;
		}
	legalid = explode(read_file(BANNED_ID), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( id == legalid[i] )   {
		  write("¶Ô²»Æğ£¬ÕâÖÖÓ¢ÎÄÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
		  return 0;
       }
	}
	return 1;
}

int check_legal_name(string name)
{
	int i;
	string *legalid;

	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
		write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö±ØĞëÊÇÒ»µ½Áù¸öÖĞÎÄ×Ö¡£\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö²»ÄÜÓÃ¿ØÖÆ×Ö·û¡£\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹È¡Ãû×Ö¡£\n");
			return 0;
		}
	}
	legalid = explode(read_file(BANNED_NAME), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( name == legalid[i] )   {
		  write("¶Ô²»Æğ£¬ÕâÖÖÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
		  return 0;
       }
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("¶Ô²»Æğ£¬ÕâÖÖÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++) {
          ob=body[i];
	  if( clonep(ob) && getuid(ob) == name 
            && ob->query("max_gin")>0 ) return ob;
	    //check max_gin to avoid damaged user object.
        }

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
