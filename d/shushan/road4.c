//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","��·");
  set ("long", @LONG

����·�Ͼ�ûʲô���ˣ����Ϸ����Ǵ�ͷ�ˡ�������һ��С������
�����濴�����ƾɲ������ˡ�
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
 "southwest" : __DIR__"exit",
      "east" : __DIR__"pomiao",
     "north" : __DIR__"road3",
 ]));
 setup();
}






