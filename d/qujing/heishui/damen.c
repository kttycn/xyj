//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG 
����ǰ����һ����ΰ�ĸ�ۡ����ˮ�����ƶ�������ͭ������
����(gate)�����һ������(bian)������д�ż������֡���
��С������������ˣ�ӣ�һ���㣬�����˹�����
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hedi6",
])); 
        set("objects", ([
                __DIR__"npc/guai" : 3,
        ]));

        set("item_desc", ([
 "bian" : "���Ϻ���˰˸�����--��������ˮ����\n", 
 "gate" : "����һ�Ⱥ�ͭ�����Ĵ��ţ�ʹ���ҿ��ɣ�\n", 
        ]) );
        setup();
} 
void init ()
{
  add_action ("do_break", "break");
}

int do_break (string arg)
{
  object who = this_player ();
        if( !arg || arg!="gate" )
              return notify_fail("��Ҫ��ʲô? \n");
    message_vision ("$N���һ����ʹ����������ȥ�����һ���������˸��������\n",who);
      message_vision ("�ҵ�һ���ſ��ˣ�\n",who);
      who->add("force",-200);
      who->add("mana",-200);
    this_object()->set("exits/east", __DIR__"dayuan");
  return 1;
}


