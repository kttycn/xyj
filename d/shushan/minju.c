//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
   set ("short", "���");
   set ("long", @LONG

��������ѻ���һ����ͨ��ӣ�����Ȼ���һƶ��ϴ����ʵ��ѻ����˶�����
ԣ���������һ������,��ֻ�м��������ˡ���������ĵ�һ����������ż�
������Ĺ��ߡ�������ʲôҲû���ˡ�
LONG);
   
   set("exits", ([ 		
       "east" : __DIR__"road3",
   ]));
   set("objects", ([ 		
      "d/city/npc/boy" : 1,
      "d/city/npc/girl" : 1,
]));

        setup();
}



