//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","С���");
  set ("long", @LONG

���������ѻ���ͷ�ˡ�������һ�����۵�С·��һ����˺�������
����ȥ�ˣ�ֻ��ż�����Լ�����λ��������������������ȥ�����ߺ�
�ϱ߾���һ����ɽ���������ơ�
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
 "northeast" : __DIR__"road4",
      "west" : __DIR__"road0",
 ]));
 setup();
}






