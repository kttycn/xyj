//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ڻԻͣ��������򽫳����յ�ʮ����������ǰ��̨�ϵ���
һ�ڶƽ��ͭ�ӣ����߹��ż�����ࡣ�����������ǳ��ڣ�������һ
��ͨ�������ĳ���

LONG);

  set("exits", ([
        "northwest" : __DIR__"shuilu",
        "west" : __DIR__"jixian",
      ]));
  set("objects", ([
        __DIR__"npc/people" :  3,
        __DIR__"npc/hu" :  1,
      ]));

  setup();
}


