// by bluewww@yszz

#include <ansi.h>

inherit F_SAVE;

mapping shili=([
	"baoxiang": (["��ׯ��":1000,]),
	"biqiu"   : (["�Ϻ�����ɽ":1000,]),
	"qinfa"   : (["��ׯ��"    :1000,]),
	"chechi"  : (["����ɽ���Ƕ�":1000,]),
	"fengxian": (["��������": 1000,]),
	"zhuzi" : (["��ɽ����"  : 1000,]),
	"jisaiguo": (["���޵ظ�": 1000,]),
	"nverguo" : (["�¹�"    : 1000,]),
	"tianzhu" : (["��ѩɽ"  : 1000,]),
	"tongtian": (["��������": 1000,]),
	"kaifeng" : (["��˿��"  : 1000,]),
	"yuhua"   : (["��ѩɽ"  : 1000,]),
	"wudidong": (["�ݿ�ɽ�޵׶�" : 1000,]),
	"jinping" : (["��ʥ��"     : 1000,]),
	"huangfeng":(["������"   : 1000,]),
	"jz"      : (["������"   : 1000,]),
	"shushan" : (["��ɽ����"  : 1000,]),
	"wuji"    : (["���ƶ�"   : 1000,]),
	"xuyi"    : (["����ɽ"   : 1000,]),
	"fenghuang":(["�����"   : 1000,]),
]);

mapping MASTERS=([
	"����ɽ���Ƕ�":"��������",
	"�Ϻ�����ɽ":"��������",
	"��ׯ��":"��Ԫ����",
	"���޵ظ�":"�ز�������",
	"�¹�":"����ĸ",
	"��������":"����",
	"��ѩɽ":"��������",
	"�ݿ�ɽ�޵׶�":"��߸",
	"��ɽ����":"��������",
	"��ʥ��":"������",
	"��˿��":"��ϼ����",
	"������":"�׷�����",
	"���ƶ�":"�Ʒɻ�",
	"����ɽ":"��ʥ��ʦ������",
	"�����":HIC"��"HIR"��"NOR
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
		printf("�ڡ�%-s����%6d������",this_object()->query_chinese(quyu[i]),n);
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
		"baigudong" : "�׹�ɽ",
		"baihuling" : "�׻���",
		"baotou"    : "��ͷɽ",
		"baoxiang"  : "�����",
		"bibotan"   : "�̲�̶",
		"biqiu"     : "�����",
		"chechi"    : "���ٹ�",
		"dudi"      : "����ɽ",
		"fengxian"  : "���ɿ�",
		"firemount" : "����ɽ",
		"heifeng"   : "�ڷ���",
		"huangfeng" : "�Ʒ���",
		"jilei"     : "����ɽ",
		"jindou"    : "��ɽ",
		"jingjiling": "������",
		"jinping"   : "��ƽ��",
		"jisaiguo"  : "������",
		"kusong"    : "���ɽ�",
		"lingshan"  : "��ɽ",
		"liusha"    : "��ɳ��",
		"maoying"   : "ëӱɽ",
		"nverguo"   : "Ů����",
		"pansi"     : "��˿��",
		"pingding"  : "ƽ��ɽ",
		"qilin"     : "����ɽ",
		"qinfa"     : "�շ���",
		"qinglong"  : "����ɽ",
		"shuangcha" : "˫����",
		"tianzhu"   : "���ù�",
		"tongtian"  : "�¼�ׯ",
		"village"   : "С��ׯ",
		"wudidong"  : "�żҴ�",
		"wuji"      : "�ڼ���",
		"wuzhuang"  : "��ׯ��",
		"xiaoxitian": "С����",
		"yingjian"  : "ӥ�",
		"yinwu"     : "����ɽ",
		"yuhua"     : "����",
		"yunzhan"   : "��ջ��",
		"zhujie"    : "���ɽ",
		"zhuzi"     : "���Ϲ�",
		"jz"        : "���ݸ�",
		"shushan"   : "��ѻ��",
		"kaifeng"   : "���⸮",
		"xuyi"      : "ϙ����",
		"fenghuang" : "��˳�",
	]);
	return diqu[pos];
}

