inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��С·���Ѿ��ߵ��˾�ͷ�����ƴ���һ��������(tree)��
�Ե�ʮ�ֵĴ�׳���м�ֻ��֪����С�������д�����ȥ�������׺�
����һ���ǳ�С������(cave)����ע�⣬�㻹�淢�ֲ��ˡ�
LONG);
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"xiaolu0",
	]));

	set("item_desc", ([
		"tree" : "һ�ô�����֦Ҷï�ܣ�����������������֦ͷ���������ӡ�\n",
	]) );
	set("no_fly",1);

	setup();
}

void init()
{
	add_action("do_enter", "zuan");
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object room;
	object who = this_player();
	if(!arg || arg != "cave")
		return notify_fail("��Ҫ�����\n");
	if(!( room = find_object("/d/city/center")) )
		room = load_object("/d/city/center");
	if(objectp(room))
	{
		message_vision("$N�����С������ǰ��Ȼһ������Ȼ�����˳������С�\n",who);
		tell_room( room, "����ǰһ����$N��֪�Ӻδ����˳�����");
		who->move(room);
	}
	return 1;
}
