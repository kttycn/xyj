// created by snowcat.c 4/4/1997
// room: /d/nverguo/towna2.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

������������İ������С�������һ�߸ߵĴ��ţ���������
������Ҫ��ڡ�����Ů������������Χ��һ��̸��������
�������µ�����һ�¡�

LONG);

  set("exits", ([
        "northup" : __DIR__"entry",
        "north" : __DIR__"jitan",
        "west"    : __DIR__"towna1",
        "east"    : __DIR__"towna3",
        "south"   : __DIR__"townb2",
    ]));
  set("outdoors", __DIR__"");

  setup();
}

int valid_leave(object me, string dir)
{
		if(dir =="north" && me->query("id")=="fe zei" ||("id") == "thief" ||("id") == "zei")
			return 0;
		return ::valid_leave(me, dir);
}







