// �����硤���μ�֮�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ϙ�ǻʹ��Ļ��ȣ������µ������滨��ݣ����������������
����԰�����������ŷ���������ƫ�
LONG);

  set("exits", ([
        "north"   : __DIR__"zhengdian",
        "south"  : __DIR__"yuhuayuan",
        "west" : __DIR__"chufang",
        "east" : __DIR__"piandian",
      ]));
  set("objects", ([

      ]));
//  set("outdoors", __DIR__);

  setup();
}

