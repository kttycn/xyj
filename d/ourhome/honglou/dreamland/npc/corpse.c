// qianmian guai
// mon 8/7/97

inherit NPC;

int fresh=1;
int MAX_MANA=4000, SPELLS=200, DAOXING=300000, EXP=500000;
int doing_kill=0;

void copy_status(object me, object ob);
void copy_weapon(object me, object ob);
void to_kill(object tar);

void create()
{
	set_name("��ʬ", ({ "jiang shi", "corpse" }) );
	set("gender", "����" );
	set("age", 340);
	set("long", "һֻ�������������\n");
	set("attitude", "aggressive");

	set("chat_chance", 3);

	set("str", 40);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_kee", 1000);
	set("max_gin", 1000);
	set("max_sen", 1000);
	set("max_force", 1000);
	set("max_mana", MAX_MANA);
	set("mana", MAX_MANA);

	set("daoxing", DAOXING);
	set("combat_exp", EXP);

	set_skill("spells",SPELLS);
	set_skill("force", 140); 
	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);

	setup();
	carry_object("/d/obj/weapon/blade/blade")->wield();
}

void init()
{
	object me=this_object(), tar=this_player();

	::init();
   
	if( tar )
		call_out("to_kill", 2);
}

void to_kill(object tar)
{
	if(doing_kill) return;
	if(!tar || environment(tar)!=environment()) return;

	if(tar->query("daoxing")>1000000)
		copy_status(this_object(), tar);
	else
		copy_status(this_object(), tar);
	doing_kill=1;

	message_vision("$N��$n˵����ɱ�˳�����Ƿծ��Ǯ������"+
	RANK_D->query_rude(tar)+"�������ɣ�\n", this_object(), tar);
	if(tar->query("daoxing")>20000)
		command("follow "+tar->parse_command_id_list()[0]);
	this_object()->kill_ob(tar);
	tar->kill_ob(this_object());
}

void kill_ob(object ob)
{
   object me=this_object();

   if(!doing_kill) 
       copy_status(me,ob);
   ::kill_ob(ob);
}

void copy_status(object me, object ob)
{
	mapping hp_status, skill_status, map_status;
	string *sname, *mname;
	int i,j;

// delete old skills.
	if(skill_status = me->query_skills()) {
		sname  = keys(skill_status);
		j=sizeof(skill_status);
		for(i=0; i<j; i++) {
			me->delete_skill(sname[i]);
		}
	}

//copy new skills.
	if (skill_status = ob->query_skills() ) {
		sname  = keys(skill_status);
		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]+random(skill_status[sname[i]]/50));
		}
	}
	
//delete old skill mappings.
	if(map_status = me->query_skill_map()) {
		mname  = keys(map_status);
		j=sizeof(map_status);
		for(i=0; i<j; i++) {
			me->map_skill(mname[i]);
		}
	}

