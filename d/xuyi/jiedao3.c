// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

һ���������ʯ·�棬������ˮĸ���︮ۡ�Ĺ��ţ�ԶԶ��ȥ�����˸��
��С�������̷�Ҳ���������͵����︮�ϣ������ﳣ�����Կ���ˮĸ����
�ļ���СѾ����������Ϸ��
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao2",
        "west"   : __DIR__"door",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}
 

