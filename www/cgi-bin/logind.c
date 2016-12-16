// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>     // for GB_AND_BIG5 define.

inherit F_DBASE;

//int wiz_lock_level = WIZ_LOCK_LEVEL;
int wiz_lock_level = 1;
string BBSVISITOR = "/data/bbsvisitor";
//#define NY "/obj/gift/ny1"

string *banned_name = ({
        "��", "��", "��", "��", "��", "��", "������", "��Сƽ", "����", "���Ż�"
,
        "�Լ�", "ĳ��", "ʬ��", "����","����", "����", "���",
        "�����", "ȥ���", "ë��", "��ʦ", "�����̵�",
});

string *default_name=({"����","����", "����",
                       "����","�׳�","����","����",
                       "���","ư��","�ȳ�","��",
                        "ţ", "�ϻ�", "����",
                        "��","è��","��","��",
                        "����","�ڹ�","��","���",
                        "¹","��","Ϭţ"});
string *default_prefix=({"С","��","��","��","��","��","��","��",
        "ֽ","ľͷ","ʯͷ","��"});


void logind_user_log(); // mon 11/5/98
int total_count,bjtime,user_num;
int howmany_visitor();
void set_visitor();
private void encoding(string arg, object ob);
//private void if_young(string arg, object ob);
private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
string ip_from;
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string dis_attr(int value);
private void confirm_gift(string yn,object ob,object user);
private void judge_freeze(object ob); //����ԭ�� �����ж��˺��Ƿ񱻶�

void create()
{
        seteuid(getuid());
        set("channel_id", "���߾���");
        set("id", "logind");
}
int howmany_visitor()
{
int num;
string content,format;
content=read_file(BBSVISITOR);
if (sscanf(content,"%s %d", format, num)==2)
{
if(format!="VISITOR" && wizardp(this_player()))
  write("��ʦ��ע�⣬�����ߵ���Ŀ�п��ܲ��ԣ�"+"��쿴logind.c�е�howmany_visitor������\n");
return num;
}

return 0;
}
void set_visitor()
{
int user_num=1;
user_num=howmany_visitor()+1;
rm(BBSVISITOR);
    write_file(BBSVISITOR,"VISITOR "+user_num);
return;
}
// mon 11/7/98
void logind_user_log()
{
    int user=sizeof(users());
    int total;

    remove_call_out("logind_user_log");
    rm("/log/user_count");    log_file("user_count",""+
            ((total=total_count)?total:user)+"\n"+
            user+"\n"+
            UPTIME_CMD->report_str()+"\n"+
            "���μ�\n");
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998

void logon(object ob)
{

#ifdef GB_AND_BIG5
     cat(BANNER);
//    cat(FJ);
write("         Welcome to Y S Z Z! Select GB or BIG5 (gb/big5):");
    input_to( (: encoding :), ob );
#else
    encoding("gb",ob);
#endif

}

private void encoding(string arg, object ob)
{
        object *usr;
        int i, ttl_cnt, wiz_cnt, ppl_cnt, login_cnt;
        string ip_name, ip_number;
        int ii;
        mixed info;
        int encode;


        if(!arg || arg=="") {
            write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
            input_to( (: encoding :), ob );
            return;
        } else if(arg[0..0]=="g" || arg[0..0]=="G")
            encode=0;
        else if(arg[0..0]=="b" || arg[0..0]=="B")
            encode=1;
        else {
            write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
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
                        log_file( "ALLCONT", sprintf("kicked out, Non_number\n")
);
                        return;
                }
        }

        write(CLR);

   switch ( random(6))
    {
   case 0:
   cat(WELCOME);
   break;
   case 1:
   cat(WELCOME2);
    break;
    case 2:
   cat(WELCOME3);
   break;
   case 3:
   cat(WELCOME4);
   break;
   case 4:
   cat(WELCOME5);
    break;
    case 5:
   cat(WELCOME6);
   break;
   }
//      MUDLIST_CMD->main(ob);
        UPTIME_CMD->report();

        // children will show both netdead and interactive users.
        usr = children(USER_OB);
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( (wizardp(usr[i]) && (string)wizhood(usr[i])!="(elder)")
&& !usr[i]->query("env/invisibility") ) wiz_cnt++;
                else ppl_cnt++;
        }
