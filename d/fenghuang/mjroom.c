// Room: /d/game/mjroom.c 
inherit ROOM; 
void create() 
{ 
        set("short", "���ǹ���ȸ�ݡ�");
        set("long", @LONG
����һ��ר�����������Ϣ�����ֳ�����������Ϊ��Ľ�ɫ 
�������ʱ����������Ϣ��Ϊ���߸���Զ��·�����������һͬ 
�������Ȧ�ɣ������ɱ�����ڶĲ���ม���������ϸ�Ĺ����� 
�����������������䣩 
LONG    );
        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 1 */
  "board" : " 
һ������Ĳ�������  ÿ���ƶ��������  ����һ��  ��1w ����  ��7s 
�����ƾ֣�addin        ��ʼ�ƾ֣�start 
���ƣ�mo             �ؿ��ƾ֣�restart 
�����1���ƣ�.1      �����2���ƣ�.2 
�����3���ƣ�.3      �����4���ƣ�.4 
���Լ����ƣ�. 
���ƣ�dump xx        �ԣ�eat xx xx         
����pon              �ܣ�gon               
����hu               ����tin xx            
xxΪ����  ����eat 2w 3w 
",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mj" : 1,
]));
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"raceroom",
]));
        set("no_spells", 1);
        set("no_magic", 1);
        set("no_fight", 1);
        set("light", 1);
        setup();
        replace_program(ROOM);
}

