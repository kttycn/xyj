// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
 
������һ�������ϣ����Զ���̨ͥ���У�����������һ�������
����ζ��������������ʯש�̳ɣ���ͷ��һ��С�ҡ�
LONG);

        set("exits", ([ //sizeof() == 4
       "south" : __DIR__"zoulang", 
       "northeast" : __DIR__"xiaoshi",        ]));

        setup();
}

