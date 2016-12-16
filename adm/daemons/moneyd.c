//Cracked by Roath
// ADM DAEMONS moneyd.c  Ǯ�Ĺ���
// Last Modified by zeus@����Ц Jan.09.2000
#include <ansi.h>

int move_money(int amount);
int write_money_log(object room,int amount);
int get_number();
int get_write_number();
void write_log(object room_o,string number);
int del_log(string x);

string money_str(int amount)
{
// returns a chinese string of `amount` of money
	string output;

	if (amount / 1000000) {
		output = chinese_number(amount / 1000000) + "ö"MAG"��Ӱ���"NOR;
		amount %= 1000000;
	}
	else
		output = "";
	if (amount / 10000) {
		output = output + chinese_number(amount / 10000) + "��"HIY"�ƽ�"NOR;
		amount %= 10000;
	}
	if (amount / 100) {
		output = output + chinese_number(amount / 100) + "��"HIW"����"NOR;
		amount %= 100;
	}
	if (amount)
		return output + chinese_number(amount) + "��"YEL"ͭ��"NOR;
	return output;
}

string price_str(int amount)
{
// returns a chinese string of `amount` of money
	string output;

	if (amount < 1)
		amount = 1;

	if (amount / 1000000) {
		output = chinese_number(amount / 1000000) + "ö��Ӱ���";
		amount %= 1000000;
	} else output = "";
	
	if (amount / 10000) {
		if (output != "")
			output += "��" + chinese_number(amount / 10000) + "���ƽ�";
		else
			output = chinese_number(amount / 10000) + "���ƽ�";

		amount %= 10000;
	}

	if (amount / 100) {
		if (output != "")
			output += "��" + chinese_number(amount / 100) + "������";
		else
			output = chinese_number(amount / 100) + "������";

		amount %= 100;
	}
	
	if (amount)
		if (output != "")
			return output + "��" + chinese_number(amount) + "��ͭ��";
		else
			return chinese_number(amount) + "��ͭ��";
	
	return output;
}

void pay_player(object who, int amount)
{
	int v;
	object ob;
	
	seteuid(getuid());
	if (amount < 1)
		amount = 1;
	if (v = amount / 1000000) {
		ob = new("/obj/money/gold-coin");
		ob->set_amount(amount / 1000000);
		ob->move(who);                
		amount %= 1000000;
	}
	
	if (amount / 10000) {
		ob = new("/obj/money/gold");
		ob->set_amount(amount / 10000);
		ob->move(who);
		amount %= 10000;
	}

	if (amount / 100) {
		ob = new("/obj/money/silver");
		ob->set_amount(amount / 100);
		ob->move(who);
		amount %= 100;
	}
	
	if (amount) {
		ob = new("/obj/money/coin");
		ob->set_amount(amount);
		ob->move(who);
	}
}

