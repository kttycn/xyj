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
        "north" : __DIR__"milin2",
        "east"  : __DIR__"milin1",
        "south"     : __DIR__"milin4",
        "west" : __DIR__"milin3", 
        "southwest" : __DIR__"coast",
        ]));

        set("dangerous", 1);
        setup();
//      replace_program(ROOM);
}

