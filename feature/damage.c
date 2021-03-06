// damage.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void remove_faint(object me);

int ghost = 0;

int is_ghost() { return ghost; }

int self_purge()
{
 	object me=this_object();
//	object link_ob = me->query_temp("link_ob");

	if( !userp(me) ) return 0;
	if ( (int)me->query("max_gin") > 0 &&
	(int)me->query("max_kee") > 0 &&
	(int)me->query("max_sen") > 0 ) return 0;
		set_heart_beat(0);
 	ghost =1;
 	me->move("/d/death/block.c");
 	CHANNEL_D->do_channel(me, "rumor", me->query("name")
 		+ "因为年纪太大，心力交瘁，不幸与世长辞，永远离开了我们！"); 
       return 1;
}

void gameover()
{
    object me = this_object();
	   
    //currently, only move the player to /d/death/block.c
    if( !userp(me) ) return;

    
    me->move("/d/death/block.c");
    if( !me->query("life/death_announced") )
    {
		me->set("life/death_announced", 1);
        CHANNEL_D->do_channel(load_object(COMBAT_D), "rumor", me->query("name")
            + "寿终正寝，永远地离开了我们。");
    }
}


int check_gameover()
{//weiqi, 981231
    object me = this_object();
	  
    if( wizardp(me) ) return 0;
    if( !userp(me) ) return 0;
		  
    if( (me->query("age") <= me->query("life/life_time")) || me->query("life/live_forever") ) return 0;
		      
    //now gameover le
    gameover();
    return 1;
}

void announce_live_forever(string reason)
{
    object me = this_object();
    object dadi;

    if( !reason ) return;
    
    if( me->query("life/live_forever_announced") ) return;

    me->set("life/live_forever_announced", 1);
    me->set("life/live_forever", 1);
	me->add("score", 100);

    dadi = new("/d/wiz/npc/dadi.c");
    dadi->move(environment(me));

    message_vision(HIY"只听一阵仙乐缥缈，一驾五彩云车从天缓缓而降。\n"NOR, dadi);
    message_vision(HIY"$N从车上立起身来对$n一拱手：恭喜！恭喜！\n"NOR, dadi, me);
    dadi->command_function("chat "+reason);
    message_vision(HIY"$N一挥手，云车渐渐淡去...\n"NOR, dadi);
    destruct(dadi);

    return;
}

varargs int receive_damage(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	if( objectp(who) ) {
	    if(objectp(who->query_temp("invoker")))
		who=who->query_temp("invoker");
	    set_temp("last_damage_from", who);
	}

	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else {
	  set( type, -1 );
	  
	  //added by mon for pk and nk.
	  if(living(this_object())&&objectp(who)&&userp(who)
	     &&!query_temp("last_fainted_from")
	     //must not be fainted before within 60 sec.
	     ) {
	    set_temp("last_fainted_from",who->query("id"));
	    if(userp(this_object()))
	      call_out("remove_faint",60,this_player());
	    //prevent help other to faint a npc or player
	    //and to get daoxing.
	    //has to wait 60 second after the faint.
	    //for NPC, the last_fainted_from mark will not
	    //be erased, so only the first one who faint a npc
	    //can possibly get dx. One can't help others to
	    //faint a npc.
          }
        }

	set_heart_beat(1);

	return damage;
}

void remove_faint(object me)
{  if(me) me->delete_temp("last_fainted_from"); }

