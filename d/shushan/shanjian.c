//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG

���������Դ�ʹ������������ҿ�û��ˤ��������������������
�����ǲ�������(climb)��ȥ�ġ�ֻ����ǰ���ˡ�
LONG);

  set("exits", ([      
         "north" : __DIR__"shanjian2",
 ]));
 setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  
  object who = this_player();
  message_vision("$N������������ȥ������\n",who);
  message_vision ("$NͻȻ��һ���������ˡ���������\n",who);
  who->unconcious();
  return 1;
}






