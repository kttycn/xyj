//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","������");
  set ("long", @LONG

��ѻ��Ĵ�����,�ϰ��Ǹ������ĺ��֣��ܶ�ñ���������
�ϰ�֮�֣����ٽ������ܶ������������,���������ǳ���
Ϊ�������֡�������ڽ�����Ҳ�����鴫��
LONG);

  set("exits", ([ 
     "west" : __DIR__"xiaoxiang",
 ]));
 set("objects", ([ 
  __DIR__"npc/daboss" : 1,
 ]));
 set("no_clean_up", 0);
 setup();
}






