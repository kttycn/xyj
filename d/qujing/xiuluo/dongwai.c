#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "�ħ����");
	set ("long", @LONG

�����������ħ������ĵط�������д�š��ħ���⡱���֡�
��ǰ����ɭ�ϡ���ע�⵽���Ϲ���һ��������������ȥ��Ϊ���ס�

LONG);

	set("exits", 
	([ //sizeof() == 4
		"up" : __DIR__"diyu18",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/gui" : 2,
		__DIR__"npc/jinchanzi" : 1,
	]));

	setup();
}
void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;
	me = this_player();

	if( !arg || arg != "door" ) 
		return notify_fail("��Ҫ��ʲô��\n");
	if( !(key = present("qiongji zhishi", me)) ) 
		return notify_fail("û��Կ����ô���ţ�\n");
	if( !(nroom = find_object(__DIR__"modong")) )
		nroom = load_object(__DIR__"modong");

	set("exits/north", __DIR__"modong");
	nroom->set("exits/south", __FILE__);
	message("vision", "���ó�Կ�ף������š�\n", this_object() );
	message("channel:rumor", HIR+"�������޽硿���������Ц�˼�������\n"+NOR,users());
	message("channel:rumor", HIR+"�������޽硿ħ�����죨wu tian): "+me->query("name")+"�����������������Ͼ�ѧ-Ǭ��ͼ��\n"+NOR,users());
	message("channel:rumor", HIY+"����硿�������� (rulai fo): "+me->query("name")+"��Ȼ��˵�����Ϊ�������ﲻ��ˡ��\n"+NOR,users());
	destruct(key);
	return 1;
}
