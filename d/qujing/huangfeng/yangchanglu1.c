//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

走到山路上，看着远方的丛山，你觉得此山真是个险啊，山峰迭障
不断，山路起浮崎岖，路旁尽是些奇石怪木。
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
        return notify_fail("你感到好象背后有人在拉你一样，竟然一步都迈不出去！\n");
	return 1;
}
