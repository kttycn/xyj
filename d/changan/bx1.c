//By waiwai@mszj 2000/10/26

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "Ұ����ҽ�����󲡷�");
	set("long", 

"\n����������ǿ��վ��Ұ����ҽ�ݵ����󲡷��������һ��\n"+
"��"+HIR"(bed)"+NOR"�ɹ���úõ���Ϣ��û�˻ᵽ���������......\n\n"

	);
	set("item_desc",(["bed":"˯���õĴ���(gosleep,gobed,bed)�� \n", ]));

	set("exits", ([
		"out" : "/d/changan/wside5",
	]) );

	setup();
}
void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed" );
	add_action("do_bed", "bed");

}
int do_bed()
{
	object me;
	me=this_player();
	message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
  	me->move("/d/changan/bed_mg");
	message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
	return 1;
}
