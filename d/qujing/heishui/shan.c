//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�����Ǻ�ˮ�ӱߵ�һ������ɽ�壬Զ��ɽ�£��������죬
��ˮ���ϡ��������ҵĺ�ˮ�����⿴��Ҳ������һ����
���С�ڴ����ˡ���ͷ���ӣ�ɽ�����գ������ǲ�����
���ʵ��ˡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"hean2",
  "up" : __DIR__"xuanya",
]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir == "up")
    return notify_fail ("ɽ�ƶ��ͣ�����ôŬ������������ȥ�ġ�\n");
  return ::valid_leave(who,dir);
}

