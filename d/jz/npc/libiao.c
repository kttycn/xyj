//Cracked by Roath

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���", ({"li biao","libiao","li"}));
        set("gender", "����");
        set("age", 38);
        set("title","����֪ү");
        set("long","һ����ǿ��׳�����ˣ���ô��Ҳ����֪ү��");
        set("attitude", "friendly");
        set("per", 10);
        set("str", 40);
        set("combat_exp",50000);
	set("daoxing",50000);		
        set("max_force",1000);
        set("force",1000);
        set("force_factor",40);
        set("max_kee",300);
        set("max_sen",300);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("dodge",70);
        set_skill("changquan",80);
        map_skill("unarmed","changqaun");
        map_skill("parry","houquan");

        setup();
}

void die ()
{
	unconcious ();
}

void unconcious ()
{
	object ob, me = this_object();

	if(objectp(ob = query_temp("last_damage_from") ))
		ob->set_temp("obstacle/jz_libiao_killed",1);
	::die();
}

void kill_ob (object ob)
{
	object me = this_object();

	set_temp("my_killer",ob);
	::kill_ob(ob);
}
