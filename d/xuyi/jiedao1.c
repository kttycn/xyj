// �����硤���μ�֮�����ͣ�
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ���Ȼ���Ǻܿ���������������Ҳ��һƬ���ٵľ��󣬱�����һ�һ�
�꣬��˵�����и��ָ������ʻ����ۡ��������ϙ�ǵ����Ĺ㳡��������
��ʮ�����֣����ﴫ��������������������һ�ҾƵ꣬��ʱ�н���֮����
����

LONG);

  set("exits", ([
        "east"   : __DIR__"center",
        "west"   : __DIR__"jiedao2",
        "north"   : __DIR__"huapu",
        "south"   : __DIR__"jiudian",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

