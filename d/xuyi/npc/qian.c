// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// by night

inherit NPC;
#include <ansi.h>

int work_me();

void create()
{
   set_name("Ǯ��", ({"qian shenjiang", "qian", "shenjiang"}));
   //set("title", "");
   set("gender", "����" );
   set("age", 30);
   set("per", 20);
   set("long", "һλ���ȵ������ˡ�\n");
   set("class", "xian");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("����ɽ", 3, "����");
   set_skill("unarmed", 50);
   set_skill("dodge", 80); 
   set_skill("tianwei-shi", 80);
   set_skill("parry", 90); 
   set_skill("lianhuan-tui", 50);   
   set_skill("hammer", 70);
   set_skill("pangu-hammer", 80);
   set_skill("force", 80);   
   set_skill("guiyuanforce", 80);   
   set_skill("literate", 70);
   set_skill("spells", 80);
   set_skill("fumozhou", 80);
   map_skill("hammer", "pangu-hammer");
   map_skill("parry", "pangu-hammer");  
   map_skill("dodge", "tianwei-shi");
   map_skill("unarmed", "lianhuan-tui");
   map_skill("force", "guiyuanforce");
   map_skill("spells", "fumozhou");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 1000);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);   
   set("force_factor", 40);
   set("mana_factor", 40);
        set("inquiry", ([
        "kill": (: work_me :),
        "job": (: work_me :),
        "����": (: work_me :),
        "��ħ": (: work_me :),
        ]));

   setup();
   carry_object("/d/obj/cloth/linen")->wear();
   carry_object("/d/obj/armor/tongjia")->wear();
   carry_object("/d/obj/weapon/hammer/kunwu")->wield();
}

void init()
{
    add_action("do_finish","finish");
    add_action("do_finish","jiaochai");
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="����ɽ" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        if ( (string)ob->query("gender") == "����" ) command("say ʦ���Ц�ˡ�\n");
        else command("say ʦ�ü�Ц�ˡ�\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        if ( (string)ob->query("gender") == "����" ) command("say ʦ��̫�����ˡ�\n");
        else command("say ʦ��̫�����ˡ�\n");
     }
     else 
     {
        command("consider");
        command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "����" ) ob->set("title", "����ɽѲ����ʿ");
        else ob->set("title", "����ɽѲ��Ů��");

     }
   }

   else
   {
     command("say �ã����Ҿ���Ϊ���Ѱɡ�\n");
     command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "����" ) ob->set("title", "����ɽѲ����ʿ");
        else ob->set("title", "����ɽѲ��Ů��");

   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "hero");
}

int accept_fight(object me)
{
        command("say ��Ϊ�����񽫣����������Ұƥ����գ�");
        return 0;
}

int work_me()
{
   object monster, me, guard;
   int i, num;
   string* dirs;   

   dirs=({"/d/xuyi/"});
      
   me = this_player();
   
   if( (string)me->query("family/family_name")!="����ɽ" ) {
     message_vision("$N����$n���ۣ�ҡͷ������л"+RANK_D->query_respect(me)+"���⣬���Ǳ��ŵ��ӵĹ�����\n", this_object(), me);
     return 1;
     }
     
   if (((int)me->query("combat_exp") < 120000 )) {
     command("say Ȱ�㻹�ǲ�Ҫȥ�����ˡ�\n");
     return 1;
     }
     
   if(me->query_temp("xuyi/monster")) {
     command("say ȥ�ɣ��м�С�����⡣");
     return 1;
     }
          
   if(this_object()->query("has_asked")) {
     command("say �����Ѿ�����ȥ������ħ�ˣ�������������ɡ�");
     return 1;
     }
     
   num = random(3)+2;
   for(i=1;i<=num;i++)
    {
        monster = new(__DIR__"monster");
        call_out("random_go",1,monster, dirs);       
    }
    command("say ���������������ɽ��������û�������ȥ�������ǰɡ�");
    command("say ҪС�Ĵ��¡�");
    me->set_temp("xuyi/monster", 1);
    me->set_temp("xuyi/num", num);    
    this_object()->set("has_asked", 1);
    guard = new(__DIR__"weishi1");
    guard->set("guard", me->query("id"));
    guard->move(environment(me));
    call_out("regenerate", 300);
    return 1;
}

