//xunbu3.c Ѳ��
//9/24/2000 BY ���(WFoxd)

inherit NPC;

void create()
{
	set_name("����Ѳ��", ({ "xun bu", "bu" }));
	set("gender", "����");
	set("age", 55);
	set("shen_type", 1);
	
	set("str", 34);
	set("int", 35);
	set("con", 34);
	set("cor", 38);
	
	 set("force", 18000); 	 
	 set("max_force", 18000);
	 set("force_factor", 350);
   set_skill("dodge", 250);
   set_skill("parry", 250);
   set_skill("force", 250);
   set_skill("spells", 250);
   set_skill("unarmed", 250);
   set_skill("staff", 250);

   set_skill("buddhism", 250);
   set_skill("jienan-zhi", 250);
   set_skill("lotusmove", 250);
   set_skill("lotusforce", 250);
   set_skill("lunhui-zhang", 250);

   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");

        set_temp("apply/attack", 300);
        set_temp("apply/defense", 600);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
	set("chat_msg_combat", ({
		(: perform_action, "staff","diyu" :),
		(: cast_spell, "bighammer" :),
	}) );
        
	setup();

	carry_object("/d/obj/cloth/cloth")->wear();
	carry_object("/d/obj/weapon/staff/tieguai")->wield();
}
	
void kill_ob(object ob) 
{
 
 	int max_skill;

	if(query("killing"))  
		 {:: kill_ob(ob);
		  return;
	        }
	set("killing",ob);

	set("max_kee",ob->query("max_kee") + 1500); 
	set("max_sen",ob->query("max_sen") + 1500);
	set("max_force",ob->query("max_force"));
	set("force_factor",ob->query("force_factor"));
	set("combat_exp", ob->query("combat_exp") + 200000);
	set("daoxing", ob->query("daoxing") + 200000);
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
