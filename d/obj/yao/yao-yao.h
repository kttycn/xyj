string* guainame=({
	"Ұè��","yemao guai",
	"Ұ����","yeji guai",
	"Ұ����","yegou guai",
	"Ұ�ù�","yetu guai",
	"Ұ���","yexiang guai",
	"Ұ�ܹ�","yexiong guai",
	"Ұ���","yezhu guai",
	"Ы�ӹ�","xiezi guai",
	"Ұ���","yehou guai",
	"����","yizi yao",
	"����","gui po",
	"����","feng yao",
	"ѩ��","xue jing",
	"����","hama guai",
	"�ڻ���","bihu guai",
	"ˮ�߾�","shuishe jing",
	"��ʬ","jiang shi",
	"����","shu yao",
	"���꾫","huli jing",
	"������","huaishu jing",
	"��Ѫ��","xixie gui",
	"������","yangshu jing",
	"������","diaosi gui",
	"���޳�","heiwu chang",
	"���޳�","baiwu chang",
	"������","hudie jing",
	"����","xing tian",
	"��","kui",
	"���","chi you",
	"ˮħ��","shui moshou",
	"��ħ��","tu moshou",
	"��ħ��","huo moshou",
	"�Թ�","jiao guai",
	"����","she yao",
	"ʯ�����","shiji niangniang",
	"��ɽ����","heishan laoyao",
	"��򼾫","wugong jing",
	"�׹Ǿ�","baigu jing",
	"֩�뾫","zhizhu jing",
	"����","feng yao",
	"������","denglong guai",
	"̳�Ӿ�","tanzi guai",
	"ɨ�Ѿ�","saoba jing",
});
        
void create()
{
	int i;

	set_name(guainame[i=random(sizeof(guainame)/2)*2],({guainame[i+1]}));
	set("age",20+random(80));
	set("attitude","heroism");
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
}