bjtime = time();
user_num=0;
user_num=howmany_visitor();
if (user_num>0)
write(HIR"��"WHT"��"HIG+MUD_NAME+WHT"��"NOR" ��һ�žŰ���ʮ��һ���𹲱�����"+HIW+chinese_number(user_num+1)+NOR"�˴�.\n");
set_visitor();

        // snowcat Mar 11 1998
//   ttl_cnt = total_players();
write(HIR"��"WHT"��"HIG+MUD_NAME+WHT"��"NOR" ���֧��������"HIR+chinese_number(MAX_USERS)+NOR"�ˡ�\n");
   printf(HIR"��"WHT"��"HIG"����֮��"WHT"��"NOR" Ŀǰ����"HIY" %s"NOR" λ��ʦ��"HIW"%s"NOR" λ��������ϣ��Լ� "HIC"%s"NOR" λʹ���߳��������С�\n",
                chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
rm("/log/counter_for_web");
log_file("counter_for_web",sprintf("Ŀǰ����%sλ��ʦ��%sλ��������ϣ��Լ�%sλʹ���߳���������",
                chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) ));
login_cnt = 0;

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

        write(HIR"��"WHT"��"HIG" ����Ӣ������ "WHT"��"NOR"������������ new ע�ᣩ");
        input_to( (: get_id :), ob);

}

private void get_id(string arg, object ob)
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
                write("����Ӣ�����֣�");
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
                  write("�Բ���"+MUD_NAME+"������Ѿ�̫���ˣ�������������\n");

                  destruct(ob);
                  return;
                }
        }
#endif
/*
        if( wiz_level(arg) < wiz_lock_level ) {
                write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
                        + " ���ϵ��˲������ߡ�\n");
                destruct(ob);
                return;
      }
*/
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
//              confirm_id("Yes", ob);
//              return;

} else if (arg=="new") { // new player login
                write("\n�������Լ�ȡһ��Ӣ�����֣�");
                input_to("get_new_id",ob);
                return;
        } else if( file_size(ob->query_save_file()
                    + __SAVE_EXTENSION__) >= 0 ) {
                if( ob->restore() ) {
                        judge_freeze(ob);
                        write(HIR"��"WHT"��"HIG"��������Ӧ����"WHT"��"NOR"");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("�������ﴢ�浵����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
                destruct(ob);
                return;
        }

        write("û�������ң�����\n");
        write("����Ӣ�����֣������������� new ע�ᣩ");
        input_to("get_id", ob);
        return;
}

private void judge_freeze(object ob)
{
        int freeze_time;
      freeze_time=ob->query("freeze_time");
        if( time() < freeze_time ) {
write ("�Բ�������˺��Ѿ�������,����"+(freeze_time+3600-time())/3600 +"С
ʱ����ʹ��");
             destruct(ob);
             return;
        }
}        
 

private void get_new_id(string arg, object ob)

{
        object ppl;
        int id_count;

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

        if(!arg) {
                write("\n�������Լ�ȡһ��Ӣ�����֣�");
                input_to("get_new_id", ob);
                return;
        }

        arg = lower_case(arg);

        if( !check_legal_id(arg)) {
                write("\n�������Լ�ȡһ��Ӣ�����֣�");
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
            write("��������Ѿ���������ʹ���ˣ�����");
            write("\n�������Լ�ȡһ��Ӣ�����֣�");
            input_to("get_new_id",ob);
            return;
        }

        if( file_size(ob->query_save_file()
                    + __SAVE_EXTENSION__) >= 0 ) {
            write("��������Ѿ���������ʹ���ˣ�����");

            write("\n�������Լ�ȡһ��Ӣ�����֣�");
            input_to("get_new_id",ob);
            return;
        }

        confirm_id("Yes", ob);
        return;
}

private void get_passwd(string pass, object ob)
{
        string my_pass,id;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass
||         !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
                write("�������");
                write("���������ߣ�������ȷ���������ȡһ���µ�Ӣ�����֡�\n");
                if((id=ob->query("id")) && member_array(id,
                        SECURITY_D->get_wizlist())!=-1)
                  log_file("wizlogin",ctime(time())+" "+id+

                        " failed login from "+query_ip_number(ob)+"\n");
                else
                  log_file("login",ctime(time())+" "+id+
                        " failed login from "+query_ip_number(ob)+"\n");
                destruct(ob);
                return;
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
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }


   if( objectp(user = make_body(ob)) ) {
     if( user->restore() ) {
        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
          user->query("id"), query_ip_number(ob), ctime(time()) ) );

        enter_world(ob, user);
        return;
     } else {
        destruct(user);
     }
   }
   write("�������´���������\n");
   confirm_id("y", ob);
}


