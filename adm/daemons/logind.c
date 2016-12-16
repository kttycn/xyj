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
	"��", "��", "��", "��", "��", "��", "������", "��Сƽ", "����", "���Ż�",
	"�Լ�", "ĳ��", "ʬ��", "����","����", "����", "���",
	"�����", "ȥ���", "ë��", "��ʦ", "�����̵�",
});


string Rname;
string default_name()
{
	string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
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
	set("channel_id", "���߾���");
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
            "��������֮"MAG"��Ӱ��Ե\n"NOR);
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998


void logon(object ob)
{
	object *usr;
	int i, login_cnt;

// ��ֹ�ж��������� KMUD �ȹ��ߵ���
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
	write("\n              [4;53m���ǽ���ʹ�� 800 * 600 �ķֱ��ʽ���"+MUD_NAME+"��\n"NOR);
    write("                [4;53m   Best view with 800 * 600    \n"NOR);
    write("\n            ��Ӱ��Ե��ӭ�����ã�ʹ�ù�������������룺gb\n");
    write("            ��v�_�t�w��z�ӳX�I�ϥΤj���X�����a����J�Gbig5\n\n");
    write("    [If there is no response after ENTER, please try Ctrl-ENTER]\n");
    write("        [��ʾ�������"HIC"ENTER"NOR"����ϵͳû����Ӧ������ Ctrl-ENTER]\n\n");
    write("          Welcome to Moon Love Story! Select GB or BIG5 (gb/big5):");
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n�������ָ�������!!\n");
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
	    write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
	    input_to( (: encoding :), ob );
	    return;
	} else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    encode=1;
	else {
	    write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
	   	write(HIR"���ĵ�ַ�ڱ� MUD ֮���������ƻ��ˡ�\n"NOR);
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
	printf(MAG+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") ����ע�����"HIR"%s"NOR"λ��",
	chinese_number(howmany_user()));
	write("\n"+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") Ŀǰ�������ƣ�" HIY + chinese_number(MAX_USERS)+NOR);
	write("\n"+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") ʹ��MUDOS�汾��" HIY + "MudOS v22pre11"NOR);
	write("\n");

	printf(MAG+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") ��վ���������������Ŀ��"HIY"%s"NOR
	" �ˣ�ƽ��������Ŀ��"HIY"%s"NOR" �ˡ�\n",chinese_number(max_online),chinese_number(avg_online));
	printf(	"\n�����ڴ�%s���߽��롣\n",CYN+query_ip_number(ob)+NOR);
	if (iplimit>1)
		write("�����ڵĵ�ַ����"HIY+chinese_number(iplimit-1)+NOR+"λ��������ϡ�\n");
	if (ttl_cnt == 0) 
		printf("\nĿǰ"); // info not available
	else 
		printf("\nĿǰ����%dλ��������ϡ���վ", ttl_cnt );
	printf("����"HIW"%sλ������Ա"NOR"��"HIY"%sλ���"NOR"���Լ�"HIC"%sλʹ�����ڳ�������"NOR"��\n\n",
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
	    write("�Բ���"+MUD_NAME+"������Ѿ�̫���ˣ�������������\n");
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
	write(CYN"�����������ڲ��������ǵ���Ҫ�����ǹ���������Ϸ����ӭ�й���������������档\n"NOR);
	write(CYN"���Ƿ��ǻ��кö๤��û�����ꣿ��(yes/no)"NOR);
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
	    write(CYN"\n���Ƿ��ǻ��кö๤��û�����ꣿ(yes/no)"NOR);
	    input_to( (: if_young :), ob );
	    return;
	}

	if( arg[0..0] == "y" || arg[0..0] == "Y" )
	{
		write(HIG"\n�ã���ӭ�㹤����ɺ�������\n"NOR);
		destruct(ob);
		return;
	}

	if( arg[0..0] != "n" && arg[0..0] != "N" ) {
	    write(CYN"\n���Ƿ��ǻ��кö๤��û�����ꣿ(yes/no)"NOR);
	    input_to( (: if_young :), ob );
	    return;
	}

	cat(XYJ_SITES);
	write(CYN"\n����Ӣ�����֣����������� "HIW"New"NOR CYN" ע�ᣩ��"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n�������ָ�������!!\n");
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
		write(CYN"����Ӣ�����֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
		  write(HIR"�Բ���"+MUD_NAME+"������Ѿ�̫���ˣ�������������\n"NOR);
		  destruct(ob);
		  return;
		} 
	}
#endif

	if( wiz_level(arg) < wiz_lock_level ) {
		write(HIR"�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
			+ " ���ϵ��˲������ߡ�\n"NOR);
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
			write(sprintf("�Բ��𣬴����IP��ַ����ͬʱ��¼%sλ���\n",
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
		write(CYN"\n�������Լ�ȡһ��Ӣ�����֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("get_new_id",ob);
		return;
	} else if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			write(CYN"��������Ӧ���룺"NOR);
			ob->add_temp("input",1);
			if (ob->query_temp("input")>120)
			{
				write("\n�������ָ�������!!\n");
				destruct(ob);
			}
			input_to("get_passwd", 1, ob);
			return;
		}
		write(HIW"�������ﴢ�浵����һЩ���⣬������ guest ����֪ͨ��ʦ����\n"NOR);
		write(HIW"���룺"HIR"password"HIW"(Ϊ����������ʹ�ø��û����벻Ҫ�޸����룡)\n"NOR);
		destruct(ob);
		return;
	} 
	
	write(HIR"û�������ң�����\n"NOR);
	write(CYN"����Ӣ�����֣������������� "HIR"new"NOR CYN" ע�ᣩ"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n�������ָ�������!!\n");
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
// ��ֹ�������ϵ������ͬһ id
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
	if (i >= 0) {
		write("�������������ʹ����� ID�����������롣\n");
		write("����Ӣ�����֣�");
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("get_new_id", ob);
		return;
	}
	if(!arg) {
		write(CYN"\n�������Լ�ȡһ��Ӣ�����֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("get_new_id", ob);
		return;
	}

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write(CYN"\n�������Լ�ȡһ��Ӣ�����֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
	    write(HIR"��������Ѿ���������ʹ���ˣ�����"NOR);
		write(CYN"\n�������Լ�ȡһ��Ӣ�����֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
	    input_to("get_new_id",ob);
	    return;
	}

	if( arg=="tmd" || arg=="fuck") {
	    write(HIR"������������ҲҪ��������"NOR);
		write(CYN"\n�������Լ�ȡһ��Ӣ�����֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
	    input_to("get_new_id",ob);
	    return;
	}
	if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
	    write(HIR"��������Ѿ���������ʹ���ˣ�����"NOR);
		write(CYN"\n�������Լ�ȡһ��Ӣ�����֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
		write(HIR"�������"NOR);
		write(HIW"���������ߣ�������ȷ���������ȡһ���µ�Ӣ�����֡�\n"NOR);
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
		temps = sprintf("����ϴ��˳��� %d ��?\n", time_rl);
		write(temps);
		if ((string)SECURITY_D->get_status(ob->query("id")) == "(player)")
		{
			write(HIR"�Բ���Ϊ�˽���ϵͳ���ɣ����Ժ���login����л���ĺ�����\n"NOR);
			destruct(ob);
			return;
		} 
		else
		{
			write(HIR"��Ȼ������ʦ��Ҳ��ҪƵ����loginŶ��\n"NOR);
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
		write(HIR"��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
	write(HIR"�������´���������\n"NOR);
	confirm_id("y", ob);
}


protected void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write(HIR"��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
	    // user may be destructed during the process.
	    // so I put in this check. mon 4/15/98
		write(HIY"�ðɣ���ӭ�´�������\n"NOR);
		destruct(ob);
		return;
	} else {
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
			+ " )����ȡ���������Ƶ����\n");
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
�������Լ���һ�����ϡ����μǡ���������������֡���
�����ֽ�����������Ӱ��Ե�е�����������󽫲����ٸ�
�ġ��벻ҪȡһЩ���Ż�����������������ŵ����֡�
[37m
[1;31m
����������������������֣���ֱ���ûس����ۣңţԣգңΣݡ�
[37m

TEXT
	);
	write(CYN"�����������֣�"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n�������ָ�������!!\n");
		destruct(ob);
	}
	ob->set_temp("get_name",0);
	input_to("get_name", ob);
}

protected void get_resp(string arg, object ob)
{
	if( arg=="" ) {
		write(CYN"������(y)������(n)����������֣�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}

	if( arg[0]=='y' || arg[0]=='Y' )
	{
//        printf("%O\n", ob);
		ob->set("name", Rname);
		write(CYN"���趨�������룺"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}
	else if( arg[0]=='n' || arg[0]=='N')
	{
		Rname = default_name();
		write(CYN"������(y)������(n)����������֣�"NOR);
		printf( HIY" -- %s ��"NOR, Rname);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}
	else {
		write(HIR"�Բ�����ֻ��ѡ������(y)������(n)��"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
		write(CYN"������Ҫ������������������֣���\n"NOR);
		write(CYN"������(y)������(n)����������֣�"NOR);
		printf( HIY" -- %s ��"NOR, Rname);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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

			write(HIR"��Ϊ�㲻�������ʵ����������֣�ϵͳָ���������Ϊ��"+arg+"\n"NOR);
			write(HIR"���ڽ�����Ϸ������ʦ�����޸ġ�\n"NOR);
		} else {
			write(CYN"�����������֣�"NOR);
			ob->add_temp("input",1);
			if (ob->query_temp("input")>120)
			{
				write("\n�������ָ�������!!\n");
				destruct(ob);
			}
			input_to("get_name", ob);
			return;
		}
	}

	printf("%O\n", ob);
	ob->set("name", arg);
	write(CYN"���趨�������룺"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n�������ָ�������!!\n");
		destruct(ob);
	}
	input_to("new_password", 1, ob);
}

protected void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 ) {
		write(HIR"��������Ҫ������ַ���ɣ��������������룺"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write(CYN"��������һ���������룬��ȷ����û�Ǵ�"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
		write(HIR"��������������벢��һ�����������趨һ�����룺"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}

	write(CYN"���ĵ����ʼ���ַ(???@ccb)��"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n�������ָ�������!!\n");
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
		write(HIR"�����ʼ���ַ��Ҫ�� id@ccb �ĸ�ʽ��\n"NOR);
		write(CYN"���ĵ����ʼ���ַ��"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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

	write(CYN"��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n�������ָ�������!!\n");
		destruct(ob);
	}
	input_to("get_gender", ob, user);
}

protected void get_gender(string gender, object ob, object user)
{
	if( gender=="" ) {
		write(CYN"��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
			destruct(ob);
		}
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "����");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Ů��" );
	else {
		write(HIR"�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n�������ָ�������!!\n");
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
		write(HIR"���ڿ������������޸��������ĳ�ʽ���޷����и��ơ�\n"NOR);
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
	user->set("title", "��ͨ����");
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
	write(HIW"\nĿǰȨ�ޣ�" + wizhood(user) + "\n\n"NOR);
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
			sprintf("���߽���"+get_config(__MUD_NAME__)+"��") );
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
			tell_room(startroom, user->query("name") + "���߽���������硣\n",
			({user}));
		friends=user->query("friendof");
		if(!friends|| !mapp(friends)||  (sizeof(friends) == 0))
			friends=([]);
		f_ids = keys(friends);
		for(i=0;i<sizeof(f_ids);i++)
		{
			if( ! find_player(f_ids[i]) && wizardp(user) ) continue;
			tell_object(find_player(f_ids[i]),HIG"�����ˡ���Ϣ����͵͵�ĸ�����:����ĺ���"+user->name()+"�Ѿ���������\n"NOR);
		}
	}
//xuer 2001��02 ���ӡ�
   
		mbx=ob->query_temp("mbox_ob");
		if (!mbx) {
		  mbx=new(MAILBOX_OB);
		  mbx->set_owner(ob->query("id"));
                }
		num=mbx->query_new_mail();
		if( num>0 ) {
	          write( GRN + "\nǧ���۸����㣺����"
		    +chinese_number(num)+
		    "���ţ��뵽�ϳǿ�ջ��һ�ˣ�����\n\n" + NOR);
		}
		destruct(mbx);
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s��%s���߽��롣", user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user)) );
	}
	if(user->query("last_on"))
		write(HIW"\n���ϴι���"NOR MAG"��Ӱ��Ե"HIW"�� " + HIG +ctime(user->query("last_on"))+ NOR + " �� " + HIR +user->query("last_from") + NOR + " ���ӵġ�\n\n"NOR);
	login_ob=new(LOGIN_OB);
	login_ob->set("id",user->query("id"));
	login_ob->restore();

	newsnum = sizeof("cmds/usr/news"->query("notes"));
	if( user->query("LastReadNews") != newsnum )
		write(MAG"\n ��Ӱ��Ե "HIW"�����±䶯������ "BLINK HIR"news new"NOR HIW" ���鿴��\n\n"NOR);

//����Ƿ�������а�add by jackyboy@cctx 1999/3/8
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
//		sprintf(NOR "%s" HIY " �� " HIG "%s" HIY " �������ߡ�", user->short(1), query_ip_name(user)) );
		/*if ( wizhood(user)=="(admin)")	{
			if( user->query("wiz_check/FILES") != file_size("/log/FILES") ) 
			{
				user->set("wiz_check/FILES", file_size("/log/FILES"));
				write(HIW"����ʦ�зǷ�д�����������鿴 /log/FILES ��\n"NOR);
			}
			if( user->query("wiz_check/CALL_PLAYER") != file_size("/log/static/CALL_PLAYER") ) 
			{
				user->set("wiz_check/CALL_PLAYER", file_size("/log/static/CALL_PLAYER"));
				write(HIW"����ʦ��ʹ�ù�call�������鿴 /log/static/CALL_PLAYER ��\n"NOR);
			}
			if( user->query("wiz_check/jiangli") != file_size("/log/jiangli") ) 
			{
				user->set("wiz_check/jiangli", file_size("/log/jiangli"));
				write(HIW"����ʦ��������ң������鿴 /log/jiangli ��\n"NOR);
			}
			if( user->query("wiz_check/log") != file_size("/log/log") ) 
			{
				user->set("wiz_check/log", file_size("/log/log"));
				write(HIW"�����ļ�update���������鿴 /log/log ��\n"NOR);
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
		tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
		({user}));
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s��%s�������߽��롣", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_number(user)) );
	}
	UPDATE_D->check_user(user, 1); // this is for reconnect.
}

int check_legal_id(string id)
{
	int i;
	string *legalid;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
		write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
			return 0;
		}
	legalid = explode(read_file(BANNED_ID), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( id == legalid[i] )   {
		  write("�Բ�������Ӣ�����ֻ���������˵����š�\n");
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
		write("�Բ�������������ֱ�����һ�����������֡�\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�Բ�������������ֲ����ÿ����ַ���\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	legalid = explode(read_file(BANNED_NAME), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( name == legalid[i] )   {
		  write("�Բ����������ֻ���������˵����š�\n");
		  return 0;
       }
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("�Բ����������ֻ���������˵����š�\n");
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
