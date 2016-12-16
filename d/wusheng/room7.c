// changan wusheng
// room7.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

��������һ������������վ�������������ʥ�ŵĿ�ɽ����
������ʥ��ۡ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"room8",
"south": __DIR__"room6",
"east": __DIR__"room9",
]));
set("objects", ([
        __DIR__"npc/kongwu": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb ()
{
  object who = this_player ();
  string midong = __DIR__"midong1";

  message_vision ("$N��סǽ�ڣ�������ȥ��\n",who);  
  if (who->is_busy() || who->is_fighting() || 
	  present ("yao guai",this_object()))
  {
    message_vision ("$N��ǽ���ϻ���������\n",who);  
    return 1;
  }
  midong[strlen(midong)-1] = '1'+random(5);
  who->move(midong);
  who->start_busy(2,2);

	if( random(2) ) {
  call_out ("sleeping",1,who);
  return 1;
	}
  call_out("fainting",1,who);
  return 1;
}

void sleeping (object who)
{
  message_vision ("�ض���ɢ����һ�������������$N��ʱ���Ȼ��\n\n",who);  
  message_vision ("$N��ǿգ��գ������۾������˸���Ƿ��\n",who);  
  who->set("last_sleep",time()-270);
  who->interrupt_me();
  who->command_function("sleep"); 
}
void fainting (object who)
{
	message_vision("ͻȻ�Ӱ��������һ�����̣�$N��ʱͷ�ؽ��ᣬ���ɼ� ... \n", who);
	who->unconcious();
}