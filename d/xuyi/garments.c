// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "Ѧ�ǳ�����");
  set ("long", @LONG

����һ�����ֺŵĹ���ׯ����������˸�ʽ����������񡢾˿������
Ƥ������춷��л������ȹ��ˮ��ɫ�ް�������ɫ�Ż�������һ���㡣
LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao5",
      ]));
  set("objects", ([
        __DIR__"npc/xue"   : 1,
      ]));

  setup();
}

