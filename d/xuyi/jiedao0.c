// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����һ��ƽֱ�Ĵ�·����һֱ�Ϳ��Ե��������ĵ�ʮ��·�ڣ���������
�ϴ������������Ϳ��Կ���ϙ�ǵĻʹ���ԶԶ��ȥ������һ�����ƣ�����
���ϳ��ţ�������ŵ�������������
LONG);

  set("exits", ([
        "south"   : __DIR__"nanmen",
        "north"   : __DIR__"lukou",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

