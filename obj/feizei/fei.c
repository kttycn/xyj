// last modify by landis@myth
// 2001.08.18

#include <ansi.h>

inherit NPC;

void set_skills();
void leave();

void create()
{
        seteuid(getuid());        
        set_name("盗宝飞贼",({"zei"}));
        set("long", 
"这是飞天遁地的飞贼，背上有一个灰布包裹，看样子是才偷了什
么东西在手。\n");
        set("age",30); 
        set("str",30);
        set("per",20);
        set("combat_exp",5000000);
//        set("daoxing",500000);
	set("zei_life",time());
        set("attitude", "heroism");
        set_skill("unarmed",200);
        set("chat_chance", 10);

        set("chat_msg", ({
            (: random_move :)
        }));
        setup();
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/obj/feizei/obj/package");
        add_money("gold", 1);
}

void init()
{
        if (!living(this_object())) return;
        if (!living(this_player())) return;

        remove_call_out("check_room");
        call_out("check_room",2);
	
	add_action("do_ji","ji");
	add_action("do_cast", "cast");   
        ::init();
}

int do_cast (string arg)
{
        object who = this_player();
        if ((arg == "qiankun") || (arg == "qiankun on fei zei") || (arg == "qi
ankun on zei") || (arg == "qiankun on thief")|| (arg == "huimeng")|| (arg == "hui
meng on fei zei")|| (arg == "huimeng on zei")|| (arg == "huimeng on thief")|| (arg == "zh
uang")|| (arg == "zhuang on fei zei")|| (arg == "zhuang on zei")|| (arg == "zhuang on thief"))
        {
                tell_object(who,"想暗算我，没门！！！\n");
                return 1;
        }
        else return 0;
}                                                    
int do_ji()
{
    message_vision(HIY"$N向$n大叫一声：好你个小王八蛋，想用法宝！没门！\n"NOR,this_object(),this_player());
        return 1;
}
void check_room()
{
        object me=this_object();
        object env=environment(me);
        if(time()-me->query("zei_life")>1800)
        {
        me->leave();
        }
        if (!living(me)) return;
        if (env && (env->query("no_fight") || env->query("no_magic")))
                random_move();
//	if (env->query("short") != "祭台")
//		return;
//	remove_call_out ("leave");	
//	call_out ("leave",1,me,env);	
}

/*void check_room ()
{
	object me = this_object();
	object where = environment (me);

	if (where->query("short") != "后院")
		return;

	if (where->query("is_open"))
		return;

	remove_call_out ("opening");	
	call_out ("opening",1,me,where);	
}*/

void copy_status(object me)
{
   //     object *inv;
    //    mapping skill_status,map_status;
  //      string *sname,*mname;
    //    int i, eff_dx, nk_factor;
        set_name("飞贼",({"fei zei","zei","thief"}));
        set("title",HIY"盗宝"+query("target")+"的"NOR);
        set("enable_type","飞贼");
        set("str",30);
        set("int",30);
        set("con",30);
        set("per",30);
        set("cor",30);
        set("spi",30);
        set("cps",30);
        set("kar",30);

        set("max_kee",3000+random(1000));
        set("eff_kee",3000+random(1000));
        set("kee",3000+random(1000));

        set("max_gin",2500+random(1000));
        set("eff_gin",2500+random(1000));
        set("gin",2500+random(1000));

        set("max_sen",2000+random(1000));
        set("eff_sen",2000+random(1000));
    	set("sen",2000+random(1000));

        set("max_force",3000+random(1000));
        set("force",6000+random(1000));
        set("force_factor",300);

        set("max_mana",3000+random(1000));
        set("mana",6000+random(1000));
        set("mana_factor",300);
        set("combat_exp",100000+random(1000000));
        set("daoxing",300000+random(300000));

        set("stay_time",time()+600+random(60));

        set("nk_gain", 100+random(50));
        set("nk_factor", 12);       
        set("bellicosity",300);
        carry_object("/d/qujing/jindou/obj/boots")->wear();
        carry_object("/d/qujing/jindou/obj/finger")->wear();
        carry_object("/d/qujing/jindou/obj/hands")->wear();
        carry_object("/d/qujing/jindou/obj/head")->wear();
        
        set_skills();

}

string invocation()
{
        object me=this_object();
        object room;
        mapping loc;
        copy_status(me);

        loc = MISC_D->random_location(2);
        room = loc["room"];
        me->move(room);
        return MISC_D->find_place(room);
}

varargs int receive_damage(string type, int damage, object who)
{
        object me=this_object();
        call_out("exertheal",1,me);
        return ::receive_damage(type,damage,who);
}

void exertheal(object me) 
{
        me->command("exert recover");
}

void die()
{
        int reward;
        object ob,me;
        ob = query_temp("last_damage_from");
//      ob = query_last_damage_from();
        me=this_object();
        if (!ob)
        {
                me->leave();
                return; 
        }
        CHANNEL_D->do_channel( this_object(), "rumor",
        sprintf("盗宝%s的"NOR+YEL"<%s>"HIM"被%s杀死了。"NOR,query("target"),query("name"), ob->name() ));
        reward = query("nk_gain") * query("nk_factor");
        ob->add("kill/nkgain",reward);
        ob->add("daoxing",reward*2/3);
        ob->add("potential", reward*2/3);
        tell_object(ob,"\n你得到了"+COMBAT_D->chinese_daoxing(reward*2/3)+"道行和"
                + reward/2 + "点潜能！\n" );
        MONITOR_D->report_system_object_msg(ob,"得到了"+COMBAT_D->chinese_daoxing(reward*2/3)+"道行和"
                + reward/2 + "点潜能！");
//	destruct(this_object());

        ::die();
}

void unconcious()
{
	die();
/*  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();*/
}

void heart_beat()
{
        if (!query_temp("weapon") && !query_temp("added"))
        {
                set_temp("added", 1);
                set("force_factor",100);
                set("force",2000);
        }
        if (query("eff_kee")<query("max_kee"))
        {
                if (random(10)) command("eat yao");
                else {
                command("surrender");
                call_out("exertheal",1,this_object());
                }
        }

        ::heart_beat();
}

int attack()
{
        object opponent;
        clean_up_enemy();
        opponent = select_opponent();
        if ( objectp(opponent) ) {
        if (opponent->query("family/family_name")==this_object()->query("target")
                        && userp(opponent)
                        && !living(opponent)
                        && environment()==environment(opponent)) {
                    call_out("leave",1);
                    return 0;
                }

                set_temp("last_opponent", opponent);
                COMBAT_D->fight(this_object(), opponent);
                return 1;
        } else
                return 0;
}

void leave()
{
        object me;
        me = this_object();

        command("say 嘿嘿，躲了这么久了，外头风声也该松了，还是趁早把宝贝藏好要紧！");
        message_vision(HIB"$N将身子一晃，化做一股轻烟消失了……\n"NOR,me);
        destruct(me);
        return;
}
