//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","С��");
  set ("long", @LONG

���С�ﲢ����һ���ž���С�����������̲�ʱ�������������Ĵ�
��������������������������˾�ûʲô���߶��ˡ������̾���Ϊ�˱�
��Ӱ����˲��޽�����С��ġ������Ǵ�·��
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
      "west" : __DIR__"road2",
      "east" : __DIR__"datiepu",
 ]));
 setup();
}






