//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","ӭ��ͤ");
  set ("long", @LONG

��ɽ������ǰ��ӭ��ͤ����������ܿ�����ɽ���ɵ�ɽ���ˡ�
ͤ�����в����ˣ�����������Χ����һ�𣬺�������������
̸���۽񣬱���һ����ζ��
LONG);

  set("exits", ([      
     "southdown" : __DIR__"zhanqiao",
       "northup" : __DIR__"shanmen",
 
 ]));
  set("objects", ([ 
    __DIR__"npc/youke" : 2,
    __DIR__"npc/liaoke" : 2,
    __DIR__"npc/oldzhang" : 1,
 ]));
  setup();
}









