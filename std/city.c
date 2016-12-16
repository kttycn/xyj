#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void fight_city(object, object, object, int);

mapping cityname = ([
  "����ɽ" : "yinfeng",
  "佻���" : "huanhua",
  "���˹�" : "erengu",
]);

void reload(string savename)
{
	SAVE_NAME=savename;
	if(!restore())     
	log_file("city_save",sprintf("Failed to restore(%s)     %d.\n",savename,time()));
}   

string query_save_file()
{
	string id;
    id = SAVE_NAME;
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "city/%s",id);
}
void init()
{
	add_action("do_tax", "tax");
	add_action("do_attack", "attack");
	add_action("do_defend", "defend");
	add_action("do_status", "status");
	add_action("do_kaifa", "kaifa");
	add_action("do_kaiba", "kaiba");
	add_action("do_caoyan", "caoyan");
	add_action("do_fangqi", "tuibing");
	add_action("do_zhuza","zhuza");
	add_action("do_combat","zhenyuan");
	add_action("do_true","true");
	set("no_clean_up", 1);
}

int do_tax(string arg)
{
	object me=this_player();
//	int money, faith, farm, trade, people, tax;
	int pts, money, faith, farm, trade, people, tax;
	faith = this_object()->query("faith");
	farm = this_object()->query("farm");
	trade = this_object()->query("trade");
	people = this_object()->query("people");
	tax = this_object()->query("tax");
	if(me->query("id")!=this_object()->query("owner")) return notify_fail("�㲻�ǳ��������ܹ�����˰�ʡ�\n");
	if(this_object()->query("taxing")> (int)time()) return notify_fail("����˰���ã���һ��������˵�ɣ������������ˡ�\n");
	if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("�����˰�ʣ�tax <˰��> (0~100������)\n");
	if(pts<0 || pts >100) return notify_fail("�����˰�ʣ�tax <˰��> (0~100������)\n");
	if((query("tax")!=0)&& pts==0) 
	{
		tell_object(me,"��ȡ����"+this_object()->query("short")+"��˰�գ����ն���м���֡��ҳ϶�������.\n"); 
		if(this_object()->query("faith")>=80)
			this_object()->set("faith",100);
		else
			this_object()->add("faith",20);
		message("vision",HIY+"����Ӱ���š�:"+me->query("name")+
			"ȡ����"+this_object()->query("short")+"��˰�ա�\n"+NOR,users());
		return 1;
	}
	tell_object(me,"�㽫"+this_object()->query("short")+"��˰����Ϊ"+pts+"%.\n");
	if( this_object()->query("tax")> pts && pts <= 30) 
	{
		if(this_object()->query("train_level")>100 
		&& this_object()->query("faith")<=100 
		&& this_object()->query("farm")>100 
		&& this_object()->query("trade")>100 
		&& this_object()->query("defendance")>80)
		{
			tell_object(me,"���ն��㽵��˰�ʵ��������Ǹм����ҳ϶�������.\n");
			this_object()->add("faith",(this_object()->query("tax")-pts)/10+random(5));
			this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
		}
	}
	if( this_object()->query("tax")<= pts && pts < 30)
	{
		tell_object(me,"���ն�������˰�ʵ��������Ǳ�ʾ��⣬����ƽ����\n");
		this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
	}
	if(pts >= 30)
	{
		tell_object(me,"���ն����˰���������ǻ��ɡ��ҳ϶��½���.\n");
 		this_object()->add("faith",-(this_object()->query("tax")-pts)/10);
		this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
	}else if(pts >= 90)
	{
		tell_object(me,"���ն����˰���������Ƿ�ŭ���ҳ϶��½���.\n");
 		this_object()->add("faith",-(this_object()->query("tax")-pts)*9/10);
		this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/5000);
	}
	if(this_object()->query("faith")>100) this_object()->set("faith",100);
//	money=(people/10000)*(farm+trade)*(faith/10)*tax/5;
	money=((this_object()->query("people")+this_object()->query("soilder")/10)*(this_object()->query("farm")+
		this_object()->query("trade"))*(this_object()->query("faith")/100))*this_object()->query("tax")/1000;
	this_object()->set("tax",pts);
	me->add("balance",money);
	this_object()->set("taxing",time()+36000); //ÿ��ʮ��Сʱ���ܸı�˰�ʡ�
	save();
	return 1;
}

