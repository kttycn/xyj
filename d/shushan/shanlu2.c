//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG

��Ŀ������ֻ��ɽ�������Ŀ��ɽ�����,���岻����εȻ���㡣����
˵��ǰ�������ɽ�ˡ�������һ��ջ�š������߾�����ɽ��·�ˡ�
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
  "eastdown" : __DIR__"shanlu1",
    "westup" : __DIR__"zhanqiao",
 ]));
 setup();
}






