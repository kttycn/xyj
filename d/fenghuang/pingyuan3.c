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
                 "south" : __DIR__"pingyuan3",
                 "north" : __DIR__"pingyuan3",
                 "west" : __DIR__"pingyuan2",
                 "east" : __DIR__"pingyuan4",
                       ]));
  setup();
}
