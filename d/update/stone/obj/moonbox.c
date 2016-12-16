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
     set("no_drop", "��ô�ѵ����õı��ﻹ�����Űɡ�\n");
     set("no_get","�¹ⱦ���ƺ���ǧ��֮�أ���ʹ�����̵ľ�Ҳ�ò�����\n");
     set("unit", "��");
	set("is_monitored",1);
}


void init()
{
   add_action("do_move", "move");
   add_action("do_sign", "sign");
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

	if( !query("sigh_place") ) return notify_fail("���� sigh ��Ŀ�ĵ����ϼǺš�\n");

	tell_room(environment(me),YEL+me->query("name")+"˫��΢�գ������������"
		"�����������ܡ�\n"NOR
		BLINK+HIY"һ��ѣĿ�Ľ������.....\n"NOR
		"�����ſ���ʱ,"+me->query("name")+"����Ӱ�Ѿ���ʧ����Ӱ����.\n"NOR,me);

	tell_object(me,HIY"��˫��΢�գ������������"
		"�����������ܡ�\n"NOR
		BLINK+HIY"�����Ӱ����һ��ѣĿ�Ľ������,��ʧ����Ӱ����.\n"NOR);
	me->move(query("sigh_place"));
	message_vision(HIY"һ��ҫ�۵Ľ��������$N����ӰͻȻ�����ˡ�\n"NOR, me);

	return 1;
}


int do_sign()
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

  set("sigh_place",base_name(environment(me)));

  tell_room(environment(me),HIY+me->query("name")+"���������¹ⱦ�У������������˼������\n"NOR,me);
 
  tell_object(me,"����������¹ⱦ�У������������˼������\n"
            +HIY"���Ȼ���������¹ⱦ������һ�¡�\n"NOR);
       return 1;
}

int query_autoload() { return 1; }