private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");

                input_to("confirm_relogin", ob, user);
                return;
        }

        if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
            // user may be destructed during the process.
            // so I put in this check. mon 4/15/98
                write("�ðɣ���ӭ�´�������\n");
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

//      if( old_link ) {
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

private void confirm_id(string yn, object ob)
{
    /*
        if( yn=="" ) {
                write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to("confirm_id", ob);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ���ô��������������Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }
        */


        write( @TEXT

�������Լ���һ�����ϡ����μǡ���������������֡���
�����ֽ������������μ��е�����������󽫲����ٸ��ġ�
�벻ҪȡһЩ���Ż�����������������ŵ����֡�

TEXT
        );
        write("�����������֣�");
        ob->set_temp("get_name",0);
        input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{

        arg = CONVERT_D->input(arg,ob);

        if( !check_legal_name(arg) ) {
            ob->add_temp("get_name",1);
            if(ob->query_temp("get_name")>2) {
                // the user can't input proper chinese name.
                // assign one for him/her.    mon 4/19/98

                arg=default_prefix[random(sizeof(default_prefix))]+
                    default_name[random(sizeof(default_name))];

                write("��Ϊ�㲻�������ʵ����������֣�ϵͳָ���������Ϊ��"+
                        arg+"\n");
                write("���ڽ�����Ϸ������ʦ�����޸ġ�\n");

            } else {
                write("�����������֣�");
                input_to("get_name", ob);
                return;
            }
        }

        printf("%O\n", ob);

        ob->set("name", arg);
        write("���趨�������룺");
        input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<5 ) {
                write("��������Ҫ������ַ���ɣ��������������룺");
                input_to("new_password", 1, ob);
                return;
        }
        if(strsrch(pass,ob->query("id")) !=-1) {
                write("[31m:P"HIY"������벻̫��Ү \n[0m");
                input_to("new_password",1,ob);
                return;
        }

        ob->set("password", crypt(pass,0) );
        write("��������һ���������룬��ȷ����û�Ǵ�");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");

        if( crypt(pass, old_pass)!=old_pass ) {
                write("��������������벢��һ�����������趨һ�����룺");
                input_to("new_password", 1, ob);
                return;
        }

        write("���ĵ����ʼ���ַ��");
        input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
        object user;
        string id,addr;
        if (email=="" || strsrch(email,".")==-1 
        || sscanf(email,"%s@%s",id,addr) !=2)
        {        
        write (HIY"��ȷʵ��д����Email��ַ��\n"NOR);
        write ("���ĵ����ʼ���ַ��");
        input_to("get_email",ob);
        return;
        }        
        ob->set("email", email);
       
        // If you want do race stuff, ask player to choose one here, then you can
        // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) ) {
            if(ob) destruct(ob);
            return;

        }

        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
        if( gender=="" ) {
                write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else {
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        confirm_gift("n",ob,user);
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        if(!ob->query("body")) {
          return 0;
        }
        user = new(ob->query("body"));
        if(!user) {
                write("���ڿ������������޸��������ĳ�ʽ���޷����и��ơ�\n");
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

private void confirm_gift(string yn, object ob, object user)
{

        int n;

   if(!ob || !user) {
            if(user) {
         destruct(user);
         return;
       }
            if(ob) destruct(ob);
       return;
        }

        if (yn!="") {
          if (yn[0]=='y' || yn[0]=='Y') {
       CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
       user->set("title", "��ͨ����");

       user->set("birthday", time() );
       user->set("potential", 299);
       user->set("combat_exp",500);
       user->set("food", user->max_food_capacity());
       user->set("water", user->max_water_capacity());
       user->set("channels", ({ "chat","rumor","es","new","sldh" }) );
       log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
     query_ip_number(ob), ctime(time()) ) );

       return enter_world(ob, user);

          } else if (yn[0]=='q' || yn[0]=='Q') {
            destruct(user);
            destruct(ob);
            return;
          }
        }

        user->set("kar",0);
   while(user->query("kar")<10 || user->query("kar")>30){
   user->set("str", 10 + random(21));
   user->set("cps", 10 + random(21));
   user->set("int", 10 + random(21));
   user->set("cor", 10 + random(21));
   user->set("con", 10 + random(21));
   user->set("spi", 10 + random(21));
   user->set("per", 10 + random(21));
        n = user->query("str") + user->query("cps") + user->query("int");
        n = n + user->query("cor") +  user->query("con") +  user->query("spi") +
 user->query("per");
        if(n>168)
           user->set("kar",0);
           else
           user->set("kar",168-n);
        }

        write("\n");
        printf(" ������[%s]  ��ʶ��[%s]  ���ԣ�[%s]  ���ԣ�[%s]\n"
               " ������[%s]  ��ò��[%s]  ���ǣ�[%s]  ��Ե��[%s]\n\n",
               dis_attr(user->query_str()),
               dis_attr(user->query_cor()),
               dis_attr(user->query_int()),
               dis_attr(user->query_spi()),
               dis_attr(user->query_cps()),
               dis_attr(user->query_per()),
               dis_attr(user->query_con()),
               dis_attr(user->query_kar()));
        write("��ͬ�������츳��ֵ��[n|y|q]");
        input_to("confirm_gift",ob,user);
        return;
}

string dis_attr(int value)
{       int gift=20;
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}


varargs void enter_world(object ob, object user, int silent)
{
        object cloth, room, mbx;
        string startroom="";
        int num,bug;
        object login_ob;

        reset_eval_cost();
        user->set_temp("temp_time",time());

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);

        // 5/11/98 mon
        user->set_encoding(ob->query_encoding());

        exec(user, ob);

        write("ĿǰȨ�ޣ�" + wizhood(user) + "\n");
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
//             if(user->query("no_gift")) {
  //             user->move("/d/wiz/init",1);
    //         } else {
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( strlen(startroom = user->query("startroom"))<2 )
                        startroom = START_ROOM;

                if(!wizardp(user) && startroom[0..2]=="/u/") {

                  startroom = START_ROOM;
                  user->set("startroom",startroom);
                }

                if ( wizardp(user) 
&& user->query("startroom") != "/d/wiz/wizroom" ) {
                   startroom="/d/wiz/wizroom";
                   user->set("startroom",startroom);
                }        
        //added by mon 10/27/97

                // the following 7 lines are aded by snowcat dec 10 1997
                if (("/adm/daemons/band"
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

             }

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
        ip_from="/adm/daemons/ipd"->seek_ip_address(query_ip_number(user));
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf(WHT "%s�� " HIG "%s" NOR WHT "���߽���,
IP���ԣ�"HIG"%s"NOR,
user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user), ip_from) );  

