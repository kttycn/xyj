//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����������󣬳��ӵ����ܴ�����һ�ų�������������Ǹ��ָ���
��������ǰ����ʳ�ۣ���������кõ����ʲ��ϡ������ı�������ͨ
�����ϡ�

LONG);

  set("exits", ([
        "north" : __DIR__"chen2",
      ]));
  set("objects", ([
        __DIR__"npc/maguan" : 1,
        __DIR__"npc/horse" : 6,
      ]));

  set("outdoors", "kaifeng");

  setup();
}

