//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","��������ջ��");
  set ("long", @LONG

����ɽ�ϵ�һ�����ţ���������������Ԩ�����ŵ���������ˮ��������
�����Ǵ����´������ģ�������ˮ���ܼ����������߾���ӭ��ͤ��,
���Ѿ���ԶԶ�Ŀ�������ӭ��ͤ������������ЪϢ��
LONG);

  set("outdoors", "shushan");
  set("exits", ([      
  "eastdown" : __DIR__"shanlu2",
   "northup" : __DIR__"yingketing",
 ]));
 setup();
}






