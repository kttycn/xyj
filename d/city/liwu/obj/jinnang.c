#include <ansi.h>
#include <dbase.h>
#include <armor.h>
#define MAX_SAVE 5
inherit F_AUTOLOAD;  
inherit ITEM;

object focusobj;

void create()

{
	set_name(HIR"����"NOR, ({ "jin nang" ,"jinnang","jin" }) );
	set_weight(100);
	set("long","����һ��С������Ľ��ң�ר��������(put)ȡ(get)������Ʒ��\n");
	set("value", 1);
	set("material", "cloth");
	set("no_drop", "��ô�ѵõĽ��һ������Űɡ�\n");
	set("unit", "��");
	set("is_monitored",1);
	setup();
}


void init()
{
   add_action("do_put", "put");
   add_action("do_get", "get");
   add_action("do_look", "look");
}


int do_put(string arg)
{
	object me=this_player(),ob;
	string msg,obj_file;
	int save_objects,new_one=1,value;
	string from_ob,put_ob;
	if(!arg)return 0;
	sscanf(arg,"%s in %s",put_ob,from_ob);

	if(!put_ob||!from_ob||(from_ob!="jin nang"&&from_ob!="jin"&&from_ob!="nang"))
		return 0;

	if(me->is_busy())
	{
		tell_object(this_player(),"�����Ķ�����ȻҪ����������\n");return 1;
	}

	ob=present(put_ob,me);
	if(ob) 
	{
		if (ob->query_weight()>800)	//ԭΪ>0
			return notify_fail("�����������ڽ��Ҷ���̫���ˡ�\n");

		if (ob->query("no_drop"))
			return notify_fail("�����������ܷŽ����ҡ�\n");

		if (ob->query("money_id"))
			return notify_fail("Ǯ��������֮�������ôС�İɣ�\n");

		if (ob->query("food_supply"))
			return notify_fail("ʳ��Ҳ��ŵ�������ȥ�������ʱ��ȥ������\n");

		save_objects=me->query("jinnang_objects");
		if(save_objects>=MAX_SAVE){tell_object(this_player(),"�����Ѿ��������κζ����ˣ�\n");return 1;}
		msg=base_name(ob);
		obj_file="jinnang_save"+save_objects;
		me->set(obj_file,msg);
		save_objects=save_objects+1;
		me->set("jinnang_objects",save_objects);
		me->start_busy(1);
		message_vision("$N�ó�һ"+ob->query("unit")+ob->query("name")+"�Ž��˽��ҡ�\n",me);
		destruct(ob);    
		return 1;
	}
	else {tell_object(this_player(),"������û������������\n");return 1;}
}

int do_look(string arg)
{
	int i,total_save; 
	object ob,me=this_player();
	if(arg!="jin"&&arg!="jin nang"&&arg!="nang")
		return 0;
	tell_object(me,"����һ��С������Ľ��ң�ר��������Ź�����Ʒ��\n");   
	total_save=me->query("jinnang_objects"); 
	if(total_save)
		tell_object(me,"����װ�У�\n");   
	else
		tell_object(me,"����û��װ�κζ�����\n");   

	for(i=0;i<total_save;i++)
	{
		ob=new(me->query("jinnang_save"+i));
		if(ob)
			tell_object(me,i+"   "+ob->query("name")+"  ("+ob->query("id")+")\n");   
		destruct(ob);
	}
	return 1;
}


int do_get(string arg)
{
	object ob,me=this_player();
	int i,j,total_save,get_ob,max_weight=me->query_max_encumbrance(),now_weight=me->query_encumbrance(); 
	string from_ob;

	sscanf(arg,"%d from %s",get_ob,from_ob);

	if(!from_ob||(from_ob!="jin nang"&&from_ob!="jin"&&from_ob!="nang"))
		return 0;

	if(me->is_busy())
        {tell_object(this_player(),"�����Ķ�����ȻҪ����������\n");return 1;}  

	total_save=me->query("jinnang_objects"); 
      if(total_save<=0) 
         {
          tell_object(me,"���ҿտ���Ҳ��û��ʲô���������ó����ˡ�\n");      
          return 1;
         }

      if(get_ob>(total_save-1)||get_ob<0)
         {
          tell_object(me,"�����ʽ�� get (��Ʒ���) from jin nang\n");      
          return 1;
         }

	ob=new(me->query("jinnang_save"+get_ob));
             if(!ob)
         {
         tell_object(me,"��������������������ò�����������֣�\n");
         return 1;
         }
           if(ob->query_weight()+now_weight>=max_weight)
         {
         tell_object(me,"��������������������ò������������Ǹ��ع����ˣ�\n");
         return 1;
         }

      tell_room(environment(me),"�㿴��"+me->query("name")+"͵͵�ӽ������ó�ʲô�����Ž����\n",me);      
      tell_object(me,"��͵͵�ӽ������ó�һ"+ob->query("unit")+ob->query("name")+"�Ž����\n",me);      
           ob->move(me);
       for(i=get_ob;i<total_save-1;i++)
         {j=i+1;
         me->set("jinnang_save"+i,me->query("jinnang_save"+j));     
         }
         me->add("jinnang_objects",-1);
      me->start_busy(1);
     return 1;
}


int query_autoload() { return 1; }
int is_container() { return 1; }