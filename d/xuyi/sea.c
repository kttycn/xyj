// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// under2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ˮɫ���ǲ��壬��Ұ��С��ͷ����īɫ��������һ���âҲû�С�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shuiyuan" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"island",
]));
        setup();
}

