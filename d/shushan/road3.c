//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","��·");
  set ("long", @LONG

����·��ֻ�м���Сͯ��������ȥ�����������š�·���������أ�ʱ
��Ұ������ֻС��СѼ������ȥ��һ��Ұ��ҡ��β�����˹���������
�ţ������˿�ȥ��������һ�Һܼ�ª����ӡ�
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
 "northeast" : __DIR__"road2",
      "west" : __DIR__"minju",
     "south" : __DIR__"road4",
 ]));
 setup();
}






