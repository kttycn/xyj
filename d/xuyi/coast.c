// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "���Ĳ��޺���");
  set ("long", @LONG

�������ϙ�Ƕ��ϵĺ����������ն񣬹�ʯ��ᾡ�����һ��һ�����˹�
�����ڽ�ʯ�ϻ��÷��飬������������������������Х�Ŵ���������
�˵������������졣
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  set("dangerous", 1);  
  
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"milin4",
]));

  setup();
}

