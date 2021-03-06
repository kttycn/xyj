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
	"你", "我", "他", "她", "它", "它", "江泽民", "邓小平", "李鹏", "朱榕基",
	"自己", "某人", "尸体", "我们","你们", "他们", "大家",
	"他妈的", "去你的", "毛泽东", "巫师", "他奶奶的",
});


string Rname;
string default_name()
{
	string *lname = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳","邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付","皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄","米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍","虞","万","支","柯","昝","管","卢","英","万","候","司马",
"上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫","尉迟","公羊","澹台","公治",
"宗政","濮阳","淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐","钟离","宇文",
"长孙","幕容","司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷","公良",
"拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦","段千","百里","东郭","南郭",
"呼延","归海","羊舌","微生","岳","帅","缑","亢","况","后","有","琴","梁丘","左丘","东门","西门",
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
	set("channel_id", "连线精灵");
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
            "世纪西游之"MAG"月影奇缘\n"NOR);
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998


void logon(object ob)
{
	object *usr;
	int i, login_cnt;

// 防止有恶意的玩家用 KMUD 等工具捣乱
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
	write("\n              [4;53m我们建议使用 800 * 600 的分辨率进入"+MUD_NAME+"。\n"NOR);
    write("                [4;53m   Best view with 800 * 600    \n"NOR);
    write("\n            月影奇缘欢迎您来访！使用国标码的玩家请键入：gb\n");
    write("            る紇絫舧眤ㄓ砐ㄏノき絏產叫龄big5\n\n");
    write("    [If there is no response after ENTER, please try Ctrl-ENTER]\n");
    write("        [提示：如果按"HIC"ENTER"NOR"键后系统没有响应，请试 Ctrl-ENTER]\n\n");
    write("          Welcome to Moon Love Story! Select GB or BIG5 (gb/big5):");
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n你输入的指令过多了!!\n");
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
	    write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
	    input_to( (: encoding :), ob );
	    return;
	} else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    encode=1;
	else {
	    write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
	   	write(HIR"您的地址在本 MUD 之信誉被人破坏了。\n"NOR);
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
	printf(MAG+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") 现有注册玩家"HIR"%s"NOR"位。",
	chinese_number(howmany_user()));
	write("\n"+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") 目前人数限制：" HIY + chinese_number(MAX_USERS)+NOR);
	write("\n"+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") 使用MUDOS版本：" HIY + "MudOS v22pre11"NOR);
	write("\n");

	printf(MAG+CHINESE_MUD_NAME+NOR"("NOR CYN+INTERMUD_MUD_NAME+NOR") 开站以来，最高在线数目："HIY"%s"NOR
	" 人，平均在线数目："HIY"%s"NOR" 人。\n",chinese_number(max_online),chinese_number(avg_online));
	printf(	"\n你现在从%s连线进入。\n",CYN+query_ip_number(ob)+NOR);
	if (iplimit>1)
		write("您所在的地址已有"HIY+chinese_number(iplimit-1)+NOR+"位玩家在线上。\n");
	if (ttl_cnt == 0) 
		printf("\n目前"); // info not available
	else 
		printf("\n目前共有%d位玩家在线上。本站", ttl_cnt );
	printf("共有"HIW"%s位管理人员"NOR"、"HIY"%s位玩家"NOR"，以及"HIC"%s位使用者在尝试连线"NOR"。\n\n",
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
	    write("对不起，"+MUD_NAME+"的玩家已经太多了，请待会儿再来。\n");
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
	write(CYN"鉴于这里是内部网，我们的主要任务是工作，本游戏不欢迎有工作任务的朋友来玩。\n"NOR);
	write(CYN"您是否是还有好多工作没有做完？？(yes/no)"NOR);
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
	    write(CYN"\n您是否是还有好多工作没有做完？(yes/no)"NOR);
	    input_to( (: if_young :), ob );
	    return;
	}

	if( arg[0..0] == "y" || arg[0..0] == "Y" )
	{
		write(HIG"\n好，欢迎你工作完成后再来。\n"NOR);
		destruct(ob);
		return;
	}

	if( arg[0..0] != "n" && arg[0..0] != "N" ) {
	    write(CYN"\n您是否是还有好多工作没有做完？(yes/no)"NOR);
	    input_to( (: if_young :), ob );
	    return;
	}

	cat(XYJ_SITES);
	write(CYN"\n您的英文名字（新玩家请键入 "HIW"New"NOR CYN" 注册）："NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n你输入的指令过多了!!\n");
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
		write(CYN"您的英文名字："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
		  write(HIR"对不起，"+MUD_NAME+"的玩家已经太多了，请待会儿再来。\n"NOR);
		  destruct(ob);
		  return;
		} 
	}
#endif

	if( wiz_level(arg) < wiz_lock_level ) {
		write(HIR"对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
			+ " 以上的人才能连线。\n"NOR);
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
			write(sprintf("对不起，从你的IP地址不能同时登录%s位人物。\n",
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
		write(CYN"\n请您给自己取一个英文名字："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("get_new_id",ob);
		return;
	} else if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			write(CYN"请输入相应密码："NOR);
			ob->add_temp("input",1);
			if (ob->query_temp("input")>120)
			{
				write("\n你输入的指令过多了!!\n");
				destruct(ob);
			}
			input_to("get_passwd", 1, ob);
			return;
		}
		write(HIW"您的人物储存档出了一些问题，请利用 guest 人物通知巫师处理。\n"NOR);
		write(HIW"密码："HIR"password"HIW"(为了他人正常使用该用户，请不要修改密码！)\n"NOR);
		destruct(ob);
		return;
	} 
	
	write(HIR"没有这个玩家．．．\n"NOR);
	write(CYN"您的英文名字：（新玩家请键入 "HIR"new"NOR CYN" 注册）"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n你输入的指令过多了!!\n");
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
// 防止两个以上的玩家用同一 id
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
	if (i >= 0) {
		write("有其他玩家正在使用这个 ID，请重新输入。\n");
		write("您的英文名字：");
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("get_new_id", ob);
		return;
	}
	if(!arg) {
		write(CYN"\n请您给自己取一个英文名字："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("get_new_id", ob);
		return;
	}

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write(CYN"\n请您给自己取一个英文名字："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
	    write(HIR"这个名字已经被别的玩家使用了．．．"NOR);
		write(CYN"\n请您给自己取一个英文名字："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
	    input_to("get_new_id",ob);
	    return;
	}

	if( arg=="tmd" || arg=="fuck") {
	    write(HIR"这样的名字你也要．．．？"NOR);
		write(CYN"\n请您给自己取一个英文名字："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
	    input_to("get_new_id",ob);
	    return;
	}
	if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
	    write(HIR"这个名字已经被别的玩家使用了．．．"NOR);
		write(CYN"\n请您给自己取一个英文名字："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
		write(HIR"密码错误！"NOR);
		write(HIW"请重新连线，键入正确的密码或另取一个新的英文名字。\n"NOR);
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
		temps = sprintf("你距上次退出仅 %d 秒?\n", time_rl);
		write(temps);
		if ((string)SECURITY_D->get_status(ob->query("id")) == "(player)")
		{
			write(HIR"对不起，为了降低系统负荷，请稍后再login，多谢您的合作。\n"NOR);
			destruct(ob);
			return;
		} 
		else
		{
			write(HIR"虽然你是巫师，也不要频繁的login哦。\n"NOR);
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
		write(HIR"您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
	write(HIR"请您重新创造这个人物。\n"NOR);
	confirm_id("y", ob);
}


protected void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write(HIR"您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
	    // user may be destructed during the process.
	    // so I put in this check. mon 4/15/98
		write(HIY"好吧，欢迎下次再来。\n"NOR);
		destruct(ob);
		return;
	} else {
		tell_object(user, "有人从别处( " + query_ip_number(ob)
			+ " )连线取代你所控制的人物。\n");
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
请您给自己想一个符合〖西游记〗神话世界的中文名字。这
个名字将代表你在月影奇缘中的人物，而且往后将不能再更
改。请不要取一些不雅或是容易造成他人困扰的名字。
[37m
[1;31m
如果你有困难输入中文名字，请直接敲回车键［ＲＥＴＵＲＮ］。
[37m

TEXT
	);
	write(CYN"您的中文名字："NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n你输入的指令过多了!!\n");
		destruct(ob);
	}
	ob->set_temp("get_name",0);
	input_to("get_name", ob);
}

protected void get_resp(string arg, object ob)
{
	if( arg=="" ) {
		write(CYN"您满意(y)不满意(n)这个中文名字？"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}

	if( arg[0]=='y' || arg[0]=='Y' )
	{
//        printf("%O\n", ob);
		ob->set("name", Rname);
		write(CYN"请设定您的密码："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}
	else if( arg[0]=='n' || arg[0]=='N')
	{
		Rname = default_name();
		write(CYN"您满意(y)不满意(n)这个中文名字？"NOR);
		printf( HIY" -- %s ："NOR, Rname);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("get_resp", ob);
		return;
	}
	else {
		write(HIR"对不起，您只能选择满意(y)不满意(n)："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
		write(CYN"看来您要个随机产生的中文名字．．\n"NOR);
		write(CYN"您满意(y)不满意(n)这个中文名字？"NOR);
		printf( HIY" -- %s ："NOR, Rname);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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

			write(HIR"因为你不能输入适当的中文名字，系统指定你的名字为："+arg+"\n"NOR);
			write(HIR"请在进入游戏后请巫师帮助修改。\n"NOR);
		} else {
			write(CYN"您的中文名字："NOR);
			ob->add_temp("input",1);
			if (ob->query_temp("input")>120)
			{
				write("\n你输入的指令过多了!!\n");
				destruct(ob);
			}
			input_to("get_name", ob);
			return;
		}
	}

	printf("%O\n", ob);
	ob->set("name", arg);
	write(CYN"请设定您的密码："NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n你输入的指令过多了!!\n");
		destruct(ob);
	}
	input_to("new_password", 1, ob);
}

protected void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 ) {
		write(HIR"密码至少要由五个字符组成，请重设您的密码："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write(CYN"请再输入一次您的密码，以确认您没记错："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
		write(HIR"您两次输入的密码并不一样，请重新设定一次密码："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("new_password", 1, ob);
		return;
	}

	write(CYN"您的电子邮件地址(???@ccb)："NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n你输入的指令过多了!!\n");
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
		write(HIR"电子邮件地址需要是 id@ccb 的格式。\n"NOR);
		write(CYN"您的电子邮件地址："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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

	write(CYN"您要扮演男性(m)的角色或女性(f)的角色？"NOR);
	ob->add_temp("input",1);
	if (ob->query_temp("input")>120)
	{
		write("\n你输入的指令过多了!!\n");
		destruct(ob);
	}
	input_to("get_gender", ob, user);
}

protected void get_gender(string gender, object ob, object user)
{
	if( gender=="" ) {
		write(CYN"您要扮演男性(m)的角色或女性(f)的角色？"NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
			destruct(ob);
		}
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "男性");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "女性" );
	else {
		write(HIR"对不起，您只能选择男性(m)或女性(f)的角色："NOR);
		ob->add_temp("input",1);
		if (ob->query_temp("input")>120)
		{
			write("\n你输入的指令过多了!!\n");
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
		write(HIR"现在可能有人正在修改玩家物件的程式，无法进行复制。\n"NOR);
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
	user->set("title", "普通百姓");
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
	write(HIW"\n目前权限：" + wizhood(user) + "\n\n"NOR);
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
			sprintf("连线进入"+get_config(__MUD_NAME__)+"。") );
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
			tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
			({user}));
		friends=user->query("friendof");
		if(!friends|| !mapp(friends)||  (sizeof(friends) == 0))
			friends=([]);
		f_ids = keys(friends);
		for(i=0;i<sizeof(f_ids);i++)
		{
			if( ! find_player(f_ids[i]) && wizardp(user) ) continue;
			tell_object(find_player(f_ids[i]),HIG"「叮咚」信息精灵偷偷的告诉你:“你的好友"+user->name()+"已经上线拉！\n"NOR);
		}
	}
//xuer 2001。02 增加。
   
		mbx=ob->query_temp("mbox_ob");
		if (!mbx) {
		  mbx=new(MAILBOX_OB);
		  mbx->set_owner(ob->query("id"));
                }
		num=mbx->query_new_mail();
		if( num>0 ) {
	          write( GRN + "\n千里眼告诉你：有您"
		    +chinese_number(num)+
		    "封信！请到南城客栈来一趟．．．\n\n" + NOR);
		}
		destruct(mbx);
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s由%s连线进入。", user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user)) );
	}
	if(user->query("last_on"))
		write(HIW"\n你上次光临"NOR MAG"月影奇缘"HIW"是 " + HIG +ctime(user->query("last_on"))+ NOR + " 从 " + HIR +user->query("last_from") + NOR + " 连接的。\n\n"NOR);
	login_ob=new(LOGIN_OB);
	login_ob->set("id",user->query("id"));
	login_ob->restore();

	newsnum = sizeof("cmds/usr/news"->query("notes"));
	if( user->query("LastReadNews") != newsnum )
		write(MAG"\n 月影奇缘 "HIW"有最新变动！请用 "BLINK HIR"news new"NOR HIW" 来查看。\n\n"NOR);

//检查是否进入排行榜！add by jackyboy@cctx 1999/3/8
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
//		sprintf(NOR "%s" HIY " 从 " HIG "%s" HIY " 进入连线。", user->short(1), query_ip_name(user)) );
		/*if ( wizhood(user)=="(admin)")	{
			if( user->query("wiz_check/FILES") != file_size("/log/FILES") ) 
			{
				user->set("wiz_check/FILES", file_size("/log/FILES"));
				write(HIW"有巫师有非法写操作，立即查看 /log/FILES 。\n"NOR);
			}
			if( user->query("wiz_check/CALL_PLAYER") != file_size("/log/static/CALL_PLAYER") ) 
			{
				user->set("wiz_check/CALL_PLAYER", file_size("/log/static/CALL_PLAYER"));
				write(HIW"有巫师修使用过call，立即查看 /log/static/CALL_PLAYER 。\n"NOR);
			}
			if( user->query("wiz_check/jiangli") != file_size("/log/jiangli") ) 
			{
				user->set("wiz_check/jiangli", file_size("/log/jiangli"));
				write(HIW"有巫师奖励过玩家，立即查看 /log/jiangli 。\n"NOR);
			}
			if( user->query("wiz_check/log") != file_size("/log/log") ) 
			{
				user->set("wiz_check/log", file_size("/log/log"));
				write(HIW"有新文件update错误，立即查看 /log/log 。\n"NOR);
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
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
		({user}));
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s由%s重新连线进入。", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_number(user)) );
	}
	UPDATE_D->check_user(user, 1); // this is for reconnect.
}

int check_legal_id(string id)
{
	int i;
	string *legalid;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
		write("对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("对不起，你的英文名字只能用英文字母。\n");
			return 0;
		}
	legalid = explode(read_file(BANNED_ID), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( id == legalid[i] )   {
		  write("对不起，这种英文名字会造成其他人的困扰。\n");
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
		write("对不起，你的中文名字必须是一到六个中文字。\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("对不起，你的中文名字不能用控制字符。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}
	legalid = explode(read_file(BANNED_NAME), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( name == legalid[i] )   {
		  write("对不起，这种名字会造成其他人的困扰。\n");
		  return 0;
       }
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("对不起，这种名字会造成其他人的困扰。\n");
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
