//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "�Ӱ�");
  set ("long", @LONG
��ˮ���ϣ����۲�������Ӱ��Զ����Ѱ��ľ�Ρ�����һ�غڣ�
����ǧ��ҡ���ʹ���ڰ��߼�����ĺӱߣ�Ҳ���Լ���ˮ��
�Ķ���ʯ���Ӱ���Χ��Բʮ����޾������������顣
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"hean4",
  "west" : __DIR__"hean2",
]));

        set("outdoors", "heishui");

  setup();
}

