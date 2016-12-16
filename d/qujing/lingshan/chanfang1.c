//crack by stey
 
inherit ROOM;
 
void check_zuochan(object me);
void finish(object me);
void reward(object me);
string chinese_time(int timep);
 
string *str=({
                "����������������\n",
                "�����һ��ʤ�����趼�ǹ������̡�\n",
                "������Լ�������һ��ǰ��δ�еľ��硣\n",
                "����ľ�����������\n"
                "�����������򵽷�ľ��衣\n",
                "���˼����������������\n"
             });
 
void create ()
{
  set ("short", "����");
  set ("long", @LONG
  
����յ����ģ�ֻ�ڿ���ǽ�ڵĵط���������ط���һЩ
���š�������ߺܰ���ǽ�ڲ�֪����ʲô�������ģ��ᷢ
�������Ļƹ⡣����������(zuochan)����ĺõط�����
Ҫ��ʵ�ڶ�������Ҳ���Գ�ȥ�����ٻ���(halt)��

LONG);

  set("exits", ([
          "south"   : "/d/qujing/lingshan/baoge1",
      ]));
  
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init()
{
    add_action("do_zuochan", "zuochan");
    add_action("do_halt", "halt");
}

int do_zuochan()
{       int zuochan_time;

        object me = this_player();
        
        if (me->query("rulaitask/get"))
             {tell_object(me,"��������������������������\n"); 
              return 1;
             }

        if (me->query_temp("zuochan"))
             {tell_object(me,"��������������\n");
              return 1;
             }

        message_vision("$N��ϥ����һ�������ϣ�Ǳ˼�붨����ʼ�����Լ���������Ϊ��\n",me);
        me->set_temp("no_move", 1);
        me->set_temp("zuochan", 1);
        if ( !me->query("rulaitask") )  finish(me);
        else {
                if (me->query("rulaitask/fail"))
                zuochan_time = 40+random(16);
                else zuochan_time = 15+random(16);
                me->set_temp("zuochan_time",zuochan_time);

                check_zuochan(me);
              }
                     
        return 1;
}


void check_zuochan(object me)
{       
        int zuochan_time = me->query_temp("zuochan_time");

        if ( zuochan_time == 0 ) finish(me);
        
        else {
                if ( zuochan_time%6 == 0 )
                      tell_object(me,str[random(sizeof(str))]);
                me->add_temp("zuochan_time", -1);
                call_out("check_zuochan",1,me);
              }
}

void finish(object me)
{
        tell_object(me,"��ֻ����̨һƬ�������ƺ������Ѿ���\n");
        message_vision("$N��������˿�����վ��������\n",me);
        me->delete_temp("no_move");
        me->delete_temp("zuochan");
        if (me->query("rulaitask/accomplish")) reward(me);
        me->delete("rulaitask");
}

void reward(object me)
{
        int wuxue,level,kind_bonus,level_bonus,timep;
        int extra_bonus,potential_bonus,combat_exp_bonus,daoxing_bonus;
        string str,kind,time,msg;
        
        wuxue = me->query("combat_exp");
        level = me->query("rulaitask/level");
        kind  = me->query("rulaitask/kind");     
        timep = me->query("rulaitask/end_time")-me->query("rulaitask/start_time");
        time  = chinese_time(timep);
                                                           // yxm *3
        if ( level == 1 ) level_bonus=300*3;
        else if ( level == 2 ) level_bonus=500*3;
        else level_bonus=700*3;
        
        if ( kind == "ɱ" ) kind_bonus=300*3;
        else if ( kind == "��" ) kind_bonus=400*3;
        else if ( kind == "Ȱ" ) kind_bonus=500*3;
        else kind_bonus=600*3;
                      
	if(wuxue<10000000) {
	    extra_bonus = (me->query("combat_exp")/1000)/4*2;
	} else if(wuxue<20000000) {
	    extra_bonus = (me->query("combat_exp")/1000)/5*2;
	} else if(wuxue<30000000) {
	    extra_bonus = (me->query("combat_exp")/1000)/7*2;
	} else if(wuxue<50000000) {
	    extra_bonus = (me->query("combat_exp")/1000)/8*2;
	} else if(wuxue<80000000) {
	    extra_bonus = (me->query("combat_exp")/1000)/9;
	} else if(wuxue<130000000) {
	    extra_bonus = (me->query("combat_exp")/1000)/10;
	} else if(wuxue<210000000) {
	    extra_bonus = (me->query("combat_exp")/1000)/11;
	}
	extra_bonus = 1000;
//	extra_bonus = (me->query("combat_exp")/1000)/4*2;   // yxm *2
        
        potential_bonus = (random(extra_bonus) + level_bonus + kind_bonus)/2;
        combat_exp_bonus = (extra_bonus*6 + (random(level_bonus) + random(kind_bonus))*3)/3;
        daoxing_bonus = (extra_bonus*6 + (random(level_bonus) + random(kind_bonus))*3)/3;
        
        me->add("potential", potential_bonus);
        me->add("combat_exp", combat_exp_bonus);
        me->add("daoxing", daoxing_bonus);
        str = "�õ���"+potential_bonus+"��Ǳ�ܣ�";
        str +=combat_exp_bonus+"��ѧ���飬";
        str += COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�\n";
        
        tell_object(me,"��õ���"+potential_bonus+"��Ǳ�ܣ�"+combat_exp_bonus+"��ѧ���飬"+COMBAT_D->chinese_daoxing(daoxing_bonus)+"���С�\n");
        str = me->name()+"�����һ���Ѷ�"+chinese_number(level)+"��"+kind+"������\n" + str;
        str = str + "��ʱ"+time+"��\n";
        if ( level > 1 ) CHANNEL_D->do_channel(me, "rumor",str);
        MONITOR_D->report_system_msg (str);
        log_file("taskreward",sprintf("[%s]%s\n",ctime(time()),str));	
     
        switch (kind)
          {case "ɱ": {
                        me->add("rulaitask_log/kill_potential",potential_bonus);
                        me->add("rulaitask_log/kill_combat",combat_exp_bonus);
                        me->add("rulaitask_log/kill_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/kill1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/kill2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/kill3",1);
                             }
                         break;
                      }
          case "��": {
                        me->add("rulaitask_log/arrest_potential",potential_bonus);
                        me->add("rulaitask_log/arrest_combat",combat_exp_bonus);
                        me->add("rulaitask_log/arrest_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/arrest1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/arrest2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/arrest3",1);
                             }
                         break;
                      }
          case "Ȱ": {
                        me->add("rulaitask_log/persuade_potential",potential_bonus);
                        me->add("rulaitask_log/persuade_combat",combat_exp_bonus);
                        me->add("rulaitask_log/persuade_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/persuade1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/persuade2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/persuade3",1);
                             }
                         break;
                      }
          case "��": {
                        me->add("rulaitask_log/fight_potential",potential_bonus);
                        me->add("rulaitask_log/fight_combat",combat_exp_bonus);
                        me->add("rulaitask_log/fight_daoxing",daoxing_bonus);
                
                        switch (level)
                            {case 1:{me->add("rulaitask_log/fight1",1);
                                     break;
                                     }
                              case 2:{me->add("rulaitask_log/fight2",1);
                                      break;
                                     }
                              case 3: me->add("rulaitask_log/fight3",1);
                             }
                     }                        
          }
}                               

int do_halt()
{
        object me = this_player();
        if (me->query_temp("zuochan"))
           {remove_call_out("check_zuochan");
            me->delete_temp("zuochan_time");
            message_vision("$N��������˿�����վ��������\n",me);
            me->delete_temp("no_move");
            me->delete_temp("zuochan");
            return 1;
           }
         else return 0;
}       
        


string chinese_time(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        
        return time;
}