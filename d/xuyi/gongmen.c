// �����硤���μ�֮�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����վ��һ�������Ĺ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ���һ���
�ң����顸ʥ�幬���������֣��ſڻ�վ�ż�����ʿ�����������������֣�
�����ͽ���ʹ��ˡ�
LONG);

  set("exits", ([
        "north"   : __DIR__"qiandian",
        "south"  : __DIR__"yujie",
      ]));
  set("objects", ([
         __DIR__"npc/wang" : 1,
         __DIR__"npc/weishi" : 3,

      ]));
  set("outdoors", __DIR__);

  setup();
}
int valid_leave(object me, string dir)
{
   if( (string)me->query("family/family_name")=="����ɽ" ) return 1;
        if( wizardp(me)) return 1;

        if (dir == "north") {
        if (objectp(present("wang shenjiang", environment(me))))
        return notify_fail("�������ֵ�ס�����ȥ·���ʹ�������������\n");
        if (objectp(present("wei shi", environment(me))))
        return notify_fail("������ʿ�������Ҽҽ������ڣ�С�˲��ҷ�����ȥ��\n");
        }   
        return ::valid_leave(me, dir);
}

