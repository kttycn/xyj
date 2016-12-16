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
	set_name(HIC"���ʿ"NOR, ({"zui daoshi", "daoshi", "zui", "master"}));
	set("title", "�ƽ���");   
	set("long", "������š��ƽ��ɡ������ٲ���������������ɽ��֮�ϣ���������
��ͷ����֮�С�\n");
	set("gender", "����");
	set("age", 58);
	create_family("��ɽ����", 2, "����");
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
		"��ɽ" : (: expell_me :),
		"leave" : (: expell_me :),
		"ȥ������"  : (: ask_me :),
		"����"     : (: ask_jiu :),
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
	if( (string)ob->query("family/family_name")=="��ɽ����") {
		if ((int)ob->query("daoxing") < 300000 ) {
  			command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ�����С�\n");
			return;
		}
		if( (int)ob->query_skill("taoism", 1) < 120 ) {
			command("say ��λ" + RANK_D->query_respect(ob) + "�����ʦ�ɷ����������,�㻹����׷�����������Ű�!\n");
			command("sigh");
			return;
		}
        if ((int)ob->query_int() < 30) 
        {
			command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ����ɽ�����书��");
			return;
        }
		command("haha");
		command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "��ɽ���ɾƽ��ɵ���");
	} 
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="��ɽ����") {
		me->set_temp("betray", 1);
		return ("�����Ҫ�뿪��?��Ҫ����һЩ����,���Ը��(agree)?");
	}
	return ("��֪��");
}

void init()
{
	::init();
	add_action("do_agree", "agree");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N���������Ը�⡣\n\n", this_player());
		command("sigh");
		command("say �����ȥ�ɡ����������������⣡");
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
		message_vision(HIC"�ƽ���"NOR"��$N��ͷ������һ�£�$N��ʱ����������ʧ��\n\n", this_player());
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "��ͨ����");
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
	if(ob->query("family/family_name") != "��ɽ����")
	{
		command("say ���ֲ�����ɽ���ɵģ�˭���㣡");
		return 1;
	}
	if(ob->query("family/master_name")!= this_object()->query("name"))
	{
		command("say ���ֲ����ҵ�ͽ�ܣ�˭���㣡");
		return 1;
	}
	command("sigh");
	if(ob->query("combat_exp",1)< 500000)
		return notify_fail("��ĵ���̫�ͣ����ǲ�Ҫȥ�����ɣ�");
	if(ob->query_temp("shushan/ask_zuidao_go") )
		return notify_fail("�����ȥ�ɣ�");
	command("say �ðɣ�������������ס���ˣ���ȥ�ɣ�");
	if(!ob->query("shushan/jiushen_cast"))
	{
		ob->set("shushan/jiushen_cast",1);
		command("say ��һ�о�����ΪʦΨһ�ܸ���ģ��������κη������Ӧ�ÿ��԰��㱣���ģ�");
	}
	ob->set_temp("shushan/ask_zuidao_go", 1);
	return 1;
}

int ask_jiu()
{
	object ob=this_player();
	if(ob->query("family/family_name") != "��ɽ����")
	{
		command("say ���ֲ�����ɽ���ɵģ�ѧ����ʲô?");
		return 1;
	}
    if(ob->query("shushan/jiushen_cast"))
    { 
		command("say �㲻���ʹ�����? ");
		return 1;
    }
    if(ob->query("family/master_name") == HIC"���ʿ"NOR )
	{
		ob->set("shushan/jiushen_cast",1);
		command("say ��һ�о�����ΪʦΨһ�ܸ���ģ��������κη������Ӧ�ÿ��԰��㱣���ģ�");
		return 1;
	}
}
