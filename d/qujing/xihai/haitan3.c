inherit ROOM;

void create ()
{
  set ("short", "��̲");
  set ("long", @LONG
������׺�Զ��ȥ�������ᡣ����΢���������ں���һ��
��������һС�����³�����������ֻ�������籡��������
��������ϼ���ûԻͣ�С��Ʈ�����·�ʻ�����С�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"haitan2",
  "southeast" : __DIR__"haitan4",
]));

        set("outdoors", "xihai");

  setup();
}

