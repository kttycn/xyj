// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create()
{
        set("short", "����˯��");
        set("long", @LONG

������һ��˯��������ɸɾ�����һ�Ÿɾ�����Ĵ󴲣���������������
Ϣ˯����
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "west" : __DIR__"piandian",
        ]));

        setup();
}


