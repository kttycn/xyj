inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("gender", "����");
	set("class","bonze");
	set("family/family_name","�Ϻ�����ɽ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("staff", j+random(5));
	me->set_skill("lunhui-zhang", j+random(5));
	me->set_skill("lotusmove", j+random(5));
	me->set_skill("buddhism", j+random(5));
	me->set_skill("jienan-zhi", j+random(5));
	me->set_skill("lotusforce", j+random(5));

	me->map_skill("force", "lotusforce");
	me->map_skill("staff", "lunhui-zhang");
	me->map_skill("parry", "lunhui-zhang");
	me->map_skill("spells", "buddhism");
	me->map_skill("dodge", "lotusmove");
	me->map_skill("unarmed", "jienan-zhi");

    exp=query("combat_exp");
    if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: cast_spell, "bighammer" :),
			(: perform_action, "staff.shenlong" :),
		}) );

		if(exp<1000000){
			weapon=new("/d/obj/weapon/staff/muzhang");
			set("weapon_","/d/obj/weapon/staff/muzhang");
		}else{
			weapon=new("/d/obj/weapon/staff/budd_staff");
			set("weapon_","/d/obj/weapon/staff/budd_staff");
		}
		weapon->move(me);
		command("wield all");
	}
}
