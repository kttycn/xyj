
//shuitan.c Ѱˮ����
#include <ansi.h>
inherit ROOM;
int do_dive();
int do_jump();
void create()
{
	set("short", "ˮ̶");
	set("long", @LONG
ӭ����һ���ٲ���������һ���޴��ˮ̶���ٲ���к��ˮ̶���������ľ��졣
�ɽ���ˮ���������³����������Ĳʺ硣̶������ɫ����������ȥ��
LONG);
	set("exits", ([
		"northeast" : __DIR__"shangu2",
	]));
	set("resource", ([
		"water" : 1,
	]) );

	setup();
}
void init()
{
	add_action("do_dive","dive");
	add_action("do_jump","jump");
}

int do_dive()
{
	object zhou,who,room;

	who = this_player();
	if(( !(zhou=present("bishui zhou", who))
	||(string)zhou->query("unit")!="��")
	&& (string)who->query("family/family_name")!="����"
	&& (string)who->query("family/family_name")!="��������")
		return notify_fail("��һ����������ˮ�����\n"+
		"\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");
	message_vision(HIY "$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n" NOR, who);
	if(!( room = find_object(__DIR__"tandi")) )
		room = load_object(__DIR__"tandi");
	if(objectp(room))
	{
		who->move(room);
		message_vision("$NǱ����̶�ס�\n",who);
	}
	return 1;
}

int do_jump()
{
	object zhou,who,room;

	who = this_player();
	message_vision(HIY "$N��������ѽ��......\n" NOR, who);
	if( !(who->query_temp("ask_qingsuo_li") 
	|| who->query_skill("dodge", 1) < 150 ))
	{
		message_vision(CYN"\n����ʯ��̫�⻬��$Nһ��С�Ļ�������������\n"NOR, who );
		who->unconcious();
		return 1;
	}
	if(!( room = find_object(__DIR__"shulin0")) )
		room = load_object(__DIR__"shulin0");
	if(objectp(room))
	{
		message_vision(CYN"\n$N����һ����������ȥ��\n����һ��,�벻�����ﾹ�������ء�\n\n"NOR,who);
		who->move(room);
	}
	return 1;
}
