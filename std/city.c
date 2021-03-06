#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;
void fight_city(object, object, object, int);

mapping cityname = ([
  "阴风山" : "yinfeng",
  "浣花堡" : "huanhua",
  "恶人谷" : "erengu",
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
	if(me->query("id")!=this_object()->query("owner")) return notify_fail("你不是城主，不能够调整税率。\n");
	if(this_object()->query("taxing")> (int)time()) return notify_fail("才征税不久，等一段日子再说吧，否则民不聊生了。\n");
	if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("请调整税率：tax <税率> (0~100的整数)\n");
	if(pts<0 || pts >100) return notify_fail("请调整税率：tax <税率> (0~100的整数)\n");
	if((query("tax")!=0)&& pts==0) 
	{
		tell_object(me,"你取消了"+this_object()->query("short")+"的税收，百姓对你感激万分。忠诚度上升了.\n"); 
		if(this_object()->query("faith")>=80)
			this_object()->set("faith",100);
		else
			this_object()->add("faith",20);
		message("vision",HIY+"【月影传闻】:"+me->query("name")+
			"取消了"+this_object()->query("short")+"的税收。\n"+NOR,users());
		return 1;
	}
	tell_object(me,"你将"+this_object()->query("short")+"的税率设为"+pts+"%.\n");
	if( this_object()->query("tax")> pts && pts <= 30) 
	{
		if(this_object()->query("train_level")>100 
		&& this_object()->query("faith")<=100 
		&& this_object()->query("farm")>100 
		&& this_object()->query("trade")>100 
		&& this_object()->query("defendance")>80)
		{
			tell_object(me,"百姓对你降低税率的做法很是感激，忠诚度上升了.\n");
			this_object()->add("faith",(this_object()->query("tax")-pts)/10+random(5));
			this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
		}
	}
	if( this_object()->query("tax")<= pts && pts < 30)
	{
		tell_object(me,"百姓对你增加税率的做法很是表示理解，表现平静。\n");
		this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
	}
	if(pts >= 30)
	{
		tell_object(me,"百姓对你加税的做法很是怀疑。忠诚度下降了.\n");
 		this_object()->add("faith",-(this_object()->query("tax")-pts)/10);
		this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/100);
	}else if(pts >= 90)
	{
		tell_object(me,"百姓对你加税的做法很是愤怒。忠诚度下降了.\n");
 		this_object()->add("faith",-(this_object()->query("tax")-pts)*9/10);
		this_object()->add("people",this_object()->query("people")*(this_object()->query("tax")-pts)/5000);
	}
	if(this_object()->query("faith")>100) this_object()->set("faith",100);
//	money=(people/10000)*(farm+trade)*(faith/10)*tax/5;
	money=((this_object()->query("people")+this_object()->query("soilder")/10)*(this_object()->query("farm")+
		this_object()->query("trade"))*(this_object()->query("faith")/100))*this_object()->query("tax")/1000;
	this_object()->set("tax",pts);
	me->add("balance",money);
	this_object()->set("taxing",time()+36000); //每隔十个小时才能改变税率。
	save();
	return 1;
}

