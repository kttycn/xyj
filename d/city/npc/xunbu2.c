//xunbu1.c Ѳ��
//9/24/2000 BY ���(WFoxd)

inherit NPC;

void create()
{
	set_name("�߼�Ѳ��", ({ "xun bu", "bu" }));
	set("gender", "����");
	set("age", 35);
	set("shen_type", 1);
	set("family/family_name", "��ɽ����");
	set("str", 29);
	set("int", 28);
	set("con", 28);
	set("cor", 27);
	
	 set("force", 10000); 	 
	 set("max_force", 10000);
	 set("force_factor", 250);
	set_skill("force", 185);
	set_skill("zixia-shengong", 185);
	set_skill("dodge", 185);
	set_skill("seven-steps", 185);
	set_skill("spells", 190);
	set_skill("taoism", 190);
	set_skill("parry", 185);
	set_skill("sword", 185);
	set_skill("shushan-jianfa", 185);
	set_skill("unarmed", 185);
	set_skill("hunyuan-zhang", 185);

	map_skill("force", "zixia-shengong");
	map_skill("dodge", "seven-steps");
	map_skill("spells", "taoism");
	map_skill("parry", "shushan-jianfa");
	map_skill("sword", "shushan-jianfa");
	map_skill("unarmed", "hunyuan-zhang");
        set_temp("apply/attack", 300);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 400);
        set_temp("apply/damage", 600);
	set("chat_msg_combat", ({
		(: perform_action, "sword","duanshui" :),
		(: cast_spell, "jianshen" :),
		(: cast_spell, "fu" :),
	}) );

	setup();

	carry_object("/d/obj/cloth/cloth")->wear();
	carry_object("/d/obj/weapon/sword/bijian")->wield();
}
	
void kill_ob(object ob) 
{
 	int max_skill;

	if(query("killing"))  
		 {:: kill_ob(ob);
		  return;
	        }
	set("killing",ob);

	set("max_kee",ob->query("max_kee") + 1000); 
	set("max_sen",ob->query("max_sen") + 1000);
	set("max_force",ob->query("max_force"));
	set("force_factor",ob->query("force_factor"));
	set("combat_exp", ob->query("combat_exp") + 50000);
	set("daoxing", ob->query("daoxing") + 50000);
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


