//stone 20020611
///d/guzhanchang/shuitan.c 
#include <ansi.h>
inherit ROOM;
int do_dive();

void create()
{
	set("short", "ˮ̶");
	set("long", @LONG

չ��������ǰ�Ǹ���Լ���ɵ���̶����վ�ڰ��ߵĴ�ʯͷ��Զ����
ֻ��̶ˮɫ�ʱ������ڳ����ģ�����ף�̶�İ�����ӿ������
�������γ�һ���޴�����У�̶�в���һ����Ϻ�ζ���

LONG);
	set("exits", ([
		"east" : __DIR__"pondside",
	]));
	set("resource", ([
		"water" : 1,
	]) );
	set("no_clean_up", 0);
	set("outdoors", "guzhanchang");
	setup();
}

void init()
{
	object who=this_player();
//	object where=this_object();
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
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
	message_vision(HIY "$Nһ����Ծ������ͨ��һ��������̶�С�\n��̶ˮ��Ȼ���գ�$N��һ��ˮ����ð��һð��������һ����ʱ����̶ˮ���ġ�\n" NOR, who);
	if(!( room = find_object(__DIR__"tandi1")) )
		room = load_object(__DIR__"tandi1");
	if(objectp(room))
	{
		who->move(room);
		message_vision("$NǱ����̶�ס�\n",who);
	}
	return 1;
}

int sounding(object where)
{
    string *msgs=({
    "ˮ���ϲ�ʱ����һ˿˿�������̰�������ȥ��\n",    
    "̶�е�ˮ��ཹ�ཱུ�ð�����������ݡ�\n",
    "һ�����İ�������̶�������ѻ�������\n",
    "һ���ŵ����𽥾ۼ���̶�����������ˡ�\n",
    "һ���ӭ�洵������Ȼ���������ڵġ�\n",    
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}
