        
string* xianname=({
	"����","xian ren",
	"�ɹ�","xian guan",
	"��Ů","xian nv",
	"����","xian qing",
	"�ɽ�","xian jiang",
	"�ɼ�","xian ji",
	"����","xian fei",
	"����","da xian",       
	"���ƴ�ʦ","baiyun dashi",
	"�����","yanchi xia",
	"����","xian zi",
	"����ר��","mieyao zhuanjia",
	"����","pu sa",
	"����","gong gong",
	"ף��","zhu rong",
	"������","jiang ziya",
	"��߸","ne zha",
	"ľ߸","mu zha",
	"��߸","jin zha",
	"��������","tuota tianwang",
	"���","jin gang",
	"����","zun zhe",
	"��Ŵ���","chijiao daxian",
	"�Ʒɻ�","huangfei hu",
	"�����","guancheng zi",
	"̫������","taiyi zhenren",
	"½ѹ����","luya daoren",
	"������","kuilei sheng",
	"��ظ","zhong kui",
	"�޺�","luo han",
	"����","jian xian",
	"����ү","zaowang ye",
	"������","tudi shen",
	"����","cai shen",
	"��Ů","long nv",
	"�Ʋ�ͯ��","shancai tongzi",
	"��������","jinbao tianzun",
	"���","tian bing",
	"�콫","tian jiang",
	"������","juling shen",
});

void create()
{
	int i;

	set_name(xianname[i=random(sizeof(xianname)/2)*2],({xianname[i+1]}));
	set("age",20+random(80));
	set("attitude","heroism");
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

    setup();
}
