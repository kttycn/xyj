inherit ROOM;

void create()
{
        set("short", "��ľС��");
        set("long",@LONG 

����һ�������С�ҡ�����ȫ����ľ�Ƴɣ�����ľ����ľ�Ͼ���ȥƤ��
��Ȼ���ӣ���һ·������̻Ի͵ĵ��ý�Ȼ��ͬ��������һ��С���ţ�
��ªȴ͸��ׯ����͵����ա�
LONG
        );
        set("exits", ([
                "southwest": __DIR__"zoulang2",
        ]));
        set("objects",([
     __DIR__"npc/master" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

