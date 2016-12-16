//xunbu1.c Ѳ��
//9/24/2000 BY ���(WFoxd)

inherit NPC;

void create()
{
	set_name("һ��Ѳ��", ({ "xun bu", "bu" }));
	set("gender", "����");
	set("age", 25);
	set("str", 22);
	set("int", 22);
	set("con", 25);
	set("cor", 23);
	
	 set("force", 8000); 	 
	 set("max_force", 8000);
	 set("force_factor", 150);
	set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("blade", 140);
        set_skill("unarmed", 150);
        set_skill("spells", 150);
	set_skill("huntian-qigong", 150);
        set_skill("lingfu-steps", 150);
        set_skill("kugu-blade", 130);
        set_skill("yinfeng-zhua", 150);
        set_skill("yaofa",150);
        set_skill("qixiu-jian", 150);
        set_skill("sword", 150);

  map_skill("force", "huntian-qigong");
  map_skill("blade", "kugu-blade");
  map_skill("sword", "qixiu-jian");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("parry", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);

	set("chat_msg_combat", ({
		(: perform_action, "blade","diyu" :),
		(: perform_action, "blade","sword" :),
		(: cast_spell, "bite" :),
		(: cast_spell, "jushu" :),
	}) );
	setup();

	carry_object("/d/obj/cloth/cloth")->wear();
	carry_object("/d/obj/weapon/blade/blade")->wield();
}
	
void kill_ob(object ob) 
{
 
 	int max_skill;

	if(query("killing"))  
		 {:: kill_ob(ob);
		  return;
	        }
	set("killing",ob);

	set("max_kee",ob->query("max_kee") + 50); 
	set("max_sen",ob->query("max_sen") + 50);
	set("max_force",ob->query("max_force"));
	set("force_factor",ob->query("force_factor"));
	set("combat_exp", ob->query("combat_exp") + 10000);
	set("daoxing", ob->query("daoxing") + 10000);
//	reincarnate();
	
	set_leader(ob); 
	
	:: kill_ob(ob);
	call_out("check_status",3,ob); 
}

void check_status(object ob)
{
	if(!ob || ob->is_ghost()) {
		destruct(this_object());
		return; }  

	if(environment(ob)!=environment()) {
		this_object()->move(environment(ob));  
		message_vision("$N��Ȼ��һ�������������һ������"+ob->name()+"�������ܣ���",this_object());
		}

	remove_call_out("check_status");
	call_out("check_status",2,ob);
}