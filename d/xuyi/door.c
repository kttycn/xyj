// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ˮĸ���︮ۡ�Ĺ��ţ������˸��һ�Ծ޴�ĺ���������������
�Ÿ�ɫ�������滨��ݣ�������������Ƭ��ɫ�������ܣ����Ϸ���ʷ���
������������ס��ˮĸ��������ļ���СѾ�ߡ�
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao3",
        "west"   : __DIR__"guifang",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

