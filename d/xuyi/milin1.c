// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created by night 8/18/2000

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
        
������ϙ��Ұ��Ľ���������գ��˼��������������˸е���Щ��ɭ����
�ºܶฯ�õ���Ҷ��һ��С�ľͻ�ˤ��һ�ӡ����������Ͽ���ͨ�����ߣ�
���������Ҳ��������Ƭ���֡�
LONG);
        set("exits",([
        "northwest" : __DIR__"xiaolu0",
        "east"  : __DIR__"milin2",
        "south"     : __DIR__"milin1",
        "west" : __DIR__"milin1",
        ]));

        set("dangerous", 1);
        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
   if((string)me->query("id")!="monster" || userp(me)) return 1;
//        if( wizardp(me)) return 1;

        if (dir == "northwest") {

        return notify_fail("ɽ�����������뿪���\n");

        }   
        return ::valid_leave(me, dir);
}

