// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "���Ĳ��޺���");
  set ("long", @LONG

����������Ĳ��޵ĺ�������ɫ��ɳ̲���������������⣬������ѩ����
�����񣬺�ˮ������һ�鱦ʯ���������ں�����������������ŷŷ���Ľ�
����
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"island",
]));

  setup();
}