int do_attack()
{
	object who,city=this_object();
	object me=this_player();
	int ap,one,two;

	if(me->query("combat_exp")<20000)
		return notify_fail("�����书��ô�����������˵ĳǱ������뵹����\n");
	if(me->query("id")==this_object()->query("owner"))
		return notify_fail("���������Լ��ļ�԰�ģ�\n");
	if(!this_object()->query("owner"))
	{
		tell_object(me,"����һ���ճǣ����ʿ������һ��һ������ҡ��ڵ����˳ǡ�\n");
		message("vision",HIY+"����Ӱ���š�:"+me->query("name")+"��ռ��"+
		this_object()->query("short")+"\n"+NOR,users());
		me->add("city/number",1);
		me->set("city/"+cityname[this_object()->query("short")], "done");
		this_object()->set("owner",me->query("id"));
		this_object()->set("ownername",me->query("name"));
		save();
		return 1;
	} //������ռ��ĳ���
	one = me->query("soilder")*me->query("train_level");
	two = this_object()->query("soilder")*(this_object()->query("train_level")+
		this_object()->query("defendance")*2);
	if(3*one < two)
		return notify_fail("������ô�������������˵ĳǱ���������\n"+chinese_number(one)+
		"\n"+chinese_number(two)+"\n");
	who=find_player(this_object()->query("owner"));
	if(!who) return notify_fail("���е����˲����ߣ��㲻�ܹ������ĳ��С�\n");
	ap=me->query("soilder")*me->query("train_level");
	if(ap<=0) return notify_fail("�㲻����������̡�����Ϊ����˭ѽ��\n");
		tell_object(who,me->query("name")+"Ҫ�������"+this_object()->query("short")+"�ˡ���Ͻ��ɱ�֧Ԯ��\n");
	if (!me->query("attacking"))
	{
		message("vision",HIY+"����Ӱ���š�"+me->query("name")+"��"+
		this_object()->query("short")+"��ٽ�����\n"+NOR,users());
		me->set("attacking",1);
		this_object()->set("attacker",me->query("id"));
		this_object()->set("receive_attack",1);
		me->fight_ob(city);
	}
	fight_city(me,city,who,1);
	return 1;
}

int do_zhuza(string arg)
{
	int pts, level, pts1, pts2, level1, level2;
	object me=this_player();
	if(me->query("id") != this_object()->query("owner"))
		return notify_fail("ֻ�г�������פ�������������\n");
	if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("ָ���ʽ��zhuza <����> (����)\n");
	if(pts <=0) return notify_fail("�ߺߣ��˻��и���ô��\n");
	if(pts > me->query("soilder")) 
		return notify_fail("��û����ô��ʿ�������䡣\n");
	pts1 = this_object()->query("soilder");
	pts2 = me->query("soilder");
	level1 = this_object()->query("train_level");
	level2 = me->query("train_level");
	level = ceil((level1*pts1+level2*pts)/(pts+pts1));
	tell_object(me,"�㽫����ʿ��������һ��פ���ڳǱ��\n");
	this_object()->add("soilder",pts);
	this_object()->set("train_level",level);
	this_object()->add("people",pts*20);
	me->add("soilder",-pts);
	me->add("city/"+cityname[this_object()->query("short")]+"sold", pts);
	message("vision",HIY+"����Ӱ���š�:"+me->query("name")+"��פ��"+chinese_number(pts)+
	"��ʿ������"+this_object()->query("short")+".\n"NOR,users());
	save();
	return 1;
}

