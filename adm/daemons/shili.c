// by bluewww@yszz

#include <ansi.h>

inherit F_SAVE;

mapping shili=([
	"baoxiang": (["五庄观":1000,]),
	"biqiu"   : (["南海普陀山":1000,]),
	"qinfa"   : (["五庄观"    :1000,]),
	"chechi"  : (["方寸山三星洞":1000,]),
	"fengxian": (["东海龙宫": 1000,]),
	"zhuzi" : (["蜀山剑派"  : 1000,]),
	"jisaiguo": (["阎罗地府": 1000,]),
	"nverguo" : (["月宫"    : 1000,]),
	"tianzhu" : (["大雪山"  : 1000,]),
	"tongtian": (["东海龙宫": 1000,]),
	"kaifeng" : (["盘丝洞"  : 1000,]),
	"yuhua"   : (["大雪山"  : 1000,]),
	"wudidong": (["陷空山无底洞" : 1000,]),
	"jinping" : (["武圣门"     : 1000,]),
	"huangfeng":(["将军府"   : 1000,]),
	"jz"      : (["将军府"   : 1000,]),
	"shushan" : (["蜀山剑派"  : 1000,]),
	"wuji"    : (["火云洞"   : 1000,]),
	"xuyi"    : (["盱眙山"   : 1000,]),
	"fenghuang":(["凤凰星"   : 1000,]),
]);

mapping MASTERS=([
	"方寸山三星洞":"菩提老祖",
	"南海普陀山":"观音菩萨",
	"五庄观":"镇元大仙",
	"阎罗地府":"地藏王菩萨",
	"月宫":"西王母",
	"东海龙宫":"傲广",
	"大雪山":"大鹏明王",
	"陷空山无底洞":"哪吒",
	"蜀山剑派":"静虚老祖",
	"武圣门":"孔武大帝",
	"盘丝洞":"紫霞仙子",
	"将军府":"白发老人",
	"火云洞":"黄飞虎",
	"盱眙山":"大圣国师王菩萨",
	"凤凰星":HIC"凤"HIR"凰"NOR
]);

void create()
{
	seteuid(getuid());
	if ( !restore() && !mapp(shili) ){
		shili = ([]);
	}
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "shilid"; }

string query_family(string pos)
{
	mapping tmp;
	string* nf;
	int max,i=1,nmax;

	if(!mapp(tmp=shili[pos]))return "";
	nf=keys(tmp);
	max=tmp[nf[0]];
	nmax=0;

	while(i<sizeof(nf)){
		if(tmp[nf[i]]>max){
			max=tmp[nf[i]];
			nmax=i;
		}
		i++;
	}
	return nf[nmax];
}

string query_master(string faname)
{
	return MASTERS[faname];
}

int query_shili(string pos,string faname)
{
	mapping tmp;

	if(!mapp(tmp=shili[pos]))return 0;
	return tmp[faname];
}
 // added by happ@YSZZ

int query_all_shili(string faname)
{
	mapping tmp;
	int i,n;
	string *quyu;

	if( ! mapp(shili) ) return 0;

	quyu=keys(shili);

	for( i=0;i<sizeof(shili);i++)
	{
		n=query_shili(quyu[i],faname);
		printf("在〖%-s〗有%6d点势力",this_object()->query_chinese(quyu[i]),n);
		i%2==1?write("\n"):write("            ");
	}

	return 1;
}



void increase_shili(string pos,string faname,int amount)
{
	mapping tmp;

	if(!mapp(tmp=shili[pos]))return;
	if(!tmp[faname])tmp+=([faname:amount]);
	else tmp[faname]+=amount;

	if(tmp[faname]>1000)tmp[faname]=1000;
}

void decrease_shili(string pos,string faname,int amount)
{
	mapping tmp;

	if(!mapp(tmp=shili[pos]))return;
	if(!tmp[faname])return;
	else tmp[faname]-=amount;

	if(tmp[faname]<0)tmp[faname]=0;
}

string query_chinese(string pos)
{
	mapping diqu=([
		"baigudong" : "白骨山",
		"baihuling" : "白虎岭",
		"baotou"    : "豹头山",
		"baoxiang"  : "宝象国",
		"bibotan"   : "碧波潭",
		"biqiu"     : "比丘国",
		"chechi"    : "车迟国",
		"dudi"      : "毒敌山",
		"fengxian"  : "凤仙郡",
		"firemount" : "火焰山",
		"heifeng"   : "黑风岭",
		"huangfeng" : "黄风岭",
		"jilei"     : "积雷山",
		"jindou"    : "金兜山",
		"jingjiling": "荆棘岭",
		"jinping"   : "金平府",
		"jisaiguo"  : "祭赛国",
		"kusong"    : "枯松涧",
		"lingshan"  : "灵山",
		"liusha"    : "流沙河",
		"maoying"   : "毛颖山",
		"nverguo"   : "女儿国",
		"pansi"     : "盘丝岭",
		"pingding"  : "平顶山",
		"qilin"     : "麒麟山",
		"qinfa"     : "钦法国",
		"qinglong"  : "青龙山",
		"shuangcha" : "双叉岭",
		"tianzhu"   : "天竺国",
		"tongtian"  : "陈家庄",
		"village"   : "小村庄",
		"wudidong"  : "张家村",
		"wuji"      : "乌鸡国",
		"wuzhuang"  : "五庄观",
		"xiaoxitian": "小西天",
		"yingjian"  : "鹰愁涧",
		"yinwu"     : "隐雾山",
		"yuhua"     : "玉华县",
		"yunzhan"   : "云栈洞",
		"zhujie"    : "竹节山",
		"zhuzi"     : "朱紫国",
		"jz"        : "江州府",
		"shushan"   : "乌鸦嘴",
		"kaifeng"   : "开封府",
		"xuyi"      : "蠙　城",
		"fenghuang" : "凤凰城",
	]);
	return diqu[pos];
}

