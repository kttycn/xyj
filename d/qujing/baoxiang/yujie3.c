// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yujie3.c
inherit ROOM;
int test_player (object who);

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�ɰ����̳ɵ�̨�ף���������������ȥ��ÿһ��̨�׶�����ϸ��
���ɣ���Ƕ�н�˿���ߡ����߸�ͨ��һ��һ���Ϊ����������
Ϊ̫���

LONG);

  set("exits", ([
        "northdown"  : __DIR__"yujie2",
        "southup"    : __DIR__"yujie4",
        "west"       : __DIR__"gong3",
        "east"       : __DIR__"dian3",
      ]));
  set("objects", ([
        __DIR__"npc/girl" : 2,
    ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if ( (dir == "west"||dir == "east") && 
  ! test_player (who))
  {
  	write(who->query("apply/name"));
    message_vision ("$N��ͷ������һ̽��������������Ļ������ͽ�$N�ܳ���\n",
                    who);
    return notify_fail("");
  }
  return 1;
}

int test_player (object who)
{
	string *names;
	string name;

	names = who->query_temp("apply/name");
	if (! names)
		return 0;

	if (sizeof(names) < 1)
		return 0;

	name = names[0];

	if (name == "����")
		return 1;
	return 0;
}