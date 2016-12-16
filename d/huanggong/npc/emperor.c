#include <ansi.h>
inherit NPC;
int laojun_yao(object me);
int check();

void create()
{
	set_name("��̫��", ({"tang taizong", "tang", "tai zong", "zong", "king", "emperor"}));
	set("long", "���ƹ�̫֮�ڻʵ�������\n");
	set("title", HIY"���ƻʵ�"NOR);
	set("gender", "����");
	set("rank_info/respect", "����");
	set("age", 80);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("int", 30);
	set("max_kee", 700);
	set("max_gin", 700);
	set("max_sen", 700);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 800);
	set("mana", 800);
	set("mana_factor", 40);
	set("combat_exp", 220000);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("spells", 50);
	set_skill("force", 50);
	set_skill("seashentong", 50);
	set_skill("dragonforce", 50);
	set_skill("dragon-steps", 50);
	set_skill("dragonfight", 50);
	map_skill("unarmed", "dragonfight");
	map_skill("dodge", "dragon-steps");
	map_skill("force", "dragonforce");
	map_skill("spells", "seashentong");
	set("inquiry",([
		"�¹���" :(: check :),
		"����"	:(: laojun_yao :),
		"Ϭţ��"	:(: laojun_yao :),
		"����"	:(: laojun_yao :),
	]));
	set_weight(5000000);	
	setup();
	carry_object("/d/obj/cloth/mangpao")->wear();
}

void init ()
{
	object who=this_player();
	if(!who) return;

	call_out ("test_player",1,this_player());
	if ((int)who->query("quest/reward") ){
		who->start_busy(2);
	}
}

string *strs = ({
	"$N��$n��̾����",
	"$N��$n���͵���",
	"$N΢Ц�Ŷ�$n˵����",
	"$N����ض�$n˵����",
});

void test_player (object who)
{
	object me = this_object();
	object where = environment (me);
	object dachen;
	string str;
	int rand, reward, color;
	mapping colors;

	if (who->query("quest/reward") < 1)
		return;

	colors=who->query("quest/colors");
	color=sizeof(colors);
//		if(!color) return;
	switch(color) {
		case 1: reward=1;break;
		case 2: reward=1;break;
		case 3: reward=3;break;
		case 4: reward=7;break;
		case 5: reward=10;break;
		case 6: reward=15;break;
		case 7: reward=25;break;
		case 8: reward=30;break;
		case 9: reward=35;break;
		default: reward=1;
	}
		
	// mon 12/17/98
	if(((int)who->query("combat_exp")+(int)who->query("daoxing"))/2
	<20000) { // for newbie, no color request.
			 // for older players, rewards depends on number of colors.
		if(color<2) color=2;
		if(reward<10) reward=10;
	}

	who->set_temp("quest/reward_point",(int)who->query("quest/reward")*reward/6);

	message_vision ("\nһ����$N����ӿ�𵭵���"+
		(color>2?chinese_number(color)+"��":"")+
		"���ơ�\n",who);

	if(color==1) { // no dx & pot rewards.
		rand=random(6);
	} else {
		rand=random(100);
	}
		
	if(rand==0)
		str = "zhang shiheng";	
	else if(rand<3)
		str = "meng ziru";
	else if(rand<6)
		str = "du ruhui";			 
	else if(rand<53)
		str = "duan zhixian";
	else if(rand<79)
		str = "xiao yu";
	else 
		str = "xu maogong";		 

	dachen = present (str, where);

	if (! dachen) {
		dachen = present ("da chen", where);
		//someone took dachen out of this room. nobody should do this.
		//here only give minimum reward as penalty.
		who->set_temp("quest/reward_point",0);
	}

	if (! dachen ||
	!living(dachen))
	{
		message_vision ("$N��$n˵�������ǲ��ڣ�"+RANK_D->query_respect(who)+
			"�Ժ�Ҳ��\n",me,who);
		return;
	}
	message_vision (strs[random(sizeof(strs))]+RANK_D->query_respect(who)+
		"�������ƣ������������޹�Ȼ�����������㣡\n",me,who);
	message_vision ("\n$N����ǰ���Ͻ���$n�ĵ�ǰ������¡�\n",who,me);
	who->start_busy (3,3);
	call_out ("reward_player",2,me,who,dachen);
}

