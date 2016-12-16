// last modify by landis@myth
// 2001.08.18

#include <ansi.h>

inherit NPC;

void set_skills();
void leave();

void create()
{
        seteuid(getuid());
        set_name("��������",({"zei"}));
        set("age",30); 
        set("str",30);
        set("per",20);
        set("combat_exp",5000000);
//        set("daoxing",500000);
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
        add_money("gold", 5);
}

void init()
{
        if (!living(this_object())) return;
        if (!living(this_player())) return;

        remove_call_out("check_room");
        call_out("check_room",2);

        ::init();
}

void check_room()
{
        object me=this_object();
        object env=environment(me);
        if (!living(me)) return;
        if (env && (env->query("no_fight") || env->query("no_magic")))
                random_move();

}

void copy_status(object me)
{
        object *inv;
        mapping skill_status,map_status;
        string *sname,*mname;
        int i, eff_dx, nk_factor;
        set_name("����",({"fei zei","zei","thief"}));
        set("title",HIY"����"+query("target")+"��"NOR);
        set("enable_type","����");
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
        set("combat_exp",500000+random(1000000));
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
        sprintf("����%s��"NOR+YEL"<%s>"HIM"��%sɱ���ˡ�"NOR,query("target"),query("name"), ob->name() ));
        reward = query("nk_gain") * query("nk_factor");
        ob->add("kill/nkgain",reward);
        ob->add("daoxing",reward);
        ob->add("potential", reward*2/3);
        tell_object(ob,"\n��õ���"+COMBAT_D->chinese_daoxing(reward)+"���к�"
                + reward/2 + "��Ǳ�ܣ�\n" );
        MONITOR_D->report_system_object_msg(ob,"�õ���"+COMBAT_D->chinese_daoxing(reward)+"���к�"
                + reward/2 + "��Ǳ�ܣ�");
        ::die();
}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
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

        command("say �ٺ٣�������ô���ˣ���ͷ����Ҳ�����ˣ����ǳ���ѱ����غ�Ҫ����");
        message_vision(HIB"$N������һ�Σ�����һ��������ʧ�ˡ���\n"NOR,me);
        destruct(me);
        return;
}
