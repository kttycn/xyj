#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_AUTOLOAD;  
inherit ITEM;

object focusobj;

void create()

{
     set_name(BLINK+HIY"�¹�"NOR+YEL"����"+NOR, ({ "goldbox","baohe","moonbox" }) );
     set_weight(100);
     set("long","����Ǵ�˵�е��������µ�"HIY"�¹�"YEL"����"NOR"����˵��˲���ƶ�(move)�����á�\n");
     set("value", 0);
     set("material", "gold");
     set("no_drop", "��ô�ѵõı��ﻹ�����Űɡ�\n");
     set("no_get","�����㣡���������������\n");
     set("unit", "��");
	set("is_monitored",1);
}


void init()
{
   add_action("do_move", "move");
   add_action("do_mark", "mark");
}


int do_move()
{
	object me=this_player(); 

	if(me->is_fighting())
		return notify_fail("������㻹����ֻ���п�ȥ���¹ⱦ���أ�\n");

/*	if(me->query("yinyangling")==0)
		me->set("yinyangling",me->query("mud_age"));
	else if(me->query("mud_age")-me->query("yinyangling")>86400)
	{
		me->set("yinyangling",0);
		tell_object(me,HIY"���Ҫ�����ͻȻ�������е��¹ⱦ�������ڻ���ֻ��������
��������Ϊһ�������ʧ�ڿ����С�\n"NOR);   
		destruct(this_object());
		return 1;
	}*/

	if( !query("mark_place") ) return notify_fail("���� mark ��Ŀ�ĵ����ϼǺš�\n");

	tell_room(environment(me),YEL+me->query("name")+"˫��΢�գ������������"
		"�����������ܡ�\n"
		BLINK+HIY"һ��ѣĿ�Ĺ�����..... \n"
		"�㲻�ɱ�����\n"
		"�����ſ���ʱ,"+me->query("name")+"����Ӱ�Ѿ���ʧ����Ӱ����.\n"NOR,me);

	tell_object(me,HIY"��˫��΢�գ������������"
		"�����������ܡ�\n"
		"�����Ӱ����һ��ѣĿ�Ĺ������Ѿ���ʧ����Ӱ����.\n"NOR);
	me->move(query("mark_place"));
	message_vision(HIY"һ��ҫ�۵Ĺ�������$N����ӰͻȻ�����ˡ�\n"NOR, me);

	return 1;
}


int do_mark()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("������㻹����ֻ���п�ȥ���¹ⱦ���أ�\n");

/*  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>86400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"���Ҫ�����ͻȻ�������е��¹ⱦ���������ڻ���ֻ��������
��������Ϊһ�������ʧ�ڿ����С�\n"NOR);   
        destruct(this_object());
        return 1;
       }*/

  set("mark_place",base_name(environment(me)));

  tell_room(environment(me),HIY+me->query("name")+"���������¹ⱦ�У������������˼������\n"NOR,me);
 
  tell_object(me,"����������¹ⱦ�У������������˼������\n"
            +HIY"���Ȼ���������¹ⱦ������һ�¡�\n"NOR);
       return 1;
}

int query_autoload() { return 1; }
