inherit ROOM;
void init();
int do_move(string arg);
int do_enter(object me);

void create()
{
	set("short","��԰");
	set("long",@LONG
�����ǰ������һ�������Ļ�԰����԰������һЩ������������Լ��
��Ʈ���ٻӰ�����Ǹ��е�Ѿ��������ˣ����԰������һ����ɽ(jiashan)��
��԰�Ķ�����ͷ�ǳ��ȣ��ϱ���һ��С����֪ͨ����????
LONG );
	set("exits",([
		"south"	: __DIR__"xiaolu0",
		"north"	: __DIR__"zoulang2",
		"east"	: __DIR__"qianyuan",
	]));
	set("outdoors", "fenghuang");
	set("item_desc", ([
		"jiashan" : "������ɽ����������̫����Ӧ�ÿ��԰ᶯ(move)��.\n",
	]));
//	set("no_clean_up", 0);
	set("no_fly",1);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{			
	object mishi;
	object me=this_player();
	if(!arg || arg!="jiashan")
		return notify_fail("��Ҫ�ƶ�ʲô��\n");
	if((int)me->query_str()>68)
	{
		if( !(mishi = find_object(__DIR__"anshi")) )
			mishi = load_object(__DIR__"anshi");

		if( mishi ) 
		{
			set("exits/enter", mishi);
			message_vision("$Nʹ�����̵�������ȥ��ֻ��������������ɽ�ƿ���¶������һ��ͨ�ڡ�\n", this_player());
			message("vision", "��ʯ���˴����ƿ��ˡ���\n", mishi );
			mishi->set("exits/out", __DIR__"huayuan2");
			call_out("close_down", 30);
		}
		return 1;
	}
	else
		message_vision("$Nʹ�����̵�����ҲŲ������ɽ��ֻ���㬵ط����ˡ�\n", this_player()); 
	return 1;			 
}

void close_down()
{
	object mishi;

	message("vision", "��ɽ���һ���ֻص�ԭλ��\n", this_object() );
	if( mishi= find_object(__DIR__"mishi1")) {
		message("vision", "��ɽ���һ���ֻص�ԭλ��\n", mishi);
		mishi->delete("exits/out");
	}

	delete("exits/enter");

}
