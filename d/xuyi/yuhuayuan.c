// �����硤���μ�֮�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

������ϙ�ǻʹ�������԰�����Եİٻ���ţ����涷�ޣ�������һ��Сˮ
�أ�ɽ����������Ȫˮ�ͻ㼯�����ˮ�ر���һֻ�������ڸ��׺�ˮ��
ֻ�����������ۣ�¹�����룬��Ȼ�Ǵ�˵�е����롣
LONG);

  set("exits", ([
        "north"   : __DIR__"hualang",
        "south"  : __DIR__"qiandian",
      ]));
  set("objects", ([
        __DIR__"npc/qilin" : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

