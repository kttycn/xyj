// guanjia.c
// 9-2-97 pickle
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string expell_me(object me);
void create()
{
	set_name("����", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
	set("gender", "Ů��");
	set("age", 23);
	set("long",
"�������޵׶��Ĵ�ܼҡ��뵱����������һ�����ɳ������Σ�\n"
"��������̫��������վ����������չ��ŵ���Ľ��飬����\n"
"�����������ⶴ�Ĺܼҡ�\n");
	set("title", "��ܼ�");
	set("cor", 25);
	set("combat_exp", 200000);
	set("daoxing", 400000);

	set("attitude", "heroic");
	create_family("�ݿ�ɽ�޵׶�", 2, "����");
	set_skill("literate", 50);
	set_skill("unarmed", 90);
	set_skill("parry", 90);
	set_skill("spells", 90);	
	set_skill("sword", 90);	
	set_skill("qixiu-jian", 90);
	set_skill("yinfeng-zhua", 90);
	set_skill("lingfu-steps", 90);
	set_skill("dodge", 90);
	set_skill("force", 90);
	set_skill("yaofa", 90);
	set_skill("huntian-qigong", 90);
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "yinfeng-zhua");
	map_skill("spells", "yaofa");
	map_skill("sword", "qixiu-jian");
	map_skill("parry", "qixiu-jian");
	map_skill("dodge", "lingfu-steps");
	
	set("str", 30);
	set("per", 30);
	set("max_kee", 800);
	set("max_sen", 800);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 75);
	set("mana", 3000);
	set("max_mana", 1500);
	set("mana_factor", 76);
	set("inquiry", ([
		"����": (: expell_me :),
		"leave": (: expell_me :),
		"name": "������������޵׶��Ĵ��ܹܣ�",
		"here": "��Ϲ��������������Ƕ����������ݿ�ɽ�޵׶���",
		"rumors": "��֪�����ұ�����ȥ��",
		"�������": "��Ϲ���������������ֲ��ǳ��ӣ�",
		"ְλ": (: rank_me :),
	]) );	
	setup();
	carry_object("/d/obj/weapon/blade/blade.c")->wield();
	carry_object("/d/obj/cloth/yuanxiang")->wear();
	carry_object("/d/obj/cloth/nichang")->wear();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "��ʥ����")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", BLU"�޵׶���"NOR+RED"��"BLU"�����"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", BLU"�޵׶���"NOR+RED"��"YEL"�������"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", BLU"�޵׶���"NOR+RED"��"RED"��������"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", BLU"�޵׶���"NOR+RED"��"MAG"�˱�����"NOR);
		} else {
			me->set("nick", BLU"�޵׶���"NOR+RED"��"CYN"ǧ����ʥ"NOR);
		}

		tell_object(me, "���󾫶���˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"���󾫶�"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

int attempt_apprentice(object me)
{
	string myname=RANK_D->query_rude(me);
	string myid=me->query("id");
	command("look "+myid);
	command("consider");
	if (me->query("combat_exp")+me->query("daoxing")>400000)
	{
		command("say "+myname+"����ʲô�������������λ�ӣ�\n");
		return 1;
	}
	if (me->query("wudidong/sell_reward")<1000)
	{
		command("say "+myname+"Ҫ�����޵׶������Ἰ����ͷ��Т���ң�\n");
		return 1;
	}
	command("grin");
	command("say ���������������ˡ�"+myname+"�����˶������Ū��ԭ�ϣ�");
	command("recruit "+myid);
	return 1;
}
int prevent_learn(object me, string skill)
{
	string myname=RANK_D->query_rude(me);

}
string expell_me(object me)
{
	me=this_player();

	if((string)me->query("family/family_name")=="�ݿ�ɽ�޵׶�")
	{
		me->set_temp("wudidong/betray", 1);
		return ("ʲô����Ҫ�뿪������ͱ������ͷ���(jieshou)\n");
	}
	return ("�����������ģ�����\n");
}
void init()
{
		add_action("do_accept", "jieshou");
}
int do_accept(string arg)
{
		object me=this_player();
		if (arg) return notify_fail("��Ҫ��ʲô��\n");
		if (!me->query_temp("wudidong/betray")) return notify_fail("��Ҫ����ʲô��\n");
		message_vision("$N����������Ҫ�뿪�޵׶�������ѣ�\n", me);
		message_vision("���������ˣ�������ˣ��������޵׶���\n", this_player());
		me->add("betray/count", 1);
		me->add("betray/wudidong", 1);
		if (me->query_skill("yaofa"))
				me->delete_skill("yaofa");
		if (me->query_skill("huntian-qigong"))
				me->delete_skill("huntian-qigong");
		if (me->query_skill("qixiu-jian"))
				me->delete_skill("qixiu-jian");
		me->delete("family");
		me->delete("class");
		me->delete("faith");
		me->delete("family_wp");
		me->set("title", "��ͨ����");
		me->set("combat_exp", me->query("combat_exp")*80/100);
		me->set("daoxing", me->query("daoxing")*80/100);
		if( (int)me->query("score") < 1000 )
			me->set("score", 0);
		else
			me->add("score", -1000 );
		me->save();
		message_vision("����һ����$N��ȥ��$N��ͬһ�������򶫷�ȥ������\n", this_player());
		this_player()->move("/d/city/kezhan");
		tell_room( environment(this_player()),"�������������¼����죬���¸�������\n", ({this_player()}));
		this_player()->unconcious();		
		return 1;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob))
	{
		ob->set("class", "yaomo");
	}
}
