// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create()
{
        set("short", "˯��");
        set("long", @LONG

    ����ɽ��һ��˯��������ɸɾ�����һ�Ÿɾ�����Ĵ󴲣�
������ɽ��������Ϣ˯����
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "west" : __DIR__"zoulang3",
        ]));

        setup();
}


