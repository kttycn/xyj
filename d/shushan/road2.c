//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","��·");
  set ("long", @LONG

����һ�����е�ʯ��·��·����һ�ҿ�ջ����ջ��ǰ�Ĵ����Ϲ���һ
�����ӣ����顰������ջ����·����һ���ӻ��̡�һֱ�����ߣ��͵�
��ͷ�ˡ�
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
     "north" : __DIR__"road1",
 "southwest" : __DIR__"road3",
 "southeast" : __DIR__"jiudian",
      "east" : __DIR__"xiaoxiang",
      "west" : __DIR__"dangpu",
 ]));
 setup();
}






