#include <ansi.h>
inherit F_VENDOR_SALE;

int random_go(object me, string* dirs);
void clear_room();
int do_gongzuo();

void create()
{
	reload("xiaoer");
	set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","er"}));
	set("shop_id",({"waiter","xiaoer","xiao","er"}));
	set("shop_title","��С��");
	set("gender", "����");
	set("combat_exp", 1000);
	set("age", 26);
	set("per", 14);
	set("attitude", "friendly");
	set("shen_type", 1);
	set_skill("unarmed", 10);
	set("max_price",20);
	set("vendor_goods", ([
		"jiudai": "/d/moon/obj/jiudai",
		"gourou": "/d/ourhome/obj/gourou",
		"jinpai" : "/d/obj/misc/tiaozhanpai",
		"jitui": "/d/ourhome/obj/jitui",
		"huasheng": "/d/ourhome/obj/huasheng",
		"zhinan": "/d/obj/misc/xiaqi-zhinan",
		"shuijing" : "/d/obj/quest/shuijingqiu",
	]) );

	if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
	set("inquiry", ([
		"����" : (: do_gongzuo :),
		"work" : (: do_gongzuo :),
	]) );

	setup();

	carry_object("/d/obj/cloth/linen")->wear();
	add_money("silver", 1);
	remove_call_out("clear_room");
	call_out("clear_room",300);
}

