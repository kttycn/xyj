// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng5.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

����Ƶ������ط��ᡣ���۵Ĳ��ɴ�أ��̲�����һ��
СϪ��·������ˮ�����ˣ���Ȼһ��������ɫ����ֻС��
���������Ӳ���������һת���ܵò�֪���١�

LONG);

  set("exits", ([
        "southwest" : __DIR__"huangfeng4",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}

void init()
{
	object me=this_player();
	if (me->disable_player("<˯����>"))
		return;
	if (me->query_temp("lingji1_done")=="yes" && 
	!me->query("obstacle/huangfeng") )
	{
		message_vision("$N�ɻ�Ŀ������ܣ��������������龰��ȫ��ͬ��\n",me);
		me->delete_temp("need_sleep");
		return;
	}
}