int do_kaiba(string arg)
{
	int pts, level, pts1, pts2, level1, level2;
	object me, city;
	me=this_player();
	city=this_object();
	if(me->query("id") != city->query("owner"))
		return notify_fail("ֻ�г������ܵ���פ��������ľ��ӡ�\n");
	if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("ָ���ʽ��kaiba <����> (����)\n");
	if(pts <=0) return notify_fail("�ߺߣ��˻��и���ô��\n");
	if(pts > city->query("soilder")) 
		return notify_fail("��ĳǱ���û����ô��ʿ����������á�\n");
	pts1 = city->query("soilder");
	pts2 = me->query("soilder");
	level1 = city->query("train_level");
	level2 = me->query("train_level");
	level = ceil((level2*pts2+level1*pts)/(pts+pts2));
	tell_object(me,"�㽫�Ǳ��е�ʿ���������Լ�ͳ�졣\n");
	city->add("soilder",-pts);
	city->add("people",-pts*20);
	me->add("soilder",pts);
	if(city->query("soilder")==0)
		city->set("train_level",0);
	me->set("train_level",level);
	me->add("city/"+cityname[city->query("short")]+"sold", -pts);
	message("vision",HIY+"����Ӱ���š�:"+me->query("name")+"��פ����"+city->query("short")+
	"��"+chinese_number(pts)+"��ʿ�������Լ�ͳ�졣\n"NOR,users());
	save();
	return 1;
}

int do_combat(string arg)
{
	object me=this_player(),who;
	int pts,train1;
	if( !arg || !sscanf(arg, "%d to %s", pts)) return notify_fail("ָ���ʽ��zhenyuan <����> (����)\n");
	if(pts > me->query("soilder"))
		return notify_fail("��û����ô��ʿ������ָ�ɡ�\n");
	train1=pts*me->query("train_level")+this_object()->query("soilder")*this_object()->query("train_level");
	train1=train1/(pts+this_object()->query("soilder"));
	tell_object(me,"������"+chinese_number(pts)+"��ʿ����Ԯ"+this_object()->query("short")+".\n");
	who=find_player(this_object()->query("owner"));
	if(who)
		if(me != who)
			tell_object(who,me->query("name")+"����"+chinese_number(pts)+"��ʿ����Ԯ"+this_object()->query("short")+".\n");
	message("vision",HIY+"����Ӱ���š�:"+me->query("name")+"����"+chinese_number(pts)+
	"��ʿ��������Ԯ"+this_object()->query("short")+".\n"NOR,users());
	this_object()->add("soilder",pts);
	this_object()->set("train_level",train1);
	me->add("soilder",-pts);
	save();
	return 1;
}

int do_kaifa(string arg)
{
	object me=this_player();
	if(me->query("id") != this_object()->query("owner"))
		return notify_fail("ֻ�г������ܿ�����\n");
	if(!arg)
	{
		printf("ũҵ������(farm):"+this_object()->query("farm")+"    ��ҵ������(trade):"+this_object()->query("trade")+
		"\n���з�����(defendance):"+this_object()->query("defendance")+"\n");
		return 1;
	}
	if((arg != "farm")&&(arg != "trade")&&(arg != "defendance"))
		return notify_fail("Ŀǰֻ�����ֿ�����Ŀ��ũҵ(farm),��ҵ(trade),����(defendance).\n");
	if(me->query("balance") < (this_object()->query(arg)+1)*10000)
		return notify_fail("����ʽ��㣬�����ȶ�׬��Ǯ�ɡ�\n");
	if(arg=="farm")
	{
		tell_object(me,this_object()->query("short")+"��ũҵ�����������ˡ�\n");
		if(random(3) && this_object()->query("farm")>100 )
			if(this_object()->query("faith") <=100)
			{
				tell_object(me,this_object()->query("short")+"������ҳ϶������ˡ�\n");
				if(this_object()->query("faith")>100)
					this_object()->set("faith",100);
				else
					this_object()->add("faith",1);
			}
		this_object()->add("farm",1);
		this_object()->add("people",1000+random(500));
	}else
		if(arg=="trade")
		{
			tell_object(me,this_object()->query("short")+"����ҵ�����������ˡ�\n");
			if(random(4) && this_object()->query("trade")>100 )
				if(this_object()->query("faith") <=100)
				{ 
					tell_object(me,this_object()->query("short")+"������ҳ϶������ˡ�\n");
					if(this_object()->query("faith")>100)
						this_object()->set("faith",100);
					else
						this_object()->add("faith",1);
				}
			this_object()->add("trade",1);
			this_object()->add("people",2000+random(500));
		}else
		{
			tell_object(me,this_object()->query("short")+"�ĳ��з����������ˡ�\n");
			this_object()->add("defendance",1);
		}
	me->add("balance",-10000*this_object()->query(arg));
	save();
	return 1;
}

