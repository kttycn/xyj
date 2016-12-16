// ������ ������ by Calvin

#include <ansi.h>
inherit ROOM;
#include <room.h>
string direction_name(string);
string direction_rev(string);

void create ()
{
  set ("short", WHT"������"NOR);
  set ("long", @LONG

�ഫ�����ɽ�����������裬��Ϊ�ĳ����ṩ�ĳ��ɱ㾶��
ֻҪ���ĵõ�����������ȥ�ͻ����ɣ����μ�������....
�������������ȥ(jump down)��

LONG);

  set("exits", ([ /* sizeof() == 3 */
//  "up": __DIR__"lingge",
]));

  setup();
}
void init() {
	add_action("do_jump","jump");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_jump(string arg) {
  object me=this_player(),ridee=me->ride();
  int damage;
  string dest=__DIR__"lukou0";

  string msg;

   if (!arg) return 0;
  if (arg!="down") return notify_fail("���Ķ�����\n");

  msg="$N";
  if (ridee) msg=msg+"����"+ridee->query("name");
  msg+="�������µ�Ծ�¡�\n\nһ���İ�������Ľ���ƮƮ������\n\n";
  message_vision(msg,me);

  damage=random(300-me->query_skill("dodge"));
  if (damage>me->query("eff_kee")-200) damage=me->query("eff_kee")-200;
  if (damage<=0) damage=0;
  me->receive_wound("kee",damage);
  me->move(dest);
  if (ridee) ridee->move(dest);
  if (!damage) message_vision("$N�������������������������ɵ����ڵ��ϣ�����δ��\n",me);
  else {
  message_vision("$N���������������������˸��������\n",me);
  COMBAT_D->report_status(me); 
  }
  if (ridee) {
      message_vision("\n$N���ŵ�"+ridee->query("name")+"ˤ����һ�������",me);
      ridee->die();
  }
  me->start_busy(1+random(2));
  return 1;
}


int do_climb(string arg)
{
	object me;

	me=this_player();
	
	if( !arg || (arg != "left" && arg != "right" && arg != "up" && arg != "down") ){
		return notify_fail("��Ҫ��������ȥ��\n");
	}

	if( arg == "right" ) 
	{
		message_vision("$N�����ұڣ���ץʯ�����"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move("/d/wusheng/xuanya3");
	}

	else return notify_fail( "��"+direction_name(arg)+"�Ѿ�û������֮���ˡ�\n" );

	message_vision("$N��"+direction_rev(arg)+"�����˹���������������һ������\n", me);   
	return 1;    

}

string direction_name(string arg)
{
	if ( arg == "right" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else return "��֪���Ķ�";
}

string direction_rev(string arg)
{
	if ( arg == "right" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else return "��֪���Ķ�";
}