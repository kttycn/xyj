//【蜀山剑派】mhxy-yushu 2001/2
inherit NPC;
inherit F_MASTER;
int ask_back();
#include <ansi.h>
void create()
{
	set_name("静虚老祖", ({"master jingxu","jingxu", "master"}));
	set("title",HIC"蜀山剑派开山祖师"NOR);
	set("gender", "男性");
	set("age", 220);
	set("class", "swordsman");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "老师祖");
	set("per", 26);
	set("looking", "玉面光润，长髯下飘，双睛微睁，两道卧蚕眉直指鬓梢。");
	set("int", 30);

	set("max_kee", 5000);
	set("max_gin", 1000);
	set("max_sen", 5000);
	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 150);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 150);
	set("combat_exp", 3000000);
	set("daoxing", 8000000);

	set_skill("literate", 220);
	set_skill("dodge", 280);
	set_skill("parry", 290);
	set_skill("unarmed", 260);
	set_skill("hunyuan-zhang", 260); 
	set_skill("sword", 300);
	set_skill("yujianshu", 300);
	set_skill("spells", 270);
	set_skill("taoism", 270);
	set_skill("zixia-shengong", 290);
	set_skill("force", 300);
	set_skill("seven-steps", 280);
	set_skill("yiruwhip", 270);
	set_skill("whip", 270);
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("spells","taoism");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	map_skill("whip", "yiruwhip");
	map_skill("unarmed","hunyuan-zhang");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
		  (: perform_action, "sword", "fumo" :),
	 }) );
	 set("inquiry", ([
		   "回去" : (: ask_back :),
		   "back" : (: ask_back :),
	  ]) );
	 create_family("蜀山剑派", 1, "弟子");
	 setup();

	 carry_object("/d/obj/cloth/mangpao")->wear();
	 carry_object("/d/shushan/obj/shenxue")->wear();
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	if( (string)ob->query("family/family_name")=="蜀山剑派") {
		if ((int)ob->query("daoxing") < 1000000 
		&& (int)ob->query("combat_exp") < 1000000 ) {
		  	command("say 你的修行还不够，对我的招法难以领悟。\n");
			return;
		}
		if( (int)ob->query("betray/shushan")) {
			command("say 这位" + RANK_D->query_respect(ob) + "反复无常，老夫不原再收你为徒了！\n");
			command("sigh");
			return;
		}
		if( (int)ob->query_skill("taoism", 1) < 180 ) {
			command("say 这位" + RANK_D->query_respect(ob) + "你的天师仙法还不到火候,你还是找剑 圣他们练着吧!\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
		command("recruit " + ob->query("id") );
		ob->set("shushan/wanjian_perform",1);
		return;
	}
	command("shake");
	command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
	return;
}

int recruit_apprentice(object ob)
{
	 if( ::recruit_apprentice(ob) ) {
		  ob->set("class", "swordsman");
		  ob->set("title", "蜀山静虚老祖传人");

}

	 return 0;
}
int ask_back()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "蜀山剑派")
    {
	    command("say 你又不是蜀山剑派的，你问这个干吗！");
    	return 1;
    }
    if(ob->query("shushan/tuoqiao_cast"))
    { 
    	command("say 你不是知道了吗? ");
    	return 1;
    }
    if(ob->query("family/master_name") == "静虚老祖" )
    {
	    command("say 你想出去啊！好吧!我教你一招「金蝉脱壳」!");
    	command("say 用(cast tuoqiao)就能出去!");
    	command("say 下次进来时就不要那么麻烦了,去藏经阁(push 书架)就可以了。");
    	ob->set("shushan/tuoqiao_cast",1);
    	return 1;
    }
}