int do_caoyan(string arg)
{
	object me=this_player();
	if(me->query("id") != this_object()->query("owner"))
		return notify_fail("ֻ�г�������ѵ�����ӡ�\n");
	if( !this_object()->query("soilder") )
		return notify_fail("�������в�û�о���פ�أ�\n");
	
	if( this_object()->query("train_level") >= 200 )
		return notify_fail("�������о��ӵ�ѵ�����Ѿ�����������ˣ�\n");

	if(me->query("balance") < (this_object()->query("soilder")+1)*1000)
		return notify_fail("����ʽ��㣬�����ȶ�׬��Ǯ�ɡ�\n");
	tell_object(me,this_object()->query("short")+"�ľ��ӵ�ѵ���������ˡ�\n");
	if(this_object()->query("train_level")>100 
	&& this_object()->query("faith")<=100
	&& this_object()->query("farm")>100 
	&& this_object()->query("trade")>100 
	&& this_object()->query("defendance")>80)
		if(random(2))
		{
			tell_object(me,"����פ����ǿ��"+this_object()->query("short")+"������ҳ϶������ˡ�\n");
			if(this_object()->query("faith")>100)
				this_object()->set("faith",100);
			else
				this_object()->add("faith",1);
		}
	this_object()->add("train_level",1);
	this_object()->add("people",400+random(100));
	me->add("balance",-(this_object()->query("soilder")*1000));
	save();
	return 1;
}

int do_status(string arg)
{
	object me=this_player();
	object ob;
	string one, one2, cmoney;
	int money, faith, farm, trade, people, tax;
	faith = this_object()->query("faith");
	farm = this_object()->query("farm");
	trade = this_object()->query("trade");
	people = this_object()->query("people");
	tax = this_object()->query("tax");
	one2 = "����������������������������������������������������\n";
	if(faith<10) one=HIY"    ���ﲻ֪Ϊ������������һ�ֻֿŵ����գ�ҥ���Ĳ���\n����˼�䡣\n"NOR;
	else if(faith<30) one=WHT"    ����һƬ���ţ�Ȼ���ǲ����ǰ��꣬Ҳ���������Ƕ���\n˭�������Ѿ���ľ��\n"NOR;
	else if(faith<50) one=HIC"    �����Ƕ��ڳ�������˵û���ڴ����������û��������\n���������ڴ��ܿ�ͻ���ʧ�ġ�\n"NOR;
	else if(faith<70) one=HIM"    �����Ƕ��ڳ���������ģ��������������ʵ������ǻ�\n��ס��������\n"NOR;
	else one=HIG"    �������ж��ǳ����Ŀ���׷���ߣ�����Ϊ������Ĥ�ݣ�\n�治֪����ʹ����ʲô�ֶΣ�����������ڶ�����ġ�\n"NOR;
	one += one2;
	if(farm<30) one +=HIY"    �������۶��ǻ��ߵ�Ұ�أ�����Ӱ����ÿһ���ˡ�\n"NOR;
	else if(farm<80) one +=WHT"    ����ũ�����������������أ�������ճɣ���������\n�϶�Ƥ�أ�\n"NOR;
	else if(farm<140) one +=HIC"    һƬƬ��ũ��ɢ���ڻ�Ұ�ϣ����ܿ���������������\n�⣬���������Ѿ����ö����ˡ�\n"NOR;
	else if(farm<180) one +=HIM"    ��������ũҵ�ƺ������ӣ����޷�ʵ�����Է��á�\n"NOR;
	else one +=HIG"    ��İ��֯�������ݺᣬ����Ʈ�㣬�������ˣ���һ��\n��԰��⣬���Ƿ�����ʳ��������ҵ��\n"NOR;
	one += one2;
	if(trade<30) one +=HIY"    �������Ҿſգ�����ƶ��Ӱ����ÿһ���ˡ�\n"NOR;
	else if(trade<80) one +=WHT"     ƽ���Ľ��ϣ�ż���ɼ���С��������������������\n����ȴ�����޼���\n"NOR;
	else if(trade<140) one +=HIC"    ���̽����ض������������ϵĽ���������˷�������\n���֡��ϰ�������Ҳ�м���СǮ����\n"NOR;
	else if(trade<180) one +=HIM"    ����������ҵ�����ӣ�ʹ�óǱ�������ʼ���ķḻ\n�������������������õ����̿��ŵı������Ͷ�ͯ����Ц\n����\n"NOR;
	else one +=HIG"    ��¥���ã��ֵ��ݺᣬ�����������˺��糱����һ��\n����֮�硣\n"NOR;

	printf(NOR HIR"��"+HIY+this_object()->query("short")+HIR"��"+NOR"������"HIY"������"+HIW+this_object()->query("ownername")+"("+
	this_object()->query("owner")+")\n"NOR+one2+one+one2);
	printf(NOR WHT"  �� �Ǳ��˿� ����%8d"NOR WHT"  �� �Ǳ�˰�� ����  %3d\n"NOR,people,tax);
	printf(NOR WHT"  ��ũҵ�����ȡ���   %5d"NOR WHT"  ����ҵ�����ȡ���%5d\n"NOR,farm, trade);
	printf(NOR WHT"  ���Ǳ������ȡ���   %5d "NOR,this_object()->query("defendance"));
	if(me->query("id") != this_object()->query("owner") && !wizardp(me))
		printf(NOR "\n");
	else
	{
//		money=(people/10000)*(farm+trade)*(faith/10)*tax/5;
		money=((this_object()->query("people")+this_object()->query("soilder")/10)*(this_object()->query("farm")+
			this_object()->query("trade"))*(this_object()->query("faith")/100))*this_object()->query("tax")/1000;

		printf(NOR WHT" ���Ǳ��ҳ϶ȡ���  %3d\n"NOR, faith);
		printf(NOR WHT"  �� פ������ ����%8d  ��פ��ѵ���ȡ���  %3d           \n"NOR,this_object()->query("soilder"), this_object()->query("train_level"));

		if (money > 0)
		{
	        if (money / 10000) {
				cmoney = HIY+chinese_number(money / 10000) + "���ƽ�"+NOR;
				money %= 10000;
    	    }
	        else cmoney = "";
	        if (money / 100) {
				cmoney = cmoney + HIW + chinese_number(money / 100) + "������"+NOR;
				money %= 100;
			}
			else cmoney = "";
			if ( money )
				cmoney = cmoney + YEL+chinese_number(money) + "��ͭ��"+NOR;
		}
		else cmoney=CYN"��������Ǳ�û������"NOR;

		printf(NOR WHT"  �� ˰������ ����%s\n"NOR, cmoney);
	}
	printf(one2);
	return 1;
}

