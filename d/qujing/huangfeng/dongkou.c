// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dongkou.c


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

Ұ��ƬƬ������ܷܷ�����ϼ�壬���͹ŵ���ֻ�����ɴ�
����������������ȽȽ��ɽʯ��ǰ¶��һ���ڣ�������һ
����ʯ��д�ţ�
[33m
                �áááááááá�
                �� [1;31m�Ʒ���Ʒ綴 [2;37;0m[0;33m��
                �áááááááá�[m


LONG);

  set("exits", ([
        "southdown" : __DIR__"huangfeng2",
        "north" : __DIR__"dong1",
      ]));
     set("objects", ([
                __DIR__"npc/baoxianfeng": 1 ]) );

        set("outdoors", __DIR__);
       
  setup();
}
int valid_leave (object me, string dir)
{
        if (dir == "north" ) {
        if (objectp(present("bao xianfeng", environment(me))) 
        && !wizardp(me) )
        return notify_fail("���ȷ��ݺݵĵ�����һ�ۣ����������,�Ʒ綴Ҳ���Ҵ���\n");
        }
  return 1;
}
