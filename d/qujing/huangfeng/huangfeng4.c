// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng4.c


inherit ROOM;

void create ()
{
  set ("short", "�Ʒ���");
  set ("long", @LONG

����Ƶ������ط��ᡣ���۵Ĳ��ɴ�أ��̲�����һ��
СϪ��·������ˮ�����ˣ���Ȼһ��������ɫ����ֻС��
���������Ӳ���������һת���ܵò�֪���١�

LONG);

  set("exits", ([
        "west" : __DIR__"huangfeng3",
        "northeast" : __DIR__"huangfeng5",
		"south" : __DIR__"yangchanglu1",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
