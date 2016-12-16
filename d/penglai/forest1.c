//Room /d/penglai/forest1.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG

���������ľ���ӷ���ïʢ�ˣ����������˵Ҳ�м������
�����ˣ���Щ�����Ա߳������˵�������ֵ�ֲ����������
�Ļ���˵��������(search)��һЩ�滨��ݡ�
LONG);

	set("exits",([
		"east" : __DIR__"forest",
	]));
	set("num",10);

	setup();
}

void init()
{
	add_action("do_search","search");
	add_action("do_search","zao");
}

int do_search(string arg)
{
	object me = this_player();

	if(me->is_busy())
		return notify_fail("��������æ���أ�\n");

	if(me->query("kee") < 50)
		return notify_fail("������̫���ˣ�Ъ����ɣ�\n");

	if(query("num") <= 0)
		return notify_fail("����ûʲô���ҵ��ˣ�\n");

	message_vision("$N����ͷ���۾����ŵ��ϲ�֪������Щʲô��\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;
}

int finish(object me)
{
	object shouwu;

	if(random(me->query_kar()) > 15 )
	{
		message_vision("$N��ǰһ����������һ�������ڣ�\n",me);
		message_vision("����û��ע�⣬$N�Ѻ����ڴ����˻��\n",me);
		shouwu = new("/d/jz/herb/heshouwu");
		shouwu->move(me);
		add("num",-1);
		return 1;
	} else {
		message_vision("$N���˰���ʲôҲû�ҵ���\n",me);
		me->start_busy(3);
		return 1;
	}
}
