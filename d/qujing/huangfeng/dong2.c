// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong2.c


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڹ��߻谵�����������ȳ��˱ǡ���������������ߴ�
����ȥ������û����ע���㣬���ǿ�Щ�뿪�ɡ�

LONG);

  set("exits", ([
        "east" : __DIR__"dong3",
      ]));
       
     set("objects", ([
                __DIR__"npc/huxianfeng": 1 ]) );

  setup();
}