//add new skill mappings.
	if (map_status = ob->query_skill_map()) {
		mname  = keys(map_status);
		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}

	me->set("chat_chance_combat",10);
	me->set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :),
		(: cast_spell, "yinshen" :),
		(: cast_spell, "light" :),
		(: cast_spell, "fenshen" :),
		(: cast_spell, "dingshen" :),
		(: cast_spell, "invocation" :),
		(: cast_spell, "thunder" :),
		(: cast_spell, "arrow" :),
		(: cast_spell, "mihun" :),
		(: cast_spell, "curse" :),
		(: cast_spell, "infreno" :),
		(: cast_spell, "heiwu" :),
		(: cast_spell, "hunfei" :),
		(: cast_spell, "freez" :),
		(: cast_spell, "water" :),
		(: cast_spell, "dragonfire" :),
		(: cast_spell, "hufa" :),
		(: cast_spell, "miwu" :),
		(: cast_spell, "huanying" :),
		(: cast_spell, "tudun" :),
		(: cast_spell, "suliao" :),
		(: cast_spell, "jushu" :),
		(: cast_spell, "bite" :),
		(: cast_spell, "bianfu" :),
		(: cast_spell, "sanmei" :),
		(: cast_spell, "zhuang" :),
		(: cast_spell, "juanbi" :),
		(: cast_spell, "tuntian" :),
		(: cast_spell, "zhenhuo" :),
		(: cast_spell, "qiankun" :),
		(: cast_spell, "escape" :),
		(: cast_spell, "fu" :),
		(: cast_spell, "jianshen" :),
		(: cast_spell, "wind" :),
		(: cast_spell, "rain" :),
		(: cast_spell, "tuoqiao" :),
		(: cast_spell, "jieti" :)
	}) );//�����Ѷ�

	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]);
	me->set("int", hp_status["int"]);
	me->set("con", hp_status["con"]);
	me->set("cps", hp_status["cps"]);
	me->set("cor", hp_status["cor"]);
	me->set("spi", hp_status["spi"]);
	me->set("per", hp_status["per"]);
	me->set("kar", hp_status["kar"]);
 
	me->set("max_mana", hp_status["maximum_mana"]);
	me->set("mana", hp_status["maximum_mana"]*2);
	me->set("mana_factor", hp_status["mana_factor"]);
	me->set("max_force", hp_status["maximum_force"]);
	me->set("force", hp_status["maximum_force"]*2);
	me->set("force_factor", hp_status["force_factor"]);
	me->set("max_kee", hp_status["max_kee"]);
	me->set("max_gin", hp_status["max_gin"]);
	me->set("max_sen", hp_status["max_sen"]);
	me->set("eff_kee", hp_status["max_kee"]);
	me->set("eff_gin", hp_status["max_gin"]);
	me->set("eff_sen", hp_status["max_sen"]);
	me->set("kee", hp_status["max_kee"]);
	me->set("gin", hp_status["max_gin"]);
	me->set("sen", hp_status["max_sen"]);
	me->set("bellicosity", hp_status["bellicosity"]);

	me->set("eff_dx", me->query("daoxing"));
	if(COMBAT_D->check_family(ob->query("family/family_name"))>0)
		me->set("eff_dx", -me->query("eff_dx"));

	if( ob->query("family/family_name") )
		me->set("family/family_name", ob->query("family/family_name"));
	if(me->query("daoxing")>10000)
		me->set("nkgain",150); //maximum gain for killing qm.

	me->set("daoxing",hp_status["daoxing"] + hp_status["daoxing"]/50);
	me->set("combat_exp",hp_status["combat_exp"] + hp_status["combat_exp"]/50);

	copy_weapon(me, ob);//����װ��
	return ;
}

void copy_weapon(object me, object ob)
{
	object *inv;
	int i,j, weapon_cnt, armor_cnt;
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) 
	{
		destruct(inv[i]);
	}
	// save once here, an external bug might stop the following
	me->setup();
	me->save();
	weapon_cnt = 0;
	armor_cnt = 0;
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) 
	{
		if ( !inv[i]->query_unique() && 
		inv[i]->query("skill_type") &&
		inv[i]->query("equipped") && !weapon_cnt ) 
		{
			object obj = new(base_name(inv[i]));
			if (obj)
			{
				if(obj->move(me)) // mon 8/13/97
				obj->wield();
			}
			me->set("weapon", base_name(inv[i]));
			weapon_cnt = 1;
		}
		else if ( !inv[i]->query_unique() && 
		!inv[i]->query("skill_type") && 
		inv[i]->query("equipped") && !armor_cnt ) 
		{
			object obj = new(base_name(inv[i]));
			if (obj)
			{
				if(obj->move(me))
				obj->wear();	//mon 8/13/97
			}
			me->set("armor", base_name(inv[i]));
			armor_cnt = 1;
		}
		else if( weapon_cnt && armor_cnt )
		break;
	}
}

void unconcious()
{
   die();
}

void die()
{
	object killer, *inv;
	int i;

	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer,this_object());
		killer->set_temp("kill_qingsuo_corpse",1);
	}
	inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) 
	{
		destruct(inv[i]);
	}
	::die();
}
