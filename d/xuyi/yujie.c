// �����硤���μ�֮�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ϙ�ǻʹ�ǰ�����֣����湬���ϵ��Ҷ�д�š�ʥ�幬���������֡�
������߱�ֲ�ɰأ���Ŀ�Դ䡣
LONG);

  set("exits", ([
        "north"   : __DIR__"gongmen",
        "south"  : __DIR__"center",
      ]));
  set("objects", ([

      ]));
  set("outdoors", __DIR__);

  setup();
}

