inherit ROOM;
void create()
{
             set("short","һ���޼ʵĴ��ԭ");
             set("long",@LONG
������һƬһ���޼ʵĴ��ԭ�����Զ���һ�׶�ߵĲݣ��ڵ���
������ߣ�����ֲ��嶫����������ڤڤ֮�����ƺ���һ������
ָʹ���������ǰ��
LONG);
         set("exits",([
                 "east" : __DIR__"shangu1",
                 "south" : __DIR__"pingyuan5",
                 "north" : __DIR__"pingyuan4",
                 "west" : __DIR__"pingyuan5",
                       ]));
  setup();
}