int do_fangqi(string arg)
{
	object me=this_player();
	object who;

	if(me->query("id") == this_object()->query("owner"))
	{
		tell_object(me,"�����Ҫ���������ǳ���(true)\n");
		me->set("ready_fangqi",1);
		return 1;
	}

	who = find_player(this_object()->query("owner"));
	if( !me->query("attacking") )
		return notify_fail("�����ڲ�û�й���ѽ��\n");
	me->remove_enemy(this_object());
	me->delete("attacking");
	this_object()->delete("receive_attack");
	this_object()->delete("attacker");
	tell_object(me,"�����ͷ���ԣ�һ�����£������ձ���\n");
	tell_object(who,"�㱣���˳��У��õ���10000����ѧ���齱����\n");
	who->add("combat_exp",10000);
	who->set("city/"+cityname[this_object()->query("short")]+"sold", this_object()->query("soilder"));
	tell_object(me,"���������ʧ�ܣ�������ʿ���������⣬����ʧ����10000����ѧ���顣\n");
	me->add("combat_exp",-20000);

	message("vision",HIY+"����Ӱ���š�:"+me->query("name")+"ȡ���˶�"+this_object()->query("short")+
		"�Ľ������Զ��˱���.\n"NOR,users());
	save();
	return 1;
}

int do_true(string arg)
{
	int soilder,train;
	object me=this_player();

	if(!me->query("ready_fangqi"))
		return notify_fail("ʲô��\n");

	tell_object("���Զ������˶�"+this_object()->query("short")+"��ͳ�Ρ�\n");
	train=this_object()->query("train_level");
	soilder=this_object()->query("soilder");
	if(soilder)
		tell_object(me,"�㽫�����"+chinese_number(soilder)+"��ʿ�����¹������¡�\n");
	this_object()->set("soilder",0);
	train=soilder*this_object()->query("train_level")+me->query("soilder")*me->query("train_level");
	train=train/(soilder+me->query("soilder"));
	me->add("soilder",soilder);
	me->add("city/number",-1);
	me->delete("city/"+cityname[this_object()->query("short")]);
	me->delete("city/"+cityname[this_object()->query("short")]+"sold");
	me->set("train_level",train);
	this_object()->delete("attacker");
	this_object()->delete("receive_attack");
	this_object()->set("train_level",0);
	this_object()->delete("owner");
	this_object()->delete("ownername");
	this_object()->set("faith",0);
	message("vision",HIY+"����Ӱ���š�:"+me->query("name")+"�Զ������˶�"+this_object()->query("short")+
		"��ͳ�Σ������˸ó�.\n"NOR,users());
	save();
	return 1;
}

