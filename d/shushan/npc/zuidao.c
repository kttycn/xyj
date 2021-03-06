//jiu jianxian-yushu 2000.10.24

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);
string houshan_me(object me);
int ask_me();
int ask_jiu();

void create()
{
	set_name(HIC"醉道士"NOR, ({"zui daoshi", "daoshi", "zui", "master"}));
	set("title", "酒剑仙");   
	set("long", "人送外号“酒剑仙”，行踪不定，或游历于名山大川之畔，或隐匿于
街头闹市之中。\n");
	set("gender", "男性");
	set("age", 58);
	create_family("蜀山剑派", 2, "弟子");
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("str", 30);
	set("int", 30);
	set("per", 20);
	set("con", 30);
	set("combat_exp", 800000);
	set("daoxing", 800000);
	set("max_kee", 1700);
	set("max_sen", 1700);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 120);
	set("max_mana", 2000);
	set("mana", 4000);
	set("mana_factor", 120);
	set_skill("zixia-shengong", 160);
	set_skill("yujianshu", 160);
	set_skill("sword", 160);
	set_skill("yiruwhip", 160);
	set_skill("dodge", 160);
	set_skill("literate", 150);
	set_skill("whip", 160);
	set_skill("force", 160);
	set_skill("parry", 160);
	set_skill("spells", 160);
	set_skill("taoism", 160);
	set_skill("seven-steps", 160);
	set_skill("unarmed", 150);
	set_skill("hunyuan-zhang", 150);
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("dodge", "seven-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
	map_skill("force", "zixia-shengong");
	map_skill("spells", "taoism");
	set("inquiry", ([
		"下山" : (: expell_me :),
		"leave" : (: expell_me :),
		"去镇妖塔"  : (: ask_me :),
		"酒神"     : (: ask_jiu :),
	]) );

	setup();
	carry_object("d/obj/cloth/linen")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
	carry_object("d/qujing/tianzhu/obj/jiuhu");
	carry_object("d/qujing/tianzhu/obj/jiuzhong");
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	if( (string)ob->query("family/family_name")=="蜀山剑派") {
		if ((int)ob->query("daoxing") < 300000 ) {
  			command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力才行。\n");
			return;
		}
		if( (int)ob->query_skill("taoism", 1) < 120 ) {
			command("say 这位" + RANK_D->query_respect(ob) + "你的天师仙法还不到火候,你还是找追云子他们练着吧!\n");
			command("sigh");
			return;
		}
        if ((int)ob->query_int() < 30) 
        {
			command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我蜀山剑派武功？");
			return;
        }
		command("haha");
		command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
		command("recruit " + ob->query("id") );
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
		ob->set("title", "蜀山剑派酒剑仙弟子");
	} 
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="蜀山剑派") {
		me->set_temp("betray", 1);
		return ("你真的要离开吗?你要付出一些代价,你可愿意(agree)?");
	}
	return ("不知。");
}

void init()
{
	::init();
	add_action("do_agree", "agree");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N答道：弟子愿意。\n\n", this_player());
		command("sigh");
		command("say 那你便去吧。。。或者这是天意！");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/shushan", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("taoism") )
			this_player()->delete_skill("taoism");
		if( this_player()->query_skill("yujianshu"))
			this_player()->delete_skill("yujianshu");
		if( this_player()->query_skill("zixia-shengong"))
			this_player()->delete_skill("zixia-shengong");
		if( this_player()->query("shushan"))
			this_player()->delete("shushan");
		message_vision(HIC"酒剑仙"NOR"在$N的头上怕了一下，$N顿时觉得若有所失。\n\n", this_player());
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "普通百姓");
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->save();
		return 1;
	}
	return 0;
}

int ask_me()
{
	object ob=this_player();
	if(ob->query("family/family_name") != "蜀山剑派")
	{
		command("say 你又不是蜀山剑派的，谁管你！");
		return 1;
	}
	if(ob->query("family/master_name")!= this_object()->query("name"))
	{
		command("say 你又不是我的徒弟，谁管你！");
		return 1;
	}
	command("sigh");
	if(ob->query("combat_exp",1)< 500000)
		return notify_fail("你的道行太低，还是不要去送死吧！");
	if(ob->query_temp("shushan/ask_zuidao_go") )
		return notify_fail("你这就去吧！");
	command("say 好吧，看来我是拦不住你了，你去吧！");
	if(!ob->query("shushan/jiushen_cast"))
	{
		ob->set("shushan/jiushen_cast",1);
		command("say 这一招酒神，是为师唯一能给你的，绝不比任何法术差！它应该可以帮你保命的！");
	}
	ob->set_temp("shushan/ask_zuidao_go", 1);
	return 1;
}

int ask_jiu()
{
	object ob=this_player();
	if(ob->query("family/family_name") != "蜀山剑派")
	{
		command("say 你又不是蜀山剑派的，学它做什么?");
		return 1;
	}
    if(ob->query("shushan/jiushen_cast"))
    { 
		command("say 你不是问过了吗? ");
		return 1;
    }
    if(ob->query("family/master_name") == HIC"醉道士"NOR )
	{
		ob->set("shushan/jiushen_cast",1);
		command("say 这一招酒神，是为师唯一能给你的，绝不比任何法术差！它应该可以帮你保命的！");
		return 1;
	}
}
