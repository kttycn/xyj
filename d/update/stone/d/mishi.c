//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/update/stone/d/mishi.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

����һ������εķ��ӣ�����ŵĶ���Щ����ӣ���Ȼ����ȫ������
���飬���Ǻ���麣���ı���ܣ�ʯͷ��ʦ��Ȼ���д˰��á�
LONG);

  set("exits", ([
         "north": "/d/update/stone/d/bookroom",
       ]));
  set("objects", ([
//        __DIR__"npc/monk_gm":1,
//         "/d/update/stone/obj/huanyang" : 1,
        ]));
  setup();
}
