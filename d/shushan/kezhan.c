//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","������ջ");
  set ("long", @LONG

��������ؿ�����ŵ���ѡ,ƽʱ�������˿���Ҳ�ᵽ������ס��ģ�����
���õ�С�������ػص��д����ķ����͡�¥���ǿͷ���
LONG);

  set("exits", ([ 
     "east" : __DIR__"road1",
       "up" : __DIR__"up",
 ]));
  set("objects", ([ 
  __DIR__"npc/xiaoer" : 1,
 ]));
  set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("freeze",1);
  set("resource", ([   
  "water" : 1,
]));

 setup();
}

int valid_leave(object me, string dir)
{
  if ( !me->query_temp("rent_paid") && dir == "up" )
    return notify_fail("��С��������Ц�ص�ס���㣺�Բ��𣬿ͷ�������š�\n");
  return ::valid_leave(me, dir);
}






