// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng5.c


inherit ROOM;

void create ()
{
  set ("short", "黄风岭");
  set ("long", @LONG

天高云淡，雾重风轻。满眼的苍松翠柏，碧草琼花。一条
小溪绕路奔流，水声叮咚，果然一派秀丽景色。几只小兽
听见人声从草中跳出，一转眼跑得不知所踪。

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
	if (me->disable_player("<睡梦中>"))
		return;
	if (me->query_temp("lingji1_done")=="yes" && 
	!me->query("obstacle/huangfeng") )
	{
		message_vision("$N疑惑的看看四周，和昨天遇到的情景完全不同。\n",me);
		me->delete_temp("need_sleep");
		return;
	}
}
