inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
	set_name("ǧ������", ({ "shu yao", "yao" }) );
	set("gender", "����");
	set("age", 1500);
	set("long","����һ�����˾���������������ͷ���¶��\n");
	set("str", 48);
	set("cor", 52);
	set("cps", 22);
	set("max_kee", 15000);
	set("max_gin", 10000);
	set("max_sen", 10000);
	set("force",2500);
	set("max_force",2500);
	set("mana",2500);
	set("max_mana",2500);
	set("force_factor",10);
	set_skill("parry",150);
	set_skill("dodge",70);
	set_skill("lotusmove",70);
	set_skill("unarmed",200);
	set_skill("cuixin-zhang",150);
	map_skill("unarmed","cuixin-zhang");
	map_skill("parry","cuixi-zhang");
	map_skill("dodge","lotusmove");
	set("attitude", "aggressive");
	set("combat_exp", 2000000+random(2000000));
	setup();
	carry_object("/obj/money/gold")->set_amount(20);
}

void die()
{
	int i;
	object me, fengzhu;
	string fengzhu_given,shengzhu_given;
	fengzhu_given = "/d/obj/baowu/fengzhu.c";
//	shengzhu_given = "/d/obj/baowu/shengzhu.c";
	if(objectp(me = query_temp("last_damage_from") ))
	{
		if ( (!fengzhu_given->in_mud()) ) {
			message_vision("$Nͷ��ð��һ����ɫ�����ӣ�$n��æһ��ץ�����\n",this_object(),me);
			fengzhu = new("/d/obj/baowu/fengzhu");
			fengzhu->move(me);
			MONITOR_D->report_rumor_object_msg(me, "�õ��������ˣ�");
		}
	}
	::die();
}