void init()
{
	object ob, me;
	me=this_object();
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	 
	add_action("do_vendor_list", "list");
/*	if( !me->query_temp("called") ){
		call_out("clear_room", 300);
		me->set_temp("called", 1);
	}
*/
}
int do_gongzuo()
{      
	 object me;
	 me = this_player(); 
	 
    if (me->query("combat_exp")>5000 || me->query("daoxing")>5000)
    {
		  tell_object(me,"���С����ô�������Ĵ�ݡ�\n");
		  return 1;
    }  
    if( me->query_temp("gongzuo/xipanzi")>0)
    {
		  tell_object(me,"��ȥϴ���Ӱɡ�\n");
		  return 1;
    }  
    message_vision(CYN"С����$N˵�����⼸����˶࣡����ϴ����������ȥ�����ҹ���Ҫ��������ϴ�ɡ�\n"NOR,me); 
	 me->set_temp("gongzuo/xipanzi", 1);
	 return 1;   
}
int accept_object(object me, object ob)
{
	int value;
	object ob1;

	if (ob->query("money_id") && (value=ob->value()) >= 300) 
	{
		tell_object(me, name()+ "һ������˵������л���ϣ��͹����Ϸ�ЪϢ��\n");
		me->set_temp("rent_paid",1);
		take_money(value, 300);
		return 1;
	}

	if (me->query_temp("gongzuo/xipanzi")<1)
	{
		command("say ��û������Ҫ�������ɡ�\n");
	}
	else if ( ob->query("name") != "����" )
	{
		command("say ����ϴ�õ����ӣ��㲻�ǿ���Ц�ɣ�\n");
	} else {
		message_vision(CYN"С����$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me);
//		message_vision(CYN"С���ݸ�$NһЩ���ӡ�\n"NOR,me);  
		me->delete_temp("gongzuo/xipanzi");
		me->delete_temp("gongzuo/gepanzi");
		if (me->query("combat_exp")>=5000)
		{
			me->add("combat_exp",2);
			me->add("potential",1);
			carry_object("/obj/money/silver");
			command("give silver to "+me->query("id"));
			call_out("destroying", 1, this_object(), ob);
		} else if (me->query("combat_exp")< 5000) {
			me->add("combat_exp",30+random(10));
			me->add("daoxing",30+random(10));
			me->add("potential",10+random(10));
			carry_object("/obj/money/silver");
			carry_object("/obj/money/silver");
			carry_object("/obj/money/silver");
			command("give 3 silver to "+me->query("id"));
			call_out("destroying", 1, this_object(), ob);
		}
		return 1;
	}
    return 0;
}

void destroying(object me, object obj)
{
	 destruct(obj);
	 return;
}
/*int clear_room()
{
	object me, ob, rider;
	object *list;
	string* dirs;
	int i, announced=0;

	me=this_object();

	if(!me || !environment(me)) return 1;

	list=all_inventory(environment(me));
	i=sizeof(list);
	me->delete_temp("called");

	dirs = ({"/d/city/"});
	 
	while (i--)
	{
		ob=list[i];
		if( ob->query("ride/dodge")) {
			if( ob->query_temp("rider") ) {
				rider=ob->query_temp("rider");
				rider->set_temp("ridee", 0);
				rider->add_temp("apply/dodge", -rider->query_temp("ride/dodge"));
				rider->set_temp("ride/dodge", 0);
				ob->set_temp("no_return", 0);
				ob->set_temp("rider", 0);
			}
			random_go(ob, dirs);
			if(!announced) {
				message_vision("$N˵����С����ɨ����λ�͹�ԭ�������\n", me);
				announced=1;
			}
			message_vision("$N������ɨ���$n���˳�ȥ��\n", me, ob);
		}
	}
	return 1;
}
*/
int random_go(object me, string* dirs)
{
	int	i, j, k;
	object  newob;
	mixed*  file;

	if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

	file = get_dir( dirs[i]+"*.c", -1 );
	if( !sizeof(file) )	      return 1;

	k = sizeof(file);
	while(1)  {
		j = random(k);
		if( file[j][1] > 0 )
			break;
	}

    if( (newob=find_object(dirs[i]+file[j][0])) )   {
		me->move( newob ); 
	}
	else  {
		seteuid(getuid(me));
		newob = load_object(dirs[i]+file[j][0]);
		if (newob)   // now this is not necessary, only for debug use
			me->move(newob);
		else  {
			tell_object(me, "Error.\n");
		}
	}

	return 1;
}

void greeting(object ob)
{
	if( !ob || !visible(ob) || environment(ob) != environment() ) return;
	if (!ob->query_temp("welcome100") && ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
		tell_object(ob,YEL"��С��Ц�����˵������λ"+RANK_D->query_respect(ob)+"����ӭ����"MAG"��Ӱ��Ե��"NOR YEL"
    �������ʲô�����׵ģ�����������ҡ�ȱǮ����Ҳ�����������
�����ݶ��ѹء�"HIY"����"NOR YEL"�Ƕ����������˵ġ���Ȼ��Ҳ������"HIC"help"NOR YEL"�������
�Ǹ����İ�����
    ����"HIC"help"NOR YEL"���ܿ����ܶ������Ŀ��
    ������������Ϸ����ƺ͹�����ʲô�����������뵽��¥����
�ġ�"MAG"��Ӱ��Ե"HIC"��չ���۰�"NOR YEL"�����ԣ����ǻ�һ�������濼�ǵġ�\n\n"NOR);
	}
	switch( random(3) ) {  // 1/3 chance to greet.
		case 0:
			say( name()+"Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "������ЪЪ�ţ������Ѱɡ�\n");
			break;
		case 1:
			say( name()+"�ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

void clear_room()
{
	string *place1 = 
		({"/d/city/zhuque-s1","/d/city/center","/d/city/xuanwu-n1",
		"/d/city/baihu-w1","/d/city/qinglong-e1","/d/jz/sgate"});

	string room;
	int race, obj,i;
	object *inv, who;
	race = 0;
	obj = 0;
	if(environment(this_object())){
		inv = all_inventory(environment(this_object()));
		say(name()+"��Ǹ��˵������С����ɨ����λ�͹�ԭ���������\n");
        if ( sizeof(inv) <= 0 ) return ;
		for (i = 0;i <sizeof(inv);i++)
		{
			if(inv[i]->query("race")=="Ұ��")
			{
				room = place1[random(5)];
				say(inv[i]->query("name")+"��"+name()+"��ɨ����˳�ȥ��\n");
				inv[i]->set_temp("no_return",0);
				inv[i]->set_temp("rider",0);
				inv[i]->move(room);
				if(who = inv[i]->query_temp("rider"))
				{
					who->set_temp("ridee",0);
					who->add_temp("apply/dodge",-inv[i]->query_temp("ride/dodge"));
					who->set_temp("ride/dodge",0);
				}
				tell_room(environment(inv[i]), inv[i]->query("name")+"��"+name()+"�ӿ�ջ���˳�����\n");
				race++;
			}
			else if(!inv[i]->is_character()&&!inv[i]->query("board_id")) {obj++; destruct(inv[i]);}
		}
		if(race+obj==0) say(name()+"���������ɨ�˰��죬����ûʲô���Դ�ɨ�ģ�����������˹�̨��\n");
		else message("channel:es",HIM+"�����ġ���С��(Xiao er)����������"+chinese_number(race)+
		"ֻ����������"+chinese_number(obj)+"����\n"NOR,users());
	}
	remove_call_out("clear_room");
	call_out("clear_room",300);
}
