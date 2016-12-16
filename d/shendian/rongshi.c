#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", HIG"����"NOR);
	set ("long", @LONG

����������̨�ϵ�����һ�����䡣����������(xiuxing)�ĵط���

LONG);
	set("exits", ([ /* sizeof() == 1 */
                 "west" : __DIR__"tianshentai",
                 ]));
	set("no_clean_up", 1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("alternative_die",1);
	set("sleep_room", 1);
	setup();
}       
void init()
{
	add_action("do_xiuxing", "xiuxing");
}
int do_xiuxing()
{
	int myspells, myspi, learned, sencost;
	object me = this_player();
	int num;
	num = 0;
	if((int)me->query("daoxing") < 2000000)
		num = 150;
	else
	{
		if((int)me->query("daoxing") < 3500000) num = 250;
		else num = 350;
	}
	if((int)me->query_skill("spells",1) < num)
	{
		if(me->query("babu/shendian") == "done")
		{
			myspells = me->query_skill("spells");
			myspi=(int)me->query_spi();
			learned=(myspells+myspi)/6;

			if( myspells < 100 )
				sencost = 30+(myspells/10);
			else  
				sencost = 30+(myspells/5);

			if ((int)me->query("sen")<=sencost)
				return notify_fail("�����ǲ��壬��������ȥ����Σ�յģ�\n");
			if(me->query("mana")<=(sencost/2))
				return notify_fail("��ķ������㣬����������ķ�����\n");
			me->receive_damage("sen", sencost);
			me->add("mana", -(sencost/2));
			tell_object (me, "��ġ��������������н�չ��\n");
			me->improve_skill("spells",learned);
			return 1;
		}
		else
		{
			message_vision(HIY"$N��ô�����ģ���ȥ�ɣ�\n"NOR,this_player());
			message_vision(HIY"$N��һ���߳�������֮�\n"NOR,this_player());
			this_player()->move("/d/city/kezhan");
			return 1;
		}
	}
	else
	{
		message_vision(HIW"$N����Ϊ�Ѿ������ˣ�\n"NOR,this_player());
		return 1;
	}
}