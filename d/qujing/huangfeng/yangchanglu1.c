//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�ߵ�ɽ·�ϣ�����Զ���Ĵ�ɽ������ô�ɽ���Ǹ��հ���ɽ�����
���ϣ�ɽ·����᫣�·�Ծ���Щ��ʯ��ľ��
LONG);

  set("exits", ([
        "north" : __DIR__"huangfeng4",
        "southeast" : __DIR__"yangchanglu2",
		"southwest" : __DIR__"songshulin",
      ]));
  set("outdoors","hfd");
  setup();
}

int valid_leave (object me, string dir)
{
	if (dir == "southeast" && !me->query("obstacle/huangfeng")
	&& !wizardp(me) )
        return notify_fail("��е����󱳺�����������һ������Ȼһ����������ȥ��\n");
	return 1;
}
