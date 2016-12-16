// Changed by sjmao  09-11-97
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int rank_me();
string expell_me(object me);

void create()
{
	set_name("��Ů", ({"long nv","gongzhu","long","princess"}));
	set("long","���ƹ����ˣ�������Ů����\n");
	set("gender", "Ů��");
	set("age", 20);
	set("int", 25+random(5));
	set("title", "���ƹ���");
	set("attitude", "peaceful");
	set("combat_exp", 350000);
	set("daoxing", 100000);

	set("rank_info/respect", "��������");
	set("class","dragon");
	set("per", 30);
	set("max_kee", 900);
	set("max_sen", 700);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("max_mana", 500);
	set("mana", 400);
	set("mana_factor", 30);

	set_skill("literate", 90);
	set_skill("unarmed", 100);
	set_skill("dodge", 120);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("fork", 100);
	set_skill("spells", 100);
	set_skill("seashentong", 100);
	set_skill("dragonfight", 100);
	set_skill("dragonforce", 100);
	set_skill("dragon-cha", 100);
	set_skill("dragon-steps", 120);
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "dragon-cha");
	map_skill("parry", "dragon-cha");
	map_skill("dodge", "dragon-steps");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		  (: cast_spell, "hufa" :),
		  (: perform_action, "fork", "fengbo" :),
	}) );
	set("inquiry", ([
		"�빬": (: expell_me :),
		"ְλ": (: rank_me :),
		"leave": (: expell_me :),
	]));

	create_family("��������", 2, "ˮ��");
	setup();

	carry_object("/d/obj/cloth/pinkskirt")->wear();
	carry_object("/d/sea/obj/yincha")->wield();
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "��������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "��������"){
		if( exp <= 100000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 500000 ){
			me->set("nick", HIC"��������"NOR+RED"��"BLU"Ѳ��Ϻ��"NOR);
		} else if(exp <= 1000000 ){
			me->set("nick", HIC"��������"NOR+RED"��"YEL"Ѳ��ҹ��"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", HIC"��������"NOR+RED"��"RED"����ʹ��"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", HIC"��������"NOR+RED"��"MAG"�޵н���"NOR);
		} else {
			me->set("nick", HIC"��������"NOR+RED"��"CYN"��������"NOR);
		}

		tell_object(me, "��Ů����˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"��Ů��"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	 command("jump");
	command("say ���ֶ���һ������Ү��\n");
	 command("recruit " + ob->query("id") );
	 return;
}

int recruit_apprentice(object ob)
{
	 if( ::recruit_apprentice(ob) )
		  ob->set("class", "dragon");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="��������")
    {
      message_vision("���ƹ����ѹ�������$N��������ֹ��\n", me);
      return ("��ȥ���Ҹ����ɡ�\n");
    }
  return ("ȥ���ʱ��˰ɣ�����ô��֪�����\n");
}
