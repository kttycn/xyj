//Cracked by Roath

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("刘洪", ({"liu hong","liuhong","liu"}));
        set("gender", "男性");
        set("age", 38);
        set("title","江州知府");
        set("long","一个看起来让人很不舒服的知府。");
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
        set_skill("sanqing-jian",80);
        set_skill("dodge",100);
      set_skill("changquan",100);
        map_skill("unarmed","changquan");
        map_skill("parry","sanqing-jian");
        map_skill("sword","sanqing-jian");
        seteuid(getuid());        

        set("inquiry", ([
                "陈光蕊": (: kill_ob(this_player()) :),
                "殷温娇": "她是我的结发妻子",
                ])),
        setup();

        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/cloth/jinpao")->wear();
}

void die ()
{
	unconcious ();
}

void unconcious ()
{
	object ob, me = this_object();

	if(objectp(ob = query_temp("last_damage_from") ))
		ob->set_temp("obstacle/jz_liuhong_killed",1);
	::die();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
