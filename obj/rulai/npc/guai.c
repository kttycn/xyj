// Crack By stey
// Crack By bignose,add chinese name
#include <ansi.h>
 
inherit NPC;
 
void copy_status(object me, int level);
void set_skills(int max_value, int level);
void set_hp_status(object me, int level);
object owner() {return query("owner");}
 
 
string *dirs1 = ({
"/d/city",
"/d/jjf",
"/d/westway",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/gao",
//"/d/dntg/hgs", 
"/d/sea", 
"/d/nanhai", 
"/d/eastway",
"/d/ourhome/honglou", 
"/d/shushan/",
"/d/shushan",
"/d/xueshan",
"/d/qujing/wuzhuang", 
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan",
"/d/qujing/biqiu",
"/d/qujing/chechi",
"/d/qujing/dudi",
"/d/qujing/fengxian",
"/d/qujing/firemount",
"/d/qujing/jilei",
"/d/qujing/jindou",
"/d/qujing/jingjiling",
"/d/qujing/jinping",
"/d/qujing/jisaiguo",
"/d/qujing/maoying",
"/d/qujing/nverguo",
"/d/qujing/pingding",
"/d/qujing/pansi",
"/d/qujing/tongtian",
"/d/qujing/qilin",
"/d/qujing/qinfa",
"/d/qujing/qinglong",
"/d/qujing/tianzhu",
"/d/qujing/wudidong",
"/d/qujing/wuji",
"/d/qujing/xiaoxitian",
"/d/qujing/yinwu",
"/d/qujing/yuhua",
"/d/qujing/zhujie",
"/d/qujing/zhuzi",
"/d/penglai",
"/d/death",  
"/d/meishan",
"/d/qujing/lingshan",
"/d/dntg/sky",
});


string* name_word1 = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",
"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��",
"��","��","ʯ",
});
string* ename_word1 = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});

string* name_word2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});


string* ename_word2 = ({
"zhong","xiao","li","yi","zhi","yong","ren","kuang","xian","ling","fu","lu","da","xiao","xiao",
"gao", "ke",   "a", "jin","shi","ke","shu","zhi","gong","fu"  ,"shi","ruo","qing","wen","wu",
"duo","cai","chang","zi","yong","you","zi","ren","wei","tie","","","","","","","","",
"","","","","","","","","","","","","","",
});



string* name_word3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});

string* ename_word3 = ({
"ba","bai","ban", "fu",  "bin", "chang","chao","cheng","chuan","ding","ding","dou",
"fa","fei","feng","feng","gang","zheng","guan","guang","hai",  "hu",  "hua",
"hao","hong","ji","jian","jian","jian","jiang","jin","jie","jun","kang",
"liang"," lin","min","ming","ming","ning","pei","qi","qiang","rong","shan",
"tai","tao","ting","wei","xi","xiang","xiong","xu",
"yi","yu","yu","yu","yue","zhou",
});



// ___________________________Ů��ר��_________________________________   
string* name_word4 = ({
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","�","��","��","��","��","��","��","��","��",
"ٻ","Ƽ","��","ϼ","��","��","��","Ӣ","��","��","��",
"��",
});
string* ename_word4 = ({
"ai","chun","dan","fang","fen","feng","gu","hong","hong","jiao","juan",
"ju","lan","lan","li","li","lian","ling","lin","na","qin","qin",
"qian","ping","ting","xia","xiang","yan","yan","ying","ying","yu","zhen",
"zhu",
});
// ____________________________________________________________________




int random_place(object me, string* dirs);

