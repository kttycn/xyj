// changan wusheng
// shijie9.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

�߹���ʥ�𶴣�����������һ�Ѹɲݣ������к��󱻻��ս��ˣ�
�պþ���һ��Ұ����״�����ۿ�ȥ��ԭ��ɽ�ϻ���һ�����ӡ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"room6",
"south": __DIR__"huoyun19",
]));
set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huoqilin" : 1,
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

