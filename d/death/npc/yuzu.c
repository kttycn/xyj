// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000

#include <ansi.h>

inherit NPC;

string *msg_d = ({
	"他妈的","你妈的","傻B","我操","操你","和你妈睡","f~u~c~k",
	"操！","操!","fuck","FUCK","Fuck","婊子","干你姐","干你妹",
	"奶奶的","和你妈做爱","她妈的","你爷爷的","他奶奶的","放狗屁",
	"放你妈的屁","tmd","TMD","tmmd","TMMD","操你妈","日死你","干你娘",
	"操你姐","狗屁wiz","狗wiz","破wiz","日死你","狗日的","驴日的",
	"干你妈","干你的","ｆｕｃｋ","ＦＵＣＫ","F u c k","小屁孩","放屁","滚蛋",
	"f u c k","睡你","狗娘养的","TNND","wokao","tnnd","wo kao","kao","KAO",
	"ＫＡＯ","ｋａｏ","他妈妈的","Shit","SHIT","ＳＨＩＴ","ｓｈｉｔ",
	"破巫师","shit","狗屁巫师","狗巫师","死WIZ","死巫师",
});

void create()
{
	set_name("钟馗", ({"zhong kui", "zhongkui"})); 
	set("title", HIB"「鬼判天师」"NOR);
	set("gender", "男性" );
	set("age", 30);
	set("per", 5);
	set("long", "无人不知的抓鬼大仙，你碰上他准是你干了什么坏事。\n"); 
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
			command("chat* 忽听半空中钟馗一声怒喝："+criminal->query("name")+" ，这次你可跑不了了。"); 
			message_vision(CYN"勾魂小鬼忽然出现，扔出索套，一下就套住$N的脖子。\n$N伸长舌头、翻着白眼地被拖走了。\n"NOR, criminal);
			if (number<7)
			{
				if (number>3)
				{
					message_vision(HIB"$N对$n喝道：你竞敢第三次口出秽语，不给你点厉害是不记得了！\n"NOR,this_object(), criminal);
					tell_object(criminal,RED"你忽然觉得有一种失落感用涌上心来。\n\n");
					criminal->skill_death_penalty();
				}
				criname = criminal->query("name") + "("+criminal->query("id")+")";
				howlong=20;
				result = sprintf("%s在%s频道说脏话(%s)被囚禁 %d 分钟！\n",
				criname,channel,msg,howlong);

				criminal->set("qiushi/howlong",howlong);
				criminal->set("qiushi/temp",result);

				criminal->move("/d/death/qiushi");
				tell_object("钟馗说道：敢口出污言秽语，在此地老老实实给我蹲着！"); 
				message_vision(CYN"说着，绳子一松，$N被扔在地上。\n"NOR, criminal); 

				message("channel:rumor",HIM"【谣言四起】某人：据说"+criname+"在公众频道第"+
				chinese_number(number)+"次使用污言秽语，被钟馗抓走了。\n"NOR, users());
				return;
			}
			else
			{
				message_vision(HIY"$N高喊一声：$n这厮满嘴污言秽语，来人啊，把他的舌头割下来拿去喂狗！\n"NOR,this_object(), criminal);
				message_vision(HIR"只见两个恶鬼走了过来，抓住$N挤破$N的肚皮把$N的肠子扯出来再用$N的肠子勒住\n"+
				"$N的脖子用力一拉，呵－－！整条舌头都伸出来啦！恶鬼再手起刀落哗－－！\n"+
				"整个世界清净了。\n"NOR,criminal);
				criminal->die(); 
				COMBAT_D->victim_penalty(criminal, this_object()); 
				return; 
			}
		}
	}
}
