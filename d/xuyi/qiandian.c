// �����硤���μ�֮�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "ǰ��");
  set ("long", @LONG

������ϙ�ǻʹ���ǰ���ש���߽���ʮ�־��ɣ�ϙ�ǹ�������������
��巺������ڴ˵�����͵�������԰�������ǻʹ����š�
LONG);

  set("exits", ([
        "north"   : __DIR__"yuhuayuan",
        "south"  : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/taijian" : 2,
        __DIR__"npc/king" : 1,  
      ]));

  setup();
}

