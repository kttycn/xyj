// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

һ���������ʯ·�棬·����Ȼ���Ǻܿ���������������Ҳ��һƬ����
�ľ��󡣶������ϙ���æ�Ľ�ͨҪ��ʮ��·�ڣ�����������������
����һ�ҳ��µꡣ

LONG);

  set("exits", ([
        "east"   : __DIR__"lukou",
        "west"   : __DIR__"jiedao6",
        "north"   : __DIR__"garments",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

