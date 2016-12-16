// Room: /d/liwu/dog_room.c

inherit ROOM;
#include <ansi.h>
#include <dbase.h>



void create()
{
	set("short", HIC"���������"NOR);
	set("long", @LONG
����һ����ģ���ܴ�ĳ�������ݣ�ԶԶ��Ϳ���������Ժ�Ĺ�������
���������ס�Ĳ�ϰ�߰ɡ���ÿһ���˳�ǰ����԰���ĳ����ȼ���������
����̨������һ��Ц���е�С��������æ�Ž����͡���̨���Ա߷���һ���
�������(sigh)��
LONG
	);

	set("exits", ([
		"west"      :__DIR__"dogjie",
	]));

	set("item_desc", ([
		"sigh" : "�����ṩ�����������
         ������   jiyang  <������>
         ��أ�   linghui <�������> 
         ������   name <����> <����>
         �鿴��   chakan     
�������������һ���ƽ�ķ��á�ÿ���޼�����ֻ���      \n",
                            
	]));

	set("objects", ([
		__DIR__"npc/siyang_yuan" : 1,

	]));

	setup();
	
}

 void init()
 {
	add_action("do_jiyang","jiyang");
    add_action("do_linghui","linghui");
    add_action("do_chakan","chakan");
    add_action("do_name","name");
  }

 int do_name(string arg)
 {
   object me=this_player();
   object ob;
   string dog_id,dog_name;

      
   if(!objectp(present("siyang yuan", environment(me))))
          return 0;  
   if(!arg)
      return notify_fail("��Ҫ��ʲô��\n");
   
   sscanf(arg, "%s %s", dog_id,  dog_name);

   if(!dog_id||!dog_name)
      return notify_fail("��Ҫ��ʲô��\n");
   
   ob =present(dog_id,environment(me));

   if(!ob)
      return notify_fail("�������û����ֻ����ɣ�\n");
 
   if(ob->query("boss_id")==me->query("id"))
       {
   switch (MONEY_D->player_pay(this_player(), 10000))
      {
	case 0:  //destruct(ob);    
		return notify_fail("�ĳ����������һ���ƽ�ķ���Ү��\n");
	case 2:  //destruct(ob);    
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
        ob->set("name","("+me->name(1)+"��)"+dog_name);
        message_vision("$N����һ���ƽ������Ա��\n",me);
        return 1;
      }
       }
    else return notify_fail("ȥ����ĳ��������\n");
}

int do_chakan()
{
      object me=this_player();
          int i;
       
     if(!objectp(present("siyang yuan", environment(me))))
                 return 0;

     if(me->query("total_jiyang_count")==0)
        tell_object(me,"��Ŀǰû�����κγ��\n");
       else 
        {
    	printf("������ĳ����У�\n");
		for (i = 1; i <=me->query("total_jiyang_count") ; i++)
                   printf("%3d   %s\n",i,me->query("chongwu_name"+i));
          }
	return 1;
  }

  int do_jiyang(string arg)
  {
   
       object me=this_player(),ob;
       string directory;
       int count,i;

       if(!objectp(present("siyang yuan", environment(me))))
                 return 0;
      if(query_temp("busy"))
        {tell_object(this_player(),"����Ա�ض���˵:\"�Ե�һ�����\"\n");return 1;}  

       if(me->is_busy())
            return notify_fail("����æ���أ�\n");  

       if(!arg)
             return notify_fail("��Ҫ����ʲô��\n");

           
       count=(int)me->query("total_jiyang_count"); 
       if(count>=2)
              return notify_fail("���Ѽ�������ֻ�����ˡ�\n");
              
       ob =present(arg,environment(me));
       if(!ob)
          return notify_fail("�������û����ֻ����ɣ�\n");
       if(ob->query("boss_id")==me->query("id"))
         {

/*******Save data************/

           count++;
           directory=base_name(ob);
           me->set("chongwu_dir"+count,directory);
           me->set("chongwu_name"+count,(string)ob->query("name"));
           me->set("chongwu_combat_exp"+count,(int)ob->query("combat_exp"));
           me->set("chongwu_mud_age"+count,(int)ob->query("mud_age"));
           me->set("total_jiyang_count",count);
           me->start_busy(1);

/***************************/

           message_vision("$N��һ"+ob->query("unit")+ob->query("name")+"����������Ա��\n",me);                                  
           destruct(ob);    
           set_temp("busy",1);
           call_out("del_busy",1);  

           return 1;

           
         }
        
        return notify_fail("ȥ����ĳ��������\n");
   }


int do_linghui(string arg)
 {
      object me=this_player(),ob;
          int order,i;

    if(!objectp(present("siyang yuan", environment(me))))
                 return 0;
    if(query_temp("busy"))
        {tell_object(this_player(),"����Ա�ض���˵:\"�Ե�һ�����\"\n");return 1;}  

     if(!arg  || arg=="")
         return notify_fail("�������ʲô���\n");

    sscanf(arg,"%d",order);
      order-=1;  
      
    if(me->is_busy())
        return notify_fail("����æ���أ�\n");  

     else if(order<0||order>=me->query("total_jiyang_count"))
          printf("�����û�м��������ɣ�\n");
     else 
      {    order+=1;
                
        ob=new(me->query("chongwu_dir"+order));
	switch (MONEY_D->player_pay(this_player(), 10000)) {
	case 0:  //destruct(ob);    
		return notify_fail("��س�����һ���ƽ�ķ���Ү��\n");
	case 2:  //destruct(ob);    
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
 /***********Load data***************/
            ob=new(me->query("chongwu_dir"+order));
            ob->set("combat_exp",me->query("chongwu_combat_exp"+order));
            ob->set("boss_id",me->query("id"));
            ob->set("mud_age",me->query("chongwu_mud_age"+order));
            ob->set("gender","����");
            ob->set("name",me->query("chongwu_name"+order));
            ob->set_leader(me);
 /***********************************/


            me->set("total_jiyang_count",me->query("total_jiyang_count")-1);
            me->start_busy(1);
                for(i=order;i<=me->query("total_jiyang_count");i++)
                   {
                      me->set("chong_dir"+i,(string)me->query("chongwu_dir"+i+1));
		      me->set("chong_name"+i,(string)me->query("chongwu_name"+i+1));	
                    }
            if(me->query("chongwu_mud_age"+order)> 286400)
               { 
                  destruct(ob);
                  return notify_fail("����Ա˵����ĳ�����Ϊ����������ˡ�\n");
               }
            ob->move(environment(me));
          
      message_vision("$N������Ա�������һ"+ob->query("unit")+ob->query("name")+"��\n",me);
      set_temp("busy",1);
           call_out("del_busy",1);  
	}
      }

	return 1;
  }


  
void del_busy()
{
   delete_temp("busy");
}
