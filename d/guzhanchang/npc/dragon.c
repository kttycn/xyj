#include <ansi.h>
inherit NPC;
int big_blowing();
void create()
{
	set_name("ǧ�����", ({"chi jiao","jiao"}));
	set("long", "����һ��ȫ����ĳ��ԡ�ֻ��ͷ����
����������ͷ������ͭ�壬ͷ����ȴ��
��һֻ���߶೤����������Ķ��ǣ���
����ף����������絶��������ȴ����
ϸ�ֳ���    
\n");
	set("race", "Ұ��");
	set("age", 2943);
	set("attitude", "aggressive");
	set("per", 9);
	set("max_kee", 15000);
	set("max_gin", 6000);
	set("max_sen", 15000);
	set("max_mana", 6000);
	set("max_force", 5500);
	set("force", 12000);
	set("mana", 12000);
	set("force_factor", 140);
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
	message_vision( HIR "\n\n$N��Ȼһ�����ȫ��ɢ�����������棬��ʱ��Χ���±�������ޱȣ�\n
\n" NOR,this_object());
	call_out("hurting",random(10)+2);
	return 1;
}
int hurting()
{
	int i;
	int dam;
	object *inv;
	message_vision( HIR "\n\n$N������һ���������һ�����棬�������˵��������������ܣ���\n\n",this_object());
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


void die()
{
	int i;
	object me, jiaosword;
	string jiaosword_given;
	jiaosword_given = "/d/guzhanchang/obj/jiaosword";
	if(objectp(me = query_temp("last_damage_from") ))
	{
		if ( (!jiaosword_given->in_mud()) ) 
		{	
			message_vision("$n�ȵ��������ϻ����ֳ�ԭ�Ρ���\nһ����������$N��Ϊһ�����ɫ�Ľ����ɵ�$n�����С�\n",this_object(),me);
			jiaosword = new("/d/guzhanchang/obj/jiaosword");
			jiaosword->move(me);
			MONITOR_D->report_rumor_object_msg(me, "�õ����Խ��ˣ�");
			destruct(this_object());
			return;
		} else { 
		message_vision ("$N"HIY"����һ����⣬��ʧ��......\n"NOR,this_object());
		destruct (this_object());
		return;
			}
	}	
	return;
}

