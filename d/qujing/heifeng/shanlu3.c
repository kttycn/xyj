//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

��������ɽ��·Ҳ������������ǰ�����ţ��㲻�����ú�ƣ������
���ڽ��ϣ�ʮ�ֵ����У�����ȡ��·�϶�ĥ�Ѱ���
LONG);

  set("exits", ([
        "west"  : __DIR__"shanlu4",
        "east"  : __DIR__"shanlu2",
        "enter"  : __DIR__"erengu",
      ]));
  set("outdoors","hf");
  setup();

}