void reward_player (object me, object who, object dachen)
{

	// added by mon 5/29/98 to prevent players repeatedly
	// get reward.
	if ((int)who->query("quest/reward") < 1)
		return;

	message_vision ("\n�Ա�������$N������$n˵�˼��䣬$n���˵�ͷ��\n",dachen,me);
	dachen->reward(who);
	message_vision ("\n$N��æ����һ�ݣ�С�������վ������\n",who,me);
	who->delete("quest/reward");
	who->interrupt_me();
}

int check()
{
	object me=this_player();
	int i;
	object jiasha, chen;

	chen = present("chen guangrui", environment(me));
	if( chen )
		destruct(chen);

	if ( me->query("obstacle/jz") == "done" )
		return 0;
	if ( me->query("combat_exp") < 10000)
		return 0;
	if( !me->query_temp("obstacle/can_see_king") )
		return 0;
	i = random(600);
	me->add("obstacle/number",1);
	me->set("obstacle/jz","done");
	me->add("daoxing",i+4000);
	me->delete_temp("obstacle");
	me->add("score", 10);
	command("oh "+me->query("id"));
	command("say ������������ȥ�ɣ�ϣ����ȡ��·��һ·ƽ����");
	jiasha = new("/d/obj/cloth/jiasha2");
	jiasha->move(me);	
	command("chat "+me->query("name")+"ɱ��������ˣ��ȳ��ͳ����");
	message("channel:chat",HIW"������ն������̫��(Tang taizong)��"+me->query("name")+"��������ȡ����һ�أ�\n"NOR,users());
	tell_object (me,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	me->save();
	return 1;
}

void reset()
{
	this_object()->delete_temp("given");
}
/*
string laojun_yao(object me)	
{
	me=this_player();
	if( me->query("laojun_jing") != 1 ) 
	{
		command("say ��ȥ�ʹ�̫���Ͼ�����!");
		command("shake");
		return ("����������ô���ĵ����� \n");
	}
	if( me->query("laojun_killjing") != 1 ) 
	{
		command("say ̫���Ͼ�˵����ׯ��......");
		command("hmm");
		return ("��ȥ��ׯ��ѽ!!\n");
	}
	command("say ���������");
	message_vision ("��̫����Щ��������.\n",me);
	command("say ���ɻ������");
	me->set("enter", 1);
	return ("��ξͶ���л�����ˡ�����\n");
}
*/

int laojun_yao(object me)	
{
	me=this_player();
//	object ziyingjian,doublesword;

//	if( me->query("ziying")=="done" )
//		return "�Բ���,��۫���Ѿ�����������!\n";	
//	if(ziyingjian == present("ziying sword",me) && doublesword == present("ziqing shuangsword",me))
//	if ( present("ziying sword",me) || present("ziqing shuangsword",me) )
//                return "�������ڲ�������һ�����˿ɲ���̫̰�İ���\n";
	if( !me->query_temp("ask_ziying") ) 
	{
		command("consider");
		command("say ҥ��ѽ������㶼���ţ�");
		command("bug1");
		me->set_temp("ask_ziying","tang1");
		return 1;
	}
	else if( me->query_temp("ask_ziying") == "laojun2" ) 
	{
		command("say ̫���Ͼ�������ȥ����");
		message_vision("��̫����˻���ߵش����е���������ͷ����ͷ��أ�����ʮ����������һ���ú���\n", me);
//		me->set_temp("ask_ziying","tang2");
		return 1;
	}
	command("say ���������");
	message_vision ("��̫����Щ��������.\n",me);
	command("say ���ɻ������");
//	me->set("enter", 1);
        message_vision ("��ξͶ���л�����ˡ�����\n",me);
        return 1;
}