void random_go(object monster, string* dirs)
{
        int i,j,k;
        object newob;
        mixed* file;   
        
        if( !sizeof(dirs) )  return;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }
    if( (newob=find_object(dirs[i]+file[j][0])) )   {
                if(!newob->query("dangerous") ){
        call_out("random_go",1,monster, dirs);   
                        return;
                }
                monster->move( newob ); 
message_vision("\nͻȻһ������ӿ��$N�����ֳ����Σ�\n", monster);
        }
        else  {
                seteuid(getuid());
                newob = load_object(dirs[i]+file[j][0]);
                if (newob)   // now this is not necessary, only for debug use
                {
                        if( !newob->query("dangerous")){
        call_out("random_go",1,monster, dirs);   
                                return;
                        }
                        monster->move(newob);
message_vision("\nͻȻһ������ӿ��$N�����ֳ����Σ�\n", monster);
        }
        else  {
                        tell_object(monster, "Error.\n");
                }
        }

        return;
}

int regenerate()
{
        set("has_asked", 0);
        return 1;
}

int do_finish()
{
        object me, reward, soldier;
        int pot,exp;
        int gold;
        
        me = this_player();
        
        if(!me->query_temp("xuyi/monster")) return notify_fail("��û�����£���Ҫ�����ﵷ�ҡ�\n");
        
        if((int)me->query_temp("xuyi/num")>1 && (int)me->query_temp("xuyi/kill_monster")<= 1)
        {
        command("sigh");
        command("say ��ô������ô���");
        command("shrug");
        if (objectp(soldier=present("guard soldier", environment(me)))) destruct(soldier);
        me->delete_temp("xuyi/monster");
        return 1;
        }
        soldier=present("guard soldier", environment(me));
        if(!soldier)
        {
        command("angry " + me->query("id"));
        command("say �������µ�ʿ�����޷�����������Ϊ�٣�");
        me->delete_temp("xuyi/monster");
        return 1;
        }        
    exp=(160+(random(5))*40);
    pot=(50+random(50));
    if (pot > 80) pot=80;

    me->add("combat_exp",exp);
    me->add("potential",pot);
    if(me->query("xuyi/kill"))
    {
    me->set("job/xuyi_kill", me->query("xuyi/kill"));
    me->delete("xuyi/kill");
    }
    me->add("job/xuyi_kill", 1);
    
   tell_object(me,HIW"��������ˣ��㱻�����ˣ�\n" + 
                COMBAT_D->chinese_daoxing(exp) + "���С�" +
                chinese_number(pot) + "��Ǳ�ܡ�\n"+
                NOR);
    
        if((int)me->query("job/xuyi_kill")%60 == 0)
        {
     message_vision("$N��$nЦ��������λ"+RANK_D->query_respect(me)+"�����˺����ͣ�"+RANK_D->query_self(this_object())+"���г�𡣡�\n",this_object(),me);
        me->add("jieshu",1);
        tell_object(me,HIG"������"+chinese_number(1)+"�������\n"NOR);
        }
        
        gold = (int)me->query_temp("xuyi/kill_monster");
        gold = random(gold)+random(2);

        if(gold >= 1)
        {
        add_money("gold", gold);

        command("give "+gold+" gold to " + me->query("id"));
        command("say ����������");
        command("say ���ٽ����һ���Ҫ���Ͱɡ�");
        }
        message_vision(CYN"$N��$nЦ��������λ"+RANK_D->query_respect(me)+"�����ˡ���\n"NOR,this_object(),me);
        me->delete_temp("xuyi/monster");
        me->delete_temp("xuyi/num");        
        if (objectp(soldier=present("guard soldier", environment(me)))) destruct(soldier);

        return 1;
}       

