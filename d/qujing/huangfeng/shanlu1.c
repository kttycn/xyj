// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

һ��С·���ּ�������ȥ��·�������ƽ�������С�·�Ϻ���
�������ˣ�ż��������ֻ�д��͵��̶ӡ�ǰ��·�����۴��ݲ�
���˿����ӣ������ƺ�д������(zi)��

LONG);

  set("item_desc",([
    "zi" : "����д�ţ�"+
    "ɽ���л���������������������֮��\n",
  ]));

  set("exits", ([
        "eastdown" : __DIR__"road5",
        "westup"      : __DIR__"shanlu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}
    
