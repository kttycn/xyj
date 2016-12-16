#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();

void create()
{
	set_name("�Ƽ�", ({ "huang ji", "huang" }));
	set("nickname", HIY "�޵�����" NOR);
	set("age", 25);
	set("title", HIW "��������" NOR);
	set("gender", "����");
	set("long", "�����������״����ӣ��Ʒ��˵ã��˳�����������\n");
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 24);
	set("str", 40);
	set("int", 25);
	set("con", 30);

	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 1000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 1800);
	set("mana", 3600);
	set("mana_factor", 80);
	set("daoxing", 3000000);
	set("combat_exp", 1400000);
	set("score", -7000);

	set_skill("literate", 100);
	set_skill("unarmed",140);
	set_skill("dodge", 110);
	set_skill("parry", 130);
	set_skill("force", 120);
	set_skill("wuzu-xinfa", 120);
	set_skill("fenghuang-shenfa", 110);
	set_skill("wudi-zhan",140);
	set_skill("spells", 120);
	set_skill("yufeng-shu", 120);
	map_skill("spells", "yufeng-shu");
	map_skill("unarmed","wudi-zhan");
	map_skill("parry", "wudi-zhan");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 80);
	create_family("�����",3,"��");

	set("inquiry", ([
		"ְλ": (: rank_me :),
	]) );

	setup();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "�����")
	     {
	       message_vision("�Ƽ�����$N���ͷ��΢΢Ц��Ц��\n",ob);
	       return;
	      }
 }

void attempt_apprentice(object ob)
{
	ob = this_player();
	if (!(int)this_player()->query("bmark/��ҵ��"))
		command("say �㻹��ȥ��˾�Уȥ����һ�°ɡ�\n");
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
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", HIC"��˳ǹ�������У"NOR);
	}
	return 0;
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "��������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "�����"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", HIR"��˴�˵"NOR+RED"��"BLU"�ػ�����"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", HIR"��˴�˵"NOR+RED"��"YEL"Խ�շɽ�"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIR"��˴�˵"NOR+RED"��"RED"��������"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIR"��˴�˵"NOR+RED"��"MAG"��ħ���"NOR);
		} else {
			me->set("nick", HIR"��˴�˵"NOR+RED"��"CYN"�������"NOR);
		}

		tell_object(me, "�Ƽ�����˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"�Ƽ���"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}
