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
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫",
"蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻",
"柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳",
"邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付",
"皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄",
"米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍",
"虞","万","支","柯","昝","管","卢","英","仇","候","岳","帅",
"司马","上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫",
"尉迟","公羊","澹台","公治","宗政","濮阳","淳于","单于","太叔",
"申屠","公孙","仲孙","辕轩","令狐","钟离","宇文","长孙","幕容",
"司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷",
"公良","拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦",
"段千","百里","东郭","南郭","呼延","归海","羊舌","微生","梁丘",
"左丘","东门","西门","佰赏","南官",
"缑","亢","况","后","有","琴","商","牟","佘","耳","墨","哈",
"谯","年","爱","阳","佟","第","五","言","福","蒯","钟",
"宗","林","石",
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
"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁","","","","","","","","",
"","","","","","","","","","","","","","",
});


string* ename_word2 = ({
"zhong","xiao","li","yi","zhi","yong","ren","kuang","xian","ling","fu","lu","da","xiao","xiao",
"gao", "ke",   "a", "jin","shi","ke","shu","zhi","gong","fu"  ,"shi","ruo","qing","wen","wu",
"duo","cai","chang","zi","yong","you","zi","ren","wei","tie","","","","","","","","",
"","","","","","","","","","","","","","",
});



string* name_word3 = ({
"霸","白","班","斌","宾","昌","超","诚","川","鼎","定","斗",
"法","飞","风","锋","钢","罡","贯","光","海","虎","华",
"浩","宏","济","坚","健","剑","江","进","杰","俊","康",
"良","麟","民","明","鸣","宁","培","启","强","荣","山",
"泰","涛","挺","伟","熙","祥","雄","旭",
"毅","瑜","羽","宇","岳","舟",
});

string* ename_word3 = ({
"ba","bai","ban", "fu",  "bin", "chang","chao","cheng","chuan","ding","ding","dou",
"fa","fei","feng","feng","gang","zheng","guan","guang","hai",  "hu",  "hua",
"hao","hong","ji","jian","jian","jian","jiang","jin","jie","jun","kang",
"liang"," lin","min","ming","ming","ning","pei","qi","qiang","rong","shan",
"tai","tao","ting","wei","xi","xiang","xiong","xu",
"yi","yu","yu","yu","yue","zhou",
});



// ___________________________女性专用_________________________________   
string* name_word4 = ({
"爱","春","丹","芳","芬","凤","姑","红","虹","娇","娟",
"菊","兰","岚","丽","莉","莲","玲","琳","娜","琴","芹",
"倩","萍","婷","霞","香","艳","燕","英","瑛","玉","珍",
"珠",
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
                    set("gender","男性");
                    namec = namec + name_word3[i];
                    ename2 = ename2 + ename_word3[i];
                    break;
           case 1 :
                    i = random(sizeof(name_word4));
                    set("gender","女性");
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
                   message_vision("$N走了过来。\n",me);
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
        
        if(!random_place(guai, dirs))  return "没妖怪。";
        
        env=environment(guai);
        where=guai->query("name") + "(" + capitalize(query("id")) + ")";
          
        if(env)
         where += "在"+MISC_D->find_place(env);
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
                while(i--) { // 找出玩家skill最大值
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
        {message_vision(CYN"$N说道：快走开，要不我吃了你。\n"NOR,me);
         return 0;
        }
        
        else {if ( query("kind")!="降" )
                   {
                        command("say 我不找你，你倒送上门来了，我就成全了你。");
                        me->kill_ob(ob);
                        return 1;
                   }
                else {  
                        if ( query("eff_kee") < query("max_kee") 
                             || query("eff_sen") < query("max_sen") )
                             {message_vision(CYN"$N说道：我受伤了，这样打不公平吧。\n"NOR,me);
                              return 0;
                             }
                        command("say 废话少说，尽管放马过来，看谁怕谁。");
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
        && query("kind") != "降" 
        && query("eff_kee") <  query("max_kee") )
     command("exert heal");
      
   if (query("kee") < query("eff_kee")-10 && query("kind") != "降")
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
                        
                if (random(3) < 1)  command ("say 我还没准备好，你就开打了，不算数。");
                      else { if (ob->query_temp("rulaitask/fight_time"))
                                   { command ("say 我现在方知天外有天，人外有人，我还要回山多多修炼，告辞了。");
                                     ob->set("rulaitask/accomplish",1);
                                     ob->set("rulaitask/end_time",time());
                                     ob->delete_temp("rulaitask/fight_time");
                                     ob->delete("rulaitask/get");
                                     destruct(me);
                                     return 1;
                                    }
                               
                                 else { command ("say 我一时大意，也没尽全力，我不服，再比一次。");
                                        ob->set_temp("rulaitask/fight_time",1);
                                        return 1;
                                      }
                            }
               }
                    
            else  {
                        command("say 哈哈，你输了，我天下无敌。");
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
        if (!ob)   return notify_fail("你要劝谁？\n");
        if (me->query("rulaitask/kind") != "劝"  || ob->query("kind") != "劝") return 0;
        
        if (me->is_busy())
             return notify_fail("你正忙着呢。\n");
        
        me->command("say 放下屠刀，立地成佛。");
        
        if ( !living(ob) )   return notify_fail("很显然，"+ob->name()+"听不见你说的话。\n");
        
        if ( me != ob->query("owner") || !ob->is_fighting(me) )
             { message_vision(CYN"$N说道：你罗嗦些什么，快滚开。\n"NOR,ob);
               return 1;
              }
                 
         guai_max_kee = ob->query("max_kee");
         guai_eff_kee = ob->query("eff_kee");
         
         if ( guai_eff_kee*100/guai_max_kee < 15 )
              {
                command("say 你说的有道理，我这就回山去。");
                me->set("rulaitask/accomplish",1);
                me->set("rulaitask/end_time",time());
                me->delete("rulaitask/get");
                destruct(ob);
                return 1;
               }
               
           else if ( guai_eff_kee*100/guai_max_kee < 20 )
                {
                        command("say 你看我现在，不比做佛快乐吗。");
                        me->start_busy(1+random(3));
                        return 1;
                 }
                 
            else {
                     me->start_busy(3);
                     return notify_fail(ob->name()+"正专心致志战斗，懒得理你。\n");
                  }
}


void die()
{       object me = owner();
        if (me->query("rulaitask/kind") == "杀"  && query("kind") == "杀")
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
  
  if ( ob->name() != "金创药" || ob->query("id") != "jinchuang yao" )
       { message_vision(CYN"$N说道：这是什么玩意儿，想毒死我啊。\n"NOR,guai);
         return 0;
        }
    else { guai->receive_curing("kee", 250);
           guai->receive_curing("sen", 250);
           message_vision(CYN"$N吃下一包金创药，气色看起来好多了。
\n"NOR,guai);
//           call_out ("destruct_ob",1,ob);
           if ( (query("eff_kee") == query("max_kee")) && (query("eff_sen") == query("max_sen")) )
                message_vision(CYN"$N说道：我好了，来来来，咱们再大战三百回合。\n"NOR,guai);
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
