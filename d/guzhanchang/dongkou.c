//stone 20020613
///d/guzhanchang/dongkou.c

inherit ROOM;

void create ()
{
  set ("short", "洞口");
  set ("long", @LONG

这里竟然异常平静，感觉不到一点声音。暗流、漩涡一下都消失了，
也没有鱼虾出没。透过黑乎乎的河水，仿佛瞧见一个的洞口，洞中
黑咕隆咚，什么也看不清楚。地上沙石之间，还遗留着白惨惨的白
骨以及一些生锈的刀剑。

LONG);
  set("exits", ([
        "enter":   __DIR__"cave",
        "east":        __DIR__"tandi11",
        ]));
	set("objects",([        	
        	__DIR__"obj/goldstone" : 1,
        ]));
  setup();
}
