// �����硤���μǣ����ͣ�
// Room: /d/xuyi/xiaolu.c

inherit ROOM;

void create ()
{
  set ("short", "��С·");
  set ("long", @LONG
  
ɽ·˳��ɽ���������·��խ��͹����ƽ������ܲ����紵����ľ����֮
�����ϴ���������Ϊ֮һ����
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xiaolu"+sprintf("%d",random(15)),
  "west" : __DIR__"xiaolu"+sprintf("%d",random(15)),
  "south" : __DIR__"xiaolu"+sprintf("%d",random(15)),
  "east" : __DIR__"xiaolu"+sprintf("%d",random(15)),
]));

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

