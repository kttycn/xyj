// �����硤���μǣ����ͣ�
// create by jing 2000.8.8
// Room: /d/xuyi/xiaolu12-17.h

inherit ROOM;

void create ()
{
  set ("short", "��С·");
  set ("long", @LONG
  
ɽ·˳��ɽ���������·��խ��͹����ƽ������ܲ����紵����ľ����֮
�����ϴ���������Ϊ֮һ����
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xiaolu"+sprintf("%d",11+random(9)),
  "west" : __DIR__"xiaolu"+sprintf("%d",11+random(9)),
  "south" : __DIR__"xiaolu"+sprintf("%d",11+random(9)),
  "east" : __DIR__"xiaolu"+sprintf("%d",11+random(9)),
]));

     set("outdoors", 1);
  setup();
}

void init()
{
  add_action("do_fly", "fly");
}


int do_fly (string arg)
{
  object me;
  me = this_player();

  message_vision("$N��������һ��������ͨ����������������û����ɵĵط���\n", me);
  tell_object(me,"���������߰ɡ���\n");
  return 1;
}