//        }
/*����������������������������  bug of pantu ������������������������*/

	if( user->query("soldier_amount") > 1000000 )
	{
	tell_object(user,"����һ����ʿ���ѱ���!!\n");
	user->set("soldier_amount",1000000+random(100));
	}

/*����������������������������  bug of pantu ������������������������*/
/*

       if(!user->query("env/no_status") )
      "/feature/frozen.c"->show_two_screen(user);
        tell_object(user,HIY"Ҫ�ر�״̬��,��help stat \n"NOR);
*/
        login_ob=new(LOGIN_OB);
        login_ob->set("id",user->query("id"));
        login_ob->restore();
        write(HIW"���ϴ������Ǵ�" + HIR +login_ob->query("last_from") + HIW + " on " + HIR +ctime(login_ob->query("last_on"))+ NOR + "\n");
        destruct(login_ob);

       TOPTEN_D->topten_checkplayer(user);

        UPDATE_D->check_user(user, 0);

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
        user->set_temp("temp_time",time());
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
                        sprintf("%s��%s�������߽��롣", user->query("name")+"("
+ capitalize(user->query("id")) + ")", query_ip_name(user)) );
      }
/*
       if(!user->query("env/no_status") )

      "/feature/frozen.c"->show_two_screen(user);
        tell_object(user,HIY"Ҫ�ر�״̬��,��help stat \n"NOR);
*/ 
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
                  write("�Բ����������ֻ���������˵����š�\n");
                  return 0;
       }
        }
        return 1;
}

int check_legal_name(string name)
{
        int i;

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