void setname()
{
     int i;
     string namec,ename1,ename2;
     object guai = this_object();
     
     i = random(sizeof(name_word1));

     namec  = name_word1[i];
     ename1 = ename_word1[i];
     ename2 = ename_word1[i];


     i = random(sizeof(name_word2));

     namec = namec + name_word2[i];
     ename2 = ename2 + ename_word2[i];

     switch( random(2))  {
           case 0 :
                    i = random(sizeof(name_word3));
                    set("gender","����");
                    namec = namec + name_word3[i];
                    ename2 = ename2 + ename_word3[i];
                    break;
           case 1 :
                    i = random(sizeof(name_word4));
                    set("gender","Ů��");
                    namec = namec + name_word4[i];
                    ename2 = ename2 + ename_word4[i];
                    break;
     }
     set_name(namec, ({ename2,ename1}));
}
void create()
{        
        set("age", 100+random(80));
        setname();
        set("attitude", "heroism");
        set("per", 40);
        set("str", 100);
        set("cor", 40);
        set("con", 40);
        set("int", 40);
        set("spi", 40);
        set("cps", 40);
        set("kar", 40);
        set("max_gin", 1000);
        set("food", 10000);
        set("water", 10000);
        set_weight(30000);
        set("no_steal",1);
        set("taskguai",1);
        set("chat_chance", 5);
        set("chat_msg", ({
             (: random_move :)
        }) );
        
        setup();
}

int random_place(object me, string* dirs)
{
        int  i, j, k;
        object  newob;
        mixed*  file, exit;

        if( !sizeof(dirs) )  return 0;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        if( !sizeof(file) )             return 0;

        for(k=0;k<30;k++) { // try 30 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       newob->query("no_mieyao") ||
                       !(exit=newob->query("exits")) ||
                       sizeof(exit)<1 ||
                       !newob->query("outdoors") )
                   continue;

               if(me->move(newob)) {
                   message_vision("$N���˹�����\n",me);
                   return 1;
               }
             }
           }
        }

        return 0;
}

string invocation(object me, int level)
{
        object guai,env;        
        string *dirs, where;
        
        dirs=dirs1;
        guai=this_object();
        copy_status(me, level);
        
        set("owner", me);
        set("kind",me->query("rulaitask/kind"));
        set("level",level);
        
        if(!random_place(guai, dirs))  return "û���֡�";
        
        env=environment(guai);
        where=guai->query("name") + "(" + capitalize(query("id")) + ")";
          
        if(env)
         where += "��"+MISC_D->find_place(env);
        return where;
        
        
}

void copy_status(object me, int level)
{
        mapping me_skill;
        int *skill_value, max_value, i;
        
        me_skill = me->query_skills();
        i=sizeof(me_skill);
        if(i>0) {
                skill_value=values(me_skill);
                max_value=skill_value[0];
                while(i--) { // �ҳ����skill���ֵ
                    if(skill_value[i]>max_value)
                        max_value=skill_value[i];
                }
          } else max_value=1;
                 
          set_skills(max_value, level);
          
          set_hp_status(me,level);
            
}         
          
void set_skills(int max_value, int level)
{
        object guai=this_object();       
        int guai_value;
        
        if (level==1) guai_value = max_value+max_value/9;
        else if (level==2) guai_value = max_value+max_value/7;
        else guai_value = max_value+max_value/5;
        
        set_skill("unarmed", guai_value+random(16));
        set_skill("dodge", guai_value+random(16));
        set_skill("parry", guai_value+random(16));
        set_skill("force", guai_value+random(16));
        set_skill("spells", guai_value+20+random(16));
}       


