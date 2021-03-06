// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//fo.c
inherit NPC;
inherit F_MASTER;
string expell_me(object me); 
int ask_me(); 
int ask_master();
void create()
{
	set_name("小张太子", ({"prince zhang", "zhang", "prince"}));
	set("long", "小张太子是大圣国师王菩萨的得意弟子，年青有为，少年得志，乃是一
英俊少年也。\n");
	set("gender", "男性");
	set("title", "小太子");
	set("class", "xian");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "太子");
	set("per", 30);
	set("int", 30);
	set("str", 30);
	set("cps", 30);
	set("max_kee", 1500);
	set("max_gin", 1500);
	set("max_sen", 1200);
	set("force", 1300);
	set("max_force", 1300);
	set("force_factor", 65);
	set("max_mana", 1200);
	set("mana", 2400);
	set("mana_factor", 60);
	set("combat_exp", 800000);

	set("eff_dx", 250000);
	set("nkgain", 400);

	set_skill("literate", 90);
	set_skill("unarmed", 120); 
	set_skill("lianhuan-tui", 120);
	set_skill("tianwei-shi", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("halberd", 120); 
	set_skill("fumozhou", 120);
	set_skill("guiyuanforce", 120);
	set_skill("tianlong-halberd", 120);
	set_skill("spells", 120);
	set_skill("force", 120);
	map_skill("unarmed", "lianhuan-tui");
	map_skill("parry", "tianlong-halberd"); 
	map_skill("halberd", "tianlong-halberd");
	map_skill("spells", "fumozhou");
	map_skill("force", "guiyuanforce");
	map_skill("dodge", "tianwei-shi");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: cast_spell, "sword" :),
		(: cast_spell, "sixiang" :)
	}) );

	set("inquiry", ([
		"下山": (: expell_me :),
		"leave": (: expell_me :), 
		"水猿大圣": (: ask_me :), 
		"大圣国师王菩萨": (: ask_master :), 
		"国师王菩萨": (: ask_master :),
		"师傅": (: ask_master :),
		"master": (: ask_master :),
	]) );

	create_family("盱眙山", 2, "弟子");
	setup();

	 carry_object("/d/obj/cloth/mangpao")->wear();
	 carry_object("/d/obj/weapon/halberd/chubai")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="盱眙山") {
		if (((int)ob->query("combat_exp") < 100000 )) {
			command("say 你的修行还差点吧，" + RANK_D->query_respect(ob) + "还需多加努力才是。\n");
			return;
		}
		command("smile");
		command("say 好极，好极，我派又添"  + RANK_D->query_respect(ob) +
"这样的英侠之士，实在是我门派的喜事！\n");
		command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，为了盱眙山加油吧。\n");
		command("recruit " + ob->query("id") );
		return;
	} 
	if (!(string)ob->query("family/family_name"))   {
		command("shake");  
		command("say " + RANK_D->query_respect(ob) + "，学艺不可越级，还是先去拜四大神将吧。\n");
		return;
	} 
	command("shake"); 
	command("say " + RANK_D->query_respect(ob) + "想加入我门吗？还是先退出其他门派再说吧！\n");  
	return;
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="盱眙山") {
		if (me->query("combat_exp")<200000) return ("你道行不够，不能下山。\n");
		if (me->query("jieshu")<50) return ("你劫数不够，不能下山。\n");
		command("say 你既是执意下山，本少爷也不留你，不过以后可不要怪我无情。");
		me->set_temp("betray", 1);
		command("say 你要下山，本少爷可要留下点东西才能走哦！");
		return ("你可愿意(agree)？");
	}
	return ("在这里闹什么闹。");
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
		this_player()->add("betray/count", 1);
		this_player()->add("jieshu", -50);
		this_player()->add("betray/xuyi", 1);
		command("say 既然你不想留在我门派，那就走吧！");
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if(this_player()->query_skill("fumozhou"))
			this_player()->delete_skill("fumozhou");
		if(this_player()->query_skill("guiyuanforce"))
			this_player()->delete_skill("guiyuanforce");
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "普通百姓"); 
		this_player()->set_temp("betray",0); 
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->save();
		command("say 居然有这样的人……\n");
		return 1;
	}
	return 0;
} 

int ask_me()
{ 
    object me, ob;
    me = this_player(); 
	if(me->query_temp("kill_yuan")){
	command("thank "+me->query("id"));
	command("say 多谢这位"+RANK_D->query_respect(me)+"，我这里有一块铜牌，用它便可去拜见家师，便送了你罢。");
	ob=new("/d/xuyi/obj/tongpai");
	ob->move(me);
     message_vision("小张太子招手叫来几个王府卫士，把$N送到了大圣禅寺前。\n",me);
	me->move("/d/xuyi/frontgate");
	me->set_temp("kill_yuan", 0);
	return 1;
	}
    command("say 这位"+RANK_D->query_respect(me)+"愿意去降伏水猿大圣，真是人民之福。");
    return 1;
}

int ask_master()
{ 
    object me, ob;
    me = this_player();  

      if (me->query("family/master_name") !="大圣国师王菩萨"){
    command("say 师父正为水猿大圣的事烦恼，不要去打扰他。");
	return 1;
	}
    command("nod");
    command("say 我差人送你去。");
     message_vision("小张太子招手叫来几个王府卫士，把$N送到了大圣禅寺前。\n",me);
	me->move("/d/xuyi/frontgate");
	return 1;
}