int do_attack()
{
	object who,city=this_object();
	object me=this_player();
	int ap,one,two;

	if(me->query("combat_exp")<20000)
		return notify_fail("你干嘛？武功这么差就想进攻别人的城堡，你想倒找吗？\n");
	if(me->query("id")==this_object()->query("owner"))
		return notify_fail("你干嘛？火烧自己的家园哪？\n");
	if(!this_object()->query("owner"))
	{
		tell_object(me,"这是一座空城，你的士兵不费一刀一剑，大摇大摆的入了城。\n");
		message("vision",HIY+"【月影传闻】:"+me->query("name")+"攻占了"+
		this_object()->query("short")+"\n"+NOR,users());
		me->add("city/number",1);
		me->set("city/"+cityname[this_object()->query("short")], "done");
		this_object()->set("owner",me->query("id"));
		this_object()->set("ownername",me->query("name"));
		save();
		return 1;
	} //对无人占领的城市
	one = me->query("soilder")*me->query("train_level");
	two = this_object()->query("soilder")*(this_object()->query("train_level")+
		this_object()->query("defendance")*2);
	if(3*one < two)
		return notify_fail("你干嘛？这么点兵就想进攻别人的城堡，找死吗？\n"+chinese_number(one)+
		"\n"+chinese_number(two)+"\n");
	who=find_player(this_object()->query("owner"));
	if(!who) return notify_fail("城市的主人不在线，你不能攻击他的城市。\n");
	ap=me->query("soilder")*me->query("train_level");
	if(ap<=0) return notify_fail("你不带兵就想打仗。你以为你是谁呀？\n");
		tell_object(who,me->query("name")+"要攻击你的"+this_object()->query("short")+"了。请赶紧派兵支援。\n");
	if (!me->query("attacking"))
	{
		message("vision",HIY+"【月影传闻】"+me->query("name")+"对"+
		this_object()->query("short")+"大举进攻。\n"+NOR,users());
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
		return notify_fail("只有城主才能驻扎军队在这儿。\n");
	if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("指令格式：zhuza <军队> (整数)\n");
	if(pts <=0) return notify_fail("哼哼，人还有负的么？\n");
	if(pts > me->query("soilder")) 
		return notify_fail("你没有那么多士兵来分配。\n");
	pts1 = this_object()->query("soilder");
	pts2 = me->query("soilder");
	level1 = this_object()->query("train_level");
	level2 = me->query("train_level");
	level = ceil((level1*pts1+level2*pts)/(pts+pts1));
	tell_object(me,"你将手下士兵分配了一部驻扎在城堡里。\n");
	this_object()->add("soilder",pts);
	this_object()->set("train_level",level);
	this_object()->add("people",pts*20);
	me->add("soilder",-pts);
	me->add("city/"+cityname[this_object()->query("short")]+"sold", pts);
	message("vision",HIY+"【月影传闻】:"+me->query("name")+"派驻了"+chinese_number(pts)+
	"名士兵守卫"+this_object()->query("short")+".\n"NOR,users());
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
		return notify_fail("只有城主才能调整驻扎在这里的军队。\n");
	if( !arg || !sscanf(arg, "%d", pts)) return notify_fail("指令格式：kaiba <军队> (整数)\n");
	if(pts <=0) return notify_fail("哼哼，人还有负的么？\n");
	if(pts > city->query("soilder")) 
		return notify_fail("你的城堡里没有那么多士兵来供你调用。\n");
	pts1 = city->query("soilder");
	pts2 = me->query("soilder");
	level1 = city->query("train_level");
	level2 = me->query("train_level");
	level = ceil((level2*pts2+level1*pts)/(pts+pts2));
	tell_object(me,"你将城堡中的士兵划归你自己统领。\n");
	city->add("soilder",-pts);
	city->add("people",-pts*20);
	me->add("soilder",pts);
	if(city->query("soilder")==0)
		city->set("train_level",0);
	me->set("train_level",level);
	me->add("city/"+cityname[city->query("short")]+"sold", -pts);
	message("vision",HIY+"【月影传闻】:"+me->query("name")+"将驻扎在"+city->query("short")+
	"的"+chinese_number(pts)+"名士兵划归自己统领。\n"NOR,users());
	save();
	return 1;
}

int do_combat(string arg)
{
	object me=this_player(),who;
	int pts,train1;
	if( !arg || !sscanf(arg, "%d to %s", pts)) return notify_fail("指令格式：zhenyuan <军队> (整数)\n");
	if(pts > me->query("soilder"))
		return notify_fail("你没有那么多士兵可以指派。\n");
	train1=pts*me->query("train_level")+this_object()->query("soilder")*this_object()->query("train_level");
	train1=train1/(pts+this_object()->query("soilder"));
	tell_object(me,"你派了"+chinese_number(pts)+"名士兵增援"+this_object()->query("short")+".\n");
	who=find_player(this_object()->query("owner"));
	if(who)
		if(me != who)
			tell_object(who,me->query("name")+"派了"+chinese_number(pts)+"名士兵增援"+this_object()->query("short")+".\n");
	message("vision",HIY+"【月影传闻】:"+me->query("name")+"派了"+chinese_number(pts)+
	"名士兵紧急驰援"+this_object()->query("short")+".\n"NOR,users());
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
		return notify_fail("只有城主才能开发。\n");
	if(!arg)
	{
		printf("农业开发度(farm):"+this_object()->query("farm")+"    商业开发度(trade):"+this_object()->query("trade")+
		"\n城市防御度(defendance):"+this_object()->query("defendance")+"\n");
		return 1;
	}
	if((arg != "farm")&&(arg != "trade")&&(arg != "defendance"))
		return notify_fail("目前只有三种开发项目：农业(farm),商业(trade),防御(defendance).\n");
	if(me->query("balance") < (this_object()->query(arg)+1)*10000)
		return notify_fail("你的资金不足，还是先多赚点钱吧。\n");
	if(arg=="farm")
	{
		tell_object(me,this_object()->query("short")+"的农业开发度上升了。\n");
		if(random(3) && this_object()->query("farm")>100 )
			if(this_object()->query("faith") <=100)
			{
				tell_object(me,this_object()->query("short")+"市民的忠诚度上升了。\n");
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
			tell_object(me,this_object()->query("short")+"的商业开发度上升了。\n");
			if(random(4) && this_object()->query("trade")>100 )
				if(this_object()->query("faith") <=100)
				{ 
					tell_object(me,this_object()->query("short")+"市民的忠诚度上升了。\n");
					if(this_object()->query("faith")>100)
						this_object()->set("faith",100);
					else
						this_object()->add("faith",1);
				}
			this_object()->add("trade",1);
			this_object()->add("people",2000+random(500));
		}else
		{
			tell_object(me,this_object()->query("short")+"的城市防御度上升了。\n");
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
		return notify_fail("只有城主才能训练军队。\n");
	if( !this_object()->query("soilder") )
		return notify_fail("这座城市并没有军队驻守！\n");
	
	if( this_object()->query("train_level") >= 200 )
		return notify_fail("这座城市军队的训练度已经不能再提高了！\n");

	if(me->query("balance") < (this_object()->query("soilder")+1)*1000)
		return notify_fail("你的资金不足，还是先多赚点钱吧。\n");
	tell_object(me,this_object()->query("short")+"的军队的训练度上升了。\n");
	if(this_object()->query("train_level")>100 
	&& this_object()->query("faith")<=100
	&& this_object()->query("farm")>100 
	&& this_object()->query("trade")>100 
	&& this_object()->query("defendance")>80)
		if(random(2))
		{
			tell_object(me,"由于驻军的强大"+this_object()->query("short")+"市民的忠诚度上升了。\n");
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
	one2 = "━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
	if(faith<10) one=HIY"    城里不知为何总是笼罩着一种恐慌的气氛，谣言四布，\n民心思变。\n"NOR;
	else if(faith<30) one=WHT"    城里一片死寂，然而那并不是安详，也许是市民们对于\n谁当城主已经麻木。\n"NOR;
	else if(faith<50) one=HIC"    城民们对于城主不能说没有期待，但是如果没有政绩的\n话，这种期待很快就会消失的。\n"NOR;
	else if(faith<70) one=HIM"    城民们对于城主还算放心，尽管生活日益潦倒，他们还\n是住了下来。\n"NOR;
	else one=HIG"    整个城市都是城主的狂热追随者，他们为他塑像膜拜，\n真不知城主使用了什么手段，笼络了如此众多的人心。\n"NOR;
	one += one2;
	if(farm<30) one +=HIY"    城里满眼都是荒芜的野地，饥荒影响着每一个人。\n"NOR;
	else if(farm<80) one +=WHT"    几个农民在烈日下刨着土地，今年的收成，够不够得\n上肚皮呢？\n"NOR;
	else if(farm<140) one +=HIC"    一片片的农田散布在荒野上，尽管看来还不是让人满\n意，但是人们已经不用饿饭了。\n"NOR;
	else if(farm<180) one +=HIM"    城主对于农业似乎很重视，仓廪丰实，物以敷用。\n"NOR;
	else one +=HIG"    阡陌交织，沟渠纵横，稻花飘香，麦穗如浪，好一派\n田园风光，人们丰衣足食，安居乐业。\n"NOR;
	one += one2;
	if(trade<30) one +=HIY"    城里四室九空，饥荒贫困影响着每一个人。\n"NOR;
	else if(trade<80) one +=WHT"     平静的街上，偶而可几个小贩在来往叫卖，但买东西\n的人却聊聊无几？\n"NOR;
	else if(trade<140) one +=HIC"    人烟渐渐地多了起来，街上的叫卖声此起彼伏，甚是\n热闹。老百姓手里也有几个小钱啦。\n"NOR;
	else if(trade<180) one +=HIM"    城主对于商业的重视，使得城堡里的物质极大的丰富\n了起来，到处可以听得到店铺开张的鞭炮声和儿童的嬉笑\n声。\n"NOR;
	else one +=HIG"    高楼广厦，街道纵横，商铺林立，人海如潮，好一个\n富贵之乡。\n"NOR;

	printf(NOR HIR"〖"+HIY+this_object()->query("short")+HIR"〗"+NOR"━━━"HIY"城主："+HIW+this_object()->query("ownername")+"("+
	this_object()->query("owner")+")\n"NOR+one2+one+one2);
	printf(NOR WHT"  〖 城堡人口 〗：%8d"NOR WHT"  〖 城堡税率 〗：  %3d\n"NOR,people,tax);
	printf(NOR WHT"  〖农业开发度〗：   %5d"NOR WHT"  〖商业开发度〗：%5d\n"NOR,farm, trade);
	printf(NOR WHT"  〖城堡防御度〗：   %5d "NOR,this_object()->query("defendance"));
	if(me->query("id") != this_object()->query("owner") && !wizardp(me))
		printf(NOR "\n");
	else
	{
//		money=(people/10000)*(farm+trade)*(faith/10)*tax/5;
		money=((this_object()->query("people")+this_object()->query("soilder")/10)*(this_object()->query("farm")+
			this_object()->query("trade"))*(this_object()->query("faith")/100))*this_object()->query("tax")/1000;

		printf(NOR WHT" 〖城堡忠诚度〗：  %3d\n"NOR, faith);
		printf(NOR WHT"  〖 驻军人数 〗：%8d  〖驻军训练度〗：  %3d           \n"NOR,this_object()->query("soilder"), this_object()->query("train_level"));

		if (money > 0)
		{
	        if (money / 10000) {
				cmoney = HIY+chinese_number(money / 10000) + "两黄金"+NOR;
				money %= 10000;
    	    }
	        else cmoney = "";
	        if (money / 100) {
				cmoney = cmoney + HIW + chinese_number(money / 100) + "两白银"+NOR;
				money %= 100;
			}
			else cmoney = "";
			if ( money )
				cmoney = cmoney + YEL+chinese_number(money) + "文铜板"+NOR;
		}
		else cmoney=CYN"你在这个城堡没有收入"NOR;

		printf(NOR WHT"  〖 税收收入 〗：%s\n"NOR, cmoney);
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
		tell_object(me,"你真的要放弃这座城池吗？(true)\n");
		me->set("ready_fangqi",1);
		return 1;
	}

	who = find_player(this_object()->query("owner"));
	if( !me->query("attacking") )
		return notify_fail("你现在并没有攻城呀。\n");
	me->remove_enemy(this_object());
	me->delete("attacking");
	this_object()->delete("receive_attack");
	this_object()->delete("attacker");
	tell_object(me,"你见势头不对，一声令下，鸣金收兵。\n");
	tell_object(who,"你保卫了城市，得到了10000的武学经验奖励。\n");
	who->add("combat_exp",10000);
	who->set("city/"+cityname[this_object()->query("short")]+"sold", this_object()->query("soilder"));
	tell_object(me,"你进攻城市失败，除部分士兵被消灭外，还损失了了10000的武学经验。\n");
	me->add("combat_exp",-20000);

	message("vision",HIY+"【月影传闻】:"+me->query("name")+"取消了对"+this_object()->query("short")+
		"的进攻，自动退兵了.\n"NOR,users());
	save();
	return 1;
}

int do_true(string arg)
{
	int soilder,train;
	object me=this_player();

	if(!me->query("ready_fangqi"))
		return notify_fail("什么？\n");

	tell_object("你自动放弃了对"+this_object()->query("short")+"的统治。\n");
	train=this_object()->query("train_level");
	soilder=this_object()->query("soilder");
	if(soilder)
		tell_object(me,"你将城里的"+chinese_number(soilder)+"名士兵从新归入麾下。\n");
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
	message("vision",HIY+"【月影传闻】:"+me->query("name")+"自动放弃了对"+this_object()->query("short")+
		"的统治，撤离了该城.\n"NOR,users());
	save();
	return 1;
}

int do_defend(string arg)
{
	object me=this_player();
	object who;
	int one,two,three;
	if(me->query("id")!= this_object()->query("owner"))
		return notify_fail("你不是城主。\n");

	if(!this_object()->query("receive_attack"))
		return notify_fail("你没有遭到攻击呀。\n");
	if(!arg)
	{
		printf("目前可用的防卫措施有:滚木擂石(stone),箭雨(arrow),火烧(fire)\n");
		return 1;
	}
	if(me->is_busy()) return notify_fail("你一时手忙脚乱，竟然不知道如何指挥才好。\n");

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
			message_vision(HIC"$N的士兵吆喝着将无数巨石从城墙上推下来，$n一时不备，士兵死伤不少。\n"NOR,me,who);
			message("vision",who->query("name")+"损失士兵"+chinese_number(random(three/10))+"名。\n", ({ me,who})); 
			me->start_busy(random(5)+1);
			return 1;
		}

	if(arg=="arrow")
		if(random(one)>3*random(two))
		{
			message_vision(HIC"$N叫道：放箭。但听一声梆子响，从箭垛后面钻出无数士兵，箭如飞蝗，$n的士兵倒下了一片。\n"NOR,me, who);
			message("vision",HIC+who->query("name")+"损失士兵"+chinese_number(random(three/10))+"名。\n"NOR, ({ me, who })); 
			me->start_busy(random(10)+2);
			return 1;
		}

	if(arg=="fire")
		if(random(one)>5*random(two))
		{
			message_vision(HIC"$N大叫：放火、放火。城上扔下无数燃着的火把，惨叫声中，$n的士兵死伤甚众。\n"NOR,me,who);
			message("vision",HIC+who->query("name")+"损失士兵"+chinese_number(random(three/10))+"名。\n"NOR, ({ me,who })); 
			me->start_busy(random(15)+3);
			return 1;
		}
	message("vision",HIC+who->query("name")+"却早有防备，没有受到损失。\n"NOR, ({ me, who})); 
	me->start_busy(random(5)+1);
	return 1;
}

void fight_city(object me, object city, object who, int number)
{
	if( city->query("owner")!=me->query("id") && query("attacker") == me->query("id") ) {
		tell_object(me,HIR"你开始对"+city->query("short")+"发动了第"+chinese_number(number)+"次进攻！\n"NOR);
		tell_object(who,HIR+me->query("name")+"开始对"+city->query("short")+"发动了第"+chinese_number(number)+"次进攻！\n"NOR);
		COMBAT_D->do1_attack(me, city, who);
		remove_call_out("fight_city");
		number += 1;
		call_out("fight_city", 2, me, city, who, number );
	}
	return;
}
