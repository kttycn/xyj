//����������

#include <ansi.h>
#define SHILI_D "/adm/daemons/shili"
#define YAODIR_ "/d/obj/yao/"

string* listxian=({
	"yao-moon",
	"yao-fangcun",
	"yao-putuo",
	"yao-dragon",
	"yao-wzg",
	"yao-phoenix",
	"yao-jjf",
	"yao-xuyi",
	"yao-shushan",
	"yao-wusheng",
});

string* listyao=({
	"yao-hell",
	"yao-pansi",
	"yao-wudidong",
	"yao-xueshan",
	"yao-gumu",
	"yao-huo",
});


string *dirs = ({
	"baigudong",
	"baihuling",
	"baotou",
	"baoxiang",
	"bibotan",
	"biqiu",
	"chechi",
	"dudi",
	"fengxian",
	"firemount",
	"heifeng",
	"huangfeng",
	"jilei",
	"jindou",
	"jinping",
	"jisaiguo",
	"kusong",
	"maoying",
	"nverguo",
	"pansi",
	"pingding",
	"qinfa",
	"shuangcha",
	"tianzhu",
	"tongtian",
	"village",
	"wuji",
	"wuzhuang",
	"xiaoxitian",
	"yingjian",
	"yuhua",
	"zhuzi",
});

int add_new_yao( object me);
void create()
{
    seteuid(getuid());
}

string query_family_type(string fam)
{
    if(fam=="�����"||fam=="������"||fam=="����ɽ"||fam=="��ɽ����"||
    fam=="��ׯ��"||fam=="�Ϻ�����ɽ"||fam=="��������"||fam=="�¹�"||
    fam=="����ɽ���Ƕ�"||fam=="ˮ����")
		return "xian";
    return "yao";
}


string add_new_yao(object me)
{
	string loc,fam,pos;
	string mytype,yaotype,postype;
	object yao;
	string str;
	int lvl=me->query_temp("mpmieyao/level");
	string yaoid;
	string yaoname,*yaoids;

	me->delete("mpmieyao");
	pos=dirs[random(sizeof(dirs))];
	loc="/d/qujing/"+pos;
	mytype=query_family_type(me->query("family/family_name"));
//      fam=SHILI_D->query("family");
	fam=SHILI_D->query_family(pos);
	postype=query_family_type(fam);
	if(mytype=="xian") yaotype="yao";
	else yaotype="xian";

	if(yaotype=="xian"){
		yao=new(YAODIR_+listxian[random(sizeof(listxian))]);
	}else{
		yao=new(YAODIR_+listyao[random(sizeof(listyao))]);
	}

    yaoname=yao->query("name");
    yaoids=yao->parse_command_id_list();
    yaoid=me->query("id")+"'s "+yaoids[0];
    yaoids=({yaoid})+explode(yaoid," ");
    yao->set_name(yaoname,yaoids);
	yao->set("pos",pos);

	str=yao->invocation(me,lvl,loc);
	if(mytype!=postype){
		str=str+"һ��������\n����ȥ�������ǵĲ���\n";
	}else if(fam==me->query("family/family_name")){
		str=str+"һ�����ҡ�\n����ȥ����֮��\n";
	}else {
		str=str+"һ�����ҡ�\n����ȥ��"+fam+"����֮��\n";
	}
	if(random(100))
	{
		str=str+MAG"\n����ĸ������Щ����Ŷ��\n\n"NOR;
		me->set_temp("sword", 1);
	}
	me->set("mpmieyao/id",yaoid);
	me->set("mpmieyao/location",loc);
    me->set("mpmieyao/name",yaoname);
    me->set("mpmieyao/place",SHILI_D->query_chinese(pos));
	return str;
}

string query_yao(object me)
{
	mapping mieyao;
	int lvl;
	string str="";
	object yao;

	if(mapp(mieyao=me->query("mpmieyao"))){
		if(time()<me->query("mpmieyao_time")+600)
			return ("��������ȥɱ��"+mieyao["place"]+"��"+mieyao["name"]+"ô?\n");
		else{
			str="������û�ã����ٸ���һ�λ��ᣡ\n";
			me->add("faith",-1);
			lvl=me->query_temp("mpmieyao/level");
			if(lvl>0)lvl--;
//         me->set_temp("mpmieyao_temp",lvl);
				me->set_temp("mpmieyao/level",lvl);
		}
	}else {
		lvl=me->query_temp("mpmieyao/level");
		lvl++;
		if(lvl==10)lvl=1;
			me->set_temp("mpmieyao/level",lvl);
		if(time()-me->query("mpmieyao_time")<100)
			return ("�������ˣ��㻹������ȥ��Ϣһ�°ɣ�\n");
    }
    str+=add_new_yao(me);
    return str;
}

string delete_mieyao(object me)
{
	int faith, score;
	if((int)me->query("mpmieyao"))
	{
		me->delete("mpmieyao");
		if( faith = me->query("faith") < 5)
			me->set("faith", 0);
		else
			me->add("faith",-5);
		if( score = me->query("score") < 3)
			me->set("score", 0);
		else
			me->add("score",-3);
		
		return ("û�õĶ�����");
	}
	else
		return ("���������𣿣�");
}

