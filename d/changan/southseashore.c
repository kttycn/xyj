//Cracked by Roath
// Room: /changan/southseashore.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "�Ϻ�֮��");
	set ("long", @LONG

�Ϻ�֮����������һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�
��������һƬ����󺣣���֪ͨ��η������Ϻ����������ɼ�
һС����ǳ�����������м�����Ӿ���ˡ�
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"broadway5",
		"west" : __DIR__"jiaoshi",
		"east" : __DIR__"seashore1",
	]));
	set("outdoors", "changan-south");

	setup();
}

void init()
{
	add_action("do_swim", "swim");
}

int do_swim()
{
	object  me, horse;
	me = this_player();

  if(me->query_temp("ridee"))
  {
      horse=me->query_temp("ridee");
      me->command_function("dismount "+horse->query("id"));
   }                        
/*	if (me->query_temp("ridee"))
		me->query_temp("ridee")->set_temp("rider",0);
	me->set_temp("ridee",0);
	me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
	me->set_temp("ride/dodge",0);
*/

message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε��˺���С���ϡ�\n" NOR, me);

	me->move("/d/nanhai/island");
	message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
	me->receive_damage("kee", 20);
	me->receive_damage("sen", 20);
	return 1;
}

