// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000

#include <ansi.h>

inherit NPC;

string *msg_d = ({
	"�����","�����","ɵB","�Ҳ�","����","������˯","f~u~c~k",
	"�٣�","��!","fuck","FUCK","Fuck","���","�����","������",
	"���̵�","����������","�����","��үү��","�����̵�","�Ź�ƨ",
	"�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������",
	"�����","��ƨwiz","��wiz","��wiz","������","���յ�","¿�յ�",
	"������","�����","������","�ƣգã�","F u c k","Сƨ��","��ƨ","����",
	"f u c k","˯��","��������","TNND","wokao","tnnd","wo kao","kao","KAO",
	"�ˣ���","����","�������","Shit","SHIT","�ӣȣɣ�","�����",
	"����ʦ","shit","��ƨ��ʦ","����ʦ","��WIZ","����ʦ",
});

void create()
{
	set_name("��ظ", ({"zhong kui", "zhongkui"})); 
	set("title", HIB"��������ʦ��"NOR);
	set("gender", "����" );
	set("age", 30);
	set("per", 5);
	set("long", "���˲�֪��ץ����ɣ���������׼�������ʲô���¡�\n"); 
	set("combat_exp", 10000000);
	set("attitude", "peaceful");
	set("dex", 50);
	set("str", 50);

	set_skill("literate", 800);
	set("max_kee", 1000);
	set("max_sen", 500);
	set("max_force", 1000);
  	
  	set("no_clean_up",1);
	setup();

	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();

	if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
	if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
	if( !clonep() ) CHANNEL_D->register_relay_channel("party");
	if( !clonep() ) CHANNEL_D->register_relay_channel("es");
	if( !clonep() ) CHANNEL_D->register_relay_channel("sldh");
	if( !clonep() ) CHANNEL_D->register_relay_channel("music");
	if( !clonep() ) CHANNEL_D->register_relay_channel("moon");
	if( !clonep() ) CHANNEL_D->register_relay_channel("yyqy");
}

void relay_channel(object criminal, string channel, string msg)
{
	int i, number;
	string criname,result,name;
	int howlong;
	if( !userp(criminal) ) return;

	for(i=0; i<sizeof(msg_d); i++)
	{
		if( strsrch(msg, msg_d[i]) >= 0)
		{
			criminal->add("qiushi/number",1);
			number = criminal->query("qiushi/number");
			command("chat* �����������ظһ��ŭ�ȣ�"+criminal->query("name")+" ���������ܲ����ˡ�"); 
			message_vision(CYN"����С���Ȼ���֣��ӳ����ף�һ�¾���ס$N�Ĳ��ӡ�\n$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, criminal);
			if (number<7)
			{
				if (number>3)
				{
					message_vision(HIB"$N��$n�ȵ����㾺�ҵ����οڳ����������������ǲ��ǵ��ˣ�\n"NOR,this_object(), criminal);
					tell_object(criminal,RED"���Ȼ������һ��ʧ�����ӿ��������\n\n");
					criminal->skill_death_penalty();
				}
				criname = criminal->query("name") + "("+criminal->query("id")+")";
				howlong=20;
				result = sprintf("%s��%sƵ��˵�໰(%s)������ %d ���ӣ�\n",
				criname,channel,msg,howlong);

				criminal->set("qiushi/howlong",howlong);
				criminal->set("qiushi/temp",result);

				criminal->move("/d/death/qiushi");
				tell_object("��ظ˵�����ҿڳ����Ի���ڴ˵�����ʵʵ���Ҷ��ţ�"); 
				message_vision(CYN"˵�ţ�����һ�ɣ�$N�����ڵ��ϡ�\n"NOR, criminal); 

				message("channel:rumor",HIM"��ҥ������ĳ�ˣ���˵"+criname+"�ڹ���Ƶ����"+
				chinese_number(number)+"��ʹ�����Ի������ظץ���ˡ�\n"NOR, users());
				return;
			}
			else
			{
				message_vision(HIY"$N�ߺ�һ����$n�����������Ի�����˰�����������ͷ��������ȥι����\n"NOR,this_object(), criminal);
				message_vision(HIR"ֻ������������˹�����ץס$N����$N�Ķ�Ƥ��$N�ĳ��ӳ���������$N�ĳ�����ס\n"+
				"$N�Ĳ�������һ�����ǣ�����������ͷ���������������������仩������\n"+
				"���������徻�ˡ�\n"NOR,criminal);
				criminal->die(); 
				COMBAT_D->victim_penalty(criminal, this_object()); 
				return; 
			}
		}
	}
}
