// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

����һ�����������ȣ���ʯΪש������Ϊ�������ų���һ·����
����������ӣ��Ͻ���Ƕ��������������ⷱ���ƽ���һ�Զ�
����������䡣��һ�����ɸ��ء����Ŷ��죡

LONG);

        set("exits", ([ //sizeof() == 4
       "north" : __DIR__"zoulang2",
       "east" : __DIR__"neidian",
        ]));

        setup();
}

