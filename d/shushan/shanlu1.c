//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG

��˳�Ųݴ����˹��������ߵ�������ɽ������������ǰ,����ɽӦ��
������ɽ�ˡ�һֱ�����߹��ƾͻᵽ�˴�˵�е���ɽ�����ˡ�
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
 "northeast" : __DIR__"shanlu",
    "westup" : __DIR__"shanlu2",
 ]));
 setup();
}