void set_hp_status(object me, int level)
{       int max_kee,max_sen,skill_force,skill_spells,maximum_mana,exp,daoxing;
        max_kee = me->query("max_kee");
        max_sen = me->query("max_sen");
        skill_force = query_skill("force");
        skill_spells = query_skill("spells");
        maximum_mana = me->query("maximum_mana");
        exp = me->query("combat_exp");
        daoxing = me->query("daoxing")*3/4;
        set("max_force", skill_force*10);
        set("force", skill_force*20);
        set("force_factor", skill_force/3);
        set("mana_factor", skill_spells/4);
        
        if (level==1)
           {
                set("max_kee", max_kee);
                set("eff_kee", max_kee);
                set("max_sen", max_sen);
                set("eff_sen", max_sen);
                set("kee", max_kee*2);
                set("sen", max_sen*2);
                set("max_mana", maximum_mana);
                set("mana",maximum_mana*2);
                set("combat_exp", exp+exp*1/16+random(exp*1/16));
                set("daoxing", daoxing+daoxing*1/16+random(daoxing*1/16));
                set_temp("apply/armor", 40);
                set_temp("apply/damage", 30);
           }
           
        else if (level==2)
           {
                set("max_kee", max_kee*3/2);
                set("eff_kee", max_kee*3/2);
                set("max_sen", max_sen*3/2);
                set("eff_sen", max_sen*3/2);
                set("kee", max_kee*3);
                set("sen", max_sen*3);
                set("max_mana", maximum_mana*3/2);
                set("mana",maximum_mana*3);
                set("combat_exp", exp+exp*1/12+random(exp*1/12));
                set("daoxing", daoxing+daoxing*1/12+random(daoxing*1/12));
                set_temp("apply/armor",60);
                set_temp("apply/damage", 60);
           }             
           	else
           {
                set("max_kee", max_kee*2);
                set("eff_kee", max_kee*2);
                set("max_sen", max_sen*2);
                set("eff_sen", max_sen*2);
                set("kee", max_kee*4);
                set("sen", max_sen*4);
                set("max_mana", maximum_mana*2);
                set("mana",maximum_mana*4);
                set("combat_exp", exp+exp*1/6+random(exp*1/6));
                set("daoxing", daoxing+daoxing*1/6+random(daoxing*1/6));
                set_temp("apply/armor", 80);
                set_temp("apply/damage", 90);
           }   
}

int accept_fight(object ob)
{       
        object me=this_object();
        if (ob != owner())
        {message_vision(CYN"$N˵�������߿���Ҫ���ҳ����㡣\n"NOR,me);
         return 0;
        }
        
        else {if ( query("kind")!="��" )
                   {
                        command("say �Ҳ����㣬�㵹���������ˣ��Ҿͳ�ȫ���㡣");
                        me->kill_ob(ob);
                        return 1;
                   }
                else {  
                        if ( query("eff_kee") < query("max_kee") 
                             || query("eff_sen") < query("max_sen") )
                             {message_vision(CYN"$N˵�����������ˣ������򲻹�ƽ�ɡ�\n"NOR,me);
                              return 0;
                             }
                        command("say �ϻ���˵�����ܷ����������˭��˭��");
                        remove_call_out("check_result");
                        call_out("check_result", 1, me, ob);
                        return 1;
                     }
              }                  
}                 

void init ()
{       ::init ();
        add_action("do_persuade", "persuade");
}       

void heart_beat()
{  object guai = this_object();
   ::heart_beat();
   
   if ( !is_fighting()
        && query("eff_kee") >= query("max_kee") / 2 
        && !query_skill("tonsillit",1)
        && !query_skill("shushan-force",1)
        && query("kind") != "��" 
        && query("eff_kee") <  query("max_kee") )
     command("exert heal");
      
   if (query("kee") < query("eff_kee")-10 && query("kind") != "��")
         command("exert recover");
   if (query("sen") < query("eff_sen")-10) 
     command("exert refresh");
   if (query("force") < query("max_force")/2)
     command("cast transfer");
   if (!owner() || owner()->query("rulaitask/fail") )    
        destruct(guai);
   
}       


