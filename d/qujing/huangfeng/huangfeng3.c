// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng3.c


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
        "southwest" : __DIR__"huangfeng2",
        "east" : __DIR__"huangfeng4",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
