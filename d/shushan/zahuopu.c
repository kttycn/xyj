//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","�ӻ���");
  set ("long", @LONG

����Ķ������������ҿ���˵��������ȫ,���Կ���Ҳ�Ƚ϶ࡣ�����
ɨ��Ҳ�ܸɾ������Լ�ʹû�п��ˣ�Ҳ�кö�����������ϰ����졣
LONG);

  set("exits", ([ 
     "west" : __DIR__"road1",
 ]));
 set("objects", ([ 
  __DIR__"npc/zaboss" : 1,
 ]));
 set("no_clean_up", 0);
 setup();
}