int check_result(object me, object ob)
{
        int guai_max_kee, ob_max_kee;

        guai_max_kee  = me->query("max_kee");
        ob_max_kee = ob->query("max_kee");
        
        if (me->is_fighting())
        {
                call_out("check_result",1, me, ob);
                return 1;
        }
        
        if ( !living(me) 
                || (int)me->query("kee") < 1 
                || (int)me->query("sen") < 1 ) return 1;
                
        if (((int)me->query("kee")*100/guai_max_kee) <= 50 )
              {
                if ( !living(me) 
                        || (int)me->query("kee") < 1 
                        || (int)me->query("sen") < 1 ) return 1;
                        
                if (random(3) < 1)  command ("say �һ�û׼���ã���Ϳ����ˣ���������");
                      else { if (ob->query_temp("rulaitask/fight_time"))
                                   { command ("say �����ڷ�֪�������죬�������ˣ��һ�Ҫ��ɽ�������������ˡ�");
                                     ob->set("rulaitask/accomplish",1);
                                     ob->set("rulaitask/end_time",time());
                                     ob->delete_temp("rulaitask/fight_time");
                                     ob->delete("rulaitask/get");
                                     destruct(me);
                                     return 1;
                                    }
                               
                                 else { command ("say ��һʱ���⣬Ҳû��ȫ�����Ҳ������ٱ�һ�Ρ�");
                                        ob->set_temp("rulaitask/fight_time",1);
                                        return 1;
                                      }
                            }
               }
                    
            else  {
                        command("say �����������ˣ��������޵С�");
                        return 1;
                  }
}

int do_persuade(string arg)
{
        object me =this_player();
        object ob;
        int guai_max_kee,guai_eff_kee;
        
        if(!arg) return 0;
        ob = present(arg, environment(me));
        if (!ob)   return notify_fail("��ҪȰ˭��\n");
        if (me->query("rulaitask/kind") != "Ȱ"  || ob->query("kind") != "Ȱ") return 0;
        
        if (me->is_busy())
             return notify_fail("����æ���ء�\n");
        
        me->command("say �������������سɷ�");
        
        if ( !living(ob) )   return notify_fail("����Ȼ��"+ob->name()+"��������˵�Ļ���\n");
        
        if ( me != ob->query("owner") || !ob->is_fighting(me) )
             { message_vision(CYN"$N˵����������Щʲô���������\n"NOR,ob);
               return 1;
              }
                 
         guai_max_kee = ob->query("max_kee");
         guai_eff_kee = ob->query("eff_kee");
         
         if ( guai_eff_kee*100/guai_max_kee < 15 )
              {
                command("say ��˵���е�������ͻ�ɽȥ��");
                me->set("rulaitask/accomplish",1);
                me->set("rulaitask/end_time",time());
                me->delete("rulaitask/get");
                destruct(ob);
                return 1;
               }
               
           else if ( guai_eff_kee*100/guai_max_kee < 20 )
                {
                        command("say �㿴�����ڣ��������������");
                        me->start_busy(1+random(3));
                        return 1;
                 }
                 
            else {
                     me->start_busy(3);
                     return notify_fail(ob->name()+"��ר����־ս�����������㡣\n");
                  }
}


void die()
{       object me = owner();
        if (me->query("rulaitask/kind") == "ɱ"  && query("kind") == "ɱ")
             {me->set("rulaitask/accomplish",1);
              me->set("rulaitask/end_time",time());
              me->delete("rulaitask/get");
             }       
        else { me->delete("rulaitask/get");
               me->set("rulaitask/fail",1);
             } 
        ::die();
}


int accept_object (object who, object ob)
{
  object guai;
  guai = this_object();
  
  if ( ob->name() != "��ҩ" || ob->query("id") != "jinchuang yao" )
       { message_vision(CYN"$N˵��������ʲô��������붾���Ұ���\n"NOR,guai);
         return 0;
        }
    else { guai->receive_curing("kee", 250);
           guai->receive_curing("sen", 250);
           message_vision(CYN"$N����һ����ҩ����ɫ�������ö��ˡ�
\n"NOR,guai);
//           call_out ("destruct_ob",1,ob);
           if ( (query("eff_kee") == query("max_kee")) && (query("eff_sen") == query("max_sen")) )
                message_vision(CYN"$N˵�����Һ��ˣ��������������ٴ�ս���ٻغϡ�\n"NOR,guai);
           return 1;
          }
}

/* void destruct_ob (object ob)
{
  destruct (ob);
}*/

void kill_ob (object ob)
{
          object me = this_object();  
          if (me->query("level")>1)
              me->set_leader(ob);
            ::kill_ob(ob);
}           