int do_defend(string arg)
{
	object me=this_player();
	object who;
	int one,two,three;
	if(me->query("id")!= this_object()->query("owner"))
		return notify_fail("�㲻�ǳ�����\n");

	if(!this_object()->query("receive_attack"))
		return notify_fail("��û���⵽����ѽ��\n");
	if(!arg)
	{
		printf("Ŀǰ���õķ�����ʩ��:��ľ��ʯ(stone),����(arrow),����(fire)\n");
		return 1;
	}
	if(me->is_busy()) return notify_fail("��һʱ��æ���ң���Ȼ��֪�����ָ�Ӳźá�\n");

	who=find_player(this_object()->query("attacker"));
	if(!who) return 1;

	one=this_object()->query("defendance")+this_object()->query("faith")+this_object()->query("train_level");
	one=one*this_object()->query("soilder");
	if(one< 0) one=0;
	two=who->query("soilder")*who->query("train_level");
	three=who->query("soilder")-this_object()->query("soilder");
	if(three <0) three= -1*three;
	if(arg=="stone")
		if(random(one)> random(two))
		{
			message_vision(HIC"$N��ʿ��ߺ���Ž�������ʯ�ӳ�ǽ����������$nһʱ������ʿ�����˲��١�\n"NOR,me,who);
			message("vision",who->query("name")+"��ʧʿ��"+chinese_number(random(three/10))+"����\n", ({ me,who})); 
			me->start_busy(random(5)+1);
			return 1;
		}

	if(arg=="arrow")
		if(random(one)>3*random(two))
		{
			message_vision(HIC"$N�е����ż�������һ�������죬�Ӽ�������������ʿ��������ɻȣ�$n��ʿ��������һƬ��\n"NOR,me, who);
			message("vision",HIC+who->query("name")+"��ʧʿ��"+chinese_number(random(three/10))+"����\n"NOR, ({ me, who })); 
			me->start_busy(random(10)+2);
			return 1;
		}

	if(arg=="fire")
		if(random(one)>5*random(two))
		{
			message_vision(HIC"$N��У��Ż𡢷Ż𡣳�����������ȼ�ŵĻ�ѣ��ҽ����У�$n��ʿ���������ڡ�\n"NOR,me,who);
			message("vision",HIC+who->query("name")+"��ʧʿ��"+chinese_number(random(three/10))+"����\n"NOR, ({ me,who })); 
			me->start_busy(random(15)+3);
			return 1;
		}
	message("vision",HIC+who->query("name")+"ȴ���з�����û���ܵ���ʧ��\n"NOR, ({ me, who})); 
	me->start_busy(random(5)+1);
	return 1;
}

void fight_city(object me, object city, object who, int number)
{
	if( city->query("owner")!=me->query("id") && query("attacker") == me->query("id") ) {
		tell_object(me,HIR"�㿪ʼ��"+city->query("short")+"�����˵�"+chinese_number(number)+"�ν�����\n"NOR);
		tell_object(who,HIR+me->query("name")+"��ʼ��"+city->query("short")+"�����˵�"+chinese_number(number)+"�ν�����\n"NOR);
		COMBAT_D->do1_attack(me, city, who);
		remove_call_out("fight_city");
		number += 1;
		call_out("fight_city", 2, me, city, who, number );
	}
	return;
}
