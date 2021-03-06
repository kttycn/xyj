//负责存放妖。

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
    if(fam=="凤凰星"||fam=="将军府"||fam=="盱眙山"||fam=="蜀山剑派"||
    fam=="五庄观"||fam=="南海普陀山"||fam=="东海龙宫"||fam=="月宫"||
    fam=="方寸山三星洞"||fam=="水帘洞")
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
		str=str+"一带护法。\n你速去扰乱他们的部署！\n";
	}else if(fam==me->query("family/family_name")){
		str=str+"一带扰乱。\n你速去消灭之。\n";
	}else {
		str=str+"一带扰乱。\n你速去助"+fam+"消灭之。\n";
	}
	if(random(100))
	{
		str=str+MAG"\n西王母那里有些传言哦！\n\n"NOR;
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
			return ("不是让你去杀了"+mieyao["place"]+"的"+mieyao["name"]+"么?\n");
		else{
			str="你真是没用，我再给你一次机会！\n";
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
			return ("辛苦你了，你还是先下去休息一下吧！\n");
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
		
		return ("没用的东西！");
	}
	else
		return ("你有任务吗？！");
}