int player_pay(object who, int amount)
{
	object jb_ob, g_ob, s_ob, c_ob;
	int jb, gc, sc, cc, left;
	
	seteuid(getuid());
	
	if (jb_ob = present("gold-coin", who))
		jb = jb_ob->query_amount();
	else
		jb = 0;
	if (g_ob = present("gold", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	
	if (cc + sc * 100 + gc * 10000 + jb * 1000000 < amount) 
		if (present("thousand-cash", who))
			return 2;
		else 
			return 0;
	else {
		left = cc + sc * 100 + gc * 10000 + jb * 1000000 - amount;
		jb = left / 1000000;
		left = left % 1000000;
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (jb_ob)
			jb_ob->set_amount(jb);
		else sc += (gc * 100);
		if (g_ob)
		 	g_ob->set_amount(gc);
		else if (gc) {
			g_ob = new("/obj/money/gold");
			g_ob->set_amount(gc);
			g_ob->move(who);
		}
		if (s_ob)
		 	s_ob->set_amount(sc);
		else if (sc) {
			s_ob = new("/obj/money/silver");
			s_ob->set_amount(sc);
			s_ob->move(who);
		}
		if (c_ob)
			c_ob->set_amount(cc);
		else if (cc) {
			c_ob = new("/obj/money/coin");
			c_ob->set_amount(cc);
			c_ob->move(who);
		}

		return 1;
	}
}

int move_money(int amount)
{
	string *path = ({
		"/d/city/",
		"/d/kaifeng/",
		"/d/changan/",
		"/d/death/",
		"/d/eastway/",
		"/d/gao/",
		"/d/jjf/",
		"/d/jz/",
		"/d/lingtai/",
		"/d/meishan/",
		"/d/moon/",
		"/d/nanhai/",
		"/d/pansi/",
		"/d/pantao/",
		"/d/penglai/",
		"/d/sea/",
		"/d/shulin/",
		"/d/shushan/",
		"/d/sky/",
		"/d/westway/",
		"/d/wudang/",
		"/d/wuguan/",
		"/d/wusheng/",
		"/d/xueshan/",
		"/d/zhaoze/",
		"/d/dntg/bmw/",
		"/d/dntg/hgs/",
		"/d/dntg/pantao/",
		"/d/dntg/sky/",
		"/d/dntg/yaochi/",
		"/d/dntg/yunlou/",
		"/d/ourhome/",
		"/d/ourhome/honglou/",
		"/d/ourhome/honglou/dreamland/",
		"/d/qujing/baigudong/",
		"/d/qujing/baihuling/",
		"/d/qujing/baotou/",
		"/d/qujing/baoxiang/",
		"/d/qujing/bibotan/",
		"/d/qujing/biqiu/",
		"/d/qujing/chechi/",
		"/d/qujing/dudi/",
		"/d/qujing/fengxian/",
		"/d/qujing/firemount/",
		"/d/qujing/heifeng/",
		"/d/qujing/huangfeng/",
		"/d/qujing/jilei/",
		"/d/qujing/jindou/",
		"/d/qujing/jingjiling/",
		"/d/qujing/jinping/",
		"/d/qujing/jisaiguo/",
		"/d/qujing/kusong/",
		"/d/qujing/lingshan/",
		"/d/qujing/liusha/",
		"/d/qujing/maoying/",
		"/d/qujing/nverguo/",
		"/d/qujing/pansi/",
		"/d/qujing/pingding/",
		"/d/qujing/qilin/",
		"/d/qujing/qinfa/",
		"/d/qujing/qinglong/",
		"/d/qujing/shuangcha/",
		"/d/qujing/tianzhu/",
		"/d/qujing/tongtian/",
		"/d/qujing/village/",
		"/d/qujing/wudidong/",
		"/d/qujing/wuji/",
		"/d/qujing/wuzhuang/",
		"/d/qujing/xiaoxitian/",
		"/d/qujing/yingjian/",
		"/d/qujing/yinwu/",
		"/d/qujing/yuhua/",
		"/d/qujing/yunzhan/",
		"/d/qujing/zhujie/",
		"/d/qujing/zhuzi/",
	});
	string mvdir,*dir,room_s;
	int f;
	object room_o;
	
	mvdir=path[random(sizeof(path))];
	dir=get_dir(mvdir);
	do{
	room_s=dir[random(sizeof(dir))];	
	}while(room_s[<2..<1]!=".c");
	room_s=mvdir+room_s;	
	room_o=find_object(room_s);	
	if(!room_o) room_o=load_object(room_s);
	if(!room_o) return 0;
	if(!room_o->query("long"))return 0;
	amount>=1000 ?f=amount:f=70+random(200);
	
	write_money_log(room_o,f);
	
	return 1;
}

int write_money_log(object room,int amount)
{
	int i,x;
        if(random(100)<=7) {
                message("chat",HIR"\n����үͻȻ�����˼䣬�ѵ��ϵĻƽ�ȫ�����ˡ���\n\n"NOR,users());
		rm("/log/money");
		return 0;
	}
	if((i=get_number())>=20) return 0;
	if(!(x=get_write_number())) return 0;
	room->set( "dig_money/value",amount);
	room->set( "dig_money/number",x);
	write_log(room,""+x+"");
}

int get_number()
{
	string msg,*line;
	int i,x=0;
	if(!(msg=read_file("/log/money"))) return 0;
	line=explode(msg,"\n");
	for(i=0;i<sizeof(line);i++) {
		if(line[i]=="") continue;
		if(strlen(line[i])>2 || to_int(line[i])>20 || to_int(line[i])<1 ) continue;
		x++;
	}
	return x;
}

int get_write_number()
{
	int i,x,k,*ar=({});
	string msg,*line;
	if(!(msg=read_file("/log/money"))) return 1;
	line=explode(msg,"\n");
	for(x=0;x<sizeof(line);x++) {
		if(line[x]=="") continue;
		if(strlen(line[i])>2 || (k=to_int(line[x]))>20 || k<1 ) continue;
		ar+=({k});
	}
	for(i=1;i<=20;i++)
		if(member_array(i,ar)==-1) return i;
	return 0;
}

void write_log(object room_o,string number)
{
	string r_long;
	int j,k;
	r_long=room_o->query("long");	
	j=strlen(r_long);
	write_file("/log/money",number+"\n");
	write_file("/log/money",r_long);
	//���������������һЩ��������ʹ�ҵĹ��������Щ��
	for(int x=0;x<j;x+=2) {
		if(r_long[x]<=160 || r_long[x]>=255 ) {
			x--;
			continue;
		}
                if(random(10)<4) {
			k=x+1;
			r_long=replace_string(r_long,r_long[x..k],"��");
		}
	}
	message("chat",CYN"\n�콵�����б�������ˣ��ƺ��ڣ�\n"NOR,users());
	message("chat",r_long,users());
}

int del_log(string x)
{
	string news="",olds,*line;
	int i,Bool=0,k;

	if( !( olds=read_file("/log/money") ) ) return 0;
	line=explode(olds,"\n");
	news="";
	for(i=0;i<sizeof(line);i++) {
		if(x==line[i]) Bool=1;
		if( Bool==1
		 && strlen(line[i])<=2
		 && line[i]!=x
		 && ( k=to_int(line[i]) )<=20
		 && k>=1 ) Bool=0;
		if(Bool==1) continue;
		news+=(line[i]+"\n");
	}
	rm("/log/money");
	write_file("/log/money",news);
	return 1;
}

string show_msg()
{
	string olds,news="",*line;
	int i,k,x,Bool=0,f=0,y;
	if( !(x=get_number())) return 0;
	k=random(x)+1;
	
	olds=read_file("/log/money");
	line=explode(olds,"\n");

	for(i=0;i<sizeof(line);i++) {
		if( strlen(line[i])<=2
		&& (y=to_int(line[i]))<=20
		&& y>=1 ) f++;
		if(f==k && Bool==0) Bool=1;
		if(f>k && Bool==1) Bool=0;
		if(Bool==0) continue;
		if( strlen(line[i])<=2
		&& y<=20
		&& y>=1 ) continue;
		news+=(line[i]+"\n");
	}
	return news;
}