varargs int receive_wound(string type, int damage, object who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	if( objectp(who) ) {
	    if(objectp(who->query_temp("invoker")))
		who=who->query_temp("invoker");
	    set_temp("last_damage_from", who);
	}

	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);
	else {
		set( "eff_" + type, -1 );
		val = -1;

	  //added by mon for pk and nk.
	  if(living(this_object())&&objectp(who)&&userp(who)
	     &&!query_temp("last_fainted_from")
	     //must not be fainted before within 60 sec.
	     ) {
	    set_temp("last_fainted_from",who->query("id"));
	    if(userp(this_object()))
	      call_out("remove_faint",60,this_player());
	    //prevent help other to faint a npc or player
	    //and to get daoxing.
	    //has to wait 60 second after the faint.
	    //for NPC, the last_fainted_from mark will not
	    //be erased, so only the first one who faint a npc
	    //can possibly get dx. One can't help others to
	    //faint a npc.
          }
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="gin" && type!="kee" && type!="sen" )
		error("F_DAMAGE: 恢复种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

// snowcat feb 8 1998 
void remove_ride ()
{
	object rider, ridee;
	
	if (ridee = query_temp("ridee"))
		ridee->delete_temp("rider");
       	delete_temp("ridee");
       	add_temp("apply/dodge",-query_temp("ride/dodge"));
       	set_temp("ride/dodge",0);
        if (rider = query_temp("rider"))
        	rider->remove_ride();
       	delete_temp("rider");
}

void unconcious()
{
	object defeater;

	if (environment() && environment()->query("alternative_die")) {
	  environment()->alternative_die(this_object());
	  return;
	}
	
	if( !living(this_object()) ) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;

	if( objectp(defeater = query_temp("last_damage_from")) )
		COMBAT_D->winner_reward(defeater, this_object());

	this_object()->remove_all_enemy();
	remove_ride();

 	message("system", HIR "\n你的眼前一黑，接着什么也不知道了．．．\n\n" NOR,
		this_object());
	this_object()->disable_player(" <昏迷不醒>");
	set("gin", 0);
	set("kee", 0);
	set("sen", 0);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
	remove_call_out("revive");

//	delete_temp("last_fainted_from");
// revive will not remove this mark.

        delete_temp("no_move");
	//sometimes players still set no_move after death
	//and can't be cleared.
	if(this_object()->is_busy()) this_object()->start_busy(1);
	//clear the busy flag.

	while( environment()->is_character() )
		this_object()->move(environment(environment()));
	this_object()->enable_player();
	if( !quiet ) {
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		message("system", HIY "\n慢慢地你终于又有了知觉．．．\n\n" NOR,
			this_object());
	} else
		set_temp("block_msg/all", 0);
}

void die()
{
	object corpse, killer, me, guai;
	object *inv;
	int i;
	string last_fainted_from, str;	
        me = this_object();

	if (environment() && environment()->query("alternative_die")) {
		environment()->alternative_die(this_object());
		return;
	}

	if (query_temp("last_fainted_from")) 
		last_fainted_from=query_temp("last_fainted_from");

	if( !living(this_object()) ) revive(1);//如果没有活着，安静地醒来
	if( wizardp(this_object()) && query("env/immortal") ) return;//不死

	// Clear all the conditions by death.
	this_object()->clear_condition();

        //needed because last_fainted_from is cleared in revive()
	if (last_fainted_from) 
		set_temp("last_fainted_from",last_fainted_from);
	
//		COMBAT_D->announce(this_object(), "dead");
		
	        if ( me->query("rulaitask/get") )
                {
                        guai = me->query("rulaitask/guai");        
                        if ( guai == me->query_temp("last_damage_from") || guai == me->query_temp("last_opponent") )
                             {
                                me->set("eff_kee",me->query("max_kee"));
                                me->set("eff_sen",me->query("max_sen"));
                                me->set("kee",me->query("max_kee")/3);
                                me->set("sen",me->query("max_sen")/3);
                                me->add("combat_exp",-1000);
                                me->add("daoxing",-1000);
                                me->add("rulaitask_log/die",1);
                                me->delete("rulaitask/get");
                                me->set("rulaitask/fail",1);
                                str = me->name()+"被"+guai->name()+"杀死了，幸好如来佛祖及时出手相救，才捡回一命。";
                                message("channel:rumor",HIM"【三界神话】某人："+str+"\n"NOR,users());
                                log_file("taskdeath",sprintf("[%s] %s is task killed by %s.\n",
                                           ctime(time()),this_object()->query("id"),guai->name()));
                                remove_ride();

                                me->move("/d/qujing/lingshan/daxiong");
                                message_vision(HIY"$N大叫：“佛祖救我！”。
如来佛祖慢慢展开左手向远方一指，$N的魂魄在裹在一团青气
中落在佛祖的左掌心，再缓缓伸出右手轻轻一招，一道白光围
绕着$N的尸体突然出现在佛祖的右掌心。
如来佛祖双手一合，硬生生地把$N魂魄逼回身体。
如来佛祖喝道：“$N不醒，更待何时?”。\n"NOR,me);
                                me->unconcious();
                                return;
                              }
                 }

	// destroy all self-made fabao here
	inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++)   {
		if( inv[i]->query("owner_id") == getuid(this_object()) )   {
			tell_object(this_object(), HIB+"你看到" + inv[i]->query("name") +
				HIB + "破空而去，慢慢消失在天际．．．\n"+NOR);
			destruct( inv[i] );
		}
	}
	COMBAT_D->announce(this_object(), "dead");

	if( (int)this_object()->query("max_gin") > 0 && 
	(int)this_object()->query("max_kee") > 0 &&
	(int)this_object()->query("max_sen") > 0 ) {
//no damage to self_purged people.

		if( objectp(killer = query_temp("last_damage_from")) ) {
			set_temp("my_killer", killer->query("id"));
			COMBAT_D->killer_reward(killer, this_object());
			if(userp(this_object()))
			{
				COMBAT_D->announce(this_object(), "death_rumor", this_object()->query_temp("death_msg"));
				log_file("death",sprintf("[%s] %s is killed by %s.\n",
					ctime(time()),this_object()->query("id"),
					killer->query("id")));
			}
		} else {
			if(userp(this_object())) {
				COMBAT_D->victim_penalty(this_object());
				if(str=this_object()->query_temp("death_msg"))  
					str=this_object()->name(1)+str;
				else  str=this_object()->name(1)+"莫名其妙地死了。\n";
				COMBAT_D->announce(this_object(), "death_rumor", str);
				log_file("death",sprintf("[%s] %s is killed: %s.\n",
					ctime(time()),this_object()->query("id"),str));
			}
		}
	}

	remove_ride();

	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
 	if (this_object()->self_purge()) return;

	if( userp(this_object()) ) {
		set("gin", 1);	set("eff_gin", 1);
		set("kee", 1);	set("eff_kee", 1);
		set("sen", 1);	set("eff_sen", 1);
		
		//here is a good point to decrease life time...weiqi,98/12/31
		if( !this_object()->query("life/life_time") ) this_object()->set("life/life_time", 60);
		if( !this_object()->query("life/no_death_decrease") )
			this_object()->set("life/life_time", (int)this_object()->query("life/life_time")-1);
		//now we check if gameover.
		if( check_gameover() ) return;

		ghost = 1;
		if( (int)this_object()->query("score") < 10 )
			this_object()->set("score", 0);
		else
			this_object()->add("score", -10 );

		this_object()->add("death/count",1);
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());
	} else
		destruct(this_object());
}

