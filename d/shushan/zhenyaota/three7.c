//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "�������Թ�");                                   
  set ("long", @LONG                                                 
������ʯ�ڵ��Թ���һ��ŨŨ�����������ڿ����                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"pole",                                                                             
  "south" : __DIR__"three2",
  "west" : __DIR__"three2",
  "east" : __DIR__"pole",
                                     
]));                                                                 
    set("objects",([
        __DIR__"npc/yao1" : 3,
        __DIR__"npc/yao2" : 3,
    ]));                                                                     
  setup();                                                           
}