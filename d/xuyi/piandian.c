// �����硤���μǡ��汾(����)
/* <SecCrypt CPL V3R05> */
 
// Room: /d/xuyi/lianwuchang.c

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG

�ʹ���ƫ�Ҳ��һ�����䳡�����ڸ��ֱ���������Ŀ��ӳ���չ⣬����
���ԡ�����������ʿ�����������Աߵı��������в��ٱ�������ѡ�á�
LONG);


  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"taizifu",
  "west" : __DIR__"hualang",
  "east" : __DIR__"shuifang",
]));

  set("objects", ([
        __DIR__"obj/rack": 1,
         __DIR__"npc/zhangmen": 1,
        __DIR__"npc/weishi": 2,
                   ]));

  setup();
}