void reincarnate()
{
	ghost = 0;
// drop all, or they could take a ghost out of hell.
	command("drop all");
	set("eff_gin", query("max_gin"));
	set("eff_kee", query("max_kee"));
	set("eff_sen", query("max_sen"));
}

int max_food_capacity() 
{ 
	int final;
	final=(int)query_weight()/200;
	if (final < 100 ){
		final=100;
	}
	return final;
}

int max_water_capacity() 
{ 	
	int final;
	final=(int)query_weight()/200;
	if( final< 100 ) {
		final=100;
	}
	return final; 
}

int heal_up()
{
	int update_flag;//, i
	mapping my;
	object ob=this_object();

	if (environment())
    	if (environment()->query("no_time")) return -1;
	update_flag = 0;

	my = query_entire_dbase();

	// mon 01/23/99
	if(sizeof(query_temp("no_heal_up")))
	    return update_flag;

	// mon 0122/99
	// allow_heal_up will allow a NPC to heal up
	// when fighting. default is no help up.
  	if( !userp(ob) && ob->is_fighting() 
  	&& !my["allow_heal_up"]) 
	    return update_flag;

//	if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
//	if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }

//	if( my["water"] < 1 && userp(this_object()) ) return update_flag;

	if( userp(ob) )
	{
		if(my["water"] > 0)
		{
			my["water"] -= 1;
			if (my["water"] == ob->max_water_capacity()*0.3)
				tell_object(ob,HIY "\n你舔了舔干裂的嘴唇，看样子是渴了。\n"NOR);
			if (my["water"] == ob->max_water_capacity()*0.1)
			{
					tell_object(ob,HIY "\n水，水，你扯着快冒火的嗓子干嚎着。\n"NOR);
					ob->delete_temp("waters");
			}
			update_flag++;
		}
		else
		{
			if(!ob->query_temp("waters"))
			{
				tell_object(ob,HIR "\n水，水，你扯着快冒火的嗓子干嚎着。\n"NOR);
				ob->set_temp("waters",10);
			}

			if((int)ob->query_temp("waters") > 1)
				ob->add_temp("waters",-1);
			else
			{
				tell_object(ob,HIR "\n你渴得快撩拦啦。。。。\n"NOR);
				if(wizardp(ob))
				{
					tell_object(ob,HIY "还好你是月影奇缘的巫师，只见你伸手一挥，变出了一大堆好喝的\n"NOR);
					if ((int)ob->query("age")<15) 
						tell_object(ob,HIG "你掏出一筒“娃哈哈”狠狠的喝了两口，爽罪达。\n"NOR);
					else if (ob->query("gender") == "女性")
						tell_object(ob,HIY "你拿起一瓶果汁！哗啦两下就喝光了，看来你真是渴坏了\n"NOR);
					else
						tell_object(ob,HIY "哇，还有啤酒耶！，你哗啦两下就喝光了，看来你真是渴坏了！\n"NOR);
					ob->set("water",ob->max_water_capacity());
				}
				else if(ob->query("nowf", 1) < 5)
				{
					ob->set_temp("waters",10);
					ob->add("nowf", 1);
					ob->unconcious();
				}
				else
				{
					ob->set_temp("death_msg", "是给活活渴死的");
					ob->set("nowf", 0);
					ob->set("water",ob->max_water_capacity());
					ob->set("food",ob->max_food_capacity());
					ob->die();
				}
			}
			update_flag++;
		}
		if(my["food"] > 0)
		{
			my["food"] -= 1;
			if(my["food"] == ob->max_food_capacity()*0.3)
				tell_object(ob,HIY "\n你肚子咕咕直叫，看来得吃点东西了。\n"NOR);
			if(my["food"] == ob->max_food_capacity()*0.1)
			{
					tell_object(ob,HIY "\n你饿得直发慌，赶快吃点东西吧。\n"NOR);
					ob->delete_temp("foods");
			}
			update_flag++;
		}
		else
		{
			if(!ob->query_temp("foods"))
			{
				tell_object(ob,HIR "\n你饿得直冒金星，实在是顶不住了。\n"NOR);
				ob->set_temp("foods",10);
			}

			if((int)ob->query_temp("foods") > 1)
				ob->add_temp("foods",-1);
			else
			{
				tell_object(ob,HIR "\n你饿得快撩拦啦。。。。\n"NOR);
				if(wizardp(ob))
				{
					tell_object(ob,HIY "还好你是月影奇缘的巫师，只见你伸手一挥，变出了一大堆好吃的\n"NOR);
					if ((int)ob->query("age")<15) 
						tell_object(ob,HIG "你掏出一支冰淇淋狠狠的啃了两口，爽罪达。\n"NOR);
					else if (ob->query("gender") == "女性")
						tell_object(ob,HIY "哇噻，还有肯德鸡耶！你也不管什么淑女身份，狼吞虎咽地吃了起来！\n"NOR);
					else
						tell_object(ob,HIY "哇，还有汉堡包耶！，你哗啦两下就吃光了，看来你真是饿坏了！\n"NOR);
					ob->set("food",ob->max_food_capacity());
				}
				else if(ob->query("nowf", 1) < 5)
				{
					ob->set_temp("foods",10);
					ob->add("nowf", 1);
					ob->unconcious();
				}
				else
				{
					ob->set_temp("death_msg", "是给活活饿死的");
					ob->set("nowf", 0);
					ob->set("water",ob->max_water_capacity());
					ob->set("food",ob->max_food_capacity());
					ob->die();
				}
			}
			update_flag++;
		}
	}

	my["gin"] += my["con"] / 3 + my["atman"] / 10;
	if( my["gin"] >= my["eff_gin"] ) {
		my["gin"] = my["eff_gin"];
		if( my["eff_gin"] < my["max_gin"] ) { my["eff_gin"] ++; update_flag++; }
	} else update_flag++;

	// kee and force depends on drink to heal.

	my["kee"] += my["con"] / 3 + my["force"] / 10;
	if( my["kee"] >= my["eff_kee"] ) {
		my["kee"] = my["eff_kee"];
		if( my["eff_kee"] < my["max_kee"] )	{ my["eff_kee"] ++; update_flag++; }
	} else update_flag++;

	if( my["max_force"] && my["force"] < my["max_force"] ) {
		my["force"] += (int)ob->query_skill("force", 1) / 2;
		if( my["force"] > my["max_force"] ) my["force"] = my["max_force"];
		update_flag++;
	}

	if( my["food"] < 1 && userp(ob) ) return update_flag;

	if( my["max_atman"] && my["atman"] < my["max_atman"] ) {
		my["atman"] += (int)ob->query_skill("magic", 1) / 2;
		if( my["atman"] > my["max_atman"] ) my["atman"] = my["max_atman"];
		update_flag++;
	}

	// sen and mana depends on food for heal.

	my["sen"] += my["con"] / 3 + my["mana"] / 10;
	if( my["sen"] >= my["eff_sen"] ) {
		my["sen"] = my["eff_sen"];
		if( my["eff_sen"] < my["max_sen"] )	{ my["eff_sen"] ++; update_flag++; }
	} else update_flag++;

	if( my["max_mana"] && my["mana"] < my["max_mana"] ) {
		my["mana"] += (int)ob->query_skill("spells", 1) / 2;
		if( my["mana"] > my["max_mana"] ) my["mana"] = my["max_mana"];
		update_flag++;
	}

	return update_flag;
}
