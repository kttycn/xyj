inherit ROOM;

void create()
{
        set("short", "�岨С��");
        set("long", @LONG  
������ʣ��岨���ơ��������������������������롣
�����ǰ�˳���۰���Ů�������ĺ�������Ҳ����һ����
����Ů���������Ļ��ʣ������Ĵ�������������ıڻ��� 
������������������ʨ����ֱ���ƻ�������
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"zoulang6",
        ]));
        set("objects", ([
                __DIR__"npc/gongzhu":1,
        ]));
        setup();
}

