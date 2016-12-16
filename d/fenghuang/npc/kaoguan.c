inherit NPC;
#include <ansi.h>;
int out_master();

void create()
{
	set_name("�Ϳ�ŵ", ({ "ji keluo", "ji" }) );
	set("title", "��˾�У������");
	set("gender", "����");
	set("age", 35);
	set("long","���Ƿ�˾�У�������٣�ѧԱҪ��ҵ�����������ء�\n");

	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "�̹�");
	set("per", 24);
	set("str", 26);
	set("int", 28);
	set("con", 30);

	set("max_kee", 800);
	set("max_gin", 300);
	set("max_sen", 800);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 1000);
	set("mana_factor", 50);
	set("daoxing", 300000);
	set("combat_exp", 400000);
	set("score", 0);

	set("inquiry", ([
		"��ҵ": (: out_master :),
	]) );
	set_skill("unarmed",50);
	set_skill("spells", 50);
	set_skill("yufeng-shu", 50);
	set_skill("force",60);
	set_skill("stick",50);
	set_skill("parry",50);
	set_skill("liedi-stick",50);
	set_skill("fenghuang-shenfa",50);
	set_skill("dodge",50);
	set_skill("tenglong-finger",50);
	set_skill("wuzu-xinfa",60);
	set_skill("spells", 50);
	set_skill("yufeng-shu", 50);
	map_skill("spells", "yufeng-shu");
	map_skill("unarmed","tenglong-finger");
	map_skill("force","wuzu-xinfa");
	map_skill("spells","yufeng-shu");
	map_skill("stick","liedi-stick");
	map_skill("parry","liedi-stick");
	map_skill("dodge","fenghuang-shenfa");

	create_family("�����", 4, "�̹�");
	setup();

	carry_object("/d/fenghuang/obj/ganggun")->wield();
	carry_object("/d/fenghuang/obj/beixin")->wear();
}

init()
{
	add_action("do_accept","accept");
}

int out_master()
{
	object ob, me;
	me = this_player();
	if (!(int)me->query("xmark/ѧԱ"))
	{
		tell_object(me,"���ٶ���˵���㲻�Ǳ�УѧԱ����Ҫ�����ҡ�\n");
		return 1;
	}

	tell_object(me,"���ٳ�����һ��,��"+me->query("name")+"˵��:Ҫ���ҵ,
	�����������(accept test).\n");
	me->set_temp("phoenix/test",1);
	return 1;
}
int do_accept(string arg)
{
	mapping guild;
	object ob, me, zheng;
	me = this_player();

	if( !me->query_temp("phoenix/test") )
		return 0;
	if( arg== "test" )
	{
		say("\n���ٵ��˵�ͷ��˵�����ܺã�С���ˡ������ǵ�һ��....\n\n");
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment()))
		{
			say("����̾�˿�����˵��������������һ�ж��Ų����������Բ�����....\n");
			return 1;
		}
		say("\n���ٺȵ����ڶ���....\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("����̾���������ӻ����ʦ,��.....\n");
			return 1;
		}
		say("\n���ٺȵ��������У���ע����!....\n\n");
		COMBAT_D->do_attack(this_object(), me,query_temp("weapon"));
		if( (int)me->query("kee") < 0
		|| !present(me, environment())) {
			say("����Ц�����㻹�ǻ�ȥ�����ϰ��.....\n");
			return 1;
		}
		if(zheng = present("xuesheng zheng", me))
			destruct(zheng);
		say("\n����΢Ц������ϲ,����Ա�ҵ�ˣ�������ı�ҵ֤���ú��ˡ�\n\n");
		me->set("title",HIM"��˳ǹ�����׼ξ"NOR);
		ob = new("/d/fenghuang/obj/zhengshu1");
		ob->move(me);
		me->delete("xmark/ѧԱ");
		me->set("bmark/��ҵ��", 1);
		return 1;
	}
	return 0;
}

void reset()
{
//        delete_temp("learned");
	set("apprentice_available", 3);
}

void attempt_apprentice(object ob)
{       
	if (!(int)ob->query_temp("bmark/ѧԱ"))
		command("say �㲻�Ƿ�˾�УѧԱ���Ҳ��������㣬�㻹�����ұ��˰ɡ�\n");
	else if (!(int)ob->query_temp("bmark/��ҵ"))
		command("say ���Ѿ��ӷ�˾�У��ҵ�ˣ�����ô�������ء�\n");
	else
	{
		command("say �ðɣ��������㡣\n");
		command("recruit "+ob->query("id"));
		return;
	}
	return;
}

int recruit_apprentice(object ob)
{
	string title = ob->query("title");
	
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", title);
	}
	return 0;
}
