#include <ansi.h>
inherit NPC;
int big_blowing();
void create()
{
	set_name("����", ({"shen long","dragon"}));
	set("long", "�����߽�������Ĺ�������ޱȡ�\n");
	set("age", 1783);
	set("attitude", "aggressive");
	set("per", 10);
	set("max_kee", 25000);
	set("max_gin", 4000);
	set("max_sen", 15000);
	set("max_mana", 6000);
	set("max_force", 6000);
	set("force", 12000);
	set("mana", 12000);
	set("force_factor", 120);
	set("mana_factor", 150);
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("chat_chance_combat", random(80));
	set("chat_msg_combat", ({
		(: big_blowing :)
	}) );

	set("combat_exp", 2000000+random(2000000));
	set("daoxing", 2000000+random(2000000));
	set_temp("apply/attack", 260+random(400));
	set_temp("apply/damage",200+random(200));
	set_temp("apply/armor", 540+random(500));
	setup();
}
int big_blowing()
{
	remove_call_out("hurting");
	message_vision( HIR "\n\n$N�����͵�һ�ţ�ȫ�����һ��Ƶĳ�죬ɢ�������˵�������
\n\n" NOR,this_object());
	call_out("hurting",random(10)+2);
	return 1;
}
int hurting()
{
	int i;
	int dam;
	object *inv;
	message_vision( HIR "\n\n$N�³�һ�ɻ��森��������Ҫ���ս��ˣ�����\n\n",this_object());
	inv = all_inventory(environment(this_object()));
	for(i=sizeof(inv)-1; i>=0; i--)
		if( living(inv[i]))
			if( inv[i] != this_object())
			{
				dam = random(300)+100 - inv[i]->query_temp("apply/armor_vs_spells");
				if(dam <0) dam = 0;
				inv[i]->receive_wound("kee",dam);
				COMBAT_D->report_status(inv[i],1);
			}
	return 1;
}

void unconcious()
{
	object killer,where,nvjing;

	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer,this_object());
		killer->set_temp("kill_ziying_dragon",1);
	}
	where = environment(killer);
//	::die();
	message_vision(RED"\n$N�ҽ�һ��,����ʬ����ȴվ����һ��Ϭţ����\n\n"NOR, this_object());
	if(!( nvjing = find_object("/d/huanggong/doublesword/npc/nvjing")) )
		nvjing = load_object("/d/huanggong/doublesword/npc/nvjing");
	if(objectp(nvjing))
		nvjing->move(where);
	load_object("/obj/empty");
	this_object()->move("/obj/empty");
	call_out ("destruct_me",3,this_object());
}

void destruct_me(object me)
{
	destruct(me);
}

void die()
{
	unconcious();
}
