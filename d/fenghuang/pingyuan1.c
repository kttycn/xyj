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
                    "north":__DIR__"pingyuan1",
                    "west":__DIR__"tudi3",
                    "east":__DIR__"pingyuan1",
                    "south":__DIR__"pingyuan2",
                       ]));
  setup();
}
