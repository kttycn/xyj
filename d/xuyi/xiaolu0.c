// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created by jing 7/24/2000
 
inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

һ��������ʯ����ӵ�С·������һֱ�߾͵���ϙ�ǡ�ԶԶ��������ϙ��
�ĳ��ţ��������ӭ��������졣������С·�������ۣ����˲�֪����
ô�ߡ�
LONG);

  set("exits", ([
        "west"   : __DIR__"dongmen",
        "southeast"   : __DIR__"milin1",
  "east" : __DIR__"xiaolu"+sprintf("%d",1+random(4)),
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave(object me, string dir)
{
   if(me->query_temp("xuyi/monster")) return 1;
//        if( wizardp(me)) return 1;

        if (dir == "southeast") {

        return notify_fail("��Ȼһ������������ﴵ�����㲻��������ͣ���˽Ų���\n");

        }   
        return ::valid_leave(me, dir);
}

